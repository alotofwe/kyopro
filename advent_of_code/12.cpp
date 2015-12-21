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
  string s; cin >>s;
  int ans = 0;
  REP(i, s.length()){
    while(!isdigit(s[i]) && s[i] != '-') ++i;
    stringstream ss;
    while(isdigit(s[i]) || s[i] == '-') ss << s[i++];
    ans += atoi(ss.str().c_str());
  }
  cout <<ans <<endl;
  return 0;
}
