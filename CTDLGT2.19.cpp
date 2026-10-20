#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;

const int MAX = 100;

void Nhap(int A[][MAX], int &n)
{
    ifstream f("Grap2.txt");

    if(!f)
    {
        cout << "Khong mo duoc tep Grap2.txt!";
        n = 0;
        return;
    }

    f >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            f >> A[i][j];
        }
    }

    f.close();
}

void HienThi(int A[][MAX], int n)
{
    cout << "  ";

    for(int i = 0; i < n; i++)
        cout << char('A' + i) << " ";

    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << char('A' + i) << " ";

        for(int j = 0; j < n; j++)
            cout << A[i][j] << " ";

        cout << endl;
    }
}

void BFS(int A[][MAX], int n, int u, int v)
{
    int Q[MAX];          
    int truoc[MAX];     
    bool visited[MAX];   

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        truoc[i] = -1;
    }

    int dau = 0, cuoi = 0;

    Q[cuoi++] = u;
    visited[u] = true;

    while(dau < cuoi)
    {
        int x = Q[dau++];

        if(x == v)
            break;

        for(int y = 0; y < n; y++)
        {
            if(A[x][y] == 1 && !visited[y])
            {
                visited[y] = true;
                truoc[y] = x;
                Q[cuoi++] = y;
            }
        }
    }

    if(!visited[v])
    {
        cout << "Khong co duong di tu "
             << char('A' + u) << " den "
             << char('A' + v) << endl;
        return;
    }

    int duongdi[MAX];
    int dem = 0;
    int x = v;

    while(x != -1)
    {
        duongdi[dem++] = x;
        x = truoc[x];
    }

    cout << "Duong di ngan nhat: ";

    for(int i = dem - 1; i >= 0; i--)
    {
        cout << char('A' + duongdi[i]);

        if(i > 0)
            cout << " -> ";
    }

    cout << endl;
    cout << "So canh cua duong di: " << dem - 1 << endl;
}

int main()
{
    int A[MAX][MAX];
    int n;

    Nhap(A, n);

    if(n <= 0 || n > MAX)
        return 0;

    cout << "Ma tran ke cua do thi G:" << endl;
    HienThi(A, n);

    cout << endl;
    BFS(A, n, 0, 7);  

    return 0;
}

