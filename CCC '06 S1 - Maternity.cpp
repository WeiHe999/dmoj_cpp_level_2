#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int x;
    string mother, father, baby;
    getline(cin, mother);
    getline(cin, father);
    cin >> x; cin.ignore();
    bool flag;
    for (int i = 0; i < x; i++)
    {
        flag = false;
        getline(cin, baby);
        for (int a = 0; a < 5; a++)
        {
            if ((isupper(mother[2 * a]) && isupper(mother[2 * a + 1])) || (isupper(father[2 * a]) && isupper(father[2 * a + 1])))
            {
                if (islower(baby[a]))
                {
                    flag = true;
                    break;
                }
            }
            if (islower(mother[2 * a]) && islower(mother[2 * a + 1]) && islower(father[2 * a]) && islower(father[2 * a + 1]))
            {
                if (isupper(baby[a]))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) cout << "Not their baby!" << endl;
        else cout << "Possible baby." << endl;
    }
}
