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
        int m,s;
        cin>>m>>s;
        vector<int>b(m);
        set<int>st;
        for(int i=0;i<m;i++)cin>>b[i],st.insert(b[i]);
        sort(all(b));
        int last=b.back();
        for(int i=1;i<=last;i++)
        {
            if(st.count(i)==0)
            {
                s-=i;
            }
        }
        if(s<0)cout<<"NO"<<endl;
        else if(s==0)cout<<"YES"<<endl;
        else 
        {
            int cur=last+1;
            bool ok=1;
            while(s>0)
            {
                s-=cur;
                cur++;
            }
            if(s==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


