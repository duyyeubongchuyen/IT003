#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int partition(vector<int>& array, int low, int high) {
	int pivot = array[high];

	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (array[j] < pivot) {
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[high], array[i + 1]);
	return i + 1;
}

void quickSort(vector<int>& array,int low,int high) {
	if (low < high) {
		int pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

int upperBound(const vector<int>& array, int x) {
	int low = 0;
	int high = array.size() - 1;
	int res = -1;

	while (high >= low) {
		int mid = low + (high - low) / 2;
		if (array[mid] > x) {
			res = array[mid];
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return res;
}

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<int>fir_arr(N);
	for (int i = 0; i < N; i++) {
		cin >> fir_arr[i];
	}

	vector<int>sec_arr(Q);
	for (int i = 0; i < Q; i++) {
		cin >> sec_arr[i];
	}

	quickSort(fir_arr, 0, N - 1);

	for (int i = 0; i < Q; i++) {
		cout << upperBound(fir_arr, sec_arr[i]) << "\n";
	}


	return 0;
}