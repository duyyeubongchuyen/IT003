#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void printArr(vector<int>arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}


void bubbleSort(vector<int>& arr) {
	bool swapped;
	for (int i = 0; i < arr.size()-1; i++) {
		swapped = false;
		for (int j = 0; j < arr.size() - 1-i; j++) {
			if (arr[j + 1] < arr[j]) {
				swap(arr, j, j + 1);
				printArr(arr);
				cout << endl;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	bubbleSort(arr);
}