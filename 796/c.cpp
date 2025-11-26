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
        vector<int>arr(26,0);
        for(int i=0;i<2*n;i++)
        {
            string s;
            cin>>s;
            for(auto& u : s)
            arr[u-'a']++;
        }
        string t;
        cin>>t;
        for(auto& u : t)arr[u-'a']++;
        char ans;
        for(int i=0;i<26;i++)
        {
            if(arr[i]%2)
            {
                ans=(i+97);
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

