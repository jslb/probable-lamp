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
	
	//Define line
	char line[MAXCHAR];

	//Get line by line from file
	while (fgets(line, MAXCHAR, fp) != NULL)
	{
		//Prints iput line
		printf("Line is: %s", line);
		
		//Split line into elements

		char newline[MAXCHAR];

		//Method for removing leading whitespace
        int x = 0; 
		if (isalpha(line[0]) || isdigit(line[0]))
		{
			//Line starts with letter or digit
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
		int c = 0;
		char instruction[10] = "";
		//Store instruction in var
		while (isalpha(newline[c]) > 0)
		{
			instruction[c] = newline[c];
			c++;
		}
		
		//Extracts element1
		int nc = 0;
		char element[10] = "";
		while (isspace(newline[c]) < 0)		
		{
			element[nc] = newline[c];
			c++;
			nc++; 
		}
		int nnc = 0;
		char element1[10] = "";
		c++;

		while (isspace(newline[c]) == 0)
		{
			element1[nnc] = newline[c];
			c++;
			nnc++;
		}
		
		//Extracts element2
		char element2[10] = "";
		c++;
		nnc = 0;
		while (isspace(newline[c]) == 0 )
		{
			element2[nnc] = newline[c];
			c++;
			nnc++;
		}

		//Etracts element3
		char element3[10] = "";
		c++;
		nnc = 0;
		while (isspace(newline[c]) == 0)
		{
			element3[nnc] = newline[c];
			c++;
			nnc++;
		}

		
		//printf("%s\n", newline); 
		printf("Instuction: %s\n", instruction);
		printf("\tElement 1:%s\n", element1);
		printf("\tElement 2:%s\n", element2);
		printf("\tElement 3:%s\n", element3);
	}

	printf("\n");
}
