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
    vector<int>x(n+1);
    for(int i=1;i<=n;i++)cin>>x[i];
    stack<int>st;
    st.push(0);
    for(int i=1;i<=n;i++)
    {
        while(x[st.top()]>=x[i])
        st.pop();
        cout<<st.top()<<" ";
        st.push(i);
    }
    return 0;
}


