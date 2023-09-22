#include <bits/stdc++.h>
using namespace std;

long long func1(long long x)
{
    return x * (x - 1) / 2;
}

long long func2(long long x)
{
    return x * (x - 1) * (x - 2) / 6;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, c, cnt = 0, ind = -1, left, right, cur = 0, val = 0;
    cin >> n >> c;
    vector <long long> vec1(n), vec2(c);
    for (long long i = 0; i < n; i++)
    {
        cin >> vec1[i];
        vec2[vec1[i]]++;
    }
    for (long long i = 0; i < c; i++) cnt += vec2[i];
    for (long long i = 0; i < c; i++)
    {
        if (vec2[i] > 0)
        {
            ind = i;
            break;
        }
    }
    left = ind, right = (left + c / 2) % c;
    if (left < right) for (long long i = left; i <= right; i++) cur += vec2[i];
    else
    {
        for (long long i = right; i <= left; i++) cur += vec2[i];
        cur = cnt - cur + vec2[left] + vec2[right];
    }
    while (left < c)
    {
        if (vec2[left] > 0)
        {
            val += vec2[left] * func1(cur - vec2[left]);
            val += func1(vec2[left]) * (cur - vec2[left]);
            val += func2(vec2[left]);
            if (c % 2 == 0 && left > right && vec2[left] > 0 && vec2[right] > 0)
            {
                val -= vec2[left] * func1(vec2[right]);
                val -= func1(vec2[left]) * vec2[right];
            }
        }
        if (left == c - 1) break;
        cur -= vec2[left];
        left = (left + 1) % c;
        right = (right + 1) % c;
        cur += vec2[right];
    }
    cout << func2(n) - val << "\n";
}
