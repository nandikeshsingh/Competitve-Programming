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
        int sum=0;
        int mn=1e18;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==0)
        {
            cout<<0<<endl;
        }
        else 
        {
            for(int i=0;i<n;i++)
            {
                int op=0;
                if(a[i]&1)
                {
                    while(a[i]%2)
                    {
                        a[i]/=2;
                        op++;
                    }
                }
                else 
                {
                    while(a[i]%2==0)
                    {
                        a[i]/=2;
                        op++;
                    }
                }
                mn=min(mn,op);
            }
            cout<<mn<<endl;
        }
    }
    return 0;
}


