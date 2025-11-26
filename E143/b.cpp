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
        int n,k;
        cin>>n>>k;
        int lo=-1e18;
        int hi=1e18;
        for(int i=0;i<n;i++)
        {
            int l,r;cin>>l>>r;
            if(k>r || k<l)continue;
            else 
            {
                lo=max(lo,l);
                hi=min(hi,r);
            }
        }
        if(lo==hi && hi==k)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


