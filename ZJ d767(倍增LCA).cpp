#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
const int maxn=3e4+5;
vector<int> v[maxn];
int dep[maxn],pra[maxn][30],n;
void dfs(int p,int fa){
	dep[p]=dep[fa]+1;
	pra[p][0]=fa;
	for(int i=1;i<=__lg(n);i++){
		pra[p][i]=pra[pra[p][i-1]][i-1];
	}
	for(int k:v[p]){
		if(k!=fa)
			dfs(k,p);
	} 
}
#define lowbit(i) ((i)&-(i))
int lca(int a,int b)
{
    if(dep[a]>dep[b])
		swap(a,b);
	int diff=dep[b]-dep[a];
    while(diff){
    	int i=__lg(lowbit(diff));
    	b=pra[b][i];
    	diff-=lowbit(diff); 
	}
	for(int i=__lg(n);i>=0;i--){
		if(pra[a][i]!=pra[b][i]){
			a=pra[a][i];
			b=pra[b][i];
		}
	}
	if(a!=b) return pra[a][0];
	return b;
}
int main(){
	IOS
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int a;
		while(cin>>a&&a){
			v[a].push_back(i);
			v[i].push_back(a);
		}
	}	
	//memset(pra,-1,sizeof(pra));
	memset(dep,0,sizeof(dep));
	dfs(1,0);
	//cout<<"build__LCA\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=lca(x,y);
		cout<<ans<<" "<<dep[x]+dep[y]-2*dep[ans]<<"\n"
    }
}
