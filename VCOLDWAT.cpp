#include<bits/stdc++.h>
#include<list>
#include<queue>
#define For(n) for(int i = 0 ; i <n ;i++)
#define Forl(u,a) for(list<int>::iterator v=a[u].begin();v!=a[u].end();v++)
#define Nmax int(1e6+100) 
using namespace std;

list<int> adj[Nmax];
int deep[Nmax],n,m;

void Init(){
int x,y,z;
//	freopen("int.txt","r",stdin);
	cin>>n>>m;
		for(int j = 0 ; j<m;j++)
		for(int i = 0 ;i<2;i++){
			cin>>x>>y>>z;
			adj[x].push_back(y);
			adj[x].push_back(z);
		}
	
}

void DFS(int x){
	Forl(x,adj){
		deep[*v]=deep[x]+1;
		DFS(*v);
	}
}



main(){
	Init();
	deep[1]=1;
	DFS(1);
	For(n){
		cout<<deep[i+1]<<"\n";
	}
}

