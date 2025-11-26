#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
int n;
vector<vector<int>>gp;
vector<int>sub,ss,kk,kkp;
void dfs(int n,int p)
{
        int cur=0;
        int tot=0;
    for(auto& u : gp[n])
    {
        if(u!=p)
        {
            dfs(u,n);
            sub[n]+=sub[u];
            sub[n]%=mod;
            // ss[n]+=(sub[u]-1);
            // ss[n]%=mod;
            kk[n]+=kk[u];
            kk[n]%=mod;
            kkp[n]+=kkp[u];
            kkp[n]%=mod;
            kk[n]+=(sub[u]-1+mod)%mod;
            kk[n]%=mod;
            // tot+=(sub[u]*cur);
            // tot%=mod;
            // cur+=sub[u];
            // cur%=mod;
        }
    }
    // cout<<"n="<<n<<" tot="<<tot<<endl;
    // kk[n]+=(tot);kk[n]%=mod;
    // kkp[n]+=tot;kkp[n]%=mod;
    sub[n]++;sub[n]%=mod;
    // ss[n]+=(sub[n]-1);
    // ss[n]%=mod;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        gp.clear();
        sub.clear();ss.clear();kk.clear();kkp.clear();
        gp.resize(n+1,vector<int>(0));
        sub.resize(n+1,0);ss.resize(n+1,0);kk.resize(n+1,0);kkp.resize(n+1,0);
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        dfs(1,-1);
        int ans=0;int l=1;int tot=0;
        int lkk=0;
        for(auto& u : gp[1])
        {
            ans+=sub[u];
            ans%=mod;
            l*=((sub[u]+1)%mod);
            l%=mod;
            tot+=(sub[u]);
            tot%=mod;
            lkk+=kkp[u];
            lkk%=mod;
        }
        cout<<"l="<<l<<" tot="<<tot<<" kk="<<kk[1]<<" lkk="<<lkk<<endl;
        l%=mod;
        ans+=l;
        ans%=mod;
        ans+=kk[1];
        ans%=mod;
        ans+=lkk;
        ans%=mod;
        ans+=1;
        cout<<ans%mod<<endl;
    }
    return 0;
}


