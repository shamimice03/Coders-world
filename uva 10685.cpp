#include<bits/stdc++.h>
using namespace std;
#define MAXX 1000000

map<string,long long int>pagla;

long long int parent[MAXX];
long long int Size[MAXX];

void makeset(long long  int p){
 parent[p]=p;
 Size[p]=1;
}

long long int finding(long long int represent){

   if(parent[represent]==represent)
    return represent;
   else
    return parent[represent]=finding(parent[represent]);
}

void Union(long long int a,long long int b){

 long long int u=finding(a);
 long long int v=finding(b);

  if(u==v) return;
  else if(u!=v){
    parent[u]=v;
    Size[v]+=Size[u];
  }

}

int main()
{

   string ll,ff;
   long long int i,j,l,f,c,r,q=1,mx=1;

   while(1){

   cin>>c>>r;

   mx=1;

   if(c==0 && r==0) break;

   for(i=1; i<=c; i++) makeset(i);

   for(i=0; i<c; i++){
     cin>>ll;
     if(pagla.find(ll)==pagla.end()) pagla[ll]=q++;
   }

   for(i=0; i<r; i++){

    cin>>ll>>ff;

    l=pagla[ll];
    f=pagla[ff];

    Union(l,f);
   }

   for(i=1; i<=pagla.size(); i++){

    mx=max(Size[finding(i)],mx);

   }

   cout<<mx<<endl;

   pagla.clear();
   mx=1,q=1,l=0,f=0;

   }

return 0;
}


