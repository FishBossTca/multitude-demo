#include"head.h"
#define MAXLEN 10086
int Slong;//���ĳ���
void Next(char string[],int *next);//����next����ļ���
int locateString(char *string,char *compareString,int pos);//������λ��λ��
void throughString(char *string);//�����鿴����ģ��
void reSortString(char *string,int startPosition,int backLong);//��������������ģ��
void StringMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��     ���������ַ���ҳ��    ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1���½�����        ��");
    puts("\t\t\t��         2���޸��Ӵ�        ��");
    puts("\t\t\t��         3������Ӵ�        ��");
    puts("\t\t\t��         4����λ�Ӵ�        ��");
    puts("\t\t\t��         5���鿴����        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

int addString(char *string)//�������ģ��
{
    system("cls");
    char String[MAXLEN];
    puts("��������Ҫ��ӵĴ�(ȡ�������ֻ����\":q\")");
    if(strcmp(gets(String),":q")==0)
        return 0;
    strcpy(string,String);
    Slong=strlen(string);
    puts("������!");
    system("pause");
}

int seemString(char *string)//��ѯ�Ӵ�ģ��
{
    char temp[MAXLEN];
    system("cls");
    puts("��������Ҫ�������Ӵ�");
    gets(temp);
    int position=locateString(string,temp,0);
    if(position==-1)
    {
        puts("����û���ҵ����Ӵ�!");
        system("pause");
        return 0;
    }
    else
    {
        printf("���Ӵ�λ���������ĵ�%d���ַ���\n",position);
        system("pause");
    }
}

int replaceString(char *string)//�޸��Ӵ�ģ��
{
    system("cls");
    int n=0,i,backLong=0,deleteLong,headPosition,taliPosition;
    char temp[MAXLEN];
    puts("��������Ҫ���������޸ĵ��Ӵ�");
    gets(temp);
    char replace[strlen(temp)];
    if((n=locateString(string,temp,n))==-1)
    {
        puts("����û���ҵ���Ӧ�Ӵ�");
        system("pause");
        return 0;
    }
    puts("�����滻Ϊ:(ȡ���޸���ֻ����\":q\",ɾ����ֱ�Ӱ��س�)");
    gets(replace);
    if(strcmp(replace,":q")==0)
        return 0;
    backLong=Slong-n-2;//�������λ�ú��洮�ĳ���,Ҫ-2��ԭ��δ֪
    deleteLong=strlen(replace)-strlen(temp);//����Ҫ�ƶ������ַ�,�������ַ�����-ԭ�����ַ����Ⱦ�����Ҫ�ƶ����ַ�����(���������ƣ�������ǰ��)
    n=0;
    /* ���Ը�Ϊ�ݹ��޸� */
    while((n=locateString(string,temp,n))!=-1)//ѭ����ԭ��λ�ü����������Ƿ񻹴�����ͬ�ַ���
    {
        if(deleteLong<0)//�滻���Ӵ���ԭ���Ķ�
        {
            headPosition=n+strlen(temp)-1;//����Ҫ�ƶ����ַ���ͷλ��
            /* 
            ������λ��:Z X C V B N M 
            ��ǰλ��Ҫ�滻��λ����C,��"CVB"�滻��"*",C��λ��+"CVB"�ĳ���(Ϊ3,������������)=N��λ��(NΪҪ�ƶ�ͷ�ַ�),Ҫ��һ����Ϊ�����һλ��0��λ
            */
            for(i=0;i<backLong;++i)//�ƶ�����Ĵ�
                string[headPosition+i+deleteLong]=string[headPosition+i];//�����deleteLongһ����С��0�ģ�������ǰ��deleteLong��λ��
            string[Slong+deleteLong]='\0';//�ƶ����ǵò�\0,"Slong"��ԭ��\0��λ��
            for(i=0;i<strlen(replace);i++)//�滻ģ��
                string[n-1+i]=replace[i];
        }    
        else//�滻���Ӵ���ԭ���ĳ�
        {
            taliPosition=Slong-1;//����Ҫ�ƶ����ַ���βλ��
            /* 
            ������λ��:Z X C V B N M 
            ��ǰλ��Ҫ�滻��λ����C,��"CVB"�滻��"****",C��λ��+"CVB"�ĳ���=N��λ��(���������λ����N+1)�������������е�λ�þ��Ѿ���M��λ����
            N��λ��+backLong(�Գ�)="M"��λ��(MΪҪ�ƶ�β�ַ�)
            */
            for(i=0;i<backLong;i++)//�ƶ�����Ĵ�
                string[taliPosition-i+deleteLong]=string[taliPosition-i];//�����deleteLongһ���Ǵ���0�ģ�����������deleteLong��λ��
            string[taliPosition+deleteLong+1]='\0';//�ƶ����ǵò�\0,"taliPosition"��ԭ��\0��λ��
            for(i=0;i<strlen(replace);i++)//�滻ģ��
                string[n-1+i]=replace[i];
        }
    n+=strlen(replace)-1;//�����ƶ�replace�������ظ�ɨ���Ѿ��滻�Ĳ���,Ҫ-1����Ȼ�滻����ȫBUG
    }
    Slong=strlen(string);//���¼������������
    puts("�滻�ɹ�!");
    system("pause");
}
int addchildString(char *string)//����Ӵ�ģ��
{
    system("cls");
    char temp[MAXLEN],insert[MAXLEN];
    int i,n=0,N,backLong=0;
    puts("�����뱻������Ӵ�");
    gets(temp);
    if((n=locateString(string,temp,n))==-1)
    {
        puts("����û���ҵ���Ӧ�Ӵ�");
        system("pause");
        return 0;
    }
    puts("��������Ҫ������Ӵ�");
    gets(insert);
    backLong=Slong-n;//�������λ�ú��洮�ĳ���-2ԭ��δ֪
    for(i=0;i<backLong;i++)//�ƶ����洮���ڿ�λ�ò���
        string[Slong-1+strlen(insert)-i]=string[Slong-1-i];
    string[Slong+strlen(insert)]='\0';
    for(i=0;i<strlen(insert);++i)//���봮
        string[n-1+strlen(temp)+i]=insert[i];
    Slong=strlen(string);
    puts("����ɹ�!");
    system("pause");
}

int locateString(char *string,char *compareString,int pos)//��λ��λ��
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

void Next(char string[],int *next)//next����ļ���,���Ըĳɵݹ��㷨
{
    int head=0,tail=1;
    next[0]=0;
    while(tail<=strlen(string))
    {
        if(string[head]==string[tail])//������ͬ���ַ�
        {
            next[tail]=next[tail-1]+1;//��ǰλ��(ָtail)��next��ֵΪǰһ����ֵ+1
            head++;//���,head��tailָ�붼����
        }
        else
        {
            if(head==0)//headΪ0ʱû��ǰ��,��������
                next[tail]=0;
            else
            {
                if(string[next[head-1]]==string[tail])//���ҵ�headָ���ǰһλ��next��ֵ,���ø���ֵ��Ӧ��stringλ�ú�tail�ıȽ�
                {
                    next[tail]=next[head-1]+1;//��ͬ,��Ϊhead��ǰһλ+1
                    head++;//���,head��tailָ�붼����
                }
                else
                    next[tail]=0;
                head=0;//���¿�ʼƥ��
            }
        }
    tail++;
    }
}

void throughString(char *string)//�鿴����ģ��
{
    system("cls");
    printf("%s\n���ַ�������Ϊ:%d",string,Slong);
    system("pause");
}
int STRING(void)
{
    //system("pause");//�����õ�
    char *string=(char *)malloc(sizeof(char[MAXLEN]));
    while(1)//������ѭ��
    {
        system("cls");//����
        StringMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
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