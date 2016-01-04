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
typedef pair<int, vector<int> > P;
const int L = 30;

void rotate(int type, vector<int> &v){
  if(type == 0){
    swap(v[0], v[23]);
    swap(v[3], v[26]);
    swap(v[6], v[29]);
    swap(v[9], v[20]);
    swap(v[15], v[17]);
  } else if(type == 1){
    swap(v[2], v[21]);
    swap(v[5], v[24]);
    swap(v[8], v[27]);
    swap(v[11], v[18]);
    swap(v[12], v[14]);
  } else if(type == 2){
    swap(v[0], v[27]);
    swap(v[1], v[28]);
    swap(v[2], v[29]);
    swap(v[14], v[15]);
    swap(v[18], v[20]);
  } else if(type == 3){
    swap(v[6], v[21]);
    swap(v[7], v[22]);
    swap(v[8], v[23]);
    swap(v[12], v[17]);
    swap(v[9], v[11]);
  }
}

bool isEnd(vector<int> &v){
  vector<int> list[6] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8},
    {21, 22, 23, 24, 25, 26, 27, 28, 29},
    {9, 10, 11},
    {12, 13, 14},
    {15, 16, 17},
    {18, 19, 20}
  };
  REP(i, 6) REP(j, list[i].size()) if(v[list[i][j]] != v[list[i][0]]) return false;
  return true;
}

int bfs(vector<int> &v){
  queue<P> open;
  open.push(P(0, v));
  set< vector<int> > closed;
  closed.insert(v);
  while(!open.empty()){
    P now = open.front(); open.pop();
    if(isEnd(now.second)) return now.first;
    REP(i, 4){
      rotate(i, now.second);
      if(closed.find(now.second) == closed.end()){
        open.push(P(now.first + 1, now.second));
        closed.insert(now.second);
      }
      rotate(i, now.second);
    }
  }
  return 8;
}
 
int main() {
  int N; cin >>N;
  vector<int> v(L);
  while(N--){
    REP(i, L) cin >>v[i];
    cout <<bfs(v) <<endl;
  }
  return 0;
}
