#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10010;
int head[N]; //��Ϊͷ������ �������֮�����ĵ���±�
int e[N]; //�����Ϣ
int ne[N]; //��һ���ڵ���±�
int n;
int idx; //��һ���սڵ���±� ���ڿ�������

void add(int a, int b)
{
	e[idx] = b; //�����b
	ne[idx] = head[a]; //�õ�b����һ�����Ϊԭ�Ⱥ�ͷ��������ĵ�
	head[a] = idx++; //��ͷ�����b�ڵ����� ͬʱ�սڵ���++
} //��a�ڵ���b�ڵ�����

int main()
{
	scanf_s("%d", &n); //����n�β���

	int k = 2 * n; //n�β�������漰2n����

	memset(head, -1, sizeof head); //��ʼ��ÿ��ͷ������һ���ڵ�ΪNULL

	while (n--)
	{
		int a, b;
		scanf_s("%d%d", &a, &b);
		add(a, b); //a->b
		add(b, a); //b->a
	} //����ӱ�ķ�ʽ�洢����ͼ ����ͼʱaddһ�μ���

	for (int j = 1; j <= k; j++)
	{
		printf("��%d�����Ľڵ�:", j);
		for (int i = head[j]; i != -1; i = ne[i])
			printf("%d ", e[i]);
		printf("\n");
	} //�������ͼ����Ϣ

	return 0;

}

//����ͼ�����ɺʹ�ӡ
//����n�����ݣ�����n����
//���ÿ������ڽӵ�

