#include"head.h"
typedef struct BinarySearchTree//定义二叉树节点
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

int checkBalance(Node *node,AVI *tree);//声明检查二叉树是否平衡模块
Node *SEACHPosition(Node *tree,int seachData);//声明查找元素位置子函数

void BSTreeMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※   您现在在二叉查找树页面  ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、添加数据        █");
    puts("\t\t\t█         2、查找数据        █");
    puts("\t\t\t█         3、删除数据        █");
    puts("\t\t\t█         4、查看数据        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

void initTree(AVI *tree)//初始化二叉树模块
{
    tree->num=0;
    tree->root=NULL;
}

int addTree(AVI *tree)//添加元素模块
{
    system("cls");
    int newdate;
    Node *p,*newnode=(Node *)malloc(sizeof(Node));
    newnode->Lchild=NULL;newnode->Rchild=NULL;newnode->BF=0;
    p=tree->root;
    puts("请输入添加的元素");
    scanf("%d",&newdate);
    fflush(stdin);
    if(tree->num==0)//首次添加根节点
    {
        newnode->data=newdate;
        tree->root=newnode;
        newnode->Father=NULL;
        tree->num++;
        puts("添加成功!");
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
                puts("添加完成!(左)");
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
                puts("添加完成!(右)");
                checkBalance(newnode,tree);
                system("pause");
                return 0;
            }
            p=p->Rchild;
        }
        else
        {
            puts("已经存在相同节点,添加失败!");
            system("pause");
            return 0;
        }
    }
}

int checkBalance(Node *node,AVI *tree)//检查二叉树是否平衡
{
    int RotateLL(Node *node,AVI *tree);//声明右旋
    int RotateRR(Node *node,AVI *tree);//声明左旋
    int RotateLR(Node *node,AVI *tree);//声明先左后右旋
    int RotateRL(Node *node,AVI *tree);//声明先右后左旋
    while(node->Father!=NULL)
    {
        if(node==node->Father->Lchild)//是父亲的左孩
            node->Father->BF++;
        else
            node->Father->BF--;
        if(node->Father->BF==0)//不会对上层有影响
            return 0;
        else if(abs(node->Father->BF)==1)//父亲的平衡因子绝对值=1,向祖辈查找(祖辈可能有影响
            node=node->Father;
        else if(abs(node->Father->BF)>1)//绝对值>1,需要平衡操作
        {
            if(node->Father->BF>1)//左边高
            {
                if(node->BF==1)//插入位置为LL
                    RotateLL(node,tree);//直接右旋
                else
                    RotateLR(node,tree);//左右旋
                return 0;
            }
            else//右边高
            {
                if(node->BF==-1)//插入位置为RR
                    RotateRR(node,tree);//直接左旋
                else
                    RotateRL(node,tree);//右左旋
                return 0;
            }
        }
    }
}

int RotateLL(Node *node,AVI *tree)//右旋
{
    node->BF=0;node->Father->BF=0;
    if(node->Lchild!=NULL)
        node->Lchild->BF=0;
    /* 这个三选一是用来判断爷爷的状况,是左儿子还是右儿子,或者是空爷爷(爸爸是根) */
    if(node->Father->Father==NULL)//调整后到达根节点,则要重新调整根节点指针指向
        tree->root=node;
    else if(node->Father->Father->Lchild==node->Father)//判断父亲节点是否为爷爷的左节点
        node->Father->Father->Lchild=node;//为了让祖先节点能找到子孙
    else
        node->Father->Father->Rchild=node;
    node->Father->Lchild=node->Rchild;//LL型调整
    node->Rchild=node->Father;
    /* 调整新父亲,这里建议画双向图理解，比较麻烦,顺序不能换 */
    node->Father=node->Rchild->Father;
        node->Rchild->Father=node;
    if(node->Rchild->Lchild!=NULL)//空指针的话没有父亲
        node->Rchild->Lchild->Father=node->Rchild;
}

