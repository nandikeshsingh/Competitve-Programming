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
        multiset<int>ms;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ms.insert(x);
        }
        int ans=n;
        for(ans=n;ans>=0;ans--)
        {
            bool ok=1;
            multiset<int>a=ms;
            for(int cur=ans;cur>=1;cur--)
            {
                if(sz(a)>0)
                {
                    auto itr=a.upper_bound(cur);
                    if(itr==a.begin())
                    {
                        ok=0;
                        break;
                    }
                    else 
                    {
                        a.erase(prev(itr));
                        if(sz(a)==0)continue;
                        auto it=a.upper_bound(cur-1);
                        if(it!=a.begin())
                        {
                            it=prev(it);
                            int now=*it;
                            now+=cur;
                            a.erase(it);
                            a.insert(now);
                        }
                    }
                }
                else 
                {
                    ok=0;
                    break;
                }
            }
            if(ok)break;
        }
        cout<<ans<<endl;
    }   
    return 0;
}
