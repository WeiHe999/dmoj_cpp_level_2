#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        int k;
        cin >> k;
        stack <int> s1;
        stack <int> s2;
        for (int a = 0; a < k; a++)
        {
            int b;
            cin >> b;
            s1.push(b);
        }
        int current = 1;
        while (!s1.empty())
        {
            if (s2.size() >= 1 && s2.top() == current)
            {
                current++;
                s2.pop();
            }
            else if (s1.top() == current)
            {
                current++;
                s1.pop();
            }
            else
            {

                
                    s2.push(s1.top());
                    s1.pop();
                    
              
                    


            }
        }
        while(!s2.empty())
        {
            if (s2.top() == current)
            {
                current++;
                s2.pop();
            }
            else
            {
                cout << "N" << endl;
                break;
            }
        }
        if (s2.empty())
        {
            cout << "Y" << endl;
        }
    }
}
