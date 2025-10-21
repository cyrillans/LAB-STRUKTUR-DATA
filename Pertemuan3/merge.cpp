#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
   
    int n1 = mid - left + 1;  //menghitung jumlah subarray kiri
    int n2 = right - mid;    //menghitung jumlah sub array kanan


    vector<int> L(n1), R(n2); //membuat 2 subarray bantu, menampung yang sebelah kiri dan kanan


    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; //menyalin elemen subarray kiri ke L
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; //menyalin elemen subarray kanan ke R


    int i = 0;    
    int j = 0;      
    int k = left; //hasil gabungan mulai dari left

/* selama kedua array bantu masih punya elemen, bandingkan L[i] dan R[j]*/
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

/*menyalin sisa elemen L kalau R habis*/
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

/*menyalin sisa elemen R kalau L habis*/
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
   
    /*kalau bagian array yang sedang diproses hanya punya 1 elemen atau kosong,
     tidak perlu diurutkan lagi — karena otomatis sudah terurut*/
    if (left >= right) 
        return;

    /*menghitung indeks tengah untuk memecah array menjadi dua bagian*/
    int mid = left + (right - left) / 2;


    mergeSort(arr, left, mid); //mengurutkan bagian kiri
    mergeSort(arr, mid + 1, right); //mengurutkan bagian kanan
   
    merge(arr, left, mid, right); //menggabungkan kedua bagian jadi sudah terurut
}

/* Untuk menampilkan seluruh elemen array ke layar*/
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n); //print elemen data yg dimasukkan
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    mergeSort(data, 0, n - 1);
   
    cout << "Array setelah diurutkan: ";
    printArray(data); //print data setelah diurutkan
   
    return 0;
}