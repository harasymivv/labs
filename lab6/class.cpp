#include "class.h"

using namespace std;

template <typename K, typename V>
LinkedListMap<K, V>::LinkedListMap() : head(nullptr) {}

template <typename K, typename V>
LinkedListMap<K, V>::~LinkedListMap() {
    clear();
}

template <typename K, typename V>
void LinkedListMap<K, V>::main_method() {
    char check;
    int n;
    int options;
    K key_element;
    V value_element;
    
    cout << "\nHow many elements do you want to enter?" << endl;
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter key of " << i + 1 << " element: ";
        cin >> key_element;

        cout << "Enter value of " << i + 1 << " element: ";
        cin >> value_element;
        cout << endl;
        insert(key_element, value_element);
    }

    do {
        cout << "\n1. Check for the existence of elements in the array\n"
             << "2. Clear array\n"
             << "3. Search for a pair with the minimum key value\n"
             << "4. Removing the pair by key\n"
             << "5. An iterator for accessing array elements with operations" << endl;
        cout << "Enter option: ";
        cin >> options;
        cout << endl;
        switch (options) {
            case 1: {
                check_for_elem_exists();
                break;
            }
            case 2: {
                clear();
                break;
            }
            case 3: {
                find_min_key_pair();
                break;
            }
            case 4: {
                cout << "Enter key of pair: ";
                cin >> key_element;
                remove(key_element);
                break;
            }
            case 5: {
                iterator_operations();
                break;
            }
            default: {
                cout << "Option is out of range" << endl;
                break;
            }
        }

        cout << "Do you want to do something else? (y/n): ";
        cin >> check;
    } while (check == 'y' || check == 'Y');
    // print_all();
}

template <typename K, typename V>
void LinkedListMap<K, V>::insert(const K& key, const V& value) {
    Node* newNode = new Node(key, value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

template <typename K, typename V>
void LinkedListMap<K, V>::find_min_key_pair() {
    if (head == nullptr) {
        cout << "No elements in the array." << endl;
        return;
    }
    Node* curr = head;
    K minKey = curr->key;
    V minValue = curr->value;

    while (curr != nullptr) {
        if (curr->key < minKey) {
            minKey = curr->key;
            minValue = curr->value;
        }
        curr = curr->next;
    }
    cout << "Pair with minimum key: Key = " << minKey << ", Value = " << minValue << endl;
}

template <typename K, typename V>
void LinkedListMap<K, V>::check_for_elem_exists() {
    if (head != nullptr)
        cout << "Elements exist in the array." << endl;
    else
        cout << "No elements in the array." << endl;
}

template <typename K, typename V>
void LinkedListMap<K, V>::remove(const K& key) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->key == key) {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

template <typename K, typename V>
void LinkedListMap<K, V>::search(const K& key) {
    Node* curr = head;
    int all_pair = 0;
    int not_search_key = 0;
    while (curr != nullptr) {
        all_pair += 1;
        if (curr->key == key) {
            cout << "Value: " << curr->value << endl;
        } else {
            not_search_key += 1;
        }
        curr = curr->next;
    }
    if (not_search_key == all_pair) {
        cout << "Cannot found this pair" << endl;
    }
}

template <typename K, typename V>
void LinkedListMap<K, V>::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

template <typename K, typename V>
void LinkedListMap<K, V>::print_all() {
    Node* curr = head;
    cout << "print:" << endl;
    while (curr != nullptr) {
        cout << "Key: " << curr->key << ", Value: " << curr->value << endl;
        curr = curr->next;
    }
}

template <typename K, typename V>
LinkedListMap<K, V>::Iterator::Iterator(Node* node) : current(node) {}

template <typename K, typename V>
bool LinkedListMap<K, V>::Iterator::isEnd() const {
    return current == nullptr;
}

template <typename K, typename V>
V& LinkedListMap<K, V>::Iterator::operator*() const {
    return current->value;
}

template <typename K, typename V>
typename LinkedListMap<K, V>::Iterator& LinkedListMap<K, V>::Iterator::operator++() {
    if (current != nullptr) {
        current = current->next;
    }
    return *this;
}

template <typename K, typename V>
typename LinkedListMap<K, V>::Iterator LinkedListMap<K, V>::begin() const {
    return Iterator(head);
}

template <typename K, typename V>
void LinkedListMap<K, V>::iterator_operations() {
    int iteratorOption;
    cout << "\nIterator Operations:" << endl;
    cout << "1. Set iterator to the beginning of the array" << endl;
    cout << "2. Check if iterator is at the end of the array" << endl;
    cout << "3. Access the value of the current array element" << endl;
    cout << "4. Move to the next array element" << endl;
    cout << "Enter your option: ";
    cin >> iteratorOption;

    switch (iteratorOption) {
        case 1: {
            it = begin();
            cout << "Iterator set to the beginning of the array." << endl;
            break;
        }
        case 2: {
            if (it.isEnd()) {
                cout << "Iterator is at the end of the array." << endl;
            } else {
                cout << "Iterator is not at the end of the array." << endl;
            }
            break;
        }
        case 3: {
            if (it.isEnd()) {
                cout << "Iterator is at the end of the array." << endl;
            } else {
                cout << "Value of the current array element: " << *it << endl;
            }
            break;
        }
        case 4: {
            if (it.isEnd()) {
                cout << "Iterator is already at the end of the array." << endl;
            } else {
                ++it;
                if (it.isEnd()) {
                    cout << "Iterator moved to the end of the array." << endl;
                } else {
                    cout << "Iterator moved to the next array element." << endl;
                }
            }
            break;
        }
        default: {
            cout << "Invalid option." << endl;
            break;
        }
    }
}

template class LinkedListMap<int, int>;
template class LinkedListMap<int, double>;
template class LinkedListMap<int, char>;
template class LinkedListMap<int, string>;

template class LinkedListMap<double, int>;
template class LinkedListMap<double, double>;
template class LinkedListMap<double, char>;
template class LinkedListMap<double, string>;

template class LinkedListMap<char, int>;
template class LinkedListMap<char, double>;
template class LinkedListMap<char, char>;
template class LinkedListMap<char, string>;

template class LinkedListMap<string, int>;
template class LinkedListMap<string, double>;
template class LinkedListMap<string, char>;
template class LinkedListMap<string, string>;