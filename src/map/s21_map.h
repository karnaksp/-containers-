#ifndef S21_MAP_H_
#define S21_MAP_H_
#include "../rb-tree/s21_tree.h"

namespace s21 {
template <class Key, class Type>
class map {
 public:
  using MapKey = Key;
  using MapType = Type;
  using MapValue = std::pair<const MapKey, MapType>;
  using reference = MapValue &;
  using const_reference = const MapValue &;
  using size_type = std::size_t;

  struct CompareLess {
    /**
     * @brief Compares two key-value pairs by the keys.
     *
     * @param key1 The first key-value pair.
     * @param key2 The second key-value pair.
     *
     * @return True if the first key is less than the second key, false
     *         otherwise.
     */
    bool operator()(const std::pair<const Key, MapType> &key1,
                    const std::pair<const Key, MapType> &key2) const {
      return (key1.first < key2.first);
    }
  };

  using MapTree = s21::RBTree<MapValue, CompareLess>;
  using iterator = typename MapTree::iterator;
  using const_iterator = typename MapTree::const_iterator;

 public:
  map() : RBTree(new MapTree{}){};
  map(std::initializer_list<MapValue> const &items);
  map(const map &other) : RBTree(new MapTree(*other.RBTree)){};
  map(map &&other) : RBTree(new MapTree(std::move(*other.RBTree))){};
  map &operator=(const map &other);
  map &operator=(map &&other);
  ~map() { delete RBTree; };

  MapType &at(const MapKey &key);
  MapType &operator[](const MapKey &key);

  iterator end() noexcept;
  const_iterator end() const noexcept;
  iterator begin() noexcept;
  const_iterator begin() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear();

  std::pair<iterator, bool> insert(const MapValue &value);
  std::pair<iterator, bool> insert(const MapKey &key, const MapType &obj);

  std::pair<iterator, bool> insert_or_assign(const MapKey &key,
                                             const MapType &obj);

  void merge(map &other);
  bool contains(const MapKey &key) const;
  void erase(iterator pos);
  void swap(map &other);

 private:
  MapTree *RBTree;
};
}  // namespace s21

#include "s21_map.tcc"

#endif  // S21_MAP_H_
