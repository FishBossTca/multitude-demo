#include"head.h"
void shellSort(int sort[],int length)//ϣ������(˳��)
{
    system("cls");
    int i,j,k,tmp,gap; // gap Ϊ����
    for (gap=length/2;gap>0;gap/=2) // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����
    { 
    	for(i=0;i<gap;++i)//����iΪÿ�η���ĵ�һ��Ԫ���±� 
        {
            for(j=i+gap;j<length;j+=gap) //�Բ���Ϊgap��Ԫ�ؽ���ֱ�����򣬵�gapΪ1ʱ������ֱ������
            {
                tmp=sort[j];  // ����a[j]��ֵ
                k=j-gap;  // k��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
                while(k>=0&&sort[k]>tmp)
                {
                    sort[k+gap]=sort[k]; // ����a[i]ǰ�ұ�tmp��ֵ���Ԫ������ƶ�һλ
                    k-=gap;
                }
	            sort[k+gap]=tmp; 
	        }
	    }
    }
    for(i=0;i<length;i++)
        printf("%d,",sort[i]);
    putchar('\n');
    system("pause");
}
