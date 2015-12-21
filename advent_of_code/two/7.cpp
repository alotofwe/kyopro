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

map<string, unsigned short> M;

vector<string> split(string &str, char delim){
  stringstream ss(str);
  string tmp;
  vector<string> res;
  while(getline(ss, tmp, delim)) res.push_back(tmp);
  return res;
}

int solve(vector<string> &strs){
  queue<string> Q;
  for(string str : strs) Q.push(str);

  while(!Q.empty()){
    string str = Q.front(); Q.pop();
    vector<string> v = split(str, ' ');
    if(M.find("a") != M.end()) return M["a"];
    if(v.size() == 3 && M.find(v[0]) != M.end() && M.find(v[2]) == M.end()){
      M[v[2]] = M[v[0]];
    } else if(v.size() == 4 && M.find(v[1]) != M.end() && M.find(v[3]) == M.end()){
      M[v[3]] = 65535 - M[v[1]];
    } else if(v.size() == 5 && v[1] == "AND" && M.find(v[0]) != M.end() && M.find(v[2]) != M.end() && M.find(v[4]) == M.end()){
      M[v[4]] = M[v[0]] & M[v[2]];
    } else if(v.size() == 5 && v[1] == "OR" && M.find(v[0]) != M.end() && M.find(v[2]) != M.end() && M.find(v[4]) == M.end()){
      M[v[4]] = M[v[0]] | M[v[2]];
    } else if(v.size() == 5 && v[1] == "LSHIFT" && M.find(v[0]) != M.end() && M.find(v[2]) != M.end() && M.find(v[4]) == M.end()){
      M[v[4]] = M[v[0]] << M[v[2]];
    } else if(v.size() == 5 && v[1] == "RSHIFT" && M.find(v[0]) != M.end() && M.find(v[2]) != M.end() && M.find(v[4]) == M.end()){
      M[v[4]] = M[v[0]] >> M[v[2]];
    } else{
      Q.push(str);
    }
  }
  return M["a"];
}

int main() {
  REP(i, 65535){ stringstream ss; ss << i; M[ss.str()] = i; }
  string input;
  vector<string> strs;
  while(getline(cin, input)) strs.push_back(input);
  int a = solve(strs);
  M = map<string, unsigned short>();
  REP(i, 65535){ stringstream ss; ss << i; M[ss.str()] = i; }
  M["b"] = a;
  cout <<solve(strs) <<endl;
  return 0;
}
