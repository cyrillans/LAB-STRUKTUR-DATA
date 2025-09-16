#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah element erray : ";
    cin >> n;

    int* arr = new int[n];

    cout << "Masukkan " << n << " angka :\n";
    for (int i = 0; i < n; i++ ){
        cin >> arr[i];
    }
    cout << "Isi Array : ";
    for (int i = 0; i < n; i++ ){
        cout << arr[i] << i << " ";
    }
    delete[] arr;
    return 0;
}