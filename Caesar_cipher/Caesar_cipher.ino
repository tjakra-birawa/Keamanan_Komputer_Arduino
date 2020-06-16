/* VARIABEL GLOBAL */
char plaintext[]= {"himekoinaba"};                             //membuat variabel global char bernama plaintext (harap gunakan teks kecil, bila gunakan kapital sesuaikan kembali lokasi tabel ascii)
char ciphertext[sizeof(plaintext)];                            //membuat variabel global char dinamis bernama ciphertext berdasarkan ukuran variabel plaintext
int shift = 3;                                                 //membuat variabel global int bernama shift dengan nilai 3

/* METHOD BOOTING AWAL */
void setup()                                                   //inisialisasi setup
{
  Serial.begin(9600);                                          //memulai komunikasi serial pada 9600 bps
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor
  Serial.print("Enkripsi Caesar kalimat '");                   //mencetak pada serial monitor
  Serial.print(plaintext);                                     //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                   //mencetak pada serial monitor
  enkripsi();                                                  //memulai method enkripsi
}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                    //inisialisasi loop
{}

/* METHOD ENKRIPSI CAESAR CIPHER DENGAN MENAMBAHKAN OFFSET PADA TULISAN SAAT INI*/
void enkripsi()                                                //inisilasisasi enkripsi
{
    for (int x=0;x<plaintext[x];x++)                           //memulai kondisi for selama dengan awal variabel int baru bernama x selama x tersebut kurang dari besar plaintext ke-x, maka setiap iterasi akan bertambah sejumlah 1
  { 
    Serial.println("");                                        //mencetak pada serial monitor
    Serial.print("Saat ini ");                                 //mencetak pada serial monitor
    Serial.print(plaintext[x]);                                //mencetak pada serial monitor variabel plaintext ke-x
 
    ciphertext[x] += char(int(plaintext[x]+shift-97)%26 +97);  //memulai kalkulasi nilai ciphertext ke-x dengan rumus akan ditambahkan dengan nilai yang didapatkan dari bentuk variabel char(bentuk variabel int(variabel plaintext ke-x + variabel shift - 97)%26 +97)

    Serial.print(" Dirubah -> ");                              //mencetak pada serial monitor
    Serial.print(ciphertext[x]);                               //mencetak pada serial monitor variabel ciphertext ke-x
  } 
}
