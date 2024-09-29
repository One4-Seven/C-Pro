#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10010;
int f[N][N]; //(n,m)只考虑前n件物品，容量为m时的最大价值
int v[N]; //物品体积
int w[N]; //物品价值
int s[N]; //物品数量
int F[N]; //一维优化数组

int main() //三维数组法
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf_s("%d%d%d", &v[i], &w[i], &s[i]); //读入物品属性

	for (int i = 1; i <= n; i++) //循环考虑前n件物品
		for (int j = 0; j <= m; j++) //循环考虑背包容量
			for (int k = 0; k <= s[i] && k * v[i] <= j; k++) //循环考虑加入k件i物品
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

	printf("当背包容量是%d时最大价值是%d。\n", m, f[n][m]);

	return 0;
}

int main() //一维优化法 & 二进制优化法
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	
	int cnt = 0; //初始化新打包的物品数量

	for (int i = 1; i <= n; i++) //将每一件物品打包成若干个集合(二进制优化法)
	{
		int a, b, s;
		scanf_s("%d%d%d", &a, &b, &s); //读入物品属性 a体积 b价值 s数量
		
		int k = 1; //初始化第一次打包的数量
		
		while (k <= s) //当物品还有剩余且够打包
		{
			cnt++; //新打包物品数+1
			v[cnt] = k * a; //此次打包的体积
			w[cnt] = k * b; //此次打包的价值
			s -= k; //更新物品总数
			k *= 2; //更新下次打包的数量
		}
		
		if (s > 0) //不够下次打包数量但有剩余
		{
			cnt++; //新打包物品数+1
			v[cnt] = s * a; //此次打包的体积
			w[cnt] = s * b; //此次打包的价值
		}
	}
	
	n = cnt; //更新总物品数为我们打包的总数
	
	
	for (int i = 1; i <= n; i++) 
		for (int j = m; j >= v[i]; j--)
			F[j] = max(F[j], F[j - v[i]] + w[i]); 
	//把问题转化为01背包问题(一维优化法)
	
	printf("当背包容量是%d时最大价值是%d。\n", m, F[m]);

	return 0;
}

//多重背包问题 (DP动态规划)
//给出n各物品和背包容量m
//依次输入每个物品的属性
//给出最大总价值


