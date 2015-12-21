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
const int H = 1010;
const int W = 1010;

int v[H][W];

void check(int type, int &x1, int &y1, int &x2, int &y2){
  FOR(x, x1, x2 + 1){
    FOR(y, y1, y2 + 1){
      if(type == 0) v[x][y] = max(v[x][y] - 1, 0);
      else if(type == 1) v[x][y] += 1;
      else v[x][y] += 2;
    }
  }
}

int main() {
  char s[10];
  int x1, y1, x2, y2;
  while(scanf("turn %s %d,%d through %d,%d\n", s, &x1, &y1, &x2, &y2) != EOF){
    int type = 2;
    if(strcmp(s, "off") == 0) type = 0;
    if(strcmp(s, "on") == 0) type = 1;
    check(type, x1, y1, x2, y2);
  }
  int ans = 0;
  REP(i, H) REP(j, W) ans += v[i][j];
  cout <<ans <<endl;
  return 0;
}
