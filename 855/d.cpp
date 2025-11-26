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
        string s;cin>>s;
        const int p=31;
        const int m1=1e9+7;
        const int m2=1e9;
        vector<long long> pm1_pow(n),pm2_pow(n);
        pm1_pow[0]=1;
        pm2_pow[0]=1;
        for (int i = 1; i < n; i++)
        {
            pm1_pow[i] = (pm1_pow[i-1] * p) % m1;
            pm2_pow[i] = (pm2_pow[i-1] * p) % m2;
        }
        vector<int>h1(n+1,0),h2(n+1,0);
        for(int i=0;i<n;i++)
        {
            h1[i+1]=(h1[i] + (((s[i] - 'a' + 1) * pm1_pow[i])%m1)) % m1;
            h2[i+1]=(h2[i] + (((s[i] - 'a' + 1) * pm2_pow[i])%m2)) % m2;
        }
        set<pair<int,int>>ans;
        for(int i=1;i<=n-1;i++)
        {
            int left1=h1[i-1];
            int right1=(h1[n]-h1[i+1]+m1)%m1;
            left1=(left1*pm1_pow[2])%m1;
            
            int left2=h2[i-1];
            int right2=(h2[n]-h2[i+1]+m2)%m2;
            left2=(left2*pm2_pow[2])%m2;            
            ans.insert({(left1+right1)%m1,(left2+right2)%m2});
        }
        cout<<sz(ans)<<endl;
    }
    return 0;
}


