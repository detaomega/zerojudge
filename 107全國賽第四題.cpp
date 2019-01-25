#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
const int maxn=2e3+5;
bool hard[maxn]={},visit[maxn]={};
int L,ans=0;
vector<int> G[5][maxn];
void dfs(int pos,int depth,int k){
	if(depth>L) return;
	if(k){
		if(!hard[pos])
		ans=max(ans,depth);
	}
	for(int now:G[k][pos]){
			if(now!=pos&&visit[now]==0){
				visit[now]=1;
				dfs(now,depth+1,(k+1)%2);
				visit[now]=0;
			} 
		} 
} 
void init(int n){
	for(int i=1;i<=n;i++)
		visit[i]=0,G[0][i].clear(),G[1][i].clear(),hard[i]=0;
}
int main(){
	IOS
	int a,b,m;
	while(cin>>a>>b>>m>>L){
		ans=-1;
		init(a+b);
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			y+=a;
			G[z][x].push_back(y);
			G[z][y].push_back(x); 
			if(z) hard[x]=hard[y]=1;
			
		}
		for(int i=1;i<=a+b;i++){
			if(hard[i]) continue;
			else{
				for(int now:G[0][i]){
						visit[now]=1;
						dfs(now,1,1);
						visit[now]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
