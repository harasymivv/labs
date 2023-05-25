#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

#include <iostream>
#include <string>

template <typename K, typename V>
class LinkedListMap {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;

public:
    LinkedListMap();
    ~LinkedListMap();
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node);
        bool isEnd() const;
        V& operator*() const;
        Iterator& operator++();
    };
      
    Iterator begin() const;
    void main_method();
    void insert(const K& key, const V& value);
    void find_min_key_pair();
    void check_for_elem_exists();
    void remove(const K& key);
    void search(const K& key);
    void clear();
    void print_all();

    Iterator it = begin();
    void iterator_operations();
};

#endif  