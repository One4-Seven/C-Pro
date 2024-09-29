#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int q[N]; //�������

void Quick_sort(int q[], int l, int r)
{
	if (l >= r) return; //�ݹ��������

	int x = q[l + r >> 1]; //����xֵ
	int i = l - 1; //��ʼ����ڵ�
	int j = r + 1; //��ʼ���ҽڵ�

	while (i < j) //ѭ����������
	{
		do i++; while (q[i] < x); //�ҵ���ߵ�һ������x��ֵ
		do j--; while (q[j] > x); //�ҵ��ұߵ�һ��С��x��ֵ
		if (i < j) swap(q[i], q[j]); //�����ʱi��j����� ����q[i]��q[j]
	}

	Quick_sort(q, l, j); //�ݹ�
	Quick_sort(q, j + 1, r); //�ݹ�
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

//��������ģ�� x��ֵ��ȡ L    L+R>>1  ʹ��  j    j+1   
//��������ģ�� x��ֵ��ȡ L+R+1>1   R  ʹ��  i-1    i
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int q[N]; //�������

void Quick_sort(int q[], int l, int r)
{
	if (l >= r) return; //�ݹ��������

	int x = q[l + r >> 1]; //����xֵ
	int i = l - 1; //��ʼ����ڵ�
	int j = r + 1; //��ʼ���ҽڵ�

	while (i < j) //ѭ����������
	{
		do i++; while (q[i] < x); //�ҵ���ߵ�һ������x��ֵ
		do j--; while (q[j] > x); //�ҵ��ұߵ�һ��С��x��ֵ
		if (i < j) swap(q[i], q[j]); //�����ʱi��j����� ����q[i]��q[j]
	}

	Quick_sort(q, l, j); //�ݹ�
	Quick_sort(q, j + 1, r); //�ݹ�
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

//��������ģ�� x��ֵ��ȡ L    L+R>>1  ʹ��  j    j+1   
//��������ģ�� x��ֵ��ȡ L+R+1>1   R  ʹ��  i-1    i
