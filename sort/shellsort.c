#include"head.h"
void shellSort(int sort[],int length)//希尔排序(顺序)
{
    system("cls");
    int i,j,k,tmp,gap; // gap 为步长
    for (gap=length/2;gap>0;gap/=2) // 步长初始化为数组长度的一半，每次遍历后步长减半
    { 
    	for(i=0;i<gap;++i)//变量i为每次分组的第一个元素下标 
        {
            for(j=i+gap;j<length;j+=gap) //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
            {
                tmp=sort[j];  // 备份a[j]的值
                k=j-gap;  // k初始化为i的前一个元素（与i相差gap长度）
                while(k>=0&&sort[k]>tmp)
                {
                    sort[k+gap]=sort[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
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
