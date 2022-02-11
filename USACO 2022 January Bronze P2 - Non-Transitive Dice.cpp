#include <bits/stdc++.h>
using namespace std;

bool compare(vector <int> vec1, vector <int> vec2)
{
    int score = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec1[i] > vec2[j]) score++;
            if (vec1[i] < vec2[j]) score--;
        }
    }
    return score > 0;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        vector <int> vec1 = {}, vec2 = {}, vec3;
        for (int y = 0; y < 4; y++)
        {
            cin >> a;
            vec1.emplace_back(a);
        }
        for (int z = 0; z < 4; z++)
        {
            cin >> a;
            vec2.emplace_back(a);
        }
        bool flag = true;
        for (int c1 = 1; c1 < 11; c1++)
        {
            for (int c2 = 1; c2 < 11; c2++)
            {
                for (int c3 = 1; c3 < 11; c3++)
                {
                    for (int c4 = 1; c4 < 11; c4++)
                    {
                        vec3 = {c1, c2, c3, c4};
                        if ((compare(vec1, vec2) && compare(vec2, vec3) && compare(vec3, vec1)) || (compare(vec2, vec1) && compare(vec1, vec3) && compare(vec3, vec2)))
                        {
                            cout << "yes" << endl;
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (flag) cout << "no" << endl;
    }
}
