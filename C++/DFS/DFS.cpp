#include <iostream>
using namespace std;

const int N = 10010;
int n;
int path[N]; //存储答案的数组
bool st[N]; //判断每个数是否使用过

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d", path[i]);
		printf("\n");
		return;
	} //当遍历的深度到达n时数出答案
	
	for (int i = 1; i <= n; i++)
	{
		if (!st[i]) //判断i是否使用过
		{
			path[u] = i; //第u层赋值为i
			st[i] = true; //标记i为使用过
			dfs(u + 1); //遍历下一层
			st[i] = false; //让i恢复为未使用的状态 《恢复现场》
		}
	} //循环判断每层的数
}
int main()
{
	scanf_s("%d", &n);
	dfs(0);
	
	return 0;
}

// 深度优先遍历
//《八皇后问题》《全排列问题》
// 输入n，给出从1到n的全排列结果