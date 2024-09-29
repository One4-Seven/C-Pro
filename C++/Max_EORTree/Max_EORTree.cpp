#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int s[N]; //存储给出的十进制数
int son[N][2], idx; //存储二进制数的每一位，操作数

void insert(int x)
{
	int p = 0; //初始化p值
	
	for (int i = 30; i >= 0; i--) //二进制数一般有30位
	{
		int u = x >> i & 1; //依次取出每一位上的数
		if (!son[p][u]) son[p][u] = ++idx; //如果节点不存在则创造节点 son中存储的是儿子节点的p值
		p = son[p][u]; //更新p值
	}
} //插入操作(Trie树)

int query(int x)
{
	int p = 0, res = 0; //初始化 p值和答案
	
	for (int i = 30; i >= 0; i--) //从高位开始循环
	{
		int u = x >> i & 1; //依次取出每一位上的数
		
		if (son[p][!u]) //因为要异或值最大所以优先选择不同值的节点
		{
			p = son[p][!u]; //取出下一层的p值
			res = res * 2 + !u; //更新答案
		}
		
		else //退而求其次 选择值相同的节点
		{
			p = son[p][u]; //取出下一层的p值
			res = res * 2 + u;//更新答案
		}
	}
	return res; //返回答案
} //

int main()
{
	int res = 0; //初始化答案为0
	
	int n;
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf_s("%d", &s[i]);
	
	for (int i = 0; i < n; i++)
	{
		insert(s[i]);
		int t = query(s[i]);
		res = max(res, t ^ s[i]);
	} //每一次执行一次插入操作和查询操作，并且更新答案为最小值
	
	if (n == 0) printf("数组为空!\n"); //判断数组是否为空
	else printf("最大异或值为%d", res); //输出答案
	
	return 0;
}

//最大异或数
//使用Trie树解决此类问题
//给出n个数，返回其中两个数的最大异或值