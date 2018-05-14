/*Simulation of Round Robin Algorithm*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	int tq;
	printf("Enter Time Quantun:");
	scanf("%d",&tq);
	int arrive[n],burst[n],burst2[n],complete[n],tat[n],wait[n];
	printf("Enter the arrival time for each process one by one:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arrive[i]);
	}
	printf("Enter the burst time for each process one by one:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
		burst2[i]=burst[i];
	}
	printf("...............PROCESS TABLE.............\n");
	printf("P.NO\tAT\tBT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",i+1,arrive[i],burst[i]);
	}
	int context=0;
	int iterate=n;
	int prev=0;
	int x=0;
	while(iterate!=0)
    {
        for(i=0;i<n;i++)
        {
            if(burst[i]!=0)
            {
            x+=(burst[i]>=tq?tq:burst[i]);
            burst[i]=(burst[i]>=tq?burst[i]-tq:0);
           // x+=burst[i];
            context+=1;
            printf("Process- %d ",i+1);
            if(burst[i]==0)
            {
                complete[i]=x;
                iterate=iterate-1;
            }
            }
        }
    }
    printf("\nNo of context switch:%d\n",context);
    int sumtat=0,sumwait=0;
	for(i=0;i<n;i++)
	{
		tat[i]=complete[i]-arrive[i];
		sumtat+=tat[i];
		wait[i]=tat[i]-burst2[i];
		sumwait+=wait[i];
	}
	float avgtat=(float)sumtat/(float)n;
	float avgwait=(float)sumwait/(float)n;
	printf("...............PROCESS TABLE.............\n");
	printf("P.NO\tAT\tBT\tCT\tTOT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arrive[i],burst2[i],complete[i],tat[i],wait[i]);
	}
	printf("\n***Average TURN AROUND TIME:%f***\n",avgtat);
	printf("***Average WAIT TIME:%f***\n",avgwait);
	return 0;
}
