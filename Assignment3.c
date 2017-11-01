#include <stdio.h>

//Global Variables rows and columns hold the values of the row size and the column size
int rows,columns;

//Gets a 2D array and fills it with user input values of 0 or 1. Doesn't return anything
void getArray(int array[rows][columns])
{
	for(int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			scanf("%d",&array[i][j]);

	for(int i = 0; i < rows; i++)
		{
		for (int j = 0; j < columns; j++)
			printf("%d ",array[i][j]);
		}
		printf("\n");
}

//Calculates and returns the total number of neighbours of a given block that are '1'
int totalNumberTouch(int array[rows][columns],int x,int y)
{
	return array[x-1][y]+array[x+1][y]+array[x][y-1]+array[x][y+1];	
}


//Removes all the '1' that are not part of the loop and only the loop remains
void extractLoop(int array[rows][columns])
{
	for(int i=0;i<rows;i++)
		for(int j=0;j<columns;j++)
			if(array[i][j]==1 && totalNumberTouch(array,i,j)<2)
			{
				array[i][j]=0;
				extractLoop(array);
				break;
			}
}

//Given a coordinate it prints out the co-ordinates of all the neighbours that are '1'
void printPath(int array[rows][columns],int visited[rows][columns],int x,int y)
{
	if(x > -1 && x < rows && y > -1 && y < columns && visited[x][y]!=1)
	{
		if(array[x][y]==1)
		{
			visited[x][y]=1;
			printf("(%d,%d)=> ",x,y);
			printPath(array,visited,x+1,y);
			printPath(array,visited,x,y+1);
			printPath(array,visited,x-1,y);
			printPath(array,visited,x,y-1);
		}
		visited[x][y]=1;
	}
	return;
}

//find the first '1' in the array and start the printpath function
void startLoop(int array[rows][columns],int visited[rows][columns])
{
	for(int i=0;i<rows;i++)
		for(int j=0;j<columns;j++)
		{
			if(array[i][j]==1)
			{
				printPath(array,visited,i,j);
				return;
			}
		}
	return;
}

int main()
{
	printf("Enter rows and columns\n");
	scanf("%d%d",&rows,&columns);
	int array[rows][columns];
	int visited[rows][columns];
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			visited[i][j]=0;
	getArray(array);
	extractLoop(array);
	startLoop(array,visited);
	return 0;
}