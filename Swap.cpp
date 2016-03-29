#include <iostream>
using namespace std;

void Swap(int* a,int*b)
{
	int temp=0;
	int *tmp=&temp;
	*tmp=*a;
	*a=*b;
	*b=*tmp;	
}
int main()
{
	int a=12;
	int*p =&a;
	int b=10;
	int*q =&b;
	cout << "p" <<*p <<"y q:  "<<*q<<endl;
	swap(p,q);
	cout << "p" <<*p <<"y q:  "<<*q<<endl;
	return 0;
}
