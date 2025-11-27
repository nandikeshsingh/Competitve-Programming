#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int M=(3e5+1)*19;
const int A=2;
struct Trie
{
    int id=0;
    int t[M][A]={};
    int lfs[M]={};
    bool f=0;
    void init()
    {
        for(int i=0;i<M;i++)
        for(int j=0;j<2;j++)
        t[i][j]=-1;
        for(int i=0;i<M;i++)
        lfs[i]=0;
    }
    void add(int x,int p,int i)
    {
        if(i<0 || p==-1)return;
        int b=(x>>i)&1;
        if(t[p][b]==-1)
        {
            t[p][b]=++id;
            if(i==0)f=1,lfs[t[p][b]]=1;
        }
        add(x,t[p][b],i-1);
        if(f)lfs[p]+=(t[p][b]==-1?0:1);
    }
    int get(int x)
    {
        int p=0;
        int mex=0;
        for(int i=18;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(t[p][b]==-1 && t[p][b^1]==-1)
            break;
            else if(t[p][b]!=-1 && t[p][b^1]==-1)
            {
                if(lfs[t[p][b]]<(1LL<<i))
                p=t[p][b];
                else 
                {
                    mex|=(1LL<<i);
                    break;
                }
            }
            else if(t[p][b]==-1 && t[p][b^1]!=-1)
            {
               break;
            }
            else 
            {
                if(lfs[t[p][b]]<(1LL<<i))
                {
                    p=t[p][b];
                }
                else 
                {
                    p=t[p][b^1];
                    mex|=(1LL<<i);
                }
            }
        }
        return mex;
    }
};
Trie T;
void print()
{
    cout<<"Printing t"<<endl;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<2;j++)
        cout<<T.t[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Printing leaves cnt"<<endl;
    for(int i=0;i<30;i++)
    cout<<T.lfs[i]<<" ";
    cout<<endl;
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    T.init();
    for(int i=0;i<n;i++)cin>>a[i],T.add(a[i],0,18),T.f=0;
    int cur=0;
    while(m--)
    {
        int x;cin>>x;
        cur^=x;
        cout<<T.get(cur)<<endl;
    }
    return 0;
}


