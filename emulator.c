#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXCHAR 1000

int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;

int numFunc(int, char, char, char);
int regFunc(int, char, char);
void storeRegFunc(char, char, int);

int main() {
	//Set up for file read
	FILE *fp;
	char* filename = "input";

	//Open file
	fp = fopen(filename, "r");

	//Close program is file cannot be found/opened
	if (fp == NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	
	//Define line and PC
	char line[MAXCHAR];
	int PC = 4; 	//Set at 4 so line PC for x = x*4

	//Get line by line from file
	while (fgets(line, MAXCHAR, fp) != NULL)
	{
		//Prints iput line
		printf("Line is: %s", line);
		printf("  PC: %i\n", PC);		

		//Split line into elements

		char newline[MAXCHAR];

		//Method for removing leading whitespace
        int x = 0; 
		if (isalpha(line[0]) || isdigit(line[0]))
		{
			//Line starts with letter or digit
			//Stores in new line --> sends to label
			for (int i = 0; i <= 20;)
			{
				newline[i] = line[x];
				i++;
				x++;
			}

		} else {
			//Line starts with some whitescape char
			//While loop determines index of first non-ws char (int x)
			while (isspace(line[x]) > 0)
			{
				x++;
			}
			//For loop removes the leading ws
			for (int i = 0; i <= 20;)
			{
				newline[i] = line[x];
				i++;
				x++;
			}
		}

		//Extracts Instruction
		int c = PC;
		int index = 0;
		char instruction[MAXCHAR];
		//Store instruction in var

		if (isalpha(newline[index]) > 0)
		{
			instruction[PC] = newline[index];
			if (isalpha(newline[index+1]) > 0)
			{
				instruction[PC+1] = newline[index+1];
				if (isalpha(newline[index+2]) > 0)
				{
					instruction[PC+2] = newline[index+2];
					if (isalpha(newline[index+3]) > 0)
					{
						instruction[PC+3] = newline[index+3];
					} else {
						instruction[PC+3] = '\0';
					}
				} else {
					instruction[PC+2] = '\0';
				}
			} else {
				instruction[PC+1] = '\0';
			}
		} else {
			instruction[PC] = '\0';
		}

		//Identifies if line is a label
		if (strstr(newline, ":") != NULL)
		{
			char* labelarr = strtok(newline, ":");
			printf("\tThis is a label: %s\n", labelarr);
			//TODO - must store the labels for later use - with their PC values
		}	

		//Extracts element1		
		char element1[MAXCHAR];
		int vars = isspace(newline[index]);
		while (isspace(newline[index]) == 0)
		{
			index++;
		} 
		index++;

		if (isalpha(newline[index]) > 0 || isdigit(newline[index]) > 0)
		{
			element1[PC] = newline[index];
			if (isalpha(newline[index+1]) > 0 || isdigit(newline[index+1]) > 0)
			{
				element1[PC+1] = newline[index+1];
				if (isalpha(newline[index+2]) > 0 || isdigit(newline[index+2]) > 0)
				{
					element1[PC+2] = newline[index+2];
					if (isalpha(newline[index+3]) > 0 || isdigit(newline[index+3]) > 0)
					{
						element1[PC+3] = newline[index+3];
					} else {
						element1[PC+3] = '\0';
					}
				} else {
					element1[PC+2] = '\0';
				}
			} else {
				element1[PC+1] = '\0';
			}
		} else {
			element1[PC] = '\0';
		}		

		//Extrscts element2
		char element2[MAXCHAR];
		while (isspace(newline[index]) == 0)
		{
			index++;
		}
		index++;

		if (isalpha(newline[index]) > 0 || isdigit(newline[index]) > 0 || newline[index] == '#')
		{
			element2[PC] = newline[index];
			if (isalpha(newline[index+1]) > 0 || isdigit(newline[index+1]) > 0 || newline[index] == '#')
			{
				element2[PC+1] = newline[index+1];
				if (isalpha(newline[index+2]) > 0 || isdigit(newline[index+2]) > 0 || newline[index] == '#')
				{
					element2[PC+2] = newline[index+2];
					if (isalpha(newline[index+3]) > 0 || isdigit(newline[index+3]) > 0 || newline[index] == '#')
					{
						element2[PC+3] = newline[index+3];
					} else {
						element2[PC+3] = '\0';
					}
				} else {
					element2[PC+2] = '\0';
				}
			} else {
				element2[PC+1] = '\0';
			}
		} else {
			element2[PC] = '\0';
		}

		//Extracts element3
		char element3[MAXCHAR];
		while (isspace(newline[index]) == 0)
		{
			index++;
		}
		index++;

		if (isalpha(newline[index]) > 0 || isdigit(newline[index]) > 0 || newline[index] == '#')
		{
			element3[PC] = newline[index];
			if (isalpha(newline[index+1]) > 0 || isdigit(newline[index+1]) > 0 || newline[index] == '#')	
			{
				element3[PC+1] = newline[index+1];
				if (isalpha(newline[index+2]) > 0 || isdigit(newline[index+2]) > 0 || newline[index] == '#')
				{
					element3[PC+2] = newline[index+2];
					if (isalpha(newline[index+3]) > 0 || isdigit(newline[index+3]) > 0 || newline[index] == '#')
					{
						element3[PC+3] = newline[index+3];
					} else {
						element3[PC+3] = '\0';
					}
				} else {
					element3[PC+2] = '\0';
				}
			} else {
				element3[PC+1] = '\0';
			}
		} else {
			element3[PC] = '\0';
		}				



		//Instruction read and calls
		//ADD
		if (instruction[PC] == 'a' && instruction[PC+1] == 'd' && instruction[PC+2] == 'd' && instruction[PC+3] == '\0')
		{
			int value = 0;
			int e2int, e3int;
			if (element2[PC] == '#')
			{
				e2int = numFunc(value, element2[PC+1], element2[PC+2], element2[PC+3]);
			} else if (element2[PC] == 'r') {
				e2int = regFunc(value, element2[PC+1], element2[PC+2]);
			} else {
				printf("Invalid input\n");
			}
			if (element3[PC] == '#')
			{
				e3int = numFunc(value, element3[PC+1], element3[PC+2], element3[PC+3]);
			} else if (element3[PC] == 'r') {
				e3int = regFunc(value, element3[PC+1], element3[PC+2]);
			} else {
				printf("Invalid inputi - here\n"); 
			}

			value = e2int + e3int;
			printf("\tvalue: %d\n",value);
			storeRegFunc(element1[PC+1], element1[PC+2], value);
			regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
			
		//MOV
		} else if (instruction[PC] == 'm' && instruction[PC+1] == 'o' && instruction[PC+2] == 'v' && instruction[PC+3] == '\0')
		{
			int value = 0;
			int e2int;			
			if (element2[PC] == '#')
			{
				e2int = numFunc(value, element2[PC+1], element2[PC+2], element2[PC+3]);
			} else if (element2[PC] == 'r') {
				e2int = regFunc(value, element2[PC+1], element2[PC+2]);
			} else {
				printf("Invalid inputi - here\n");
			}
	
			storeRegFunc(element1[PC+1], element1[PC+2], e2int);
			regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);

		//SWI
		} else if (instruction[PC] == 's' && instruction[PC+1] == 'w' && instruction[PC+2] == 'i' && instruction[PC+3] == '\0')
        {   
			if (element1[PC] == "0")
			{
				printf("SWI Function Interrupt\n\n");
			} else {
				printf("SWI System Exit\n\n");
				fclose(fp);
				return 0;
			}
		//SUB
        } else if (instruction[PC] == 's' && instruction[PC+1] == 'u' && instruction[PC+2] == 'b' && instruction[PC+3] == '\0')
		{
			int value = 0;
			int e2int, e3int;
			if (element2[PC] == '#')
			{
				e2int = numFunc(value, element2[PC+1], element2[PC+2], element2[PC+3]);
			} else if (element2[PC] == 'r') {
                e2int = regFunc(value, element2[PC+1], element2[PC+2]);
            } else {
                printf("Invalid input\n");
            }
            if (element3[PC] == '#')
            {
                e3int = numFunc(value, element3[PC+1], element3[PC+2], element3[PC+3]);
            } else if (element3[PC] == 'r') {
                e3int = regFunc(value, element3[PC+1], element3[PC+2]);
            } else {
                printf("Invalid inputi - here\n");
            }

            value = e2int - e3int;
            printf("\tvalue: %d\n",value);
            storeRegFunc(element1[PC+1], element1[PC+2], value);
            regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
		}


		PC = PC + 4;

	}

	printf("\n");
}

