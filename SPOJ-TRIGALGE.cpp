#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ul unsigned long
#define ll long long int

// CONTROL STRUCTURES
#define FOR(i, a) for (int i = 0; i < (a); i++)
#define FIR(i, a) for (int i = 1; i < (a); i++)
#define all(vec) vec.begin(), vec.end()
#define ANMR cin.tie(0)->sync_with_stdio(0);
// CONSTANTS
const ll INF32 = INT32_MAX;
const int MOD = 1000000007;

// The given equation
inline double eq(int a, int b, int c, double x){
    return a*x + sin(x)*b - c;
}

// Find positive or negative answer
inline double find_(int a, int b, int c, bool positive) {
    int g = abs(c/a + c); 
    for (int i = -g ; i < g ; i++){
        if (positive && eq(a,b,c, i) > 0) return i;
        if (!positive && eq(a,b,c,i) < 0) return i; 
    }
    return positive ? 100001 : -100001;
}

// successive bissection 
void solve() {

    double a, b, c, x1, x2, x, error = 0.0000001;
    cin >> a >> b >> c;
    x1 = find_(a,b,c,true);
    x2 = find_(a,b,c,false);
    while(abs(x1-x2) > error){
        x = (x1+x2)/2; 
        if (eq(a,b,c,x1)*eq(a,b,c,x) < 0) x2 = x; 
        else x1 = x; 
    }
    cout << fixed << setprecision(6) << x << endl; 
}
int main() {
    ANMR int t;
    cin >> t;
    while (t--) solve();
}