#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int result(vector<int> input,int x) {
	int i = 0;

	while (!(input[i] > x)) {
		i++;
		if (i == input.size()) return -1;
	}
	
	int min = input[i];;

	for (i ; i < input.size(); i++) {
		if ((input[i] < min) && (input[i] > x)) {
			min = input[i];
		}
	}
	return min;
}

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<int> fir_array(N);
	for (int i = 0; i < N; i++) {
		cin >> fir_array[i];	
	}
	
	vector<int> sec_array(Q);
	for (int i = 0; i < Q; i++) {
		cin >> sec_array[i];
	}

	for (int i = 0; i < Q; i++) {
		cout << result(fir_array, sec_array[i]) << endl;
	}

	return 0;
}