int RotateRR(Node *node,AVI *tree)//左旋
{
    node->BF=0;node->Father->BF=0;
    if(node->Rchild!=NULL)
        node->Rchild->BF=0;
    /* 这个三选一是用来判断爷爷的状况,是左儿子还是右儿子,或者是空爷爷(爸爸是根) */
    if(node->Father->Father==NULL)//调整后到达根节点,则要重新调整根节点指针指向
        tree->root=node;
    else if(node->Father==node->Father->Father->Lchild)//判断父亲节点是否为爷爷的左节点
        node->Father->Father->Lchild=node;//为了让祖先节点能找到子孙
    else
        node->Father->Father->Rchild=node;
    node->Father->Rchild=node->Lchild;//RR型调整
    node->Lchild=node->Father;
    /* 调整新父亲 */
    node->Father=node->Lchild->Father;
    node->Lchild->Father=node;
    if(node->Lchild->Rchild!=NULL)//空指针的话没有父亲
        node->Lchild->Rchild->Father=node->Lchild;
}

int RotateLR(Node *node,AVI *tree)//先左后右旋
{
    Node *p=node->Rchild;
    int RotateLL(Node *node,AVI *tree);//声明右旋
    int RotateRR(Node *node,AVI *tree);//声明左旋
    RotateRR(node->Rchild,tree);
    RotateLL(p,tree);
}

int RotateRL(Node *node,AVI *tree)//先右后左旋
{
    Node *p=node->Lchild;
    int RotateLL(Node *node,AVI *tree);//声明右旋
    int RotateRR(Node *node,AVI *tree);//声明左旋
    RotateLL(node->Lchild,tree);
    RotateRR(p,tree);
}

int seachTree(AVI *tree)//查找树模块
{
    system("cls");
    int seachData;
    Node *p=tree->root;
    puts("请输入需要查找的数值");
    scanf("%d",&seachData);
    fflush(stdin);
    if((p=SEACHPosition(p,seachData))!=NULL)
    {
        puts("找到了!");
        system("pause");
        return 0;
    }
    puts("抱歉，没找到!");
    system("pause");
    return 0;
}

Node *SEACHPosition(Node *tree,int seachData)//查找元素位置子函数
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

int throughTree(AVI *tree)//遍历元素模块
{
    int recursionTree(Node *tree);//声明递归遍历子模块
    system("cls");
    if(tree->num==0)
    {
        puts("抱歉,没有元素可以遍历!");
        system("pause");
        return 0;
    }
    printf("该树元素为:");
    recursionTree(tree->root);
    printf("共有%d个元素",tree->num);
    putchar('\n');
    system("pause");
    return 0;
}

int deleteTree(AVI *tree)//删除树元素模块
{
    system("cls");
    int deleteData;
    Node *p=tree->root,*s,*q;
    puts("请输入需要删除的元素");
    scanf("%d",&deleteData);
    fflush(stdin);
    if((p=SEACHPosition(p,deleteData))!=NULL)
    {
        if(p->Lchild==NULL&&p->Rchild==NULL)//是叶子节点,没有孩子
        {
            if(p->data>p->Father->data)//孩子比爸爸大,则为右孩子
                p->Father->Rchild=NULL;
            else
                p->Father->Lchild=NULL;
            free(p);
        }
        else if(p->Rchild==NULL&&p->Lchild!=NULL)//只有左节点
        {
            if(p->data>p->Father->data)//孩子比爸爸大,则p为右孩子
                p->Father->Rchild=p->Lchild;
            else
                p->Father->Lchild=p->Lchild;
            free(p);
        }
        else if(p->Lchild==NULL&&p->Rchild!=NULL)//只有右节点
        {
            if(p->data>p->Father->data)//孩子比爸爸大,则为右孩子
                p->Father->Rchild=p->Rchild;
            else
                p->Father->Lchild=p->Rchild;
            free(p);
        }
        else//两个都有
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
        puts("删除成功!");
        system("pause");
        return 0;
    }
    puts("错误，没有找到该元素!");
    system("pause");
    return 0;
}

int recursionTree(Node *tree)//递归遍历子模块
{
    if(tree==NULL)
        return 0;
    printf("%d,",tree->data);
    recursionTree(tree->Lchild);
    recursionTree(tree->Rchild);
}

int AVIBSTREE(void)
{
    //system("pause");//调试用的
    void BSTreeMenu(void);//声明菜单模块
    AVI *tree=(AVI *)(malloc(sizeof(AVI)));
    initTree(tree);
    while(1)//封面死循环
    {
        system("cls");//清屏
        BSTreeMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
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