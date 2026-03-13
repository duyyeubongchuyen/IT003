#include <iostream>
#include <vector>

using namespace std;

struct XYZ {
    float x;
    float y;
    float z;
};

int main() {
    int n, m;
    cin >> n;
    vector<XYZ> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    cin >> m;
    vector<XYZ> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i].x >> B[i].y >> B[i].z;
    }
    for (int i = 0; i < m; i++) {
        int j = 0;
        while (j < n&&(B[i].x != A[j].x || B[i].y != A[j].y || B[i].z != A[j].z)) j++;
        if (j == n) cout << "KHONG" << endl;
        else cout << j << endl;
    }
    return 0;
}