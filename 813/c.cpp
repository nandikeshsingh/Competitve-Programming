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
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        int ans=0;
        set<int>s;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            if(s.count(vec[i]))vec[i]=0;
            if(vec[i]<st.top())
            {   
                while(st.top()>0)
                {
                    s.insert(st.top());
                    st.pop();
                }
                st.push(vec[i]);
            }
            else st.push(vec[i]);
        }
        cout<<(int)s.size()<<endl;
    }
    return 0;
}


