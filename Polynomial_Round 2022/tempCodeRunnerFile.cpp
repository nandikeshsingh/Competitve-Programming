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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(m);
        for(int i=0;i<m;i++)cin>>a[i];
        if(k>m)cout<<"NO"<<endl;
        else 
        {
            sort(all(a));
            reverse(all(a));
            bool ok=1;
            for(int i=0;i<k;i++)
            {
                int cur=0;
                for(int j=i;j<m;j++)
                {
                    cur+=a[j];
                }
                if(cur%k!=0)ok=0;
            }
            if(ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


