#include <bits/stdc++.h>
using namespace std;
bool vis[100];
int n, m;
string g[100];
vector<vector<int>> v(100, vector<int>(100, 0));
int locate(string *g, int n, string s)
{
   for (int i = 0; i < n; i++)
   {
      if (s == g[i])
      {
         return i;
      }
   }
   return -1;
}
queue<string> q;
void bfs(vector<vector<int>> v, int x)
{
   q.push(g[x]);
   while (!q.empty())
   {
      string s = q.front();
      cout << s << " ";
      q.pop();
      int y = locate(g, n, s);
      vis[y] = true;
      for (int i = 0; i < n; i++)
      {
         if (v[y][i] != 0 && !vis[i])
         {
            q.push(g[i]);
            vis[i] = true;
         }
      }
   }
}
int main()
{
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      cin >> g[i];
   }
   for (int i = 0; i < m; i++)
   {
      string a, b;
      cin >> a >> b;
      int x, y;
      x = locate(g, n, a);
      y = locate(g, n, b);
      v[x][y] = 1;
      v[y][x] = 1;
   }
   bfs(v, 0);
   
} // main