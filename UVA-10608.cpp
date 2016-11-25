#include<bits/stdc++.h>
using namespace std;
#define MAXX 40000

int parent[MAXX];
int Size[MAXX];
int mx=2;

void makeset(int p){
 parent[p]=p;
 Size[p]=1;
}

int finding(int represent){

   if(parent[represent]==represent)
    return represent;
   else
    return parent[represent]=finding(parent[represent]);
}

void Union(int a,int b){

 int u=finding(a);
 int v=finding(b);

  if(u==v){
    return;
  }
  else{
    parent[u]=v;
    Size[v]+=Size[u];
  }
}

int main()
{

    int a,b,s,n,m,t;

   cin>>t;

   while(t--){

   cin>>n>>m;
  for(int i=1; i<=n; i++) makeset(i);

  for(int i=1; i<=m; i++){
    cin>>a>>b;
    Union(a,b);
  }

  for(int i=1; i<=n; i++){
        if(Size[finding(i)] != 1){
        mx=max(Size[finding(i)],mx);
}

}

cout<<mx<<endl;

mx=2;

   }

return 0;
}
