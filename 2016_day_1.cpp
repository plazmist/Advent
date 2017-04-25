#include "stdio.h"
#include "stdlib.h"
#include <vector>

typedef struct
{
    int x;
    int y; 
} point;

int main(int argc, char const *argv[])
{
	FILE *input;
	input=fopen("2016_day_1.txt", "rt");
	point Points[160];
	int p_cnt=0;
	//std::vector<point> points;
	point tmp;
	char dr, g_dr='N';
	int cnt=0, Xcnt=0,Ycnt=0;
	while (!feof(input)) {
		fscanf(input, "%c%d, ", &dr,&cnt);

		switch(g_dr) {
			case 'N' : 
				if (dr == 'R') { g_dr ='E';}
				else { g_dr = 'W';}
				break;
			case 'E' :
				if (dr == 'R') {g_dr ='S';}
				else {g_dr = 'N'; } 
				break;
			case 'S' :
				if (dr == 'R') {g_dr ='W';}
				else {g_dr = 'E'; }
				break;
			case 'W' :
				if (dr == 'R') {g_dr ='N';}
				else {g_dr = 'S'; } 
				break;
			default :
         		printf("Invalid grade\n" );
		}
		switch(g_dr) {
			case 'N' : Ycnt+=cnt; break;
			case 'E' : Xcnt+=cnt; break;
			case 'S' : Ycnt-=cnt; break;
			case 'W' : Xcnt-=cnt; break;
			default  :
         		printf("Invalid grade\n" );
        }
        tmp.x = Xcnt;
        tmp.y = Ycnt;
        Points[p_cnt++]=tmp;
		printf("#%d: %c%d  -->  %c%d [%d,%d] \n",p_cnt,dr,cnt, g_dr,cnt, Xcnt,Ycnt); 
	}
	for (int j = 0; j < 160-1; ++j) {
		tmp = Points[j];
		for (int i = (j+1); i < 160; ++i)
		{
			if ((tmp.x == Points[i].x) && (tmp.y == Points[i].y))   
				printf("Found = [%d,%d](points %d and %d) = %d\n",Points[i].x, Points[i].y, j,i, abs( Points[i].x)+abs(Points[i].y) );
		}
	}
	printf("[FIN] Xcnt = %d, Ycnt = %d, [sum] = %d\n", Xcnt,Ycnt, abs(Xcnt)+abs(Ycnt) );
	return 0;
}

/*#43: L4  -->  E4 [16,22] 
#44: L190  -->  N190 [16,212] 

16, 143

#60: L2  -->  S2 [51,143] 
#61: R191  -->  W191 [-140,143] 
*/