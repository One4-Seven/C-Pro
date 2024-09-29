#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int s[N]; //�洢������ʮ������
int son[N][2], idx; //�洢����������ÿһλ��������

void insert(int x)
{
	int p = 0; //��ʼ��pֵ
	
	for (int i = 30; i >= 0; i--) //��������һ����30λ
	{
		int u = x >> i & 1; //����ȡ��ÿһλ�ϵ���
		if (!son[p][u]) son[p][u] = ++idx; //����ڵ㲻��������ڵ� son�д洢���Ƕ��ӽڵ��pֵ
		p = son[p][u]; //����pֵ
	}
} //�������(Trie��)

int query(int x)
{
	int p = 0, res = 0; //��ʼ�� pֵ�ʹ�
	
	for (int i = 30; i >= 0; i--) //�Ӹ�λ��ʼѭ��
	{
		int u = x >> i & 1; //����ȡ��ÿһλ�ϵ���
		
		if (son[p][!u]) //��ΪҪ���ֵ�����������ѡ��ֵͬ�Ľڵ�
		{
			p = son[p][!u]; //ȡ����һ���pֵ
			res = res * 2 + !u; //���´�
		}
		
		else //�˶������ ѡ��ֵ��ͬ�Ľڵ�
		{
			p = son[p][u]; //ȡ����һ���pֵ
			res = res * 2 + u;//���´�
		}
	}
	return res; //���ش�
} //

int main()
{
	int res = 0; //��ʼ����Ϊ0
	
	int n;
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf_s("%d", &s[i]);
	
	for (int i = 0; i < n; i++)
	{
		insert(s[i]);
		int t = query(s[i]);
		res = max(res, t ^ s[i]);
	} //ÿһ��ִ��һ�β�������Ͳ�ѯ���������Ҹ��´�Ϊ��Сֵ
	
	if (n == 0) printf("����Ϊ��!\n"); //�ж������Ƿ�Ϊ��
	else printf("������ֵΪ%d", res); //�����
	
	return 0;
}

//��������
//ʹ��Trie�������������
//����n����������������������������ֵ