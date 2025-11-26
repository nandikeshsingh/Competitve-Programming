#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int tot=0;
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='1' && s[i+1]=='0')tot+=10;
            else if(s[i]=='0' && s[i+1]=='1')tot+=1;
            else if(s[i]=='1' && s[i+1]=='1')tot+=11;
            else if(s[i]=='0' && s[i+1]=='0')tot+=0;
        }
          for(int i=0;i<n;i++)
        {
            if(s[i]=='1')cnt++;

        }
        if(k==0 || cnt==0 ||cnt==n)
        {
            cout<<tot<<endl;
            continue;
        }
        if(n==2)
        {
            if(s[0]=='1' && s[1]=='0' )cout<<1<<endl;
            else cout<<tot<<endl;
            // cout<<"inside"<<endl;
            continue;
        }
      
        if(s[0]=='1' && s[n-1]=='1')cout<<tot<<endl;
        else if(s[0]=='0' && s[n-1]=='1')
        {
            if(cnt>1)
            {
                int first=-1;
                for(int i=0;i<n;i++)
                {
                    if(s[i]=='1')
                    {
                        first=i;
                        break;
                    }
                }
                if(first<=k)cout<<tot-1<<endl;
                else cout<<tot<<endl;
            }
            else if(cnt==1)cout<<tot<<endl;
        }
        else if(s[0]=='1' && s[n-1]=='0')
        {
            int last=-1;
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='1')
                {
                    last=i;
                    break;
                }
            }
            if(cnt>1 && (n-1-last)<=k)
            {
                cout<<tot-10<<endl;
            }
            else if(cnt==1 && (n-1-last)<=k)cout<<1<<endl;
            else cout<<tot<<endl;
        }
        else if(s[0]=='0' && s[n-1]=='0')
        {
            int last=-1;
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='1')
                {
                    last=i;
                    break;
                }
            }
                int first=-1;
                for(int i=0;i<n;i++)
                {
                    if(s[i]=='1')
                    {
                        first=i;
                        break;
                    }
                }
                if(cnt==1)
                {
                    if((n-1-last)<=k)cout<<tot-10<<endl;
                    else if(first<=k)cout<<tot-1<<endl;
                    else cout<<tot<<endl;
                }
                else 
                {
                    if((n-1-last+first)<=k)cout<<tot-11<<endl;
                    else if((n-1-last)<=k)cout<<tot-10<<endl;
                    else if(first<=k)cout<<tot-1<<endl;
                    else cout<<tot<<endl;
                }
        }
    }
    return 0;
}
