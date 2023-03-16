//Firstfit

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
    int j,k;
    
    for(i=0;i<n;i++)
    {
        ans[i]=0;
	}
	
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(pro[i]<=mem[j])
            {
                ans[i]=j+1;
                mem[j]=mem[j]-pro[i];
                break;
            }
        }
    }
    printf("Process\tP_size\tAllocated_Block\n");
    for(i=0;i<n;i++)
    {
            if(ans[i]==0)
            {
            	printf("P%d\t%d\tNot Allocated\t\n",i+1,pro[i]);
            }
        	else
        	{
        		printf("P%d\t%d\t%d\t\n",i+1,pro[i],ans[i]);
        	}
    }
}
