#include"head.h"
void main(void)
{
    while(1)//������ѭ��
    {
        system("cls");//����
        MainMenu();//����ģ��
        while(2)//����������ֻ��������ڵ�ֵ���ܼ���
        {
            switch (getch())//getch�Ƿǻ�������
            {
                case '0':exit(0);
                case '1':SEQLIST();break;
                case '2':LINKLIST();break;
                case '3':SEQSTACK();break;
                case '4':LINKSTACK();break;
                case '5':SEQQUEUE();break;
                case '6':LINKQUEUE();break;
                case '7':STRING();break;
                case '8':AVIBSTREE();break;
                case '9':HASHTABLE();break;
                case 'k':SORT();break;
                default :continue;
            }
            break;
        }
    }
}


void MainMenu(void)//�˵�ģ��
{
    puts("\n\n");
    puts("\t\t\t������������������������������������������������������������");
    color(4);//�޸�����Ϊ��ɫ
    puts("\t\t\t�� ����������ͬ������,�Ͻ����� ��");
    color(7);//�޸�����Ϊ��ɫ
    puts("\t\t\t������������������������������������������������������������");
    puts("\t\t\t��         0���˳��˵�        ��");
    puts("\t\t\t��         1��˳ �� ��        ��");
    puts("\t\t\t��         2����    ��        ��");
    puts("\t\t\t��         3��˳ �� ջ        ��");
    puts("\t\t\t��         4����    ջ        ��");
    puts("\t\t\t��         5��˳�����        ��");
    puts("\t\t\t��         6����ʽ����        ��");
    puts("\t\t\t��         7��   ��           ��");
    puts("\t\t\t��         8���� �� ��        ��");
    puts("\t\t\t��         9���� ϣ ��        ��");
    puts("\t\t\t��         k����    ��        ��");
    puts("\t\t\t������������������������������������������������������������");
    printf("\t\t\t��������Ҫʹ�õ�ѡ���Ӧ������:");
}

void color(short x)	//�޸���ɫ����
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ 
    else//Ĭ�ϵ���ɫ��ɫ
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}