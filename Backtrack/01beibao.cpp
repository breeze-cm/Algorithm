//#include "stdafx.h"
#include <iostream>
using namespace std;
 
#define N 10
int w[N];//����
int v[N];//��ֵ
int x[N];//1����뱳����0������
int num,cap;//num����Ʒ���� cap���������������
 
int capw=0;//��ǰ��Ʒ����
int capv=0;//��ǰ��Ʒ�ܼ�ֵ
 
int bestp=0;//��ǰ����ֵ
int bestx[N];//���Ž�
 
                                              //���ݺ��� k��ʾ��ǰ���ڵڼ�����ѡ��k=1ʱ��ʾ�����Ƿ񽫵�һ����Ʒ���뱳��
void backtrack(int k)
{
   if(k>num){
     if(capv>bestp){
        bestp = capv;
        for(int i=1; i<=num; i++)
            bestx[i] = x[i];
        }
    }
   else{                                      //������ǰ�ڵ���ӽڵ�
     for(int i=0; i<=1; i++){
        x[k]=i;
        if(i==0){
            backtrack(k+1);
        }
        else{                                 //Լ����������ǰ��Ʒ�Ƿ�ŵ���
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
    cout<<"��Ʒ������";
    cin>>num;
    cout<<"ÿ����Ʒ��������ֵ:"<<endl;
    
    for(int i=1;i<=num;i++)
        cin >> w[i] >> v[i];
    
    cout<<"����������";
    cin>>cap;
    backtrack(1);
    cout<<"���Ž���:"<<bestp<<endl;
   
    
    for(int i=1;i<=num;i++)
        cout<<bestx[i]<<" ";
    
    
    return 0;
}