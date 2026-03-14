#include <iostream>
#include <vector>

using namespace std;

struct output {
    int location;
    int iteration;
};

int main() {
    int N, x;
    int ammount = 0;
    int count = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> x;
    vector<output> B;
    for (int i = 0; i < N; i++) {
        count++;
        if (A[i] == x) {
            ammount++;
            output a;
            a.location = i;
            a.iteration = count;
            B.push_back(a);
        }
    }
    if (ammount == 0) {
        cout << 0;
    }
    else {
        cout << ammount << endl;
        for (int i = 0; i < ammount; i++) {
            cout << B[i].location <<" "<< B[i].iteration << endl;
        }
    }
    return 0;
}