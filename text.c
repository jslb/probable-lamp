#include <stdio.h>
int numberFunc(int, char[]);

int main ()
{
   int value = 0;
   value = numberFunc(value, "#789");
   printf("final int vmain: %d\n", value);
   return 0;
}


int numberFunc(int value, char* input)
{
   //char z[] = input;
   char num[32];

   printf("%s", input); // %s is format specifier
   int n = 0;
   int i = 0;
   int newindex = 0;
   int finalint = 0;
   n = sizeof(input)/sizeof(input[0]);
   int totchars = n - 1;
   int lastcharindex = totchars - 1;
   printf("Totalchars: %d\n", totchars);
   printf("Lastcharindex: %d\n", lastcharindex); 
   if (input[0] == '#') {
      printf("First char is hash\n");

      //n = sizeof(z)/sizeof(z[0]);
      
      //printf("%d\n", n);
      //n++;
      for (int i = 1; i <= lastcharindex;) {
	printf("Char at %d index = %c\n", i , input[i]);
	
        num[newindex] = input[i];
	i++;
	newindex++;
      }
      sscanf(num, "%d", &finalint);
      printf("int: %d\n", finalint);
      value = finalint;
   } else {
      printf("not vaild input");
   }

   printf("final int func: %d\n", value);
   return value;
}
