#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    vector<pair<int,int>>vec;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]>b[i])swap(a[i],b[i]);
        mp[b[i]]=a[i];
        vec.push_back({a[i],1});
        vec.push_back({b[i],-1});
    }
    sort(all(vec));
    stack<pair<int,int>>st;
    bool ok=1;
    for(int i=0;i<2*n;i++)
    {
        if(st.empty())
        {
            st.push(vec[i]);
        }
        else 
        {
            if(vec[i].second==1)st.push(vec[i]);
            else 
            {
                if(st.empty())
                {
                    ok=0;
                    break;
                }
                pair<int,int>tp=st.top();
                if(tp.first!=mp[vec[i].first])
                {
                    ok=0;
                    break;
                }
                else 
                {
                    st.pop();
                }
            }
        }
    }
    if(!ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


