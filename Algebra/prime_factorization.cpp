#include <bits/stdc++.h>
using namespace std;

int prime_factors(int n, vector < int > & factors)
{
    int result = n;
    
    for(int i = 2; i * i <= n; ++i)
        while(n % i == 0)
        {
            n /= i;
            factors.push_back(i);
        }
        
    if(n > 1)
        factors.push_back(n);
}

int main()
{
    cout << "Enter the number:\n";
    int n;
    cin >> n;
    
    if(n == 1)
    {
        cout << "No prime factors for 1!!!\n";
        return 0;
    }
    
    vector < int > factors;
    prime_factors(n, factors);
    
    cout << "Prime Factors of " << n << ":\n";
    for( int i=0; i< factors.size() - 1; ++i)
        cout << factors[i] << " X ";
    cout << factors[factors.size()-1] << endl;
    
    return 0;
}