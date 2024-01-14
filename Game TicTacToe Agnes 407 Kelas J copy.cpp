#include <iostream>
using namespace std;

char ruang[3][3] = {{'1', '2', '3'}, {'4', '5', '6'},{'7','8','9'}};
int baris,kolom;
char token = 'X';
bool tie = false;
string n1 = " ";
string n2 = " ";  

void fungsiPertama(){

system("cls");
  cout << "|===================================|" << endl;
  cout << "|       Selamat Datang di Game      |" << endl;
  cout << "|            Tic Tac Toe            |" << endl;
  cout << "|-----------------------------------|" << endl;
  cout << "|   Pemain 1 (X)  -  Pemain 2 (O)   |" << endl;
  cout << "|===================================|" << endl;
  cout << "|                                   |" << endl;
  cout << "|        |-----------------|        |" << endl;
  cout << "|        |     |     |     |        |" << endl;
  cout << "|        |  " << ruang[0][0] << "  |  " << ruang[0][1] << "  |  " << ruang[0][2] << "  |" << "        |" << endl;
  cout << "|        |_____|_____|_____|        |" << endl;
  cout << "|        |     |     |     |        |" << endl;
	cout << "|        |  " << ruang[1][0] << "  |  " << ruang[1][1] << "  |  " << ruang[1][2] << "  |" << "        |" << endl;
  cout << "|        |_____|_____|_____|        |" << endl;
  cout << "|        |     |     |     |        |" << endl;
	cout << "|        |  " << ruang[2][0] << "  |  " << ruang[2][1] << "  |  " << ruang[2][2] << "  |" << "        |" << endl;
	cout << "|        |     |     |     |        |" << endl;
  cout << "|        |-----------------|        |" << endl;
  cout << "|                                   |" << endl;
  cout << "|===================================|" << endl;
}

void fungsiKedua(){
  int angka;
  if(token == 'X'){
    cout << n1 << " memilih kolom : ";
    cin >> angka;
  }
  if(token == '0'){
    cout << n2 << " memilih kolom : ";
    cin >> angka;
  }
  if(angka == 1){
    baris = 0;
    kolom = 0;
  }
  if(angka == 2){
    baris = 0;
    kolom = 1;
  }
  if(angka == 3){
    baris = 0;
    kolom = 2;
  }
  if(angka == 4){
    baris = 1;
    kolom = 0;
  }
  if(angka == 5){
    baris = 1;
    kolom = 1;
  }
  if(angka == 6){
    baris = 1;
    kolom = 2;
  }
  if(angka == 7){
    baris = 2;
    kolom = 0;
  }
  if(angka == 8){
    baris = 2;
    kolom = 1;
  }
  if(angka == 9){
    baris = 2;
    kolom = 2;
  }
  else if(angka < 1 || angka > 9){
    cout << "TIDAK SAH !!!" << endl;
  }
  if(token == 'X' && ruang[baris][kolom] !='X' && ruang[baris][kolom] !='0'){
    ruang[baris][kolom] = 'X';
    token = '0';
  }
  else if(token == '0' && ruang[baris][kolom] !='X' && ruang[baris][kolom] !='0'){
    ruang[baris][kolom] = '0';
    token = 'X';
  }
  else{
    cout << "Tidak ada ruang kosong!" << endl;
    fungsiKedua();
  }
fungsiPertama();
}
bool fungsiKetiga(){

    for(int i = 0; i < 3; i++){
      if(ruang[i][0] == ruang[i][1] && ruang[i][0] == ruang[i][2] || ruang[0][i] == ruang[1][i] && ruang[0][i] == ruang[2][i])
        return true;
    }
    if( ruang[0][0] ==  ruang[1][1] && ruang[1][1] == ruang[2][2] || ruang[0][2] == ruang[1][1] && ruang[1][1] == ruang[2][0]){
      return true;
    }
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(ruang[i][j] != 'X' &&  ruang[i][j] != '0'){
          return false;
            }
        }
    }
    tie = true;
    return false;
}

int main(){
  
  cout << "Masukkan nama pemain 1 : \n";
  getline(cin, n1);
  cout << "Masukkan nama pemain 2 : \n";
  getline(cin, n2);
  cout << n1 << "  adalah pemain 1 jadi dia akan bermain terlebih dahulu.\n";
  cout << n2 << "  adalah pemain 2 jadi dia akan bermain terlebih dahulu.\n";
  
  while(!fungsiKetiga()){
    fungsiPertama();
    fungsiKedua();
    fungsiKetiga();
  }
  if(token == 'X' && tie == false){
    cout << "SELAMAT " << n2 << " MENANG YEAYYY!" << endl;
  }
  else if(token == '0' && tie == false){
    cout << "SELAMAT " << n1 << " MENANG YEAYYY!" << endl;
  }
  else{
    cout << "HASIL NYA IMBANG!" << endl;
  }
}