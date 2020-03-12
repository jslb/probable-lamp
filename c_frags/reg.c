#include <stdio.h>
#include <string.h>
#include <ctype.h>

int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;
void regPrintFunc(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

int main ()
{
    R1 = 9;
    R2 = 8;
    R3 = 0;
    regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
}

void regPrintFunc(int R0, int R1, int R2, int R3, int R4, int R5, int R6, int R7, int R8, int R9, int R10, int R11, int R12, int R13, int R14, int R15)
{
    printf("\n********************");
    printf("\n**** REGISTERS. ****");
    printf("\n********************");
    printf("\n   R0:  %d", R0);
    printf("\n   R1:  %d", R1);
    printf("\n   R2:  %d", R2);
    printf("\n   R3:  %d", R3);
    printf("\n   R4:  %d", R4);
    printf("\n   R5:  %d", R5);
    printf("\n   R6:  %d", R6);
    printf("\n   R7:  %d", R7);
    printf("\n   R8:  %d", R8);
    printf("\n   R9:  %d", R9);
    printf("\n  R10:  %d", R10);
    printf("\n  R11:  %d", R11);
    printf("\n  R12:  %d", R12);
    printf("\n  R13:  %d", R13);
    printf("\n  R14:  %d", R14);
    printf("\n  R15:  %d", R15);
    printf("\n********************");
    printf("\n********************");
    printf("\n********************\n\n");
}
