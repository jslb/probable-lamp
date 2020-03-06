#include <stdio.h>
int main()
{
   char z[] = "#564";
   char num[32];

   printf("%s", z); // %s is format specifier
   int n = 0;
   int i = 0;
   int newindex = 0;
   int finalint = 0;
   n = sizeof(z)/sizeof(z[0]);
   int totchars = n - 1;
   int lastcharindex = totchars - 1;
   printf("Totalchars: %d\n", totchars);
   printf("Lastcharindex: %d\n", lastcharindex); 
   if (z[0] == '#') {
      printf("First char is hash\n");

      //n = sizeof(z)/sizeof(z[0]);
      
      //printf("%d\n", n);
      //n++;
      for (int i = 1; i <= lastcharindex;) {
	printf("Char at %d index = %c\n", i , z[i]);
	
        num[newindex] = z[i];
	i++;
	newindex++;
      }
      sscanf(num, "%d", &finalint);
      printf("int: %d\n", finalint);
   } else {
      printf("not vaild input");
   }

   return 0;
}
