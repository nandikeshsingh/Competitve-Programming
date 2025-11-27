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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(auto& u : s)
        cnt+=(u=='1');
        if(cnt%2 || cnt<2)
        {
            cout<<"NO"<<endl;
            continue;
        }

        vector<pair<int,int>>ans;
        int start=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                start=i;
                break;
            }
        }
        set<int>st;
        set<int>zr;
        for(int i=0;i<n;i++)st.insert(i);
        int cur=start-1;
        int root=cur;
        if(root<0)root+=n;
        bool ok=1;
        bool f=1;
        while(cur>=start || f==1)
        {
            // cout<<"cur="<<cur<<endl;
            if(cur<0)cur+=n,f=0;
            // int now=cur;
            int back=cur-1;
            if(back<0)back+=n;
            if(s[cur]=='1')cur--;
            else 
            {
                if(s[cur]=='0' && s[back]=='0')
                {
                    ans.push_back({cur,back});
                    if(ok)
                    zr.insert(cur),ok=0;
                    if(st.count(cur))
                    st.erase(st.find(cur));
                    if(st.count(back))
                    st.erase(st.find(back));
                    cur--;
                }
                else if(s[cur]=='0' && s[back]=='1')
                {
                    ans.push_back({cur,back});
                    if(ok)zr.insert(cur),ok=0;
                    if(st.count(cur))
                    st.erase(st.find(cur));
                    if(st.count(back))
                    st.erase(st.find(back));
                    cur-=2;
                    ok=1;
                }
            }
        }
        // int root=*st.begin();
        // st.erase(st.begin());
        for(auto& u : st)if(u!=root)ans.push_back({u,root});
        for(auto& u : zr)if(u!=root)ans.push_back({u,root});
        cout<<"YES"<<endl;
        assert((int)ans.size()==n-1);
        for(auto& u : ans)cout<<u.first+1<<" "<<u.second+1<<endl;
    }
    return 0;
}

