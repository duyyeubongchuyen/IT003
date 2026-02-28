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

void insertionSort(int a[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int temp = i;
		while (j >= 0 && (a[temp] < a[j])) {
			swapArray(a, size, temp, j);
			j--;
			temp--;
		}
	}
}

void insertionSortLegit(int a[], int size) {
	for (int i = 0; i < size; i++) {
		int j = i - 1;
		int key = a[i];
		while (j >= 0 && (a[j] > key)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) cout << a[i] << " ";
}

//BÀI 1 – Insertion Sort có ràng buộc(sắp xếp từng đoạn)
//🔹 Mô tả
//
//Cho mảng số nguyên a[0…n - 1] và một số nguyên k.
//
//Yêu cầu :
//
//Chỉ được phép dùng Insertion Sort
//
//Mỗi lần chèn, chỉ được dịch chuyển tối đa k phần tử
//
//Nếu không thể sắp xếp toàn bộ mảng thì in ra "IMPOSSIBLE"

bool bai1(int a[], int size,int k) {
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int key = a[i];
		int count = 0;
		while (j >= 0 && (a[j] > key)) {
			count++;
			a[j + 1] = a[j];
			j--;
			if (count > k) {
				return false;
			}
		}
		a[j + 1] = key;
	}
	return true;
}

int main() {
	int a[] = { 9,10,0,0,3,2 };
	printArray(a, 6);
	cout << endl;
	/*selectionSort(a, 6);
	printArray(a, 6);*/
	/*insertionSortLegit(a, 6);*/
	cout << bai1(a, 6, 2) << endl;
	printArray(a, 6);
}

