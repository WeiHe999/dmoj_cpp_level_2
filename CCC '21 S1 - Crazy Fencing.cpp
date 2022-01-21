#include <bits/stdc++.h>
using namespace std;

int main()
{  
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <double> vec1(n + 1), vec2(n);
    for (int i = 0; i <= n; i++) cin >> vec1[i];
    for (int i = 0; i < n; i++) cin >> vec2[i];
    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    {   
        if (vec1[i] == vec1[i - 1])
        {
            ans += vec1[i] * vec2[i - 1];
            continue;
        }
        ans += (vec2[i - 1] * min(vec1[i], vec1[i - 1])) + ((max(vec1[i], vec1[i - 1]) - min(vec1[i], vec1[i - 1])) * vec2[i - 1] / 2.0);
    }
    cout << fixed << setprecision(5) << ans << endl;
}
