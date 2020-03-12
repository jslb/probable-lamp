#include <stdio.h>
#include <string.h>
#include <ctype.h>

//global vars
//Register declaration
int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;

int numberFunc(int, char[]);
int regnumFunc(int, char[]);
int value = 0;
int numberFunc(int value, char* input)
{
   char num[32];
   //printf("%s", input); // %s is format specifier
   int n = 0;
   int i = 0;
   int newindex = 0;
   int finalint = 0;
   n = sizeof(input)/sizeof(input[0]);
   int totchars = n - 1;
   int lastcharindex = totchars - 1;
   //printf("Totalchars: %d\n", totchars);
   //printf("Lastcharindex: %d\n", lastcharindex);
   if (input[0] == '#') {
      //printf("First char is hash\n");
      for (int i = 1; i <= lastcharindex;) {
	//printf("Char at %d index = %c\n", i , input[i]);
	num[newindex] = input[i];
	i++;
	newindex++;
      }
      sscanf(num, "%d", &finalint);
      //printf("int: %d\n", finalint);
      value = finalint;
   } else {   
      printf("Invaild input");
   }
   //printf("final int func: %d\n", value);
   return value;
}


void addFunc (int endreg, int val1var, int val2var)
{
    //printf("addFunc vars:\n");
    //printf("%i\n", endreg);
    //printf("%i\n", val1var);
    //printf("%i\n", val2var);
    
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
    } else if (endreg == 1){
        R1 = temptotal;
    } else if (endreg == 2){
        R2 = temptotal;
    } else if (endreg == 3){
        R3 = temptotal;
    } else if (endreg == 4){
        R4 = temptotal;
    } else if (endreg == 5){
        R5 = temptotal;
    } else if (endreg == 6){
        R6 = temptotal;
    } else if (endreg == 7){
        R7 = temptotal;
    } else if (endreg == 8){
        R8 = temptotal;
    } else if (endreg == 9){
        R9 = temptotal;
    } else if (endreg == 10){
        R10 = temptotal;
    } else if (endreg == 11){
        R11 = temptotal;
    } else if (endreg == 12){
        R12 = temptotal;
    } else if (endreg == 13){
        R13 = temptotal;
    } else if (endreg == 14){
        R14 = temptotal;
    } else if (endreg == 15){
        R15 = temptotal;
    } else {
        printf("Invalid register/value");
    }
}

void movFunc (int endreg, int val1var)
{
    printf("movFunc vars:\n");
    printf("%i\n", endreg);
    printf("%i\n", val1var);

    if (endreg == 0){                                                                                               
        R0 = val1var;
    } else if (endreg == 1){
        R1 = val1var;
    } else if (endreg == 2){
        R2 = val1var;
    } else if (endreg == 3){
        R3 = val1var;
    } else if (endreg == 4){
	R4 = val1var;
    } else if (endreg == 5){
	R5 = val1var;
    } else if (endreg == 6){
	R6 = val1var;
    } else if (endreg == 7){
	R7 = val1var;
    } else if (endreg == 8){
	R8 = val1var;
    } else if (endreg == 9){
	R9 = val1var;
    } else if (endreg == 10){
	R10 = val1var; 
    } else if (endreg == 11){ 
	R11 = val1var;
    } else if (endreg == 12){
	R12 = val1var;
    } else if (endreg == 13){
	R13 = val1var;
    } else if (endreg == 14){
	R14 = val1var;
    } else if (endreg == 15){
	R15 = val1var;
    } else {
	printf("Invalid register/value");
    }

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
        //printf("You entered: ");
        puts(inputstr);    // display string
        
        char *frag = strtok(inputstr, " ");
        int counter = 0;
        
        // loop through the string to split at each " "
        while( frag != NULL ) 
        {
            //printf( " %s\n", frag ); //printing each
            argsstr[counter++] = frag;
            frag = strtok(NULL, " ");
        }
        
        //add each frag into new array (argsstr)
        //int p;
       // for (p = 0; p < counter; ++p)
        //{
         //   printf( "%s\n", argsstr[p]) ;
        //}
        
        printf("Instruction: %s", argsstr[0]);

	//sets registers/values
        int regVar, val1var, val2var;
	regVar = regnumFunc(value, argsstr[1]);
	if (isdigit(regVar))
	{
	   printf("regVar int is: %d\n", regVar);
	} else {
	   regVar = numberFunc(regVar, argsstr[1]);
	   printf("final int from main: %d\n", regVar);
	} 
	    
	val1var = regnumFunc(value, argsstr[2]);
	if (isdigit(val1var))
	{
	   printf("val1var int is: %d\n", val1var);
	} else {
	   val1var = numberFunc(val1var, argsstr[2]);
	   printf("final int from main: %d\n", val1var);
	}

	val2var = regnumFunc(value, argsstr[3]);
	if (isdigit(val2var))
	{
	   printf("val2var int is: %d\n", val2var);
	} else {
	   val2var = numberFunc(val2var, argsstr[3]);
	   printf("final int from main: %d\n", val2var);
	}
	
	//instruction calls
        if (strcmp(argsstr[0], "add") == 0)
        {
            //printf("\ncall add func\n"); // want to give the function, the rest of the input string
            addFunc(regVar, val1var, val2var); //passing the inst to addFunc
	    regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
        } 
        else if (strcmp(argsstr[0], "mov") == 0)
        {
            //printf("\ncall move func\n");
            movFunc(regVar, val1var);
	    regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
        } 
        else 
        {
            printf("Unknown instruction");
        }
    }
    
    
    //out of while loops, exits
    return 0;
}

int regnumFunc(int value, char* input)
{
   
   char num[32];
   int n = 0;
   int finalint =0;
   printf("%s", input); // %s is format specifier
   if (input[0] == 'r') {
      //printf("First char is r, register detected \n");
      
      for (int i = 1; isdigit(input[i]);)
      {
	//printf("the first statement: %c\n", input[i]);
	num[i-1] = input[i];
	i++;
      }
      sscanf(num, "%d", &finalint);
      printf("Register: %d\n", finalint);
      value = finalint;

   } else {
      printf("not vaild input");
   }

   printf("Final register int: %d\n", value);
   return value;
}


void regPrintFunc(int R0, int R1, int R2, int R3, int R4, int R5, int R6, int R7, int R8, int R9, int R10, int R11, int R12, int R13, int R14, int R15)
{
    printf("\n**** REGISTERS. ****");
    printf("\n*   R0:  %d", R0);
    printf("\n*   R1:  %d", R1);
    printf("\n*   R2:  %d", R2);
    printf("\n*   R3:  %d", R3);
    printf("\n*   R4:  %d", R4);
    printf("\n*   R5:  %d", R5);
    printf("\n*   R6:  %d", R6);
    printf("\n*   R7:  %d", R7);
    printf("\n*   R8:  %d", R8);
    printf("\n*   R9:  %d", R9);
    printf("\n*  R10:  %d", R10);
    printf("\n*  R11:  %d", R11);
    printf("\n*  R12:  %d", R12);
    printf("\n*  R13:  %d", R13);
    printf("\n*  R14:  %d", R14);
    printf("\n*  R15:  %d", R15);
    printf("\n********************\n\n");
}
    
    
