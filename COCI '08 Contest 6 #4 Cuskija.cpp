#include <bits/stdc++.h>
using namespace std;

int n, a;
vector <int> vec1, vec2, vec3, output;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a % 3 == 0) vec1.emplace_back(a);
        if (a % 3 == 1) vec2.emplace_back(a);
        if (a % 3 == 2) vec3.emplace_back(a);
    }
    if (vec1.size() == 0 && vec2.size() == 0)
    {
        for (auto x : vec3) cout << x << " ";
        cout << "\n";
        return 0;
    }
    if (vec1.size() == 0 && vec3.size() == 0)
    {
        for (auto x : vec2) cout << x << " ";
        cout << "\n";
        return 0;
    }
    if ((vec1.size() == 0 && vec2.size() > 0 && vec3.size() > 0) || (vec1.size() > vec2.size() + vec3.size() + 1))
    {
        cout << "impossible\n";
        return 0;
    }
    
    int p2 = 0, p3 = 0;
    for (int p1 = 0; p1 < vec1.size() - 1; p1++)
    {
        output.push_back(vec1[p1]);
        if (p2 < vec2.size()) 
        {
            output.push_back(vec2[p2]);
            p2++;
        }
        else if (p3 < vec3.size()) 
        {
            output.push_back(vec3[p3]);
            p3++;
        }
    }
    while(p2 < vec2.size())
    {
      output.push_back(vec2[p2]);
      p2++;
    
    }
    output.push_back(vec1.back());
     while(p3 < vec3.size())
    {
      output.push_back(vec3[p3]); 
      p3++;
    } 
    
    for (auto x : output) cout << x << " ";
    cout << "\n";
}
