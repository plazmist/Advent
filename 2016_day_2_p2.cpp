#include "stdio.h"
#include "stdlib.h"
#include <vector>

char Pad[7][7]=
{
	{' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ','1',' ',' ',' '},
	{' ',' ','2','3','4',' ',' '},
	{' ','5','6','7','8','9',' '},
	{' ',' ','A','B','C',' ',' '},
	{' ',' ',' ','D',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' '}
};

int main(int argc, char const *argv[])
{
	FILE *input;
	input=fopen("2016_day_2.txt", "rt");
  	
  	char * line = NULL;
    size_t len = 0;
    ssize_t length;

    char x=1,y=3;

	while ((length = getline(&line, &len, input)) != -1) {
        //printf("Retrieved line of length %zu :\n", length);
        //printf("%s", line);
        for (int i = 0; i < length-1; ++i)
        {
        	switch(line[i]) {
			case 'U' : 
				if (Pad[x][y-1]!=' ') y-=1;
				break;
			case 'R' :
				if (Pad[x+1][y]!=' ') x+=1;
				break;
			case 'D' :
				if (Pad[x][y+1]!=' ') y+=1;
				break;
			case 'L' :
				if (Pad[x-1][y]!=' ') x-=1; 
				break;
			default :
         		printf("Invalid move = %c\n", line[i]);
			}
			//printf("%d-", Pad[y][x] );
        }
        printf("\n===== Last digit = %c\n\n", Pad[y][x] );
    }
	fclose(input);
	return 0;
}

