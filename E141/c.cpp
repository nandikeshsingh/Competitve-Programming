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
        int n,m;
        cin>>n>>m;
        vector<int>a(n+1);
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vec.push_back({a[i],i});
        }   
        sort(all(vec));
        int cnt=0;
        int cur=0;
        for(int i=0;i<sz(vec);i++)
        {
            if(cur+vec[i].first<=m)
            {
                cur+=vec[i].first;
                cnt++;
            }
            else break;
        }
        if(cnt==n)cout<<1<<endl;
        else 
        {
            int ans=n-cnt+1;
            int rim=m-cur;
            if(vec[0].first+rim>=vec[cnt].first)ans--;
            cout<<ans<<endl;
        }
    }
    return 0;
}

DDS_DomainId_t domain_id = 10;
// MyDomainParticipantListener is user defined and
// extends DDSDomainParticipantListener
MyDomainParticipantListener* participant_listener = 
	new MyDomainParticipantListener(); // or = NULL
// Create the participant
DDSDomainParticipant* participant = factory->create_participant(domain_id, DDS_PARTICIPANT_QOS_DEFAULT, participant_listener, DDS_STATUS_MASK_ALL);
if (participant == NULL) {
	// ... error
};



