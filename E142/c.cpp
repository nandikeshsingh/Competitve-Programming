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
        vector<int>p(n);
        vector<int>idx(n+1);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            idx[p[i]]=i;
        }
        int l,r;
        if(n%2)
        {
            l=(n+1)/2;
            r=l;
        }
        else 
        {
            l=n/2;
            r=l+1;
        }
        int last_l=l+1;
        int last_r=r-1;
        bool f=0;
        bool first=1;
        int ans=-1;
        do
        {
            if(first)
            {
                if(idx[l]<=idx[r])
                {
                    last_l=idx[l];
                    last_r=idx[r];
                    l--;r++;
                }
                else 
                {
                    f=1;
                    ans=l;
                }
                first=0;
            }
            else
            {
                if(idx[l]<last_l && idx[r]>last_r)
                {
                    last_l=idx[l];
                    last_r=idx[r];
                    l--;r++;                   
                }
                else 
                {
                    f=1;
                    ans=l;
                }
            }

        } while(!f);
        cout<<ans<<endl;
    }
    return 0;
}


