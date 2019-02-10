#include<bits/stdc++.h>
#include<list>
#define Nmax int (1e4+100)
#define forl(a,u) for(list<int> ::iterator v = a[u].begin(); v!=a[u].end();v++)

using namespace std;

int low[Nmax],num[Nmax],n,m,sk,sc,cnt,parent[Nmax],root,child,d,res,b[Nmax];
bool AP[Nmax],kt[Nmax];
list<int> adj[Nmax];

void Init(){
int u , v;
	freopen("int.txt","r",stdin);
	cin>>n>>m;
	for(int i = 0 ; i < m ; i ++ ){
		cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
}
	

void Tarjan(int u){
	low[u]=num[u]=++cnt;

	forl(adj,u)
		if(num[*v]==0) {
		parent[*v]=u;
		if(u==root) child++;
		Tarjan(*v);
		
		
		low[u]=min(low[u],low[*v]);
		if(num[u]<=low[*v] and !AP[u]) 
		{
		
		    AP[u]=true;
			sk++;
		}
		if(num[u]<low[*v]) sc++;
	
	   } 
	   
	   else{
		if(parent[u]!=*v)
		    low[u]=min(low[u],num[*v]);
	   }
	
	

	
}

main(){
	Init();
	for(int i = 1;i<=n;i++)
	  if(!num[i])
      {	 child=0;
      	 root=i;
			 Tarjan(i);
	    if(child>1 and !AP[root]) {
		sk++;AP[root]=true ;}  ;
     }
	
	
	cout<<sk<<" "<<sc;

}
