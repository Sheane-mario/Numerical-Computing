#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;

// The code below finds an approximation to PI without utilizing any library functions nor any constants such as (22/7), etc. but using analytical geometry inside a circle which contains a triangle.
 
// binary power function
long long binpow(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long temp = binpow(a, b/2);
    long long ans = temp * temp;
    if (b & 1) ans = ans * a;
    return ans;
}
// S(n) = sin(theta_n)*sin(theta_n), where theta_n is the angle subtended at the center of the semicircle with a unit radius when the semicircle is divided into 2^(n-1) parts. 
long double S(int n) {
    if (n == 2) return 1;
    long double temp = S(n - 1);
    long double ans = temp / (2 + 2 * sqrt(1 - temp));
    return ans; // S(n + 1) = S(n) / (2 + 2 * sqrt(1 - S(n)))
}
// P(n) recursively find the perimeter of the semicircular arc which has a unit radius. 
// P(n) = 2^n*sqrt(S(n+1))
long double P(int n) {
    if (n == 1) return 2 * sqrt(2);
    long double ans = binpow(2, n) * sqrt(S(n + 1));
    return ans;
}


int32_t main() {
   long double pi = P(20);
   cout << setprecision(30) << pi << endl;
}
