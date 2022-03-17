#include <vector>
#include <cstdio>
#include <cmath>

class FenwickTree {
 public:
  int N;
  std::vector<int> T;

  // Initiate tree, internal tree is 1-based indexing, but external isn't
  FenwickTree(int N) {
    this->N = N;
    T = std::vector<int>(N + 1, 0);
  }

  void add(int r, int v) {
    r++;
    while (r <= N) {
      this->T[r] += v;
      r = r + (r & -r);
    }
  }

  // Sums [0 - r] inclusive
  int sum(int r) {
    int ret = 0;
    r++;
    while (r > 0) {
      ret += this->T[r];
      r = r - (r & -r);
    }
    return ret;
  }

  // Sums [l - r] inclusive
  int sumRange(int l, int r) {
    return this->sum(r) - this->sum(l - 1);
  }

  // For debugging
  void printTree(void) {
    printf("T = { ");
    for (int i = 1; i <= this->N; i++)
      printf("%d ", this->T[i]); 
    printf("}\n");
  }
};
