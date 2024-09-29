#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL; //定义为2^64,方便取模操作
const ULL N = 10010;
ULL p[N]; //存的为p的[i]次方
ULL s[N]; //前缀和数组
string str; //初始字符串
int n; //字符串长度

void inithash()
{
	p[0] = 1; 
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] * 131; //p的值一般定义为131，1313，13131
} //初始化p数组

void initHash()
{
	s[0] = str[0];
	for (int i = 1; i < n; i++)
		s[i] = s[i - 1] * 131 + str[i];
} //初始化s数组

bool cmp(int l, int r,int ll,int rr)
{
	//ULL a = s[rr] - s[ll - 1] * p[rr - ll + 1];
	//ULL b = s[r] - s[l - 1] * p[r - l + 1];
	//cout << a << ' ' << b << endl;
	if (s[rr] - s[ll - 1] * p[rr - ll + 1] == (s[r] - s[l - 1] * p[r - l + 1])) //两个片段的数值对比，要保证最大数量级相同
		return true;
	else return false;
}

int main()
{
	getline(cin, str); //读入字符串
	n = str.length(); //获得字符串长度
	
	inithash();
	initHash();
	
	int l, r, ll, rr;
	scanf_s("%d%d%d%d", &l, &r, &ll, &rr);
	
	if (cmp(l, r, ll, rr)) printf("相同!");
	else printf("不同!");
	
	return 0;
}

//字符串哈希
//1.输入一个字符串
//2.给出需要对比的子串下标
//3.返回是否相同