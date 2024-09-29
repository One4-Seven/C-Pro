#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int f[N][N]; //f(n,m)������ǰn����Ʒ�ұ���������m������µ�����ֵ
int v[N]; //ÿ����Ʒ�����
int w[N]; //ÿ����Ʒ�ļ�ֵ
int F[N]; //һά�Ż�����

//int main() //��ά���鷨
//{
//	int m, n;
//	scanf_s("%d%d", &n, &m);
//
//	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]); //����n����Ʒ����
//
//	for (int i = 1; i <= n; i++) //ѭ������ǰn����Ʒ
//		for (int j = 0; j <= m; j++) //ѭ�����Ǳ������
//		{
//			f[i][j] = f[i - 1][j]; //�������i����Ʒ�����
//			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); //����װ���µ�i����Ʒ ����Ϊ�����i����Ʒ�����ֵ
//		}
//
//	printf("�ڱ���������%d������£��ܼ�ֵ�����%d��\n", m, f[n][m]);
//
//	return 0;
//}

int main() //һά�Ż���
{
	int m, n;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			F[j] = max(F[j], F[j - v[i]] + w[i]);

	printf("�ڱ���������%d������£��ܼ�ֵ�����%d��\n", m, F[m]);

	return 0;
}

//����01�������� (DP��̬�滮)
//����n����Ʒ�ͱ�������m
//��������ÿ����Ʒ������
//��������ܼ�ֵ
