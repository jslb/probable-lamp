#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>

//global vars
//Register declaration
int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;
R2 = 5;
R3 = 7;

void addFunc (int endreg, int val1var, int val2var)
{
    printf("addFunc vars:\n");
    printf("%i\n", endreg);
    printf("%i\n", val1var);
    printf("%i\n", val2var);
    
    int temptotalvar1 = 0;
    int temptotalvar2 = 0;
    int temptotal = 0;
    
    //val1var
    if (val1var == 0){
        temptotalvar1 = R0;
    } else if (val1var == 1){
        temptotalvar1 = R1;
    } else if (val1var == 2){
        temptotalvar1 = R2;
    } else if (val1var == 3){
        temptotalvar1 = R3;
    } else if (val1var == 4){
        temptotalvar1 = R4;
    } else if (val1var == 5){
        temptotalvar1 = R5;
    } else if (val1var == 6){
        temptotalvar1 = R6;
    } else if (val1var == 7){
        temptotalvar1 = R7;
    } else if (val1var == 8){
        temptotalvar1 = R8;
    } else if (val1var == 9){
        temptotalvar1 = R9;
    } else if (val1var == 10){
        temptotalvar1 = R10;
    } else if (val1var == 11){
        temptotalvar1 = R11;
    } else if (val1var == 12){
        temptotalvar1 = R12;
    } else if (val1var == 13){
        temptotalvar1 = R13;
    } else if (val1var == 14){
        temptotalvar1 = R14;
    } else if (val1var == 15){
        temptotalvar1 = R15;
    } else {
        printf("Invalid register/value");
    }
    
    //val2var
    if (val2var == 0){
        temptotalvar2 = R0;
    } else if (val2var == 1){
        temptotalvar2 = R1;
    } else if (val2var == 2){
        temptotalvar2 = R2;
    } else if (val2var == 3){
        temptotalvar2 = R3;
    } else if (val2var == 4){
        temptotalvar2 = R4;
    } else if (val2var == 5){
        temptotalvar2 = R5;
    } else if (val2var == 6){
        temptotalvar2 = R6;
    } else if (val2var == 7){
        temptotalvar2 = R7;
    } else if (val2var == 8){
        temptotalvar2 = R8;
    } else if (val2var == 9){
        temptotalvar2 = R9;
    } else if (val2var == 10){
        temptotalvar2 = R10;
    } else if (val2var == 11){
        temptotalvar2 = R11;
    } else if (val2var == 12){
        temptotalvar2 = R12;
    } else if (val2var == 13){
        temptotalvar2 = R13;
    } else if (val2var == 14){
        temptotalvar2 = R14;
    } else if (val2var == 15){
        temptotalvar2 = R15;
    } else {
        printf("Invalid register/value");
    }
 
    temptotal = temptotalvar1 + temptotalvar2;
    
    //store in end register
    if (endreg == 0){
        R0 = temptotal;
        printf("Register R0 value: %i\n", R0);
    } else if (endreg == 1){
        R1 = temptotal;
        printf("Register R1 value: %i\n", R1);
    } else if (endreg == 2){
        R2 = temptotal;
        printf("Register R2 value: %i\n", R2);
    } else if (endreg == 3){
        R3 = temptotal;
        printf("Register R3 value: %i\n", R3);
    } else if (endreg == 4){
        R4 = temptotal;
        printf("Register R4 value: %i\n", R4);
    } else if (endreg == 5){
        R5 = temptotal;
        printf("Register R5 value: %i\n", R5);
    } else if (endreg == 6){
        R6 = temptotal;
        printf("Register R6 value: %i\n", R6);
    } else if (endreg == 7){
        R7 = temptotal;
        printf("Register R7 value: %i\n", R7);
    } else if (endreg == 8){
        R8 = temptotal;
        printf("Register R8 value: %i\n", R8);
    } else if (endreg == 9){
        R9 = temptotal;
        printf("Register R9 value: %i\n", R9);
    } else if (endreg == 10){
        R10 = temptotal;
        printf("Register R10 value: %i\n", R10);
    } else if (endreg == 11){
        R11 = temptotal;
        printf("Register R11 value: %i\n", R11);
    } else if (endreg == 12){
        R12 = temptotal;
        printf("Register R12 value: %i\n", R12);
    } else if (endreg == 13){
        R13 = temptotal;
        printf("Register R13 value: %i\n", R13);
    } else if (endreg == 14){
        R14 = temptotal;
        printf("Register R14 value: %i\n", R14);
    } else if (endreg == 15){
        R15 = temptotal;
        printf("Register R15 value: %i\n", R15);
    } else {
        printf("Invalid register/value");
    }
}

