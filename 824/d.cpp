#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    // map<pair<vector<int>,vector<int>>,vector<int>>mp;
    set<vector<int>>st;
    map<vector<int>,int>rmp;
    vector<vector<int>>c(n,vector<int>(k));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        cin>>c[i][j];
        st.insert(c[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            vector<int>vec(k);
            for(int k1=0;k1<k;k1++)
            {
                if(c[i][k1]==c[j][k1])vec[k1]=c[i][k1];
                else vec[k1]=3-c[i][k1]-c[j][k1];
            }
            if(st.count(vec))
            rmp[vec]++;
        }
    }
    int ans=0;
    for(auto& u : rmp)ans+=(u.second*(u.second-1))/2;
    cout<<ans<<endl;
    return 0;
}
