#include<bits/stdc++.h>
#include<list>
#include<queue>
#define For(n) for(int i = 0 ; i <n ;i++)
#define Forl(u,a) for(list<int>::iterator v=a[u].begin(),v!=a[u].end(),v++)
#define Nmax 705
using namespace std;
int a[Nmax][Nmax],n,m,ans,vhill;
bool visited[Nmax][Nmax],ishill;
int r[8]={0,1,1,1,0,-1,-1,-1};
int c[8]={-1,-1,0,1,1,1,0,-1}; 
void Init(){
//	freopen("int.txt","r",stdin);
	cin>>n>>m;
	for(int i = 0 ; i < n; i++)
		for(int j = 0 ; j < m ; j++)
			cin>>a[i][j];
}

void DFS(int x,int y){
	visited[x][y]=true;
	for(int i = 0 ; i < 8 ; i++){
		int x1 = x + r[i];
		int y1 =y + c[i];
		if(x1>=0 and x1<=n-1 and y1>=0 and y1<=n-1){
			if(a[x1][y1]>a[x][y]) ishill=false;
			if(a[x1][y1]==a[x][y] and !visited[x1][y1]) DFS(x1,y1);
		} 
	}
	
}

main(){
	Init();
	for(int i = 0;i < n; i++)
		for(int j = 0;j<m;j++){
			if(!visited[i][j]){
				ishill=true;
				DFS(i,j);
				if(ishill) ans++;
			}
			
			
		}
		cout<<ans;
}

