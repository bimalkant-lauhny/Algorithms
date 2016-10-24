#include <bits/stdc++.h>
using namespace std;

int gcd_rec_ext(int a, int b, int &x, int &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = gcd_rec_ext(b % a, a, x1, y1);
    
    x = y1 - (b/a) * x1;
    y = x1;
    
    return gcd;
}

int gcd_iter_ext(int a, int b, int &x, int &y)
{
    int temp;
    int x0 = 1, x1= 0, y0= 0, y1= 1;
    int q;
    
    while(b > 0)
    {
        q = a / b;
        temp = b;
        b = a % b;
        a = temp;
        
        temp = x0;
        x0 = x1;
        x1 = temp - q * x1;
        
        temp = y0;
        y0 = y1; 
        y1 = temp - q * y1;
    }
    
    x = x0;
    y = y0;
    return a;
}

int main()
{
    cout << "Enter two numbers:\n";
    int a, b, x, y;
    cin >> a >> b;
    
    cout << "GCD(" << a << ", " << b << ") is:\n";
    
    int gcd = gcd_rec_ext(a, b, x, y);
    cout << a << "*" << x << " + " << b << "*" << y << " = " << gcd << endl;
    
    gcd = gcd_iter_ext(a, b, x, y);
    cout << a << "*" << x << " + " << b << "*" << y << " = " << gcd << endl;
    
    return 0;
}