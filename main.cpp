#include <iostream>
#include <string>
using namespace std;
struct data_pasien
{ 
  int id_pasien;
  string nama_pasien;
  string keluhan;
};
struct node{
    data_pasien data;
    node*next;
};
void enqueue(node*& head, data_pasien data)
{
  node*baru = new node;
  baru ->data = data;
  baru ->next = NULL;
  if (head==NULL)
  {
    head = baru;
  }
  else
  {
    node*temp = head;
    while (temp->next != NULL)
    {
      temp =temp->next;

    }
    temp->next = baru;
  }
  
}
void display(node*head)
{
  if (head== NULL)
  {
    cout<<"antrian kosong"<<endl;
  }
  node*temp = head;
  int no = 1;
  while (temp!= NULL)
  {
    cout<<"pasien ke-  "<<no<<endl;
    cout << "nama pasien:"<<temp->data.nama_pasien<<endl;
    cout << "id peserta:"<<temp->data.id_pasien<<endl;
    cout << "keluhan:"<<temp->data.keluhan<<endl;
    temp = temp->next;
    no++;
  }
  
}
int main(){
  data_pasien home;
  node* head = NULL;
   while (true)
   {
    int pilihan;
    cout<<"----------sistem antrian rumah sakit----------"<<endl;
    cout<<"1.Tambah pasien"<<endl;
    cout<<"2.Lihat daftar antrian"<<endl;
    cout<<"3.Cari Data Pasien"<<endl;
    cout<<"4.Riwayat Pelayanan"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<< "masukkan nomor (1-5): "<<endl;
    cin >>pilihan;
    cin.ignore();
    switch (pilihan)
    {
    case 1:
    cout << "[Menu Tambah Pasien]\n";
    cout<<"masukkan nama:"<<endl;
    getline(cin, home.nama_pasien);
    cout<<"masukkan id:"<<endl;
    cin>>home.id_pasien;
    cin.ignore();
    cout<<"masukkan keluhan:";
    getline(cin, home.keluhan);
    cout << "\n ✅ Data berhasil dimasukkan!\n";
    cout << "Nama    : " << home.nama_pasien << endl;
    cout << "ID      : " << home.id_pasien << endl;
    cout << "Keluhan : " << home.keluhan << endl;
    enqueue(head,home);
    break;
    

    case 2:
    cout << "[Menu Lihat Antrian]\n";
    display(head); 
    break;

    case 3:
    cout << "[Menu Cari Pasien]\n";
    break;

    case 4:
    cout << "[Menu Riwayat Pelayanan]\n";
    break;

    case 0:
    cout << "Keluar program...\n";
    return 0;

    default:
    cout << "[!] Pilihan tidak valid!\n";

    }
    
    
   }

   

}