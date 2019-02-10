#include<iostream>
#include<list>
#include<queue>
#define For(n) for(int i = 0 ; i <n ;i++)
#define Forl(u,a) for(list<int>::iterator v=a[u].begin();v!=a[u].end();v++)
#define Nmax int(1e4+100)
using namespace std;
list<int> a[Nmax];
bool c[Nmax];
int n,m,t,du;

void Init(){
int x, y;
// 	freopen("int.txt","r",stdin);
	cin>>n>>m>>t;
	For(m){
		cin>>x>>y;
		a[y].push_back(x);
	}
} 

Dfs(int x){
	Forl(x,a)
		if(!c[*v]){
			c[*v]=true;
		    Dfs(*v);
		}
}

main(){
int d=0;
	Init();
	Dfs(t);
	c[t]=true;
	For(n)
		if(!c[i+1]){
			Dfs(i+1);
			c[i+1]=false;
		}
int res=0;		
	For(n)
		if(!c[i+1]) res++;
	cout<<res;
}

