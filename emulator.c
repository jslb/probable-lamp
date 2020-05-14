#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Global Varvs declarations
#define MAXCHAR 1000
char instruction[MAXCHAR];
char labelarr[MAXCHAR];
char* labelarrstr;
char* storestr;
char element1[MAXCHAR];
char element2[MAXCHAR];
char element3[MAXCHAR];
char* labelex;
char* labelex1;
char ldrMEM[MAXCHAR];
int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;

int numFunc(int, char, char, char);
int regFunc(int, char, char);
void storeRegFunc(char, char, int);

//Global CMP variable
//	1 = e1>
//	2 = e1==e2
//	3 = e2>
int cmpGlob = 0;


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
	//Store in memory
	while (fgets(line, MAXCHAR, fp) != NULL)
	{
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
		printf("Line is: %s", newline);
		printf("\tPC: %i\n", PC);

		//Extracts Instruction
		int c = PC;
		int index = 0;
		//Store instruction in instruction[] at array inital index of PC
		//The nested loops here ensure that chars are copied across
		//If char is not a letter (as all instructions should be letters), closes with '\0'
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
		int labeli = PC*4;
		int temp = 0;
		if (strstr(newline, ":") != NULL)
		{
			labelarrstr = strtok(newline, ":");
			printf("\tThis is a label: '%s'\n", labelarrstr);
			//Stores char in labelarr with one -> one function of PC*4
			for (int i = 0; isalpha(labelarrstr[i]);)
			{
				labelarr[labeli] = labelarrstr[i];
				i++;
				labeli++;
			}
		}	

		//Identifies strings in line and stores to ldrMEM
		int stri = PC*4;
		int temp2 = 0;
		if (strstr(newline, "=") != NULL)
		{
			storestr = strtok(newline, "=");
			storestr = strtok(NULL, " \n");
			printf("\tThis line contains a string: '%s'\n", storestr);
			//Stores str in ldrMRM with same 1 -> 1 function as labelarrs
			for (int i = 0; isalpha(storestr[i]);)
			{
				ldrMEM[stri] = storestr[i];
				i++;
				stri++;
			}
		}

		//Extracts element1	
		int vars = isspace(newline[index]);
		while (isspace(newline[index]) == 0)
		{
			index++;
		} 
		index++;
		//Store element1 in array following imilar method to instruction store
		//All elements (bar instruction) may contain digits, this is reflected with a conditional OR
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

		//Extracts element2 
		while (isspace(newline[index]) == 0)
		{
			index++;
		}
		index++;
		//Store of element2 follows the same as element1
		//Element2 may also being with '#' or '[', reflected by OR
		if (isalpha(newline[index]) > 0 || isdigit(newline[index]) > 0 || newline[index] == '#' || newline[index] == '[')
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
		while (isspace(newline[index]) == 0)
		{
			index++;
		}
		index++;
		//Store of element3 follows the same as element2
		//Element2 may also being with '#', reflected by OR
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

		//Opcodes printed here
		char* OPCODE;
		//Pronts opcode based off instruction
		if (instruction[PC] == 'a' && instruction[PC+1] == 'd' && instruction[PC+2] == 'd' && instruction[PC+3] == '\0')
        {
			OPCODE = "0100";	
			printf("\tOPCODE: %c%c%c%c\n\n", OPCODE[0], OPCODE[1], OPCODE[2], OPCODE[3]);
		} else if (instruction[PC] == 'm' && instruction[PC+1] == 'o' && instruction[PC+2] == 'v' && instruction[PC+3] == '\0')
		{
			OPCODE = "1101";
			printf("\tOPCODE: %c%c%c%c\n\n", OPCODE[0], OPCODE[1], OPCODE[2], OPCODE[3]);
		} else if (instruction[PC] == 'c' && instruction[PC+1] == 'm' && instruction[PC+2] == 'p' && instruction[PC+3] == '\0')
		{
			OPCODE = "1010";
			printf("\tOPCODE: %c%c%c%c\n\n", OPCODE[0], OPCODE[1], OPCODE[2], OPCODE[3]);
		} else if (instruction[PC] == 's' && instruction[PC+1] == 'u' && instruction[PC+2] == 'b' && instruction[PC+3] == '\0')
		{
			OPCODE = "0010";
			printf("\tOPCODE: %c%c%c%c\n\n", OPCODE[0], OPCODE[1], OPCODE[2], OPCODE[3]);
		} else {
			OPCODE = " ";
			printf("\n");
		}


		//Increases PC for next line
		PC = PC + 4;

	} //closes first while loop 

	//closes the file reader
	fclose(fp);

	//Load and Execute
	//Set PC to 4 (First line)
	PC = 4;
	while (PC != 0) 
	{
		//Instruction read and calls
		//ADD
		if (instruction[PC] == 'a' && instruction[PC+1] == 'd' && instruction[PC+2] == 'd' && instruction[PC+3] == '\0')
		{
			int value = 0;
			int e2int, e3int;
			if (element2[PC] == '#')
			{
				//Send element2 to numFunc to return int
				e2int = numFunc(value, element2[PC+1], element2[PC+2], element2[PC+3]);
			} else if (element2[PC] == 'r') {
				//Send element2 to regFun to return value of reg
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

			//Final calulation for instruction
			value = e2int + e3int;
			//Use storeRegFunc to store value in desired register
			//Using element1 and the calculated final value
			storeRegFunc(element1[PC+1], element1[PC+2], value);
			//Print all registers using regPrintFunc
			regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
			
		//MOV
		} else if (instruction[PC] == 'm' && instruction[PC+1] == 'o' && instruction[PC+2] == 'v' && instruction[PC+3] == '\0')
		{
			int value = 0;
			int e2int;			
			if (element2[PC] == '#')
			{
				//Uses e2 and numFunc to retrive int
				e2int = numFunc(value, element2[PC+1], element2[PC+2], element2[PC+3]);
			} else if (element2[PC] == 'r') {
				//Uses e2 and regFunc to retreive register value int
				e2int = regFunc(value, element2[PC+1], element2[PC+2]);
			} else {
				printf("Invalid input - here\n");
			}
			//Store
			storeRegFunc(element1[PC+1], element1[PC+2], e2int);
			//Print all registers
			regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);

		//SWI
		} else if (instruction[PC] == 's' && instruction[PC+1] == 'w' && instruction[PC+2] == 'i' && instruction[PC+3] == '\0')
        {   
			if (element1[PC] == "0")
			{
				printf("SWI Function Interrupt\n\n");
			} else {
				printf("SWI System Exit\n\n");
				//SWI causes system exit
				return 0;
			}
		//SUB
        } else if (instruction[PC] == 's' && instruction[PC+1] == 'u' && instruction[PC+2] == 'b' && instruction[PC+3] == '\0')
		{
			int value = 0;
			int e2int, e3int;
			//Using element2 and element3 arrays, and numFunc and regFunc, retrive instruction ints
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

			//Perform calulation for instruction
            value = e2int - e3int;
			//Store and Print all registers
            storeRegFunc(element1[PC+1], element1[PC+2], value);
            regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);
		} else if (instruction[PC] == 'l' && instruction[PC+1] == 'd' && instruction[PC+2] == 'r' && instruction[PC+3] == '\0')
		{
			//Uses 1 -> 1 mapping to calcute the index at which the str in stored in the array
			//This index is then stored in the register
			int ldrindex = PC*4;
			storeRegFunc(element1[PC+1], element1[PC+2], ldrindex);
			regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);	

		} else if (instruction[PC] == 'l' && instruction[PC+1] == 'd' && instruction[PC+2] == 'r' && instruction[PC+3] == 'b')
		{
			//Loads byte using ldrMeM and ldrindex (stored usring ldr)
			int value = 0;
			int ldrindex = regFunc(value, element2[PC+2], element2[PC+3]);
			storeRegFunc(element1[PC+1], element1[PC+2], ldrMEM[ldrindex]);
			regPrintFunc(R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15);

		} else if (instruction[PC] == 'c' && instruction[PC+1] == 'm' && instruction[PC+2] == 'p' && instruction[PC+3] == '\0')
		{
			int value;
			int e1int, e2int;
			//Get e1 value 
			if (element1[PC] == '#')
			{
				e1int = numFunc(value, element1[PC+1], element1[PC+2], element1[PC+3]);
			} else if (element1[PC] == 'r') {
				e1int = regFunc(value, element1[PC+1], element1[PC+2]);
			} else {
				printf("Invalid input\n");
			}
			//Get e2 value
			if (element2[PC] == '#')
			{
				e2int = numFunc(value, element2[PC+1], element2[PC+2], element2[PC+3]);
			} else if (element2[PC] == 'r') {
				e2int = regFunc(value, element2[PC+1], element2[PC+2]);
			} else {
				printf("Invalid input\n");
			}
			//Compare and set CMP global var (cmpGlob) with result - see lines 23-27
			if(e1int == e2int)
			{
				printf("CMP result: =\n");
				cmpGlob = 2;
			} else if (e1int > e2int)
			{
				printf("CMP result: >\n");
				cmpGlob = 1;
			} else if (e1int < e2int)
			{
				printf("CMP reults: <\n");
				cmpGlob = 3;
			}
		} else if (instruction[PC] == 'b' && instruction[PC+1] == 'e' && instruction[PC+2] == 'q' && instruction[PC+3] == '\0')
		{
		//BEQ
			if (cmpGlob == 2) 
			{
				printf("Equal -> branch to: %c%c%c%c\n", element1[PC], element1[PC+1], element1[PC+2], element1[PC+3]);
				
				//Finds first occrance of element1[PC] in labelarr
				int labPC = 0;
				for (int i = 0; labelarr[i] != element1[PC];)
				{
					i++;
					labPC = i;
				}
				//Confirms the whole label matches
				int j = PC;
				for(int i = 0; i > 4;)
				{
					if(labelarr[labPC] == element1[j])
					{
						//chars match
					}else{
						//chars dont match
					}
					i++;
					j++;
					labPC++;
				}
				//Sets new PC to envoke the label
				labPC = labPC/4;
				PC = labPC;
				labPC = 0;
			} else if (cmpGlob == 1 || cmpGlob == 3)
			{
				printf("Not Equal");
			}
		} else if (instruction[PC] == 'b' && instruction[PC+1] == 'g' && instruction[PC+2] == 't' && instruction[PC+3] == '\0')
		{
		//BGT - Branch if previous CMP is greater than-- using cmpGlob
			if (cmpGlob == 1)
			{
				printf("E1 > E2 -> branch to: '%c%c%c%c'\n", element1[PC], element1[PC+1], element1[PC+2], element1[PC+3]);
				//Finds first occrance of element1[PC] in labelarr
				int labPC = 0;
				for (int i = 0; labelarr[i] != element1[PC];)
				{
					i++;
					labPC = i;
				}
				//Confirms the whole label matches
				int j = PC;
				for(int i = 0; i > 4;)
				{
					if(labelarr[labPC] == element1[j])
					{

					}else{

					}
					i++;
					j++;
					labPC++;
				}
				//Sets new PC to envoke the label
				labPC = labPC/4;
				PC = labPC;
				labPC = 0;
			} 

		} else if (instruction[PC] == 'b' && instruction[PC+1] == '\0' && instruction[PC+2] == '\0' && instruction[PC+3] == '\0')
		{
		//B
			printf("Branch to: '%c%c%c%c'\n", element1[PC], element1[PC+1], element1[PC+2], element1[PC+3]);
			//Finds first occrance of element1[PC] in labelarr
			int labPC = 0;
			for (int i = 0; labelarr[i] != element1[PC];)
			{
				i++;
				labPC++;
			}
			//Confirms the whole label matches
			int j = PC;
			for(int i = 0; i > 4;)
			{
				if(labelarr[labPC] == element1[j])
				{
			
				} else {
			
				}
				i++;
				j++;
				labPC++;
			}
			//Sets new PC to envoke the label
			labPC = labPC/4;
			PC = labPC;
			labPC = 0;
			
		} else {
			//if line is a label - move on, else invalid
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
		if (char2 == ',' || char2 == ']')
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
	} else if (char1 == '0')
	{
		value = R0;
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
	} else if (char1 == '0')
	{
		R0 = store;
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
