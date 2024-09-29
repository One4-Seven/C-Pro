#include <iostream>
#include <algorithm>
#include <cstring>
using  namespace std;

const int N = 10010;
int INF = 1e9; //定义数据
int a[N][N]; //存放数字三角数据
int f[N][N]; //(i,j)存放到达i行j列的最大值

int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf_s("%d", &a[i][j]); //读入数字三角数据


	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i + 1; j++)
			f[i][j] = -INF; //初始化最大值都为负无穷

	f[1][1] = a[1][1]; //初始化起点

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]); //分别求两种状态的最大值，左上方和右上方

	int res = -INF; //初始化答案
	for (int i = 1; i <= n; i++) res = max(res, f[n][i]);//从最终的一行里选出最大值

	printf("数字三角:\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	printf("到达低端路径的最大值是%d。\n", res);

	return 0;
}

//数字三角 (DP动态规划)
//给出三角形行数
//给出每一行数据
//给出走到最后一层的最大路径

