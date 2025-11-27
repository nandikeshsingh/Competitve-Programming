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
        int a,b,c,d;
        cin>>a>>b>>c>>d;//a-'A',b-'B',c-'AB',d-'BA'
        string s;
        cin>>s;
        int cnt=0;
        for(auto& u : s)
        cnt+=(u=='A');
        if(cnt!=a+c+d)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int any=0;
        int cur=0;
        int n=a+b+2*c+2*d;
        vector<int>sa,sb;
        while(cur<n)
        {
            int last=cur;
            while(last+1<n && s[last]!=s[last+1])last++;
            int len=last-cur+1;
            if(len%2)any+=len/2;
            else 
            {
                if(s[cur]=='A')sa.push_back(len/2);
                else sb.push_back(len/2);
            }
            cur=last+1;
        }
        sort(all(sa));
        sort(all(sb));
        reverse(all(sa));
        reverse(all(sb));
        int cnta=0;
        int cntb=0;
        int posa=(int)sa.size()-1,posb=(int)sb.size()-1;
        for(int i=posa;i>=0;i--)
        {
            if(cnta+sa[i]<=c)cnta+=sa[i],posa--;
            else 
            {
                sa[i]-=(c-cnta);
                cnta=c;
                break;
            }   
        }
        for(int i=posb;i>=0;i--)
        {
            if(cntb+sb[i]<=d)cntb+=(sb[i]),posb--;
            else 
            {
                sb[i]-=(d-cntb);
                cntb=d;
                break;
            }
        }
        if(cnta<c)
        {
            for(int i=posb;i>=0;i--)
            {
                if(cnta+sb[i]-1<=c)cnta+=(sb[i]-1),sb[i]=1;
                else 
                {
                    sb[i]-=(c-cnta);
                    cnta=c;
                    break;
                }
            }
        }
        if(cnta<c)
        {
            if(cnta+any<c)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else 
            {
                any-=(c-cnta);
                cnta=c;
            }
        }

        if(cntb<d)
        {
            for(int i=posa;i>=0;i--)
            {
                if(cntb+sa[i]-1<=d)cntb+=(sa[i]-1),sa[i]=1;
                else 
                {
                    sa[i]-=(d-cntb);
                    cntb=d;
                    break;
                }
            }
        }
        if(cntb<d)
        {
            if(cntb+any<d)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else 
            {
                any-=(d-cntb);
                cntb=d;
            }
        }
        if(cnta==c && cntb==d)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

