//#include "stdafx.h"
#include <iostream>
using namespace std;
 
#define N 10
int w[N];//重量
int v[N];//价值
int x[N];//1表放入背包，0表不放入
int num,cap;//num：物品个数 cap：背包的最大容量
 
int capw=0;//当前物品总重
int capv=0;//当前物品总价值
 
int bestp=0;//当前最大价值
int bestx[N];//最优解
 
                                              //回溯函数 k表示当前处在第几层做选择，k=1时表示决定是否将第一个物品放入背包
void backtrack(int k)
{
   if(k>num){
     if(capv>bestp){
        bestp = capv;
        for(int i=1; i<=num; i++)
            bestx[i] = x[i];
        }
    }
   else{                                      //遍历当前节点的子节点
     for(int i=0; i<=1; i++){
        x[k]=i;
        if(i==0){
            backtrack(k+1);
        }
        else{                                 //约束条件：当前物品是否放的下
           if((capw+w[k])<=cap){
             capw += w[k];
             capv += v[k];
             backtrack(k+1);
             capw -= w[k];
             capv -= v[k];
           }
        }
     }
  }
}
 
int main()
{
    cout<<"物品个数：";
    cin>>num;
    cout<<"每个物品重量及价值:"<<endl;
    
    for(int i=1;i<=num;i++)
        cin >> w[i] >> v[i];
    
    cout<<"背包容量：";
    cin>>cap;
    backtrack(1);
    cout<<"最优解是:"<<bestp<<endl;
   
    
    for(int i=1;i<=num;i++)
        cout<<bestx[i]<<" ";
    
    
    return 0;
}