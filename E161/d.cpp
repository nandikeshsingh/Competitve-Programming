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
        vector<int>a(n),d(n);
        set<int>st,die;
        for(int i=0;i<n;i++)cin>>a[i],st.insert(i);
        for(int i=0;i<n;i++)cin>>d[i];
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(d[i]<a[i+1])
                {
                    die.insert(i);
                }
            }
            else if(i==n-1)
            {
                if(d[i]<a[i-1])
                {
                    die.insert(i);
                }
            }
            else 
            {
                if(d[i]<a[i+1]+a[i-1])
                {
                    die.insert(i);
                }
            }
        }
        for(auto& u :die)st.erase(u);
        ans.push_back(sz(die));
        while(sz(die))
        {
            set<int>check;
            for(auto& u : die)
            {
                auto itr=st.upper_bound(u);
                if(itr!=st.end())check.insert(*itr);
                if(itr!=st.begin())check.insert(*prev(itr));
            }
            die.clear();
            for(auto& u : check)
            {
                int atot=0;
                auto nxt=st.upper_bound(u);
                if(nxt!=st.end())atot+=a[*nxt];
                if(st.find(u)!=st.begin())
                {
                    auto pre=prev(st.find(u));
                    atot+=a[*pre];
                }
                if(atot>d[*st.find(u)])
                {
                    die.insert(u);
                }
            }
            for(auto& u : die)st.erase(u);
            ans.push_back(sz(die));
        }
        while(sz(ans)<n)ans.push_back(0);
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}

