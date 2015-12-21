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
const int INF = 1e9;

int N;
vector< vector<int> > v;

vector< vector<int> > prepare(){
  vector<string> ss; string s;
  while(getline(cin, s)) ss.push_back(s);

  char a[100], b[100], c[100]; int d;
  set<string> S;
  REP(i, ss.size()){
    sscanf(ss[i].c_str(), "%s would %s %d happiness units by sitting next to %s.\n", a, c, &d, b);
    S.insert(a); S.insert(b);
  }

  map<string, int> M; int num = 0;
  for(string str : S) M[str] = num++;

  vector< vector<int> > res(S.size(), vector<int>(S.size(), INF));
  REP(i, res.size()) res[i][i] = 0;
  REP(i, ss.size()){
    sscanf(ss[i].c_str(), "%s would %s %d happiness units by sitting next to %s.\n", a, c, &d, b);
    if((string)c == "lose") d *= -1;
    res[M[a]][M[b]] = d;
  }
  return res;
}

int calc(vector<int> &num){
  int res = v[num[0]][num[num.size() - 1]] + v[num[num.size() - 1]][num[0]];
  FOR(i, 1, N) res += v[num[i - 1]][num[i]] + v[num[i]][num[i - 1]];
  return res;
}

int solve(int now, vector<int> &num, vector<bool> &used){
  if(now >= N) return calc(num);
  int res = 0;
  REP(i, used.size()){
    if(used[i]) continue;
    used[i] = 1;
    num[now] = i;
    res = max(res, solve(now + 1, num, used));
    used[i] = 0;
  }
  return res;
}

int main() {
  v = prepare();
  N = v.size();
  vector<bool> used(N, 0);
  vector<int> num(N, -1);
  cout <<solve(0, num, used) <<endl;
  return 0;
}
