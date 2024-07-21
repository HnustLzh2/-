#include <bits/stdc++.h>
using namespace std;
int ans;
int c = 1;
int t;
struct Edge
{
    int head;
    int tail;
    int weight;
} E[100];
int parent[100];
void sort(Edge E[])
{
    for (int i = 1; i <= c - 1; i++)
    {
        for (int j = 1; j <= c - i - 1; j++)
        {
            if (E[j].weight > E[j + 1].weight)
            {
                Edge x;
                x = E[j];
                E[j] = E[j + 1];
                E[j + 1] = x;
            }
        }
    }
}
void lowertree(vector<vector<int>> v)
{
    sort(E);
    for (int i = 1; i <= t; i++)
        parent[i] = i;

    for (int i = 1; i < c; i++)
    {
        int v1 = E[i].head;
        int v2 = E[i].tail;
        int vs1 = parent[v1], vs2 = parent[v2];
        if (vs1 != vs2)
        {
            for (int j = 1; j <= t; j++)
            {
                if (parent[j] == vs2)
                    parent[j] = vs1;
            }
            ans += E[i].weight;
        }
    }
    cout << ans;
}
int main()
{
    cin >> t;
    vector<vector<int>> v(100, vector<int>(100, 0));
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            cin >> v[i][j];
            if (v[i][j] != 0)
            {
                E[c].head = i, E[c].tail = j, E[c].weight = v[i][j]; // c表示E的长度+1;
            }
            c++;
        }
    }
    lowertree(v);
}