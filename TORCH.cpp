#include<bits/stdc++.h>
#define Nmax int(1e3)

using namespace std;

struct Point{
	int x;
	int y;
} typedef Point ;

Point a[Nmax];
float Res,s;
int f[Nmax],n,b[Nmax];
bool c[Nmax];


void Init(){
int x, y;
//	freopen("int.txt","r",stdin);
		cin>>n;
		for(int i = 1 ; i <= n ; i++ ){
			cin>>x>>y;
			a[i].x=x;
			a[i].y=y;
		}
}

float Cal(Point x,Point y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
void Xuli(){
	if(s+Cal(a[f[n]],a[1])<Res){
	
	for(int i = 1;i<=n;i++)
		b[i]=f[i];
	Res=s+Cal(a[f[n]],a[1]);
	}
}

void DFS(int i){
	for(int j=1;j<=n;j++)
		if(!c[j] and s+Cal(a[f[i-1]],a[j])<Res){
			f[i]=j;
			c[j]=true;
			s+=Cal(a[f[i-1]],a[j]);
			if(i==n) Xuli();else DFS(i+1);
			c[j]=false;
			s-=Cal(a[f[i-1]],a[j]);
		}
}

void Output(){
	printf("%.3f\n",Res);
	for(int i = 1;i<=n;i++)
		cout<<b[i]<<" ";
	
}

void Program(){
	Res=10000000;

		s=0;
		f[1]=1;
		c[1]=true;
		DFS(2);

	Output();
}

main(){
	Init();
	Program();
}

