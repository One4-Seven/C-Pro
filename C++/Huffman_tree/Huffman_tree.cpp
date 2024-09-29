#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n); //��ʼ�����ٶѽ��
	
	priority_queue<int, vector<int>, greater<int>> heap; //����С����
	
	while (n--)
	{
		int x;
		scanf_s("%d", &x);
		heap.push(x);
	}
	
	int res = 0; //��ʼ����Ҫ���ĵ�����
	
	while (heap.size() > 1) //�����������ѽ��
	{
		int a = heap.top();
		heap.pop();
		
		int b = heap.top();
		heap.pop();
		
		res += a + b; //��������
		
		heap.push(a + b);
	} //ÿ��ȡ��������С�Ľ�ң���Ϊһ�Ѳ��Ҳ���С������

	printf("�ᶯ���н����Ҫ����%d��������\n", res);
	
	return 0;
}

//���������㷨(̰��)
//����n�ѽ��
//����ÿ�����ĵ�����
//�ó���С��Ҫ���ĵ�����