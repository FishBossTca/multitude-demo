#include"head.h"
#define MAXnum 100
void SORTMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��    ����������������ҳ��   ��");
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��       0���˳��˵�          ��");
    puts("\t\t\t��       1���������          ��");
    puts("\t\t\t��       2��ֱ�Ӳ�������      ��");
    puts("\t\t\t��       3��ϣ������          ��");
    puts("\t\t\t��       4��������            ��");
    puts("\t\t\t��       5���鲢����          ��");
    puts("\t\t\t��       6����������          ��");
    puts("\t\t\t��       9����ʾ����          ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

int addSort(int sort[])//�������ģ��
{
    system("cls");
    int ch=0,i=0;
    puts("����������,ÿ������֮���ÿո����,����������\"-65536\"�����س�");
    while(1)
    {
        scanf("%d",&ch);
        if(ch==-65535)
            break;
        sort[i]=ch;
        i++;
    }
    sort[i]=-65535;
    fflush(stdin);
    puts("������!");
    system("pause");
}

int showSort(int sort[])//��ʾ����ģ��
{
    system("cls");
    int i=0;
    puts("������Ϊ");
    while(sort[i]!=-65535)
    {
        printf("%d,",sort[i]);
        if(i%10==0&&i!=0)
            printf("\n");
        i++;
    }
    printf("����%d��Ԫ��",i);
    system("pause");
}

int count(int sort[])//����Ԫ�ؼ���ģ��
{
    int i=0;
    while(sort[i]!=-65535)
        i++;
    return i;
}
// 
//
//        ������       ������
//    �������� �ة��������������� �ة�����
//    ��                 ��
//    ��       ������       ��
//    ��  ���Щ�       ���Щ�  ��
//    ��                 ��
//    ��       ���ة�       ��
//    ��                 ��
//    ����������         ����������
//        ��         ��
//        ��         ��
//        ��         ��
//        ��         ��������������������������������
//        ��                        ��
//        ��                        ������
//        ��                        ������
//        ��                        ��  ���ޱ���
//        ������  ��  �����������������Щ�����  ��������         ��������!
//        �� ���� ����       �� ���� ����
//        �������ة�����       �������ة�����
//
//        


int SORT(void)
{
    //system("pause");
    int sort[MAXnum]={-65535};
    while(1)//������ѭ��
    {
        system("cls");//����
        SORTMenu();
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
            {
                case '0':return 0;
                case '1':addSort(sort);break;
                case '2':insertSort(sort,count(sort));break;
                case '3':shellSort(sort,count(sort));break;
                case '4':heapsort(sort,count(sort));break;
                case '5':merge(sort,count(sort));break;
                case '6':QSort(sort,count(sort));break;
                case '9':showSort(sort);break;
                default :continue;
            }
            break;
        }
    }

}