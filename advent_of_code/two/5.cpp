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

bool check1(string &s){
  for(int a = 'a'; a <= 'z'; a++){
    for(int b = 'a'; b <= 'z'; b++){
      int cnt = 0;
      stringstream ss;
      ss << (char)a << (char)b;
      for(int i = 0; i < s.length(); i++) if(s.substr(i, 2) == ss.str()) { ++cnt; ++i; }
      if(cnt >= 2) return true;
    }
  }
  return false;
}

bool check2(string &s){
  for(int a = 'a'; a <= 'z'; a++){
    for(int b = 'a'; b <= 'z'; b++){
      stringstream ss;
      ss << (char)a << (char)b << (char)a;
      for(int i = 0; i < s.length(); i++) if(s.substr(i, 3) == ss.str()) return true;
    }
  }
  return false;
}

int check(string &s){
  return check1(s) && check2(s);
}
 
int main() {
  string s;
  int ans = 0;
  while(cin >>s) ans += check(s);
  cout <<ans <<endl;
  return 0;
}
