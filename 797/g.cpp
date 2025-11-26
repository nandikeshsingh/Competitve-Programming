#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false);cin.tie(NULL);
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
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        set<int>st;
        st.insert(0);
        int last=vec[0];
        for(int i=1;i<n;i++)
        {
            if(vec[i]<last)
            {
                st.insert(i);
                last=vec[i];
            }
        }
        while(m--)
        {
            int k,d;
            cin>>k>>d;
            k--;vec[k]-=d;
            if(st.find(k)!=st.end())
            {
                auto itr=st.upper_bound(k);
                while(1)
                {
                    if(itr==st.end())break;
                    if(vec[(*itr)]>=vec[k])
                    {
                        auto val=itr;
                        itr=next(itr);
                        st.erase(val);
                        if(itr==st.end())break;
                    }
                    else break;
                }
                cout<<st.size()<<" ";
            }
            else 
            {
                auto itr=st.upper_bound(k);
                auto it=prev(itr);
                auto cur=*it;
                if(vec[cur]>vec[k])
                {
                    while(1)
                    {
                        if(itr==st.end())break;
                        if(vec[(*itr)]>=vec[k])
                        {
                            auto val=*itr;
                            itr=next(itr);
                            st.erase(val);
                            if(itr==st.end())break;
                        }
                        else break;                      
                    }
                    st.insert(k);
                }
                cout<<st.size()<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

