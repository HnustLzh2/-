#include<bits/stdc++.h>
using namespace std;
bool vis[1000];
int trs[1000];
int g[1000][1000];
int n;
int j,ans;
bool prim(){
    for(int i=1;i<=n;i++){
        trs[i]=1e8;     
    }
    trs[1]=0;    
    for(int i=1;i<=n;i++){
       trs[i]=min(trs[i],g[1][i]);
    }
    vis[1]=true;
    for(int i=2;i<=n;i++){
        int temp=1e8;
        int k=-1;
        for(j=2;j<=n;j++){
            if(!vis[j]&&temp>trs[j]){
                temp=trs[j];
                k=j;
            }
        }
        if(k==-1) {ans=0;return false;}
        vis[j]=true;
        ans+=temp;
        for(int s=2;s<=n;s++){
           trs[s]=min(trs[s],g[k][s]);
        }
    }
    return true;
}
int main(){
    cout << 123;
}