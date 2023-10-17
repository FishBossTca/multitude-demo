#include "head.h"

void MergeArr(int sort[],int head,int tail,int forth,int end,int newsort[])
{
    int left=head,right=end,index=head;
    while(head<=tail&&forth<=end)//两边都有数据时
    {
        if(sort[head]<sort[forth])
        {
            newsort[index]=sort[head];
            head++;index++;
        }
        else
        {
            newsort[index]=sort[forth];
            forth++;index++;
        }
    }
    while(head<=tail)//只有单边有数据了，全部复制下来
		newsort[index++]=sort[head++];
	while(forth<=end)
		newsort[index++]=sort[forth++];
    for(int i=left;i<=right;i++)//数据复制回原数组(这里还能再优化成全部分类好后再复制回原数组)
        sort[i]=newsort[i];
}

void merge(int sort[],int length)//归并排序
{
    system("cls");
    int newsort[length];
    int i,gap,head,tail,forth,end;
    for(gap=1;gap<length;gap*=2)
    {
        for(i=0;i<length;i+=2*gap)
        {
            head=i;tail=i+gap-1;
            forth=i+gap;end=i+2*gap-1;
            if(forth>=length)//没有第二组,不合并
                break;
            if(end>length)//第二组只有部分有数据,要修改边界位置
                end=length-1;
            MergeArr(sort,head,tail,forth,end,newsort);
        }
    }
    for(i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}