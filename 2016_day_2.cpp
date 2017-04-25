#include "stdio.h"
#include "stdlib.h"
#include <vector>


int Pad[3][3]=
{
	{1,2,3},
	{4,5,6},
	{7,8,9}
};

int main(int argc, char const *argv[])
{
	FILE *input;
	input=fopen("2016_day_2.txt", "rt");
  	
  	char * line = NULL;
    size_t len = 0;
    ssize_t length;

    char x=1,y=1;

	while ((length = getline(&line, &len, input)) != -1) {
        //printf("Retrieved line of length %zu :\n", length);
        //printf("%s", line);
        for (int i = 0; i < length-1; ++i)
        {
        	switch(line[i]) {
			case 'U' : 
				if (y > 0) y-=1;
				break;
			case 'R' :
				if (x < 2) x+=1;
				break;
			case 'D' :
				if (y < 2) y+=1;
				break;
			case 'L' :
				if (x > 0) x-=1; 
				break;
			default :
         		printf("Invalid move = %c\n", line[i]);
			}
			//printf("%d-", Pad[y][x] );
        }
        printf("\n===== Last digit = %d\n\n", Pad[y][x] );
    }
	fclose(input);
	return 0;
}

