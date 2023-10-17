#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MAXnum 100
int count(int sort[]);//声明数组元素计数模块
void insertSort(int sort[],int length);//声明直接插入排序(顺序)
void shellSort(int sort[],int length);//声明希尔排序(顺序)
void heapsort(int sort[],int length);//声明堆排序(大根堆)
void merge(int sort[],int length);//声明归并排序(顺序)
void QSort(int sort[],int length);//声明快速排序模块(顺序)