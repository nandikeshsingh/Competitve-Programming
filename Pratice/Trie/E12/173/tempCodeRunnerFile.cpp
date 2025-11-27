#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int M=(1e5+1)*40;
const int A=2;
int tot;
struct Trie
{
    int n=0;
    int t[M][A]={};

    void init()
    {
        for(int i=0;i<M;i++)
        for(int j=0;j<A;j++)
        t[i][j]=-1;
    }

    void add(int x)
    {
        int p=0;
        for(int i=39;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(t[p][b]==-1)
            t[p][b]=++n;
            p=t[p][b];
        }
    }

    int get(int x)
    {
        int p=0;
        int ret=0;
        for(int i=39;i>=0;i--)
        {
            if(p==-1)break;
            int b=(x>>i)&1;
            if((tot>>i)&1)
            {
                if(t[p][b]!=-1)
                 p=t[p][b];
                else p=t[p][b^1];
            }
            else 
            {
                if(t[p][b^1]!=-1)
                {
                    p=t[p][b^1];
                    ret|=(1LL<<i);
                }
                else p=t[p][b];
            }
        }
        return tot^ret;
    }
};
Trie T;
void print()
{
    cout<<"Printing t"<<endl;
    for(int p=0;p<=30;p++)
    {
        for(int b=0;b<2;b++)
        cout<<T.t[p][b]<<" ";
        cout<<endl;
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i],tot^=a[i];
    T.init();
    T.add(0);
    int cur=0;
    int ans=0;
    for(int j=0;j<n;j++)
    {
        cur^=a[j];
        T.add(cur);
        ans=max(ans,T.get(cur));
    }
    cout<<ans<<endl;
    return 0;
}


