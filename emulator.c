#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXCHAR 1000

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
		printf("PC: %i\n", PC);		

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

/*
		while (isalpha(newline[index]) > 0)
		{
			instruction[c] = newline[index];
			index++;
			c++;
		}
*/		
		//printf("\tInstruction: '%c%c%c' ", instruction[PC], instruction[PC+1], instruction[PC+2]);
		
		//If the next char is as ':'
		//Store as label var
		//Set instruction as blank
		char labelstr[10] = "";
		int d = 0;
		if (newline[index] == ':')
		{
			while (isalpha(newline[d]) > 0)
			{
				labelstr[d] = newline[d];
				d++;
			}

			printf("This is a label: %s\n", labelstr);
			
		}

		//Extracts element1
		
		char element1[MAXCHAR];
		d = PC;
		index = index + 1;
		while (isspace(newline[index]) == 0)		
		{
			element1[d] = newline[index];
			d++;
			index++; 
		}
		
		char element2[MAXCHAR];
		d = PC;
		index = index + 1;
		while (isspace(newline[index]) == 0)
		{
			element1[d] = newline[index];
			d++;
			index++;
		}

		char element3[MAXCHAR];
		d = PC;
		index = index + 1;
		while (isspace(newline[index]) == 0)
		{
			element2[d] = newline[index];
			d++;
			index++;
		}

		d = PC;
		index = index + 1;
		while (isspace(newline[index]) == 0)
		{
			element3[d] = newline[index];
			d++;
			index++;
		}

		//Store the instrction and element values in mem[PC]

		printf("\tInstruction: '%c%c%c' \n", instruction[PC], instruction[PC+1], instruction[PC+2]);
		printf("\tElement1: '%c%c%c' \n", element1[PC], element1[PC+1], element1[PC+2]);
		printf("\tElement2: '%c%c%c' \n", element2[PC], element2[PC+1], element2[PC+2]);
		printf("\tElement3: '%c%c%c' \n", element3[PC], element3[PC+1], element3[PC+2]);

		if (instruction[PC] == 'a' && instruction[PC+1] == 'd' && instruction[PC+2] == 'd' && instruction[PC+3] == '\0')
		{
			printf("ADD FUNC\n");
			//TODO
			//if if element2[PC] == '#' send to numFunc if == "r" sent to regFunc
			//if if element3[PC] == '#' send to numFunc if == "r" sent to regFunc 
			//add responses
			//use element1[PC+1], element1[PC+2]) to store value in reg
			//Call printRegFunc 
		} else if (instruction[PC] == 'm' && instruction[PC+1] == 'o' && instruction[PC+2] == 'v' && instruction[PC+3] == '\0')
		{
			printf("MOV FUNC\n");
		} else if (instruction[PC] == 's' && instruction[PC+1] == 'w' && instruction[PC+2] == 'i' && instruction[PC+3] == '\0')
        {   
            printf("SWI FUNC\n");
        }

		PC = PC + 4;

	}

	printf("\n");
}
