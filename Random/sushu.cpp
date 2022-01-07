#include<stdio.h>
#include<iostream>
#include<math.h>
#include   <stdlib.h>
#include<time.h>
using namespace std;
#define MIN 1    //随机数产生的范围      
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

int Rad(int c) //随机生成一个素数（存在问题）
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

//计算a^p mod n,并实施对n的二次探测
void power(unsigned int a,unsigned int p,unsigned int n,unsigned int &result,bool &composite)
{
	unsigned int x;
	if(p == 0)
	{
		result = 1;
	}
	else
	{
		power(a,p/2,n,x,composite);		//递归计算
		result = (x*x)%n;				//二次探测
 
		if((result == 1) && (x!=1) && (x!=n-1))
		{
			composite  = true;
		}
 
		if((p%2)==1)                   //p是奇数
		{
			result = (result*a)%n;
		}
	}
}
 
bool PrimeMC(unsigned int n,unsigned int k) //重复调用k次Prime算法的蒙特卡罗算法  
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
		cout << "1、手动" << endl << "2、自动" << endl;
		cin >> num;
		switch (num)
		{
			case 1:
				cout << "请输入一个数：";
				cin >> N;
					break;
			case 2:
				cout << "自动生成一个数：";
					N = Rad(c);
					cout << N << endl;;
					break;
		}
		printf("the result of the PrimeNumber is:%d\n", PrimeMC(N, k));
		cout << endl;	
	}
	return 0;
}

