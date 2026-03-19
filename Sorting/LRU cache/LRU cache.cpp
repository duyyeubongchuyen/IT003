#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

struct LRUCache {
    int capacity;
    unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNodeToHead(node);
    }

    Node* popTail() {
        Node* lruNode = tail->prev;
        removeNode(lruNode);
        return lruNode;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        Node* node = cacheMap[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->val = value;
            moveToHead(node);
        }
        else {
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            addNodeToHead(newNode);

            if (cacheMap.size() > capacity) {
                Node* tailNode = popTail();
                cacheMap.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};

int main() {
    LRUCache lru(2);

    lru.put(1, 10);
    lru.put(2, 20);
    cout << "Get 1: " << lru.get(1) << "\n";

    lru.put(3, 30);
    cout << "Get 2: " << lru.get(2) << "\n";

    lru.put(4, 40);
    cout << "Get 1: " << lru.get(1) << "\n";
    cout << "Get 3: " << lru.get(3) << "\n";
    cout << "Get 4: " << lru.get(4) << "\n";

    return 0;
}