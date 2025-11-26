#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            st.insert(x);
        }
        for(auto& u : st)a.push_back(u);
        int ans=1;
        int len=sz(a)-1;
        for(int j=len;j>=0;j--)
        {
            int find=a[j]-(n-1);
            auto itr=lower_bound(all(a),find)-a.begin();
            ans=max(ans,j+1-itr);
        }
        cout<<ans<<endl;
    }
    return 0;
}


