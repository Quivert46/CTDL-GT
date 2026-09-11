#include <iostream>
using namespace std;
struct hh
{
	char ma[10];
	char ten[50];
	char ngayxh[20];
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
		
		cout << "Nhap ngay xuat hang: ";
		cin.getline(a[i].ngayxh, 20);
		
		cout << "Nhap gia xuat: ";
		cin >> a[i].gia;
		cin.ignore();
	}
}

void hienthi(hh *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma hang hoa: " << a[i].ma << endl;
		cout << "Ten hang hoa: " << a[i].ten << endl;
		cout << "Ngay xuat hang: " << a[i].ngayxh << endl;
		cout << "Gia xuat: " << a[i].gia << endl;
	}
}

void sx(hh *a, int n)
{
	int p, i;
	float x; 
	for(i=1;i<n;i++)
	{
		x = a[i].gia;
		p = i-1;
		while((p>=0)&&(a[p].gia>x))
		{
			a[p+1] = a[p];
			p--;
		}
		a[p+1].gia = x;
	}
}

void timkiem(hh *a, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r)/2;
		
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
				cout << "Ma hang hoa: " << a[i].ma << endl;
				cout << "Ten hang hoa: " << a[i].ten << endl;
				cout << "Ngay xuat hang: " << a[i].ngayxh << endl;
				cout << "Gia xuat: " << a[i].gia << endl;
				
				found = true;
				i++;
			}
			
			break;
		}
		else if(a[m].gia < x)
			l = m+1;
		else
			r = m-1;
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
	
	cout << "Danh sach vua nhap: \n";
	hienthi(a, n);
	
	sx(a, n);
	
	cout << "Danh sach sau sx: \n";
	hienthi(a, n);
	
	float x;
	cout << "Nhap gia hang hoa can tim: ";
	cin >> x;
	
	cout << "Danh sach hang hoa co gia = " << x << endl;
	timkiem(a, n, x);;
	
	return 0;
}
