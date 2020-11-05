#include <iostream>
#include <string>

using namespace std;
int n;
string kata;

bool awal(string cariKata,int panjangKata);
bool akhir(string cariKata,int panjangKata, int lok);
bool tengah(string cariKata,int panjangKata, int lok);

int main(){
	string input;
	int panjang,lokasi;
	//input
	cin >> input;
	cin >> n;

	panjang = input.length()-1;
	lokasi = input.find("*");

	if(lokasi == panjang){
		//akhir
		for (int i = 0; i < n; i++)
		{
			cin >> kata;
			if(akhir(input, panjang, lokasi)){
				cout << kata << endl;
			}
		}
	}else if(lokasi == 0){
		//awal
		for (int i = 0; i < n; i++)
		{
			cin >> kata;
			if(awal(input, panjang)){
				cout << kata << endl;
			}
		}
		
	}else{
		//tengah
		for (int i = 0; i < n; i++)
		{
			cin >> kata;
			if(tengah(input, panjang, lokasi)){
				cout << kata << endl;
			}
		}
	}

	return 0;
}

bool awal(string cariKata,int panjangKata){
	//kondisi jika kata lebih pendek dari patern
	if(kata.length()< panjangKata){
		return false;
	}
	cariKata = cariKata.erase(0,1);
	if (kata.substr(kata.length()- panjangKata,  panjangKata) == cariKata){
		return true;
	}else{
		return false;
	}
}

bool akhir(string cariKata,int panjangKata, int lok){
	cariKata = cariKata.erase( lok,1);
	if (kata.substr(0,cariKata.length()) == cariKata){
		return true;
	}else{
		return false;
	}
}

bool tengah(string cariKata,int panjangKata, int lok){
	//kondisi jika kata lebih pendek dari patern
	if(kata.length()< panjangKata){
		return false;
	}
	string a1 = kata.substr(kata.length()-(cariKata.length()- lok-1),cariKata.length()- lok-1);
	string a2 = cariKata.substr( lok+1,cariKata.length()- lok-1);
	bool a = (a1 == a2);
	if(kata.substr(0, lok) == cariKata.substr(0, lok) && a){
		return true;
	}
	return false;
}