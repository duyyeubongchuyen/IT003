#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> mang, int i, int j) {
	int temp = mang[i];
	mang[i] = mang[j];
	mang[j] = temp;
}

int findMin(vector<int> mang, int index, int& result) {    // Trả về index của min
	int min = mang[index];
	index++;
	result = index;
	for (index; index < mang.size(); index++) {
		if (mang[index] < min) {
			min = mang[index];
			result = index;
		}
	}
	return min;
}

void selectionSort(vector<int> mang) {
	for (int i = 0; i < mang.size() - 1; i++) {
		int minIndex = 0;
		int min = findMin(mang, i + 1, minIndex);
		if (min < mang[i]) swap(mang, i, minIndex);
	}
}

void printArray(vector<int> mang) {
	for(int i = 0; i < mang.size(); i++)
		cout << mang[i] << " ";
}

int main() {
	vector<int> mang = { 5 ,9 ,10, 4, 3,0 ,1, 2 };
	printArray(mang);
	cout << endl;
	selectionSort(mang);
	printArray(mang);
	return 0;
}