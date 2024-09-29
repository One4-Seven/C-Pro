#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int p[N]; //���鼯
int m, n; //m�β�����n����

struct Graph
{
	int a, b, w;
	
	bool operator< (const Graph &XYN)const
	{
		return w < XYN.w;
	} //����С�ں�

}graphs[N]; //����ṹ������

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
} //���鼯��find����

int main()
{
	scanf_s("%d%d", &m, &n);

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf_s("%d%d%d", &a, &b, &w);
		graphs[i] = { a,b,w };
	} //��ʼ���ṹ������(�ṹ�巨)

	sort(graphs, graphs + m); //�Խṹ�������������(��С����)

	for (int i = 1; i <= n; i++) p[i] = i; //��ʼ�����鼯����

	int res = 0; //��ʼ����Ȩֵ
	int cnt = 0; //��ʼ���ܱ���

	for (int i = 0; i < m; i++) //��Ȩֵ��С�ı߿�ʼ����
	{
		int a = graphs[i].a;
		int b = graphs[i].b;
		int w = graphs[i].w;

		a = find(a); //a�ڵ�ĸ��ڵ�
		b = find(b); //b�ڵ�ĸ��ڵ�

		if (a != b) //���a��b����ͨ
		{
			p[a] = b; //��a�ڵ����b�ڵ���
			res += w; //������Ȩֵ
			cnt++; //�����ܱ���
		}
	}

	if (cnt < n - 1) //�����������˵���������� ����ͨ
	{
		printf("������%d����", n); 
		printf("����ͨ!\n");
	}
	
	else
	{
		printf("������%d�����", n);
		printf("��С����������Ȩֵ��%d��\n", res);
	}
	
	return 0;
}

//Kruskal�㷨����С������(����ͼ)(ϡ��ͼ)
//����m��������n���ڵ���
//ÿ�θ���������ͱߵ�Ȩֵ
//�����С����������Ȩֵ
