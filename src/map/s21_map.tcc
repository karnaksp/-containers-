#include "s21_map.h"

namespace s21 {
template <class MapKey, class MapType>
map<MapKey, MapType>::map(std::initializer_list<MapValue> const& items)
    : map() {
  for (auto i : items) {
    insert(i);
  }
}

template <class MapKey, class MapType>
map<MapKey, MapType>& map<MapKey, MapType>::operator=(
    map<MapKey, MapType>&& other) {
  if (this != &other) {
    *RBTree = std::move(*other.RBTree);
  }
  return *this;
}

template <class MapKey, class MapType>
map<MapKey, MapType>& map<MapKey, MapType>::operator=(
    const map<MapKey, MapType>& other) {
  if (this != &other) {
    clear();
    for (auto i = other.begin(); i != other.end(); ++i)
      RBTree->Insert(i.ptr_node_->key);
  }
  return *this;
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::MapType& map<MapKey, MapType>::at(
    const MapKey& key) {
  MapValue search(key, MapType{});
  iterator it = RBTree->TreeSearch(search);
  if (it == end()) throw std::out_of_range("s21::map::at");
  return (*it).second;
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::MapType& map<MapKey, MapType>::operator[](
    const MapKey& key) {
  MapValue search(key, MapType{});
  iterator it = RBTree->TreeSearch(search);
  if (it == end()) {
    auto it_iterator = RBTree->Insert(search);
    it = it_iterator.first;
  }
  return (*it).second;
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::iterator map<MapKey, MapType>::end() noexcept {
  return RBTree->TreeEnd();
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::const_iterator map<MapKey, MapType>::end()
    const noexcept {
  return RBTree->TreeConstEnd();
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::iterator map<MapKey, MapType>::begin() noexcept {
  return RBTree->TreeBegin();
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::const_iterator map<MapKey, MapType>::begin()
    const noexcept {
  return RBTree->TreeConstBegin();
}

template <class MapKey, class MapType>
std::pair<typename map<MapKey, MapType>::iterator, bool>
map<MapKey, MapType>::insert(const MapKey& key, const MapType& obj) {
  return insert(std::pair<MapKey, MapType>(key, obj));
}

template <class MapKey, class MapType>
std::pair<typename map<MapKey, MapType>::iterator, bool>
map<MapKey, MapType>::insert(const MapValue& value) {
  std::pair<iterator, bool> res = RBTree->Insert(value);
  return res;
}

template <class MapKey, class MapType>
bool map<MapKey, MapType>::empty() const noexcept {
  return RBTree->TreeEmpty();
}

template <class MapKey, class MapType>
void map<MapKey, MapType>::clear() {
  RBTree->TreeClear();
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::size_type map<MapKey, MapType>::size()
    const noexcept {
  return RBTree->TreeSize();
}

template <class MapKey, class MapType>
typename map<MapKey, MapType>::size_type map<MapKey, MapType>::max_size()
    const noexcept {
  return RBTree->TreeMaxSize();
}

/**
 * @brief Inserts a new element or assigns the value to an existing element.
 *
 * @param key The key of the element to insert or assign.
 * @param obj The value to assign to the element.
 *
 * This function first searches for the element with the specified key. If
 * the element is not found, the function inserts a new element with the
 * specified key and the specified value. If the element is found, the
 * function assigns the specified value to the element. The function returns
 * a pair of iterator and boolean. The iterator points to the inserted element
 * or the existing element. The boolean is true if the element is inserted,
 * false otherwise.
 */
template <class MapKey, class MapType>
std::pair<typename map<MapKey, MapType>::iterator, bool>
map<MapKey, MapType>::insert_or_assign(const MapKey& key, const MapType& obj) {
  MapValue search(key, MapType{});
  iterator res = RBTree->TreeSearch(search);

  std::pair<iterator, bool> pair_iter{res, false};
  if (res == end()) {
    pair_iter = RBTree->Insert({key, obj});
  } else {
    (*res).second = obj;
  }
  return pair_iter;
}

/**
 * @brief Erases the element at the specified iterator.
 *
 * @param pos The iterator to the element to erase.
 *
 * This function calls the TreeErase function from the underlying Red-Black
 * tree class. The function erases the element at the specified iterator.
 *
 * @throws std::runtime_error if the iterator is not valid.
 */
template <class MapKey, class MapType>
void map<MapKey, MapType>::erase(typename map<MapKey, MapType>::iterator pos) {
  try {
    RBTree->TreeErase(pos.ptr_node_);
  } catch (...) {
    throw std::runtime_error("s21::map::erase");
  }
}

/**
 * @brief Swaps the contents of this map with the contents of the other map.
 *
 * @param other The map to swap contents with.
 *
 * This function calls the TreeSwap function from the underlying Red-Black tree
 * class. The function swaps the contents of the two Red-Black trees, which
 * effectively swaps the contents of the two maps.
 */
template <class MapKey, class MapType>
void map<MapKey, MapType>::swap(map& other) {
  RBTree->TreeSwap(*other.RBTree);
}

/**
 * @brief Merges two maps by inserting all key-value pairs from the other map
 *        into this map, without duplicates.
 *
 * @param other The map to merge into this map.
 *
 * This function uses the underlying Red-Black tree's TreeMergeUniq function
 * which inserts all key-value pairs from the other Red-Black tree into this
 * Red-Black tree, without duplicates. The function uses the operator< to
 * determine equality of keys.
 */
template <class MapKey, class MapType>
void map<MapKey, MapType>::merge(map& other) {
  RBTree->TreeMergeUniq(*other.RBTree);
}

/**
 * @brief Checks if the map contains a key-value pair with the given key.
 *
 * @param key The key to search for.
 *
 * @return True if the map contains a key-value pair with the given key, false
 *         otherwise.
 *
 * This function uses the underlying Red-Black tree's TreeConstSearch function
 * to find the given key. If the key is found, the function returns true. If
 * the key is not found, the function returns false.
 */
template <class MapKey, class MapType>
bool map<MapKey, MapType>::contains(const MapKey& key) const {
  MapValue search(key, MapType{});
  const_iterator it = RBTree->TreeConstSearch(search);
  return it != end();
}

};  // namespace s21
