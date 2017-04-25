#include <stdio.h>
#include <stdlib.h>


#define SWAP(x,y) do {   \ 
   typeof(x) _x = x;      \
   typeof(y) _y = y;      \
   x = _y;                \
   y = _x;                \
} while(0)



int main() 
{
	FILE * pFile;
	pFile = fopen ("input-2-1.txt","rt");
	int a,b,c,num=0;
  long int Sum=0;

  while(!feof(pFile))
{
  fscanf(pFile, "%dx%dx%d", &a,&b,&c);
  printf("%dx%dx%d=", a,b,c);
  if (a > c) SWAP(a, c);
  if (a > b) SWAP(a, b);
  if (b > c) SWAP(b, c);
  printf("%dx%dx%d; ", a,b,c);
  Sum += a+a+b+b+ a*b*c;
  a=b=c=0;
  num++;
}


  
  printf("\nThere are %d values", num);
  printf("\nSum = %ld", Sum);
	fclose (pFile);
	return 0;
}


