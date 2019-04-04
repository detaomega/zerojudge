#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int p[maxn];
int n=100000;
void init(int n){
	for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x){
	return p[x]==x? x: p[x]=find(p[x]);
}
set<int> id;
int  merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a!=b){
		int w=rand()%20+1;
		int idd=(rand()*rand())%(n-1)+1;
		while(id.count(idd)){
			idd=(rand()*rand())%n+1;
		}
		id.insert(idd);
		cout<<idd<<" "<<x<<" "<<y<<" "<<w<<"\n";	
		p[a]=b;
		return 1;
	}

	return 0;
}

int main(){
	freopen("input_1.in","w",stdout);
	srand(time(NULL));
	init(n);
	int m=100000;
	cout<<n<<"\n";
	for(int i=1;i<n;i++){
		int u=(rand()*rand())%n+1;
		int v=(rand()*rand())%n+1;
		while(merge(u,v)==0){	
		u=(rand()*rand())%n+1;
		v=(rand()*rand())%n+1;
		} 
	}
	cout<<m<<"\n";
	while(m--){
			int u=rand()%(n)+1,v=rand()%n+1;
			long long w=(rand()*rand())%5+1;
			cout<<u<<" "<<v<<" "<<abs(w)<<"\n";
//			int go=rand()%n+1;
		
	}
}
