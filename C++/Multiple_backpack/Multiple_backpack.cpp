#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10010;
int f[N][N]; //(n,m)ֻ����ǰn����Ʒ������Ϊmʱ������ֵ
int v[N]; //��Ʒ���
int w[N]; //��Ʒ��ֵ
int s[N]; //��Ʒ����
int F[N]; //һά�Ż�����

int main() //��ά���鷨
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf_s("%d%d%d", &v[i], &w[i], &s[i]); //������Ʒ����

	for (int i = 1; i <= n; i++) //ѭ������ǰn����Ʒ
		for (int j = 0; j <= m; j++) //ѭ�����Ǳ�������
			for (int k = 0; k <= s[i] && k * v[i] <= j; k++) //ѭ�����Ǽ���k��i��Ʒ
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

	printf("������������%dʱ����ֵ��%d��\n", m, f[n][m]);

	return 0;
}

int main() //һά�Ż��� & �������Ż���
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	
	int cnt = 0; //��ʼ���´������Ʒ����

	for (int i = 1; i <= n; i++) //��ÿһ����Ʒ��������ɸ�����(�������Ż���)
	{
		int a, b, s;
		scanf_s("%d%d%d", &a, &b, &s); //������Ʒ���� a��� b��ֵ s����
		
		int k = 1; //��ʼ����һ�δ��������
		
		while (k <= s) //����Ʒ����ʣ���ҹ����
		{
			cnt++; //�´����Ʒ��+1
			v[cnt] = k * a; //�˴δ�������
			w[cnt] = k * b; //�˴δ���ļ�ֵ
			s -= k; //������Ʒ����
			k *= 2; //�����´δ��������
		}
		
		if (s > 0) //�����´δ����������ʣ��
		{
			cnt++; //�´����Ʒ��+1
			v[cnt] = s * a; //�˴δ�������
			w[cnt] = s * b; //�˴δ���ļ�ֵ
		}
	}
	
	n = cnt; //��������Ʒ��Ϊ���Ǵ��������
	
	
	for (int i = 1; i <= n; i++) 
		for (int j = m; j >= v[i]; j--)
			F[j] = max(F[j], F[j - v[i]] + w[i]); 
	//������ת��Ϊ01��������(һά�Ż���)
	
	printf("������������%dʱ����ֵ��%d��\n", m, F[m]);

	return 0;
}

//���ر������� (DP��̬�滮)
//����n����Ʒ�ͱ�������m
//��������ÿ����Ʒ������
//��������ܼ�ֵ


