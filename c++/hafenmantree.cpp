#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int data;
	int parent,lchild,rchild;
}HTNode,*Huffmantree;
typedef char **HuffmanCode;
void select(Huffmantree &ht,int n,int s1,int s2){
	int min1=INT_MAX;
	int min2=INT_MAX;
	for(int i=1;i<=n;i++){
		if(ht[i].parent==0){
			if(ht[i].data<min1){
				min2=min1;
				s2=s1;
				min1=ht[i].data;
				s1=i;
			}else if(ht[i].data<min2){
				min2=ht[i].data;
				s2=i;
			}
		}
	}
}
void CreateHuffmantree(Huffmantree &ht,int n){
	if(n<=1) return;
	int m=2*n-1;
	ht =  new HTNode[m+1];
	for(int i=1;i<=m;i++){
		ht[i].lchild=0;ht[i].rchild=0;
		ht[i].parent=0;
	}
	for(int i=1;i<=n;i++){ 
		cin >> ht[i].data;
	}
	for(int i=n+1;i<=m;i++){
		int s1,s2;
		select(ht,i-1,s1,s2);
		ht[s1].parent=i;
		
		ht[s2].parent=i;
		
		ht[i].data=ht[s1].data+ht[s2].data;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
	}
}
void CreatHuffmantreeCode(Huffmantree HT,HuffmanCode &HC,int n){  //哈夫曼编码
	HC = new char*[n+1];
    char *cd=new char[n];
	cd[n-1]='\0';
	for(int i=1;i<=n;i++){
		int start = n - 1;
		int c=i;
	    int f=HT[i].parent;
		while(f!=0){
			start--;
			if(HT[f].lchild==c) cd[start]='0';
			else cd[start]='1';
			c=f;
			f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]); //HC[i]存了每个不同字符的编码
	}
	delete cd;
}
int sum=0;
void jisuanhafu(Huffmantree H,int n){
	for(int i=n+1;i<=2*n-1;i++){
		sum+=H[i].data;
	}
}
int main(){
	int n;
	cin >> n;
	Huffmantree H=NULL;
	CreateHuffmantree(H,n);
    jisuanhafu(H,n);
	cout << sum;
	return 0;
}