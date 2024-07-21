#include<bits/stdc++.h>
using namespace std;
int ans=0;
int flag;
int n,m;
int vis[8][2]={{1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1}};
int pma[8][2]={{0,1},{1,0},{0,1},{-1,0},{0,-1},{-1,0},{0,-1},{1,0}};
void bfs(string ma[],int b,int x,int y){
	queue<pair<int,int>> q;
	pair<int,int>p;
	p.first=x,p.second=y;
	q.push(p);
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nx=p.first+vis[i][0];
			int ny=p.second+vis[i][1];
			if(nx<=0||nx>n||ny<=0||ny>m){
				continue;
			}
			if(ma[nx][ny]!='#'&&ma[p.first+pma[i][0]][p.second+pma[i][1]]!='#'){
				ans++;
				q.push({nx,ny});
			}
			if(ma[nx][ny]=='z'&&ma[p.first+pma[i][0]][p.second+pma[i][1]]!='#'){
				cout << ans << "\n";
				return;
			}
		}
	}
	cout << "can not reaching!\n"; 
}
void solve(){
	cin >> n >> m;
	int x,y,x1,y1;
	cin >> x >> y >> x1 >> y1;
	int s;
	cin >> s;
	string ma[102];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ma[i][j]='*';
		}
	}
	ma[x][y]='q',ma[x1][y1]='z';
	for(int i=0;i<s;i++){
		int o,p;
		cin >> o >> p;
		ma[o][p]='#';
	}
	bfs(ma,0,x,y);
	ans=0;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	} 
}