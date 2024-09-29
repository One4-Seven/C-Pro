#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int f[N][N]; //f(n,m)：考虑前n件物品且背包容量是m的情况下的最大价值
int v[N]; //每个物品的体积
int w[N]; //每个物品的价值
int F[N]; //一维优化数组

//int main() //二维数组法
//{
//	int m, n;
//	scanf_s("%d%d", &n, &m);
//
//	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]); //读入n件物品数据
//
//	for (int i = 1; i <= n; i++) //循环考虑前n件物品
//		for (int j = 0; j <= m; j++) //循环考虑背包体积
//		{
//			f[i][j] = f[i - 1][j]; //不放入第i件物品的情况
//			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); //背包装得下第i件物品 更新为放入第i件物品的最大值
//		}
//
//	printf("在背包容量是%d的情况下，总价值最大是%d。\n", m, f[n][m]);
//
//	return 0;
//}

int main() //一维优化法
{
	int m, n;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			F[j] = max(F[j], F[j - v[i]] + w[i]);

	printf("在背包容量是%d的情况下，总价值最大是%d。\n", m, F[m]);

	return 0;
}

//经典01背包问题 (DP动态规划)
//给出n各物品和背包容量m
//依次输入每个物品的属性
//给出最大总价值
