#include <stdio.h>
#include <ctype.h>
#include <string.h> 

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
		
		//detects label
		if (strstr(finalstr, ":") != NULL) { 
			printf("Line %d is a label: %s\n", linecount, finalstr);
		}
		else if (strstr(str, ":") != NULL ) {
			printf("Line %d is a label: %s\n", linecount, str);
		} else {
		
		//

		}

		linecount++;
		
    } 

	
    fclose(fp);
    return 0;
}
