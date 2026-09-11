#include <iostream>
#include <string.h>
using namespace std;
struct sv
{
	char ma[15];
	char ten[50];
	float diem;
};

void nhap(sv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap sinh vien thu " << i+1 << endl;
		 
		cout << "Nhap ma SV: ";
		cin.getline(a[i].ma, 15);
		
		cout << "Nhap ten SV: ";
		cin.getline(a[i].ten, 50);
		
		cout << "Nhap diem: ";
		cin >> a[i].diem;
		cin.ignore();
	}
}

void sx(sv *a, int n)
{
	int min, i, j, tg;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		if(a[j].diem<a[min].diem)
			min = j;
		if(min != i)
		{
			tg = a[min].diem;
			a[min].diem = a[i].diem;
			a[i].diem = tg;
		}
	}
}

void hienthi(sv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma SV: " << a[i].ma << endl;
		cout << "Ten SV: " << a[i].ten << endl;
		cout << "Diem: " << a[i].diem << endl;
	}
}

int timkiem(sv *a, int n, char *c)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].ma, c)==0)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int n;
	do
	{
		cout << "Nhap so SV: ";
		cin >> n;
	}
	while(n<=0);
	cin.ignore();
	
	sv *a = new sv[n];
	
	nhap(a, n);
	sx(a, n);
	hienthi(a, n);
	
	char c[15];
	cout << "Nhap ma can tim: ";
	cin.getline(c, 15);
	
	int vt = timkiem(a, n, c);
	if(vt == -1)
	{
		cout << "Khong tim thay SV co ma " << c << endl;
	}
	else
	{
		cout << "Ma SV: " << a[vt].ma << endl;
		cout << "Ten SV: " << a[vt].ten << endl;
		cout << "Diem: " << a[vt].diem << endl;
	}
	
	return 0;
}

