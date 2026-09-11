#include<iostream>
using namespace std;

struct nv
{
	int ma;
	char ten[50];
	char ngaysinh[20];
	float luong;
};

void nhap(nv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap thong tin nhan vien " << i+1 << endl;
		
		cout << "Nhap ma nhan vien: ";
		cin >> a[i].ma;
		cin.ignore();
		
		cout << "Nhap ho ten: ";
		cin.getline(a[i].ten, 50);
		
		cout << "Nhap ngay sinh: ";
		cin.getline(a[i].ngaysinh, 20);
		
		cout << "Nhap luong (trieu dong): ";
		cin >> a[i].luong;
		cin.ignore();
	}
}

void hienthi(nv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma NV: " << a[i].ma << endl;
		cout << "Ho ten: " << a[i].ten << endl;
		cout << "Ngay sinh: " << a[i].ngaysinh << endl;
		cout << "Luong: " << a[i].luong << " trieu dong" << endl;
	}
}

void sx(nv *a, int n)
{
	int i, j;
	nv tg;
	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j].luong < a[j-1].luong)
			{
				tg = a[j];
				a[j] = a[j-1];
				a[j-1] = tg;
			}
		}
	}
}

void timkiem(nv *a, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r) / 2;
		
		if(a[m].luong == x)
		{
			int i = m;
			
			while(i>=0 && a[i].luong == x)
			{
				i--;
			}
			
			i++;
			
			while(i<n && a[i].luong == x)
			{
				cout << "Ma NV: " << a[i].ma << endl;
				cout << "Ho ten: " << a[i].ten << endl;
				cout << "Ngay sinh: " << a[i].ngaysinh << endl;
				cout << "Luong: " << a[i].luong << " trieu dong" << endl;
				
				found = true;
				i++;
			}
			
			break;
		}
		else if(a[m].luong < x)
			l = m + 1;
		else
			r = m - 1;
	}
	
	if(!found)
	{
		cout << "Khong tim thay nhan vien co luong = " << x << endl;
	}
}

int main()
{
	int n;
	
	do
	{
		cout << "Nhap so nhan vien: ";
		cin >> n;
	}
	while(n<=0);
	
	cin.ignore();
	
	nv *a = new nv[n];
	
	nhap(a, n);
	
	cout << "\nDanh sach nhan vien: \n";
	hienthi(a, n);
	
	sx(a, n);
	
	cout << "\nDanh sach sau sap xep: \n";
	hienthi(a, n);
	
	float x;
	cout << "\nNhap luong muon tim: ";
	cin >> x;
	
	cout << "\nDanh sach nhan vien co luong " << x << " trieu dong:" << endl;
	timkiem(a, n, x);
	
	return 0;
}
