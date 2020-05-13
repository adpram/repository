#include <iostream>
#include <string>

#include "crc32.h"

using namespace std;

string numerals = "0123456789";
string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string specialAnsi = "!\"#¤%&/()=?`^¨*';:_,.";


// fungsi utama
void CrackHash(string source, unsigned int hash, string seed, size_t length){
	
	static const int startTick = GetTickCount();
	
	static int iterations; // menahan hitungan iterasi 
	static int collissions; // menahan hitungan hash
	
	iterations++; // penambahan pada setiap eksekusi
	
	if (length == 0){
		// jika hash cocok dengan seed
		if (CRC32(seed.c_str(), seed.length()) == hash){
			// hitung waktu yang dipakai
			double endTick = GetTickCount() - startTick;
			collissions++;
			
			string inputSeed;
			// hasil
			
			cout << "CRC-32" <<endl<<endl;
			cout << "Input : ";
			cin >> inputSeed;
			cout << "Output : 0x" << StrCRC32(inputSeed) << endl;

		}
		
		return;
	}
	
	// penambahan melalui input
	for (size_t i = 0; i < source.length(); i++){
		string appended = seed + source[i];

		// loop
		CrackHash(source, hash, appended, length - 1);
	}
}

int main(){
	
	// target hash yang akan di crack
	unsigned int targetHash = 0xd87f7e0c;
	
	// lakukan perulangan fungsi CrackHash
	while (1){
		// panjang start
		static unsigned int strlen = 1;
		CrackHash(alphabetLower + alphabetUpper + numerals + specialAnsi, targetHash, "", strlen);
		strlen++; // menambah panjang setiap setelah proses iterasi (penambahan)
	}
}

// Adi Pramono
// 1814321017

// terima kasih Zer0Mem0ry untuk inspirasi nya
// link github : https://github.com/Zer0Mem0ry
