#include "head.h"

void MergeArr(int sort[],int head,int tail,int forth,int end,int newsort[])
{
    int left=head,right=end,index=head;
    while(head<=tail&&forth<=end)//���߶�������ʱ
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
    while(head<=tail)//ֻ�е����������ˣ�ȫ����������
		newsort[index++]=sort[head++];
	while(forth<=end)
		newsort[index++]=sort[forth++];
    for(int i=left;i<=right;i++)//���ݸ��ƻ�ԭ����(���ﻹ�����Ż���ȫ������ú��ٸ��ƻ�ԭ����)
        sort[i]=newsort[i];
}

void merge(int sort[],int length)//�鲢����
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
            if(forth>=length)//û�еڶ���,���ϲ�
                break;
            if(end>length)//�ڶ���ֻ�в���������,Ҫ�޸ı߽�λ��
                end=length-1;
            MergeArr(sort,head,tail,forth,end,newsort);
        }
    }
    for(i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}