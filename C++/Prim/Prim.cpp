#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 500, INF = 0x3f3f3f3f; //�������ֵ
int m, n; //mΪ��������nΪ�������
int g[N][N]; //�洢ÿ����֮��ľ���
int dist[N]; //ÿ���㵽��ͨ���ϵľ���
bool st[N]; //�ж�ÿ�����Ƿ���뼯��

int Prim()
{
	int res = 0; //���ϳ��ȳ�ʼ��
	
	memset(dist, 0x3f, sizeof dist); //��ʼ��ÿ���㵽��ͨ���ϵľ���
	
	for (int i = 0; i < n; i++) //ѭ������n�ε�
	{
		int k = -1; //��¼��ǰ������Ǽ��ŵ�
		
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (k == -1 || dist[j] < dist[k]))
				k = j;
		} //ѭ��ѡ��һ�����뼯������ĵ�
		
		if (i && dist[k] == INF) return INF; //������ǵ�һ������Ҿ����������˵������ͨ
		
		if (i) res += dist[k]; //������ǵ�һ��������¼��ϳ���
		
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], g[j][k]); //����ÿ���㵽���ϵľ���
		
		st[k] = true; //���µ�k��״̬
	}
	return res; //���ؼ��ϳ���
}

int main()
{
	memset(g, 0x3f, sizeof g); //��ʼ��ÿ����֮��ľ���
	
	scanf_s("%d%d", &m, &n);
	while (m--)
	{
		int a, b, c;
		scanf_s("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	} //��ʼ��������״̬(�ڽӾ���)
	
	int t = Prim();

	if (t == INF)
	{
		printf("������%d����", n);
		printf("����ͨ!\n");
	}
	else
	{
		printf("������%d�����", n);
		printf("��С����������Ȩֵ��%d��\n", t);
	}
	return 0;
}

//Prim�㷨����С������(����ͼ)(����ͼ)
//����m��������n���ڵ���
//ÿ�θ���������֮���Ȩֵ
//�����С����������Ȩֵ