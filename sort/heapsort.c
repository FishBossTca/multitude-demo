#include "head.h"

void swap(int *a,int *b)//����ģ��
{
    int temp;
    temp=*a;*a=*b;*b=temp;
}

void MinHeadAdjust(int sort[],int k,int length)//����ΪС����
{
    if(2*k+1<length)//�����ӽڵ�Ž��н���,���û�����ӿ϶���û���Һ���
    {
        if(sort[2*k+1]<sort[k])//�󺢱ȸ���С
        {
            swap(sort+k,sort+2*k+1);
            MinHeadAdjust(sort,2*k+1,length);//�����󺢽���С���ѵ���
        }
        if(2*k+2<length)//�ж��Ƿ����Һ�
            if(sort[2*k+2]<sort[k])//�Һ��ȸ���С
            {
                swap(sort+k,sort+2*k+2);
                MinHeadAdjust(sort,2*k+2,length);//�����󺢽���С���ѵ���
            }
    }   
}

void heapsort(int sort[],int length)//������(����)
{
    system("cls");
    int k,i,j;
    for(k=length/2-1;k>=0;k--)/* kΪ���һ�����ڵ� */
        MinHeadAdjust(sort,k,length);
    for(i=1;i<length;i++)//����
    {
        swap(sort,sort+length-i);
        MinHeadAdjust(sort,0,length-i);
    }
    for(i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}