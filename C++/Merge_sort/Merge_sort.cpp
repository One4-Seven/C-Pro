#include <iostream>
using namespace std;

const int N = 10010;
int q[N], cmt[N]; //�洢��������� ��ʱ����

void Merge_sort(int q[], int l, int r)
{
	if (l >= r) return; //�ݹ��������
	int mid = l + r >> 1; //�����е�
	
	Merge_sort(q, l, mid); //�ݹ�
	Merge_sort(q, mid + 1, r); //�ݹ�
	
	int i = l; //��������������
	int j = mid + 1; //��������������
	int k = 0; //��ʱ���������
	
	while (i <= mid && j <= r) //���������鶼û��Ϊ��
	{
		if (q[i] < q[j]) cmt[k++] = q[i++]; //ѡ��С����������ʱ����
		else cmt[k++] = q[j++];
	}
	
	while (i <= mid) cmt[k++] = q[i++]; //��ÿ�����������������ʱ����
	while (j <= r) cmt[k++] = q[j++]; //��ÿ�����������������ʱ����
	
	for (int i = l, j = 0; i <= r; i++, j++)
		q[i] = cmt[j]; //����ʱ������������������
}

int main()
{
	int n;
	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf_s("%d", &q[i]);
	
	Merge_sort(q, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	
	return 0;
}

//�鲢����ģ��