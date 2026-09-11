#include<iostream>
using namespace std;

struct kh
{
	int ma;
	char ten[50];
	char sdt[20];
	float tongtien;
};

void nhap(kh *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Nhap thong tin khach hang " << i+1 << endl;
		
		cout << "Nhap ma khach hang: ";
		cin >> a[i].ma;
		cin.ignore();
		
		cout << "Nhap ten khach hang: ";
		cin.getline(a[i].ten, 50);
		
		cout << "Nhap so dien thoai: ";
		cin.getline(a[i].sdt, 20);
		
		cout << "Nhap tong tien thanh toan: ";
		cin >> a[i].tongtien;
		cin.ignore();
	}
}

void hienthi(kh *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << "Ma KH: " << a[i].ma << endl;
		cout << "Ten KH: " << a[i].ten << endl;
		cout << "So dien thoai: " << a[i].sdt << endl;
		cout << "Tong tien thanh toan: " << a[i].tongtien << endl;
	}
}

void sx(kh *a, int n)
{
	int i, j;
	kh tg;
	
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j].tongtien < a[j-1].tongtien)
			{
				tg = a[j];
				a[j] = a[j-1];
				a[j-1] = tg;
			}
		}
	}
}

void timkiem(kh *a, int n, float x)
{
	int l = 0;
	int r = n-1;
	bool found = false;
	
	while(l <= r)
	{
		int m = (l+r) / 2;
		
		if(a[m].tongtien == x)
		{
			int i = m;
			
			while(i>=0 && a[i].tongtien == x)
			{
				i--;
			}
			
			i++;
			
			while(i<n && a[i].tongtien == x)
			{
				cout << "Ma KH: " << a[i].ma << endl;
				cout << "Ten KH: " << a[i].ten << endl;
				cout << "So dien thoai: " << a[i].sdt << endl;
				cout << "Tong tien thanh toan: " << a[i].tongtien << endl;
				
				found = true;
				i++;
			}
			
			break;
		}
		else if(a[m].tongtien < x)
			l = m + 1;
		else
			r = m - 1;
	}
	
	if(!found)
	{
		cout << "Khong tim thay khach hang co tong tien thanh toan = " << x << endl;
	}
}

int main()
{
	int n;
	do
	{
		cout << "Nhap so khach hang: ";
		cin >> n;
	}
	while(n<=0);
	
	cin.ignore();
	
	kh *a = new kh[n];
	
	nhap(a, n);
	
	cout << "\nDanh sach khach hang: \n";
	hienthi(a, n);
	
	sx(a, n);
	
	cout << "\nDanh sach sau sap xep: \n";
	hienthi(a, n);
	
	float x;
	cout << "\nNhap tong tien thanh toan muon tim: ";
	cin >> x;
	
	cout << "\nDanh sach khach hang co tong tien thanh toan " << x << endl;
	timkiem(a, n, x);
	
	return 0;
}
