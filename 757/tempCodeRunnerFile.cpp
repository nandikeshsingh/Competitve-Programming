#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>cnt(20000001);
    vector<int>mul(20000001);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        mul[1]++;
        if(a[i]%2==0)mul[2]++;
        if(a[i]%3==0)mul[3]++;
    }
    for(int g=4;g<=20000000;g++)
    {
        for(int j=g;j<=20000000;j+=g)
        {
            mul[g]+=cnt[j];
        }
    }
    int ans=-1e18;
    vector<int>tot(20000001);
    for(int g=20000000;g>=1;g--)
    {
        tot[g]=mul[g]*g;
        for(int j=g;j<=20000000;j+=g)
        {
            tot[g]=max(tot[g],tot[j]+(mul[g]-mul[j])*g);
        }
        ans=max(ans,tot[g]);
    }
    cout<<ans<<endl;
    return 0;
}


