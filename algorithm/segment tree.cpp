#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
const int maxn=5e5+5;
ll seg[maxn*4],tag[maxn*4];
void build(int l,int r,int node){
	if(l==r){
		cin>>seg[node];
		tag[node]=0;
		return;
	}
	int m=(l+r)>>1;
	build(l , m ,(node<<1)  );
	build(m+1 , r ,(node<<1)+1);
	seg[node]=seg[(node<<1)]+seg[(node<<1)+1];
	tag[node]=0;
} 
void push(int node,int add){
	if(tag[node]){
		tag[(node<<1)]+=tag[node];
		tag[(node<<1)+1]+=tag[node];
		seg[(node<<1)]+=tag[node]*(add-(add>>1));
		seg[(node<<1)+1]+=tag[node]*(add>>1);
		tag[node]=0;
	}
}
void modify(int l,int r,int node,int a,int b,int add){
	if(a<=l&&r<=b){
		tag[node]+=add;
		seg[node]+=add*(r-l+1);
		return ;
	}
	int m=(l+r)>>1; 
	push(node,r-l+1);
	if(a<=m) modify(l ,m ,(node<<1),a,b,add);
	if(b>m)	 modify(m+1,r,(node<<1)+1,a,b,add);
	seg[node]=seg[(node<<1)]+seg[(node<<1)+1]; 
}
ll query(int l,int r,int node,int a,int b){
	if(a<=l&&r<=b) return seg[node];
	push(node,r-l+1);
	int m=(l+r)>>1;
	ll flat=0;
	if(a<=m) flat+=query(l,m,(node<<1),a,b);
	if(b>m)  flat+=query(m+1,r,(node<<1)+1,a,b);
	return flat;
}
int main(){
	IOS
	int n;
	cin>>n;
	build(1,n,1);
	int m;
	cin>>m;
	while(m--){
		int s,a,b,add;
		cin>>s;
		if(s==1){
			cin>>a>>b>>add;
			modify(1,n,1,a,b,add);
		}
		else{
			cin>>a>>b;
			cout<<query(1,n,1,a,b)<<"\n";
		}
	}
}
