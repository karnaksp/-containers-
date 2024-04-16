#ifndef S21_ITERATOR_H_
#define S21_ITERATOR_H_

#include <iostream>

namespace s21 {
enum RBColor { BLACK, RED };

template <class T>
struct Node {
  using key_type = T;
  key_type key;
  Node *parent{nullptr};
  Node *left{nullptr}, *right{nullptr};
  bool color{RED};

  Node() = default;

  Node(const key_type &key) : key(key) {}
  Node(key_type &&key) : key(std::move(key)) {}

  ~Node() = default;
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

  Iterator() = default;

  explicit Iterator(tree_node *Node) : ptr_node_(Node) {}

  Iterator(const iterator &it) = default;

  Iterator(iterator &&it) = default;

  iterator &operator=(const iterator &it) = default;

  iterator &operator=(iterator &&it) = default;

  ~Iterator() = default;

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

  iterator operator++(int) {
    iterator tmp{*this};
    ++(*this);
    return tmp;
  }

  reference operator*() { return ptr_node_->key; }

  pointer operator->() { return &ptr_node_->key; }

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
    iterator tmp{*this};
    --(*this);
    return tmp;
  }

  bool operator==(const iterator &other) const {
    return ptr_node_ == other.ptr_node_;
  }

  bool operator!=(const iterator &other) const {
    return ptr_node_ != other.ptr_node_;
  }

  tree_node *ptr_node_{nullptr};
};

template <class T>
class ConstIterator {
 public:
  using key_type = T;
  using tree_node = s21::Node<key_type>;
  using iterator = ConstIterator<key_type>;
  using pointer = const key_type *;
  using reference = const key_type &;

  explicit ConstIterator(tree_node *Node = nullptr) : ptr_node_(Node) {}

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
    iterator tmp{*this};
    --(*this);
    return tmp;
  }

  iterator operator++(int) {
    iterator tmp{*this};
    ++(*this);
    return tmp;
  }

  bool operator==(const iterator &other) const {
    return ptr_node_ == other.ptr_node_;
  }

  bool operator!=(const iterator &other) const {
    return ptr_node_ != other.ptr_node_;
  }

  reference operator*() const { return ptr_node_->key; }

  pointer operator->() const { return &ptr_node_->key; }

 private:
  tree_node *ptr_node_{nullptr};
};
}  // namespace s21
#endif  // S21_ITERATOR_H_