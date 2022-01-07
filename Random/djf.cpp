#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
using namespace std;

double Darts(int n)
{
       double x,y;
       time_t t;
       int i,count=0;
       srand((unsigned)time(&t));         
       for(i=0;i<n;i++)
       {
              x=rand()%100/100.0;         //将x，y控制在（0，1）内
              y=rand()%100/100.0;
              if(y<=1-pow(x,2))
                     count++;
       }
       return (double)count/(double)n;
}



int main()
{
	int n1 = 100,n2 = 1000,n3 = 1000,n4 = 10000,n5 = 10000000;
	cout<<"1-x^2积分结果为："<<endl;
	cout<<"n1="<<n1<<",1="<<Darts(n1)<<endl;
	cout<<"n2="<<n2<<",2="<<Darts(n2)<<endl;
	cout<<"n3="<<n3<<",3="<<Darts(n3)<<endl;
	cout<<"n4="<<n4<<",4="<<Darts(n4)<<endl;
	cout<<"n5="<<n5<<",5="<<Darts(n5)<<endl;
	int m = 0;

    return 0;
}
