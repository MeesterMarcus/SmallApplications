#include <stdio.h>
#include <stdlib.h>
#include "ieee.h"
//Assign 2 
int main(int argc, char *argv[]) {
   unsigned bits;
   printf("%s by Marcus Lorenzana\n",argv[0]);

   if (argc == 1) {
      if (createDataFile() == -1)
         printf("Could not create data file\n");
      else
         printf("Data file created\n");
      return 0;
   }

   if (argc != 4) {
      printf("Usage: %s value\n",argv[0]);
      return 0;
   }
	unsigned exp = (unsigned)strtol(argv[1],NULL,0);
	unsigned frac = (unsigned)strtol(argv[2],NULL,0);
    bits = (unsigned)strtol(argv[3],NULL,0);
    printf("The argument in hex was %x\n",bits);
    printf("The exp value is %u\n",getExp(exp,frac,bits));
    printf("The frac value is %u\n",getFrac(exp,frac,bits));
    printf("The sign is %d\n",getSign(exp,frac,bits));
    printf("isDenormalized: %d\n",isDenormalized(exp,frac,bits));
    printf("isNormalized:   %d\n",isNormalized(exp,frac,bits));
    printf("isInfinity:     %d\n",isInfinity(exp,frac,bits));
    printf("isNAN:          %d\n",isNaN(exp,frac,bits));
    printf("Value is %0.12lf\n", getValue(exp,frac,bits));

   return 0;
}
   

