#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}

void insertionSort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			print(arr);
			cout << endl;
			j--;
		}
		arr[j + 1] = key;
		print(arr);
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < arr.size(); i++) cin >> arr[i];
	insertionSort(arr);
	return 0;
}