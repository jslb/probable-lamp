//this is the frag --ready for implementation
//this returns the regitser int var

#include <stdio.h>
#include <ctype.h>

int regnumFunc(int, char[]);

int main ()
{
   int value = 0;
   int value2 = 0;
   //char argsstr[2];
   char argsstr[] = "r2 ";
   char temp1[] = "r16, ";
   //printf("argsstr[0]: %c", argsstr[0]);
   value = regnumFunc(value, argsstr);
   value2 = regnumFunc(value2, temp1);
   printf("main value output: %d\n", value);
   printf("main value output: %d\n", value2);
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
