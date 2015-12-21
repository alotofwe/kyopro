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

int check(string &s){
  map<string, int> M;
  for(int i = 0; i < (int)s.length(); i++) M[s.substr(i, 1)] += 1;
  for(int i = 0; i < (int)s.length() - 1; i++) M[s.substr(i, 2)] += 1;
  int x = 0, y = 0, z = 0;
  string vowels[] = {"a", "e", "i", "o", "u"};
  for(string vowel : vowels) x += M[vowel];
  for(int c = 'a'; c <= 'z'; c++){
    stringstream ss;
    ss << (char)c << (char)c;
    y += M[ss.str()];
  }
  string invalid[] = {"ab", "cd", "pq", "xy"};
  for(string inv : invalid) z += M[inv];
  return x >= 3 && y >= 1 && z == 0;
}
 
int main() {
  string s;
  int ans = 0;
  while(cin >>s) ans += check(s);
  cout <<ans <<endl;
  return 0;
}
