#include <bits/stdc++.h>
using namespace std;
typedef struct humantree{
    char s;
    int lchild,rchild,praren;
}*HT;
typedef char** HuffmanCode;
void creatHuffmanCode(HT H,HuffmanCode & Hi,int n){
    Hi = new char*[n+1];
    char *cd=new char[n];
    cd[n-1]='\0';
    for(int i=1;i<=n;i++){
        int start=n-1;
        int c=i;
        int f=H[i].praren;
        while(f!=0){
            start--;
            if(H[f].lchild==c){
                cd[start]='0';
            }else{
                cd[start]='1';
            }
            c=f;
            f=H[f].praren;
        }
        Hi[i]=new char[n-start]; //为二维数组开辟一个空间储存编码
        strcpy(Hi[i],&cd[start]); //记得加上&这是取从start开始的数组
    }
    return;
}
int main()
{
    cout << "hello world" << endl;
    return 0;
}
