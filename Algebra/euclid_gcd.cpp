#include <bits/stdc++.h>
using namespace std;

int euclid_gcd(int a, int b)
{
    if(b > a)
        swap(a, b);
    
    if(b == 0)
        return a;
    
    else
        return euclid_gcd(a % b, b);
}

int main()
{
    cout << "Enter two numbers:\n";
    int a, b;
    cin >> a >> b;
    
    cout << "GCD(" << a << ", " << b << ") is:\n";
    cout << euclid_gcd(a, b) << endl;
    
    return 0;
}