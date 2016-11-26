#include<bits/stdc++.h>
using namespace std;
#define MAXX 10000

long long int parent[MAXX],su=0,un=0;
long long int Size[MAXX];

void makeset(long long int p){
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

  if(u==v){
    return;
  }
  else{
    parent[u]=v;
    Size[v]+=Size[u];
  }
}

void check(long long int l,long long int k){

  long long int u=finding(l);
  long long int v=finding(k);

  if(u==v)
    su++;
  else
    un++;

}

int main()
{
    string s;
    char ch;
    long long int A,B,n,t,j,coke,pk;

    cin>>t;


    for(j=1; j<=t; j++){

     cin>>n;
  for(long long int i=1; i<=n; i++) makeset(i);
     getchar();
  while(1){

    if(!getline(cin,s) || s.empty()) break;

      sscanf(s.c_str(),"%c %d %d",&ch,&A,&B);

      if(ch=='c') Union(A,B);
      if(ch=='q') check(A,B);


  }
  if(j!=1) cout<<endl;
  cout<<su<<","<<un<<endl;
  su=0,un=0;

}
return 0;
}

