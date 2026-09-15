#include<iostream>
using namespace std;

void nhap(float *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap phan tu " << i+1 << ": ";
		cin >> a[i];
	}
}

void hienthi(float *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool kiemtra(float *a, int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(a[i] > a[i+1])
		{
			return false;
		}
	}
	
	return true;
}

void sx(float *a, int l, int r)
{
	int i, j;
	float x, tg;
	
	i = l;
	j = r;
	x = a[(l+r)/2];
	
	while(i <= j)
	{
		while(a[i] < x)
			i++;
		
		while(a[j] > x)
			j--;
		
		if(i <= j)
		{
			tg = a[i];
			a[i] = a[j];
			a[j] = tg;
			
			i++;
			j--;
		}
	}
	
	if(l < j)
		sx(a, l, j);
	
	if(i < r)
		sx(a, i, r);
}

void timkiem(float *a, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r) / 2;
		
		if(a[m] == x)
		{
			int i = m;
			
			while(i>=0 && a[i] == x)
			{
				i--;
			}
			
			i++;
			
			while(i<n && a[i] == x)
			{
				cout << a[i] << " ";
				found = true;
				i++;
			}
			
			cout << endl;
			break;
		}
		else if(a[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	
	if(!found)
	{
		cout << "Khong tim thay so thuc bang " << x << endl;
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
	
	float *a = new float[n];
	
	nhap(a, n);
	
	cout << "\nMang vua nhap: ";
	hienthi(a, n);
	
	if(kiemtra(a, n))
	{
		cout << "Mang da duoc sap xep tang dan." << endl;
	}
	else
	{
		cout << "Mang chua duoc sap xep tang dan." << endl;
		
		sx(a, 0, n-1);
		
		cout << "Mang sau khi sap xep: ";
		hienthi(a, n);
	}
	
	float x;
	cout << "\nNhap so thuc X muon tim: ";
	cin >> x;
	
	cout << "Cac so thuc bang " << x << ": ";
	timkiem(a, n, x);
	
	return 0;
}
