// library program
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// struck data menu
struct Menu {
    string nama;
    int harga;
};

// deklarasi struck menu
Menu daftar_menu[10]={{"kopi", 7000},{"teh", 4000}};
int total_menu = 2;

// menampilkan seluruh data
void tampil(){
	system("cls");
	for (int i=0; i < total_menu; i++){
		cout << "\nNama"  << ": "<< daftar_menu[i].nama;
		cout << "\nHarga" << ": "<< daftar_menu[i].harga <<endl;				 
	}
	getch();
}

// sort atribut nama menggunakan bubblesort
void bubble(Menu daftar_menu[], int total_menu){
	int i,j,pilih;
	Menu swap;
	cout << "1. Ascending" << endl
		 << "2. Descending" << endl
		 << "masukkan nomor pilihan : "; cin >> pilih;
		switch(pilih){
		case 1: 
			for (i = 0; i < total_menu - 1; i++){
				for(j = 0; j < total_menu - 1; j++){
					if(daftar_menu[j].nama > daftar_menu[j+1].nama){
						swap = daftar_menu[j];
						daftar_menu[j] = daftar_menu[j+1];
						daftar_menu[j+1] = swap;
					}
				}	
			}
			tampil();
			break;	
		case 2:
			for(i = 0; i < total_menu - 1; i++){
				for(j = 0; j < total_menu - 1; j++){
					if(daftar_menu[j].nama < daftar_menu[j+1].nama){
						swap = daftar_menu[j];
						daftar_menu[j] = daftar_menu[j+1];
						daftar_menu[j+1] = swap;
					}
				}	
			}
			tampil();
			break;
		break;
		}
}

// menukar data menggunakan pointer
// xp = pointer x || yp = pointer y
void swap(Menu *xp, Menu *yp){ 
	Menu temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// sort atribut nama menggunakan selection sort
void selection(Menu daftar_menu[], int total_menu){
	int i, j, min_idx;
	int pilih;
	cout << "1. Ascending" << endl
		 << "2. Descending" << endl
		 << "Pengurutan berdasarkan : "; cin >> pilih;
	for (i = 0; i < total_menu-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < total_menu; j++)
		{
			switch (pilih){
				case 1:
					if (daftar_menu[j].nama < daftar_menu[min_idx].nama)
					{
						min_idx = j;	
					}
					tampil();
					break;
				case 2:
					if (daftar_menu[j].nama > daftar_menu[min_idx].nama)
					{
						min_idx = j;	
					}
					tampil();
					break;
			}
		}
		swap(&daftar_menu[i], &daftar_menu[min_idx]);
	}
}

// fungsi sort harga menggunakan quicksort
int partisi_ascend (Menu daftar_menu[], int low, int high){
	int pivot = daftar_menu[high].harga;
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++){
		if (daftar_menu[j].harga <= pivot){
			i++;
			swap(&daftar_menu[i], &daftar_menu[j]);
		}
	}
	swap(&daftar_menu[i + 1], &daftar_menu[high]);
	return (i + 1);
}

int partisi_descend (Menu daftar_menu[], int low, int high){
	int pivot = daftar_menu[high].harga;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++){
		if (daftar_menu[j].harga >= pivot){
			i++;
			swap(&daftar_menu[i], &daftar_menu[j]);
		}
	}
	swap(&daftar_menu[i + 1], &daftar_menu[high]);
	return (i + 1);
}

void quicksort_ascend(Menu daftar_menu[], int low, int high){
	if (low < high){
		int pi = partisi_ascend(daftar_menu, low, high);
		quicksort_ascend(daftar_menu, low, pi - 1);
		quicksort_ascend(daftar_menu, pi + 1, high);
	}
}

void quicksort_descend(Menu daftar_menu[], int low, int high){
	if (low < high){
		int pi = partisi_descend(daftar_menu, low, high);
		quicksort_descend(daftar_menu, low, pi - 1);
		quicksort_descend(daftar_menu, pi + 1, high);
	}
}

// fungsi search nama menu
int binary_search(int pilih){
	system("cls");
    string num;
	int beg = 0;
	int end = total_menu-1;
	int index = -1;
	cout<<"Nama yang dicari: ";
	cin>>num;
	switch (pilih){
		case 1:
			for (int i = 0; i < total_menu - 1; i++){
				for(int j = 0; j < total_menu - 1; j++){
					if(daftar_menu[j].nama > daftar_menu[j+1].nama){
						Menu swap = daftar_menu[j];
						daftar_menu[j] = daftar_menu[j+1];
						daftar_menu[j+1] = swap;
					}
				}	
			}
			while(beg <= end){
				int mid = (end + beg)/2;
				if(daftar_menu[mid].nama == num){
					index = mid +1;
					for (int i = 0; i < total_menu; i++){
						if(daftar_menu[mid].nama == daftar_menu[i].nama){
							cout << "Nama : "<< daftar_menu[i].nama << endl;
							cout << "Harga : "<< daftar_menu[i].harga << endl;
							cout << "\n";
						}
						getch();
					}
					break;
				}
				else{
					if(num > daftar_menu[mid].nama){
						beg = mid+1;
					}
					else{
						end =mid-1;
					}
				}
			}
			break;
	}
	if (index == -1){
		cout << "\nData tidak ditemukan"; getch();
	}
	return 0;
}

