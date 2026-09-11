#include <iostream>
using namespace std;
void nhap(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap phan tu thu " << i+1 << ": ";
		cin >> a[i];
	}
}
void sx(int *a, int n)
{
	int p, i, x;
	for(i=1;i<n;i++)
	{
		x = a[i];
		p = i-1;
		while((p>=0)&&(a[p]>x))
		{
			a[p+1] = a[p];
			p--;
		}
		a[p+1] = x;
	}
}
void hienthi(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << a[i] << "\t";
	}
}
int main()
{
	int n;
	do
	{
		cout << "Nhap so phan tu mang: ";
		cin >> n;
	}
	while(n<=0);
	cin.ignore();
	
	int *a = new int[n];
	
	nhap(a, n);
	sx(a, n);
	cout << "Mang sau sap xep: \n";
	hienthi(a, n);
	return 0;
}
