#include <stdio.h>
#include <string.h>
#include "pslibrary.h"

#define READY  0
#define RUNNING  1
#define WAITING  2
#define DONE  3

static char stateChars[] = {'r','R','w',0};

void part0(char *s1, char *s2) {
    strcpy(s1,"RRwwwwwRRRRRRRRR");
    strcpy(s2,"rrRRRRwwwwwwwwrrRRRRRRR");
}

void display(char *heading, char *s1, char *s2) {
    printf("\n");
    printf("%s\n",heading);
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("\n");
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int i,s1cnt,s2cnt,s1cnt2,s2cnt2;
    s1cnt=s2cnt=0;
    s1cnt2=s2cnt2=0;
    for (i = 0; i < s1len; i++) {
        if (s1[i]=='r')
            s1cnt++;
    }
    for (i = 0; i < s2len; i++) {
        if (s2[i]=='r')
            s2cnt++;
    }
    float average_r = (s1cnt+s2cnt)/2;

    for (i = 0; i < s1len; i++) {
        if (s1[i]=='R')
            s1cnt2++;
    }
    for (i = 0; i < s2len; i++) {
        if (s2[i]=='R')
            s2cnt2++;
    }

    int longest;
    if (s2len > s1len) {
        longest = s2len;
    } else {
        longest = s1len;
    }

    float average_R = (float)(s1cnt2+s2cnt2)/longest;

    printf("%d %d %.1f %.5f\n",s1cnt,s2cnt,average_r,average_R);
}

/* 1) handle state changes:

         running process completes CPU burst

         running process has quantum expire

         IO complete

   2) do context switch if necessary

         both ready

         one ready and CPU free

   3) append appropriate characters to character arrays

         avoid putting in multiple string terminators

*/

/* assume s1 and s2 point to buffers with enough space to hold the result */

/* assume that the int parameters are strictly greater than 0 */



void fcfs(char *s1, char *s2, int x1, int y1, int z1,
          int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0)) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }
        /* if both ready, depends on algorithm */
        if ((state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
        }
        /* handle one ready and CPU available */
        else if ((state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }
        else if ((state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }
}



void sjf(char *s1, char *s2, int x1, int y1, int z1,
         int x2, int y2, int z2) {
    
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0)) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }
        /* if both ready, depends on algorithm */
        if ((state1 == READY) && (state2 == READY)) {
            if (cpuLeft1 <= cpuLeft2)
                state1 = RUNNING;
            else
                state2 = RUNNING;
        }
        /* handle one ready and CPU available */
        else if ((state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }
        else if ((state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }
}

void psjf(char *s1, char *s2, int x1, int y1, int z1,
          int x2, int y2, int z2) {

    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];
            }
            else
                state2 = WAITING;
        }
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }
        /* if both ready, depends on algorithm */
        if ((state1 == READY) && (state2 == READY)) {
            if (cpuLeft1 <= cpuLeft2)
                state1 = RUNNING;
            else
                state2 = RUNNING;
        }
        /* handle one ready and CPU available */
        else {
            if (state1 == READY) {
                if (state2 != RUNNING)
                    state1 = RUNNING;
                else if (cpuLeft1 < cpuLeft2) {
                    state1 = RUNNING;
                    state2 = READY;
                }
            }
            else if (state2 == READY) {
                if (state1 != RUNNING)
                    state2 = RUNNING;
                else if (cpuLeft2 < cpuLeft1) {
                    state2 = RUNNING;
                    state1 = READY;
                }
            }
        }
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }                                               /* end of main for loop */
}



void rr(char *s1, char *s2, int q, int x1, int y1, int z1,

        int x2, int y2, int z2) {

    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */
    int qleft;                                         /* quantum remaining */
    int bit1 = 0;                                            /* input bit 1*/
    int bit2 = 0;                                            /* input bit 2*/

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];
            }
            else
                state2 = WAITING;
        }
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
            bit1 = 1;
        }
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
            bit2 = 1;
        }
        if (bit1)
            bit1++;
        if (bit2)
            bit2++;
        /* if both ready, depends on algorithm */
        if ((state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
            qleft = q;
        }
        /* handle one ready and CPU available */
        else if ((state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
            qleft = q;  //change it was quatum
        }
        else if ((state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
            qleft = q;
        }
        else if (qleft == 0) {
            /* handle when both become ready at same time */
            if (state1 == RUNNING && bit2 == 2) {
                state2 = READY;
                state1 = RUNNING;
                qleft = q;
            }
            else if (state1 == RUNNING) {
                if (state2 == READY) {
                    state1 = READY;
                    state2 = RUNNING;
                    qleft = q;
                }
                qleft = q;
            }
            else if (state2 == RUNNING) {
                if (state1 == READY) {
                    state2 = READY;
                    state1 = RUNNING;
                    qleft = q;
                }
                qleft = q;
            }
        }

        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        qleft--;                   /* OK to decrement even if nothing running */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
    }  /* end of main for loop */
}
