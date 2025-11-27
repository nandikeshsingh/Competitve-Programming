#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,k,s;
        cin>>n>>k;
        vector<int>vec(n);
        vector<int>cnt(110,0);
        for(int i=0;i<n;i++)cin>>vec[i],cnt[vec[i]]++;
        if(n>2*k)
        {
            cout<<"Case #"<<c<<": "<<"NO"<<endl;
            continue;
        }
        bool ok=1;
        for(int i=1;i<=100;i++)
        {
            if(cnt[i]>=3)
            {
                ok=0;
                break;
            }
        }
        cout<<"Case #"<<c<<": "<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}


