#include<bits/stdc++.h>
#define int long long
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
        int n,m;
        cin>>n>>m;
        string s;cin>>s;
        vi a(m);
        rep(i,0,m-1)cin>>a[i],a[i]--;
        string c;cin>>c;
        multiset<char>st;
        for(auto& u : c)st.insert(u);
        map<int,int>cnt;
        rep(i,0,m-1)cnt[a[i]]++;
        for(auto& u : cnt)
        {
            int idx=u.F;
            int ct=u.S;
            if(ct==1)
            {
                s[idx]=*st.begin();
                st.erase(st.begin());
            }
            else 
            {
                s[idx]=*st.begin();
                st.erase(st.begin());
                int rim=ct-1;
                while(rim>0)
                {
                    st.erase(prev(st.end()));
                    rim--;
                }
            }
        }
        cout<<s<<endl;
        
    }
    return 0;
}


