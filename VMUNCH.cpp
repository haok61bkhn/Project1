#include<bits/stdc++.h>
#include<queue>
#define forn(n) for(int i = 0 ; i < n ; i++)
#define Nmax 105
using namespace std;
int f[Nmax][Nmax],n,m,firstx,firsty,lastx,lasty;
char a[Nmax][Nmax];
bool kt[Nmax][Nmax];


void Init(){
//	freopen("int.txt","r",stdin);
	cin>>n>>m;
	forn(n)
		for(int j=0;j<m;j++){
		   cin>>a[i][j];
		   if(a[i][j]=='B'){
		   	firstx=i;
		   	firsty=j;
		   }
		   if(a[i][j]=='C'){
		   	lastx=i;
		   	lasty=j;
		   }
	}
}
//============================================
void Tick(int x,int y){
	kt[x][y]=true;	
}

//=============================================
void BFS(int fx,int fy){
int h[4]={-1,0,1,0};
int c[4]={0,1,0,-1};
queue< pair<int,int> >  que;
    que.push(make_pair(fx,fy));
    Tick(fx,fy);
    while(!que.empty()){
    	pair<int,int> u = que.front();
    	que.pop();
    	forn(4){
    		int x = u.first+h[i];
    		int y = u.second+c[i];
    		if(x>=0 and y>= 0 and x<n and y< m and !kt[x][y] and a[x][y]!='*'){
    			que.push(make_pair(x,y));
    			Tick(x,y);
    			f[x][y]=f[u.first][u.second]+1;
    			if(x==lastx and y == lasty) {
				cout<<f[x][y];
				return;}
			}
		}
	}
}

main(){
	Init();
	BFS(firstx,firsty);
}

