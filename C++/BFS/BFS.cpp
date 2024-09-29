#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int m, n;
PII queue[N * N]; //�洢������Ķ�Ԫ������
int lab[N][N]; //�洢�������Թ�

int d[N][N]; //�洢����ÿ��������Ҫ�ߵĲ���

void BFS()
{
	memset(d, -1, sizeof d); //��ʼ���������ľ���Ϊ-1
	
	int hh = 0; //��ͷ
	int tt = 0; //��β
	
	queue[0] = { 0,0 }; //������������
	
	d[0][0] = 0; //��ʼ����㵽������̾���
	
	int dx[4] = { -1,0,1,0 }; //�ĸ�����Ĳ�����
	int dy[4] = { 0,1,0,-1 }; //�ĸ�����Ĳ�����
	
	while (hh <= tt) //�����д��ڲ�����
	{
		auto t = queue[hh++]; //ȡ����ͷ�������ҳ���
		
		for (int i = 0; i < 4; i++) //��չȡ���Ĳ�����
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			
			if (x >= 0 && x < m && y >= 0 && y < n && lab[x][y] == 0 && d[x][y] == -1) //������µ�����(������Ŀ�ı�)
			{
				d[x][y] = d[t.first][t.second] + 1; //���¾���
				queue[++tt] = { x,y }; //��չ���²��������
			}
		}
	}
}

int main()
{
	scanf_s("%d%d", &m, &n);
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &lab[i][j]); //�����Թ�
	
	BFS(); //������ȱ���
	
	printf("��������Թ�ԭ��:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d ", lab[i][j]);
		printf("\n");
	} 

	if (d[m - 1][n - 1] == -1) //�����ڵ����յ��·��
	{
		printf("�޷������յ�(%d,%d)��\n", n, m);
		printf("�Թ�������\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%4d ", d[i][j]);
			printf("\n");
		}
	}
	
	else
	{
		printf("�����յ�(%d,%d)����Ҫ��%d����\n", n, m, d[m - 1][n - 1]);
		printf("·��������\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%4d ", d[i][j]);
			printf("\n");
		}
	} //��ӡ
	
	return 0;
}

//������ȱ���
//�����Թ���(ÿ����֮���Ȩֵ��Ҫ��ͬ)
//���峤�������Թ���ģ�ͣ�1Ϊǽ����ͨ����0Ϊ·����ͨ��
//������ӣ�0,0�����m��n�����ٵĲ���


//    ������ȱ���ģ�棺    //
//                          //
//    ���                  //  
//    while(hh<=tt)         //
//    {                     //
//	    ȡ��ͷ              //
//      ��չ��ͷ(����)      //
//      ������չ��Ľڵ�    //
//    }                     //
