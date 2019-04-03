#include <iostream>
#include <vector>
using namespace std;
const int maxn=1e5+5;
int num[maxn],n,m;
bool used[maxn]={};
vector<int> v;
void dfs(int cnt){
	if(m==cnt){
		for(int i=0;i<v.size();i++) cout<<v[i];
		cout<<'\n';
		return;
	}
	else{
		for(int i=0;i<=n;i++){
			v.push_back(num[i]);
			dfs(cnt+1);
			v.pop_back();//////////
		}
	}
}
int main(){
	cin>>m>>n;
	for(int i=0;i<=n;i++) num[i]=i;
	dfs(0);
}

