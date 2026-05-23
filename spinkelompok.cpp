#include <iostream>
#include <vector> //untk menggunakan vector untuk menyimpan nama peserta
#include <algorithm> //untuk menggunakan fungsi shuffle untuk mengacak nama peserta
#include <random> // untuk menggunakan random_device dan mt19937 untuk menghasilkan angka acak yang digunakan dalam fungsi shuffle
#include <ctime> // untuk menggunakan time untuk seed random

using namespace std;

int main() {
    vector<string> nama;
    string input;
    int jumlah;

    cout << "\n====== PROGAM PENGLOMPOKAN PESERTA ======\n";
    cout << "Masukkan jumlah peserta: ";
    cin >> jumlah;
    cin.ignore(); // untuk membersihkan buffer setelah membaca jumlah peserta

    // Input nama peserta
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama peserta ke-" << i + 1 << ": ";
        getline(cin, input); // untuk membaca nama peserta yang mungkin mengandung spasi, menggunakan getline untuk membaca seluruh baris input
        nama.push_back(input); // untuk menambahkan nama peserta ke dalam vector nama menggunakan fungsi push_back
    }

    // Acak nama
    random_device rd; // untuk mendapatkan seed acak dari hardware
    mt19937 g(rd()); // untuk menghasilkan angka acak menggunakan Mersenne Twister engine dengan seed dari random_device

    shuffle(nama.begin(), nama.end(), g); // untuk mengacak elemen dalam vector nama menggunakan fungsi shuffle dengan generator acak g

    // Bagi kelompok isi 4 orang
    int nomorKelompok = 1;
    for (int i = 0; i < nama.size(); i++) {

        if (i % 4 == 0) {
            cout << "\nKelompok " << nomorKelompok++ << endl;
            cout << "--------------------------------------\n";
        }
        cout << "- " << nama[i] << endl;
    }

    return 0;
}