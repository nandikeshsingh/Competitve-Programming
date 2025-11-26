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
        int n,m;
        cin>>n>>m;
        vector<int>k(n);
        for(int i=0;i<n;i++)cin>>k[i];
        sort(all(k));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(a*c<0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            double lw=(double)b-(double)2*double(sqrt(a*c));
            int low=floor(lw);
            int pos=upper_bound(all(k),low)-k.begin();
            if(pos==n)cout<<"NO"<<endl;
            else 
            {
                double cur=(double)k[pos];
                double high=(double)b+(double)2*double(sqrt(a*c));
                if(high>cur)
                {
                    cout<<"YES"<<endl;
                    cout<<k[pos]<<endl;
                }
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}


