/*Simulation of Shortest Job First(SJF) Algorithm*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	int arrive[n],burst[n],complete[n],tat[n],wait[n],pos[n];
	printf("Enter the arrival time for each process one by one:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arrive[i]); //Take arrival time as input
	}
	printf("Enter the burst time for each process one by one:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);  //Take burst time as input
		pos[i]=0;
	}
	complete[0]=burst[0];
	tat[0]=complete[0]-arrive[0];
	wait[0]=tat[0]-burst[0];
	int sumtat=tat[0],sumwait=wait[0];
	int q=1,index,prev=0;
	while(q!=n)
	{
		int min=10000,index;
		for(i=n-1;i>=1;i--)
		{
			if(burst[i]<min && pos[i]==0)
			{
				min=burst[i];
				index=i;
			}
		}
		complete[index]=min+complete[prev];    //calculate completion
		tat[index]=complete[index]-arrive[index];  //time,turn around
		sumtat+=tat[index];     //time,wait time using round robin 
		wait[index]=tat[index]-min;  //Algorithm
		sumwait+=wait[index];
		pos[index]=1;
		prev=index;
		q+=1;
	}
	
	float avgtat=(float)sumtat/(float)n;
	float avgwait=(float)sumwait/(float)n;
	printf("...............PROCESS TABLE.............\n");
	printf("P.NO\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
	//printing the table	
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arrive[i],burst[i],complete[i],tat[i],wait[i]);
	}
	printf("\n***Average TURN AROUND TIME:%f***\n",avgtat);
	printf("***Average WAIT TIME:%f***\n",avgwait);
	return 0;
}
