#include <stdio.h>
#include <ctype.h>
#include <string.h> 

//global vars
//Register declaration
int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;

int numberFunc(int, char[]);
int regnumFunc(int, char[]);
int value = 0;

int tempREG = 0;


#define MAXCHAR 1000
int main() {
    FILE *fp;
    char str[MAXCHAR];
	char finalstr[MAXCHAR];
	char label[MAXCHAR];
    char* filename = "input";
	int PC = 0; 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
	int linecount = 1;
	char *argsstr[10];
	char *instarr[10];
    while (fgets(str, MAXCHAR, fp) != NULL)
	{
        printf("Line %d is: %s", linecount, str);
		//linecount++;
		PC = PC+4;
		printf("PC: %d\n", PC);

		//if str contains : it is a label - store this as global var
			//change in label results in some other execution

		//then instruction string 
			//process instruction, registers and vars 

		//call instruction function

		//removes tab if input doesnt start with number or letter
		//write input to finalstr[]
		int finalstrindex = 0;
        if (isalpha(str[0]) || isdigit(str[0])){ 
			//printf("str start with a letter"); 
        //else if (isdigit(str[0])) 
			//printf("str starts with a number"); 
		}
		else {
			int n = sizeof(str)/sizeof(str[0]) - 2;
			for (int i = 1; i <= n;) {
				
				finalstr[finalstrindex] = str[i];
				i++;
				finalstrindex++;
			}
			//printf("firstchar of new -%c-\n", finalstr[0]);
		} 
		int z = 0;
		//detects label
		if (strstr(finalstr, ":") != NULL) { 
			//printf("Line %d is a label: %s\n", linecount, finalstr);
            for (int i = 0; finalstr[i] != ':';) {
				label[i] = finalstr[i];
				i++;
				z = i;
				//printf("i: %d\n", i);
			}
			label[z] = '\0';
			printf("Line %d is a label: %s\n", linecount, label);
			
		}
		else if (strstr(str, ":") != NULL ) {
			//printf("Line %d is a label: %s\n", linecount, str);
			for (int i = 0; str[i] != ':';) {
				label[i] = str[i];
				i++;
				z = i;
			}
			label[z] = '\0';
			printf("Line %d is a label: %s\n", linecount, label);
			
		} else {
			//split by tab - puts instrction in instarr[0]
			char* instfrag = strtok(finalstr, "\t");
			int count = 0;

			while( instfrag != NULL )
			{
				instarr[count++] = instfrag;
				instfrag = strtok(NULL, "\t");
			}		
			printf("Current label: %s\n", label);
			printf("Instruction: %s\n", instarr[0]);

			//split reaminer od line/string by ", "
			char* regfrag = strtok(instarr[1], ", ");
			int count2 = 0;

			while( regfrag != NULL )
			{
				argsstr[count2++] = regfrag;
				regfrag = strtok(NULL, ", ");
			}

			int regVar, val1var, val2var;

			regVar = regnumFunc(value, argsstr[0]);
			if (isdigit(regVar))
			{
				//printf("\nregVar int is: %d\n", regVar);
			} else {
				regVar = numberFunc(regVar, argsstr[0]);
				//printf("\nfinal int from main: %d\n", regVar);
			}

			val1var = regnumFunc(value, argsstr[1]);

			if (isdigit(val1var))
			{
				//printf("\nval1var int is: %d\n", val1var);
			} else {
				val1var = numberFunc(val1var, argsstr[1]);
				//val1var = 200;
				//printf("\nfinal int from main: %d\n", val1var);
			}

			if (argsstr[2] == NULL) {
				//here
			} else {
				val2var = regnumFunc(value, argsstr[2]);
				if (isdigit(val2var))
				{
					//printf("\nval2var int is: %d\n", val2var);
				} else {
					tempREG = numberFunc(val2var, argsstr[2]);
					//printf("\nfinal int from main: %d\n", val2var);
					val2var = 200;

				}
			}

			//instruction calls
			if (strcmp(instarr[0], "add") == 0)
			{
				addFunc(regVar, val1var, val2var); //passing to add function
				regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
			} else if (strcmp(instarr[0], "mov") == 0) 
			{	
				movFunc(regVar, val1var);
				regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
			} else {
				printf("Unknown Instruction\n\n");
			}
		}

		linecount++;
		str[0] = '\0';
		finalstr[0] = '\0';
		
    } 

	
    fclose(fp);
    return 0;
}


int regnumFunc(int value, char* input)
{

   char num[32];
   int n = 0;
   int finalint =0;
   //printf("\tregnumFunc - %s", input); // %s is format specifier
   if (input[0] == 'r') {
      //printf("First char is r, register detected \n");

      for (int i = 1; isdigit(input[i]);)
      {
   		//printf("the first statement: %c\n", input[i]);
		num[i-1] = input[i];
   		i++;
      }
      sscanf(num, "%d", &finalint);
      //printf("\tregnumFunc - Register: %d\n", finalint);
      value = finalint;

   } else {
      //printf("\tregnumFunc - not vaild input");
   }

   //printf("\tregnumFunc - Final register int: %d\n", value);
   return value;
}

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
	  tempREG = finalint;
	  printf("tempREG: %d", tempREG);
      value = finalint;
   } else {
      //printf("\tnumberFunc - Invaild input");
   }
   //printf("final int func: %d\n", value);
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

void movFunc (int endreg, int val1var)
{
    //printf("movFunc vars:\n");
    //printf("%i\n", endreg);
    //printf("%i\n", val1var);

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

//addFunction
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
	} else if (val2var == 200){
		temptotalvar2 = tempREG;
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
