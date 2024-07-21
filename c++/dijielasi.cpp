#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(100,vector<int>(100,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> v[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==0) v[i][j]=1e8;
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(v[i][j]>v[i][k]+v[k][j]){
                    v[i][j]=v[i][k]+v[k][j];
                }
        }
    for(int i=1;i<=n;i++){
        if(i!=m){
        if(v[m][i]!=1e8){
        cout << v[m][i] << " ";
     }else{
        cout << "-1" << " ";
     }   
    }   
    }
}