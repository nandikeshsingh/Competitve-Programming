#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        set<int>nz,z;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<b[i])
            {
                ok=0;
                break;
            }
            if(b[i]==0)
            {
                z.insert(a[i]-b[i]);
            }
            else 
            {
                nz.insert(a[i]-b[i]);
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else{
            if(nz.size()>1)
            {
                cout<<"NO"<<endl;

            }
            else if(nz.size()==0) 
            {
                cout<<"YES"<<endl;
            }
            else 
            {
                if(z.size()==0)
                {
                    cout<<"YES"<<endl;
                }
                else 
                {
                    int val=*z.rbegin();
                    int cur=*nz.begin();
                    if(val<=cur)
                    {
                        cout<<"YES"<<endl;
                        
                    }
                    else cout<<"NO"<<endl;
                
                }
            }
        }

    }
    return 0;
}

