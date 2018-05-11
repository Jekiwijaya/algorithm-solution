/*
 * Created by Jacky Wijaya
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
#include <map>

#define FOREACH(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)

#define ALL(c) (c).begin(), (c).end()
#define F first
#define S second
#define INS insert
#define MP make_pair
#define PB push_back
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

template <class T> inline T MAX(T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN(T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS(T x) { if (x < 0) return -x; return x; }

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const static int INF = 2123123123;

#define MAXN 405

int n;
LL arr[MAXN];

map<LL, int> idx;
LL conv[MAXN];
vvi ver(MAXN);
vvi rev(MAXN);
bool visited[MAXN];
int l = 0;

int getIdx(LL angka, bool ins = false) {
  if (idx.count(angka)) return idx[angka];
  if (!ins) return -1;
  idx[angka] = l;
  conv[l] = angka;
  l++;
}

int lastIdx = -1;
vector<LL> res;

void findLast(int now) {
  if (visited[now]) return;
  visited[now] = true;
  lastIdx = now;
  // printf("findLast: %d\n",now);
  REP(i, ver[now].size()) {
    int w = ver[now][i];
    findLast(w);
  }
}

void addE(int v,int w){
  if (v == -1 || w == -1) return;
  ver[v].PB(w);
  rev[w].PB(v);
}

void dfs(int now) {
  if (visited[now]) return;
  visited[now] = true;
  res.PB(conv[now]);
  REP(i, rev[now].size()) {
    int w = rev[now][i];
    dfs(w);
  }
}

int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%I64d", &arr[i]);
    getIdx(arr[i], true);
  }
  REP(i,n){
    int v = getIdx(arr[i]);
    int w = -1;
    if (arr[i] % 3 == 0) {
      w = getIdx(arr[i] / 3);
      addE(v, w);
    }
    w = getIdx(arr[i] * 2);
    addE(v, w);
    w = getIdx(arr[i] * 3);
    addE(w, v);
    if (arr[i] % 2 == 0) {
      w = getIdx(arr[i] / 2);
      addE(w, v);
    }
  }
  memset(visited, false, sizeof(visited));
  findLast(0);
  // printf("lastIdx: %d\n",lastIdx);
  memset(visited, false, sizeof(visited));
  dfs(lastIdx);
  reverse(ALL(res));
  REP(i, res.size()){
    if(i) printf(" ");
    printf("%I64d",res[i]);
  }
  printf("\n");
  return 0;
}