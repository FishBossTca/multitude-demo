#include"head.h"
#define MAXlong 100
typedef struct 
{
    int data[MAXlong];
    int num;
}List;

void SeqListMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※     您现在在顺序表页面    ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、添加元素        █");
    puts("\t\t\t█         2、删除元素        █");
    puts("\t\t\t█         3、遍历元素        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

int searchInfo(int data,List *list)//查找数据位置模块
{
    int i;
    for(i=0;i<list->num;i++)
    {
        if(data==list->data[i])
            return i;
    }
    return -1;//没找到返回-1，其他情况返回该元素位置
}

int addSeqList(List *list)//添加元素模块
{
    system("cls");
    if(list->num>=MAXlong)
    {
        puts("抱歉,该顺序表已满!");
        system("pause");
        return 0;
    }
    int newdata;
    puts("请输入需要添加的元素:");
    scanf("%d",&newdata);
    fflush(stdin);
    if(searchInfo(newdata,list)!=-1)//该元素已经添加过
    {
        puts("抱歉,该元素已经存在!");
        system("pause");
        return 0;
    }
    list->data[list->num]=newdata;
    list->num++;
    puts("添加完成!");
    system("pause");
}

int delSeqList(List *list)//删除元素模块
{
    system("cls");
    int deleted,position,i;
    puts("请输入需要删除的元素");
    scanf("%d",&deleted);
    fflush(stdin);
    if((position=searchInfo(deleted,list))==-1)//没找到该元素
    {
        puts("抱歉,没有找到改元素!");
        system("pause");
        return 0;
    }
    for(i=position;i<list->num;i++)
        list->data[i]=list->data[i+1];
    list->num--;
    puts("删除完成!");
    system("pause");
}

int scanSeqList(List *list)//遍历元素模块
{
    system("cls");
    int i;
    for(i=0;i<list->num;i++)
    {
        if(i!=0&&i%10==0)
            putchar('\n');
        printf("%d,",list->data[i]);
    }
    printf("\n共有%d个元素\n",list->num);
    system("pause");
}

int SEQLIST(void)
{
    List *list=(List *)malloc(sizeof(List));
    list->num=0;
    while(1)//封面死循环
    {
        system("cls");//清屏/*  */
        SeqListMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':free(list);return 0;
                case '1':addSeqList(list);break;
                case '2':delSeqList(list);break;
                case '3':scanSeqList(list);break;
                default :continue;
            }
            break;
        }
        
    }
}