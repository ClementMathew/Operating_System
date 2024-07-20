#include <stdio.h>
#include <stdbool.h>

#define M 5

struct processes
{
    int pno;
    int wtime;
    int btime;
    int atime;
    int burst;
};

int ready[M];

bool isTimeLeft(int, struct processes *);

void main()
{
    int t,i, n, ready_count = 0, total_wtime = 0, total_btime = 0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    
    struct processes p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pno = i;
        printf("\nProcess %d\n", p[i].pno);
        printf("Enter burst time : ");
        scanf("%d", &p[i].btime);
        printf("Enter arrival time : ");
        scanf("%d", &p[i].atime);
        p[i].burst = p[i].btime;
        p[i].wtime = 0;
    }

    for(int i = 0; i<M; i++) 
    {
            ready[i] = -1;
    }

    for (t = 0; isTimeLeft(n, p); t++)
    {
        for (int j = 0; j < n; j++) 	// adding process to ready queue
        {
            if (p[j].atime == t && p[j].btime != 0)
            {
                ready[ready_count] = p[j].pno;
                ready_count++;
            }
        }

        if (ready_count != 0)
        {
            p[ready[0]].btime--;
        } 
        
        // decrementing burst time of first element in ready array

        for (int i = 0; i < n; i++) 	// incrementing waiting time of all other processes
        {
            if (p[i].pno != ready[0] && p[i].btime != 0)
            {
                p[i].wtime++;
            }
        }

        if (p[ready[0]].btime == 0)
        {
            // when btime of process in front of ready queue is 0 remove the process from ready queue and push queue forward
            for (i = 0; i < ready_count - 1; i++)
            {
                ready[i] = ready[i + 1];
            }
            ready[i] = -1;
            ready_count--;
        }
    }

    for(int i=0; i<n; i++) 
    {
        p[i].wtime -= p[i].atime;
    }
	int total_tatime;
	
    printf("\n Process\tBursttime\tArrival time\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++)
    {
        total_wtime += p[i].wtime;
        total_btime += p[i].burst;
        printf("\n%d\t\t%d\t\t%d", p[i].pno, p[i].burst, p[i].atime);
        printf("\t\t%d\t\t%d", p[i].wtime, p[i].wtime + p[i].burst);
        total_tatime += p[i].wtime + p[i].burst - p[i].atime;
    }
    float Avg_Wt = total_wtime/n;
    float Avg_Tat = total_tatime/n;
    printf("\nAverage WT : %.2f",Avg_Wt);
    printf("\nAverage TAT : %.2f",Avg_Tat);
}

bool isTimeLeft(int n, struct processes p[n])
{
    int total_btime = 0;
    for (int i = 0; i < n; i++)
    {
        total_btime += p[i].btime;
    }
    return total_btime == 0 ? false : true;
}
