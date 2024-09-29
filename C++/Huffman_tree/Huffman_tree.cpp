#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n); //初始化多少堆金币
	
	priority_queue<int, vector<int>, greater<int>> heap; //定义小根堆
	
	while (n--)
	{
		int x;
		scanf_s("%d", &x);
		heap.push(x);
	}
	
	int res = 0; //初始化需要消耗的体力
	
	while (heap.size() > 1) //存在至少两堆金币
	{
		int a = heap.top();
		heap.pop();
		
		int b = heap.top();
		heap.pop();
		
		res += a + b; //更新体力
		
		heap.push(a + b);
	} //每次取出两堆最小的金币，和为一堆并且插入小根堆中

	printf("搬动所有金币需要消耗%d的体力。\n", res);
	
	return 0;
}

//哈夫曼树算法(贪心)
//给出n堆金币
//给出每堆消耗的体力
//得出最小需要消耗的体力