#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int f[N][N]; //(n,m)只考虑前n件物品，背包容量为m
int v[N]; //物品体积
int w[N]; //物品价值
int F[N]; //一维优化数组

int main() //三维数组法
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]); //读入每件物品属性

	for (int i = 1; i <= n; i++) //循环考虑n件物品
		for (int j = 0; j <= m; j++) //循环考虑背包容量
			for (int k = 0; k * v[i] <= j; k++) //循环考虑可以放k件i物品
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]); //更新最大价值
	
	printf("当背包容量是%d时最大价值是%d。\n", m, f[n][m]); 
	
	return 0;
}

int main() //二维优化法
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]); //读入每件物品属性

	for (int i = 1; i <= n; i++) //循环考虑n件物品
		for (int j = 0; j <= m; j++) //循环考虑背包容量
		{
			f[i][j] = f[i - 1][j]; //没有选择第i件物品的情况
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]); //优化：选择第i件物品的情况
		}

	printf("当背包容量是%d时最大价值是%d。\n", m, f[n][m]);

	return 0;
}

int main() //一维优化法 类似01背包问题
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= n; i++) 
		for (int j = v[i]; j <= m; j++) 
			F[j] = max(F[j], F[j - v[i]] + w[i]); 
	

	printf("当背包容量是%d时最大价值是%d。\n", m, F[m]);

	return 0;
}

//完全背包问题 (DP动态规划)
//给出n各物品和背包容量m
//依次输入每个物品的属性
//给出最大总价值
//最终优化代码和01背包问题只相差一个循环顺序