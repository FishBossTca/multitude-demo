#include "head.h"

int PillarChoice(int sort[],int low,int high)//����ѡȡģ��(����ȡ�з�)
{
    int middle=(low+high)/2;
    if(sort[middle]<sort[low]<sort[high]||sort[high]<sort[low]<sort[middle])//low����ֵ
        return sort[low];
    else if(sort[low]<sort[middle]<sort[high]||sort[high]<sort[middle]<sort[low])//middle����ֵ
        return sort[middle];
    else
        return sort[high];
}
int Partition(int sort[],int low,int high)
{
    int pivotkey=PillarChoice(sort,low,high);
    while(low<high)
    {
        while(low<high&&sort[high]>=pivotkey)
            high--;
        sort[low]=sort[high];
        while(low<high&&sort[low]<=pivotkey)
            low++;
        sort[high]=sort[low];
    }
    sort[low]=pivotkey;
    return low;
}

int recursionQsort(int sort[],int low,int high)//β�ݹ鷨
{
    int pillar;
    while(low<high)
    {
        pillar=Partition(sort,low,high);
        recursionQsort(sort,low,pillar-1);
        low=pillar+1;
    }
}

void QSort(int sort[],int length)//������������ģ��
{
    system("cls");
    recursionQsort(sort,0,length-1);
    for(int i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}
