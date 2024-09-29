#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 500, INF = 0x3f3f3f3f; //定义最大值
int m, n; //m为操作数，n为点的数量
int g[N][N]; //存储每个点之间的距离
int dist[N]; //每个点到连通集合的距离
bool st[N]; //判断每个点是否加入集合

int Prim()
{
	int res = 0; //集合长度初始化
	
	memset(dist, 0x3f, sizeof dist); //初始化每个点到连通集合的距离
	
	for (int i = 0; i < n; i++) //循环插入n次点
	{
		int k = -1; //记录当前插入的是几号点
		
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (k == -1 || dist[j] < dist[k]))
				k = j;
		} //循环选择一个距离集合最近的点
		
		if (i && dist[k] == INF) return INF; //如果不是第一个点而且距离是正无穷，说明不连通
		
		if (i) res += dist[k]; //如果不是第一个点则更新集合长度
		
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], g[j][k]); //更新每个点到集合的距离
		
		st[k] = true; //更新点k的状态
	}
	return res; //返回集合长度
}

int main()
{
	memset(g, 0x3f, sizeof g); //初始化每个点之间的距离
	
	scanf_s("%d%d", &m, &n);
	while (m--)
	{
		int a, b, c;
		scanf_s("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	} //初始化点与点的状态(邻接矩阵法)
	
	int t = Prim();

	if (t == INF)
	{
		printf("给出的%d个点", n);
		printf("不连通!\n");
	}
	else
	{
		printf("给出的%d个点的", n);
		printf("最小生成树的总权值是%d。\n", t);
	}
	return 0;
}

//Prim算法求最小生成树(无向图)(稠密图)
//给出m个操作和n个节点数
//每次给出两个点之间的权值
//输出最小生成树的总权值