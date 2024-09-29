#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int F[N]; //һά�Ż�����
int v[N][N]; //��N���N�ֵ����
int w[N][N]; //��N���N�ֵļ�ֵ
int s[N]; //��N�������

int main() //����ѭ�� ��ά����
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) //ѭ������n�������
	{
		scanf_s("%d", &s[i]); //�����i�������
		
		for (int j = 1; j <= s[i]; j++)
			scanf_s("%d%d", &v[i][j], &w[i][j]); //������Ʒ����
	}

	for (int i = 1; i <= n; i++) //ѭ������ǰi����Ʒ
		for (int j = m; j >= 0; j--) //ѭ�����Ǳ�������
			for (int k = 1; k <= s[i]; k++) //ѭ�����ǵ�i���ÿһ����Ʒ
				if (v[i][k] <= j) //�жϵ�i��ĵ�k����Ʒ�Ƿ����������
					F[j] = max(F[j], F[j - v[i][k]] + w[i][k]); //��������ֵ(����01��������)

	printf("������������%dʱ����ֵ��%d��\n", m, F[m]);
	
	return 0;
}

//���鱳������ (DP��̬�滮)
//����n����Ʒ�ͱ�������m
//����ÿһ����Ʒ�ж�����
//��������ÿ����Ʒ������
//��������ܼ�ֵ
//�����Ż������01������������