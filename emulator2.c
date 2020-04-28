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
		int c = 0;
		char instruction[10] = "";
	
		while (isalpha(newline[c]) > 0)
		{
			instruction[c] = newline[c];
			c++;
		}

		char element1[10] = "";
		
		//c = c + 1;
		int nc = 0;
		while (isspace(newline[c]) < 0)		
		{
			element1[nc] = newline[c];
			c++;
			nc++; 
		}

		char element2[10] = "";

		c++;
		int nnc = 0;
		while (isspace(newline[c]) == 0)
		{
			element2[nnc] = newline[c];
			c++;
			nnc++;
		}

		//printf("%s\n", newline); 
		printf("Instuction: %s\n", instruction);
		printf("Element 1:%s\n", element1);
		printf("Element 2:%s\n", element2);
	}

	printf("\n");
}
