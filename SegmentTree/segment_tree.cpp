struct SegmentTreeNode {
  int start;
  int end;
  int sum; // can be max/min
  SegmentTreeNode *left;
  SegmentTreeNode *right;
  SegmentTreeNode(int start, int end, int sum): 
    start(start), end(end), sum(sum), left(nullptr), right(nullptr) {}
  SegmentTreeNode(int start, int end, int sum, SegmentTreeNode* left, SegmentTreeNode* right):
    start(start), end(end), sum(sum), left(left), right(right) {}
}

// O(n)
SegmentTreeNode* build_tree(int start, int end, vector<int> vals) {
  if (start == end) {
    return SegmentTreeNode(start, end, vals[start]);
  }
  int mid = (start + end) / 2;
  auto left = build_tree(start, mid, vals)
  auto right = build_tree(mid + 1, end, vals)
  // change this sentence
  return SegmentTreeNode(start, end, left.sum + right.sum, left, right);
}

// O(log n)
void updateTree(SegmentTreeNode* root, int index, val) {
  if (root.start == root.end == index) { // leaf node
    root.sum = val;
    return;
  }
  int mid = (root.start + root.end) / 2;
  if (index <= mid) {
    updateTree(root->left, index, val);
  } else {
    updateTree(root->right, index, val);
  }
  // change this sentence
  root.sum = root->left.sum + root->right.sum; 
}

// O(logn + k) 
int query(SegmentTreeNode* root, int i, int j) {
  if (root->start == i && root->end == j) {
    return root->sum;
  }
  int mid = (root->start + root->end) / 2;
  if (j <= mid) {
    return query(root->left, i, j);
  } else if (i > mid) {
    return query(root->right, i, j);
  } else {
    return query(root->left, i, mid) + query(root->right, mid + 1, j);
  }
}

