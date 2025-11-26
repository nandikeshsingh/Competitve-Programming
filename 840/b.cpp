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
        int n,k;
        cin>>n>>k;
        vector<int>h(n),p(n);
        set<pair<int,int>>x,y;
        for(int i=0;i<n;i++)
        {
            cin>>h[i];
            x.insert({h[i],i});
            
        }
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            y.insert({p[i],i});
        }
        while(k>0 && sz(x)>0)
        {
            // cout<<"starting k="<<k<<" sz="<<sz(x)<<endl;
            pair<int,int>mn=*x.begin();
            
            int red=k;
            set<pair<int,int>>temp;
            for(auto& u : x)
            {
                if(red>=u.first)
                {
                    y.erase(y.find({p[u.second],u.second}));
                }
                else 
                {
                    temp.insert({u.first-red,u.second});
                }
            }
            x.clear();
            x=temp;
            pair<int,int> sub=*y.begin();
            k-=sub.first;

            // cout<<"k="<<k<<" sz="<<sz(x)<<endl;
        }
        if(sz(x)==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


