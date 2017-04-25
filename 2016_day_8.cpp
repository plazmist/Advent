#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>



#define clear() printf("\033[H\033[J")
#define H 6
#define L 50



FILE *input;

char Lit[H][L];

void Draw(){
	for (int i = 0; i < H; ++i, printf("\n"))
		for (int j = 0; j < L; ++j)
			printf("%c",Lit[i][j]);
	printf("\n");
}

void rtColumn(int x,int count){
	char tmp;
	for (int c = 0; c < count; ++c){
		tmp = Lit[H-1][x];
		for (int i = H-1; i > 0; --i)
			Lit[i][x] = Lit[i-1][x];
		Lit[0][x] = tmp;
	}
}

void rtRow(int y,int count){
	char tmp;
	for (int c = 0; c < count; ++c){
		tmp = Lit[y][L-1];
		for (int i = L-1; i > 0; --i)
			Lit[y][i] = Lit[y][i-1];
		Lit[y][0] = tmp;
	}
}

void Screen(){
	char Row[100]={0};
	int cnt=0,intA,intB;
	while (!feof(input)) {
		fgets(Row,100,input);
		printf("[%d]%s\n",cnt++,Row);

		if (strstr(Row,"rect")){

			sscanf(Row,"rect %dx%d", &intA,&intB);
			printf("rect %dx%d\n",intA,intB);
			for (int i = 0; i < intA; ++i)
				for (int j = 0; j < intB; ++j)
				{
					Lit[j][i]='#';
				}
		}
		//rotate column x=1 by 1
		if (strstr(Row,"column")){
			sscanf(Row,"rotate column x=%d by %d", &intA,&intB);
			printf("coloumn x = \"%d\" by \"%d\"\n",intA,intB);
			rtColumn(intA,intB);
		}
		//rotate row y=0 by 4
		if (strstr(Row,"row")){
			sscanf(Row,"rotate row y=%d by %d", &intA,&intB);
			printf("row y=%d by %d\n", intA,intB);
			rtRow(intA,intB);
		}

		Draw();
	}
}


int main(int argc, char const *argv[])
{
	//clear();
	int litted=0;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < L; ++j)
			Lit[i][j]='.';
	input=fopen("2016_day_8.txt", "rt");
	Draw();
	Screen();
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < L; ++j)
			if (Lit[i][j]=='#') litted++;
	printf("\nLitted = %d\n",litted );
/*	for (int i = 0; i < L*H; ++i)
	{
		//clear();
		Lit[rand()%H][rand()%L]='#';
		sleep(1);
		Draw();
	}*/
	//clear();
	fclose(input);
	return 0;
}

