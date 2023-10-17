/* ˳��ջģ�� */
#include"head.h"
#define MAXSIZE 10
typedef struct//����ջ
{
    int data[MAXSIZE];
    int top;
    int num;
}SeqStack;

void initStack(SeqStack *s)//��ʼ��ջģ��
{
    s->top=-1;
    s->num=0;
}

int pushStack(SeqStack *s)//��ջģ��
{
    system("cls");//����
    if(s->top==MAXSIZE-1)//�ж��Ƿ���ջ
    {
        puts("��Ǹ����ջ����!");
        system("pause");
        return 0;
    }
    s->top++;
    puts("��������Ҫ��ջ����:");
    scanf("%d",&s->data[s->top]);
    fflush(stdin);//������뻺�������Ե��س�
    puts("�������!");
    s->num++;
    system("pause");
}

int popStack(SeqStack *s)//��ջģ��
{
    system("cls");//����
    if(s->top==-1)//�ж��Ƿ�Ϊ��ջ
    {
        puts("��Ǹ��û�����ݿɳ�ջ!");
        system("pause");
        return 0;
    }
    printf("��ջ����Ϊ:%d\n",s->data[s->top]);
    --s->top;
    --s->num;
    system("pause");
}

void clearStack(SeqStack *s)//���ջģ��
{
    system("cls");
    s->top=-1;
    puts("������!");
    system("pause");
    s->num=0;
}

int throughStack(SeqStack *s)//�鿴��ջģ��
{
    system("cls");
    if(s->num==0)
    {
        puts("��Ǹ��û������!");
        system("pause");
        return 0;
    }
    int i;
    printf("����%d��ջԪ��,���ϵ�������Ϊ\n",s->num);
    for(i=s->top;i!=-1;--i,--s->top)
        printf("%d\n",s->data[s->top]);
    puts("������!");
    s->top=s->num-1;
    system("pause");
}
int SEQSTACK(void)
{
    void SeqStackMenu(void);//�����˵�ģ��
    SeqStack _s,*S;//����һ��ջ
    S=&_s;
    initStack(S);//��ʼ��ջ
    while(1)//������ѭ��
    {
        system("cls");//����
        SeqStackMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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

void SeqStackMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��     ��������˳��ջҳ��    ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1��������ջ        ��");
    puts("\t\t\t��         2�����ݳ�ջ        ��");
    puts("\t\t\t��         3�����ջ��        ��");
    puts("\t\t\t��         4���鿴ջ��        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}