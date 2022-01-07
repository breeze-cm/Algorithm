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

void merge(int[], int, int, int);//�鲢��������ϲ���������
void mergesort(int[], int, int);//�鲢������������������

//�鲢������
void mergeSort()
{
    int i, a1[N];
    double t1, t2, t3, t4;

    for (i = 0; i < N; i++)
    {
        a1[i] = rand() % N;
    }


    //�鲢����N������������õ�ʱ��
    t2 = clock();
    mergesort(a1, 0, N - 1);
    t2 = clock() - t2;

    /*�ź���Ľ��*/
    for (i = 0; i < N - 1; i++)
    {
        printf("%4d ", a1[i]);
    }

    printf("\n�鲢����%d�������������ʱ��Ϊ:%f����\n", N, (double)t2);
    getch();
    //return 0;
}



//�鲢����
//�鲢����ϲ����麯���ľ���ʵ��
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

//�鲢�������ľ���ʵ��
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

    //��ӡ����������
    for (i = 0; i < N; i++)
    {
        printf("%4d ", a[i]);
    }
    printf("\nð������%d�������������ʱ��Ϊ:%f����\n", N, (double)t2);
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
    while (i != j)/*�ҵ�����λ��*/
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
    quickSort(a, left, i - 1);/*�ݹ����*/
    quickSort(a, i + 1, right);/*�ݹ��ұ�*/
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
    /*�ź���Ľ��*/
    for (i = 0; i < N - 1; i++)
    {
        printf("%4d ", a[i]);
    }

    printf("\n��������%d�������������ʱ��Ϊ:%f����\n", N, (double)t2);
    getch();
    
}


//����PointX��PointY��ʾ��x�����y�����ź���ĵ�
class PointX {
public:
	int operator<=(PointX a)const
	{
		return (x <= a.x);
	}
	int ID; //����
	float x, y; //������ 
};

class PointY {
public:
	int operator<=(PointY a)const
	{
		return(y <= a.y);
	}
	int p; //ͬһ��������x�е����� 
	float x, y; //������
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

	cout << "������������";
	cin >> length;

	PointX X[M];
	cout << "������ɵĶ�ά���Ϊ��" << endl;

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
	cout << "���ڽ����Ϊ��(" << a.x << "," << a.y << ")��(" << b.x << "," << b.y << ") " << endl;
	cout << "���ڽ�����Ϊ�� " << d << endl;

	//return 0;
}

float Random()
{
	float result = rand() % 10000;
	return result * 0.01;
}

//ƽ������������u��v֮��ľ���ɼ�������
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
	for (int i = 0; i < n; i++) //������X�еĵ㸴�Ƶ�����Y��
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
	if (r - l == 1) //��������� 
	{
		a = X[l];
		b = X[r];
		d = dis(X[l], X[r]);
		return;
	}

	if (r - l == 2) //3������� 
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

	//����3������Σ��÷��η� 
	int m = (l + r) / 2;
	int f = l, g = m + 1;

	//���㷨Ԥ����׶Σ�������X�еĵ���x�������򣬽�����Y�еĵ���y��������
	//��������X[l:r]���Ȼ��ֳ��������뽻���Ӽ���ȡm=(l+r)/2
	//X[l:m]��X[m+1:r]��������Ҫ��ķָ
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

	Merge(Z, Y, l, m, r);//�ع�����Y

	//d�������ڵĵ�����Z��
	int k = l;
	for (int i = l; i <= r; i++)
	{
		if (fabs(X[m].x - Y[i].x) < d)
		{
			Z[k++] = Y[i];
		}
	}

	//����Z[l:k-1]
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
		Merge(a, b, left, i, right);//�ϲ�������b
		Copy(a, b, left, right);//���ƻ�����a		
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
		printf("��ѡ��1 �鲢���� 2 ð������3 ��������4 ��Ե㣻");
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