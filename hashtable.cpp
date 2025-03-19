#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable {
private:
    static const int size = 10;
    std::vector<std::list<std::pair<std::string, int>>> table;

    int _hash(const std::string &key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash + ch) % size;
        }
        return hash;
    }

public:
    HashTable() : table(size) {}

    void insert(const std::string &key, int value) {
        int index = _hash(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; 
                return;
            }
        }
        table[index].push_back({key, value});
    }

    int get(const std::string &key) {
        int index = _hash(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) return pair.second;
        }
        return -1;
    }

    void remove(const std::string &key) {
        int index = _hash(key);
        table[index].remove_if([&](const std::pair<std::string, int> &pair) {
            return pair.first == key;
        });
    }
};

int main() {
    HashTable ht;
    return 0;
}