//Function to convert # inpurs to ints
int numFunc(int value, char char1, char char2, char char3)
{

	char number[10];
	int c = 0;
	if (isdigit(char1))
	{
		number[c] = char1;
	} else {
		number [c] = '\0';
	}
	if (isdigit(char2))
	{
		number[c+1] = char2;
	} else {
		number[c+1] = '\0';
	}
	if (isdigit(char3))
	{
		number[c+2] = char3;
	} else {
		number[c+2] = '\0';
	}

	int finalint = 0;	
	sscanf(number, "%d", &finalint);
	value = finalint;

	return value;
}

//Function to load register value as int
int regFunc(int value, char char1, char char2)
{
	if (char1 == '1')
	{
		if (char2 == ',')
		{
			value = R1;
		} else if (char2 == '1')
		{
			value = R11;
		} else if (char2 == '2')
		{
			value = R12;
		} else if (char2 == '3')
		{
			value = R13;
		} else if (char2 == '4')
		{
			value = R14;
		} else if (char2 == '5')
		{
			value = R15;
		} else if (char2 == '0')
		{
			value = R10;
		}
	} else if (char1 == '2')
	{
		value = R2;
	} else if (char1 == '3')
	{
		value = R3;
	} else if (char1 == '4')
	{
		value = R4;
	} else if (char1 == '5')
	{
		value = R5;
	} else if (char1 == '6')
	{
		value = R6;
	} else if (char1 == '7')
	{
		value = R7;
	} else if (char1 == '8')
	{
		value = R8;
	} else if (char1 == '9')
	{
		value = R9;
	} else {
		printf("Invalid register");
	}

	return value;
}

//Function to store final value in desired reg
void storeRegFunc(char char1, char char2, int store)
{
	
	if (char1 == '1')
	{
		if (char2 == '\0')
		{
			R1 = store;
		} else if (char2 == '1')
		{
			R11 = store;
		} else if (char2 == '2')
		{
			R12 = store;
		} else if (char2 == '3')
		{
			R13 = store;
		} else if (char2 == '4')
		{
			R14 = store;
		} else if (char2 == '5')
		{
			R15 = store;
		} else if (char2 == '0')
		{
			R10 = store;
		}
	} else if (char1 == '2')
	{
		R2 = store;
	} else if (char1 == '3')
	{
		R3 = store;
	} else if (char1 == '4')
	{
		R4 = store;
	} else if (char1 == '5')
	{
		R5 = store;
	} else if (char1 == '6')
	{
		R6 = store;
	} else if (char1 == '7')
	{
		R7 = store;
	} else if (char1 == '8')
	{
		R8 = store;
	} else if (char1 == '9')
	{
		R9 = store;
	} else {
		printf("Invalid register");
	}	
}

//Prints all registers and values
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
