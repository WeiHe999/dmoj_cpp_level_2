#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int find_smallest_gap()
{
    int smallest_gap = 2000000, current_start = -1;
    for (int i = 0; i <= 1000000; i++)
    {
        if (a[i] != 0)
        {
            if (current_start != -1 && a[current_start] != a[i] && i - current_start < smallest_gap) smallest_gap = i - current_start;
            current_start = i;
        }
    }
    return smallest_gap;
}

int num_sick_clusters()
{
    int last_state = 0, ans = 0;
    for (int i = 0; i <= 1000000; i++)
    {
        if (a[i] != 0)
        {
            if (a[i] != last_state && a[i] == 1) ans++;
            last_state = a[i];
        }
    }
    return ans;
}
 
int num_sick_gaps(int r)
{
    int ans = 0, current_start = 0;
    for (int i = 0; i <= 1000000; i++)
    {
        if (a[i] != 0)
        {
            if (current_start != 0 && a[current_start] == 1 && a[i] == 1 && i - current_start >= r) ans++;
            current_start = i;
        }
    }
    return ans;
}

int main()
{
    int n, x, s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> s;
        if (s == 1)
        {
            a[x] = 1;
        }
        if (s == 0)
        {
            a[x] = -1;
        }
    }
    int res = find_smallest_gap();
    cout << num_sick_clusters() + num_sick_gaps(res) << endl;
}
