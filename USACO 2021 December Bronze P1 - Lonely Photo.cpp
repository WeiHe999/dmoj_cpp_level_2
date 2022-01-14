#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, left, right, s = 0;
    cin >> n; cin.ignore();
    string a;
    getline(cin, a);
    vector <long long> g_ind, h_ind;
    for (long long b = 0; b < a.size(); b++)
    {
        if (a[b] == 'G') g_ind.emplace_back(b);
        else h_ind.emplace_back(b);
    }
    for (long long i = 0; i < g_ind.size(); i++)
    {
        if (g_ind.size()==1)
        {
            left = g_ind[i] + 1;
            right = n - g_ind[i];
        }
        else
        {
            if (i == 0)
            {
                left = g_ind[i] + 1;
                right = g_ind[i + 1] - g_ind[i];
            }
            else if (i == g_ind.size() - 1)
            {
                left = g_ind[i] - g_ind[i - 1];
                right = n - g_ind[i];
            }
            else
            {
                left = g_ind[i] - g_ind[i - 1];
                right = g_ind[i + 1] - g_ind[i];
            }            
            
            
        }
        

        if (left == 1) s += max(right - 2, 0ll);
        else if (left == 2) s += max(right - 2, 0ll) + max(right - 1, 0ll);
        else s += max(right - 2, 0ll) + max(right - 1, 0ll) + right * (left - 2);
    }
    for (long long i = 0; i < h_ind.size(); i++)
    {
        
        if (h_ind.size()==1)
        {
            left = h_ind[i] + 1;
            right = n - h_ind[i];
        } 
        else
        {
            if (i == 0)
            {
                left = h_ind[i] + 1;
                right = h_ind[i + 1] - h_ind[i];
            }
            else if (i == h_ind.size() - 1)
            {
                left = h_ind[i] - h_ind[i - 1];
                right = n - h_ind[i];
            }
            else
            {
                left = h_ind[i] - h_ind[i - 1];
                right = h_ind[i + 1] - h_ind[i];
            }            
            
        }

        if (left == 1) s += max(right - 2, 0ll);
        else if (left == 2) s += max(right - 2, 0ll) + max(right - 1, 0ll);
        else s += max(right - 2, 0ll) + max(right - 1, 0ll) + right * (left - 2);
    }
    cout << s << endl;
}
