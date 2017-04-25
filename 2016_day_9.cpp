#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

#define clear() printf("\033[H\033[J")

FILE *input;
FILE *output;

char Row[17000]={0};

void Decompress(){
	char Row[17000]={0}, Len[5],Rpt[5], Paste[17000]={0};
	int curPtr=0,cnt=0,iLen,iRpt,mainCnt=0;
	fscanf(input, "%s", Row);
	printf("[%d]\n",(int)strlen(Row));
	while (curPtr<(int)strlen(Row)){
		if (Row[curPtr]=='(') {
			memset(Len, 0, sizeof(Len));
			memset(Rpt, 0, sizeof(Rpt));
			memset(Paste, 0, sizeof(Paste));
			strncpy(Len,&Row[curPtr+1],strchr(&Row[curPtr+1],'x')-&Row[curPtr+1]); iLen = atoi(Len);
			strncpy(Rpt,strchr(&Row[curPtr+1],'x')+1,strchr(&Row[curPtr+1],')')-strchr(&Row[curPtr+1],'x') ); iRpt=atoi(Rpt);
			printf("Len = %s, Rpt = %s\n",Len, Rpt);
			curPtr += strchr(&Row[curPtr+1],')') - &Row[curPtr] + 1;
			/*strncpy(Paste,&Row[curPtr],iLen);
			printf("Will copy %d symbols:\n%s\n",iLen,Paste);
			for (int i = 0; i < iRpt; ++i)
				fprintf(output,"%s",Paste);
			*/curPtr += iLen;
			mainCnt += iLen*iRpt;
		}
		else { printf("%c ",Row[curPtr]); fprintf(output,"%c",Row[curPtr]); curPtr++; mainCnt++;}
	}
	printf("\n\nSo, the result length = %d\n",mainCnt );
}

long recDecompress(int start, int thisLen){
	char Len[5],Rpt[5];
	int curPtr = start, cnt = 0, iLen, iRpt;
	long mainCnt=0;
	while ( curPtr < start + thisLen ){
		if (Row[curPtr]=='(') {
			memset(Len, 0, sizeof(Len));
			memset(Rpt, 0, sizeof(Rpt));
			strncpy(Len,&Row[curPtr+1],strchr(&Row[curPtr+1],'x')-&Row[curPtr+1]); iLen = atoi(Len);
			strncpy(Rpt,strchr(&Row[curPtr+1],'x')+1,strchr(&Row[curPtr+1],')')-strchr(&Row[curPtr+1],'x') ); iRpt=atoi(Rpt);
			printf("Len = %s, Rpt = %s\n",Len, Rpt);
			curPtr += strchr(&Row[curPtr+1],')') - &Row[curPtr] + 1;
			//strncpy(Paste,&Row[curPtr],iLen);
			//printf("Will copy %d symbols:\n%s\n",iLen,Paste);
			//for (int i = 0; i < iRpt; ++i)
			//	fprintf(output,"%s",Paste);
			mainCnt += recDecompress(curPtr,iLen) * iRpt;
			curPtr += iLen;
		}
		else { 
			printf("%c ",Row[curPtr]); 
			fprintf(output,"%c",Row[curPtr]); 
			curPtr++; 
			mainCnt++;
		}
	}
	printf("\n\nSo, the result length = %ld\n",mainCnt );
	return mainCnt;
}

void callRecDec(){
	long theMainCnt=0;
	fscanf(input, "%s", Row);
	printf("[%d]\n",(int)strlen(Row));
	theMainCnt = recDecompress(0,(int)strlen(Row));
	printf("The Main Counter = %ld\n", theMainCnt);
}

int main(int argc, char const *argv[])
{
	//clear();
	input=fopen("2016_day_9.txt", "rt");
	output=fopen("2016_day_9.res", "w+");

	Decompress();
	//callRecDec();
	//clear();
	fclose(input);
	fclose(output);
	return 0;
}