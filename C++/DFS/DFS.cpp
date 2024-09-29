#include <iostream>
using namespace std;

const int N = 10010;
int n;
int path[N]; //�洢�𰸵�����
bool st[N]; //�ж�ÿ�����Ƿ�ʹ�ù�

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d", path[i]);
		printf("\n");
		return;
	} //����������ȵ���nʱ������
	
	for (int i = 1; i <= n; i++)
	{
		if (!st[i]) //�ж�i�Ƿ�ʹ�ù�
		{
			path[u] = i; //��u�㸳ֵΪi
			st[i] = true; //���iΪʹ�ù�
			dfs(u + 1); //������һ��
			st[i] = false; //��i�ָ�Ϊδʹ�õ�״̬ ���ָ��ֳ���
		}
	} //ѭ���ж�ÿ�����
}
int main()
{
	scanf_s("%d", &n);
	dfs(0);
	
	return 0;
}

// ������ȱ���
//���˻ʺ����⡷��ȫ�������⡷
// ����n��������1��n��ȫ���н��