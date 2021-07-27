#include <iostream>
using namespace std;

int main() 
{
    string str1, str2;
    long long int n;
	cin.tie();
	cin >> str1;
	cin >> str2;
	n = str1.length();
	if (str1 == str2){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
		{
			n = i;
			break;
		}
	}
	if (str1.length() < str2.length())
	{
		cout << (str1.length() - n) + (str2.length() - n) << endl;
	}

	else
	{
		cout << (str1.length() - n) + (str2.length() - n) << endl;
	}
	return 0;
}
