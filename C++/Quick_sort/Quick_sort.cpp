#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int q[N]; //最初数组

void Quick_sort(int q[], int l, int r)
{
	if (l >= r) return; //递归结束条件

	int x = q[l + r >> 1]; //定义x值
	int i = l - 1; //初始化左节点
	int j = r + 1; //初始化右节点

	while (i < j) //循环结束条件
	{
		do i++; while (q[i] < x); //找到左边第一个大于x的值
		do j--; while (q[j] > x); //找到右边第一个小于x的值
		if (i < j) swap(q[i], q[j]); //如果此时i在j的左侧 交换q[i]和q[j]
	}

	Quick_sort(q, l, j); //递归
	Quick_sort(q, j + 1, r); //递归
}

int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &q[i]);

	Quick_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	return 0;
}

//快速排序模版 x的值可取 L    L+R>>1  使用  j    j+1   
//快速排序模版 x的值可取 L+R+1>1   R  使用  i-1    i
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int q[N]; //最初数组

void Quick_sort(int q[], int l, int r)
{
	if (l >= r) return; //递归结束条件

	int x = q[l + r >> 1]; //定义x值
	int i = l - 1; //初始化左节点
	int j = r + 1; //初始化右节点

	while (i < j) //循环结束条件
	{
		do i++; while (q[i] < x); //找到左边第一个大于x的值
		do j--; while (q[j] > x); //找到右边第一个小于x的值
		if (i < j) swap(q[i], q[j]); //如果此时i在j的左侧 交换q[i]和q[j]
	}

	Quick_sort(q, l, j); //递归
	Quick_sort(q, j + 1, r); //递归
}

int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &q[i]);

	Quick_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	return 0;
}

//快速排序模版 x的值可取 L    L+R>>1  使用  j    j+1   
//快速排序模版 x的值可取 L+R+1>1   R  使用  i-1    i
