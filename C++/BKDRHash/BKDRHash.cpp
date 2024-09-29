#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL; //����Ϊ2^64,����ȡģ����
const ULL N = 10010;
ULL p[N]; //���Ϊp��[i]�η�
ULL s[N]; //ǰ׺������
string str; //��ʼ�ַ���
int n; //�ַ�������

void inithash()
{
	p[0] = 1; 
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] * 131; //p��ֵһ�㶨��Ϊ131��1313��13131
} //��ʼ��p����

void initHash()
{
	s[0] = str[0];
	for (int i = 1; i < n; i++)
		s[i] = s[i - 1] * 131 + str[i];
} //��ʼ��s����

bool cmp(int l, int r,int ll,int rr)
{
	//ULL a = s[rr] - s[ll - 1] * p[rr - ll + 1];
	//ULL b = s[r] - s[l - 1] * p[r - l + 1];
	//cout << a << ' ' << b << endl;
	if (s[rr] - s[ll - 1] * p[rr - ll + 1] == (s[r] - s[l - 1] * p[r - l + 1])) //����Ƭ�ε���ֵ�Աȣ�Ҫ��֤�����������ͬ
		return true;
	else return false;
}

int main()
{
	getline(cin, str); //�����ַ���
	n = str.length(); //����ַ�������
	
	inithash();
	initHash();
	
	int l, r, ll, rr;
	scanf_s("%d%d%d%d", &l, &r, &ll, &rr);
	
	if (cmp(l, r, ll, rr)) printf("��ͬ!");
	else printf("��ͬ!");
	
	return 0;
}

//�ַ�����ϣ
//1.����һ���ַ���
//2.������Ҫ�Աȵ��Ӵ��±�
//3.�����Ƿ���ͬ