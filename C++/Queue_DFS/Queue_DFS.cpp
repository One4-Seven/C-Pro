#include <iostream>
using namespace std;

const int N = 100;
int n; //皇后数量
int sum1, sum2; //方案总数
char g[N][N]; //棋盘数组
bool row[N], col[N], dg[N], udg[N]; //每个方向的布尔数组 (对角线布尔数组要开大一些,容易越界)

void Queue_dfs(int x, int y, int s) //x为循环的行数,y为循环的列数，s为放置皇后的数量
{
	if (y == n) x++, y = 0; //循环到最后一列时

	if (x == n) //循环到最后一行时
	{
		if (s == n) //n个皇后都已经放置
		{
			sum1++;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					printf("%c ", g[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		return;
	} //打印答案棋盘

	Queue_dfs(x, y + 1, s); //当前点不放皇后，递归下一格

	if (!row[x] && !col[y] && !dg[x + y] && !udg[n - x + y]) //当前行，列，对角线，反对角线都不存在皇后
	{
		g[x][y] = 'Q'; //当前点放置皇后
		row[x] = col[y] = dg[x + y] = udg[n - x + y] = true; //当前行，列，对角线，反对角线布尔值赋值为1

		Queue_dfs(x, y + 1, s + 1); //递归下一格，皇后数加1

		row[x] = col[y] = dg[x + y] = udg[n - x + y] = false; //当前行，列，对角线，反对角线布尔值赋值为0 (恢复现场)
		g[x][y] = 'o'; //当前点取出皇后 (恢复现场)
	}
}


void Queue_Dfs(int u) //u为循环的行数
{
	if (u == n) //每一行皇后放置完成
	{
		sum2++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%c ", g[i][j]);
			printf("\n");
		}
		printf("\n");
		return;
	} //打印答案棋盘

	for (int i = 0; i < n; i++) //循环考虑皇后放置的列数
	{
		if (!col[i] && !dg[u + i] && !udg[n - u + i]) //当前列，对角线，反对角线都不存在皇后
		{
			g[u][i] = 'Q'; //当前点放置皇后
			col[i] = dg[u + i] = udg[n - u + i] = true; //当前列，对角线，反对角线布尔值赋值为1

			Queue_Dfs(u + 1); //递归下一行

			col[i] = dg[u + i] = udg[n - u + i] = false; //当前列，对角线，反对角线布尔值赋值为0 (恢复现场)
			g[u][i] = 'o'; //当前点取出皇后 (恢复现场)
		}
	}
}

int main()
{
	scanf_s("%d", &n); //读入皇后数量

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = 'o'; //初始化棋盘

	
	Queue_dfs(0, 0, 0); //调用深搜函数
	printf("%d皇后的排列方法有%d种\n", n, sum1);
	
	printf("- - - - - - - - - - - - - - \n"); //分界线
	
	Queue_Dfs(0); //调用深搜函数
	printf("%d皇后的排列方法有%d种\n", n, sum2);
	return 0;
}

//n皇后问题(DFS)
//给出n个皇后
//打印皇后位置和所有解法