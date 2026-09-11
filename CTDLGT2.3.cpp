#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

struct ds
{
	node *head;
	node *tail;
};

void taods(ds &l)
{
	l.head = l.tail = NULL;
}

node* taonode(int x) 
{
	node *p = new node;
	if(p == NULL)
	{
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void chencuoi(ds &l, node *p)
{
	if(l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void sx(ds &l)
{
	for(node *i = l.head;i != NULL;i = i->next)
	{
		node *min = i;
		for(node *j = i->next;j != NULL;j = j->next)
		if(j->data < min->data)
			min = j;
		if(min != i)
		{
			int tg = i->data;
			i->data = min->data;
			min->data = tg;
		}
	}
}

void hienthi(ds l)
{
	node *p = l.head;
	while(p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

void del(ds &l)
{
	node *p = l.head;
	while(p != NULL)
	{
		node *q = p;
		while(q->next != NULL)
		{
			if(q->next->data == p->data)
			{
				node *tg = q->next;
				q->next = tg->next;
				delete tg;
			}
			else
			{
				q = q->next;
			}
		}
		p = p->next; 
	}
}

int sum(ds l)
{
	int s = 0;
	node *p = l.head;
	while(p != NULL)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}

int main()
{
	ds l;
	taods(l);
	
	int n;
	do
	{
		cout << "Nhap so phan tu: ";
		cin >> n;
	}
	while(n<=0);
	cin.ignore();
	
	for(int i=0;i<n;i++)
	{
		int x;
		cout << "Nhap so thu " << i+1 << ": ";
		cin >> x;
		cin.ignore();
		
		node *p = taonode(x);
		chencuoi(l, p);
	}
	
	sx(l);
	cout << "Mang da nhap: \n"; 
	del(l);
	cout << "Mang da nhap sau khi xoa trung: \n";
	hienthi(l);
	
	int s = sum(l);
	cout << "Tong cac phan tu con lai: " << s << endl;
	
	return 0;
}
