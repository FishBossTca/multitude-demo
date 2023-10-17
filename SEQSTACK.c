/* 顺序栈模块 */
#include"head.h"
#define MAXSIZE 10
typedef struct//定义栈
{
    int data[MAXSIZE];
    int top;
    int num;
}SeqStack;

void initStack(SeqStack *s)//初始化栈模块
{
    s->top=-1;
    s->num=0;
}

int pushStack(SeqStack *s)//入栈模块
{
    system("cls");//清屏
    if(s->top==MAXSIZE-1)//判断是否满栈
    {
        puts("抱歉，该栈已满!");
        system("pause");
        return 0;
    }
    s->top++;
    puts("请输入需要进栈数据:");
    scanf("%d",&s->data[s->top]);
    fflush(stdin);//清空输入缓冲区，吃掉回车
    puts("输入完成!");
    s->num++;
    system("pause");
}

int popStack(SeqStack *s)//出栈模块
{
    system("cls");//清屏
    if(s->top==-1)//判断是否为空栈
    {
        puts("抱歉，没有数据可出栈!");
        system("pause");
        return 0;
    }
    printf("出栈数据为:%d\n",s->data[s->top]);
    --s->top;
    --s->num;
    system("pause");
}

void clearStack(SeqStack *s)//清空栈模块
{
    system("cls");
    s->top=-1;
    puts("清空完成!");
    system("pause");
    s->num=0;
}

int throughStack(SeqStack *s)//查看对栈模块
{
    system("cls");
    if(s->num==0)
    {
        puts("抱歉，没有数据!");
        system("pause");
        return 0;
    }
    int i;
    printf("共有%d个栈元素,从上到下依次为\n",s->num);
    for(i=s->top;i!=-1;--i,--s->top)
        printf("%d\n",s->data[s->top]);
    puts("输出完成!");
    s->top=s->num-1;
    system("pause");
}
int SEQSTACK(void)
{
    void SeqStackMenu(void);//声明菜单模块
    SeqStack _s,*S;//创建一个栈
    S=&_s;
    initStack(S);//初始化栈
    while(1)//封面死循环
    {
        system("cls");//清屏
        SeqStackMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':return 0;
                case '1':pushStack(S);break;
                case '2':popStack(S);break;
                case '3':clearStack(S);;break;
                case '4':throughStack(S);;break;
                default :continue;
            }
            break;
        }
        
    }
}

void SeqStackMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※     您现在在顺序栈页面    ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、数据入栈        █");
    puts("\t\t\t█         2、数据出栈        █");
    puts("\t\t\t█         3、清除栈列        █");
    puts("\t\t\t█         4、查看栈列        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}