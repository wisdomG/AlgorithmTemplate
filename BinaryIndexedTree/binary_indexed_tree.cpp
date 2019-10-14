/****************
树状数组：Binary Indexed Tree / Fenwick Tree

******************/
class FenwickTree {
public:
  FenwickTree(int n): sums_(n + 1, 0) {}

  // O(log n)
  void update(int i, int delte) {
    while (i < sums_.size()) {
      sums_[i] += delte;
      i += lowbit(i);
    }
  }

  // O(log n)
  int query(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

private:
  static inline int lowbit(int x) { return x & (-x); }
  vector<int> sums_;
}
/*  */
// leetcode 307 / 315