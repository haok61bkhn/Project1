#include<bits/stdc++.h>
#define Nmax 1000
#define forl(a,u) for(list<int> ::iterator v = a[u].begin(); v!=a[u].end();v++) 
using namespace std;
list<int> adj[Nmax];
int a[3],n;
bool kt[Nmax][Nmax],c[Nmax];

void Init(){
int x;
//	freopen("int.txt","r",stdin);
	cin>>n;
	for(int i = 0 ; i < n;i++)
		for(int j = 0 ; j < n ; j++){
			cin>>x;
			if(x==1){
			adj[i].push_back(j);
			kt[i][j]=true;
			}
		}
			
	
}	
void Output(){
	for(int i = 0 ; i < 3; i ++)
	 cout<<a[i]+1<<" ";
	 exit(0);
}
void Dfs(int i){
	forl(adj,a[i-1])
	if(!c[*v] )
	{
		c[*v]=true;
		a[i]=*v;
		if(i==2 and kt[a[2]][a[0]] ) Output();else Dfs(i+1);
		c[*v]=false;
	}
		
}


main(){
	Init();
	for(int i = 1 ;i<=n;i++){
		c[i]=true;
		a[1]=i;
		Dfs(0);
	
	}
	cout<<"-1 -1 -1";
}

