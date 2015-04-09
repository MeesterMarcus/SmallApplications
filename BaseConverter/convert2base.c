#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 50
static const char hexstr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char * argv[]) {
   printf("Marcus Lorenzana\n");
   if (argc == 3) {
      int base = atoi(argv[1]);
      if (base < 2 || base > 36){
         printf("Wrong base number\n");
         return 1; 
      }
      int i = 0;
      long long pvalue;
      int remainder;
      char remainders[BUFFER];
      long long value = atoll(argv[2]);
      int vwidth = strlen(argv[2]);
      int wMax = 0; 
	   //Convert the decimal to user given base
      while(value != 0) {
         pvalue= value;
         remainder = value%base;
         value = value/base;
         //Store the remainder in an array for later use
         remainders[i]=hexstr[remainder];
			char line[BUFFER];
         int w = sprintf(line,"%*lld = %lld * %d + %d", \
            vwidth,pvalue,value,base,remainder);
         if (w > wMax)
            wMax = w; 
         printf("%s %*s(%c)\n", line,wMax-w,"",hexstr[remainder]);
         i++;
      }
      while(i > 0) {
         printf("%c",remainders[--i]);
      }
      printf("\n");
      } else {
         printf("Error: Wrong arguments\n");
         return 1; 
      }
   return 0;
}
