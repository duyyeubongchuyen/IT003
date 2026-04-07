#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partipation(vector<int>& arr,int low,int high) {
	int pivot = arr[high];
	int j = low;
	int i = j - 1;
	while (j < high) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[j], arr[i]);
		}
		j++;
	}
	swap(arr[high], arr[i + 1]);
	return i + 1; // vị trí của pivot 
}

void quickSort(vector<int>& arr, int low, int high) {
	if (high > low) {
		int pi = partipation(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int lowerBound(const vector<int>& arr,int query) {
	int high = arr.size() - 1;
	int low = 0;
	int res;
	bool check = false;
	while (high >= low) {
		int mid = low + (high - low) / 2;
		if (arr[mid] < query) {
			low = mid + 1;
		}
		else {
			check = true;
			res = arr[mid];
			high = mid - 1;
		}
	}
	if (check) return res;
	return -1;
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> arr(N);
	vector<int> query(Q);
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < Q; i++) cin >> query[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < Q; i++) {
		cout << lowerBound(arr, query[i]) << '\n';
	}

	return 0;
}