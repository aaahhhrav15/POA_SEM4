#include <stdio.h>
int n, nf;
int sequence[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

void initialize()
{
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
    {
        p[i] = 9999;
    }
}

int isHit(int data)
{
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }
    return hit;
}
void dispPages()
{
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
        {
            printf(" %d", p[k]);
        }
    }
}

void dispPgFaultCnt()
{
    printf("\nTotal no of page faults:%d", pgfaultcnt);
}

void fifo()
{
    initialize();
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d :", sequence[i]);

        if (isHit(sequence[i]) == 0)
        {

            for (k = 0; k < nf - 1; k++)
            {
                p[k] = p[k + 1];
            }

            p[k] = sequence[i];
            pgfaultcnt++;
            dispPages();
        }
        else
        {
            printf("No page fault");
        }
    }
    dispPgFaultCnt();
}
void optimal()
{
    initialize();
    int near[50];
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d :", sequence[i]);

        if (isHit(sequence[i]) == 0)
        {

            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i; k < n; k++)
                {
                    if (pg == sequence[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                    {
                        found = 0;
                    }
                }
                if (!found)
                {
                    near[j] = 9999;
                }
            }
            int max = -9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (near[j] > max)
                {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = sequence[i];
            pgfaultcnt++;

            dispPages();
        }
        else
        {
            printf("No page fault");
        }
    }
    dispPgFaultCnt();
}

void lru()
{
    initialize();
    int least[50];
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d :", sequence[i]);
        if (isHit(sequence[i]) == 0)
        {
            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (pg == sequence[k])
                    {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                    {
                        found = 0;
                    }
                }
                if (!found)
                {
                    least[j] = -9999;
                }
            }
            int min = 9999;
            int repindex;
            for(j = 0; j < nf; j++)
            {
                if (least[j] < min)
                {
                    min = least[j];
                    repindex = j;
                }
            }
            p[repindex] = sequence[i];
            pgfaultcnt++;

            dispPages();
        }
        else
        {
            printf("No page fault!");
        }
    }
    dispPgFaultCnt();
}


int main()
{

    printf("\nEnter length of page reference sequence:");
    scanf("%d", &n);
    printf("\nEnter the page reference sequence:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &sequence[i]);
    }
    printf("\nEnter no of frames:");
    scanf("%d", &nf);

    fifo();
    optimal();
    lru();

    return 0;
}