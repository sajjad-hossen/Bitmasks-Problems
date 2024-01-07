#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define must ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        int ans=-1;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
            ans=max(ans,arr[i]);
        }
        set<int>st;
        st.insert(arr[1]);
        int xor_=arr[1];
        for(int i=2; i<=n; i++)
        {
            xor_^=arr[i];
            ans=max(ans,xor_);
            for(auto it:st)
            {
                ans=max(ans,xor_^it);
            }
            st.insert(xor_);
        }
        cout<<ans<<endl;
    }
}
