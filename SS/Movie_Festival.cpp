#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec.push_back({b,a});
    }
    sort(all(vec));
    set<pair<int,int>>st;
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        auto itr=st.upper_bound({vec[i].second,1e18});
        if(itr==st.begin())
        {
            if(cnt<k)
            {
                cnt++;
                st.insert({vec[i].first,cnt});
            }
            else ans++;
        }
        else 
        {
            --itr;
            int val=itr->second;
            st.erase(itr);
            st.insert({vec[i].first,val});
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
