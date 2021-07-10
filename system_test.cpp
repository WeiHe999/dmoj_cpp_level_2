#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;


int main()
{
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1], arr2[n1], arr3[n1];
    int s = 0;
    for (int k = 0; k < n1; k++) {
        scanf("%d %d %d", &arr1[k], &arr2[k], &arr3[k]);
    }

    scanf("%d", &n2);
    int arr[n2];
    for(int i = 0; i < n2; i++) scanf("%d", &arr[i]);
    vector<int> vect_q(arr, arr+n2);
    sort(vect_q.begin(), vect_q.end());
    
    for (int m=0; m<n1; m++)
    {
        if (upper_bound (vect_q.begin(), vect_q.end(), arr2[m]) - 
        lower_bound (vect_q.begin(), vect_q.end(), arr1[m]) ==0)
        {
            s += arr3[m];
        }
        
    }

    printf("%d", s);
    return 0;
}
