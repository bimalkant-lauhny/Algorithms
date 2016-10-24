#include <bits/stdc++.h>
using namespace std;

int euclid_gcd_rec(int a, int b)
{
    if(a == 0)
        return b;
    
    else
        return euclid_gcd_rec(b % a, a);
}

int euclid_gcd_iter(int a, int b)
{
    int temp;
    
    while(a > 0)
    {
        temp = a;
        a = b % temp;
        b = temp;
    }
    
    return b;
}

int main()
{
    cout << "Enter two numbers:\n";
    int a, b;
    cin >> a >> b;
    
    cout << "GCD(" << a << ", " << b << ") is:\n";
    cout << euclid_gcd_rec(a, b) << endl;
    cout << euclid_gcd_iter(a, b) << endl;
    
    return 0;
}