#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int p[N]; //并查集
int m, n; //m次操作和n个点

struct Graph
{
	int a, b, w;
	
	bool operator< (const Graph &XYN)const
	{
		return w < XYN.w;
	} //重载小于号

}graphs[N]; //定义结构体数组

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
} //并查集的find函数

int main()
{
	scanf_s("%d%d", &m, &n);

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf_s("%d%d%d", &a, &b, &w);
		graphs[i] = { a,b,w };
	} //初始化结构体数组(结构体法)

	sort(graphs, graphs + m); //对结构体数组进行排序(从小到大)

	for (int i = 1; i <= n; i++) p[i] = i; //初始化并查集数组

	int res = 0; //初始化总权值
	int cnt = 0; //初始化总边数

	for (int i = 0; i < m; i++) //从权值最小的边开始遍历
	{
		int a = graphs[i].a;
		int b = graphs[i].b;
		int w = graphs[i].w;

		a = find(a); //a节点的根节点
		b = find(b); //b节点的根节点

		if (a != b) //如果a，b不连通
		{
			p[a] = b; //将a节点接在b节点上
			res += w; //更新总权值
			cnt++; //更新总边数
		}
	}

	if (cnt < n - 1) //如果边数少则说明点数不够 不连通
	{
		printf("给出的%d个点", n); 
		printf("不连通!\n");
	}
	
	else
	{
		printf("给出的%d个点的", n);
		printf("最小生成树的总权值是%d。\n", res);
	}
	
	return 0;
}

//Kruskal算法求最小生成树(无向图)(稀疏图)
//给出m个操作和n个节点数
//每次给出两个点和边的权值
//输出最小生成树的总权值
