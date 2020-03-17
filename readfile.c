#include <stdio.h>
#include <ctype.h>
 
#define MAXCHAR 1000
int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "input";
	int PC = 0; 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
	int linecount = 1;
    while (fgets(str, MAXCHAR, fp) != NULL)
	{
        printf("Line %d is: %s", linecount, str);
		linecount++;
		PC = PC+4;
		printf("PC: %d\n", PC);

		//if str contains : it is a label - store this as global var
			//change in label results in some other execution
		printf("firstchar -%c-\n", str[0]);	
		//then instruction string 
			//strip \t from beggining?
			//process instruction, registers and vars 

		//call instruction function



	}
    fclose(fp);
    return 0;
}
