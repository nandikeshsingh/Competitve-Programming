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
        vector<string>a;
        for(int i=0;i<2;i++)
        {
            string s;
            cin>>s;
            a.push_back(s);
        }
        int p=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[1][i]>=a[0][i+1])p++;
            else break;
        }
        string ans;
        for(int i=0;i<n;i++)
        {
            if(i<=p)ans+=a[0][i];
        }
        for(int i=0;i<n;i++)
        {
            if(i>=p)ans+=a[1][i];
        }
        int cnt=1;
        for(int i=p-1;i>=0;i--)
        {
            if(a[1][i]==a[0][i+1])cnt++;
            else break;
        }
        cout<<ans<<endl;
        cout<<cnt<<endl;
    }
    return 0;
}


