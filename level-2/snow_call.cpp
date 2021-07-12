#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string str1;
	for (int x = 0; x < n; x++)
	{
		string line;
		getline(cin, line);
		str1 = "";
		for (int a = 0; a < line.length(); a++)
		{
			if (isalpha(line[a]))
			{
				if (line[a] == 'A' || line[a] == 'B' || line[a] == 'C')
				{
					str1 += '2';
				}
				else if (line[a] == 'D' || line[a] == 'E' || line[a] == 'F')
				{
					str1 += '3';
				}
				else if (line[a] == 'G' || line[a] == 'H' || line[a] == 'I')
				{
					str1 += '4';
				}
				else if (line[a] == 'J' || line[a] == 'K' || line[a] == 'L')
				{
					str1 += '5';
				}
				else if (line[a] == 'M' || line[a] == 'N' || line[a] == 'O')
				{
					str1 += '6';
				}
				else if (line[a] == 'P' || line[a] == 'Q' || line[a] == 'R' || line[a] == 'S')
				{
					str1 += '7';
				}
				else if (line[a] == 'T' || line[a] == 'U' || line[a] == 'V')
				{
					str1 += '8';
				}
				else
				{
					str1 += '9';
				}
			}
			if (isdigit(line[a]))
			{
			    str1 += line[a];
			}
			
			if (str1.length() == 3 || str1.length() == 7)
			{
				str1 += '-';
			}
            if (str1.length() == 12)
            {
                break;
            }
		}
		cout << str1 << endl;
	}
	return 0;
}
