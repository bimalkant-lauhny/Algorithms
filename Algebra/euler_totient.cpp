#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int result = n;
    
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) 
        {
            while(n % i == 0)
                n /= i;
            result -= (result / i);
        }
        
    if(n > 1)
        result -= (result / n);
    return result;   
}

int phi2( int n)
{
    int res = n;
    int num = 1;
    int den = 1;
    
    for(int i=2; i*i <= n; ++i)
    {
        if(n%i == 0)
        {
            while(n % i == 0)
                n /= i;
            res /= i;
            res *= (i-1);
        }
    }
    
    if(n > 1)
    {
        res /= n;
        res *= (n-1);
    }
    
    return (res / den) * num;
}

int main()
{
    cout << "Enter the number:\n";
    int n;
    cin >> n;
    
    cout << "Value of Euler's Totient Function for " << n << ":\n";
    cout << phi(n) << endl;
    cout << phi2(n) << endl;
    
    return 0;
}