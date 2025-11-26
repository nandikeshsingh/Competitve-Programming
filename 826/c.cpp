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
        int tot=0;
        int ans=n;
        for(int i=0;i<n;i++)cin>>a[i],tot+=a[i];
        vector<int>d;
        for(int l=1;l*l<=tot;l++)
        {
            if(tot%l==0)
            {
                d.push_back(l);
                if(l*l!=tot)
                d.push_back(tot/l);
            }
            
        }
        for(auto l : d)
        {
            // if(tot%l==0)
            {
                int s=tot/l;
                bool ok=1;
                int mn=0;
                int l=0,r=0,cur=0;
                while(r<n)
                {
                    if(cur==s)
                    {
                        mn=max(mn,r-l);
                        l=r;
                        cur=0;
                    }
                    else if(cur<s)
                    {
                        cur+=a[r];
                        r++;
                    }
                    else 
                    {
                        ok=0;
                        break;
                    }
                }
                if(cur==s)mn=max(mn,r-l);
                else ok=0;
                if(ok)ans=min(ans,mn);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


