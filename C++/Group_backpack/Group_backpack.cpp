#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int F[N]; //一维优化数组
int v[N][N]; //第N组第N种的体积
int w[N][N]; //第N组第N种的价值
int s[N]; //第N组的种类

int main() //三重循环 二维数组
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) //循环读入n组的数据
	{
		scanf_s("%d", &s[i]); //读入第i组的种类
		
		for (int j = 1; j <= s[i]; j++)
			scanf_s("%d%d", &v[i][j], &w[i][j]); //读入物品属性
	}

	for (int i = 1; i <= n; i++) //循环考虑前i组物品
		for (int j = m; j >= 0; j--) //循环考虑背包容量
			for (int k = 1; k <= s[i]; k++) //循环考虑第i组的每一种物品
				if (v[i][k] <= j) //判断第i组的第k件物品是否可以塞得下
					F[j] = max(F[j], F[j - v[i][k]] + w[i][k]); //更新最大价值(类似01背包问题)

	printf("当背包容量是%d时最大价值是%d。\n", m, F[m]);
	
	return 0;
}

//分组背包问题 (DP动态规划)
//给出n组物品和背包容量m
//给出每一组物品有多少种
//依次输入每种物品的属性
//给出最大总价值
//最终优化代码和01背包问题相似