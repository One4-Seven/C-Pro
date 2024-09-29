#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int f[N][N]; //(n,m)ֻ����ǰn����Ʒ����������Ϊm
int v[N]; //��Ʒ���
int w[N]; //��Ʒ��ֵ
int F[N]; //һά�Ż�����

int main() //��ά���鷨
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]); //����ÿ����Ʒ����

	for (int i = 1; i <= n; i++) //ѭ������n����Ʒ
		for (int j = 0; j <= m; j++) //ѭ�����Ǳ�������
			for (int k = 0; k * v[i] <= j; k++) //ѭ�����ǿ��Է�k��i��Ʒ
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]); //��������ֵ
	
	printf("������������%dʱ����ֵ��%d��\n", m, f[n][m]); 
	
	return 0;
}

int main() //��ά�Ż���
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]); //����ÿ����Ʒ����

	for (int i = 1; i <= n; i++) //ѭ������n����Ʒ
		for (int j = 0; j <= m; j++) //ѭ�����Ǳ�������
		{
			f[i][j] = f[i - 1][j]; //û��ѡ���i����Ʒ�����
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]); //�Ż���ѡ���i����Ʒ�����
		}

	printf("������������%dʱ����ֵ��%d��\n", m, f[n][m]);

	return 0;
}

int main() //һά�Ż��� ����01��������
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) scanf_s("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= n; i++) 
		for (int j = v[i]; j <= m; j++) 
			F[j] = max(F[j], F[j - v[i]] + w[i]); 
	

	printf("������������%dʱ����ֵ��%d��\n", m, F[m]);

	return 0;
}

//��ȫ�������� (DP��̬�滮)
//����n����Ʒ�ͱ�������m
//��������ÿ����Ʒ������
//��������ܼ�ֵ
//�����Ż������01��������ֻ���һ��ѭ��˳��