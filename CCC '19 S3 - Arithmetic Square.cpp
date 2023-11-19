#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <vector <int> > vec1(3, vector <int>(3)), vec2(3, vector <int>(3));
    vector <int> row(3), col(3);
    int s = 0;
    string str1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> str1;
            if (str1 == "X")
            {
                vec2[i][j] = 1;
                row[i]++;
                col[j]++;
                s++;
            }
            else vec1[i][j] = stoi(str1);
        }
    }
    while (s > 0)
    {
        bool flag = true;
        for (int i = 0; i < 3; i++)
        {
            if (!flag) break;
            if (row[i] == 1)
            {
                if (vec2[i][0] == 1)
                {
                    vec1[i][0] = 2 * vec1[i][1] - vec1[i][2];
                    vec2[i][0] = 0;
                    col[0]--;
                }
                if (vec2[i][1] == 1)
                {
                    vec1[i][1] = (vec1[i][0] + vec1[i][2]) / 2;
                    vec2[i][1] = 0;
                    col[1]--;
                }
                if (vec2[i][2] == 1)
                {
                    vec1[i][2] = 2 * vec1[i][1] - vec1[i][0];
                    vec2[i][2] = 0;
                    col[2]--;
                }
                s--;
                row[i]--;
                flag = false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (!flag) break;
            if (col[i] == 1)
            {
                if (vec2[0][i] == 1)
                {
                    vec1[0][i] = 2 * vec1[1][i] - vec1[2][i];
                    vec2[0][i] = 0;
                    row[0]--;
                }
                if (vec2[1][i] == 1)
                {
                    vec1[1][i] = (vec1[0][i] + vec1[2][i]) / 2;
                    vec2[1][i] = 0;
                    row[1]--;
                }
                if (vec2[2][i] == 1)
                {
                    vec1[2][i] = 2 * vec1[1][i] - vec1[0][i];
                    vec2[2][i] = 0;
                    row[2]--;
                }
                s--;
                col[i]--;
                flag = false;
            }
        }
        if (vec2[1][1] == 1 && flag)
        {
            vec1[1][1] = 0;
            row[1]--;
            col[1]--;
            s--;
            vec2[1][1] = 0;
            flag = false;
        }
        if (vec2[1][0] == 1 && flag)
        {
            vec1[1][0] = 0;
            row[1]--;
            col[0]--;
            s--;
            vec2[1][0] = 0;
            flag = false;
        }
        if (vec2[1][2] == 1 && flag)
        {
            vec1[1][2] = 0;
            row[1]--;
            col[2]--;
            s--;
            vec2[1][2] = 0;
            flag = false;
        }
        if (vec2[0][1] == 1 && flag)
        {
            vec1[0][1] = 0;
            row[0]--;
            col[1]--;
            s--;
            vec2[0][1] = 0;
            flag = false;
        }
        if (vec2[2][1] == 1 && flag)
        {
            vec1[2][1] = 0;
            row[2]--;
            col[1]--;
            s--;
            vec2[2][1] = 0;
            flag = false;
        }
        if (vec2[0][0] == 1 && flag)
        {
            vec1[0][0] = 0;
            row[0]--;
            col[0]--;
            s--;
            vec2[0][0] = 0;
            flag = false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) cout << vec1[i][j] << " ";
        cout << "\n";
    }
}
