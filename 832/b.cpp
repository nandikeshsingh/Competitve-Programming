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
        int m=0;
        int l=2,r=3*n;
        vector<pair<int,int>>ans;
        while(l<r)
        {
            m++;
            ans.push_back({l,r});
            l+=3;r-=3;
        }
        cout<<m<<endl;
        for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
    }
    return 0;
}


