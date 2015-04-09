#include <stdio.h>
#include <stdlib.h>
#include "pslibrary.h"

int main(int argc, char *argv[]) {
    int nsum;
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int num7;
    char *s1;
    char *s2;

    if (argc != 8 ) {
        printf("Incorrect number of command line parameters\n");
        return(1);
    }
    printf("Assignment 2 program was written by Marcus Lorenzana\n");

    printf("inputs: ");
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s ",argv[i]);
    }
    printf("\n");

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    num3 = atoi(argv[3]);
    num4 = atoi(argv[4]);
    num5 = atoi(argv[5]);
    num6 = atoi(argv[6]);
    num7 = atoi(argv[7]);

    nsum = num2 + num3 + num4 + num5 + num6 + num7;

    if ((s1 = (char *)malloc(nsum)) == NULL) {
        printf("Memory Error \n");
        exit(1);
    }

    if ((s2 = (char *)malloc(nsum)) == NULL) {
        printf("Memory Error \n");
        exit(1);
    }

    //part0(s1,s2);
    fcfs(s1,s2,num2,num3,num4,num5,num6,num7);
    display("FCFS \n",s1,s2);

    sjf(s1,s2,num2,num3,num4,num5,num6,num7);
    display("SJF \n", s1, s2);

    psjf(s1,s2,num2,num3,num4,num5,num6,num7);
    display("PSFJ \n", s1, s2);

    rr(s1,s2,num1,num2,num3,num4,num5,num6,num7);
    display("RR \n", s1, s2);

    free(s1);
    free(s2);

    return 0;

}
