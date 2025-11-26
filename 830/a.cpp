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
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int now=a[1];
        for(int i=2;i<=n;i++)now=__gcd(now,a[i]);
        set<int>st;
        st.insert(2);
        st.insert(3);
        st.insert(5);
        st.insert(7);
        st.insert(11);
        st.insert(13);
        st.insert(17);
        st.insert(19);
        if(now==1)cout<<0<<endl;
        else 
        {
            bool f=0;
            vector<int>temp=a;
            int first=-1;
            for(int i=n;i>=1;i--)
            {
                temp[i]=__gcd(a[i],i);
                int g=temp[i];
                for(int j=n-1;j>=1;j--)
                g=__gcd(temp[j],g);
                if(g==1)
                {
                    first=n-i+1;
                    f=1;
                    break;
                }
            }
            {
                int x=-1,y=-1;
                for(int i=n;i>=1;i--)
                {   
                    if(x==-1 && y==-1)
                    {
                        if(st.count(i))
                        x=i;
                    }
                    else if(y==-1)
                    {
                        if(st.count(i))
                        y=i;
                    }
                    else break;
                }
                if(first!=-1)
                cout<<min({n+n+2-x-y,first,n})<<endl;
                else cout<<min(n+n+2-x-y,n);
            }
        }
    }   
    return 0;
}


