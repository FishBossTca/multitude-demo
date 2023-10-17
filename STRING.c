#include"head.h"
#define MAXLEN 10086
int Slong;//串的长度
void Next(char string[],int *next);//声明next数组的计算
int locateString(char *string,char *compareString,int pos);//声明定位串位置
void throughString(char *string);//声明查看主串模块
void reSortString(char *string,int startPosition,int backLong);//声明重新排序子模块
void StringMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t※     您现在在字符串页面    ※");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、新建主串        █");
    puts("\t\t\t█         2、修改子串        █");
    puts("\t\t\t█         3、添加子串        █");
    puts("\t\t\t█         4、定位子串        █");
    puts("\t\t\t█         5、查看主串        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

int addString(char *string)//添加主串模块
{
    system("cls");
    char String[MAXLEN];
    puts("请输入需要添加的串(取消添加请只输入\":q\")");
    if(strcmp(gets(String),":q")==0)
        return 0;
    strcpy(string,String);
    Slong=strlen(string);
    puts("添加完成!");
    system("pause");
}

int seemString(char *string)//查询子串模块
{
    char temp[MAXLEN];
    system("cls");
    puts("请输入需要查找在子串");
    gets(temp);
    int position=locateString(string,temp,0);
    if(position==-1)
    {
        puts("错误，没有找到该子串!");
        system("pause");
        return 0;
    }
    else
    {
        printf("该子串位置在主串的第%d个字符处\n",position);
        system("pause");
    }
}

int replaceString(char *string)//修改子串模块
{
    system("cls");
    int n=0,i,backLong=0,deleteLong,headPosition,taliPosition;
    char temp[MAXLEN];
    puts("请输入需要在主串中修改的子串");
    gets(temp);
    char replace[strlen(temp)];
    if((n=locateString(string,temp,n))==-1)
    {
        puts("错误。没有找到相应子串");
        system("pause");
        return 0;
    }
    puts("将此替换为:(取消修改请只输入\":q\",删除请直接按回车)");
    gets(replace);
    if(strcmp(replace,":q")==0)
        return 0;
    backLong=Slong-n-2;//计算插入位置后面串的长度,要-2的原因未知
    deleteLong=strlen(replace)-strlen(temp);//计算要移动多少字符,后来的字符长度-原来的字符长度就是需要移动的字符长度(正号往后移，负号往前移)
    n=0;
    /* 可以改为递归修改 */
    while((n=locateString(string,temp,n))!=-1)//循环在原有位置继续向后查找是否还存在相同字符串
    {
        if(deleteLong<0)//替换的子串比原来的短
        {
            headPosition=n+strlen(temp)-1;//计算要移动的字符的头位置
            /* 
            看键盘位置:Z X C V B N M 
            当前位置要替换的位置是C,把"CVB"替换成"*",C的位置+"CVB"的长度(为3,往后再数三格)=N的位置(N为要移动头字符),要减一是因为数组第一位是0号位
            */
            for(i=0;i<backLong;++i)//移动后面的串
                string[headPosition+i+deleteLong]=string[headPosition+i];//这里的deleteLong一定是小于0的，所以往前移deleteLong个位置
            string[Slong+deleteLong]='\0';//移动完后记得补\0,"Slong"是原本\0的位置
            for(i=0;i<strlen(replace);i++)//替换模块
                string[n-1+i]=replace[i];
        }    
        else//替换的子串比原来的长
        {
            taliPosition=Slong-1;//计算要移动的字符的尾位置
            /* 
            看键盘位置:Z X C V B N M 
            当前位置要替换的位置是C,把"CVB"替换成"****",C的位置+"CVB"的长度=N的位置(这里的数组位置是N+1)，所以在数组中的位置就已经在M的位置了
            N的位置+backLong(自长)="M"的位置(M为要移动尾字符)
            */
            for(i=0;i<backLong;i++)//移动后面的串
                string[taliPosition-i+deleteLong]=string[taliPosition-i];//这里的deleteLong一定是大于0的，所以往后移deleteLong个位置
            string[taliPosition+deleteLong+1]='\0';//移动完后记得补\0,"taliPosition"是原本\0的位置
            for(i=0;i<strlen(replace);i++)//替换模块
                string[n-1+i]=replace[i];
        }
    n+=strlen(replace)-1;//往后移动replace，以免重复扫描已经替换的部分,要-1，不然替换不完全BUG
    }
    Slong=strlen(string);//重新计算后来串长度
    puts("替换成功!");
    system("pause");
}
int addchildString(char *string)//添加子串模块
{
    system("cls");
    char temp[MAXLEN],insert[MAXLEN];
    int i,n=0,N,backLong=0;
    puts("请输入被插入的子串");
    gets(temp);
    if((n=locateString(string,temp,n))==-1)
    {
        puts("错误。没有找到相应子串");
        system("pause");
        return 0;
    }
    puts("请输入需要插入的子串");
    gets(insert);
    backLong=Slong-n;//计算插入位置后面串的长度-2原因未知
    for(i=0;i<backLong;i++)//移动后面串来腾空位置插入
        string[Slong-1+strlen(insert)-i]=string[Slong-1-i];
    string[Slong+strlen(insert)]='\0';
    for(i=0;i<strlen(insert);++i)//插入串
        string[n-1+strlen(temp)+i]=insert[i];
    Slong=strlen(string);
    puts("插入成功!");
    system("pause");
}

int locateString(char *string,char *compareString,int pos)//定位串位置
{
    int j=0;
    int next[MAXLEN];
    Next(compareString,next);
    while(pos<strlen(string))
    {
        if(string[pos]==compareString[j])
        {
            if(j==strlen(compareString)-1)
               return pos-strlen(compareString+2);
            j++;
        }
        else
        {
            if(j==0)
                j++;
            else
            {
                j=next[j-1];
                continue;
            }
        }
    pos++;
    }
    return -1;
}

void Next(char string[],int *next)//next数组的计算,尝试改成递归算法
{
    int head=0,tail=1;
    next[0]=0;
    while(tail<=strlen(string))
    {
        if(string[head]==string[tail])//遇到相同的字符
        {
            next[tail]=next[tail-1]+1;//当前位置(指tail)的next数值为前一个数值+1
            head++;//相等,head和tail指针都后移
        }
        else
        {
            if(head==0)//head为0时没有前驱,单独出来
                next[tail]=0;
            else
            {
                if(string[next[head-1]]==string[tail])//先找到head指针的前一位的next数值,并用该数值对应的string位置和tail的比较
                {
                    next[tail]=next[head-1]+1;//相同,则为head的前一位+1
                    head++;//相等,head和tail指针都后移
                }
                else
                    next[tail]=0;
                head=0;//重新开始匹配
            }
        }
    tail++;
    }
}

void throughString(char *string)//查看主串模块
{
    system("cls");
    printf("%s\n该字符串长度为:%d",string,Slong);
    system("pause");
}
int STRING(void)
{
    //system("pause");//调试用的
    char *string=(char *)malloc(sizeof(char[MAXLEN]));
    while(1)//封面死循环
    {
        system("cls");//清屏
        StringMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
            {
                case '0':free(string);return 0;
                case '1':addString(string);break;
                case '2':replaceString(string);break;
                case '3':addchildString(string);break;
                case '4':seemString(string);break;
                case '5':throughString(string);break;
                default :continue;
            }
            break;
        }
        
    }
}