#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node* n, Node* p) : val(x), next(n), prev(p) {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void pushBack(int x) {
        Node* newNode = new Node(x, nullptr, tail);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void clearList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

Node* splitList(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = nullptr;
    if (temp) temp->prev = nullptr;
    return temp;
}

Node* mergeTwoLists(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->val < second->val) {
        first->next = mergeTwoLists(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    }
    else {
        second->next = mergeTwoLists(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

Node* mergeSortHelper(Node* head) {
    if (!head || !head->next) return head;
    Node* second = splitList(head);
    head = mergeSortHelper(head);
    second = mergeSortHelper(second);
    return mergeTwoLists(head, second);
}

void mergeSort(DoublyLinkedList& list) {
    if (!list.head || !list.head->next) return;
    list.head = mergeSortHelper(list.head);

    Node* curr = list.head;
    while (curr && curr->next) {
        curr = curr->next;
    }
    list.tail = curr;
}

void insertionSort(DoublyLinkedList& list) {
    if (!list.head || !list.head->next) return;

    Node* sortedTail = list.head;
    Node* curr = list.head->next;

    while (curr) {
        Node* nextNode = curr->next;

        if (curr->val >= sortedTail->val) {
            sortedTail = curr;
        }
        else {
            sortedTail->next = nextNode;
            if (nextNode) nextNode->prev = sortedTail;

            Node* temp = list.head;
            while (temp != sortedTail->next && temp->val < curr->val) {
                temp = temp->next;
            }

            if (temp == list.head) {
                curr->next = list.head;
                curr->prev = nullptr;
                list.head->prev = curr;
                list.head = curr;
            }
            else {
                curr->next = temp;
                curr->prev = temp->prev;
                temp->prev->next = curr;
                temp->prev = curr;
            }
        }
        curr = nextNode;
    }

    Node* tailNode = list.head;
    while (tailNode && tailNode->next) {
        tailNode = tailNode->next;
    }
    list.tail = tailNode;
}

int getMaxVal(Node* head) {
    int maxVal = head->val;
    Node* curr = head->next;
    while (curr) {
        if (curr->val > maxVal) {
            maxVal = curr->val;
        }
        curr = curr->next;
    }
    return maxVal;
}

void countingSortForRadix(DoublyLinkedList& list, int exp) {
    Node* bucketsHead[10] = { nullptr };
    Node* bucketsTail[10] = { nullptr };

    Node* curr = list.head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = nullptr;
        curr->prev = nullptr;

        int digit = (curr->val / exp) % 10;

        if (!bucketsHead[digit]) {
            bucketsHead[digit] = curr;
            bucketsTail[digit] = curr;
        }
        else {
            bucketsTail[digit]->next = curr;
            curr->prev = bucketsTail[digit];
            bucketsTail[digit] = curr;
        }
        curr = nextNode;
    }

    list.head = nullptr;
    list.tail = nullptr;

    for (int i = 0; i < 10; i++) {
        if (bucketsHead[i]) {
            if (!list.head) {
                list.head = bucketsHead[i];
                list.tail = bucketsTail[i];
            }
            else {
                list.tail->next = bucketsHead[i];
                bucketsHead[i]->prev = list.tail;
                list.tail = bucketsTail[i];
            }
        }
    }
}

void radixSort(DoublyLinkedList& list) {
    if (!list.head || !list.head->next) return;
    int maxVal = getMaxVal(list.head);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(list, exp);
    }
}

void buildListFromVector(DoublyLinkedList& list, const vector<int>& arr) {
    list.clearList();
    for (int x : arr) {
        list.pushBack(x);
    }
}

Node* mergeTwoLists(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    if (first->val < second->val) {
        first->next = mergeTwoLists(first->next, second);
        if (first->next) first->next->prev = first;
        first->prev = nullptr;
        return first;
    }
    else {
        second->next = mergeTwoLists(first, second->next);
        if (second->next) second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

void mergeSort(DoublyLinkedList& list) {
    if (!list.head || !list.head->next) return;

    Node* slow = list.head;
    Node* fast = list.head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    DoublyLinkedList rightList;
    rightList.head = slow->next;
    if (rightList.head) rightList.head->prev = nullptr;
    slow->next = nullptr;
    list.tail = slow;

    Node* currRight = rightList.head;
    while (currRight && currRight->next) {
        currRight = currRight->next;
    }
    rightList.tail = currRight;

    mergeSort(list);
    mergeSort(rightList);

    list.head = mergeTwoLists(list.head, rightList.head);

    Node* curr = list.head;
    while (curr && curr->next) {
        curr = curr->next;
    }
    list.tail = curr;
}

int main() {
    vector<int> data1 = { 38, 27, 43, 3, 9, 82, 10 };
    vector<int> data2 = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };
    vector<int> data3 = { 170, 45, 75, 90, 802, 24, 2, 66 };

    DoublyLinkedList listForMerge;
    buildListFromVector(listForMerge, data1);
    cout << "Merge Sort Input:  ";
    listForMerge.printList();
    mergeSort(listForMerge);
    cout << "Merge Sort Output: ";
    listForMerge.printList();
    cout << "---" << endl;

    DoublyLinkedList listForInsertion;
    buildListFromVector(listForInsertion, data2);
    cout << "Insertion Sort Input:  ";
    listForInsertion.printList();
    insertionSort(listForInsertion);
    cout << "Insertion Sort Output: ";
    listForInsertion.printList();
    cout << "---" << endl;

    DoublyLinkedList listForRadix;
    buildListFromVector(listForRadix, data3);
    cout << "Radix Sort Input:  ";
    listForRadix.printList();
    radixSort(listForRadix);
    cout << "Radix Sort Output: ";
    listForRadix.printList();

    return 0;
}