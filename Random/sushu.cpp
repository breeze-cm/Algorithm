#include<stdio.h>
#include<iostream>
#include<math.h>
#include   <stdlib.h>
#include<time.h>
using namespace std;
#define MIN 1    //����������ķ�Χ      
#define MAX 10000000  

bool judgeprime(int i) 
{
	int j;
	for (j = 2; j <= sqrt(i); j++)
		if (i % j == 0)
			break;
	if (j > sqrt(i))
		return true;
}

int Rad(int c) //�������һ���������������⣩
{
	srand((unsigned)time(NULL));
	while (1) {
		
		if (judgeprime(c)) {
			//cout << c << endl;
			break;
		}
		else
			continue;
	}
	return c;
}

//����a^p mod n,��ʵʩ��n�Ķ���̽��
void power(unsigned int a,unsigned int p,unsigned int n,unsigned int &result,bool &composite)
{
	unsigned int x;
	if(p == 0)
	{
		result = 1;
	}
	else
	{
		power(a,p/2,n,x,composite);		//�ݹ����
		result = (x*x)%n;				//����̽��
 
		if((result == 1) && (x!=1) && (x!=n-1))
		{
			composite  = true;
		}
 
		if((p%2)==1)                   //p������
		{
			result = (result*a)%n;
		}
	}
}
 
bool PrimeMC(unsigned int n,unsigned int k) //�ظ�����k��Prime�㷨�����ؿ����㷨  
{                                 
	unsigned int a,result;
	bool composite = false;
    if(n/2==0)
    return false;
    srand(time(NULL));
	for(int i=1; i<=k; i++)
	{
        a=rand()%(n-3)+2;
		power(a,n-1,n,result,composite);
		if(composite || (result!=1))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	while (1)
	{
		int c = MIN + (rand() % (MAX - MIN));;
		int k = 10;
		int N;
		Rad(c);
		int num;
		cout << "1���ֶ�" << endl << "2���Զ�" << endl;
		cin >> num;
		switch (num)
		{
			case 1:
				cout << "������һ������";
				cin >> N;
					break;
			case 2:
				cout << "�Զ�����һ������";
					N = Rad(c);
					cout << N << endl;;
					break;
		}
		printf("the result of the PrimeNumber is:%d\n", PrimeMC(N, k));
		cout << endl;	
	}
	return 0;
}

