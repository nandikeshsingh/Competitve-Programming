#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    int tot=0;
    vector<int>m(n+2,0);
    for(int i=1;i<=n;i++)cin>>m[i],tot+=m[i];
    vector<int>l(n+1,0),r(n+2,0);
    stack<pair<int,int>>st;
    st.push({0,0});
    for(int i=1;i<=n;i++)
    {
        if(m[i]>=m[i-1])l[i]=m[i]+l[i-1];
        else 
        {
            while(st.top().first>m[i])
            st.pop();
            l[i]=((i-st.top().second)*m[i])+l[st.top().second];
        }
        st.push({m[i],i});
    }
    while(st.size()>0)st.pop();
    st.push({0,n+1});
    for(int i=n;i>=1;i--)
    {
        if(m[i]>=m[i+1])r[i]=m[i]+r[i+1];
        else 
        {
            while(st.top().first>m[i])st.pop();
            r[i]=((st.top().second-i)*m[i])+r[st.top().second];
        }
        st.push({m[i],i});
    }
    int mx=0;
    int pos=-1;
    for(int i=1;i<=n;i++)
    {
        if(l[i]+r[i]-m[i]>mx)
        {
            mx=l[i]+r[i]-m[i];
            pos=i;
        }
    }
    int cur=m[pos];
    for(int i=pos-1;i>=1;i--)
    {
        if(m[i]>cur)m[i]=cur;
        else cur=m[i];
    }
    cur=m[pos];
    for(int i=pos+1;i<=n;i++)
    {
        if(m[i]>cur)m[i]=cur;
        else cur=m[i];
    }
    for(int i=1;i<=n;i++)cout<<m[i]<<" ";
    cout<<endl;
    return 0;   
}
