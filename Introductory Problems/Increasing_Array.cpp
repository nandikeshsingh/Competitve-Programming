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
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(vec[i]<vec[i-1])ans+=-vec[i]+vec[i-1],vec[i]=vec[i-1];
    }
    cout<<ans<<endl;
    return 0;
}
