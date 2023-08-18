#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long x;
    cin >> x;
    for (long long j = 0; j < x; j++)
    {
        long long y;
        cin >> y;
        long long count = 0;
        set<long long> s1, s2;
        bool first_string = true;
        for (long long i = 0; i < y; i++) {
            string a;
            cin >> a;
            long long hash1 = 0, hash2=0;
            bool keep_count = true;
            if (first_string)
            {
                count++;
                first_string = false;
                keep_count = false;
            }            

            for (long long i1 = 0; i1 < a.size(); i1++)
            {
                hash1 += (37*hash1%MOD+(a[i1] - 'a'+1)+MOD)%MOD;
                hash2 += (67*hash2%MOD+(a[i1] - 'a'+1)+MOD)%MOD;

                if(keep_count)
                {
                    if (s1.count(hash1) && s2.count(hash2))
                    {
                        count++;
                    }
                    else
                    {
                        count++;
                        keep_count = false;
                    }
                    
                }
     
                s1.insert(hash1);
                s2.insert(hash2);
      
            }
        }
        cout << "Case #"<<j+1<<": "<<count << endl;

    }

}
