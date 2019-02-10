#include<bits/stdc++.h>
#include<list>
#define Nmax int (1e4+100)
#define forl(a,u) for(list<int> ::iterator v = a[u].begin(); v!=a[u].end();v++)
#include<stack>
using namespace std;

int low[Nmax],num[Nmax],n,m,sk,sc,cnt,parent[Nmax],root,child,d,res,b[Nmax];
bool AP[Nmax],kt[Nmax];
list<int> adj[Nmax];
stack<int> st;

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
	st.push(u);
	forl(adj,u)
		if(num[*v]==0) {
		parent[*v]=u;
		if(u==root) child++;
		Tarjan(*v);
		
		
		low[u]=min(low[u],low[*v]);
		if(num[u]<=low[*v]){
		
		int x= st.top();
			st.pop();
			int d=1;
			while(x!=u){
				d++;
				st.pop();
				x=st.top();
			}
			res=max(res,d);
		
		}
		st.push(u);
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
     }
	
      
	cout<<res;

}
