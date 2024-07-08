#include <bits/stdc++.h>
#define EPS 1e-6
#define DELTA 1e-5
using namespace std;
typedef long long ll;
 
// function for which we approximate root
long double f(long double x) {
    // x^3 - 2x^2 + x - 3
    long double exp = ((x - 2)*x + 1)*x - 3;
    return exp;
}
// derivative of the function f
long double df(long double x) {
    long double exp = (3*x - 4)*x + 1;
    return exp;
}
// approximate the roots of function f using the newton's method
void Newton(function<long double(long double)> f, function<long double(long double)> df, long double x, int nmax) {
    long double fx, fp, d;
    fx = f(x);                                              // value of f at x
    printf("  n         x              \t\tfx\n");
    printf("  0         %.18Lf        %.18Lf\n", x, fx);
    for (int n = 0; n < nmax; n++) {
        fp = df(x);                                         // derivative of f at x
        if (abs(fp) < DELTA) {
            printf("Small Derivative\n");                   // if the derivative is too small numbers may underflow or it would be like division by zero
            return;
        }
        d = fx / fp;
        x = x - d;
        fx = f(x);
        printf("%3d         %.18Lf        %.18Lf \n", n+1, x, fx);
        if (abs(d) < EPS) {                                // when this happens x(n+1) approximately equals x(n). so f has reached the root.
            printf("Convergence\n");
            return;
        }
    }
}
int32_t main() {
    Newton(f, df, 3.0, 10);
}