// fungsi search harga menu
void inter_search(int pilih)
{
	quicksort_ascend(daftar_menu,0,total_menu-1);
    // inisiasi nilai variabel indeks
    int i_awal = 0, i_posisi;
    int proses = 0;
    int i_akhir = total_menu - 1;
    
    int key;
    cout << "Masukkan harga yang ingin dicari : ";
    cin >> key;
	switch (pilih){
		case 2:
			while (true)
			{
				proses++;
				i_posisi = (i_awal + ((key - daftar_menu[i_awal].harga) * (i_akhir - i_awal)) / (daftar_menu[i_akhir].harga + daftar_menu[i_awal].harga));
			
				if (daftar_menu[i_posisi].harga == key)
				{
					for (int i = 0; i < total_menu; i++){
						if (daftar_menu[i_posisi].harga == daftar_menu[i].harga){
							cout<<"Nama : "<<daftar_menu[i_posisi].nama<<endl;
							cout<<"Jumlah harga : Rp. "<<daftar_menu[i_posisi].harga<<endl;
							cout<<"\n";
						}
						getch();
					}
					break;
				}
				else if ((daftar_menu[i_posisi].harga < key) && (daftar_menu[i_posisi].harga >= daftar_menu[i_posisi].harga))
				{
					i_awal = i_posisi + 1;
					continue;
				}
				else if ((daftar_menu[i_posisi].harga > key) && (daftar_menu[i_posisi].harga <= daftar_menu[i_posisi].harga))
				{
					i_akhir = i_posisi - 1;
					continue;
				}
				else
				{
					cout << "Nilai yang anda cari tidak ada" << endl;
					break;
				}
			}
			break;
	}
}

// fungsi search
void cari(){
    system("cls");
	int pilih;
		cout<<"1. Nama\n"
			<<"2. Harga\n"
			<<"\n"
			<<"Masukkan pilihan: ";
		cin>>pilih;
	switch (pilih)
	{
	case 1:
		binary_search(1);
		break;
	case 2:
		inter_search(2);
		break;
	default:
		cout << "Inputan salah"; getch();
	}
}

// fungsi melihat isi data 
void lihat(){
	system("cls");
	int pilihan;
	int urutan;

	cout << "1. Bubble sort (sort nama)"<<endl;
    cout << "2. Selection sort (sort nama)"<<endl;
	cout << "3. Quick sort (sort harga)"<<endl;
	cout << "tampilkan dengan sorting apa ? "; cin>>pilihan;

	if(pilihan == 1){
		bubble(daftar_menu, total_menu);
		tampil(); 
	}
	else if(pilihan == 2){
		selection(daftar_menu, total_menu);
		tampil();
	}
	else if(pilihan == 3){
		cout <<endl
			 << "1. Ascending" << endl
			 << "2. Descending" << endl
			 << "Pengurutan berdasarkan: "; cin >> urutan;
				switch (urutan){
					case 1:
						quicksort_ascend(daftar_menu, 0, total_menu-1 );
						tampil(); 
						break; getch();
					case 2:
						quicksort_descend(daftar_menu, 0, total_menu-1 );
                       	tampil(); 
						break; getch();
				}
	}
	else{
	cout << "pilihan tidak tersedia!"<<endl; getch();
	} 
         
}

// fungsi menambahkan input user ke indeks array
void tambah(){
    Menu menu_baru;
    cout << "\nNama menu  : "; fflush(stdin); getline(cin, menu_baru.nama);
    cout << "Harga menu   : "; cin >> menu_baru.harga;
    cout <<endl;
    daftar_menu[total_menu] = menu_baru;
    total_menu++;

    cout << "\t Berhasil menambahkan menu!"; getch();
}

// fungsi mengubah isi data
void ubah(){
    int index;
	tampil();
    cout << "\n Masukkan nomor data (1 - " << total_menu << ") : "; cin >> index;

    if(index != 0 && index <= total_menu) {
        index = index - 1;
        Menu menu_diubah = daftar_menu[index];
        cout << "Nama menu baru  : "; fflush(stdin); getline(cin, menu_diubah.nama);
        cout <<endl;
        cout << "Harga menu baru : "; cin >> menu_diubah.harga;
        cout <<endl;
        daftar_menu[index] = menu_diubah;
		cout <<endl;
        cout << "\t Berhasil mengubah menu!"; getch();
    }
}

// fungsi menghapus data pada array
void hapus(){
    int index;
    tampil();
    cout << "\n Masukkan nomor data (1 - " << total_menu << ") : "; cin >> index;

    if(index != 0 && index <= total_menu) {
        for (int i = index - 1; i < total_menu; ++i) {
            daftar_menu[i] = daftar_menu[i + 1];
        }
    }
    cout << "Data berhasil dihapus!"; getch();
}

// menampilkan main menu
void tampil_pilihan() {
    cout << "\t====== Daftar Pilihan ======\t" << endl
         << "1. Tampilkan Menu" << endl
         << "2. Tambah Menu" << endl
         << "3. Ubah Menu"   << endl
         << "4. Cari Menu"   << endl
         << "5. Hapus Menu"  << endl
         << "6. Keluar"      << endl
         << "\n Masukkan pilihan : ";
}

// fungsi utama
int main() {
    system("cls");
    cout <<  "--------------Program Data Menu--------------" << endl;
    int pilihan;
	tampil_pilihan();
    cin >> pilihan;

    switch(pilihan) {   
        case 1:
            lihat();
			main();
			break;        
        case 2:
            tambah();
			main();
			break;             
        case 3:
            ubah();
			main();
			break;               
        case 4:
            cari();
			main();
			break;       
        case 5:
            hapus();
			main();
			break;               
        case 6:
            system("cls");
			cout << " Program selesai "; getch();
            break;               
        default:
			main();        
    }
    return 0;
}
