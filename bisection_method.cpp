#include <bits/stdc++.h>
#include <iomanip>
#define EPS 1e-7

using namespace std;
typedef long long ll;

// returns true if x is positive
bool sign(double x) {
   return x > 0.0;  
}
// function evaluation f(x) goes here.
double f(double x) {
    double exp = pow(x, 3) - 3*x + 1;
    return exp;
}
void Bisection(function<double(double)> f, double a, double b, int nmax) {
    double c, fa, fb, fc, error;
    fa = f(a);
    fb = f(b);
    if (sign(fa) == sign(fb)) {
        printf("functions has same signs at %f and %f", a, b);
        return ;
    }
    error = abs(b - a);
    printf("  n    \t\tc     \t\tfc      \t\terror\n");
    printf("--------------------------------------------------------------\n");
    for (int n = 0; n < nmax; n++) {
        error /= 2;
        c = a + error;
        fc = f(c);
        printf("%3d\t\t%.7f\t\t%.8f\t\t%.8f\n", n, c, fc, error);
        if (abs(error) < EPS) {  // iterate untill the error falls below EPS
            printf("Convergence\n");
            return;
        }
        if (sign(fa) != sign(fc)) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
}
int32_t main() {
   
    Bisection(f, 0.0, 1.0, 26);
}
