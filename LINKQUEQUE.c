/* ����ģ�� */
#include"head.h"
#define QueueRam (QNode *)malloc(sizeof(QNode))//�����ڴ�
typedef struct _linkQueue//����ڵ���ջ
{
   int data;
   struct _linkQueue *next;
}QNode;

typedef struct
{
    QNode *head,*tail;
    int num;
}LinkQueue;

void initLinkQueue(LinkQueue *q)//��ʼ������
{
    q->num=0;
}

int enLinkQueue(LinkQueue *q)//���ģ��
{
    system("cls");
    if(q->num==0)
    {
        q->head=q->tail=QueueRam;
        puts("��������Ҫ���ӵ�����");
        scanf("%d",&q->tail->data);
        fflush(stdin);
        puts("�������!");
        ++q->num;
        system("pause");
        return 0;
    }
    q->tail->next=QueueRam;
    puts("��������Ҫ���ӵ�����");
    scanf("%d",&q->tail->next->data);
    fflush(stdin);
    puts("�������!");
    q->tail=q->tail->next;
    ++q->num;
    system("pause");
}

int delLinkQueue(LinkQueue *q)//����ģ��
{
    system("cls");
    QNode *cutQueue;
    if(q->num==0)//�ж��Ƿ�Ϊ�ն�
    {
        puts("��Ǹ��û�����ݿɳ���!");
        system("pause");
        return 0;
    }
    printf("��������Ϊ:%d\n",q->head->data);
    cutQueue=q->head;
    q->head=q->head->next;
    free(cutQueue);
    q->num--;
    system("pause");
}

void clearLinkQueue(LinkQueue *q)//��ն�ģ��
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
    puts("ɾ�����!");
    system("pause");
}

int throughLinkQueue(LinkQueue *q)//�鿴��ջģ��
{
    system("cls");
    if(q->num==0)
    {
        puts("��Ǹ��û������!");
        system("pause");
        return 0;
    }
    QNode *temp=q->head;
    int i;
    printf("����%d������,�ֱ�Ϊ:\n",q->num);
    for(i=0;i<q->num;i++)
    {
        printf("��%d������Ϊ%d\n",i+1,temp->data);
        temp=temp->next;
    }
    system("pause");
}

int LINKQUEUE(void)
{
    //system("pause");//�����õ�
    void Menu(void);//�����˵�ģ��
    LinkQueue *Q=(LinkQueue *)malloc(sizeof(LinkQueue));//����һ������
    initLinkQueue(Q);
    while(1)//������ѭ��
    {
        system("cls");//����
        Menu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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

void Menu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��    ����������ʽ����ҳ��   ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1���������        ��");
    puts("\t\t\t��         2�����ݳ���        ��");
    puts("\t\t\t��         3���������        ��");
    puts("\t\t\t��         4���鿴����        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}