#ifndef S21_TREE_H_
#define S21_TREE_H_
#include <functional>
#include <iostream>
#include <limits>
#include <utility>

namespace s21 {

enum Color { BLACK, RED };

template <class T>
struct Node {
  using key_type = T;
  key_type key;
  Node *parent;
  Node *left;
  Node *right;
  bool color;

  Node() : parent(nullptr), left(nullptr), right(nullptr), color(RED) {}

  Node(const key_type &key)
      : key(key), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}

  Node(key_type &&key)
      : key(std::move(key)),
        parent(nullptr),
        left(nullptr),
        right(nullptr),
        color(RED) {}

  ~Node() {}
};

template <class T>
class Iterator {
 public:
  using key_type = T;
  using reference = key_type &;
  using const_reference = const reference;
  using pointer = key_type *;
  using tree_node = s21::Node<key_type>;
  using iterator = Iterator;

  Iterator() = delete;

  Iterator(tree_node *Node) : ptr_node_(Node) {}

  Iterator(const iterator &it) : ptr_node_(it.ptr_node_) {}

  Iterator(iterator &&it) : ptr_node_(std::move(it.ptr_node_)) {}

  // ? ---- Операторы присваивания ---- ?

  Iterator &operator=(const iterator &it) {
    ptr_node_ = it.ptr_node_;
    return *this;
  }

  Iterator &operator=(iterator &&it) {
    ptr_node_ = std::move(it.ptr_node_);
    return *this;
  }

  ~Iterator() {}

  // ? ---- Операторы инкремента и декремента ---- ?

  iterator &operator++() {
    if (!ptr_node_) {
      return *this;
    }

    if (ptr_node_->parent == nullptr) {
      ptr_node_ = ptr_node_->left;
      while (ptr_node_->right) ptr_node_ = ptr_node_->right;
      return *this;
    }

    if (ptr_node_->right) {
      ptr_node_ = ptr_node_->right;
      while (ptr_node_->left) ptr_node_ = ptr_node_->left;
    } else {
      tree_node *temp;
      while ((temp = ptr_node_->parent) && ptr_node_ == temp->right) {
        ptr_node_ = temp;
      }
      ptr_node_ = temp;
    }
    return *this;
  }

  reference operator*() { return ptr_node_->key; }

  iterator operator++(int) {
    iterator tmp{ptr_node_};
    ++(*this);
    return tmp;
  }

  iterator &operator--() {
    if (!ptr_node_) {
      return *this;
    }

    if (ptr_node_->left) {
      ptr_node_ = ptr_node_->left;
      while (ptr_node_->right) ptr_node_ = ptr_node_->right;
    } else {
      tree_node *temp;
      while ((temp = ptr_node_->parent) && ptr_node_ == temp->left) {
        ptr_node_ = temp;
      }
      ptr_node_ = temp;
    }
    return *this;
  }

  iterator operator--(int) {
    iterator tmp{ptr_node_};
    --(*this);
    return tmp;
  }

  // ? ---- Операторы сравнения ---- ?

  bool operator==(const iterator &other) {
    return ptr_node_ == other.ptr_node_;
  }

  bool operator!=(const iterator &other) {
    return ptr_node_ != other.ptr_node_;
  }

  tree_node *ptr_node_;
};

template <class T>
class ConstIterator {
 public:
  using key_type = T;
  using tree_node = s21::Node<key_type>;
  using iterator = ConstIterator<key_type>;
  using pointer = const key_type *;
  using reference = const key_type &;
  tree_node *ptr_node_;

  ConstIterator() = delete;

  ConstIterator(tree_node *Node) : ptr_node_(Node) {}

  ConstIterator(const iterator &it) : ptr_node_(it.ptr_node_) {}

  ConstIterator(iterator &&it) : ptr_node_(std::move(it.ptr_node_)) {}

  ConstIterator &operator=(const iterator &it) {
    ptr_node_ = it.ptr_node_;
    return *this;
  }

  ConstIterator &operator=(iterator &&it) {
    ptr_node_ = std::move(it.ptr_node_);
    return *this;
  }

  ~ConstIterator() = default;

