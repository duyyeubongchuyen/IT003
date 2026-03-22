#include <iostream>

using namespace std;

int search(int arr[], int N, int x) {
    if (N == 0) return -1;
    int index = 0;
    while (index<N&&arr[index] != x) index++;
    if (index == N) return -1;
    return index;
}

int main() {
    int arr[100], n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout << search(arr, n, x) << endl;
    return 0;
}