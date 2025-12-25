#include <iostream>
using namespace std;
int main(){
    //buat fungsi pencarian biner

    int n, cari, kiri, kanan, tengah;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> n;
    int arr[n];
    cout << "Masukkan elemen-elemen array (urutkan terlebih dahulu):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> cari;

    kiri = 0;
    kanan = n - 1;
    bool found = false;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (arr[tengah] == cari) {
            cout << "Elemen ditemukan di indeks: " << tengah << endl;
            found = true;
            break;
        } else if (arr[tengah] < cari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (!found) {
        cout << "Elemen tidak ditemukan." << endl;
    }

    return 0;
}