#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
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
        vector<int>a(m);
        for(int i=0;i<m;i++)cin>>a[i];
        sort(all(a));
        multiset<int>st;
        for(int i=1;i<m;i++)
        {
            st.insert(a[i]-a[i-1]-1);
        }
        int tot=a[m-1]-a[0]+1;
        if(n-tot>0)
        st.insert(n-tot);
        int ans=m;
        int cur=0;
        while(st.size()>0)
        {
            // cout<<"in"<<endl;
            int val=(*st.rbegin())-cur;
            st.erase(prev(st.end()));
            // cout<<"val="<<val<<endl;
            // cout<<"cur="<<cur<<endl;
            // cout<<"Printing set"<<endl;
            // for(auto& u :st)cout<<u<<" ";
            // cout<<endl;
            if(val<=0)break;
            for(int i=0;i<2;i++)
            { 
                // cout<<"i="<<i<<endl;
                int cnt=0;
                while((*st.begin())-cur==0 && st.size()>0)st.erase((st.begin()));
                // cout<<"out"<<endl;
                while((*st.begin())-cur==1 && st.size()>0)
                {
                    st.erase((st.begin()));
                    cnt++;
                }
                // cout<<"out1"<<endl;
                if(i%2==0)
                {
                    if(val>=2)
                    ans+=((st.size())*2 + 1);
                    else ans+=((st.size()*2));
                }
                else ans+=((st.size())*2);
                ans+=cnt;
                cur+=2;
                // cout<<"val="<<val<<endl;
                if(i%2==0)
                {
                    if(val>=2)val-=2;
                    else val--;
                }
                else val--;
                
                // cout<<"ans="<<ans<<endl;
                // cout<<"size="<<st.size()<<endl;
                if(val==0)break;
            }   
           
        }
        // cout<<"Printing"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}