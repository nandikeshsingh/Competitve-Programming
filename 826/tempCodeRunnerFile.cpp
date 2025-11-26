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
        vector<int>b(n);
        for(int i=0;i<n;i++)cin>>b[i];
        int l=0,r=0;
        while(r<n)
        {
            if(b[r]==r-l+1)
            {
                r++;
                l=r;
            }
            else if(b[l]==r-l)
            {
                l=r;
            }
            else r++;
        }
        if(l==r)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