void movFunc (int endreg, int val1var)
{
    printf("movFunc vars:\n");
    printf("%i\n", endreg);
    printf("%i\n", val1var);
}


int main()
{
    char inputstr[50];
    char inst[10];
    int marker = 1;
    int spacebool;
    char *argsstr[10];

    //runs continuously
    while (marker == 1)
    {
        printf("Enter input: ");
        
        //reads, stores, and prints, input
        fgets(inputstr, sizeof(inputstr), stdin);  // read string
        printf("You entered: ");
        puts(inputstr);    // display string
        
        char *frag = strtok(inputstr, " ");
        int counter = 0;
        
        // loop through the string to split at each " "
        while( frag != NULL ) 
        {
            printf( " %s\n", frag ); //printing each
            argsstr[counter++] = frag;
            frag = strtok(NULL, " ");
        }
        
        //add each frag into new array (argsstr)
        int p;
        for (p = 0; p < counter; ++p)
        {
            printf( "%s\n", argsstr[p]) ;
        }
        
        printf("Instruction: %s", argsstr[0]);
        int regVar, val1var, val2var;
        //regVar
        if (strcmp(argsstr[1], "r0,") == 0){
            regVar = 0;
            printf("\nregVar = 0");
        } else if (strcmp(argsstr[1], "r1,") == 0){
            regVar = 1;
            printf("\nregVar = 1");
        } else if (strcmp(argsstr[1], "r2,") == 0){
            regVar = 2;
            printf("\nregVar = 2");
        } else if (strcmp(argsstr[1], "r3,") == 0){
            regVar = 3;
            printf("\nregVar = 3");
        } else if (strcmp(argsstr[1], "r4,") == 0){
            regVar = 4;
            printf("\nregVar = 4");
        } else if (strcmp(argsstr[1], "r5,") == 0){
            regVar = 5;
            printf("\nregVar = 5");
        } else if (strcmp(argsstr[1], "r6,") == 0){
            regVar = 6;
            printf("\nregVar = 6");
        } else if (strcmp(argsstr[1], "r7,") == 0){
            regVar = 7;
            printf("\nregVar = 7");
        } else if (strcmp(argsstr[1], "r8,") == 0){
            regVar = 8;
            printf("\nregVar = 8");
        } else if (strcmp(argsstr[1], "r9,") == 0){
            regVar = 9;
            printf("\nregVar = 9");
        } else if (strcmp(argsstr[1], "r10,") == 0){
            regVar = 10;
            printf("\nregVar = 10");
        } else if (strcmp(argsstr[1], "r11,") == 0){
            regVar = 11;
            printf("\nregVar = 11");
        } else if (strcmp(argsstr[1], "r12,") == 0){
            regVar = 12;
            printf("\nregVar = 12");
        } else if (strcmp(argsstr[1], "r13,") == 0){
            regVar = 13;
            printf("\nregVar = 13");
        } else if (strcmp(argsstr[1], "r14,") == 0){
            regVar = 14;
            printf("\nregVar = 14");
        } else if (strcmp(argsstr[1], "r15,") == 0){
            regVar = 15;
            printf("\nregVar = 15");
        } else 
        {
            printf("\n2nd frag: possible int");
        }
        
        //val1var
        if (strcmp(argsstr[2], "r0,") == 0){
            val1var = 0;
            printf("\nval1var = 0");
        } else if (strcmp(argsstr[2], "r1,") == 0){
            val1var = 1;
            printf("\nval1var = 1");
        } else if (strcmp(argsstr[2], "r2,") == 0){
            val1var = 2;
            printf("\nval1var = 2");
        } else if (strcmp(argsstr[2], "r3,") == 0){
            val1var = 3;
            printf("\nval1var = 3");
        } else if (strcmp(argsstr[2], "r4,") == 0){
            val1var = 4;
            printf("\nval1var = 4");
        } else if (strcmp(argsstr[2], "r5,") == 0){
            val1var = 5;
            printf("\nval1var = 5");
        } else if (strcmp(argsstr[2], "r6,") == 0){
            val1var = 6;
            printf("\nval1var = 6");
        } else if (strcmp(argsstr[2], "r7,") == 0){
            val1var = 7;
            printf("\nval1var = 7");
        } else if (strcmp(argsstr[2], "r8,") == 0){
            val1var = 8;
            printf("\nval1var = 8");
        } else if (strcmp(argsstr[2], "r9,") == 0){
            val1var = 9;
            printf("\nval1var = 9");
        } else if (strcmp(argsstr[2], "r10,") == 0){
            val1var = 10;
            printf("\nval1var = 10");
        } else if (strcmp(argsstr[2], "r11,") == 0){
            val1var = 11;
            printf("\nval1var = 11");
        } else if (strcmp(argsstr[2], "r12,") == 0){
            val1var = 12;
            printf("\nval1var = 12");
        } else if (strcmp(argsstr[2], "r13,") == 0){
            val1var = 13;
            printf("\nval1var = 13");
        } else if (strcmp(argsstr[2], "r14,") == 0){
            val1var = 14;
            printf("\nval1var = 14");
        } else if (strcmp(argsstr[2], "r15,") == 0){
            val1var = 15;
            printf("\nval1var = 15");
        } else {
            printf("\nThird frag: possible int");
        }
        
        //val2var
        if (strcmp(argsstr[3], "r0") == 0){
            val2var = 0;
            printf("\nval2var = 0");
        } else if (strcmp(argsstr[3], "r1") == 0){
            val2var = 1;
            printf("\nval2var = 1");
        } else if (strcmp(argsstr[3], "r2") == 0){
            val2var = 2;
            printf("\nval2var = 2");
        } else if (strcmp(argsstr[3], "r3") == 0){
            val2var = 3;
            printf("\nval2var = 3");
        } else if (strcmp(argsstr[3], "r4") == 0){
            val2var = 4;
            printf("\nval2var = 4");
        } else if (strcmp(argsstr[3], "r5") == 0){
            val2var = 5;
            printf("\nval2var = 5");
        } else if (strcmp(argsstr[3], "r6") == 0){
            val2var = 6;
            printf("\nval2var = 6");
        } else if (strcmp(argsstr[3], "r7") == 0){
            val2var = 7;
            printf("\nval2var = 7");
        } else if (strcmp(argsstr[3], "r8") == 0){
            val2var = 8;
            printf("\nval2var = 8");
        } else if (strcmp(argsstr[3], "r9") == 0){
            val2var = 9;
            printf("\nval2var = 9");
        } else if (strcmp(argsstr[3], "r10") == 0){
            val2var = 10;
            printf("\nval2var = 10");
        } else if (strcmp(argsstr[3], "r11") == 0){
            val2var = 11;
            printf("\nval2var = 11");
        } else if (strcmp(argsstr[3], "r12") == 0){
            val2var = 12;
            printf("\nval2var = 12");
        } else if (strcmp(argsstr[3], "r13") == 0){
            val2var = 13;
            printf("\nval2var = 13");
        } else if (strcmp(argsstr[3], "r14") == 0){
            val2var = 14;
            printf("\nval2var = 14");
        } else if (strcmp(argsstr[3], "r15") == 0){
            val2var = 15;
            printf("\nval2var = 15");
        } else 
        {
            printf("\n4th frag");
        }
        
                
        if (strcmp(argsstr[0], "add") == 0)
        {
            printf("\ncall add func\n"); // want to give the function, the rest of the input string
            addFunc(regVar, val1var, val2var); //passing the inst to addFunc
        } 
        else if (strcmp(argsstr[0], "mov") == 0)
        {
            printf("\ncall move func\n");
            movFunc(regVar, val1var);
        } 
        else 
        {
            printf("Unknown instruction");
        }
    }
    
    
    //out of while loops, exits
    return 0;
}

/*int registerFunc(char *reg)
{
    printf("string: %s", reg);
    
    if (strcmp(tolower(reg), "r0") == 0)
    {
        regCode = 0;
    } else if (strcmp(tolower(reg), "r1") == 0)
    {
        regCode = 1;
    } else if (strcmp(tolower(reg), "r2") == 0)
    {
        regCode = 2;
    } 
    
    return regCode;
    
}*/
