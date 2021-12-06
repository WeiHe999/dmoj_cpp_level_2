#include <iostream>
#include <regex>
using namespace std;
int main()
{
    string subject;
    for (int x = 0; x < 5; x++)
    {
        getline(cin, subject);
        smatch match;
        int i = 0;
        while (regex_search(subject, match, regex("[a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z]+")))
        {
            i++;
            subject = match.suffix().str();
        }
        cout << i << endl;
    }
}
