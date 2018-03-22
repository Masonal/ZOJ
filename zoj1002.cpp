//copied from http://www.cnblogs.com/phinecos/archive/2008/09/18/1293017.html
#include<iostream>
using namespace std;

char map[4][4];
int maxNum, n;


bool canPut(int R, int C) {
	int i;
	for (i = R - 1; i >= 0; --i) 
	{
		if (map[i][C] == 'O') return false;
		if (map[i][C] == 'X') break;
	}
	for (i = C - 1; i >= 0; --i) 
	{
		if (map[R][i] == 'O') return false;
		if (map[R][i] == 'X') break;
	}
	return true;
}


void Solve(int k, int curNum) {
	int row, col;
	if (k == n*n) 
	{
		if (curNum > maxNum) 
		{
			maxNum = curNum;
			return;
		}
	}
	else 
	{
		row = k / n;
		col = k % n;
		if ((map[row][col] == '.') && (canPut(row, col) == true)) 
		{
			map[row][col] = 'O';
			Solve(k + 1, curNum + 1);
			map[row][col] = '.';
		}
		Solve(k + 1, curNum);
	}

}

int main()
{
	int i, j;
	while (cin >> n&&n != 0)
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				cin >> map[i][j];
			}
		}
		maxNum = 0;
		Solve(0, 0);
		cout << maxNum << endl;
	}
	return 0;
}
