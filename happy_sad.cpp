#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int happy = 0;
    int sad = 0;
    for (int x = 0; x < line.length(); x++)
    {
        string substring = line.substr(x, 3);
        if (substring == ":-)")
        {
            happy++;
        }
        if (substring == ":-(")
        {
            sad++;
        }
    }
    if (happy == 0 && sad == 0)
    {
        cout << "none" << endl;
    }
    else if (happy == sad)
    {
        cout << "unsure" << endl;
    }
    else if (happy > sad)
    {
        cout << "happy" << endl;
    }
    else
    {
        cout << "sad" << endl;
    }
    return 0;
}
