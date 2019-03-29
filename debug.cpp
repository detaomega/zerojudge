#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define de(x) cout<<#x<<" "<<x<<"\n";
using namespace std;
const int maxn=1e5+5;
//////////////////////////// using segment ////////////////////////
int seg[maxn*8];
void modify(int a,int add,int l,int r,int node){
	if(l==a&&r==a) seg[node]=add;
	else{
		int m=(l+r)>>1;
		if(a<=m) modify(a,add,l  ,m,node*2  );
		if(a> m) modify(a,add,m+1,r,node*2+1);
		seg[node]=seg[node*2]+seg[node*2+1];
	}
}
int query(int a,int b,int l,int r,int node){
	if(a<=l&&r<=b) return seg[node];
	else{
		int m=(l+r)>>1,ret=0;
		if(a<=m) ret+=query(a,b,l  ,m,node*2  );
		if(a> m) ret+=query(a,b,m+1,r,node*2+1);
		return ret;
	}
}
int ance[maxn][30],depth[maxn],idx[maxn][3],_t=1,num[maxn];//////////1 -> up 2 -> down;
int n,m,start;
struct edge{
	int id,u,w;
};
vector<edge> G[maxn];
void dfs(int now,int fa){
	depth[now]=depth[fa]+1;
	ance[now][0]=fa;
	num[now]=_t;
	for(int i=1;i<=__lg(n);i++) ance[now][i]=ance[ance[now-1][i-1]][i-1];
	for(int i=0;i<G[now].size();i++){
		edge k=G[now][i];
		if(k.u==fa) continue;
		modify(_t,k.w,1,n*2,1); 
		idx[k.id][1]=_t++;
		dfs(k.u,now);
		modify(_t,-k.w,1,n*2,1); 
		idx[k.id][2]=_t++;

	}
}
#define lowbit(x) (x)&(-x)
int lca(int u,int v){
		if(depth[u]>depth[v]) swap(u,v);
		int diff=depth[v]-depth[u];
		while(diff){
			int k=__lg(lowbit(diff));
			v=ance[v][k];
			diff-=lowbit(diff);
		}
		if(u==v) return u;
		for(int i=__lg(n);i>=0;i--){
			if(ance[u][i]!=ance[v][i]){
				u=ance[u][i];
				v=ance[v][i];
			}
		}
		return ance[v][0];
		
}
void solve(int v,int u){
	int LCA=lca(v,u);
//	de(LCA);
	long long cnt=0;
	if(LCA!=v)
	cnt+=query(num[LCA],num[v]-1,1,n*2-2,1);
	if(LCA!=u)
	cnt+=query(num[LCA],num[u]-1,1,n*2-2,1);
	cout<<cnt<<'\n';
}
int main(){
//	freopen("std.in","r",stdin);
//	freopen("ans1.out","w",stdout);
	cin>>n>>m>>start;
	for(int i=1;i<n;i++){
		int v,u,x;
		cin>>v>>u>>x;
		G[v].push_back({i,u,x});
		G[u].push_back({i,v,x});
	}
	de("fuck")
	dfs(1,0);
/*	10 10 1
10 8 28360
9 2 25018
8 6 13464
7 9 22445
6 1 25846
2 8 20243
7 8 14668
8 3 21606
4 1 27053
0 6
0 10
1 4 14919
1 4 4456
1 3 29808
0 1
1 1 8890
1 5 32091
0 6
0 3*/
		de("fuck")
	for(int i=1;i<n;i++){
		int a=idx[i][1],b=idx[i][2];
			de(a)de(b)
	}
	while(m--){
		int k;
		cin>>k;
		if(k){
			int u,w;
			cin>>u>>w;
			/*int a=idx[u][1],b=idx[u][2];
			de(a)de(b)
			modify(a,w,1,n*2-2,1);
			modify(b,-w,1,n*2-2,1);*/
		}
		else{
			int u;
			cin>>u;
			/*solve(start,u);
			start=u;*/
		}
	}
}
	////////////////////////////////////////
  #include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int p[maxn];
int n=5;
void init(int n){
	for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x){
	return p[x]==x? x: p[x]=find(p[x]);
}
int  merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(x!=y){
		int w=rand();
		cout<<x<<" "<<y<<" "<<w<<"\n";	
		p[a]=b;
		return 1;
	}

	return 0;
}
int main(){
	freopen("std.in","w",stdout);
	srand(time(NULL));
	init(n);
	int start=1,m=10;
	cout<<n<<" "<<m<<" "<<start<<"\n";
	for(int i=1;i<n;i++){
		int u=rand()%n+1;
		int v=rand()%n+1;
		while(merge(u,v)==0){	
		u=rand()%n+1;
		v=rand()%n+1;
		} 
	}
	while(m--){
		int is=rand()%2;
		if(is){
			int id=rand()%(n-1)+1;
			int w=rand();
			cout<<is<<" "<<id<<" "<<w<<"\n";
		}
		else{
			int go=rand()%n+1;
			while(go==start){
				go=rand()%n+1;
			}cout<<is<<" "<<go<<"\n";start=go;
		}
		
	}
}
	
