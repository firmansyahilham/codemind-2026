#include <iostream>
#include <vector> // untuk menggunakan vector untuk menyimpan nama peserta
#include <algorithm> // untuk menggunakan fungsi shuffle untuk mengacak nama peserta
#include <random> // untuk menggunakan random_device dan mt19937 untuk menghasilkan angka acak yang digunakan dalam fungsi shuffle
#include <iomanip> // untuk menggunakan setw untuk mengatur lebar tampilan nomor anggota dalam kelompok
using namespace std; // untuk menghindari penulisan std:: sebelum setiap penggunaan elemen dari namespace std

// Fungsi untuk menampilkan garis pemisah
void garis() {
    cout << "====================================================\n";
}

// Fungsi utama program
int main() {
    vector<string> namaPeserta;
    string nama;
    int jumlahPeserta, anggotaPerKelompok;

    garis();
    cout << "        PROGRAM RANDOM KELOMPOK CODE CLASH\n";
    garis();

    cout << "Masukkan jumlah peserta: ";
    cin >> jumlahPeserta;
    cin.ignore();

    if (jumlahPeserta <= 0) {
        cout << "Jumlah peserta tidak valid.\n";
        return 0;
    }

    cout << "\nMasukkan nama peserta:\n";
    for (int i = 0; i < jumlahPeserta; i++) {
        cout << "Peserta ke-" << i + 1 << ": ";
        getline(cin, nama);

        while (nama.empty()) {
            cout << "Nama tidak boleh kosong. Masukkan ulang: ";
            getline(cin, nama);
        }

        namaPeserta.push_back(nama);
    }

    cout << "\nMasukkan jumlah anggota per kelompok (contoh 3, 4, atau 5): ";
    cin >> anggotaPerKelompok;

    if (anggotaPerKelompok <= 0) {
        cout << "Jumlah anggota per kelompok tidak valid.\n";
        return 0;
    }

    random_device rd; // untuk mendapatkan seed acak dari hardware
    mt19937 g(rd()); // untuk menghasilkan angka acak menggunakan Mersenne Twister engine dengan seed dari random_device
    shuffle(namaPeserta.begin(), namaPeserta.end(), g); // untuk mengacak elemen dalam vector namaPeserta menggunakan fungsi shuffle dengan generator acak g

    int jumlahKelompok = (jumlahPeserta + anggotaPerKelompok - 1) / anggotaPerKelompok;

    cout << "\n\n";
    garis();
    cout << "          HASIL RANDOM KELOMPOK CODE CLASH\n";
    garis();

    int index = 0;

    for (int k = 1; k <= jumlahKelompok; k++) {
        cout << "\nKelompok " << k << "\n";
        cout << "----------------------------------------------------\n";

        for (int j = 1; j <= anggotaPerKelompok && index < jumlahPeserta; j++) {
            cout << setw(2) << j << ". " << namaPeserta[index] << "\n";
            index++;
        }
    }

    cout << "\n";
    garis();
    cout << "Total Peserta      : " << jumlahPeserta << "\n";
    cout << "Anggota/Kelompok   : " << anggotaPerKelompok << "\n";
    cout << "Jumlah Kelompok    : " << jumlahKelompok << "\n";
    garis();

    cout << "\nRandom kelompok selesai. Semangat yaa mengikuti Code Clash!\n" << endl;

    return 0;
}