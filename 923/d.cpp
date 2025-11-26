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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int q;cin>>q;
        stack<int>st;
        vector<int>nxt(n,-1);
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else 
            {
                while(a[st.top()]!=a[i])
                {
                    nxt[st.top()]=i;
                    st.pop();
                    if(st.empty())break;
                }
                st.push(i);
            }
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;r--;
            if(nxt[l]==-1)cout<<-1<<" "<<-1<<endl;
            else if(nxt[l]>r)cout<<-1<<" "<<-1<<endl;
            else cout<<l+1<<" "<<nxt[l]+1<<endl; 
        }
    }
    return 0;
}


