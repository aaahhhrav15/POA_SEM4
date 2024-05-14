#include<stdio.h>

void firstfit(int bsize[], int psize[], int bno, int pno)
{
    int flag[bno];
    for(int i=0;i<bno;i++)
    {
        flag[i]=0;
    }
    for(int i=0;i<pno;i++)
    {
        for(int j=0;j<bno;j++)
        {
            if(bsize[j]>psize[i] && flag[j]==0)
            {
                printf("Process %d is allocated to Block %d\n", i+1, j+1);
                flag[j]=1;
                break;
            }
            if(j==bno-1)
            {
                printf("Process %d is not allocated\n", i+1);
            }
        }
    }
}

void bestFit(int bsize[], int psize[], int bno, int pno) 
{
    for(int i=0;i<pno;i++)
    {
        int min=9999;
        int index=-1;
        for(int j=0;j<bno;j++)
        {
            if(bsize[j]>=psize[i] && bsize[j]<min)
            {
                min=bsize[j];
                index=j;
            }
        }
        if(index!=-1)
        {
            printf("Process %d is allocated to Block %d\n", i+1, index+1);
        }
        else
        {
            printf("Process %d is not allocated\n", i+1);
        }
    }
}

void worstfit(int bsize[], int psize[], int bno, int pno) 
{
    for(int i=0;i<pno;i++)
    {
        int max=-1;
        int index=-1;
        for(int j=0;j<bno;j++)
        {
            if(bsize[j]>=psize[i] && bsize[j]>max)
            {
                max=bsize[j];
                index=j;
            }
        }
        if(index!=-1)
        {
            printf("Process %d is allocated to Block %d\n", i+1, index+1);
        }
        else
        {
            printf("Process %d is not allocated\n", i+1);
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

    firstfit(bsize, psize, bno, pno);
    bestFit(bsize, psize, bno, pno);
    worstFit(bsize, psize, bno, pno);
    return 0;
}