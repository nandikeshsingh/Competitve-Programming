#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
#define sz(v) (int)v.size()
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int l,n;
        cin>>l>>n;
        int ans=0;
        int cur=0;
        char last='#';
        for(int i=0;i<n;i++)
        {
            int d;cin>>d;
            char c;cin>>c;
            if(last==c || last=='#')
            {
                cur+=d;
                ans+=(cur/l);
                cur%=l;
            }
            else 
            {
                 if(cur>d)
                 {
                    cur-=d;
                    cur=-cur;
                 }
                 else 
                 {
                    d-=cur;
                    cur=0;
                    //dir changed
                    ans+=(d/l);
                    cur+=(d%l);
                    // if(cur<0)cur+=l;
                 }
            }
            last=c;
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}

