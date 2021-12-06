#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int cases, m, k;
    string line;
    cin >> cases;
    for (int x = 0; x < cases; x++)
    {
        cin >> m >> k; cin.ignore();
        vector <pair <int, string> > words;
        for (int a = 0; a < m; a++)
        {
            bool add = true;
            getline(cin, line);
            pair <int, string> save = {1, line};
            for (int y = 0; y < words.size(); y++)
            {
                if (save.second == words[y].second)
                {
                    words[y].first++;
                    add = false;
                    break;
                }
            }
            if (add) words.push_back(save);
        }
        for (int b = words.size() - 1; b >= 0; b--) for (int c = 0; c < b; c++) if (words[c] < words[c + 1]) swap(words[c], words[c + 1]);
        if (k > m)
        {
            if (k > 9)
            {
                if (to_string(k)[to_string(k).length() - 2] == '1')
                {
                    if (to_string(k)[to_string(k).length() - 1] == '1') cout << to_string(k) << "th most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '2') cout << to_string(k) << "th most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '3') cout << to_string(k) << "th most common word(s):";
                }
                else
                {
                    if (to_string(k)[to_string(k).length() - 1] == '1') cout << to_string(k) << "st most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '2') cout << to_string(k) << "nd most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '3') cout << to_string(k) << "rd most common word(s):";
                    else cout << to_string(k) << "th most common word(s):";
                }
            }
            else
            {
                if (to_string(k)[to_string(k).length() - 1] == '1') cout << to_string(k) << "st most common word(s):";
                else if (to_string(k)[to_string(k).length() - 1] == '2') cout << to_string(k) << "nd most common word(s):";
                else if (to_string(k)[to_string(k).length() - 1] == '3') cout << to_string(k) << "rd most common word(s):";
                else cout << to_string(k) << "th most common word(s):";
            }
            cout << endl;
        }
        else
        {
            int counter = 1;
            int tmp = words[0].first;
            vector <string> common_words;
            for (int d = 0; d < words.size(); d++)
            {
                if (words[d].first != tmp)
                {
                    counter = d + 1;
                    tmp = words[d].first;
                }
                if (counter == k) common_words.emplace_back(words[d].second);
            }
            if (k > 9)
            {
                if (to_string(k)[to_string(k).length() - 2] == '1')
                {
                    if (to_string(k)[to_string(k).length() - 1] == '1') cout << to_string(k) << "th most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '2') cout << to_string(k) << "th most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '3') cout << to_string(k) << "th most common word(s):";
                }
                else
                {
                    if (to_string(k)[to_string(k).length() - 1] == '1') cout << to_string(k) << "st most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '2') cout << to_string(k) << "nd most common word(s):";
                    else if (to_string(k)[to_string(k).length() - 1] == '3') cout << to_string(k) << "rd most common word(s):";
                    else cout << to_string(k) << "th most common word(s):";
                }
            }
            else
            {
                if (to_string(k)[to_string(k).length() - 1] == '1') cout << to_string(k) << "st most common word(s):";
                else if (to_string(k)[to_string(k).length() - 1] == '2') cout << to_string(k) << "nd most common word(s):";
                else if (to_string(k)[to_string(k).length() - 1] == '3') cout << to_string(k) << "rd most common word(s):";
                else cout << to_string(k) << "th most common word(s):";
            }
            cout << endl;
            for (auto e : common_words) cout << e << endl;
        }
        cout << endl;
    }
}
