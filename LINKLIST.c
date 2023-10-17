/* 链表模块 */
#include"head.h"

struct STUDENT
{
    int num;
    char name[10];
    struct STUDENT *next;
}*head,*t,*p,*p_del;

int errorInfo(void);//声明空信息检测报错模块

int LINKLIST(void)
{
    head=t=p=NULL;//初始化指针
    void LinkListMenu(void);//声明菜单模块
    void addInfo(void);//声明信息添加模块
    int showInfo(void);//声明显示全部信息模块
    int insertInfo(void);//声明插入信息模块
    int delInfo(void);//声明删除信息模块
    while(1)//封面死循环
    {
        system("cls");//清屏
        LinkListMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':free(p_del);return 0;
                case '1':addInfo();break;
                case '2':showInfo();break;
                case '3':insertInfo();break;
                case '4':delInfo();break;
                default :continue;
            }
            break;
        }
        
    }

}

void LinkListMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※      您现在在链表页面     ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、返回主页        █");
    puts("\t\t\t█         1、添加信息        █");
    puts("\t\t\t█         2、查询信息        █");
    puts("\t\t\t█         3、插入信息        █");
    puts("\t\t\t█         4、删除信息        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

void addInfo(void)//信息添加模块
{
    system("cls");
    if(head==NULL)//首次创建链表,需要指定头指针位置
    {
        head=(struct STUDENT *)malloc(sizeof(struct STUDENT));
        t=(struct STUDENT *)malloc(sizeof(struct STUDENT));
        head->next=t;
    }
    else
    {
        t->next=(struct STUDENT *)malloc(sizeof(struct STUDENT));
        t=t->next;
    } 
    t->next=NULL;
    puts("请输入学号:");
    scanf("%d",&t->num);
    fflush(stdin);//清除回车，算是scanf的配套代码
    puts("请输入名字:");
    gets(t->name);
    puts("完成!");
    system("pause");//按下任意键继续
}

int showInfo(void)//显示全部信息模块
{
    system("cls");
    if(!errorInfo())//空信息检测报错模块
        return 0;
    else
    p=head->next;//头指针不含信息，只负责领队
    while(p!=NULL)
    {   
        printf("学号:%d\t姓名:%s\n",p->num,p->name);
        p=p->next;
    }
    system("pause");
}

int insertInfo(void)//插入信息模块
{
    system("cls");
    if(!errorInfo())//空信息检测报错模块
        return 0;
    int num;
    p_del=(struct STUDENT *)malloc(sizeof(struct STUDENT));
    puts("请输入需要插入元素的num(为该元素后方)");
    scanf("%d",&num);
    fflush(stdin);
    p=head->next;
    while(p!=NULL)
    {
        if(p->num==num)
        {
            puts("好的，请输入需要插入的信息:");
            printf("学号:");
            scanf("%d",&p_del->num);
            fflush(stdin);
            printf("名字:");
            gets(p_del->name);
            p_del->next=p->next;
            p->next=p_del;
            puts("完成!");
            system("pause");
            return 0;
        }
        p=p->next;
    }
    puts("抱歉，无法找到该元素!");
    system("pause");
}

int delInfo(void)//删除信息模块
{
    system("cls");
    if(!errorInfo())
        return 0;
    int num;
    puts("请输入需要删除的信息所对应的学号:");
    scanf("%d",&num);
    fflush(stdin);
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->num==num)
        {
            if(t==p)
                t=p;//如果删除的是最后一个元素，就把尾指针往前移，避免下次尾指针无法使用
            p_del=p->next;
            p->next=p->next->next;
            free(p_del);
            puts("删除完成！");
            system("pause");
            return 0;
        }
        else p=p->next;
    }
    puts("抱歉，没有找到该数据");
    system("pause");
}

int errorInfo(void)//空信息检测报错模块
{
    if(head==NULL)
    {
        puts("错误,没有数据!");
        system("pause");
        return 0;
    }
    return 1;
}