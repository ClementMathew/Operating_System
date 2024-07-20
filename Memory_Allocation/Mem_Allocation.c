// Memory Allocation Scheme
// 1.Firstfit
// 2.WorstFit
// 3.BestFit

#include <stdio.h>

void firstfit(int, int, int[], int[]);
void worstfit(int, int, int[], int[]);
void bestfit(int, int, int[], int[]);

void main()
{
    int m, n, i, ch;
    printf("Enter the no of memory : ");
    scanf("%d", &m);
    int mem[m];
    printf("Enter the memory sizes : ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &mem[i]);
    }
    printf("Enter the no of processes : ");
    scanf("%d", &n);
    int pro[n];
    printf("Enter the process sizes : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pro[i]);
    }
    printf("1.FirstFit\n2.WorstFit\n3.BestFit\n\nSelect your choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        firstfit(m, n, mem, pro);
        break;

    case 2:
        worstfit(m, n, mem, pro);
        break;

    case 3:
        bestfit(m, n, mem, pro);
        break;
    }
}
void firstfit(int m, int n, int mem[], int pro[])
{
    int ans[n];
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        ans[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (pro[i] <= mem[j])
            {
                ans[i] = j + 1;
                mem[j] = mem[j] - pro[i];
                break;
            }
        }
    }
    printf("Process\tP_size\tAllocated_Block\n");
    for (i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            printf("P%d\t%d\tNot Allocated\t\n", i + 1, pro[i]);
        }
        else
        {
            printf("P%d\t%d\t%d\t\n", i + 1, pro[i], ans[i]);
        }
    }
}
void worstfit(int m, int n, int mem[], int pro[])
{
    int ans[n];
    int i, j, ind = -1, max = -999;

    for (i = 0; i < n; i++)
    {
        ans[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mem[j] >= max)
            {
                max = mem[j];
                ind = j;
            }
        }
        if (max >= pro[i])
        {
            mem[ind] = mem[ind] - pro[i];
            max = -999;
            ans[i] = ind + 1;
            ind = -1;
        }
    }
    printf("Process\tP_size\tAllocated_Block\n");
    for (i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            printf("P%d\t%d\tNot Allocated\t\n", i + 1, pro[i]);
        }
        else
        {
            printf("P%d\t%d\t%d\t\n", i + 1, pro[i], ans[i]);
        }
    }
}
void bestfit(int m, int n, int mem[], int pro[])
{
    int ans[n];
    int i, j, ind = -1, diff = 999;

    for (i = 0; i < n; i++)
        ans[i] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if ((mem[j] >= pro[i]) && (diff >= mem[j] - pro[i]))
            {
                diff = mem[j] - pro[i];
                ind = j;
            }
        }
        mem[ind] = mem[ind] - pro[i];
        diff = 999;
        ans[i] = ind + 1;
        ind = -1;
    }
    printf("Process\tP_size\tAllocated_Block\n");
    for (i = 0; i < n; i++)
    {
        if (ans[i] == 0)
            printf("P%d\t%d\tNot Allocated\t\n", i + 1, pro[i]);
        else
            printf("P%d\t%d\t%d\t\n", i + 1, pro[i], ans[i]);
    }
}