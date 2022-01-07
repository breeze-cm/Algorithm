#include<iostream>
#include<string>
#include<vector>

using namespace std;

//最长公共子序列
int Max(int a, int b)
{
	return (a > b) ? a : b;
}

void creatDp(string s1, string s2, int* dp)
{
	int len1 = s1.length();
	int len2 = s2.length();
	
	//先求出第一行
	for (int j = 0; j < len2; j++)
	{
		if (s1[0] == s2[j]) {
			*(dp + 0 * len2 + j) = 1;
			for (; j < len2; j++)
				*(dp + 0 * len2 + j) = 1;
			break;
		}
		else
			*(dp + 0 * len2 + j) = 0;
	}
	//然后求第一列
	for (int i = 0; i < len1; i++)
	{
		if (s1[i] == s2[0]) {
			*(dp + i * len2 + 0) = 1;
			for (; i < len1; i++)
				*(dp + i * len2 + 0) = 1;
			break;
		}
		else
			*(dp + i * len2 + 0) = 0;
	}
	//求其他的数据
	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (s1[i] == s2[j])
				*(dp + i * len2 + j) = *(dp + (i - 1) * len2 + (j - 1)) + 1;
			else
				*(dp + i * len2 + j) = Max(*(dp + (i - 1) * len2 + j), *(dp + i * len2 + j - 1));
		}
	}
	//这个值记录着最大公共子序列的长度

}

void getLCS(int* dp, string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int i = len1 - 1;
	int j = len2 - 1;
	int len = dp[i * len2 + j];
	char* result = new char[len];
	int k = len - 1;
	while (*(dp + i * len2 + j) != 0 && i >= 0 && j >= 0) {
		if (s1[i] == s2[j]) {
			result[k--] = s1[i];
			i--; j--;
		}
		else
		{
			if (*(dp + (i - 1) * len2 + j) > * (dp + (i)*len2 + j - 1))
				i--;
			else
				j--;
		}
	}
	cout << "最长公共子序列为：";
	for (int i = 0; i < len; i++)	
		cout << result[i] << " ";
	cout << endl;
		
}

void LCSLength()
{
	string s1;
	string s2;
	while (1) {
		cout << "First:";
		cin >> s1;
		cout << "Second:";
		cin >> s2;
		int len1 = s1.length();
		int len2 = s2.length();
		int* dp = new int[len1 * len2];
		creatDp(s1, s2, dp);
		getLCS(dp, s1, s2);
		delete[] dp;
	}
	
}

//————————————————————————————————————————————————————————————————————————————//
//矩阵连乘
const int maxn = 1e3 + 5;
int num[maxn][maxn], by[maxn][maxn];
int p[maxn];

void solve1(int n)//动态规划 
{
	for (int i = 1; i <= n; i++)
		num[i][i] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int st = 1; st <= n - i + 1; st++)
		{
			int ed = st + i - 1;
			num[st][ed] = num[st][st] + num[st + 1][ed] + p[st - 1] * p[st] * p[ed];
			by[st][ed] = st;
			for (int b = st + 1; b < ed; b++)
			{
				if (num[st][b] + num[b + 1][ed] + p[st - 1] * p[b] * p[ed] < num[st][ed])
				{
					num[st][ed] = num[st][b] + num[b + 1][ed] + p[st - 1] * p[b] * p[ed];
					by[st][ed] = b;
				}
			}
		}
	}
}

int solve(int l, int r)//备忘录 
{
	if (l == r)
		return 0;
	if (num[l][r] != 0)
		return num[l][r];
	num[l][r] = solve(l, l) + solve(l + 1, r) + p[l - 1] * p[l] * p[r];
	by[l][r] = l;
	for (int i = l + 1; i < r; i++)
	{
		if (num[l][r] > solve(l, i) + solve(i + 1, r) + p[l - 1] * p[i] * p[r])
			num[l][r] = solve(l, i) + solve(i + 1, r) + p[l - 1] * p[i] * p[r], by[l][r] = i;
	}
	return num[l][r];
}

void display(int l, int r)
{
	//cout << "结果：";
	if (r == l)
	{
		cout << "A" << l;
		return;
	}
	cout << "(";
	if (r - l == 1)
	{
		cout << "A" << l << "A" << r << ")";
		return;
	}
	display(l, by[l][r]);
	display(by[l][r] + 1, r);
	cout << ")";
	cout << endl;
}
void MatrixChain()
{
	int n;
	scanf_s("%d", &n);
	int r, c;
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d%d", &r, &c);
		if (i == 1)
			p[i - 1] = r, p[i] = c;
		else p[i] = c;
	}
	solve(1, n);
	display(1, n);

}

int main()
{
	while (1)
	{
		int x;
		printf("请选择：1 矩阵连乘； 2 LCSLength；");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:
			MatrixChain();
			break;
		case 2:
			LCSLength();
			break;
		}
	}
}