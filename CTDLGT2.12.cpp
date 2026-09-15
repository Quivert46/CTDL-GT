#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void nhap(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap phan tu " << i+1 << ": ";
		cin >> a[i];
	}
}

void sx(int *a, int l, int r)
{
	int i, j, x, tg;
	x = a[(l+r)/2];
	i = l;
	j = r;
	do
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			tg = a[i];
			a[i] = a[j];
			a[j] = tg;
			i++;
			j--;
		}
	}
	while(i<j);
	if(l<j)
		sx(a,l,j);
	if(i<r)
		sx(a,j,r);
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
	int l;
	int r = n - 1;
	nhap(a, n);
	cout << "Mang da nhap: \n";
	hienthi(a, n);
	sx(a, l, r);
	cout << "\nMang da sap xep: \n";
	hienthi(a, n);
	
	return 0;
}


