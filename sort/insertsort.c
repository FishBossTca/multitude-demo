#include "head.h"
void insertSort(int sort[],int length)//÷±Ω”≤Â»Î≈≈–Ú(À≥–Ú)
{
    system("cls");
    int i,j,exchange;
    for(i=1;i<length;i++)
    {
        if(sort[i]<=sort[i-1])
        {
            exchange=sort[i];
            for(j=i-1;sort[j]>exchange;j--)
                sort[j+1]=sort[j];
            sort[j+1]=exchange;
        }
    }
    for(i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}