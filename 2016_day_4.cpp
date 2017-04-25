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
 	int a,b,c, cnt=1,sec,sum=0;
 	char Row[100]={0};
 	char Key[6]={0};
 	char  Code[100]={0}, Sector[5]={0};
 	char * pch;

	while (!feof(input)) {
		memset(&Code[0], 0, sizeof(Code));
		fscanf(input, "%s", Row);
		strncpy(Key, strchr(Row,'[')+1, 5);
		strncpy(Code,Row,strchr(Row,'[')-Row);
		strncpy(Sector,strchr(Row,'[')-3,3);
		sec = atoi(Sector);
		CntAlph(Code);
		printf("[%d] %s [%s] - [%s]\n",cnt++,Code,Key,rKey);
		if (!strcmp(Key,rKey)) sum+=sec;
    }
    printf("Sum = %d\n", sum);
}

void Part2(){
 	int cnt=1,sec,ticks, tmp;
 	char Row[100]={0};
 	char Key[6]={0};
 	char Code[100]={0}, deCode[100]={0}, Sector[5]={0};

	while (!feof(input)) {
		memset(&Code[0], 0, sizeof(Code));
		fscanf(input, "%s", Row);
		strncpy(Key, strchr(Row,'[')+1, 5);
		strncpy(Code,Row,strchr(Row,'[')-Row-4);
		strncpy(Sector,strchr(Row,'[')-3,3);
		sec = atoi(Sector);
		ticks = sec % 26;
		strcpy(deCode,Code);
		for (int i = 0; i < strlen(deCode); ++i)
		{
			if (deCode[i] == 45) 
				deCode[i] = 32;
			else {
				tmp = deCode[i] + ticks;
				if (tmp > 122) tmp-=26;
				deCode[i] = tmp;
			}
		}
		printf("[%d] %s [%d] - ticks = %d \n    %s\n",cnt++,Code,sec,ticks, deCode);
    }

}

int main(int argc, char const *argv[])
{
	// 97 = a
	// 122 = z
	input=fopen("2016_day_4.txt", "rt");
 	//Part1();
 	Part2();

	fclose(input);
	return 0;
}
