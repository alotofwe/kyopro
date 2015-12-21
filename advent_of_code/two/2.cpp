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
typedef complex<double> P;
const int N = 3;
 
int main() {
  int num[N], ans = 0;
  while(scanf("%dx%dx%d\n", &num[0], &num[1], &num[2]) != EOF){
    int f = 1, n = 1e9;
    REP(i, N) f *= num[i];
    REP(i, N){
      n = min(n, num[i] * 2 + num[(i + 1) % N] * 2);
    }
    ans += n + f;
  }
  cout <<ans <<endl;
  return 0;
}
