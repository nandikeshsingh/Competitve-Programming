#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<int>vec(n+1);
        bool ch=1;
        for(int i=1;i<=n;i++)
        {
            cin>>vec[i];
            if(vec[i]!=0)ch=0;
        }
        vec[0]=0;
        if(n==1)
        {
            if(vec[1]==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if(ch==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(vec[1]<=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        while(vec.back()==0)vec.pop_back();
        for(int i=0;i<=n;i++)vec[i]=-vec[i];
        vec.push_back(0);
        reverse(vec.begin(),vec.end());
        vec.pop_back();
        bool ok=1;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            vec[i]+=vec[i-1];
            if(vec[i]==0)
            {
                cur=i;
                break;
            }
            if(vec[i]<0)
            {
                ok=0;
                break;
            }
        }
        if(!ok)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=cur+1;i<=n;i++)
        {
            if(vec[i]!=0)
            {
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

