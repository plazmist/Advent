#include "stdio.h"
#include "stdlib.h"
#include <vector>

FILE *input;

int chkTrngl(int a, int b ,int c)
{
	if ((a+b > c) && (a+c >b) && (b+c > a)) return 1;
	return 0;
}

void Part1(){
 	int a,b,c, cnt=1,good=0;
	while (!feof(input)) {
		fscanf(input, "%d %d %d", &a,&b,&c);
		printf("[%d] %d %d %d\n",cnt++,a,b,c );
		good += chkTrngl(a,b,c);
    }
    printf("Good = %d\n", good);
}

void Part2(){
	 	int a1,a2,a3,b1,b2,b3,c1,c2,c3, cnt=1,good=0;
	while (!feof(input)) {
		fscanf(input, "%d %d %d", &a1,&b1,&c1);
		fscanf(input, "%d %d %d", &a2,&b2,&c2);
		fscanf(input, "%d %d %d", &a3,&b3,&c3);
		//printf("[%d] %d %d %d\n",cnt++,a,b,c );
		good += chkTrngl(a1,a2,a3) + chkTrngl(b1,b2,b3) + chkTrngl(c1,c2,c3);
    }
    printf("Good = %d\n", good);

}

int main(int argc, char const *argv[])
{

	input=fopen("2016_day_3_p1.txt", "rt");
 	Part2();
	fclose(input);
	return 0;
}
