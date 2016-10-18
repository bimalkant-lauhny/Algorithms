#include <bits/stdc++.h>
using namespace std;

#define MODVAL 1000000007

int binexpo_rec(int base, int exp)
{
    if(exp == 1)
        return base;
    
    int res;
    
    if(exp & 1) // odd
    {
        res = (long long) pow(binexpo_rec(base, (exp-1) >> 1), 2) % MODVAL;
        res = (res * (long long)base) % MODVAL;
    }
    else // even
    {
        res = (long long) pow(binexpo_rec(base, exp >> 1), 2) % MODVAL;
    }
    
    return res;
}

long long binexpo_iter(int base, int exp)
{
    long long res = 1;
    
    while(exp > 0)
    {
        if(exp & 1)
            res = (res * (long long) base) % MODVAL;
        base = ((long long) base * base) % MODVAL;
        exp >>= 1;
    }
    
    return res;
}

int main()
{
    cout << "Enter the base and exponent:\n";
    int b, e;
    cin >> b >> e;
    
    cout << binexpo_rec(b, e) << endl;
    cout << binexpo_iter(b, e) << endl;
    
    return 0;
}