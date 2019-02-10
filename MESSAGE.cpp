#include<iostream>
#include<list>
#include<queue>
#define For(n) for(int i = 0 ; i <n ;i++)
#define Forl(u,a) for(list<int>::iterator v=a[u].begin();v!=a[u].end();v++)
#define Nmax int(1e4+100)
using namespace std;
list<int> a[Nmax];
int t1[Nmax];
bool c[Nmax];
int n,m,t,du;

void Init(){
int x, y;
//	freopen("int.txt","r",stdin);
	cin>>n>>m;
	For(m){
		cin>>x>>y;
		a[x].push_back(y);
	}
} 

void Dfs(int x,int k){
	for(list<int>::iterator v=a[x].begin();v!=a[x].end();v++)
		if(t1[*v]!=k){
			t1[*v]=k;
			c[*v]=true;
		    Dfs(*v,k);
		}
}

main(){
int k=1;
	Init();
	For(n)
		if(!c[i+1]){
			k++;
			t1[i+1]=k;
			Dfs(i+1,k);
			c[i+1]=false;
		}
		
int res=0;		
	For(n)
		if(!c[i+1]) {
	//	cout<<i+1<<"\n";
		res++;
	}
	cout<<res;
}
