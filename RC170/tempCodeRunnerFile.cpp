  // for(int i=1;i<n-1;i++)
    // {
    //     int mid=2*a[i];
    //     for(int j=1;j<=mid-1;j++)
    //     {
    //         if(pos[j].size()==0)continue;
    //         auto itr=pos[j].lower_bound(i);
    //         itr=prev(itr);
    //         if(pos[mid-j].size()==0)continue;
    //         auto it=pos[mid-j].upper_bound(i);
    //         if(it!=pos[mid-j].end() && itr!=pos[j].end())
    //         {
    //             vec.push_back({*it,*itr});
    //         }
    //     }
    // }