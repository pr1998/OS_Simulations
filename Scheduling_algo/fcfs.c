/*First Come First Serve(FCFS) Scheduling Algorithm*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j;
	printf("Enter the no of processes:"); 
	scanf("%d",&n);
	int arrive[n],burst[n],complete[n],tat[n],wait[n];
	printf("Enter the arrival time for each process one by one:");
	for(i=0;i<n;i++)                   //Take arrival time as 
	{
		scanf("%d",&arrive[i]);      //input
	}
	printf("Enter the burst time for each process one by one:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);         //Take burst time as
	}
	complete[0]=burst[0];                 //input
	for(i=1;i<n;i++)
	{
		complete[i]=burst[i]+complete[i-1];  //Calculate            
	}
	int sumtat=0,sumwait=0;                   //completion time
	for(i=0;i<n;i++)
	{
		tat[i]=complete[i]-arrive[i];       //Calculate turn 
		sumtat+=tat[i];           //around time and wait time
		wait[i]=tat[i]-burst[i];    //for every process
		sumwait+=wait[i];
	}
//Calculate average turn around time and wait time for every //process
	float avgtat=(float)sumtat/(float)n;  
	float avgwait=(float)sumwait/(float)n;
	printf("...............PROCESS TABLE.............\n");
	printf("P.NO\tAT\tBT\tCT\tTOT\tWT\n");
	for(i=0;i<n;i++)
	{
//Printing the table		
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arrive[i],burst[i],complete[i],tat[i],wait[i]);
	}
	printf("\n***Average TURN AROUND TIME:%f***\n",avgtat);
	printf("***Average WAIT TIME:%f***\n",avgwait);
	return 0;
}
