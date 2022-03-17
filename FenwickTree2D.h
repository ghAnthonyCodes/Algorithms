#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define vi_t  std::vector<int>
#define vvi_t std::vector<vi_t>

class FenwickTree2D {
 public:
  int M, N;
  vvi_t T;

  FenwickTree2D(int M, int N) { 
    this->M = M;
    this->N = N;
    vvi_t T = vvi_t(M+1, vi_t(N + 1, 0));
  }

  void update(int x, int y, int val) {
    for (int i = x; i <= this->M; i = i | (i + 1)) {
      for (int j = y; j <= this->N; j = j | (j + 1))
        T[i][j] += val;
    }
  }

  int query(int x, int y) {
    int ret = 0;
    for (int xp = x; xp >= 0; xp = (xp & (xp + 1)) - 1) {
      for (int yp = y; yp >= 0; yp = (yp & (yp + 1)) - 1)
        ret += T[xp][yp];
    }
    return ret;
  }

  int queryRange(int x0, int y0, int x1, int y1) {
    return query(x1, y1) - query(x0 - 1, y1) - query(x1, y0 - 1) + query(x0 - 1, y0 - 1);
  }

  void clear(void) {
    T = vvi_t(M + 1, vi_t(N + 1, 0));
    A = vvi_t(M + 1, vi_t(N + 1, 0));
  }
};
