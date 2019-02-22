#include <bits/stdc++.h>
#define lson (node<<1),(l),(l+r)>>1
#define rson (node<<1)|1,((l+r)>>1)+1,r
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
const int maxn=3e5+5;
typedef long long ll;
ll sum[maxn*4];
bool tag[maxn*4]={};
void push(int node){
	sum[node]=sum[node*2]+sum[node*2+1];
	tag[node]=(tag[node*2]&tag[node*2+1]);
}
void build(int node,int l,int r){
	if(l==r){
		cin>>sum[node];
		if(sum[node]<=1) 
			tag[node]=1; 
		return;
	}
	else{
		build(lson);
		build(rson);
		push(node);
	}
}
void modify(int a,int b,int node,int l,int r){
	if(tag[node]) return;
	if(l==r){
		sum[node]=sqrt(sum[node]);
		if(sum[node]<=1)
			tag[node]=1;
	}
	else{
		int mid=(l+r)/2;
		if(a<=mid) modify(a,b,lson);
		if(b>mid) modify(a,b,rson);
		push(node); 
	}
}
ll query(int a,int b,int node,int l,int r){
	if(a<=l&&r<=b) return sum[node];
	ll ret=0,mid=(l+r)/2;
	if(a<=mid) ret+=query(a,b,lson);
	if(b>mid)  ret+=query(a,b,rson);
	return ret;
}
int main(){
	IOS
	int n,m;
	cin>>n>>m;
	build(1,1,n);
	while(m--){
		int x,a,b;
		cin>>x>>a>>b;
		if(x){
			modify(a,b,1,1,n);
		}
		else{
			cout<<query(a,b,1,1,n)<<"\n";
		}
	}
}