  iterator &operator++() {
    if (!ptr_node_) {
      return *this;
    }
    if (ptr_node_->parent == nullptr) {
      ptr_node_ = ptr_node_->left;
      while (ptr_node_->right) ptr_node_ = ptr_node_->right;
      return *this;
    }

    if (ptr_node_->right) {
      ptr_node_ = ptr_node_->right;
      while (ptr_node_->left) ptr_node_ = ptr_node_->left;
    } else {
      tree_node *temp;
      while ((temp = ptr_node_->parent) && ptr_node_ == temp->right) {
        ptr_node_ = temp;
      }
      ptr_node_ = temp;
    }

    return *this;
  }

  iterator &operator--() {
    if (!ptr_node_) {
      return *this;
    }
    if (ptr_node_->left) {
      ptr_node_ = ptr_node_->left;
      while (ptr_node_->right) ptr_node_ = ptr_node_->right;
    } else {
      tree_node *temp;
      while ((temp = ptr_node_->parent) && ptr_node_ == temp->left) {
        ptr_node_ = temp;
      }
      ptr_node_ = temp;
    }
    return *this;
  }

  iterator operator--(int) {
    iterator tmp{ptr_node_};
    --(*this);
    return tmp;
  }

  bool operator==(const iterator &other) {
    return ptr_node_ == other.ptr_node_;
  }

  bool operator!=(const iterator &other) {
    return ptr_node_ != other.ptr_node_;
  }

  reference operator*() { return ptr_node_->key; }

  iterator operator++(int) {
    iterator tmp{ptr_node_};
    ++(*this);
    return tmp;
  }
};

template <class K, class Compare = std::less<K>>
class RBTree {
 public:
  using key_type = K;
  using reference = key_type &;
  using const_reference = const key_type &;
  using size_type = std::size_t;
  using tree_type = RBTree;
  using tree_node = s21::Node<key_type>;
  using iterator = s21::Iterator<key_type>;
  using const_iterator = s21::ConstIterator<key_type>;

 public:
  RBTree() : head_(new tree_node), size_(0){};
  RBTree(const tree_type &other);
  RBTree(tree_type &&other);
  RBTree &operator=(const tree_type &other);
  RBTree &operator=(tree_type &&other);
  ~RBTree();

  iterator TreeBegin() noexcept;
  iterator TreeEnd() noexcept;
  const_iterator TreeConstEnd() const noexcept;
  const_iterator TreeConstBegin() const noexcept;
  iterator TreeSearch(const_reference key);
  const_iterator TreeConstSearch(const_reference key) const;
  bool TreeEmpty() const noexcept;
  size_type TreeSize() const noexcept;
  size_type TreeMaxSize() noexcept;
  iterator TreeErase(iterator pos);
  void TreeClear();
  void TreeSwap(tree_type &other);
  void TreeMerge(tree_type &other);
  void TreeMergeUniq(tree_type &other);
  iterator TreeLowerBound(const key_type &key);
  iterator TreeUpperBound(const key_type &key);
  std::pair<iterator, bool> Insert(const key_type &key);
  void NotUniq() { flag_uniq = false; }

 private:
  tree_node *head_;
  size_type size_;
  Compare less_;
  bool flag_uniq = true;

  tree_node *&root_() const;
  bool IsRed(tree_node *node);
  bool equal(key_type key_1, key_type key_2);
  tree_node *FixUp(tree_node *node);
  tree_node *MostMin(tree_node *node) const;
  tree_node *ColorFlip(tree_node *node);
  tree_node *RotateLeft(tree_node *node);
  tree_node *RotateRight(tree_node *node);
  tree_node *SwapAndDeletenodes(tree_node *node);
  tree_node *LeanRight(tree_node *node);
  tree_node *DeleteMin(tree_node *node);
  tree_node *MoveRedLeft(tree_node *node);
  tree_node *MoveRedRight(tree_node *node);
  tree_node *TreeCopy(const tree_node *node);
  void TreeClear(tree_node *node);
  tree_node *Insert(tree_node *node, tree_node *Parent, const key_type &key,
                    std::pair<iterator, bool> &pair_res);
  tree_node *TreeErase(tree_node *node, iterator pos);
  bool EqualNodes(tree_node *node_1, tree_node *node_2);
  void RessetingParents(tree_node *node);
};
}  // namespace s21
#include "s21_tree.tcc"
#endif  // S21_TREE_H_