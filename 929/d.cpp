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
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        bool ok=0;
        sort(all(a));
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            cnt+=(a[i]==a[0]);
            if((a[i]%a[0])!=0)ok=1;
        }
        if(cnt==1)cout<<"YES"<<endl;
        else 
        {
            cout<<(ok?"YES":"NO")<<endl;
        }
    }
    return 0;
}


