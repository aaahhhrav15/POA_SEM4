#include <stdio.h>

void firstFit(int bsize[], int psize[], int bno, int pno) 
{
    int flags[10], allocation[10], i, j;

    for (i = 0; i < 10; i++) 
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    for (i = 0; i < pno; i++) 
    {
        for (j = 0; j < bno; j++) 
        {
            if (flags[j] == 0 && bsize[j] >= psize[i]) 
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess no.\tBlock Size\tBlock No\tProcess Size");
    for (i = 0; i < bno; i++) 
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flags[i] == 1)
        {
            printf("%d\t\t%d", allocation[i] + 1, psize[allocation[i]]);
        }
        else
        {
            printf("Not allocated\t-");
        }
    }
}

void bestFit(int bsize[], int psize[], int bno, int pno) {
    int flags[15], allocation[15], i, j;

    for (i = 0; i < 15; i++) 
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    for (i = 0; i < pno; i++) 
    {
        int indexPlaced = -1;
        for (j = 0; j < bno; j++) 
        {
            if (bsize[j] >= psize[i] && flags[j] == 0) 
            {
                if (indexPlaced == -1)
                {
                    indexPlaced = j;
                }
                else if (bsize[j] < bsize[indexPlaced])
                {
                    indexPlaced = j;
                }
            }
        }
        if (indexPlaced != -1) 
        {
            allocation[i] = indexPlaced;
            flags[indexPlaced] = 1;
        }
    }

    printf("\nProcess No.\tMemory Size\tBlock No.\tProcess Size");
    for (i = 0; i < pno; i++) 
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[allocation[i]]);
        if (allocation[i] != -1)
        {
            printf("%d\t\t%d", allocation[i] + 1, psize[i]);
        }
        else
        {
            printf("Not allocated");
        }
    }
}

void worstFit(int bsize[], int psize[], int bno, int pno) 
{
    int allocation[15], i, j;

    for (i = 0; i < pno; i++)
    {
        allocation[i] = -1;
    }
        

    for (i = 0; i < pno; i++) 
    {
        int indexPlaced = -1;
        for (j = 0; j < bno; j++) 
        {
            if (bsize[j] >= psize[i]) 
            {
                if (indexPlaced == -1)
                {
                    indexPlaced = j;
                }
                else if (bsize[j] > bsize[indexPlaced])
                {
                    indexPlaced = j;
                }
            }
        }
        if (indexPlaced != -1) 
        {
            allocation[i] = indexPlaced;
            bsize[indexPlaced] -= psize[i];
        }
    }

    printf("\nProcess No.\tMemory Size\tBlock No.\tProcess Size");
    for (i = 0; i < pno; i++) 
    {
        if (bsize[allocation[i]] == -1)
        {
            printf("\n%d\t\tNone\t\t", i + 1);
        }
        else
        {
            printf("\n%d\t\t%d\t\t", i + 1, bsize[allocation[i]]);
        }
        if (allocation[i] != -1)
        {
            printf("%d\t\t%d", allocation[i] + 1, psize[i]);
        }
        else
        {
            printf("Not allocated\t%d", psize[i]);
        }
    }
}

int main() 
{
    int bsize[15], psize[15], bno, pno, choice, i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &bno);

    printf("Enter the size of each memory block: \n");
    for (i = 0; i < bno; i++)
    {
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &pno);

    printf("Enter the size of each process: \n");
    for (i = 0; i < pno; i++)
    {
        scanf("%d", &psize[i]);
    }

    firstFit(bsize, psize, bno, pno);
    bestFit(bsize, psize, bno, pno);
    worstFit(bsize, psize, bno, pno);
    return 0;
}