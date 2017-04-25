#include <stdio.h>
#include <stdlib.h>



int main() 
{
	FILE * pFile;
	pFile = fopen ("input-1-2.txt","rt");
	int i=0, num=1;
	char c='0';


  	while ((c = fgetc(pFile)) != EOF)
    {
       //printf("%c",(char) c);
       if ( c == '(' ) i++;
       if ( c == ')' ) i--;
       printf("%d, ", i);		
       if ( i == -1 ) printf ("\nSGOOD! n - %d\n", num);
       num++;
    }

	fclose (pFile);
	return 0;
}


