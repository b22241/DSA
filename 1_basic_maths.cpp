#include <iostream>
using  namespace std;
#include <algorithm>

int reverse(int n) {
    int k = 0;
    int p; 
    while (n > 0) {
        p = (k * 10) + (n % 10);  
        k = p;                   
        n = n / 10;               
    }
    if (n==k) return 1;
    else return 0;
}

int gcd(int n1, int n2)
 {
    int gcd = 1;  
    int min_value = min(n1, n2);  

    for (int i = min_value; i>=1;i--) 
    {  
        if (n1 % i == 0 && n2 % i == 0)
        {  
            gcd = i;  
            break;
        }
    }
    return gcd; 
}


int euclidean_gcd(int n1, int n2) {
    // Base case: when n2 becomes 0, n1 is the GCD
    if (n2 == 0) {
        return n1;
    }
    // Recursive case: gcd(n1, n2) is the same as gcd(n2, n1 % n2)
    return euclidean_gcd(n2, n1 % n2);
}
int main()
{
    int n1=16;
    int n2=36;
    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd(n1, n2) << std::endl;
    cout<<euclidean_gcd(n1,n2)<<endl;
    cout<<n1%n2;
}
