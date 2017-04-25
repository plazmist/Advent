#include "stdio.h"
#include "stdlib.h"
#include "string.h"

FILE *input;
char Key[6]={0};
char rKey[6]={0};

char *CntAlph(char * Code)
{
	char chCnt[30] = {0}; // +97
	for (int i = 0; i < strlen(Code); ++i)
		chCnt[Code[i]-97]++;
	int maxi;
	for (int i = 0; i < 5; ++i)
	{
		maxi=0;
		for (int j = 1; j < 26; ++j)
			if (chCnt[j] > chCnt[maxi]) {maxi = j;}
		rKey[i]=maxi+97;
		chCnt[maxi]=0;
	}
	//printf("Key = %s\n", rKey);
	return rKey;
}

void Part1(){
 	int cnt=1,maxi;
 	char Row[10]={0};
 	char chCnt[30] = {0}; // +97
 	char Answer[]="________";

 	for (int sym = 0; sym < 8; ++sym)
 	{
	 	for (int i = 0; i < 29; ++i) chCnt[i] = 0;

		while (!feof(input)) {
			fscanf(input, "%s", Row);
			chCnt[Row[sym]-97]++;
			//printf("[%d] %s [%d]=%c \n",cnt++,Row,sym, Row[sym]);
	    }
	    rewind(input);

	    for (int i = 97; i < 123; ++i)	printf("%c ",i);
	    printf("\n");
	    for (int i = 0; i < 26; ++i)    printf("%d ", chCnt[i]);
	    maxi=0;
		for (int j = 1; j < 26; ++j)
			if (chCnt[j] > chCnt[maxi]) {maxi = j;}
		printf("Max [%d] = %c\n", sym, maxi+97);
		Answer[sym] = maxi+97;
	}
	printf("Answer = \"%s\" \n", Answer);
}


void Part2(){
 	int cnt=1,maxi;
 	char Row[10]={0};
 	char chCnt[30] = {0}; // +97
 	char Answer[]="________";

 	for (int sym = 0; sym < 8; ++sym)
 	{
	 	for (int i = 0; i < 29; ++i) chCnt[i] = 0;

		while (!feof(input)) {
			fscanf(input, "%s", Row);
			chCnt[Row[sym]-97]++;
			//printf("[%d] %s [%d]=%c \n",cnt++,Row,sym, Row[sym]);
	    }
	    rewind(input);

	    for (int i = 97; i < 123; ++i)	printf("%c ",i);
	    printf("\n");
	    for (int i = 0; i < 26; ++i)    printf("%d ", chCnt[i]);
	    maxi=0;
		for (int j = 1; j < 26; ++j)
			if (chCnt[j] < chCnt[maxi]) {maxi = j;}
		printf("Max [%d] = %c\n", sym, maxi+97);
		Answer[sym] = maxi+97;
	}
	printf("Answer = \"%s\" \n", Answer);
}


int main(int argc, char const *argv[])
{
	// 97 = a
	// 122 = z
	input=fopen("2016_day_6.txt", "rt");
 	//Part1();
 	Part2();

	fclose(input);
	return 0;
}


//cyxeoc