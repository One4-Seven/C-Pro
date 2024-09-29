#include <iostream>
#include <algorithm>
#include <cstring>
using  namespace std;

const int N = 10010;
int INF = 1e9; //��������
int a[N][N]; //���������������
int f[N][N]; //(i,j)��ŵ���i��j�е����ֵ

int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf_s("%d", &a[i][j]); //����������������


	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i + 1; j++)
			f[i][j] = -INF; //��ʼ�����ֵ��Ϊ������

	f[1][1] = a[1][1]; //��ʼ�����

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]); //�ֱ�������״̬�����ֵ�����Ϸ������Ϸ�

	int res = -INF; //��ʼ����
	for (int i = 1; i <= n; i++) res = max(res, f[n][i]);//�����յ�һ����ѡ�����ֵ

	printf("��������:\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	printf("����Ͷ�·�������ֵ��%d��\n", res);

	return 0;
}

//�������� (DP��̬�滮)
//��������������
//����ÿһ������
//�����ߵ����һ������·��

