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
        set<int>st;
        vector<int>cnt(101);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            st.insert(x);
            cnt[x]++;
        }
        if(sz(st)==1)cout<<"NO"<<endl;
        else 
        {
            cout<<"YES"<<endl;
            for(int i=100;i>=1;i--)
            {
                if(cnt[i])
                {
                    cout<<i<<" ";
                    cnt[i]--;
                }
            }
            for(int i=100;i>=1;i--)
            {
                if(cnt[i])
                {
                    while(cnt[i]--)
                    {
                        cout<<i<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}


