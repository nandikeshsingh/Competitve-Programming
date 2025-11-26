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
        vector<int>a(n);
        set<int>st;
        for(int i=0;i<n;i++)cin>>a[i],st.insert(a[i]);
        if(st.size()==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else 
        {
            int x=0,y=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]%10==5 || a[i]%10==0)x=1;
                else y=1;
            }
            if(x==1 && y==1)cout<<"NO"<<endl;
            else if(x==1 && y==0)
            {
                set<int>st1;
                for(int i=0;i<n;i++)
                {
                    if(a[i]%10==0)st1.insert(a[i]);
                    else st1.insert(a[i]+5);
                }
                if(st1.size()==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(x==0 && y==1)
            {
                for(int i=0;i<n;i++)
                {
                    if(a[i]%10==1)a[i]+=15;
                    else if(a[i]%10==2)a[i]+=14;
                    else if(a[i]%10==4)a[i]+=12;
                    else if(a[i]%10==8)a[i]+=8;
                    else if(a[i]%10==7)a[i]+=19;
                    else if(a[i]%10==9)a[i]+=17;
                    else if(a[i]%10==3)a[i]+=3;
                }
                sort(all(a));
                int mx=a[n-1];
                set<int>st2;
                st2.insert(mx);
                for(int i=0;i<n-1;i++)
                {
                    int rim=mx-a[i];
                    int div=rim/20;
                    a[i]+=div*20;
                    st2.insert(a[i]);
                }
                if(st2.size()==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}