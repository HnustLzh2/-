#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int INF=1e8;
int n,s=1;
int a[N][N],d[N];
bool used[N];
void dijkstra(){
    for(int i=1;i<=n;i++){
        d[i]=a[s][i];
        used[i]=false;
    }
    used[s]=true;
    d[s]=0;
    
    int k;
    for(int i=1;i<=n;i++){
        int min=INF;
        for(int j=1;j<=n;j++){
            if(!used[j]&&d[j]<min){
                min=d[j];
                k=j;
            }
        }
        used[k]=true;
        for(int w=1;w<=n;w++){
            int tmp;
            if(a[k][w]==INF){
                tmp=INF;
            }else{
                tmp = min+a[k][w];
            }
            if(!used[w]&&tmp<d[w]){
                d[w]=tmp;
            }
        }
    }
}

// 主函数
int main(){
    // 输入邻接矩阵a
     while(cin >> n){
        string b[n+1][n+1];
        memset(a,0,sizeof(a));
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                cin >> b[i][j];
                if(b[i][j][0]=='x'){
                    a[i][j]=INT_MAX;a[j][i]=INT_MAX;
                }else{
                    if(b[i][j].size()>1){
                        int sum=0;
                        for(int k=0;k<b[i][j].size();k++){
                            sum=sum*10+b[i][j][k]-'0';
                        }
                        a[i][j]=sum; a[j][i]=sum;
                    }else{
                    a[i][j]=b[i][j][0]-'0';
                    a[j][i]=a[i][j];
                    }     
                }          
            }
        }
        dijkstra();
        int ma=0;
        for(int i=1;i<=n;i++){
            cout << d[i] << " ";
        }
        for(int i=2;i<=n;i++){
            ma=max(ma,d[i]);
        }
        cout << ma << endl;
     }
    return 0;
}