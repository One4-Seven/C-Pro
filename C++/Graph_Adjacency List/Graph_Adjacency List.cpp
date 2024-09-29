#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10010;
int head[N]; //作为头结点的数 存的是与之相连的点的下标
int e[N]; //点的信息
int ne[N]; //下一个节点的下标
int n;
int idx; //下一个空节点的下表 用于控制链表

void add(int a, int b)
{
	e[idx] = b; //存入点b
	ne[idx] = head[a]; //让点b的下一个点变为原先和头结点相连的点
	head[a] = idx++; //让头结点与b节点相连 同时空节点数++
} //让a节点与b节点相连

int main()
{
	scanf_s("%d", &n); //读入n次操作

	int k = 2 * n; //n次操作最多涉及2n个点

	memset(head, -1, sizeof head); //初始化每个头结点的下一个节点为NULL

	while (n--)
	{
		int a, b;
		scanf_s("%d%d", &a, &b);
		add(a, b); //a->b
		add(b, a); //b->a
	} //用领接表的方式存储无向图 有向图时add一次即可

	for (int j = 1; j <= k; j++)
	{
		printf("与%d相连的节点:", j);
		for (int i = head[j]; i != -1; i = ne[i])
			printf("%d ", e[i]);
		printf("\n");
	} //输出无向图的信息

	return 0;

}

//无向图的生成和打印
//给出n组数据，即有n条边
//输出每个点的邻接点

