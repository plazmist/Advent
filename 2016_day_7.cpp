#include "stdio.h"
#include "stdlib.h"
#include "string.h"

FILE *input;

int checkABBA(char *input){
	for (int i = 0; i < strlen(input)-3; ++i)
		if ((input[i] != input[i+1]) && (input[i] == input[i+3]) && (input[i+1] == input[i+2]))
			return 1;
	return 0;
}

int checkRow(char *Row){


}

int checkTLS() {
	int cnt=0,TLS=0,cntTLS=0,ABBA=0,nABBA=0;
	char *curPtr;
	char Row[150]={0};
 	char Key[150]={0};
 	char outside[100]={0},inside[100]={0};
	while (!feof(input)) {
		ABBA = 0;
		nABBA = 0;
		fscanf(input, "%s", Row);
		printf("\n%s\n",Row );
		curPtr = Row;
		while (strchr(curPtr,']')) {
			memset(&outside[0], 0, sizeof(outside));
			memset(&inside[0], 0, sizeof(inside));
			strncpy(outside,curPtr,strchr(curPtr,'[')-curPtr);
			strncpy(inside,strchr(curPtr,'[')+1,strchr(curPtr,']')-strchr(curPtr,'[')-1);
			curPtr = strchr(curPtr,']') + 1;
			//printf("outside=\"%s\"\n", outside);
			//printf("inside =\"%s\"\n", inside);
			ABBA += checkABBA(outside);
			nABBA += checkABBA(inside);
		}
		memset(&outside[0], 0, sizeof(outside));
		strncpy(outside,curPtr,strlen(curPtr));
		//printf("outside=\"%s\"\n", outside);
		ABBA += checkABBA(outside);
		if ((ABBA > 0) && (nABBA==0)) cntTLS++;
		//printf("ZBS!!!\n");
		//if ((checkABBA(outside1) || checkABBA(outside2)) && !checkABBA(inside) ) TLS=1; else TLS=0;
		//printf("[%d] %s %s(%d)|%s(%d)|%s(%d) TLS=%d\n", cnt++, Row, outside1,checkABBA(outside1), inside,checkABBA(inside), outside2,checkABBA(outside2),TLS);
		//cntTLS += TLS;
	}
	printf("cntTLS = %d\n", cntTLS);
	return 0;
}

int checkSSL() {
	int cnt=0,SSL=0;
	char *curPtr;
	char Row[150]={0};
	char BAB[4]={0};

 	char outside[100]={0},inside[100]={0};
 	char allOutside[100]={0},allInside[100]={0};
	while (!feof(input)) {
		memset(&allOutside[0], 0, sizeof(allOutside));
		memset(&allInside[0], 0, sizeof(allInside));
		fscanf(input, "%s", Row);
		//printf("\n%s\n",Row );
		curPtr = Row;
		while (strchr(curPtr,']')) {
			memset(&outside[0], 0, sizeof(outside));
			memset(&inside[0], 0, sizeof(inside));
			strncpy(outside,curPtr,strchr(curPtr,'[')-curPtr);
			strncpy(inside,strchr(curPtr,'[')+1,strchr(curPtr,']')-strchr(curPtr,'[')-1);
			curPtr = strchr(curPtr,']') + 1;
			sprintf(allOutside,"%s %s", allOutside, outside);
			sprintf(allInside,"%s %s", allInside, inside);
		}
		memset(&outside[0], 0, sizeof(outside));
		strncpy(outside,curPtr,strlen(curPtr));
		sprintf(allOutside,"%s %s", allOutside, outside);
		//printf("allOutside=\"%s\"\n", allOutside);
		//printf("allInside=\"%s\"\n", allInside);
		for (int i = 0; i < strlen(allOutside)-2; ++i)
		{
			if ((allOutside[i]==allOutside[i+2]) &&(allOutside[i]!=allOutside[i+1]))
			{
				//printf("Outside foud \"%c%c%c\"\n", allOutside[i],allOutside[i+1],allOutside[i+2]);
				sprintf(BAB,"%c%c%c",allOutside[i+1],allOutside[i],allOutside[i+1]);
				if (strstr(allInside, BAB)) { 
					//printf("[Found]%s\n",BAB ); 
					SSL ++; 
					break;
				}
			}
		}
	}
	printf("SSL = %d\n", SSL);
	return 0;
}


int main(int argc, char const *argv[])
{
	// 97 = a
	// 122 = z
	input=fopen("2016_day_7.txt", "rt");

	checkSSL();
	fclose(input);
	return 0;
}