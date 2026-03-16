#include <iostream>
#include <string>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh& x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void OutputCompact(Hocsinh hs) {
    cout << hs.Hoten << "\n";
}

void OutputFull(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}

void QuickSort(Hocsinh ls[], int b, int e) {
    int left = b;
    int right = e;
    string pivot = ls[left + (right - left) / 2].Hoten;

    while (left <= right) {
        while (ls[left].Hoten < pivot) left++;
        while (ls[right].Hoten > pivot) right--;

        if (left <= right) {
            Hocsinh temp = ls[left];
            ls[left] = ls[right];
            ls[right] = temp;

            left++;
            right--;
        }
    }

    if (e > left) QuickSort(ls, left, e);
    if (b < right) QuickSort(ls, b, right);

}

int main()
{
    Hocsinh* ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    QuickSort(ls, 0, n - 1);
    for (int i = 0; i < n; i++) {
        OutputCompact(ls[i]);
    }
    delete[] ls;
    return 0;
}



