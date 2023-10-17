/* ˳����� */
#include"head.h"

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int head;
    int tail;
}SqQueue;

void initQueue(SqQueue *q)//��ʼ������
{
    q->head=0;
    q->tail=0;
}

int enQueue(SqQueue *q)//���ģ��
{
    system("cls");
    if((q->tail+1)%MAXSIZE==q->head)//�ж��Ƿ�����
    {
        puts("���󣬶�������");
        system("pause");
        return 0;
    }
    puts("��������Ҫ��ӵ�ֵ:");
    scanf("%d",&q->data[q->tail]);
    q->tail=(q->tail+1)%MAXSIZE;//ȡ��Ϊ���ö��б�Ϊѭ������
    fflush(stdin);
    puts("������!");
    system("pause");
}

int delQueue(SqQueue *q)//����ģ��
{
    system("cls");
    if(q->head==q->tail)//�ն����ж�
    {
        puts("���󣬶���Ϊ��");
        system("pause");
        return 0;
    }
    printf("��������Ϊ%d\n",q->data[q->head]);
    q->head=(q->head+1)%MAXSIZE;
    system("pause");
}

void cleanQueue(SqQueue *q)//�������ģ��
{
    system("cls");
    q->head=q->tail=0;
    puts("������!");
    system("pause");
}

int infoQueue(SqQueue *q)//�鿴���г��ȼ���Ϣģ��
{
    system("cls");
    if(q->head==q->tail)
    {
        puts("��Ǹ��û������!");
        system("pause");
        return 0;
    }
    int i,initPosition=q->head;
    printf("��ǰ���г���Ϊ%d,���ǵĴ�ͷ��β�ֱ���\n",(q->tail-q->head+MAXSIZE)%MAXSIZE);
    do
    {
        printf("%d\n",q->data[q->head]);
        q->head=(q->head+1)%MAXSIZE;
    }while(q->head!=q->tail);//��ͷβָ�������ǲ�����ѭ��
    q->head=initPosition;
    system("pause");
}

int SEQQUEUE(void)
{
    void SeqQUeueMenu(void);//�����˵�ģ��
    SqQueue *Q=(SqQueue *)malloc(sizeof(SqQueue));//��������ָ��
    initQueue(Q);
    while(1)//������ѭ��
    {
        system("cls");//����
        SeqQUeueMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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

void SeqQUeueMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��    ��������˳�����ҳ��   ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1���������        ��");
    puts("\t\t\t��         2�����ݳ���        ��");
    puts("\t\t\t��         3���������        ��");
    puts("\t\t\t��         4���鿴����        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}