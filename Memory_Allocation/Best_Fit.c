//Bestfit

#include<stdio.h>

void main()
{
    int m,n,i;

    printf("Enter the no of memory : ");
    scanf("%d",&m);

    int mem[m];

    printf("Enter the memory sizes : ");
    for(i=0;i<m;i++)
    {
    	scanf("%d",&mem[i]);
	}

    printf("Enter the no of processes : ");
    scanf("%d",&n);

    int pro[n];

    printf("Enter the process sizes : ");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&pro[i]);
    }
 	
 	int ans[n];
    int j,ind=-1,diff=999;
    
    for(i=0;i<n;i++)
        ans[i]=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((mem[j]>=pro[i]) && (diff>=mem[j]-pro[i]))
            {
              diff=mem[j]-pro[i];
              ind=j;
            }
        }
        mem[ind]=mem[ind]-pro[i];
        diff=999;
        ans[i]=ind+1;
	}
	
	printf("Process\tP_size\tAllocated_Block\n");
    for(i=0;i<n;i++)
    {
         if(ans[i]==0)
            printf("P%d\t%d\tNot Allocated\t\n",i+1,pro[i]);
        else
        	printf("P%d\t%d\t%d\t\n",i+1,pro[i],ans[i]);
    }
}
