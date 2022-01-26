#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <char> roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector <int> numbers = {1, 5, 10, 50, 100, 500, 1000};
    string d;
    cin >> d;
    int sum = 0;
    for (int a = 0; a < d.length(); a += 2)
    {
        for (int b = 0; b < 7; ++b)
        {
            if (d[a + 1] == roman[b])
            {

                if (a < d.length() - 2)
                {
                    for (int c = 0; c < 7; ++c)
                    {
                        if (d[a + 3] == roman[c])
                        {
                            if (b < c) sum -= ((d[a] - '0') * numbers[b]) * 2;
                            break;
                        }
                    }
                }
                sum += (d[a] - '0') * numbers[b];
            }
        }
    }
    cout << sum << endl;
}
