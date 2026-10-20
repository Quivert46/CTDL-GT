#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

const int MAX = 100;

void Nhap(int A[][MAX], int &n)
{
    ifstream f("Grap3.txt");

    if(!f)
    {
        cout << "Khong mo duoc tep Grap3.txt!" << endl;
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

void TryDFS(int A[][MAX], int n, int u, int v,
            bool visited[], int path[], int &dem,
            int cost, int &minCost, int bestPath[],
            int &bestDem)
{
    if(u == v)
    {
        if(cost < minCost)
        {
            minCost = cost;
            bestDem = dem;

            for(int i = 0; i < dem; i++)
                bestPath[i] = path[i];
        }

        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(A[u][i] > 0 && !visited[i])
        {
            visited[i] = true;
            path[dem] = i;
            dem++;

            TryDFS(A, n, i, v, visited, path, dem,
                   cost + A[u][i], minCost, bestPath,
                   bestDem);

            dem--;
            visited[i] = false;
        }
    }
}

void DFS(int A[][MAX], int n, int u, int v)
{
    bool visited[MAX];
    int path[MAX];
    int bestPath[MAX];

    int dem = 0;
    int bestDem = 0;
    int minCost = INT_MAX;

    for(int i = 0; i < n; i++)
        visited[i] = false;

    visited[u] = true;
    path[dem++] = u;

    TryDFS(A, n, u, v, visited, path, dem,
           0, minCost, bestPath, bestDem);

    if(minCost == INT_MAX)
    {
        cout << "Khong co duong di tu "
             << char('A' + u) << " den "
             << char('A' + v) << endl;
        return;
    }

    cout << "Duong di co tong trong so nho nhat: ";

    for(int i = 0; i < bestDem; i++)
    {
        cout << char('A' + bestPath[i]);

        if(i < bestDem - 1)
            cout << " -> ";
    }

    cout << endl;
    cout << "Tong trong so nho nhat: " << minCost << endl;
}

int main()
{
    int A[MAX][MAX];
    int n;

    Nhap(A, n);

    if(n <= 0 || n > MAX)
        return 0;

    cout << "Ma tran trong so cua do thi G:" << endl;
    HienThi(A, n);

    cout << endl;

    DFS(A, n, 0, 6);

    return 0;
}

