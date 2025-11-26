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
        int l,r,x;
        cin>>l>>r>>x;
        int a,b;
        cin>>a>>b;
        if(b<l || b>r)cout<<-1<<endl;
        else if(abs(a-b)>=x)cout<<1<<endl;
        else if(a==b)cout<<0<<endl;
        else 
        {
            // if(a>b)
            // {
            //     swap(a,b);
            //     swap(l,r);
            // }
            if(b>a)
            {
                // int need=abs(min(b+x,r)-a);
                // int bst=1e18;
                // if(need>=x)bst=min(bst,1LL);
                // need=abs(max(b-x,l)-a);
                // if(need>=x)bst=min(bst,1LL);
                // if(bst==1e18)cout<<-1<<endl;
                // else cout<<bst+1<<endl;
                int rim=b-a;
                if(a-(x)>=l)cout<<2<<endl;
                else if(a+x+rim<=r)cout<<2<<endl;
                else if(b+x>r && b-x<l)cout<<-1<<endl;
                else if(a-x<l && a+x>r)cout<<-1<<endl;
                else if(a+x<=r)
                {
                    // cout<<"r-b+x"<<r-b+x<<endl;
                    if(r-b+x>=x)cout<<3<<endl;
                }
                else if(a-x>=l)
                {
                    if(b+x-l>=x)cout<<3<<endl;
                }
                else cout<<-1<<endl;
            }
            else if(a>b)
            {
                // int need=abs(min(b+x,r)-a);
                // int bst=1e18;
                // if(need>=x)bst=min(bst,1LL);
                // need=abs(max(b-x,l)-a);
                // if(need>=x)bst=min(bst,1LL);
                // if(bst==1e18)cout<<-1<<endl;
                // else cout<<bst+1<<endl;
                int rim=a-b;
                if(b-(x)>=l)cout<<2<<endl;
                else if(b+x+rim<=r)cout<<2<<endl;
                else if(b+x>r && b-x<l)cout<<-1<<endl;
                else if(a-x<l && a+x>r)cout<<-1<<endl;
                else if(b+x<=r)
                {
                    // cout<<"r-b+x"<<r-b+x<<endl;
                    if(r-a+x>=x)cout<<3<<endl;
                }
                else if(b-x>=l)
                {
                    if(a+x-l>=x)cout<<3<<endl;
                }
                else cout<<-1<<endl;
            }
        }
    }
    return 0;
}
