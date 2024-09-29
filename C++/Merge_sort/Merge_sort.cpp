#include <iostream>
using namespace std;

const int N = 10010;
int q[N], cmt[N]; //存储最初的数组 临时数组

void Merge_sort(int q[], int l, int r)
{
	if (l >= r) return; //递归结束条件
	int mid = l + r >> 1; //定义中点
	
	Merge_sort(q, l, mid); //递归
	Merge_sort(q, mid + 1, r); //递归
	
	int i = l; //定义子数组的起点
	int j = mid + 1; //定义子数组的起点
	int k = 0; //临时数组操作数
	
	while (i <= mid && j <= r) //两个子数组都没有为空
	{
		if (q[i] < q[j]) cmt[k++] = q[i++]; //选出小的数加入临时数组
		else cmt[k++] = q[j++];
	}
	
	while (i <= mid) cmt[k++] = q[i++]; //将每个子数组的数加入临时数组
	while (j <= r) cmt[k++] = q[j++]; //将每个子数组的数加入临时数组
	
	for (int i = l, j = 0; i <= r; i++, j++)
		q[i] = cmt[j]; //将临时数组的数赋给最初数组
}

int main()
{
	int n;
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf_s("%d", &q[i]);
	
	Merge_sort(q, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	
	return 0;
}

//归并排序模版