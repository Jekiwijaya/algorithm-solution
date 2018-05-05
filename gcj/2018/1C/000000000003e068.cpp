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

#define MAXN 205

int t,n, m;
int arr[MAXN];
bool visited[MAXN];

double totalLike[MAXN];
string input;

bool f(int a, int b) {
  return totalLike[a] < totalLike[b];
}

int main() {
  // OPEN("input");
  scanf("%d\n", &t);
  REPN(tc, t){
    memset(totalLike, 0, sizeof(totalLike));
    memset(visited, false, sizeof(visited));
    scanf("%d\n", &n);
    REP(i, n) {
      scanf("%d", &m);
      REP(j, m) scanf("%d",&arr[j]);
      REP(j, m) {
        totalLike[arr[j]] = totalLike[arr[j]] + (1 - (j*0.1));
      }
      sort(arr, arr+m, f);
      int res = -1;
      REP(j, m) {
        if (visited[arr[j]]) continue;
        if(arr[j] >= n) continue;
        visited[arr[j]] = true;
        res = arr[j];
        break;
      }
      printf("%d\n",res);
      fflush(stdout);
    }
  }
  return 0;
}