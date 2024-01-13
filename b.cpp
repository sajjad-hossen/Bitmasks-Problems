#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 1;
const int mod = 998244353;
signed main()
{
    int t = 1;
    while (t--)
    {
        int u, v;
        cin >> u >> v;
        if (abs(u - v) % 2 == 1 || v < u)
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<int> vt[100];
            vt[0].push_back(u);
            for (int i = 1; i <= 99; i++)
            {
                vt[i].push_back(0);
            }
            bitset<64> arr(u);
            int res = v - u;
            for (int i = 61; i >= 0; i--)
            {
                int indx = 1;
                if(arr[i]==0)
                {
                    indx=0;
                }
                while (res >= (2LL * (1LL << i)))
                {
                    vt[indx].push_back(1LL << i);
                    indx++;
                    vt[indx].push_back(1LL << i);
                    res -= (2LL * (1LL << i));
                    indx++;
                }
            }
            if(res!=0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                vector<int>ans;
                for(int i=0; i<100; i++)
                {
                    int sum=0;
                    for(auto it:vt[i])
                    {
                        sum+=it;
                    }
                    if(sum>0)
                        ans.push_back(sum);
                }
                cout<<ans.size()<<endl;
                for(auto it:ans)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
            }
        }
    }
}
