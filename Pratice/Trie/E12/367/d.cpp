#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int M=(2e5+1)*30;
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
                ret|=(1<<i);
                p=t[p][b^1];
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
void print()
{
    cout<<"Printing t"<<endl;
    for(int p=0;p<=30;p++)
    {
        for(int b=0;b<2;b++)
        cout<<T.t[p][b]<<" ";
        cout<<endl;
    }
    cout<<"Printing pre"<<endl;
    for(int i=0;i<=30;i++)
    cout<<T.pre[i]<<" ";
    cout<<endl;

}
signed main()
{
    speed;
    int q;
    cin>>q;
    T.init();
    T.add(0);
    while(q--)
    {
        char c;
        int x;
        cin>>c>>x;
        if(c=='+')T.add(x);
        else if(c=='-')T.remove(x);
        else cout<<T.get(x)<<endl;
        // print();
    }
    return 0;
}


