#include<bits/stdc++.h>
#include<list>
#define Nmax int (1e4+100)
#define forl(a,u) for(list<int> ::iterator v = a[u].begin(); v!=a[u].end();v++)

using namespace std;

int low[Nmax],num[Nmax],n,m,res,cnt;
bool Free[Nmax];
list<int> adj[Nmax],st;
void Init(){
int u , v;
	freopen("int.txt","r",stdin);
	cin>>n>>m;
	for(int i = 0 ; i < m ; i ++ ){
		cin>>u>>v;
	    adj[u].push_back(v);
	}
}
	

void Tarjan(int u){
	low[u]=num[u]=++cnt;
	Free[u]=true;
	st.push_back(u);
	forl(adj,u){
		if(!num[*v]) Tarjan(*v);
		if(Free[*v]) low[u]=min(low[u],low[*v]);
		
	}
	
	if(low[u]==num[u]){
	res++;
	int x;
		do{
			x=st.back();
			st.pop_back();
	
			Free[x]=false;	
		} while(x!=u);
		

	}
	
}


main(){
	Init();
	for(int i = 1;i<=n;i++)
		if(!num[i]) Tarjan(i);
	
	cout<<res;
}
