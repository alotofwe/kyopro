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

vector<int> split(string &str, char delim){
  stringstream ss(str);
  string tmp;
  vector<int> res;
  while(getline(ss, tmp, delim)) res.push_back(atoi(tmp.c_str()));
  return res;
}

int main() {
  int ans = 0;
  string s;
  while(cin >>s){
    vector<int> v = split(s, 'x');
    int m = 1e9;
    REP(i, v.size()){
      ans += v[i] * v[(i + 1) % (int)v.size()] * 2;
      m = min(m, v[i] * v[(i + 1) % (int)v.size()]);
    }
    ans += m;
  }
  cout <<ans <<endl;
  return 0;
}
