/* ��ջģ�� */
#include"head.h"

#define MAXSIZE 10
#define stackRam (NodeStack *)malloc(sizeof(NodeStack))//�����ڴ�
typedef struct _SeqStack//������ջ
{
    int data;
    struct _SeqStack *next;
}NodeStack;

typedef struct
{
    NodeStack *top;
    int num;
}linkStack;//���嶥ջ

void initLinkStack(linkStack *s)//��ʼ����ջģ��
{
    s->num=0;
}

int pushLinkStack(linkStack *s)//���ݽ�ջģ��
{
    system("cls");
    if(s->num==0)//�״�ֱ��ʹ��topָ��
    {
        s->top=stackRam;
        puts("��������Ҫ��ջ������");
        scanf("%d",&s->top->data);
        fflush(stdin);
        puts("�������!");
        ++s->num;
        system("pause");
        return 0;
    }
    NodeStack *link=stackRam;//�����µĽڵ�
    link->next=s->top;
    puts("��������Ҫ��ջ������");
    scanf("%d",&link->data);
    fflush(stdin);
    s->top=link;
    s->num++;
    puts("�������!");
    system("pause");
}

int popLinkStack(linkStack *s)//��ջģ��
{
    NodeStack *delStack;
    system("cls");//����
    if(s->num==0)//�ж��Ƿ�Ϊ��ջ
    {
        puts("��Ǹ��û�����ݿɳ�ջ!");
        system("pause");
        return 0;
    }
    printf("��ջ����Ϊ:%d\n",s->top->data);
    delStack=s->top;
    s->top=s->top->next;
    free(delStack);
    s->num--;
    system("pause");
}

void clearLinkStack(linkStack *s)//���ջģ��
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
    puts("ɾ�����!");
    system("pause");
}

int throughLinkStack(linkStack *s)//�鿴��ջģ��
{
    system("cls");
    NodeStack *temp=s->top;
    int i;
    if(s->num==0)
    {
        puts("��Ǹ��û������!");
        system("pause");
        return 0;
    }
    printf("����%d������,�ֱ�Ϊ:\n",s->num);
    for(i=0;i<s->num;i++)
    {
        printf("��%d������Ϊ%d\n",i+1,temp->data);
        temp=temp->next;
    }
    system("pause");
}

int LINKSTACK(void)
{
    //system("pause");//�����õ�
    void LinkStackMenu(void);//�����˵�ģ��
    linkStack *S=(linkStack *)malloc(sizeof(linkStack));//����һ����ջ
    initLinkStack(S);
    while(1)//������ѭ��
    {
        system("cls");//����
        LinkStackMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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

void LinkStackMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��      ����������ջҳ��     ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1��������ջ        ��");
    puts("\t\t\t��         2�����ݳ�ջ        ��");
    puts("\t\t\t��         3�����ջ��        ��");
    puts("\t\t\t��         4���鿴ջ��        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}