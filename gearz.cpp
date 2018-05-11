#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void calcRotation(int numofgears, float** gears, int* requested_gears);

int main(int argc, char *argv[])
{
	FILE *inputfile;
	inputfile = fopen("inputs.txt", "r");
	
	if (inputfile == NULL) return NULL;
	
	
	int ch, line = 1, numofgears, i, count = -1, b = 0, j = 0;
	int requested_gears[4];
	float* gears;
	float** gears2;
	
	char buffer[32];
	
	while((ch=fgetc(inputfile)) != EOF)
	{
		
		//printf("stream reads: %c\n",ch);
		
		if(ch == '\n')
		{
			line++;
			//printf("line = %d\n", line);
		}
		else if(ch == ' ')
		{
			if(line == 1)
			{
		
				numofgears = atoi(buffer);
				for(i=0; i<=numofgears; i++)
				{
					gears = (float*)malloc(numofgears*2* sizeof(float));
					gears2 = (float**)malloc(numofgears* sizeof(float));
				}
				
				for (int l = 0; l <= numofgears; l++)
				{
    				gears2[l] = gears + l*2; 
				}
				//printf("numofgears = %d", numofgears);
			}
			else if(line == 2)
			{
				gears2[j][1] = atoi(buffer);
				//printf("saved1: %.1f \n", gears2[j][1]);
				j++;
			}
			else if(line == 3)
			{
				if (count == -1)
				{
					gears2[0][2] = atoi(buffer);
					//printf("saved2: %f \n", gears2[0][2]);
					count++;
				}
				else
				{
					requested_gears[count] = atoi(buffer);
					//printf("saved3: %d \n", requested_gears[count]);
					count++;
				}
				
				
			}
			
				
			//bzero(buffer, 32);
			for(int k = 0; k <=b; k++)
			{
				buffer[k]=NULL;
			}
			b = 0;
			continue;
		}
		else
		{
			buffer[b]=ch;
			//printf("saved stream to buffer");
			b++;
			
		}
	}
	
	
	printf("input file closed");
	fclose(inputfile);
	
	calcRotation(numofgears, gears2, requested_gears);
	
	
	return 0;
}

void calcRotation(int numofgears, float** gears, int requested_gears[4])
{
	FILE *outputfile;
	outputfile = fopen("outputs.txt", "w");
	
	int j = 0;
	for(int i = 1; i<=numofgears; i++)
	{
		gears[i][2] = (gears[i-1][1]* gears[i-1][2]) / gears[i][1];
		//printf("%.0f*%.0f / %.0f = %.2f\n",gears[i-1][1], gears[i-1][2], gears[i][1], gears[i][2] );
		//printf("Gear : #%d has : %.0f teeth\n", i-1, gears[i-1][1]);
		//printf("Rotations = [%d][2] = %.2f\n", i-1, gears[i-1][2]);
		//printf("i = %d \n", i);
		if(requested_gears[j]-1 == i-1)
		{
			printf("Rotations of gear #%d = %.2f\n", i-1, gears[i-1][2]);
			fprintf(outputfile, "%f", gears[i-1][2]);
			j++;
		}
		
		fclose(outputfile);
		
		
	}
	//return gears;
}
