#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    sort(all(x));   
    int l=x[0],r=x[0];
    if(x[0]>1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int nl=l+x[i];
        int nr=r+x[i];
        if((nl<=r+1) || ((nl>r+1)&&(x[i]==r+1)))
        r=nr;
        else 
        {
            if(nl>=r+2 && x[i]!=r+1)
            cout<<r+1<<endl;
            else if(nl>r+2)
            {
                if(x[i]!=r+1)
                cout<<r+1<<endl;
                else cout<<r+2<<endl;
            }
            return 0;
        }
    }
    cout<<r+1<<endl;
    return 0;
}


