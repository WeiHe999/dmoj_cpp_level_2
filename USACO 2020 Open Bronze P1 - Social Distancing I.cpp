#include <bits/stdc++.h>
using namespace std;

int find_largest_interior_gap(string s, int &gap_start)
{
    int biggest_gap = 0, current_start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            if (current_start != -1 && i - current_start > biggest_gap)
            {
                biggest_gap = i-current_start;
                gap_start = current_start;
            }
            current_start = i;
        }
    }
    return biggest_gap;
}
 
int find_smallest_interior_gap(string s)
{
    int smallest_gap = INT_MAX, current_start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            if (current_start != -1 && i - current_start < smallest_gap) smallest_gap = i - current_start;
            current_start = i;
        }
    }
    return smallest_gap;
}
 
int try_cow_in_largest_gap(string s)
{
    int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
    if (largest_gap >= 2)
    {
        s[gap_start + largest_gap / 2] = '1';
        return find_smallest_interior_gap(s);
    } 
    return -1;
}
 
int main()
{
    int n;
    string s, tmp;
    cin >> n >> s;
    int ans = 0;
    int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
    if (largest_gap >= 3)
    {
        tmp = s;
        tmp[gap_start + largest_gap / 3] = '1';
        tmp[gap_start + largest_gap * 2 / 3] = '1';
        ans = max(ans, find_smallest_interior_gap(tmp));
    }
    if (s[0] == '0' && s[n - 1] == '0')
    {
        tmp = s;
        tmp[0] = tmp[n - 1] = '1';
        ans = max(ans, find_smallest_interior_gap(tmp));        
    }
    if (s[0] == '0')
    {
        tmp = s;
        tmp[0] = '1';
        ans = max(ans, try_cow_in_largest_gap(tmp));
    }
    if (s[n - 1] == '0')
    {
        tmp = s;
        tmp[n - 1] = '1';
        ans = max(ans, try_cow_in_largest_gap(tmp));
    }
    if (largest_gap >= 2)
    {
        tmp = s;
        tmp[gap_start + largest_gap / 2] = '1';
        ans = max(ans, try_cow_in_largest_gap(tmp));
    }
    cout << ans << endl;
}
