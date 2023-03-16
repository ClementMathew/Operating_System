
// FCFS diskscheduling

#include<stdio.h>

void main()
{
    int head,i=0,n,sum=0;
    
    printf("Enter the head of disks : ");
    scanf("%d",&head);
   	printf("Enter the number of elements in request queue : ");
   	scanf("%d",&n);
   	int rq[n];
   	int ans[n];
   	
    printf("Enter the  elements in request queue : ");
    for(i=0;i<n;i++)
    	scanf("%d",&rq[i]);
    	
    //order of request
    printf("\nSequence is : \n");
    printf("%d",head);
    for(i=0;i<n;i++)
    	printf("->%d",rq[i]);

	ans[0]=rq[0]-head;
	int k=1;
	for(i=0;i<n-1;i++)
	{
		ans[k]=rq[i]-rq[i+1];
		k++;
	}
	printf("\n\n");
	printf("Seek times : ");
	for(i=0;i<n;i++)
	{
    	if(ans[i]<0)
    	{
        	ans[i]=ans[i]*-1;
    	}
		printf("%d ",ans[i]);
		sum+=ans[i];
	}
	printf("\n\nTotal seek time = %d",sum);
}
