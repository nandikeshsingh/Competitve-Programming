#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        auto itr=lower_bound(all(ans),x[i]);
        if(itr==ans.end())
        ans.push_back(x[i]);
        else *itr=x[i];
    }
    cout<<ans.size()<<endl;
    return 0;
}


