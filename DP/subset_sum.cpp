#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 9, 8, 3, 6, 4, 2, 7, 5};

bool findSubsetSumRec(int n, int Sum)
{
    bool found = false;
     
    if(n == 0)
        return false;

    if(Sum == arr[n])
        return true;

    if(arr[n] > Sum)
        findSubsetSumRec(n-1, Sum);

    else
        found = findSubsetSumRec(n-1, Sum - arr[n-1])
                || findSubsetSumRec(n-1, Sum);

    return found;
}

bool findSubsetSumDP(int n, int Sum)
{
    bool found = false;

    int r = n+1;
    int c = Sum+1;

    bool DP[r][c];

    for(int i=0; i<r; i++)
        fill(DP[i], DP[i]+c, false);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=Sum; j++)
        {
            if(j < arr[i])
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = (arr[i]==j)
                            ||DP[i-1][j]
                            || DP[i-1][j-arr[i]];
        }
        if(DP[i][Sum] == true)
            return true;
    }

    return found;
}

int main()
{
    cout << "Set {1, 9, 8, 3, 6, 4, 2, 7, 5}\n";
    cout << "To find subset with sum = 23.\n";

    int n = 8;
    int Sum = 23;

    cout << findSubsetSumRec(n, Sum) << "\n";
 
    cout << findSubsetSumDP(n, Sum) << "\n";   
    return 0;
}
