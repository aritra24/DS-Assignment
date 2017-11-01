#include <stdio.h>


int rows,columns;

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


int totalNumberTouch(int array[rows][columns],int x,int y)
{
	return array[x-1][y]+array[x+1][y]+array[x][y-1]+array[x][y+1];	
}

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