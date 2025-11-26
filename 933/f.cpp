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
        vector<int>a(n),d(m),f(k);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>d[i];
        for(int i=0;i<k;i++)cin>>f[i];
        sort(all(f));
        int mx=-1e18;int mx2=-1e18;
        int idx=-1;
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]>mx)
            {
                mx=a[i]-a[i-1];
                idx=i;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(i==idx)continue;
            mx2=max(mx2,a[i]-a[i-1]);
        }
        // cout<<"mx="<<mx<<" mx2="<<mx2<<endl;
        int ans=mx;
        for(int i=0;i<m;i++)
        {
            set<int>st;
            st.insert(mx2);
            auto itr=lower_bound(all(f),a[idx-1]+mx/2-d[i]);
            if(itr!=f.end())
            {
                // cout<<"index_lower="<<itr-f.begin()<<endl;
                if(d[i]+f[itr-f.begin()]<=a[idx])
                {
                    // cout<<"lower"<<endl;
                    st.insert(d[i]+f[itr-f.begin()]-a[idx-1]);
                    st.insert(a[idx]-(d[i]+f[itr-f.begin()]));
                    ans=min(ans,*prev(st.end()));
                }
            }
            st.clear();
            st.insert(mx2);
            auto end=upper_bound(all(f),a[idx-1]+mx/2-d[i]);
            if(end!=f.begin())
            {
                end=prev(end);
                // cout<<"index_upper="<<end-f.begin()<<endl;
                if(d[i]+f[end-f.begin()]>=a[idx-1])
                {
                    // cout<<"upper"<<endl;
                    st.insert(d[i]+f[end-f.begin()]-a[idx-1]);
                    st.insert(a[idx]-d[i]-f[end-f.begin()]);
                    ans=min(ans,*prev(st.end()));
                }
            }
        }   
        cout<<ans<<endl;
    }
    return 0;
}


