#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

bool check(string str1)
{
    if (str1.size() == 4)
    {
        int diff1 = int(str1[1]) - int(str1[0]);
        int diff2 = int(str1[2]) - int(str1[1]);
        int diff3 = int(str1[3]) - int(str1[2]);
        if (diff1 == diff2 && diff2 == diff3) return true;
    }
    else
    {
        int diff1 = int(str1[1]) - int(str1[0]);
        int diff2 = int(str1[2]) - int(str1[1]);
        if (diff1 == diff2) return true;
    }
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    //cout << check("531") << endl;
    int d, val, hour = 12, minute = 0;
    cin >> d;
    vector <string> vec1 = {"1234", "111", "123", "135", "147", "159", "210", "222", "234", "246", "258", "321", "333", "345", "357", "420", "432", "444", "456", "531", "543",
        "555", "630", "642", "654", "741", "753", "840", "852", "951", "1111"};
    // cout << "total=" << d << endl;
    val = (vec1.size() * (d / 720));
    for (int i = 0; i < (d % 720); i++)
    {
        string str1 = "";
        if (minute == 59)
        {
            if (hour == 12) hour = 1;
            else hour++;
            str1 += to_string(hour);
            str1 += "00";
            minute = 0;
        }
        else if (minute < 9)
        {
            str1 += to_string(hour);
            minute++;
            str1 += "0" + to_string(minute);
        }
        else
        {
            str1 += to_string(hour);
            minute++;
            str1 += to_string(minute);
        }
        // cout << "i=" << i << ", time=" << str1 << endl;
        if (check(str1)) val++;
    }
    cout << val << endl;
}
