#include"head.h"
#define MAXHASHSIZE 1024//最大表长
#define Dividend 1013//哈希函数除留余数法的被除数

typedef struct _data
{
    int data;
    struct _data *next;
}Node;

typedef struct 
{
    Node *next;
}elem;

typedef struct
{
    elem Table[MAXHASHSIZE];
    int num;
}HASHTable;

void HASHTableMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※   您现在在哈希表查找页面  ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、添加数据        █");
    puts("\t\t\t█         2、查找数据        █");
    puts("\t\t\t█         3、删除数据        █");
    puts("\t\t\t█         4、查看数据        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

void initHashTable(HASHTable *hash)//初始化哈希表模块
{
    int i=0;
    hash->num=0;
    for(i=0;i<MAXHASHSIZE;i++)
        hash->Table[i].next=NULL;
}

int hashFunction(int key)//哈希函数模块
{
    return key%Dividend;
}

int addHash(HASHTable *hash)//添加元素模块
{
    int hashFunction(int key);//声明哈希函数模块
    system("cls");
    int newData;
    puts("请输入需要添加的元素");
    scanf("%d",&newData);
    fflush(stdin);   
    Node *q,*p;
    p=hash->Table[hashFunction(newData)].next;
    if(p==NULL)//首次添加
    {
        hash->Table[hashFunction(newData)].next=p=(Node *)malloc(sizeof(Node));
        p->data=newData;
        p->next=NULL;
        puts("添加完成!");
        system("pause");
        hash->num++;
        return 0;
    }
    do//否则先找到空位子
    {
        if(p->data==newData)//先比较是否重复
        {
            puts("已添加相同元素,添加失败!");
            system("pause");
            return 0;
        }
        q=p;//q记录这次指针位置,为后来链接做准备
        p=p->next;
    }while(p!=NULL);
    
    q->next=p=(Node *)malloc(sizeof(Node));
    p->data=newData;
    p->next=NULL;
    puts("添加完成!");
    system("pause");
    hash->num++;
    return 0;
}

int searchHash(HASHTable *hash)//哈希表查找
{
    system("cls");
    int searched;
    Node *p;
    if(hash->num==0)
    {
        puts("抱歉，没有元素可供查找!");
        system("pause");
        return 0;
    }
    puts("请输入需要查找的元素");
    scanf("%d",&searched);
    fflush(stdin);
    p=hash->Table[hashFunction(searched)].next;
    if(p!=NULL)
        do
        {
            if(p->data==searched)
            {
                puts("查找成功!");
                system("pause");
                return 0;
            }
            p=p->next;
        }while(p!=NULL);
    puts("抱歉,没有找到该元素!");
    system("pause");
    return 0;
}

int deleteHash(HASHTable *hash)//删除哈希表元素
{
    system("cls");
    int deleted;
    Node *p,*q;
    if(hash->num==0)
    {
        puts("抱歉，没有元素可以删除!");
        system("pause");
        return 0;
    }
    puts("请输入需要删除的元素");
    scanf("%d",&deleted);
    fflush(stdin);
    q=p=hash->Table[hashFunction(deleted)].next;
    if(p!=NULL)
        do
        {
            if(p->data==deleted)
            {
                if(p==q)//只有一个节点
                    hash->Table[hashFunction(deleted)].next=NULL;
                q->next=p->next;
                free(p);
                puts("删除成功!");
                system("pause");
                return 0;
            }
            q=p;
            p=p->next;
        }while(p!=NULL);
    puts("抱歉,没有找到该元素!");
    system("pause");
    return 0;
}

int throughHash(HASHTable *hash)//遍历哈希表元素
{
    system("cls");
    int i;
    Node *p;
    if(hash->num==0)
    {
        puts("抱歉，没有元素可以遍历");
        system("pause");
        return 0;
    }
    for(i=0;i<MAXHASHSIZE;i++)
    {
        p=hash->Table[i].next;
        if(hash->Table[i].next!=NULL)
        {
            printf("第%d个位置上有");
            while(p!=NULL)
            {
                printf("%d,",p->data);
                p=p->next;
            }
            putchar('\n');
        }
    }
    printf("一共%d个元素",hash->num);
    system("pause");
}

int HASHTABLE(void)
{
    HASHTable *hash=(HASHTable *)malloc(sizeof(HASHTable));//创建哈希表
    initHashTable(hash);//初始化哈希表
    while(1)//封面死循环
    {
        system("cls");//清屏
        HASHTableMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':free(hash);return 0;
                case '1':addHash(hash);break;
                case '2':searchHash(hash);break;
                case '3':deleteHash(hash);break;
                case '4':throughHash(hash);break;
                default :continue;
            }
            break;
        }
    }

}