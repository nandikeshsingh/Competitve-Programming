#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    vector<int>prime(31624,1);
    vector<int>pp;
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=sqrt(1e9);i++)
    {
        if(prime[i])
        {
            pp.push_back(i);
            for(int j=i*2;j<=sqrt(1e9);j+=i)
            {
                prime[j]=0;
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        bool ok=1;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            for(auto& p : pp)
            {
                if(p>vec[i])break;
                if(vec[i]%p==0)
                {
                    if(st.count(p))
                    {
                        ok=0;
                        break;
                    }
                    else st.insert(p);
                    while(vec[i]%p==0)vec[i]/=p;
                }
            }
            if(!ok)break;
            if(vec[i]>1)
            {
                if(st.count(vec[i]))
                {
                    ok=0;
                    break;
                }
                else 
                st.insert(vec[i]);
            }
            if(!ok)break;
        }
        if(!ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


