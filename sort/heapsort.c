#include "head.h"

void swap(int *a,int *b)//交换模块
{
    int temp;
    temp=*a;*a=*b;*b=temp;
}

void MinHeadAdjust(int sort[],int k,int length)//调整为小根堆
{
    if(2*k+1<length)//有左孩子节点才进行交换,如果没有左孩子肯定就没有右孩子
    {
        if(sort[2*k+1]<sort[k])//左孩比父亲小
        {
            swap(sort+k,sort+2*k+1);
            MinHeadAdjust(sort,2*k+1,length);//对其左孩进行小根堆调整
        }
        if(2*k+2<length)//判断是否有右孩
            if(sort[2*k+2]<sort[k])//右孩比父亲小
            {
                swap(sort+k,sort+2*k+2);
                MinHeadAdjust(sort,2*k+2,length);//对其左孩进行小根堆调整
            }
    }   
}

void heapsort(int sort[],int length)//堆排序(逆序)
{
    system("cls");
    int k,i,j;
    for(k=length/2-1;k>=0;k--)/* k为最后一个父节点 */
        MinHeadAdjust(sort,k,length);
    for(i=1;i<length;i++)//排序
    {
        swap(sort,sort+length-i);
        MinHeadAdjust(sort,0,length-i);
    }
    for(i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}