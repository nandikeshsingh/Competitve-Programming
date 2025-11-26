#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        // cout<<"n="<<n<<" m="<<m<<endl;
        vector<vector<int>>a(n,vector<int>(m)),b(n,vector<int>(m));
        vector<set<int>>sa(n),sb(n);
        rep(i,0,n-1)
        {
            rep(j,0,m-1)
            {
                cin>>a[i][j];
                sa[i].insert(a[i][j]);
            }
        }
        rep(i,0,n-1)
        {
            rep(j,0,m-1)
            {
                cin>>b[i][j];
                sb[i].insert(b[i][j]);
            }
        }
        // cout<<"done"<<t<<endl;
        map<int,int>index;
        rep(i,0,n-1)index[*sb[i].begin()]=i;
        vector<bool>ok(n,0);
        bool ans=1;
        vector<int>pos(n,-1);
        rep(i,0,n-1)
        {
            int val=*sa[i].begin();
            int idx=-1;
            if(index.find(val)!=index.end())idx=index[val];
            if(idx==-1)
            {
                ok[i]=0;
                ans=0;
                break;
            }
            else 
            {
                bool good=1;
                for(auto& u : sa[i])
                {
                    if(sb[idx].find(u)==sb[idx].end())
                    {
                        good=0;
                        break;
                    }
                }
                if(good)
                {
                    ok[i]=1;
                    pos[i]=idx;
                }
                else 
                {
                    ans=0;
                    break;
                }
            }
        }
        // cout<<"Out"<<endl;
        if(!ans)cout<<"NO"<<endl;
        else 
        {
            // cout<<"inside"<<endl;
            vector<vector<int>>da(n,vector<int>(m));
            rep(i,0,n-1)
            {
                rep(j,0,m-1)
                {
                    da[pos[i]][j]=a[i][j];
                }
            }
            // cout<<"ok"<<endl;
            map<int,int>mp;
            rep(j,0,m-1)mp[b[0][j]]=j;
            // cout<<"ok2"<<endl;
            bool go=1;
            rep(j,0,m-1)
            {
                int idx=mp[da[0][j]];
                rep(i,0,n-1)
                {
                    if(da[i][j]!=b[i][idx])
                    {
                        go=0;
                        break;
                    }
                }
                if(go==0)break;
            }
            if(!go)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        // cout<<"t="<<t<<endl;
    }
    return 0;
}


