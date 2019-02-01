/*
這題的技巧是用 dijkstra+disjoint set
所先先用disjoint set判斷題目問的那個點有沒有跟其他點連接
再來用dijkstra求最短路徑 中間如果那個距離大於目前的最短距離我們可以砍掉
*/
#include <bits/stdc++.h>
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

char getc(){
	static const int bufsize = 1<<16;
	static char B[bufsize], *S=B, *T=B;
	return (S==T&&(T=(S=B)+fread(B,1,bufsize,stdin),S==T)?0:*S++);
}

template <class T>
bool input(T& a){
	a=(T)0;
	register char p;
	while ((p = getc()) < '-')
		if (p==0 || p==EOF) return false;
	if (p == '-')
		while ((p = getc()) >= '0') a = a*10 - (p^'0');
	else {
		a = p ^ '0';
		while ((p = getc()) >= '0') a = a*10 + (p^'0');
	}
	return true;
}

template <class T, class... U>
bool input(T& a, U&... b){
	if (!input(a)) return false; 
	return input(b...);
}
const int maxn=3e5+5;
int dis[maxn];
int ans=1e9;
int num[maxn]={};
bool used[maxn];
vector<pair<int,int> > G[maxn];
struct dsu{
	int p[maxn];
	void init(int n){
		for(int i=1;i<=n;i++)
			p[i]=i;
	}
	int findp(int x){
		return p[x]==x ? x:p[x]=findp(p[x]);
	}
	void unite(int x,int y){
		p[findp(x)]=findp(y);
	}
}dsu;
struct node{
	int u,w;
	bool operator < (const node& rph) const{
		return w > rph.w;
	}
};
void dijk(int n){
	priority_queue<node> pq;
		pq.push({n,0});
		dis[n]=0;
		while(!pq.empty()){
			int k=pq.top().u;pq.pop();
			if(k!=n&&used[k]){
				ans=min(ans,dis[k]);
				break;
			}
			for(auto i:G[k]){
				if(dis[i.first]==-1){
					dis[i.first]=dis[k]+i.second;
					if(dis[i.first]<ans)
					pq.push({i.first,dis[i.first]});
				}
				else if(dis[i.first]>dis[k]+i.second){
					dis[i.first]=dis[k]+i.second;
					if(dis[i.first]<ans)
						pq.push({i.first,dis[i.first]});
				}
			}
		}
}

int main(){
	IOS
	int n,m,hide;
	input(n,m,hide);
	dsu.init(n);
	memset(dis,-1,sizeof(dis));
	for(int i=0;i<m;i++){
		int a,b,c;
		input(a,b,c);
		G[a].push_back({b,c});
		G[b].push_back({a,c});
		dsu.unite(a,b);
	}
	vector<int > h;
	for(int i=0;i<hide;i++){
		int a;
		input(a);
		used[a]=1;
		num[dsu.findp(a)]++;
		h.push_back(a);
	}
	for(int k:h){
		if(num[dsu.findp(k)]<=1)
			continue;
		dijk(k);
	}
	if(ans==1e9)
		cout<<"zombie";
	else
	cout<<ans;
}/*
5 7 3
1 2 4
1 3 2
1 5 7
2 3 1
2 5 3
3 4 5
4 5 8
5 1 4

5 4 5
1 2 12
2 3 13
3 4 11
4 5 12
1 2 3 4 5
*/
