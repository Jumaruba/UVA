#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include <sstream>
using namespace std;
#define ull unsigned long long
#define ul unsigned long
#define ll long long int

// CONTROL STRUCTURES
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FIR(i, a) for (int i=1; i<(a); i++)
#define all(vec)  vec.begin(),  vec.end()
#define ANMR cin.tie(0)->sync_with_stdio(0);
// CONSTANTS
const ll INF32 = INT32_MAX;
const int MOD = 1000000007;

int solve(int n){
    unordered_map<string,int> map; 
    vector<int> v(5);
    string s, empty = " ";
    ostringstream ss(s);
    int m = 0; 
    FOR(i,n){
        cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4]; 
        sort(v.begin(), v.end());
        s = to_string(v[0]) + " " + to_string(v[1]) + " " + to_string(v[2]) + " " + to_string(v[3]) + " " + to_string(v[4]);
        cout << s << endl;
        if (map.find(s) != map.end())  {
            map[s] += 1; 
        }else map[s] = 1;
    }
    for (auto &it: map) m = max(m, it.second);
    
    return m; 
}
int main(){
    ANMR
    int t = 1;
    while(t){
        cin >> t;
        if (t) cout << solve(t) << endl;
    }

}