/* ����ģ�� */
#include"head.h"

struct STUDENT
{
    int num;
    char name[10];
    struct STUDENT *next;
}*head,*t,*p,*p_del;

int errorInfo(void);//��������Ϣ��ⱨ��ģ��

int LINKLIST(void)
{
    head=t=p=NULL;//��ʼ��ָ��
    void LinkListMenu(void);//�����˵�ģ��
    void addInfo(void);//������Ϣ���ģ��
    int showInfo(void);//������ʾȫ����Ϣģ��
    int insertInfo(void);//����������Ϣģ��
    int delInfo(void);//����ɾ����Ϣģ��
    while(1)//������ѭ��
    {
        system("cls");//����
        LinkListMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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

void LinkListMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��      ������������ҳ��     ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0��������ҳ        ��");
    puts("\t\t\t��         1�������Ϣ        ��");
    puts("\t\t\t��         2����ѯ��Ϣ        ��");
    puts("\t\t\t��         3��������Ϣ        ��");
    puts("\t\t\t��         4��ɾ����Ϣ        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

void addInfo(void)//��Ϣ���ģ��
{
    system("cls");
    if(head==NULL)//�״δ�������,��Ҫָ��ͷָ��λ��
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
    puts("������ѧ��:");
    scanf("%d",&t->num);
    fflush(stdin);//����س�������scanf�����״���
    puts("����������:");
    gets(t->name);
    puts("���!");
    system("pause");//�������������
}

int showInfo(void)//��ʾȫ����Ϣģ��
{
    system("cls");
    if(!errorInfo())//����Ϣ��ⱨ��ģ��
        return 0;
    else
    p=head->next;//ͷָ�벻����Ϣ��ֻ�������
    while(p!=NULL)
    {   
        printf("ѧ��:%d\t����:%s\n",p->num,p->name);
        p=p->next;
    }
    system("pause");
}

int insertInfo(void)//������Ϣģ��
{
    system("cls");
    if(!errorInfo())//����Ϣ��ⱨ��ģ��
        return 0;
    int num;
    p_del=(struct STUDENT *)malloc(sizeof(struct STUDENT));
    puts("��������Ҫ����Ԫ�ص�num(Ϊ��Ԫ�غ�)");
    scanf("%d",&num);
    fflush(stdin);
    p=head->next;
    while(p!=NULL)
    {
        if(p->num==num)
        {
            puts("�õģ���������Ҫ�������Ϣ:");
            printf("ѧ��:");
            scanf("%d",&p_del->num);
            fflush(stdin);
            printf("����:");
            gets(p_del->name);
            p_del->next=p->next;
            p->next=p_del;
            puts("���!");
            system("pause");
            return 0;
        }
        p=p->next;
    }
    puts("��Ǹ���޷��ҵ���Ԫ��!");
    system("pause");
}

int delInfo(void)//ɾ����Ϣģ��
{
    system("cls");
    if(!errorInfo())
        return 0;
    int num;
    puts("��������Ҫɾ������Ϣ����Ӧ��ѧ��:");
    scanf("%d",&num);
    fflush(stdin);
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->num==num)
        {
            if(t==p)
                t=p;//���ɾ���������һ��Ԫ�أ��Ͱ�βָ����ǰ�ƣ������´�βָ���޷�ʹ��
            p_del=p->next;
            p->next=p->next->next;
            free(p_del);
            puts("ɾ����ɣ�");
            system("pause");
            return 0;
        }
        else p=p->next;
    }
    puts("��Ǹ��û���ҵ�������");
    system("pause");
}

int errorInfo(void)//����Ϣ��ⱨ��ģ��
{
    if(head==NULL)
    {
        puts("����,û������!");
        system("pause");
        return 0;
    }
    return 1;
}