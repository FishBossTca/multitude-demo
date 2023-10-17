#include"head.h"
#define MAXlong 100
typedef struct 
{
    int data[MAXlong];
    int num;
}List;

void SeqListMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��     ��������˳���ҳ��    ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1�����Ԫ��        ��");
    puts("\t\t\t��         2��ɾ��Ԫ��        ��");
    puts("\t\t\t��         3������Ԫ��        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

int searchInfo(int data,List *list)//��������λ��ģ��
{
    int i;
    for(i=0;i<list->num;i++)
    {
        if(data==list->data[i])
            return i;
    }
    return -1;//û�ҵ�����-1������������ظ�Ԫ��λ��
}

int addSeqList(List *list)//���Ԫ��ģ��
{
    system("cls");
    if(list->num>=MAXlong)
    {
        puts("��Ǹ,��˳�������!");
        system("pause");
        return 0;
    }
    int newdata;
    puts("��������Ҫ��ӵ�Ԫ��:");
    scanf("%d",&newdata);
    fflush(stdin);
    if(searchInfo(newdata,list)!=-1)//��Ԫ���Ѿ���ӹ�
    {
        puts("��Ǹ,��Ԫ���Ѿ�����!");
        system("pause");
        return 0;
    }
    list->data[list->num]=newdata;
    list->num++;
    puts("������!");
    system("pause");
}

int delSeqList(List *list)//ɾ��Ԫ��ģ��
{
    system("cls");
    int deleted,position,i;
    puts("��������Ҫɾ����Ԫ��");
    scanf("%d",&deleted);
    fflush(stdin);
    if((position=searchInfo(deleted,list))==-1)//û�ҵ���Ԫ��
    {
        puts("��Ǹ,û���ҵ���Ԫ��!");
        system("pause");
        return 0;
    }
    for(i=position;i<list->num;i++)
        list->data[i]=list->data[i+1];
    list->num--;
    puts("ɾ�����!");
    system("pause");
}

int scanSeqList(List *list)//����Ԫ��ģ��
{
    system("cls");
    int i;
    for(i=0;i<list->num;i++)
    {
        if(i!=0&&i%10==0)
            putchar('\n');
        printf("%d,",list->data[i]);
    }
    printf("\n����%d��Ԫ��\n",list->num);
    system("pause");
}

int SEQLIST(void)
{
    List *list=(List *)malloc(sizeof(List));
    list->num=0;
    while(1)//������ѭ��
    {
        system("cls");//����/*  */
        SeqListMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
            {
                case '0':free(list);return 0;
                case '1':addSeqList(list);break;
                case '2':delSeqList(list);break;
                case '3':scanSeqList(list);break;
                default :continue;
            }
            break;
        }
        
    }
}