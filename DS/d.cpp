#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,q;
int p[1000][1000];
int func(int i,int j)
{
    int ret=0;
    int x=i/n;
    int rx=i%n;
    int y=j/n;
    int ry=j%n;
    ret+=(x*y*p[n-1][n-1]);
    if(rx>0)ret+=(y*p[rx-1][n-1]);
    if(ry>0)ret+=(x*p[n-1][ry-1]);
    if(rx>0 && ry>0)ret+=(p[rx-1][ry-1]);
    return ret;
}
signed main()
{
    speed;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch;cin>>ch;
            if(ch=='B')p[i][j]=1;
            else p[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)p[i][j]+=p[i][j-1];
    }
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<n;i++)p[i][j]+=p[i-1][j];
    }
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<func(c+1,d+1)-func(c+1,b)-func(a,d+1)+func(a,b)<<endl;
    }
    return 0;
}


