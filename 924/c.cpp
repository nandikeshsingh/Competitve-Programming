#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
set<int>st;
int div(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            st.insert(i);
            st.insert(n/i);
            if (n / i == i) 
                cnt++; 
            else 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        st.clear();
        int n,x;
        cin>>n>>x;
        int xx=x;
        int nn=n;
        int up=x;
        int ans=0;
        if(up==n)ans++;
        n-=x;
        if(n%2==0)
        {
            n/=2;
            div(n);
            // ans+=div(n);
        }
        if(x>1)
        {
            if((nn+x-2)%2==0)
            {
                nn+=x;
                nn-=2;
                nn/=2;
                div(nn);
                // ans+=div(nn);
            }
        }
        for(auto& u : st)
        {
            if(u+1>=xx)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


