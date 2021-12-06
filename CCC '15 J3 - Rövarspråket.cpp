#include <bits/stdc++.h>
using namespace std;

char find_closest_vowel(int consonant, vector <int> vowels)
{
    int min_diff = INT_MAX;
    for (auto v : vowels) if (min_diff > abs(v - consonant)) min_diff = abs(v - consonant);
    if (find(vowels.begin(), vowels.end(), consonant - min_diff) != vowels.end()) return char(consonant - min_diff);
    else return char(consonant + min_diff);
}

char find_next_consonant(int consonant, vector <int> vowels)
{
    if (consonant == 122) return 'z';
    for (int x = consonant + 1; x < 123; x++) if (find(vowels.begin(), vowels.end(), x) == vowels.end()) return char(x);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vowels = {97, 101, 105, 111, 117};
    string line, line2;
    getline(cin, line);
    for (auto c : line)
    {
        if (find(vowels.begin(), vowels.end(), int(c)) == vowels.end())
        {
            line2 += c;
            line2 += find_closest_vowel(int(c), vowels);
            line2 += find_next_consonant(int(c), vowels);
        }
        else line2 += c;
    }
    cout << line2 << endl;
}
