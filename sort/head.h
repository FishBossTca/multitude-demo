#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MAXnum 100
int count(int sort[]);//��������Ԫ�ؼ���ģ��
void insertSort(int sort[],int length);//����ֱ�Ӳ�������(˳��)
void shellSort(int sort[],int length);//����ϣ������(˳��)
void heapsort(int sort[],int length);//����������(�����)
void merge(int sort[],int length);//�����鲢����(˳��)
void QSort(int sort[],int length);//������������ģ��(˳��)