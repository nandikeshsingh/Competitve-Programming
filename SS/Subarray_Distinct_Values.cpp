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
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int>mp;
    int l=0,r=1;
    mp[a[l]]++;
    int ans=0;
    while(r<n)
    {
        if((int)mp.size()<=k)
        {
            ans+=r-l;
            mp[a[r]]++;
            r++;
            // if((int)mp.size()==k)
        }
        if((int)mp.size()>k)
        {
            mp[a[l]]--;
            if(mp[a[l]]==0)
            mp.erase(mp.find(a[l]));
            l++;
        }
    }
    // while((int)mp.size()>k)
    // {
    //     mp[a[l]]--;
    //     if(mp[a[l]]==0)
    //     mp.erase(mp.find(a[l]));
    //     l++;       
    // }
    if((int)mp.size()<=k)ans+=(r-l);
    cout<<ans<<endl;
    return 0;
}
