#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

long long find_steps(vector <pair <long long, long long> > boundaries, long long index, long long a)
{
    long long upper_first = boundaries[index].first, upper_second = boundaries[index].second;
    long long lower_first = boundaries[index + 1].first, lower_second = boundaries[index + 1].second;
    long long c = 0;
    while (upper_first < a)
    {
        if (a % 2 == 0) c++;
        else c += 2;
        a = ceil(a / 2.0);
        // cout << "going down count: " << c << endl << "a: " << a << endl;
    }
    while (lower_first > a)
    {
        a *= 2;
        c++;
        // cout << "going up count: " << c << endl;
    }
    if (upper_first == a)
    {
        return upper_second + c;
    }
    if (lower_first == a)
    {
        return lower_second + c;
    }
    c += upper_first - a;
    // cout << "final count: " << c << "    upper_second: " << upper_second << endl;
    return c + upper_second;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, a, b;
    cin >> t;
    for (long long x = 0; x < t; x++)
    {
        cin >> a >> b;
        vector <pair <long long, long long> > boundaries;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        long long current = b, dist = 0;
        while (current != 0)
        {
            boundaries.push_back({current, dist});
            if (current % 2 == 0) dist++;
            else dist += 2;
            current /= 2;
        }
        if (b > a)
        {
            // for (auto c : boundaries)
            // {
            //     cout << c.first << " " << c.second << endl;
            // }
        }
        else
        {
            current = b * 2; dist = 1;
            while (current < a * 2)
            {
                boundaries.push_back({current, dist});
                current *= 2;
                dist++;
            }
            sort(boundaries.rbegin(), boundaries.rend());
            // for (auto c : boundaries)
            // {
            //     cout << c.first << " " << c.second << endl;
            // }
        }
        long long mina = LLONG_MAX;
        for (int c = 0; c < boundaries.size() - 1; c++)
        {
            mina = min(find_steps(boundaries, c, a), mina);
        }
        cout << mina << endl;
    }
}
