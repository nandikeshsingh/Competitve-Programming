#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    set<int>st;
    map<int,int>mp;
    for(int i=0;i<=n;i++)st.insert(i);
    for(int i=0;i<n;i++)cin>>a[i],st.erase(a[i]),mp[a[i]]++;
    while(q--)
    {
        int i,x;
        cin>>i>>x;
        i--;
        mp[a[i]]--;
        if(mp[a[i]]==0)st.insert(a[i]);
        a[i]=x;
        mp[a[i]]++;
        st.erase(a[i]);
        cout<<*st.begin()<<endl;
    }
    
    return 0;
}


