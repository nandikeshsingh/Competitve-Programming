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
        int x=0,y=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==1)x++;
            else y++;
        }
        if(x==y)
        {
            cout<<n<<endl;
            for(int i=1;i<=n;i++)cout<<i<<" "<<i<<endl;
        }
        else if((abs(x-y))%2)cout<<"-1"<<endl;
        else if(x>y)
        {
            int k=y+y+(x-y)/2;
            int pr=(x-y)/2;
            cout<<k<<endl;
            int l=1,r=1;
            while(r<=n)
            {
                if(a[l]==-1)
                {
                    cout<<l<<" "<<l<<endl;
                    l++;
                    if(r<l)r=l;
                }
                else if(a[l]==1)
                {
                    if(r==l && r==n)
                    {
                        cout<<l<<" "<<l<<endl;
                        r++;
                    }
                    else if(r==l && pr>0)
                    {
                        r++;
                    }
                    else if(r==l && pr==0)
                    {
                        cout<<l<<" "<<l<<endl;
                        l++;
                        if(l>r)r=l;
                    }
                    else 
                    {
                        if(a[r]==1)
                        {
                            cout<<l<<" "<<r<<endl;
                            pr--;
                            r++;
                            l=r;
                        }
                        else if(a[r]==-1)
                        {
                            cout<<l<<" "<<l<<endl;
                            l++;
                        }
                    }
                }
            }
        }
        else 
        {
            for(int i=1;i<=n;i++)a[i]*=-1;
            int k=x+x+(y-x)/2;
            int pr=(y-x)/2;
            cout<<k<<endl;
            int l=1,r=1;
            while(r<=n)
            {
                if(a[l]==-1)
                {
                    cout<<l<<" "<<l<<endl;
                    l++;
                    if(r<l)r=l;
                }
                else if(a[l]==1)
                {
                    if(r==l && r==n)
                    {
                        cout<<l<<" "<<l<<endl;
                        r++;
                    }
                    else if(r==l && pr>0)
                    {
                        r++;
                    }
                    else if(r==l && pr==0)
                    {
                        cout<<l<<" "<<l<<endl;
                        l++;
                        if(l>r)r=l;
                    }
                    else 
                    {
                        if(a[r]==1)
                        {
                            cout<<l<<" "<<r<<endl;
                            pr--;
                            r++;
                            l=r;
                        }
                        else if(a[r]==-1)
                        {
                            cout<<l<<" "<<l<<endl;
                            l++;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


