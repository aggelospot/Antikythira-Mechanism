#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

float* calcRotation(int rotations);

int main(int argc, char *argv[])
{
	FILE *inputfile;
	inputfile = fopen("inputs.txt", "r");
	
	if (inputfile == NULL) return NULL;
	
	
	int ch, line = 1, numofgears, i, count = 0, b = 0;
	
	//fscanf(inputfile, "%d", &numofgears);
	//printf("numofgears = %d\n", numofgears);
	//numofgears = 60;
	int j = 0;
	float* gears;
	float** gears2;
	
	char buffer[32];
	
	while((ch=fgetc(inputfile)) != EOF)
	{
		
		printf("stream reads: %c\n",ch);
		
		if(ch == '\n')
		{
			line++;
		}
		else if(ch == ' ')
		{
			if(line == 1)
			{
		
				numofgears = atoi(buffer);
				gears = (float*)malloc(numofgears*2* sizeof(float));
				gears2 = (float**)malloc(numofgears* sizeof(float));
				for (int l = 0; l < numofgears; l++)
				{
    				gears2[l] = gears + l*2; // 
				}
				printf("numofgears = %d", numofgears);
			}
			else if(line == 2)
			{
				gears2[j][1] = atoi(buffer);
				printf("saved: %f \n", gears2[j][1]);
			}
			
			j++;
				
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
			printf("saved stream to buffer");
			b++;
			
		}
		/*if ((ch=fgetc(inputfile)) == EOF)
		{
			printf("EOF");
		}*/
	}
	printf("exited");
	//int calcRotation(int rotations)
	//{
		
		
	//}
	//printf("lines = %d", line);
	/*
	int rotations = 3, teeth = 15;
	int input = 50;
	float gears[input][2];
	gears[0][1] = teeth;
	gears[0][2] = 33;
	gears[1][1] = teeth + 10;
	printf("gear1 = %f.3", gears[0][2]);
	
	for(int i = 1; i<=input; i++)
	{
		gears[i][2] = gears[i-1][1] / gears[i][1] * gears[i-1][2];
		
	}
	printf("gear2 = %lf", gears[1][2]);
	
	*/
	fclose(inputfile);
	//exit(0);
	return 0;
}
