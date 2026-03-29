#include "HashTableOpen.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    HashTableOpen<string, string> ht(10);

    cout << "=== insert ===" << endl;
    ht.insert("banana", "a fruit");
    ht.insert("cactus", "a pointy plant");
    ht.insert("dog", "a fluffy animal");
    cout << endl;

    cout << "=== size ===" << endl;
    cout << "size: " << ht.size() << " (expected: 3)" << endl;
    cout << endl;

    cout << "=== find ===" << endl;
    try {
        cout << "banana: " << ht.find("banana") << endl;
        cout << "dog: " << ht.find("dog") << endl;
    } catch (string& e) {
        cout << "Error: " << e << endl;
    }
    cout << endl;

    cout << "=== find (key not found) ===" << endl;
    try {
        ht.find("zebra");
    } catch (string& e) {
        cout << "Caught: " << e << endl;
    }
    cout << endl;

    cout << "=== remove ===" << endl;
    try {
        ht.remove("cactus");
        cout << "removed cactus" << endl;
        cout << "size after remove: " << ht.size() << " (expected: 2)" << endl;
    } catch (string& e) {
        cout << "Error: " << e << endl;
    }
    cout << endl;

    cout << "=== remove (key not found) ===" << endl;
    try {
        ht.remove("cactus");
    } catch (string& e) {
        cout << "Caught: " << e << endl;
    }
    cout << endl;

    cout << "=== clear ===" << endl;
    ht.clear();
    cout << "size after clear: " << ht.size() << " (expected: 0)" << endl;
    cout << endl;

    cout << "=== find after clear ===" << endl;
    try {
        ht.find("banana");
    } catch (string& e) {
        cout << "Caught: " << e << endl;
    }
    cout << endl;

    cout << "=== collision handling ===" << endl;
    ht.insert("abc", "first");
    ht.insert("abc", "second");
    cout << "size: " << ht.size() << endl;
    cout << endl;

    cout << "=== all tests done ===" << endl;
    return 0;
}
