#include<iostream>
using namespace std;
#define INF 10000
static int eq[INF] = {0}, count = 0, n;

void print() {
	for(int i = 0; i < n; i++)
	{
		int j;
		for(j = 0; j < eq[i]; j++)
		  cout << "0";
		cout << "#";
		for(j = eq[i]+1; j < n; j++)
		  cout << "0";
		cout << endl;
	}
	cout << "------------------------------\n";
}

bool check(int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		j = eq[i];
		if (col == j)
		  return false;
		if (row - col == i - j)
		  return false;
		if (row + col == i + j)
		  return false;
	}
	return true;
}

void eight_queen(int row)
{
	int col;
	for (col = 0; col < n; col++)
	{
		if(check(row, col))
		{
			eq[row] = col;
			if (row == n-1)
			{
				count++;
				print();
				eq[row] = 0;
				return;
			}
			eight_queen(row+1);
			eq[row] = 0;
		}
	}
}

int main()
{
	cout << "ÊäÈën:" << endl;
	cin >> n;
	if (n == 1 || n >= 4)
	  eight_queen(0);
	cout << "total=" << count << endl;
}
