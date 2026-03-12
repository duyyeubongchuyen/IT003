#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int N, x;
    cin >> N;
    vector<int> A(N);
    int count1 = 0;
    int count2 = 0;
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> x;

    //Dòng đầu tiên là vị trí của x đầu tiên trong mảng nếu tìm được. Nếu không tìm thấy thì xuất ra -1

   //Số lần duyệt qua các phần tử của mảng (từ đầu mảng đến cuối) để tìm được x

    //Dòng thứ ba là vị trí của x đầu tiên trong mảng (đếm từ cuối đến đầu) nếu tìm được. Nếu không tìm thấy thì xuất ra -1

    //Số lần duyệt qua các phần tử của mảng (từ cuối mảng đến đầu) để tìm được x

   //Nếu như ở 2 dòng đầu tiên mà không tìm thấy thì không cần xuất ra 2 dòng tiếp theo

    for (int i = 0; i < N; i++) {
        count1++;
        if (A[i] == x) {
            flag1 = true;
            cout << i << endl;
            break;
        }
    }
    if (flag1) {

        cout << count1 << endl;

        for (int i = N - 1; i >= 0; i--) {
            count2++;
            if (A[i] == x) {
                flag2 = true;
                cout << abs(i - (N - 1)) << endl;
                break;
            }
        }
        if (flag2) {
            cout << count2 << endl;
        }
        else {
            cout << -1;
        }
    }
    else {
        cout << -1;
    }
}