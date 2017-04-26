#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

#define clear() printf("\033[H\033[J")
#define NBots 210

FILE *input;

struct bot{
	int low;
	int high;
	int lowTo;
	int highTo;
} Bots[NBots];

int outPut[30];

void zeroBotsInit(){
	for (int i = 0; i < NBots; ++i)
	{
		Bots[i].low = -1;
		Bots[i].high = -1;
		Bots[i].lowTo = -1;
		Bots[i].highTo = -1;
	}
	for (int i = 0; i < 30; ++i)
		outPut[i] = -2;
}

void printBots(){
	for (int i = 0; i < NBots; ++i)
	{
		printf("Bot[%d]  (%d,%d)-> (%d,%d)",i, Bots[i].low, Bots[i].high, Bots[i].lowTo, Bots[i].highTo);
		if (Bots[i].lowTo >= 1000)  printf(" low to Output[%d]", Bots[i].lowTo-1000);
		if (Bots[i].highTo >= 1000) printf(" high to Output[%d]", Bots[i].highTo-1000);
		printf("\n");
	}
}

void printOutPut(){
	for (int i = 0; i < 30; ++i)
		printf("%d, ",outPut[i] );
	printf("\n");
}

int valToBot(int toBot,int val){
	int cnt = 0;
	if (toBot >= 1000) { cnt = toBot-1000; outPut[cnt] = val; printf("processing %d to Output[%d], now = %d\n", val, cnt, outPut[cnt] ); printOutPut(); return 0;}
	printf("\t\tWas Bot[%d] has (%d,%d) \n", toBot, Bots[toBot].low, Bots[toBot].high);
	if ( Bots[toBot].low == -1 ) Bots[toBot].low = val;
			else if (Bots[toBot].low < val)  Bots[toBot].high = val;
				 else { Bots[toBot].high = Bots[toBot].low; Bots[toBot].low = val;}
	printf("\t\tNow Bot[%d] has (%d,%d) \n", toBot, Bots[toBot].low, Bots[toBot].high);
	return 0;
}

void Parse(){
	int rowCnt=0,val,toBot,to1,to2;
	char Row[100]={0};
	while (!feof(input)) {
		fgets(Row,100,input);
		//printf("[%d] +-%s\n",rowCnt++,Row);
		if ( strstr(Row,"value") ){
			sscanf(Row,"value %d goes to bot %d",&val,&toBot);
			valToBot(toBot,val);
		} 
		if ( strstr(Row,"gives low to output") && strstr(Row,"and high to output") ) {
			sscanf(Row,"bot %d gives low to output %d and high to output %d",&toBot,&to1,&to2);
			Bots[toBot].lowTo = to1+1000;
			Bots[toBot].highTo = to2+1000;
		}
		if ( strstr(Row,"gives low to output") && strstr(Row,"and high to bot") ) {
			sscanf(Row,"bot %d gives low to output %d and high to bot %d",&toBot,&to1,&to2);
			Bots[toBot].lowTo = to1+1000;
			Bots[toBot].highTo = to2;
		}
		if ( strstr(Row,"gives low to bot") && strstr(Row,"and high to bot") ) {
			sscanf(Row,"bot %d gives low to bot %d and high to bot %d",&toBot,&to1, &to2);
			Bots[toBot].lowTo = to1;
			Bots[toBot].highTo = to2;
		}
		rowCnt++;
	}
}

void Run(){
	int curPtr = 0; 
	int step = 0;
	while (true){ // (Bots[curPtr].low =! -1) && (Bots[curPtr].high =! -1) 
		//printf("Processing bot [%d] with (%d,%d)\n",curPtr, Bots[curPtr].low, Bots[curPtr].high );
		if ( (Bots[curPtr].low > -1) && (Bots[curPtr].high > -1) ) {
			step++;
			printf("{%d} Bot[%d] has (%d,%d) and will go to bot %d and bot %d\n", step, curPtr, Bots[curPtr].low, Bots[curPtr].high, Bots[curPtr].lowTo, Bots[curPtr].highTo);
			valToBot(Bots[curPtr].lowTo,Bots[curPtr].low);
			valToBot(Bots[curPtr].highTo,Bots[curPtr].high);
			Bots[curPtr].low = -1;
			Bots[curPtr].high = -1;
			curPtr = -1;
		}
		curPtr++;
		if (curPtr > NBots) {printf("EXCEEDED\n"); break;}
	}
	printf("\n\nLooks found thms! [%d]\n", curPtr);
	printOutPut();
}

int main(int argc, char const *argv[])
{
	//clear();
	input=fopen("2016_day10.txt", "rt");
	zeroBotsInit();
	Parse();
	printBots();
	printf("*****************************************************\n");
	printOutPut();
	Run();
	printBots();
	printf("*****************************************************\n");
	printOutPut();
	//clear();
	fclose(input);
	return 0;
}