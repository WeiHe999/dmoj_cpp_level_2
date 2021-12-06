#include <bits/stdc++.h>
using namespace std;

int h_index(vector <int> papers)
{
    int h = papers.size();
    while (h > 0 && papers[h - 1] < h) h--;
    return h;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n, l;
    cin >> n >> l;
    vector <int> papers;
    int a;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        papers.emplace_back(a);
    }
    sort(papers.rbegin(), papers.rend());
    int h = h_index(papers);
    if (h != n)
    {
        int counter = 0;
        for (int a = h; a < papers.size(); a++) 
        {
            if (counter < l)
            {
                papers[a]++;
                counter++;
            }
            else
            {
                break;
            }
        }
        if (l - counter > 0)
        {
            int ind = h - 1;
            for (int left = l - counter; left > 0; left--)
            {
                if (ind == -1) break;
                papers[ind]++;
                ind--;
            }
        }
    }
    sort(papers.rbegin(), papers.rend());
    cout << h_index(papers) << endl;
}
