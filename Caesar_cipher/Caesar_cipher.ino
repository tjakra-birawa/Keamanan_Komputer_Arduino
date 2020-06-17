/* VARIABEL GLOBAL */
char plaintext[]= {"HIMEKOINABA"};                                                           //membuat variabel global char bernama plaintext (harap gunakan teks kecil, bila gunakan kapital sesuaikan kembali lokasi tabel ascii atau ubah saja jadi 'A' atau 'a')
char CT[sizeof(plaintext)];                                                                 //membuat variabel global char dinamis bernama CT berdasarkan ukuran variabel plaintext
char ciphertext[]= {"KLPHNRLQDED"};                                                         //membuat variabel global char bernama ciphertext (harap gunakan teks kecil, bila gunakan kapital sesuaikan kembali lokasi tabel ascii atau ubah saja jadi 'A' atau 'a')
char PT[sizeof(ciphertext)];                                                                //membuat variabel global char dinamis bernama PT berdasarkan ukuran variabel ciphertext
int pergeseran = 3;                                                                         //membuat variabel global int bernama pergeseran dengan nilai 3

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  
  /*EKSEKUSI ENKRIPSI*/
  Serial.print("Enkripsi Caesar kalimat '");                                                //mencetak pada serial monitor
  Serial.print(plaintext);                                                                  //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                                                //mencetak pada serial monitor
  enkripsi();                                                                               //inisialisasi enkripsi
  
  /*EKSEKUSI DEKRIPSI*/
  Serial.println("");                                                                       //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor
  Serial.print("Dekripsi Caesar kalimat '");                                                //mencetak pada serial monitor
  Serial.print(ciphertext);                                                                 //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                                                //mencetak pada serial monitor
  dekripsi();                                                                               //inisialisasi dekripsi
}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                 //inisialisasi loop
{}

/* METHOD ENKRIPSI */
void enkripsi()                                                                             //inisialisasi enkripsi
{
  /*PROSES UNTUK PERUBAHAN ENKRIPSI CAESAR*/
  for (int x=0;x<plaintext[x];x++)                                                          //memulai kondisi for untuk nilai variabel int x saat 0 dan masih kurang dari nilai variabel plaintext ke-x maka ketika selesai iterasi akan ditambahkan nilai x++
  { 
    Serial.println("");                                                                     //mencetak pada serial monitor
    Serial.print("Saat ini ");                                                              //mencetak pada serial monitor
    Serial.print(plaintext[x]);                                                             //mencetak pada serial monitor variabel plaintext ke-x

    /*INTI PERUBAHAN NGAMBIL DARI NILAI INT HASIL PENJUMLAHAN DARI POSISI A/a PADA TABEL ASCII YANG ADA TERUS DI GESER SEJUMLAH pergeseran DAN NANTINYA DI KONVERSI JADI CHAR BALIK*/
    CT[x] += char(int(plaintext[x] + pergeseran - 'A') %26 + 'A');                          //memulai kalkulasi nilai CT ke-x dengan rumus akan ditambahkan dengan nilai yang didapatkan dari bentuk variabel char(bentuk variabel int(variabel plaintext ke-x + variabel pergeseran - A)%26 +A)

    Serial.print(" Dirubah -> ");                                                           //mencetak pada serial monitor
    Serial.print(CT[x]);                                                                    //mencetak pada serial monitor variabel CT ke-x
  } 
}

/* METHOD DEKRIPSI */
void dekripsi()                                                                             //inisialisasi dekripsi
{
  /*PROSES UNTUK PERUBAHAN DEKRIPSI CAESAR*/
  for (int x=0;x<ciphertext[x];x++)                                                         //memulai kondisi for untuk nilai variabel int x saat 0 dan masih kurang dari nilai variabel plaintext ke-x maka ketika selesai iterasi akan ditambahkan nilai x++
  { 
    Serial.println("");                                                                     //mencetak pada serial monitor
    Serial.print("Saat ini ");                                                              //mencetak pada serial monitor
    Serial.print(ciphertext[x]);                                                            //mencetak pada serial monitor variabel plaintext ke-x

    /*INTI PERUBAHAN NGAMBIL DARI NILAI INT HASIL PENJUMLAHAN DARI POSISI A/a PADA TABEL ASCII YANG ADA TERUS DI GESER SEJUMLAH pergeseran DAN NANTINYA DI KONVERSI JADI CHAR BALIK*/
    PT[x] += char(int(ciphertext[x] - pergeseran - 'A') %26 + 'A');                         //memulai kalkulasi nilai PT ke-x dengan rumus akan ditambahkan dengan nilai yang didapatkan dari bentuk variabel char(bentuk variabel int(variabel ciphertext ke-x - variabel pergeseran - A)%26 +A)

    Serial.print(" Dirubah -> ");                                                           //mencetak pada serial monitor
    Serial.print(PT[x]);                                                                    //mencetak pada serial monitor variabel PT ke-x
  } 
}
