// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// signed main()
// {
//     int t;
//     cin>>t;
//     for(int c=1;c<=t;c++)
//     {
//         int n,m;
//         cin>>n>>m;
//         double ans=0;
//         vector<double>vec(n);
//         for(int i=0;i<n;i++)cin>>vec[i];
//         sort(vec.begin(),vec.end());
//         while(m>1)
//         {
//             ans+=vec[(int)vec.size()-1];
//             vec.pop_back();
//             m--;
//         }
//         int sz=vec.size();
//         if(sz%2==0)
//         {
//             ans+=(vec[(sz/2)]+vec[(sz/2)-1])/2.0;
//         }     
//         else ans+=vec[sz/2];
//         cout<<"Case #"<<c<<": "<<ans<<endl;
//     }
// }
#include<bits/stdc++.h>
using namespace std;
// #define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,m;
        cin>>n>>m;
        double ans=0;
        vector<double>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i],ans+=vec[i];
        sort(vec.begin(),vec.end());
        if(n==m)
        {
            cout<<"Case #"<<c<<": "<<ans<<endl;
        }
        else 
        {
            double ans=0;
            ans+=((vec[0]+vec[1])/2.0);
            for(int i=2;i<n;i++)ans+=vec[i];
            cout<<"Case #"<<c<<": "<<ans<<endl;
        }
    }
    return 0;
}