/* 顺序队列 */
#include"head.h"

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int head;
    int tail;
}SqQueue;

void initQueue(SqQueue *q)//初始化队列
{
    q->head=0;
    q->tail=0;
}

int enQueue(SqQueue *q)//入队模块
{
    system("cls");
    if((q->tail+1)%MAXSIZE==q->head)//判断是否满队
    {
        puts("错误，队列已满");
        system("pause");
        return 0;
    }
    puts("请输入需要入队的值:");
    scanf("%d",&q->data[q->tail]);
    q->tail=(q->tail+1)%MAXSIZE;//取余为了让队列变为循环队列
    fflush(stdin);
    puts("添加完成!");
    system("pause");
}

int delQueue(SqQueue *q)//出队模块
{
    system("cls");
    if(q->head==q->tail)//空队列判断
    {
        puts("错误，队列为空");
        system("pause");
        return 0;
    }
    printf("出队数据为%d\n",q->data[q->head]);
    q->head=(q->head+1)%MAXSIZE;
    system("pause");
}

void cleanQueue(SqQueue *q)//清除队列模块
{
    system("cls");
    q->head=q->tail=0;
    puts("清空完成!");
    system("pause");
}

int infoQueue(SqQueue *q)//查看队列长度及信息模块
{
    system("cls");
    if(q->head==q->tail)
    {
        puts("抱歉，没有数据!");
        system("pause");
        return 0;
    }
    int i,initPosition=q->head;
    printf("当前队列长度为%d,他们的从头到尾分别是\n",(q->tail-q->head+MAXSIZE)%MAXSIZE);
    do
    {
        printf("%d\n",q->data[q->head]);
        q->head=(q->head+1)%MAXSIZE;
    }while(q->head!=q->tail);//当头尾指针相遇是不进行循环
    q->head=initPosition;
    system("pause");
}

int SEQQUEUE(void)
{
    void SeqQUeueMenu(void);//声明菜单模块
    SqQueue *Q=(SqQueue *)malloc(sizeof(SqQueue));//创建队列指针
    initQueue(Q);
    while(1)//封面死循环
    {
        system("cls");//清屏
        SeqQUeueMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':free(Q);return 0;
                case '1':enQueue(Q);break;
                case '2':delQueue(Q);break;
                case '3':;cleanQueue(Q);break;
                case '4':infoQueue(Q);;break;
                default :continue;
            }
            break;
        }
        
    }
}

void SeqQUeueMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※    您现在在顺序队列页面   ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、数据入队        █");
    puts("\t\t\t█         2、数据出队        █");
    puts("\t\t\t█         3、清除对列        █");
    puts("\t\t\t█         4、查看队列        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}