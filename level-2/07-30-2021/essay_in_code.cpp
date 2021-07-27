#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    for(int x = 0; x < 5; x++)
    {
        string line;
        getline(cin, line);
        vector <string> vec1;
        int end;
        int tp = 0;
        string str1;
        for (int a = 0; a < line.length(); a++)
        {
            if(a < tp) continue;
            if (line[a]=='\"') 
            {
                end = line.find('\"', a + 1);
                str1 = line.substr(a + 1, end - a - 1);
                vec1.emplace_back(str1);
                tp = end + 1;
                continue;
            } 
            if (line[a]=='\'') 
            {
                end = line.find('\'', a + 1);
                str1 = line.substr(a + 1, end - a - 1);
                vec1.emplace_back(str1);
                tp = end + 1;
                continue;
            } 
            if (line[a]=='/') 
            {
                if (a + 1 < line.size() && line[a + 1] == '*')
                {
                    end = line.find("*/", a + 2);
                    str1 = line.substr(a + 2, end - a - 2);
                    vec1.emplace_back(str1);
                    tp = end + 2;
                    continue;
                }
                if (a + 1 < line.size() && line[a + 1]=='/')
                {
                    str1 = line.substr(a + 2);
                    vec1.emplace_back(str1);
                    break;
                }
    
            }        
            
        }
        string str2 = vec1[0];
        for (int i=1; i<vec1.size(); i++)
        {
            str2 = str2 + " " + vec1[i];
        }
        cout << str2 << endl;         
    }
}
