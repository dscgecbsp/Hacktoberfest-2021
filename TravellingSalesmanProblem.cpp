# include <stdio.h>


int nodes[4]={0,0,0,0};
int values[4][4]={{0,16,11,6},{8,0,13,16},{4,7,0,9},{5,12,2,0}};
int cost=0;


int tsp(int);
void min_cost(int);


void min_cost(int city)
{
	int nearest;
	nodes[city]=1;
	printf("%d ",city+1);
	nearest=tsp(city);
	if(nearest==999)
	{
		nearest=0;
		printf("%d ",nearest+1);
		cost+=values[city][nearest];
		return;
	}	
	min_cost(nearest);
}


int tsp(int c)
{
	int nearest=999;
	int min=999,temp;
	for(int count=0;count<4;count++)
	{
		if((values[c][count]!=0) && (nodes[count]==0))
		{
			if(values[c][count]<min)
			{
				min=values[count][0]+values[c][count];
			}
			temp=values[c][count];
			nearest=count;
		}
	}
	if(min!=999)
	{
		cost+=temp;
	}
	return nearest;
}



int main()
{
	printf("Travelling Salesman Problem (Greedy Algorithm)\n\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d ",values[i][j]);
		}
		printf("\n");
	}
	printf("\n\nPath: ");
	min_cost(0);
	printf("\nCost: %d",cost);
	return 0;
}

 
