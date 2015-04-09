#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ieee.h"

unsigned maxEXP(unsigned exp) {
	unsigned int max = (1 << exp)-1 ; 
    return max; 
}

unsigned getExpMask(unsigned exp){
    unsigned int expmask = (2 << (exp-1))-1; 
	return expmask;
}

unsigned getFracMask(unsigned frac){
	unsigned int fracmask = (2 << (frac-1)) - 1; 
	return fracmask; 
}

unsigned getBias(unsigned exp){
    unsigned int bias = (1 << (exp-1))-1;
	return bias;
}

unsigned getExp(unsigned exp, unsigned frac, unsigned x) {
	x = (x >> frac);
    x = x & getExpMask(exp);
   return x;
}

unsigned getFrac(unsigned exp, unsigned frac, unsigned x) {
   x = x & getFracMask(frac);
   return x;
}

int getSign(unsigned exp, unsigned frac, unsigned x) {
   unsigned int nbits = 1 << (frac+exp);    
   unsigned int y = (x & nbits);
   if (y == nbits)
	   return 1;
   else
	   return 0;  
}

int isDenormalized(unsigned exp, unsigned frac, unsigned x) {
    if (getExp(exp,frac,x) == 0)
      return 1;
    return 0;
}

int isNormalized(unsigned exp, unsigned frac, unsigned x) {
    if (getExp(exp,frac,x) != 0 && getExp(exp,frac,x) != maxEXP(exp))
      return 1;
    return 0;
}

int isInfinity(unsigned exp, unsigned frac, unsigned x) {
   if (getFrac(exp,frac,x) == 0 && getExp(exp,frac,x) == maxEXP(exp))
      return 1;
   return 0;
}

int isNaN(unsigned exp, unsigned frac, unsigned x) {
   if (getFrac(exp,frac,x) != 0 && getExp(exp,frac,x) == maxEXP(exp))
      return 1;
   return 0;
}

double getValueDenormalized(unsigned exp, unsigned frac, unsigned x){
	if(isDenormalized(exp,frac,x)==-1)
		return -1; 
	double twoE,S,M,E;
	S = getSign(exp,frac,x);
    int mpower = 2 << (frac-1);
    M = getFrac(exp,frac,x)* 1.0/mpower;
	E = 1-(int)getBias(exp);
	if (E < 0) {
		E = -1 * E; 
        int power = (2 << (int)E-1); 
    	twoE = -1*1.0/power;
    }
    else if (E == 0) {
		twoE = 1; 
	}
   	else{
       int power = (2 << (int)E-1); 
       twoE = power;
    }
    if (S = 1) {
        return -1 * M * twoE; 
    } else {
        return M * twoE; 
    }
}

double getValueNormalized(unsigned exp, unsigned frac, unsigned x) {
	if(isNormalized(exp,frac,x)==-1)
		return -1;
	if (x == 0) 
		return 0; 
	double twoE,S,M,E;
	S = getSign(exp,frac,x);
	int mpower = 2 << (frac-1);
	M = 1 + getFrac(exp,frac,x)* 1.0/mpower;
	E = (double)getExp(exp,frac,x)-(double)getBias(exp);
    if (E < 0) {
		E = -1 * E; 
        int power = (2 << (int)E-1); 
    	twoE = 1.0/power;
    }
    else if (E == 0){
      twoE = 1.0; 
    }
   	else{
       int power = (2 << (int)E-1); 
       twoE = power;
    }
    if (S == 1) {
        return -1 * M * twoE; 
    } else {
        return 1 * M * twoE; 
    }
    
}

double getValueInfinity(unsigned exp, unsigned frac, unsigned x) {
	if (isInfinity(exp,frac,x)){
		if (getSign(exp,frac,x) == 0) {
			return (1.0/0.0);
		}else {
			return ((1.0/0.0) * - 1); 
		}
	}
}

double getValue(unsigned exp, unsigned frac, unsigned x){
	if (isDenormalized(exp,frac,x)){
		return getValueDenormalized(exp,frac,x);
	}
	else if (isNormalized(exp,frac,x)){
		return getValueNormalized(exp,frac,x); 
	}
	else if (isInfinity(exp,frac,x)){
		return getValueInfinity(exp,frac,x); 
	}
	else if (isNaN(exp,frac,x)) {
		return (0.0/0.0); 
	}
}

int createDataFile() {
   FILE *file;
   unsigned bits;
   unsigned bitsList[] = {4000, 0x15cc, 0, 250, 0x3092, 0x3f00, 0x1fff};
   int i;
   file = fopen("tests-5-8.out","w");
   if (file == NULL)
      return -1;
   for (i=0;i<7;i++)
      fprintf(file,"%04x: %17.10lf\n",bitsList[i],getValue(5,8,bitsList[i]));
   for (bits =0; bits < 4*4096; bits++)
      fprintf(file,"%04x: %17.10lf\n",bits,getValue(5,8,bits));
   return 0;
}

