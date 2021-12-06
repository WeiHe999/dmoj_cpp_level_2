#include <bits/stdc++.h>
using namespace std;

char lista[100][16];
char tmp[16];

bool code(int n, char *str)
{
    for (int j = 0; j < strlen(str); j++) tmp[strlen(str) - j - 1] = str[j];
    tmp[strlen(str)] = 0;
    for (int i = 0; i < n; i++) if (!strcmp(lista[i], tmp)) return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int x = 0; x < n; x++) scanf("%s", (char*) lista[x]);
    for (int i = 0; i < n; i++)
    {
        if (code(n, lista[i]))
        {
            cout << strlen(lista[i]) << " " << lista[i][strlen(lista[i]) / 2] << endl;
            break;
        }
    }
}
