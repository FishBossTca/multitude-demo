/* 链栈模块 */
#include"head.h"

#define MAXSIZE 10
#define stackRam (NodeStack *)malloc(sizeof(NodeStack))//分配内存
typedef struct _SeqStack//定义链栈
{
    int data;
    struct _SeqStack *next;
}NodeStack;

typedef struct
{
    NodeStack *top;
    int num;
}linkStack;//定义顶栈

void initLinkStack(linkStack *s)//初始化链栈模块
{
    s->num=0;
}

int pushLinkStack(linkStack *s)//数据进栈模块
{
    system("cls");
    if(s->num==0)//首次直接使用top指针
    {
        s->top=stackRam;
        puts("请输入需要进栈的数据");
        scanf("%d",&s->top->data);
        fflush(stdin);
        puts("输入完成!");
        ++s->num;
        system("pause");
        return 0;
    }
    NodeStack *link=stackRam;//创建新的节点
    link->next=s->top;
    puts("请输入需要进栈的数据");
    scanf("%d",&link->data);
    fflush(stdin);
    s->top=link;
    s->num++;
    puts("输入完成!");
    system("pause");
}

int popLinkStack(linkStack *s)//出栈模块
{
    NodeStack *delStack;
    system("cls");//清屏
    if(s->num==0)//判断是否为空栈
    {
        puts("抱歉，没有数据可出栈!");
        system("pause");
        return 0;
    }
    printf("出栈数据为:%d\n",s->top->data);
    delStack=s->top;
    s->top=s->top->next;
    free(delStack);
    s->num--;
    system("pause");
}

void clearLinkStack(linkStack *s)//清空栈模块
{
    system("cls");
    int i;
    NodeStack *delStack;
    for(i=0;i<s->num;i++)
    {
        delStack=s->top;
        s->top=s->top->next;
        free(delStack);
        s->num--;
    }
    s->num=0;
    puts("删除完成!");
    system("pause");
}

int throughLinkStack(linkStack *s)//查看链栈模块
{
    system("cls");
    NodeStack *temp=s->top;
    int i;
    if(s->num==0)
    {
        puts("抱歉，没有数据!");
        system("pause");
        return 0;
    }
    printf("共有%d个数据,分别为:\n",s->num);
    for(i=0;i<s->num;i++)
    {
        printf("第%d个数据为%d\n",i+1,temp->data);
        temp=temp->next;
    }
    system("pause");
}

int LINKSTACK(void)
{
    //system("pause");//调试用的
    void LinkStackMenu(void);//声明菜单模块
    linkStack *S=(linkStack *)malloc(sizeof(linkStack));//创建一个链栈
    initLinkStack(S);
    while(1)//封面死循环
    {
        system("cls");//清屏
        LinkStackMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':clearLinkStack(S);return 0;
                case '1':pushLinkStack(S);break;
                case '2':popLinkStack(S);break;
                case '3':clearLinkStack(S);break;
                case '4':throughLinkStack(S);break;
                default :continue;
            }
            break;
        }
    }
}

void LinkStackMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※      您现在在链栈页面     ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、数据入栈        █");
    puts("\t\t\t█         2、数据出栈        █");
    puts("\t\t\t█         3、清除栈列        █");
    puts("\t\t\t█         4、查看栈列        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}