#include <iostream>
using namespace std;

const int N = 100;
int n; //�ʺ�����
int sum1, sum2; //��������
char g[N][N]; //��������
bool row[N], col[N], dg[N], udg[N]; //ÿ������Ĳ������� (�Խ��߲�������Ҫ����һЩ,����Խ��)

void Queue_dfs(int x, int y, int s) //xΪѭ��������,yΪѭ����������sΪ���ûʺ������
{
	if (y == n) x++, y = 0; //ѭ�������һ��ʱ

	if (x == n) //ѭ�������һ��ʱ
	{
		if (s == n) //n���ʺ��Ѿ�����
		{
			sum1++;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					printf("%c ", g[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		return;
	} //��ӡ������

	Queue_dfs(x, y + 1, s); //��ǰ�㲻�Żʺ󣬵ݹ���һ��

	if (!row[x] && !col[y] && !dg[x + y] && !udg[n - x + y]) //��ǰ�У��У��Խ��ߣ����Խ��߶������ڻʺ�
	{
		g[x][y] = 'Q'; //��ǰ����ûʺ�
		row[x] = col[y] = dg[x + y] = udg[n - x + y] = true; //��ǰ�У��У��Խ��ߣ����Խ��߲���ֵ��ֵΪ1

		Queue_dfs(x, y + 1, s + 1); //�ݹ���һ�񣬻ʺ�����1

		row[x] = col[y] = dg[x + y] = udg[n - x + y] = false; //��ǰ�У��У��Խ��ߣ����Խ��߲���ֵ��ֵΪ0 (�ָ��ֳ�)
		g[x][y] = 'o'; //��ǰ��ȡ���ʺ� (�ָ��ֳ�)
	}
}


void Queue_Dfs(int u) //uΪѭ��������
{
	if (u == n) //ÿһ�лʺ�������
	{
		sum2++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%c ", g[i][j]);
			printf("\n");
		}
		printf("\n");
		return;
	} //��ӡ������

	for (int i = 0; i < n; i++) //ѭ�����ǻʺ���õ�����
	{
		if (!col[i] && !dg[u + i] && !udg[n - u + i]) //��ǰ�У��Խ��ߣ����Խ��߶������ڻʺ�
		{
			g[u][i] = 'Q'; //��ǰ����ûʺ�
			col[i] = dg[u + i] = udg[n - u + i] = true; //��ǰ�У��Խ��ߣ����Խ��߲���ֵ��ֵΪ1

			Queue_Dfs(u + 1); //�ݹ���һ��

			col[i] = dg[u + i] = udg[n - u + i] = false; //��ǰ�У��Խ��ߣ����Խ��߲���ֵ��ֵΪ0 (�ָ��ֳ�)
			g[u][i] = 'o'; //��ǰ��ȡ���ʺ� (�ָ��ֳ�)
		}
	}
}

int main()
{
	scanf_s("%d", &n); //����ʺ�����

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = 'o'; //��ʼ������

	
	Queue_dfs(0, 0, 0); //�������Ѻ���
	printf("%d�ʺ�����з�����%d��\n", n, sum1);
	
	printf("- - - - - - - - - - - - - - \n"); //�ֽ���
	
	Queue_Dfs(0); //�������Ѻ���
	printf("%d�ʺ�����з�����%d��\n", n, sum2);
	return 0;
}

//n�ʺ�����(DFS)
//����n���ʺ�
//��ӡ�ʺ�λ�ú����нⷨ