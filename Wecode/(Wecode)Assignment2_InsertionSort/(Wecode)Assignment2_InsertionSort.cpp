#include <iostream>
#include <vector>

using namespace std;

void inMang(const vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << (i == A.size() - 1 ? "" : " ");
    }
    cout << endl;
}

void insertionSortGiamDan(vector<int>& A) {
    int n = A.size();

    cout << "Mang truoc khi sap xep:" << endl;
    inMang(A);
    cout << "Sap xep:" << endl;

    for (int i = 1; i < n; i++) {
        cout << "i = " << i << endl;
        cout << "Mang truoc khi xu ly: "; inMang(A);

        int key = A[i]; 
        cout << "Phan tu dang xet A[" << i << "] = " << key << endl;

        int j = i - 1;

        while (j >= 0 && A[j] < key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key; 
        cout << "Chen " << key << " vao vi tri k = " << j + 1 << endl;
        cout << "Mang sau khi xu ly: "; inMang(A);
    }

    cout << "Mang sau khi sap xep:" << endl;
    inMang(A);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    insertionSortGiamDan(A);

    return 0;
}