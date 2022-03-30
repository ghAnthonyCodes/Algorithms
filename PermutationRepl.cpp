#include <vector>
#include <cmath>
#include <cstdio>

template <typename T>
class Permutation {
 public:
  std::vector<T> A;

  /********************************************************************************/
  /*                                                                              */
  /* Permutation with replacement.                                                */
  /*                                                                              */
  /* Description:                                                                 */
  /*   Generate all permutations of length "N" with options in B. The current     */
  /* permutation is stored publicly as "A".                                       */
  /*                                                                              */
  /* Formula:                                                                     */
  /*   nPr = n^r: where n is number of items which can be selected, r is number   */
  /*              of items selected, and nPr is ordered list of permuatations.    */
  /*                                                                              */
  /*                                                                              */
  /*                                                                              */
  /********************************************************************************/
  Permutation(std::vector<T> B, int N) {
   this->B = B;
   this->N = N;
   this->repl = repl;
   this->bp = N - 1;
   this->bm = B.size() - 1;

   // Init pointer vector
   this->P = std::vector<int>(N, 0);

   // Init permutation
   this->A = std::vector<T>(N, B[0]);
  }

  bool genNextPerm(void) {

    // No rollover condition
    if (P[bp] < bm) {
      P[bp]++;
      A[bp] = B[P[bp]];
      return true;
    }

    while (bp >= 0 && P[bp] == bm) {
      A[bp] = B[0];
      P[bp] = 0;
      bp--;
    }

    // We are done, re-init perm
    if (bp < 0) {
      this->A = std::vector<T>(N, B[0]);
      return false;
    }

    P[bp]++;
    A[bp] = B[P[bp]];
    bp = N - 1;
    return true;
  }
  
 private:
  std::vector<T> B;
  std::vector<int> P;
  int N;
  int bp;
  int bm;
};

int main() {
  std::vector<char> bag = { 'X', 'Y', 'Z' };
  Permutation<char> P = Permutation<char>(bag, 3);
  do {
    for (auto& a : P.A) 
      printf("%c", a);
    printf("\n");
  } while (P.genNextPerm());

  return 0;
};
