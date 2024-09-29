#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int m, n;
PII queue[N * N]; //存储操作点的二元组数组
int lab[N][N]; //存储给出的迷宫

int d[N][N]; //存储到达每个点最少要走的步数

void BFS()
{
	memset(d, -1, sizeof d); //初始化距离起点的距离为-1
	
	int hh = 0; //队头
	int tt = 0; //队尾
	
	queue[0] = { 0,0 }; //给出起点的坐标
	
	d[0][0] = 0; //初始化起点到起点的最短距离
	
	int dx[4] = { -1,0,1,0 }; //四个方向的操作数
	int dy[4] = { 0,1,0,-1 }; //四个方向的操作数
	
	while (hh <= tt) //数组中存在操作数
	{
		auto t = queue[hh++]; //取出队头操作数且出队
		
		for (int i = 0; i < 4; i++) //拓展取出的操作数
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			
			if (x >= 0 && x < m && y >= 0 && y < n && lab[x][y] == 0 && d[x][y] == -1) //距离更新的条件(根据题目改变)
			{
				d[x][y] = d[t.first][t.second] + 1; //更新距离
				queue[++tt] = { x,y }; //拓展的新操作数入队
			}
		}
	}
}

int main()
{
	scanf_s("%d%d", &m, &n);
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &lab[i][j]); //读入迷宫
	
	BFS(); //广度优先遍历
	
	printf("你给出的迷宫原型:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d ", lab[i][j]);
		printf("\n");
	} 

	if (d[m - 1][n - 1] == -1) //不存在到达终点的路径
	{
		printf("无法到达终点(%d,%d)。\n", n, m);
		printf("迷宫总览：\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%4d ", d[i][j]);
			printf("\n");
		}
	}
	
	else
	{
		printf("到达终点(%d,%d)最少要走%d步。\n", n, m, d[m - 1][n - 1]);
		printf("路线总览：\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%4d ", d[i][j]);
			printf("\n");
		}
	} //打印
	
	return 0;
}

//广度优先遍历
//《走迷宫》(每个点之间的权值需要相同)
//定义长宽，给出迷宫的模型，1为墙不可通过，0为路可以通过
//计算出从（0,0）到达（m，n）最少的步数


//    广度优先遍历模版：    //
//                          //
//    入队                  //  
//    while(hh<=tt)         //
//    {                     //
//	    取队头              //
//      拓展队头(条件)      //
//      插入拓展后的节点    //
//    }                     //
