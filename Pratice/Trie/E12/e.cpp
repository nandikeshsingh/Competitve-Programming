#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int M=(1e6+2)*30;
const int A=2;
int k;
struct Trie {
    int G = 0;
    int t[M][A]={};
    int f[M] = {};
    void init()
    {
        for(int i=0;i<M;i++)
        for(int j=0;j<2;j++)t[i][j]=-1;
    }
    void add(int a) {
        int x = 0;
        for (int i=29;i>=0;i--) {
            int c = (a>>i)&1;
 
            if (t[x][c]==-1) {
                t[x][c] = ++G;
            }
 
            x = t[x][c];
            f[x] += 1;
        }
    }
 
    int get(int a) {
        int x = 0;
       long long int res = 0;
       int cur=0;
        for (int i=29;i>=0;i--) {
            if(x==-1)break;
            int c = (a>>i)&1;
 
            if((cur+(1<<i))>=k)
            {
                res+=(t[x][c^1]==-1?0:f[t[x][c^1]]);
                x=t[x][c];
            }
            else 
            {
                x=t[x][c^1];
                cur|=(1<<i);
            }
        }
        if(cur>=k)res+=(x==-1?0:f[x]);
        return res;
    }
};
Trie T;
signed main()
{
    speed;
    int n;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    long long int ans=0;
    int tot=0;
    T.init();
    T.add(0);
    for(int j=0;j<n;j++)
    {
        tot^=vec[j];
        ans+=T.get(tot);
        T.add(tot);
    }
    cout<<ans<<endl;
    return 0;
}


