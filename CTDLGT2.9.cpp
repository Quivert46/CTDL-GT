#include<iostream>
using namespace std;
struct hh
{
	char ma[10];
	char ten[50];
	char ngay[20];
	float gia;
};

void nhap(hh *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap thong tin hang hoa " << i+1 << endl;
		cout << "Nhap ma hang hoa: ";
		cin.getline(a[i].ma, 10);
		
		cout << "Nhap ten hang hoa: ";
		cin.getline(a[i].ten, 50);
		
		cout << "Nhap ngay xuat hang hoa: ";
		cin.getline(a[i].ngay, 20);
		
		cout << "Nhap gia xuat hang hoa: ";
		cin >> a[i].gia;
		cin.ignore();
	}
}

void hienthi(hh *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma HH: " << a[i].ma << endl;
		cout << "Ten HH: " << a[i].ten << endl;
		cout << "Ngay xuat: " << a[i].ngay << endl;
		cout << "Gia xuat: " << a[i].gia << endl;
	}
}

void sx(hh *a, int n)
{
	int i, j, tg;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j<i;j++)
		if(a[j].gia < a[j-1].gia)
		{
			tg = a[j].gia;
			a[j] = a[j-1];
			a[j-1].gia = tg;
		}
	}
}

void timkiem(hh *a, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r) / 2;
		
		if(a[m].gia == x)
		{
			int i = m;
			
			while(i>=0 && a[i].gia == x)
			{
				i--;
			}
			
			i++;
			
			while(i<n && a[i].gia == x)
			{
				cout << "Ma HH: " << a[i].ma << endl;
				cout << "Ten HH: " << a[i].ten << endl;
				cout << "Ngay xuat: " << a[i].ngay << endl;
				cout << "Gia xuat: " << a[i].gia << endl;
				
				found = true;
				i++;
			}
			
			break;
		}
		else if(a[m].gia < x)
			l = m + 1;
		else
			r = m - 1;
	}
	if(!found)
	{
		cout << "Khong tim thay hang hoa co gia = " << x << endl;
	}
}

int main()
{
	int n;
	do
	{
		cout << "Nhap so hang hoa: ";
		cin >> n;
	}
	while(n<=0);
	cin.ignore();
	
	hh *a = new hh[n];
	
	nhap(a, n);
	cout << "Danh sach hang hoa: \n";
	hienthi(a, n);
	sx(a, n);
	cout << "Danh sach sau sap xep: \n";
	hienthi(a, n);
	
	float x;
	cout << "Nhap gia xuat muon tim: ";
	cin >> x;
	
	cout << "Danh sach hang hoa co gia xuat " << x << endl;
	timkiem(a, n, x);
	
	return 0;
}
