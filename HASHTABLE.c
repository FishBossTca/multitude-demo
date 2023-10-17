#include"head.h"
#define MAXHASHSIZE 1024//����
#define Dividend 1013//��ϣ���������������ı�����

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

void HASHTableMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��   �������ڹ�ϣ�����ҳ��  ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1���������        ��");
    puts("\t\t\t��         2����������        ��");
    puts("\t\t\t��         3��ɾ������        ��");
    puts("\t\t\t��         4���鿴����        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

void initHashTable(HASHTable *hash)//��ʼ����ϣ��ģ��
{
    int i=0;
    hash->num=0;
    for(i=0;i<MAXHASHSIZE;i++)
        hash->Table[i].next=NULL;
}

int hashFunction(int key)//��ϣ����ģ��
{
    return key%Dividend;
}

int addHash(HASHTable *hash)//���Ԫ��ģ��
{
    int hashFunction(int key);//������ϣ����ģ��
    system("cls");
    int newData;
    puts("��������Ҫ��ӵ�Ԫ��");
    scanf("%d",&newData);
    fflush(stdin);   
    Node *q,*p;
    p=hash->Table[hashFunction(newData)].next;
    if(p==NULL)//�״����
    {
        hash->Table[hashFunction(newData)].next=p=(Node *)malloc(sizeof(Node));
        p->data=newData;
        p->next=NULL;
        puts("������!");
        system("pause");
        hash->num++;
        return 0;
    }
    do//�������ҵ���λ��
    {
        if(p->data==newData)//�ȱȽ��Ƿ��ظ�
        {
            puts("�������ͬԪ��,���ʧ��!");
            system("pause");
            return 0;
        }
        q=p;//q��¼���ָ��λ��,Ϊ����������׼��
        p=p->next;
    }while(p!=NULL);
    
    q->next=p=(Node *)malloc(sizeof(Node));
    p->data=newData;
    p->next=NULL;
    puts("������!");
    system("pause");
    hash->num++;
    return 0;
}

int searchHash(HASHTable *hash)//��ϣ�����
{
    system("cls");
    int searched;
    Node *p;
    if(hash->num==0)
    {
        puts("��Ǹ��û��Ԫ�ؿɹ�����!");
        system("pause");
        return 0;
    }
    puts("��������Ҫ���ҵ�Ԫ��");
    scanf("%d",&searched);
    fflush(stdin);
    p=hash->Table[hashFunction(searched)].next;
    if(p!=NULL)
        do
        {
            if(p->data==searched)
            {
                puts("���ҳɹ�!");
                system("pause");
                return 0;
            }
            p=p->next;
        }while(p!=NULL);
    puts("��Ǹ,û���ҵ���Ԫ��!");
    system("pause");
    return 0;
}

int deleteHash(HASHTable *hash)//ɾ����ϣ��Ԫ��
{
    system("cls");
    int deleted;
    Node *p,*q;
    if(hash->num==0)
    {
        puts("��Ǹ��û��Ԫ�ؿ���ɾ��!");
        system("pause");
        return 0;
    }
    puts("��������Ҫɾ����Ԫ��");
    scanf("%d",&deleted);
    fflush(stdin);
    q=p=hash->Table[hashFunction(deleted)].next;
    if(p!=NULL)
        do
        {
            if(p->data==deleted)
            {
                if(p==q)//ֻ��һ���ڵ�
                    hash->Table[hashFunction(deleted)].next=NULL;
                q->next=p->next;
                free(p);
                puts("ɾ���ɹ�!");
                system("pause");
                return 0;
            }
            q=p;
            p=p->next;
        }while(p!=NULL);
    puts("��Ǹ,û���ҵ���Ԫ��!");
    system("pause");
    return 0;
}

int throughHash(HASHTable *hash)//������ϣ��Ԫ��
{
    system("cls");
    int i;
    Node *p;
    if(hash->num==0)
    {
        puts("��Ǹ��û��Ԫ�ؿ��Ա���");
        system("pause");
        return 0;
    }
    for(i=0;i<MAXHASHSIZE;i++)
    {
        p=hash->Table[i].next;
        if(hash->Table[i].next!=NULL)
        {
            printf("��%d��λ������");
            while(p!=NULL)
            {
                printf("%d,",p->data);
                p=p->next;
            }
            putchar('\n');
        }
    }
    printf("һ��%d��Ԫ��",hash->num);
    system("pause");
}

int HASHTABLE(void)
{
    HASHTable *hash=(HASHTable *)malloc(sizeof(HASHTable));//������ϣ��
    initHashTable(hash);//��ʼ����ϣ��
    while(1)//������ѭ��
    {
        system("cls");//����
        HASHTableMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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