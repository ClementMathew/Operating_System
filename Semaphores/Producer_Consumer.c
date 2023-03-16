// Semaphores – Producer Consumer
#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 3, f = -1, r = -1, x;
void main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    while (1)
    {
        printf("\nEnter your choice : \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("BUFFER IS FULL");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("BUFFER IS EMPTY");
            break;
        case 3:
            exit(0);
            break;
        }
    }
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    if (f == -1)
        f = 0;
    r++;
    x = r + 1;
    printf("Producer produces the item %d\n", x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    f++;
    x = f;
    if (f > r)
        f = r = -1;
    printf("Consumer consumes item %d\n", x);
    mutex = signal(mutex);
}