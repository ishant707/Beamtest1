
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 2613
#define MAX_COLS 128
#define MAX_APR 64

void CFBfun(float delay[MAX_ROWS][MAX_APR], float data[MAX_ROWS][MAX_COLS], float bf[MAX_ROWS]) {

	  float temp[MAX_ROWS];
	  int z1=0;

	  int num_lines = 0;


		for (int s=0; s<MAX_ROWS; s++)
	    {
	        for(int t=0; t<MAX_COLS; t++)
	        {
	            z1 = delay[s][t];
				if (z1==0){
					continue;
				}
				else {

	            temp[s] = temp[s] + data[z1][t];
				}
	        }

	    }

		for (int s=0;s<MAX_ROWS;s++)
		{
			bf[s] = temp[s];
			temp[s]=0;

		}

}
