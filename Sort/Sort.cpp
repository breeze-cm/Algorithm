//#include "StdAfx.h"
#include"stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<iostream> 
#include<cmath>
#define N 100000


using namespace std;
const int M = 50;

void merge(int[], int, int, int);//归并排序数组合并函数声明
void mergesort(int[], int, int);//归并排序数组排序函数声明

//归并主函数
void mergeSort()
{
    int i, a1[N];
    double t1, t2, t3, t4;

    for (i = 0; i < N; i++)
    {
        a1[i] = rand() % N;
    }


    //归并排序N个随机数字所用的时间
    t2 = clock();
    mergesort(a1, 0, N - 1);
    t2 = clock() - t2;

    /*排好序的结果*/
    for (i = 0; i < N - 1; i++)
    {
        printf("%4d ", a1[i]);
    }

    printf("\n归并排序%d个随机数字所用时间为:%f毫秒\n", N, (double)t2);
    getch();
    //return 0;
}



//归并排序
//归并排序合并数组函数的具体实现
void merge(int a[], int low, int middle, int high)
{
    int h, i, j, k;
    int b[N];
    h = low;
    i = low;
    j = middle + 1;

    while (h <= middle && j <= high)
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > middle)
        for (k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    else
    {
        for (k = h; k <= middle; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

//归并排序函数的具体实现
void mergesort(int a[], int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = (low + high) / 2;
        mergesort(a, low, middle);
        mergesort(a, middle + 1, high);
        merge(a, low, middle, high);
    }
}

void maopao()
{
    double t2 = clock();
    int i, j, a[N];
    int flag = 1;
    int temp;
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % N;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    t2 = clock() - t2;

    //打印排序后的数组
    for (i = 0; i < N; i++)
    {
        printf("%4d ", a[i]);
    }
    printf("\n冒泡排序%d个随机数字所用时间为:%f毫秒\n", N, (double)t2);
    getch();
    //return 0;
}

void quickSort(int a[], int left, int right)
{
    int i, j, temp;
    i = left;
    j = right;
    temp = a[left];
    if (left > right)
        return;
    while (i != j)/*找到最终位置*/
    {
        while (a[j] >= temp && j > i)
            j--;
        if (j > i)
            a[i++] = a[j];
        while (a[i] <= temp && j > i)
            i++;
        if (j > i)
            a[j--] = a[i];

    }
    a[i] = temp;
    quickSort(a, left, i - 1);/*递归左边*/
    quickSort(a, i + 1, right);/*递归右边*/
}

void kuaisu()
{
    double t2 = clock();
    int i, a[N];
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % N;
    }

    quickSort(a, 0, N - 1);
    t2 = clock() - t2;
    /*排好序的结果*/
    for (i = 0; i < N - 1; i++)
    {
        printf("%4d ", a[i]);
    }

    printf("\n快速排序%d个随机数字所用时间为:%f毫秒\n", N, (double)t2);
    getch();
    
}


//用类PointX和PointY表示依x坐标和y坐标排好序的点
class PointX {
public:
	int operator<=(PointX a)const
	{
		return (x <= a.x);
	}
	int ID; //点编号
	float x, y; //点坐标 
};

class PointY {
public:
	int operator<=(PointY a)const
	{
		return(y <= a.y);
	}
	int p; //同一点在数组x中的坐标 
	float x, y; //点坐标
};

float Random();
template <class Type>
float dis(const Type& u, const Type& v);

bool Cpair2(PointX X[], int n, PointX& a, PointX& b, float& d);
void closest(PointX X[], PointY Y[], PointY Z[], int l, int r, PointX& a, PointX& b, float& d);

template <typename Type>
void Copy(Type a[], Type b[], int left, int right);

template <class Type>
void Merge(Type c[], Type d[], int l, int m, int r);

template <class Type>
void MergeSort(Type a[], Type b[], int left, int right);

void ptop()
{
	srand((unsigned)time(NULL));
	int length;

	cout << "请输入点对数：";
	cin >> length;

	PointX X[M];
	cout << "随机生成的二维点对为：" << endl;

	for (int i = 0; i < length; i++)
	{
		X[i].ID = i;
		X[i].x = Random();
		X[i].y = Random();
		cout << "(" << X[i].x << "," << X[i].y << ") ";
	}

	PointX a;
	PointX b;
	float d;

	Cpair2(X, length, a, b, d);

	cout << endl;
	cout << "最邻近点对为：(" << a.x << "," << a.y << ")和(" << b.x << "," << b.y << ") " << endl;
	cout << "最邻近距离为： " << d << endl;

	//return 0;
}

float Random()
{
	float result = rand() % 10000;
	return result * 0.01;
}

//平面上任意两点u和v之间的距离可计算如下
template <class Type>
inline float dis(const Type& u, const Type& v)
{
	float dx = u.x - v.x;
	float dy = u.y - v.y;
	return sqrt(dx * dx + dy * dy);
}

bool Cpair2(PointX X[], int n, PointX& a, PointX& b, float& d)
{
	if (n < 2) return false;

	PointX* tmpX = new PointX[n];
	MergeSort(X, tmpX, 0, n - 1);

	PointY* Y = new PointY[n];
	for (int i = 0; i < n; i++) //将数组X中的点复制到数组Y中
	{
		Y[i].p = i;
		Y[i].x = X[i].x;
		Y[i].y = X[i].y;
	}

	PointY* tmpY = new PointY[n];
	MergeSort(Y, tmpY, 0, n - 1);

	PointY* Z = new PointY[n];
	closest(X, Y, Z, 0, n - 1, a, b, d);

	delete[]Y;
	delete[]Z;
	delete[]tmpX;
	delete[]tmpY;
	return true;
}
void closest(PointX X[], PointY Y[], PointY Z[], int l, int r, PointX& a, PointX& b, float& d)
{
	if (r - l == 1) //两点的情形 
	{
		a = X[l];
		b = X[r];
		d = dis(X[l], X[r]);
		return;
	}

	if (r - l == 2) //3点的情形 
	{
		float d1 = dis(X[l], X[l + 1]);
		float d2 = dis(X[l + 1], X[r]);
		float d3 = dis(X[l], X[r]);

		if (d1 <= d2 && d1 <= d3)
		{
			a = X[l];
			b = X[l + 1];
			d = d1;
			return;
		}

		if (d2 <= d3)
		{
			a = X[l + 1];
			b = X[r];
			d = d2;
		}
		else {
			a = X[l];
			b = X[r];
			d = d3;
		}
		return;
	}

	//多于3点的情形，用分治法 
	int m = (l + r) / 2;
	int f = l, g = m + 1;

	//在算法预处理阶段，将数组X中的点依x坐标排序，将数组Y中的点依y坐标排序
	//将子数组X[l:r]均匀划分成两个不想交的子集，取m=(l+r)/2
	//X[l:m]和X[m+1:r]就是满足要求的分割。
	for (int i = l; i <= r; i++)
	{
		if (Y[i].p > m) Z[g++] = Y[i];
		else Z[f++] = Y[i];
	}

	closest(X, Z, Y, l, m, a, b, d);
	float dr;

	PointX ar, br;
	closest(X, Z, Y, m + 1, r, ar, br, dr);

	if (dr < d)
	{
		a = ar;
		b = br;
		d = dr;
	}

	Merge(Z, Y, l, m, r);//重构数组Y

	//d矩形条内的点置于Z中
	int k = l;
	for (int i = l; i <= r; i++)
	{
		if (fabs(X[m].x - Y[i].x) < d)
		{
			Z[k++] = Y[i];
		}
	}

	//搜索Z[l:k-1]
	for (int i = l; i < k; i++)
	{
		for (int j = i + 1; j < k && Z[j].y - Z[i].y < d; j++)
		{
			float dp = dis(Z[i], Z[j]);
			if (dp < d)
			{
				d = dp;
				a = X[Z[i].p];
				b = X[Z[j].p];
			}
		}
	}
}

template <class Type>
void Merge(Type c[], Type d[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	while ((i <= m) && (j <= r))
	{
		if (c[i] <= c[j])
		{
			d[k++] = c[i++];
		}
		else
		{
			d[k++] = c[j++];
		}
	}

	if (i > m)
	{
		for (int q = j; q <= r; q++)
		{
			d[k++] = c[q];
		}
	}
	else
	{
		for (int q = i; q <= m; q++)
		{
			d[k++] = c[q];
		}
	}
}

template <class Type>
void MergeSort(Type a[], Type b[], int left, int right)
{
	if (left < right)
	{
		int i = (left + right) / 2;
		MergeSort(a, b, left, i);
		MergeSort(a, b, i + 1, right);
		Merge(a, b, left, i, right);//合并到数组b
		Copy(a, b, left, right);//复制回数组a		
	}
}

template <typename Type>
void Copy(Type a[], Type b[], int left, int right)
{
	for (int i = left; i <= right; i++)
		a[i] = b[i];
}


int main()
{
    while (1)
    {
        int x;
		printf("请选择：1 归并排序； 2 冒泡排序；3 快速排序；4 点对点；");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            mergeSort();
            break;
        case 2:
            maopao();
            break;
        case 3:
            kuaisu();
            break;
		case 4:
			ptop();
			break;
        }
    }
}