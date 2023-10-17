/* 链队模块 */
#include"head.h"
#define QueueRam (QNode *)malloc(sizeof(QNode))//分配内存
typedef struct _linkQueue//定义节点链栈
{
   int data;
   struct _linkQueue *next;
}QNode;

typedef struct
{
    QNode *head,*tail;
    int num;
}LinkQueue;

void initLinkQueue(LinkQueue *q)//初始化链队
{
    q->num=0;
}

int enLinkQueue(LinkQueue *q)//入队模块
{
    system("cls");
    if(q->num==0)
    {
        q->head=q->tail=QueueRam;
        puts("请输入需要进队的数据");
        scanf("%d",&q->tail->data);
        fflush(stdin);
        puts("输入完成!");
        ++q->num;
        system("pause");
        return 0;
    }
    q->tail->next=QueueRam;
    puts("请输入需要进队的数据");
    scanf("%d",&q->tail->next->data);
    fflush(stdin);
    puts("输入完成!");
    q->tail=q->tail->next;
    ++q->num;
    system("pause");
}

int delLinkQueue(LinkQueue *q)//出队模块
{
    system("cls");
    QNode *cutQueue;
    if(q->num==0)//判断是否为空队
    {
        puts("抱歉，没有数据可出队!");
        system("pause");
        return 0;
    }
    printf("出队数据为:%d\n",q->head->data);
    cutQueue=q->head;
    q->head=q->head->next;
    free(cutQueue);
    q->num--;
    system("pause");
}

void clearLinkQueue(LinkQueue *q)//清空队模块
{
    system("cls");
    int i;
    QNode *cutQueue;
    for(i=0;i<q->num;i++)
    {
        cutQueue=q->head;
        q->head=q->head->next;
        free(cutQueue);
        q->num--;
    }
    q->num=0;
    puts("删除完成!");
    system("pause");
}

int throughLinkQueue(LinkQueue *q)//查看链栈模块
{
    system("cls");
    if(q->num==0)
    {
        puts("抱歉，没有数据!");
        system("pause");
        return 0;
    }
    QNode *temp=q->head;
    int i;
    printf("共有%d个数据,分别为:\n",q->num);
    for(i=0;i<q->num;i++)
    {
        printf("第%d个数据为%d\n",i+1,temp->data);
        temp=temp->next;
    }
    system("pause");
}

int LINKQUEUE(void)
{
    //system("pause");//调试用的
    void Menu(void);//声明菜单模块
    LinkQueue *Q=(LinkQueue *)malloc(sizeof(LinkQueue));//创建一个链队
    initLinkQueue(Q);
    while(1)//封面死循环
    {
        system("cls");//清屏
        Menu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':clearLinkQueue(Q);return 0;
                case '1':enLinkQueue(Q);break;
                case '2':delLinkQueue(Q);break;
                case '3':clearLinkQueue(Q);break;
                case '4':throughLinkQueue(Q);break;
                default :continue;
            }
            break;
        }
    }
}

void Menu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※    您现在在链式队列页面   ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、数据入队        █");
    puts("\t\t\t█         2、数据出队        █");
    puts("\t\t\t█         3、清除队列        █");
    puts("\t\t\t█         4、查看队列        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}