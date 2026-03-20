#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& mang, int i, int j) {
	int temp = mang[i];
	mang[i] = mang[j];
	mang[j] = temp;
}

void printArray(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}

void selectionSort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		swap(arr, i, min_idx);
		if (min_idx != i) {
			printArray(arr);
			cout << endl;
		}
	}
}

int main() {
	int n;
	cin >> n; 
	vector<int> arr(n);
	for (int i = 0; i < arr.size(); i++) cin >> arr[i];
	selectionSort(arr);
	return 0;
}