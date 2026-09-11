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
	int min, i, j, tg;
	for(int i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		if(a[j]<a[min])
			min = j;
		if(min != i)
		{
			tg = a[min];
			a[min] = a[i];
			a[i] = tg;
		}
	}
}

int main()
{
	int n;
	do
	{
		cout << "Nhap so phan tu: ";
		cin >> n;
	}
	while(n<=0);
	int *a = new int[n];
	nhap(a, n);
	sx(a, n);
	cout << "Mang sau sap xep: \n";
	for(int i=0;i<n;i++)
	{
		cout << a[i] << "\t";
	}
	return 0;
}
