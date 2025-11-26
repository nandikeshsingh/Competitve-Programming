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
        for(int i=0;i<n;i++)cin>>a[i];
        int cur=a[0];
        reverse(all(a));
        a.pop_back();
        sort(all(a));
        for(int i=0;i<sz(a);i++)
        {
            if(a[i]>cur)
            {
                int rim=a[i]-cur;
                if(rim&1)
                {
                    rim/=2;
                     rim++;
                }
                else rim/=2;
                cur+=rim;
                a[i]-=rim;
            }
        }
        cout<<cur<<endl;
    }
    return 0;
}


