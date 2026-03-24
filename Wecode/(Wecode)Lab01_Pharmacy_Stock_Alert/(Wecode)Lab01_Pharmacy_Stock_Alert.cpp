#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MEDICINE {
	string name;
	unsigned int stock;
};

string findMiniumStock(vector<MEDICINE> medicines) {
	string res = medicines[0].name;
	unsigned int min = medicines[0].stock;
	for (int i = 1; i < medicines.size(); i++) {
		if (medicines[i].stock < min) {
			min = medicines[i].stock;
			res = medicines[i].name;
		}
	}
	return res;
}

int main() {
	unsigned int n;
	cin >> n;

	vector<MEDICINE> medicines(n);
	for (int i = 0; i < n; i++) cin >> medicines[i].name >> medicines[i].stock;

	cout << findMiniumStock(medicines);
	return 0;
}