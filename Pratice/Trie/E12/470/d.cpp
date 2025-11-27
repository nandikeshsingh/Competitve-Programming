#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int M=(3e5+1)*30;
const int A=2;
struct Trie
{
    int n=0;
    int t[M][A]={};
    int pre[M]={};
    void init()
    {
        for(int i=0;i<M;i++)
        for(int j=0;j<A;j++)
        t[i][j]=-1;
        
    }
    void add(int x)
    {
        int p=0;
        pre[p]++;
        for(int i=29;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(t[p][b]==-1)
            {
                t[p][b]=++n;
            }
            p=t[p][b];
            pre[p]++;
        }
    }
    void remove(int x)
    {
        int p=0;
        for(int i=29;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(pre[t[p][b]]>1)
            {
                p=t[p][b];
                pre[p]--;
            }
            else 
            {
                pre[t[p][b]]--;
                int nn=t[p][b];
                t[p][b]=-1;
                p=nn;
            }
        }
    }
    int get(int x)
    {
        int p=0;
        int ret=0;
        for(int i=29;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(t[p][b]!=-1 && t[p][b^1]!=-1)
            {
                p=t[p][b];
            }
            else if(t[p][b]==-1 && t[p][b^1]==-1)
                break;
            else if(t[p][b]==-1 && t[p][b^1]!=-1)
            {
                p=t[p][b^1];
                ret|=(1<<i);
            }
            else 
            {
                p=t[p][b];
            }
        }
        return ret;
    }
};
Trie T;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n),p(n);
    T.init();
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>p[i],T.add(p[i]);
    for(int i=0;i<n;i++)
    {
        int best=T.get(a[i]);
        cout<<best<<" ";
        T.remove(best^a[i]);
    }
    return 0;
}


