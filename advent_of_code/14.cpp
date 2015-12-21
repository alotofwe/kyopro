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
typedef pair<int, int> P;
typedef pair<P, int> PP;
const int N = 9;
const int T = 2503;
 
int main() {
  char s[N][100]; int a[N], b[N], c[N], cnt = 0;
  while(scanf("%s can fly %d km/s for %d seconds, but then must rest for %d seconds.", s[cnt], &a[cnt], &b[cnt], &c[cnt]) != EOF) ++cnt;
  vector<PP> v(N);
  REP(i, N) v[i] = PP(P(b[i], 0), 0);
  REP(t, T){
    REP(i, N){ if(v[i].first.first > 0){
        v[i].first.first -= 1;
        v[i].second += a[i];
        if(v[i].first.first <= 0) v[i].first.second = c[i];
      } else{
        v[i].first.second -= 1;
        if(v[i].first.second <= 0) v[i].first.first = b[i];
      }
    }
  }
  int ans = 0;
  FOR(i, 1, N) if(v[i].second > v[ans].second) ans = i;
  cout <<v[ans].second <<endl;
  return 0;
}
