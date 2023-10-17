#include"head.h"
void main(void)
{
    while(1)//封面死循环
    {
        system("cls");//清屏
        MainMenu();//封面模块
        while(2)//输入锁定，只有输入存在的值才能继续
        {
            switch (getch())//getch是非缓冲输入
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


void MainMenu(void)//菜单模块
{
    puts("\n\n");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    color(4);//修改字体为红色
    puts("\t\t\t※ 本程序由虞同赐制作,严禁盗用 ※");
    color(7);//修改字体为白色
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("\t\t\t█         0、退出菜单        █");
    puts("\t\t\t█         1、顺 序 表        █");
    puts("\t\t\t█         2、链    表        █");
    puts("\t\t\t█         3、顺 序 栈        █");
    puts("\t\t\t█         4、链    栈        █");
    puts("\t\t\t█         5、顺序队列        █");
    puts("\t\t\t█         6、链式队列        █");
    puts("\t\t\t█         7、   串           █");
    puts("\t\t\t█         8、二 叉 树        █");
    puts("\t\t\t█         9、哈 希 表        █");
    puts("\t\t\t█         k、排    序        █");
    puts("\t\t\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    printf("\t\t\t请输入需要使用的选项对应的数字:");
}

void color(short x)	//修改颜色函数
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
    else//默认的颜色白色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}