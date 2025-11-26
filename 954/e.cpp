#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vi a(n);
        rep(i,0,n-1)cin>>a[i];
        map<int,int>mp;
        rep(i,0,n-1)mp[a[i]]++;
        int ans=0;
        set<int>st;
        for(auto& u : mp)
        {
            if(u.S%2!=0)st.insert(u.F);
        }
        set<int>cst=st;
        // cout<<"Printing st"<<endl;
        // for(auto& u : st)cout<<u<<" ";
        // cout<<endl;
        if(sz(st)%2==0)
        {
                bool ok=1;
            while(sz(st)>=2)
            {
                int cur=*st.begin();
                st.erase(st.begin());
                int rem=-1;
                for(auto& u : st)
                {
                    if((u-cur)%k==0)
                    {
                        ans+=(u-cur)/k;
                        rem=u;
                        break;
                    }
                }
                if(rem!=-1)
                {
                    st.erase(st.find(rem));
                }
                else 
                {
                    ok=0;
                    break;
                }
            }
            cout<<"ans="<<endl;
            if(ok)cout<<ans<<endl;
            else cout<<-1<<endl;
        }
        else 
        {
                        cout<<"Printing set before"<<endl;
            for(auto& u : st)cout<<u<<" ";
            cout<<endl;
            // st.erase(st.begin());
            bool ok=1;
            while(sz(st)>=2)
            {
                int cur=*st.begin();
                st.erase(st.begin());
                int rem=-1;
                for(auto& u : st)
                {
                    if((u-cur)%k==0)
                    {
                        ans+=(u-cur)/k;
                        rem=u;
                        break;
                    }
                }
                if(rem!=-1)
                {
                    st.erase(st.find(rem));
                }
                else 
                {
                    ok=0;
                    break;
                }
            }
            cout<<"ok="<<ok<<" ans="<<ans<<endl;
            cst.erase(cst.begin());
            // cout<<"Printing set after"<<endl;
            // for(auto& u : cst)cout<<u<<" ";
            // cout<<endl;
            map<int,set<int>>mp;
            for(auto& u : cst)
            {
                mp[u%k].insert(u);
            }
                 bool okk=1;
            int odd_ans=0;
            for(auto& u : mp)
            {
                set<int>cst=u.S;
                
            while(sz(cst)>=2)
            {
                int cur=*cst.begin();
                cst.erase(cst.begin());
                int rem=-1;
                for(auto& u : cst)
                {
                    if((u-cur)%k==0)
                    {
                        odd_ans+=(u-cur)/k;
                        rem=u;
                        break;
                    }
                }
                if(rem!=-1)
                {
                    cst.erase(cst.find(rem));
                }
                else 
                {
                    okk=0;
                    break;
                }
            }
            }
           
            cout<<"okk="<<okk<<" odd_ans="<<odd_ans<<endl;
            cout<<"ans="<<endl;
            if(ok==0 && okk==0)cout<<-1<<endl;
            else if(ok==0 && okk!=0)cout<<odd_ans<<endl;
            else if(ok!=0 && okk==0)cout<<ans<<endl;
            else cout<<min(ans,odd_ans)<<endl;
        }
    }
    return 0;
}


