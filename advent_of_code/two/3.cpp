#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<int> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
 
int main() {
  P s = P(0, 0), r = P(0, 0);
  int ans = 1;
  string str; cin >>str;
  map<char, P> m;
  m['^'] = P(0, -1);
  m['>'] = P(1, 0);
  m['v'] = P(0, 1);
  m['<'] = P(-1, 0);
  set<P> S;
  S.insert(P(0, 0));
  for(int i = 0; i < str.length(); i += 2){
    s += m[str[i]];
    r += m[str[i + 1]];
    S.insert(s);
    S.insert(r);
  }
  cout <<S.size() <<endl;
  return 0;
}
