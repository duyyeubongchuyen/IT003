#include <iostream>

using namespace std;

void swapArray(int a[], int size, int fir, int sec) {
	int temp = a[fir];
	a[fir] = a[sec];
	a[sec] = temp;
}

void selectionSort(int a[], int size) {// Duyệt min với current
	for (int i = 0; i < size-1; i++) {
		int index = i + 1;
		int min = a[i + 1];
		for (int j = i + 2; j < size; j++)
			if (a[j] < min) {
				min = a[j];
				index = j;
			}
		if (min < a[i]) swapArray(a, size, index, i);
	}
}

void insert(int a[], int size, int curindex,int newindex){
	for (int i = newindex; i < size-1; i++) {
		int temp = a[i];
		a[i + 1] = temp;
	}
}

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) cout << a[i] << " ";
}

int main() {
	int a[] = { 9,0,1,5,3,2 };
	printArray(a, 6);
	cout << endl;
	selectionSort(a, 6);
	printArray(a, 6);
}

