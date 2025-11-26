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
        vector<int>d(n);
        for(int i=0;i<n;i++)cin>>d[i];
        bool ok=1;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)ans.push_back(d[i]);
            else 
            {
                if((int)ans.back()+d[i]>=0 && (int)ans.back()-d[i]>=0 && (int)ans.back()+d[i]!=(int)ans.back()-d[i])
                {
                    ok=0;
                    break;
                }
                else if((int)ans.back()+d[i]<0 && (int)ans.back()-d[i]<0)
                {
                    ok=0;
                    break;
                }
                else if((int)ans.back()+d[i]>=0)
                ans.push_back((int)ans.back()+d[i]);
                else ans.push_back((int)ans.back()-d[i]);
            }
        }
        if(!ok)cout<<-1<<endl;
        else 
        {
            for(auto& u : ans)cout<<u<<" ";
            cout<<endl;
        }
    }
    return 0;
}


// void solve(){
// int n;
// cin>>n;
// int x;
// int sum,mi,pi;
// int d[n],arr[n];
// bool f=0;
// loop(n){
//   cin>>  arr[i];
// }
// loop(n){
//     if(i==0){
//         d[i]=arr[i];
//         continue;
//     }
//     if(arr[i]==0){
//         d[i]=d[i-1];
//         continue;
//     }
//     if(d[i-1]+arr[i]>0&&d[i-1]-arr[i]>0){
//         cout<<-1;
//         f=1;
//         break;
//     }
//     d[i]=d[i-1]+arr[i];
// }
// if(f)return;
// loop(n){
// cout<<d[i]<<" ";}
// }