#include"head.h"
#define MAXnum 100
void SORTMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※    您现在在数组排序页面   ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█       0、退出菜单          █");
    puts("\t\t\t█       1、添加数组          █");
    puts("\t\t\t█       2、直接插入排序      █");
    puts("\t\t\t█       3、希尔排序          █");
    puts("\t\t\t█       4、堆排序            █");
    puts("\t\t\t█       5、归并排序          █");
    puts("\t\t\t█       6、快速排序          █");
    puts("\t\t\t█       9、显示数组          █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

int addSort(int sort[])//添加数组模块
{
    system("cls");
    int ch=0,i=0;
    puts("请输入数字,每个数字之间用空格隔开,结束请输入\"-65536\"并按回车");
    while(1)
    {
        scanf("%d",&ch);
        if(ch==-65535)
            break;
        sort[i]=ch;
        i++;
    }
    sort[i]=-65535;
    fflush(stdin);
    puts("添加完成!");
    system("pause");
}

int showSort(int sort[])//显示数组模块
{
    system("cls");
    int i=0;
    puts("该数组为");
    while(sort[i]!=-65535)
    {
        printf("%d,",sort[i]);
        if(i%10==0&&i!=0)
            printf("\n");
        i++;
    }
    printf("共有%d个元素",i);
    system("pause");
}

int count(int sort[])//数组元素计数模块
{
    int i=0;
    while(sort[i]!=-65535)
        i++;
    return i;
}
// 
//
//        ┌─┐       ┌─┐
//    ┌──┘ ┴───────┘ ┴──┐
//    │                 │
//    │       ───       │
//    │  ─┬┘       └┬─  │
//    │                 │
//    │       ─┴─       │
//    │                 │
//    └───┐         ┌───┘
//        │         │
//        │         │
//        │         │
//        │         └──────────────┐
//        │                        │
//        │                        ├─┐
//        │                        ┌─┘
//        │                        │  神兽保佑
//        └─┐  ┐  ┌───────┬──┐  ┌──┘         永不出错!
//        │ ─┤ ─┤       │ ─┤ ─┤
//        └──┴──┘       └──┴──┘
//
//        


int SORT(void)
{
    //system("pause");
    int sort[MAXnum]={-65535};
    while(1)//封面死循环
    {
        system("cls");//清屏
        SORTMenu();
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':return 0;
                case '1':addSort(sort);break;
                case '2':insertSort(sort,count(sort));break;
                case '3':shellSort(sort,count(sort));break;
                case '4':heapsort(sort,count(sort));break;
                case '5':merge(sort,count(sort));break;
                case '6':QSort(sort,count(sort));break;
                case '9':showSort(sort);break;
                default :continue;
            }
            break;
        }
    }

}