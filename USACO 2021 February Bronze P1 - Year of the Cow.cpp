#include <bits/stdc++.h>
using namespace std;

string get_animal(int year, vector <string> animals)
{
    int a = 0, y = 2021;
    while (y < year) { y++; a++; if (a == 12) a = 0; }
    while (y > year) { y--; a--; if (a == -1) a = 11; }
    return animals[a];
}
 
int main()
{
    vector <string> animals = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map <string, int> when_born = {{"Bessie", 2021}};
    int n;
    bool flag;
    cin >> n;
    string cowa, born, in, relation, animal, year, from, cowb;
    for (int i = 0; i < n; i++)
    {
        flag = true;
        cin >> cowa >> born >> in >> relation >> animal >> year >> from >> cowb;
        when_born[cowa] = when_born[cowb];
        while (get_animal(when_born[cowa], animals) != animal || flag)
        {
            if (flag) flag = false;
            if (relation == "previous") when_born[cowa]--;
            else when_born[cowa]++;
        }
    }
    cout << abs(when_born["Bessie"] - when_born["Elsie"]) << endl;
}
