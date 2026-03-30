#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int umur;
    string keluhan;
    Pasien *next;
};

Pasien *head = NULL;
Pasien *tail = NULL;

// ARRAY untuk riwayat pasien
string riwayat[100];
int jumlahRiwayat = 0;

// Tambah pasien (enqueue)
void tambahPasien(string nama, int umur, string keluhan) {
    Pasien *baru = new Pasien;
    baru->nama = nama;
    baru->umur = umur;
    baru->keluhan = keluhan;
    baru->next = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }

    cout << "Pasien berhasil ditambahkan.\n";
}

// Tampilkan antrean
void tampilkan() {
    if (head == NULL) {
        cout << "Antrean kosong.\n";
        return;
    }

    Pasien *temp = head;
    int i = 1;
    cout << "\n=== Antrean ===\n";
    while (temp != NULL) {
        cout << i++ << ". " << temp->nama 
             << " | Umur: " << temp->umur 
             << " | Keluhan: " << temp->keluhan << endl;
        temp = temp->next;
    }
}

// Layani pasien (dequeue + masuk riwayat)
void layaniPasien() {
    if (head == NULL) {
        cout << "Antrean kosong.\n";
        return;
    }

    Pasien *hapus = head;

    // simpan ke array riwayat
    if (jumlahRiwayat < 100) {
        riwayat[jumlahRiwayat++] = hapus->nama;
    }

    head = head->next;
    if (head == NULL) tail = NULL;

    delete hapus;

    cout << "Pasien telah dilayani dan masuk riwayat.\n";
}

// Tampilkan riwayat
void tampilkanRiwayat() {
    if (jumlahRiwayat == 0) {
        cout << "Belum ada riwayat pasien.\n";
        return;
    }

    cout << "\n=== RIWAYAT PASIEN ===\n";
    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << i + 1 << ". " << riwayat[i] << endl;
    }
}

// Hapus pasien berdasarkan nama
void batalkanPasien(string nama) {
    if (head == NULL) {
        cout << "Antrean kosong.\n";
        return;
    }

    Pasien *temp = head;
    Pasien *prev = NULL;

    while (temp != NULL && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Pasien tidak ditemukan.\n";
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    if (temp == tail) tail = prev;

    delete temp;
    cout << "Pasien berhasil dihapus dari antrean.\n";
}

// Ubah data pasien
void ubahData(string nama) {
    Pasien *temp = head;

    while (temp != NULL) {
        if (temp->nama == nama) {
            cout << "Masukkan umur baru: ";
            cin >> temp->umur;
            cin.ignore();
            cout << "Masukkan keluhan baru: ";
            getline(cin, temp->keluhan);

            cout << "Data berhasil diubah.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Pasien tidak ditemukan.\n";
}

// Menu
int main() {
    int pilihan;
    string nama, keluhan;
    int umur;

    do {
        cout << "\n=== SISTEM ANTREAN RUMAH SAKIT ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Tampilkan Antrean\n";
        cout << "3. Ubah Data Pasien\n";
        cout << "4. Layani Pasien\n";
        cout << "5. Batalkan Pasien\n";
        cout << "6. Tampilkan Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Nama: ";
                getline(cin, nama);
                cout << "Umur: ";
                cin >> umur;
                cin.ignore();
                cout << "Keluhan: ";
                getline(cin, keluhan);
                tambahPasien(nama, umur, keluhan);
                break;

            case 2:
                tampilkan();
                break;

            case 3:
                cout << "Masukkan nama pasien: ";
                getline(cin, nama);
                ubahData(nama);
                break;

            case 4:
                layaniPasien();
                break;

            case 5:
                cout << "Masukkan nama pasien: ";
                getline(cin, nama);
                batalkanPasien(nama);
                break;

            case 6:
                tampilkanRiwayat();
                break;
        }

    } while (pilihan != 0);

    return 0;
}