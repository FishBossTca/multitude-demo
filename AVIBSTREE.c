#include"head.h"
typedef struct BinarySearchTree//����������ڵ�
{
    int data;
    int BF;
    struct BinarySearchTree *Lchild,*Rchild,*Father;
}Node;

typedef struct 
{
    int num;
    Node *root;
}AVI;

int checkBalance(Node *node,AVI *tree);//�������������Ƿ�ƽ��ģ��
Node *SEACHPosition(Node *tree,int seachData);//��������Ԫ��λ���Ӻ���

void BSTreeMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��   �������ڶ��������ҳ��  ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1���������        ��");
    puts("\t\t\t��         2����������        ��");
    puts("\t\t\t��         3��ɾ������        ��");
    puts("\t\t\t��         4���鿴����        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

void initTree(AVI *tree)//��ʼ��������ģ��
{
    tree->num=0;
    tree->root=NULL;
}

int addTree(AVI *tree)//���Ԫ��ģ��
{
    system("cls");
    int newdate;
    Node *p,*newnode=(Node *)malloc(sizeof(Node));
    newnode->Lchild=NULL;newnode->Rchild=NULL;newnode->BF=0;
    p=tree->root;
    puts("��������ӵ�Ԫ��");
    scanf("%d",&newdate);
    fflush(stdin);
    if(tree->num==0)//�״���Ӹ��ڵ�
    {
        newnode->data=newdate;
        tree->root=newnode;
        newnode->Father=NULL;
        tree->num++;
        puts("��ӳɹ�!");
        system("pause");
        return 0;
    }
    while(1)
    {
        if(newdate<p->data)
        {
            if(p->Lchild==NULL)
            {
                p->Lchild=newnode;
                newnode->data=newdate;
                newnode->Father=p;
                tree->num++;
                puts("������!(��)");
                checkBalance(newnode,tree);
                system("pause");
                return 0;
            }
            p=p->Lchild;
        }
        else if(newdate>p->data)
        {
            if(p->Rchild==NULL)
            {
                p->Rchild=newnode;
                newnode->data=newdate;
                newnode->Father=p;
                tree->num++;
                puts("������!(��)");
                checkBalance(newnode,tree);
                system("pause");
                return 0;
            }
            p=p->Rchild;
        }
        else
        {
            puts("�Ѿ�������ͬ�ڵ�,���ʧ��!");
            system("pause");
            return 0;
        }
    }
}

int checkBalance(Node *node,AVI *tree)//���������Ƿ�ƽ��
{
    int RotateLL(Node *node,AVI *tree);//��������
    int RotateRR(Node *node,AVI *tree);//��������
    int RotateLR(Node *node,AVI *tree);//�������������
    int RotateRL(Node *node,AVI *tree);//�������Һ�����
    while(node->Father!=NULL)
    {
        if(node==node->Father->Lchild)//�Ǹ��׵���
            node->Father->BF++;
        else
            node->Father->BF--;
        if(node->Father->BF==0)//������ϲ���Ӱ��
            return 0;
        else if(abs(node->Father->BF)==1)//���׵�ƽ�����Ӿ���ֵ=1,���汲����(�汲������Ӱ��
            node=node->Father;
        else if(abs(node->Father->BF)>1)//����ֵ>1,��Ҫƽ�����
        {
            if(node->Father->BF>1)//��߸�
            {
                if(node->BF==1)//����λ��ΪLL
                    RotateLL(node,tree);//ֱ������
                else
                    RotateLR(node,tree);//������
                return 0;
            }
            else//�ұ߸�
            {
                if(node->BF==-1)//����λ��ΪRR
                    RotateRR(node,tree);//ֱ������
                else
                    RotateRL(node,tree);//������
                return 0;
            }
        }
    }
}

int RotateLL(Node *node,AVI *tree)//����
{
    node->BF=0;node->Father->BF=0;
    if(node->Lchild!=NULL)
        node->Lchild->BF=0;
    /* �����ѡһ�������ж�үү��״��,������ӻ����Ҷ���,�����ǿ�үү(�ְ��Ǹ�) */
    if(node->Father->Father==NULL)//�����󵽴���ڵ�,��Ҫ���µ������ڵ�ָ��ָ��
        tree->root=node;
    else if(node->Father->Father->Lchild==node->Father)//�жϸ��׽ڵ��Ƿ�Ϊүү����ڵ�
        node->Father->Father->Lchild=node;//Ϊ�������Ƚڵ����ҵ�����
    else
        node->Father->Father->Rchild=node;
    node->Father->Lchild=node->Rchild;//LL�͵���
    node->Rchild=node->Father;
    /* �����¸���,���ｨ�黭˫��ͼ��⣬�Ƚ��鷳,˳���ܻ� */
    node->Father=node->Rchild->Father;
        node->Rchild->Father=node;
    if(node->Rchild->Lchild!=NULL)//��ָ��Ļ�û�и���
        node->Rchild->Lchild->Father=node->Rchild;
}

int RotateRR(Node *node,AVI *tree)//����
{
    node->BF=0;node->Father->BF=0;
    if(node->Rchild!=NULL)
        node->Rchild->BF=0;
    /* �����ѡһ�������ж�үү��״��,������ӻ����Ҷ���,�����ǿ�үү(�ְ��Ǹ�) */
    if(node->Father->Father==NULL)//�����󵽴���ڵ�,��Ҫ���µ������ڵ�ָ��ָ��
        tree->root=node;
    else if(node->Father==node->Father->Father->Lchild)//�жϸ��׽ڵ��Ƿ�Ϊүү����ڵ�
        node->Father->Father->Lchild=node;//Ϊ�������Ƚڵ����ҵ�����
    else
        node->Father->Father->Rchild=node;
    node->Father->Rchild=node->Lchild;//RR�͵���
    node->Lchild=node->Father;
    /* �����¸��� */
    node->Father=node->Lchild->Father;
    node->Lchild->Father=node;
    if(node->Lchild->Rchild!=NULL)//��ָ��Ļ�û�и���
        node->Lchild->Rchild->Father=node->Lchild;
}

int RotateLR(Node *node,AVI *tree)//���������
{
    Node *p=node->Rchild;
    int RotateLL(Node *node,AVI *tree);//��������
    int RotateRR(Node *node,AVI *tree);//��������
    RotateRR(node->Rchild,tree);
    RotateLL(p,tree);
}

int RotateRL(Node *node,AVI *tree)//���Һ�����
{
    Node *p=node->Lchild;
    int RotateLL(Node *node,AVI *tree);//��������
    int RotateRR(Node *node,AVI *tree);//��������
    RotateLL(node->Lchild,tree);
    RotateRR(p,tree);
}

int seachTree(AVI *tree)//������ģ��
{
    system("cls");
    int seachData;
    Node *p=tree->root;
    puts("��������Ҫ���ҵ���ֵ");
    scanf("%d",&seachData);
    fflush(stdin);
    if((p=SEACHPosition(p,seachData))!=NULL)
    {
        puts("�ҵ���!");
        system("pause");
        return 0;
    }
    puts("��Ǹ��û�ҵ�!");
    system("pause");
    return 0;
}

Node *SEACHPosition(Node *tree,int seachData)//����Ԫ��λ���Ӻ���
{
    Node *p=tree,*q=NULL;
    while(p!=NULL)
    {
        if(seachData<p->data)
        {
            q=p;p=p->Lchild;
        }
        else if(seachData>p->data)
        {
            q=p;p=p->Rchild;
            }
        else
            return p;
    }
    return NULL;
}

int throughTree(AVI *tree)//����Ԫ��ģ��
{
    int recursionTree(Node *tree);//�����ݹ������ģ��
    system("cls");
    if(tree->num==0)
    {
        puts("��Ǹ,û��Ԫ�ؿ��Ա���!");
        system("pause");
        return 0;
    }
    printf("����Ԫ��Ϊ:");
    recursionTree(tree->root);
    printf("����%d��Ԫ��",tree->num);
    putchar('\n');
    system("pause");
    return 0;
}

int deleteTree(AVI *tree)//ɾ����Ԫ��ģ��
{
    system("cls");
    int deleteData;
    Node *p=tree->root,*s,*q;
    puts("��������Ҫɾ����Ԫ��");
    scanf("%d",&deleteData);
    fflush(stdin);
    if((p=SEACHPosition(p,deleteData))!=NULL)
    {
        if(p->Lchild==NULL&&p->Rchild==NULL)//��Ҷ�ӽڵ�,û�к���
        {
            if(p->data>p->Father->data)//���ӱȰְִ�,��Ϊ�Һ���
                p->Father->Rchild=NULL;
            else
                p->Father->Lchild=NULL;
            free(p);
        }
        else if(p->Rchild==NULL&&p->Lchild!=NULL)//ֻ����ڵ�
        {
            if(p->data>p->Father->data)//���ӱȰְִ�,��pΪ�Һ���
                p->Father->Rchild=p->Lchild;
            else
                p->Father->Lchild=p->Lchild;
            free(p);
        }
        else if(p->Lchild==NULL&&p->Rchild!=NULL)//ֻ���ҽڵ�
        {
            if(p->data>p->Father->data)//���ӱȰְִ�,��Ϊ�Һ���
                p->Father->Rchild=p->Rchild;
            else
                p->Father->Lchild=p->Rchild;
            free(p);
        }
        else//��������
        {
            s=p->Lchild;
            while(s->Rchild!=NULL)
                s=s->Rchild;
            if(s->Lchild==NULL)
            {
                s->Father->Rchild=NULL;
                p->data=s->data;
                free(s);
            }
            else
            {
                s->Father->Rchild=s->Lchild;
                p->data=s->data;
                free(s);
            }
        }
        tree->num--;
        puts("ɾ���ɹ�!");
        system("pause");
        return 0;
    }
    puts("����û���ҵ���Ԫ��!");
    system("pause");
    return 0;
}

int recursionTree(Node *tree)//�ݹ������ģ��
{
    if(tree==NULL)
        return 0;
    printf("%d,",tree->data);
    recursionTree(tree->Lchild);
    recursionTree(tree->Rchild);
}

int AVIBSTREE(void)
{
    //system("pause");//�����õ�
    void BSTreeMenu(void);//�����˵�ģ��
    AVI *tree=(AVI *)(malloc(sizeof(AVI)));
    initTree(tree);
    while(1)//������ѭ��
    {
        system("cls");//����
        BSTreeMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
            {
                case '0':free(tree);return 0;
                case '1':addTree(tree);break;
                case '2':seachTree(tree);break;
                case '3':deleteTree(tree);break;
                case '4':throughTree(tree);break;
                default :continue;
            }
            break;
        }
    }
}