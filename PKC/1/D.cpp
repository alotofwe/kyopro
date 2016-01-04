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
 
int main() {
  int N, h, m;
  set<int> S;
  REP(z, 2){
    cin >>N;
    while(N--){ cin >>h >>m; S.insert(h * 60 + m); }
  }
  bool f = false;
  for(int n : S){
    printf("%s%d:%02d", (f ? " " : ""), n / 60, n % 60);
    f = 1;
  }
  cout <<endl;
  return 0;
}
