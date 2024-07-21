#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    while(scanf("%d",&n)!=EOF){
       cin >> m;
       set<int>s;
       for(int i=0;i<n;i++){
        int x;
        cin >> x; s.insert(x);
       }
       for(int i=0;i<m;i++){
         int x;
         cin >> x;
         if(s.find(x)!=s.end()){
           cout << "yes\n";
         }else{
            cout << "no\n";
         }
       }
    }
    return 0;
}