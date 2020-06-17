/* VARIABEL GLOBAL */
char plaintext[]= {"HIMEKOINABA"};                             //membuat variabel global char bernama plaintext = HIMEKOINABA (Saat ini tidak bisa diubah menjadi huruf kecil karena akan merubah keseluruhan tabel inti)
char key[] = {"DEREBAN"};                                      //membuat variabel global char bernama key = DEREBAN (Saat ini tidak bisa diubah menjadi huruf kecil karena akan merubah keseluruhan tabel inti)
char ciphertext[]={"KMDILOVQESE"};                             //membuat variabel global char bernama ciphertext = KMDILOVQESE (Saat ini tidak bisa diubah menjadi huruf kecil karena akan merubah keseluruhan tabel inti)
char CT[sizeof(plaintext)];                                    //membuat variabel global char dinamis bernama CT berdasarkan ukuran variabel plaintext
char PT[sizeof(ciphertext)];                                   //membuat variabel global char dinamis bernama PT berdasarkan ukuran variabel ciphertext
char kbaru[sizeof(plaintext)];                                 //membuat variabel global char dinamis bernama kbaru berdasarkan ukuran variabel plaintext
int x, y;                                                      //membuat variabel global int bernama x dan y
int kpanjang = sizeof(key)- 1;                                 //membuat variabel global int dinamis bernama kpanjang sebesar variabel key - 1 (offset)

/* METHOD BOOTING AWAL */
void setup()                                                   //inisialisasi setup
{
  Serial.begin(9600);                                          //memulai komunikasi serial pada 9600 bps
  
  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor
  Serial.print("Enkripsi Vigenere kalimat '");                 //mencetak pada serial monitor
  Serial.print(plaintext);                                     //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                   //mencetak pada serial monitor
  Serial.println("");                                          //mencetak pada serial monitor 
  Serial.println("");                                          //mencetak pada serial monitor
  Serial.print("Diketahui Key saat ini : ");                   //mencetak pada serial monitor
  Serial.print(key);                                           //mencetak pada serial monitor variabel key
  Serial.println("");                                          //mencetak pada serial monitor  

  /*PROSES UNTUK PELENGKAPAN ISI DARI ARRAY KEY AGAR SESUAI DENGAN BESAR ARRAY PLAINTEXT*/
  for(x=0,y=0; x < plaintext[x]; x++,y++)                      //memulai kondisi for dengan awal variabel x dan y sebesar 0, serta melalkukan perulangan selama kurang dari ppanjang, yang nantinya akan di increment masing-masing
  {
    /*DIPERLUKAN AGAR NGULANG KEY DARI AWAL SELAMA MASIH ADA SLOT*/
    if(y == (kpanjang))                                        //jika nilai y sama dengan kpanjang maka
    {y=0;}                                                     //menyatakan nilai y = 0
    kbaru[x]= key[y];                                          //menyatakan nilai kbaru ke-x - nilai key ke-y
  }
  
  Serial.print("Penyesuaian Key baru : ");                     //mencetak pada serial monitor
  Serial.print(kbaru);                                         //mencetak pada serial monitor variabel kbaru
  Serial.println("");                                          //mencetak pada serial monitor  

  /*PROSES ENKRIPSI VIGENERE*/
  for(x = 0; x < plaintext[x]; x++)                            //memulai kondisi for dengan nilai variabel x = 0 selama x kurang dari variabel plaintext ke-x dan menambahkan x setiap iterasi berikutnya
  {
    Serial.println("");                                        //mencetak pada serial monitor
    Serial.print("Saat ini ");                                 //mencetak pada serial monitor
    Serial.print(plaintext[x]);                                //mencetak pada serial monitor variabel plaintext ke-x
    Serial.print(" bertemu dengan ");                          //mencetak pada serial monitor
    Serial.print(kbaru[x]);                                    //mencetak pada serial monitor variabel kbaru ke-x

    /*PROSES UTAMA DIMANA NILAI CT AKAN DIDAPATKAN DARI KALKULASI ANTARA PLAINTEXT DAN KBARU, KONDISI SAAT INI TIDAK DAPAT MERUBAH MENJADI HURUF NON-KAPITAL*/
    CT[x] = ((plaintext[x] + kbaru[x]) % 26) + 'A';            //menyatakan nilai variabel CT ke-x = ((nilai variabel plaintext ke-x + nilai variabel kbaru ke-x) % 26) + 'A' (bila pake huruf kecil ubah A -> a)

    Serial.print(" Dirubah -> ");                              //mencetak pada serial monitor
    Serial.print(CT[x]);                                       //mencetak pada serial monitor variabel CT ke-x
  }
  
  Serial.println("");                                          //mencetak pada serial monitor
  Serial.println("");                                          //mencetak pada serial monitor
  Serial.print("Dekripsi Vigenere kalimat '");                 //mencetak pada serial monitor
  Serial.print(ciphertext);                                    //mencetak pada serial monitor variabel ciphertext
  Serial.print("' akan menjadi berikut : ");                   //mencetak pada serial monitor
  Serial.println("");                                          //mencetak pada serial monitor 
  
  /*PROSES DEKRIPSI VIGENERE*/
  for(x = 0; x < plaintext[x]; x++)                            //memulai kondisi for dengan nilai variabel x = 0 selama x kurang dari variabel plaintext ke-x dan menambahkan x setiap iterasi berikutnya
  {
    Serial.println("");                                        //mencetak pada serial monitor
    Serial.print("Saat ini ");                                 //mencetak pada serial monitor
    Serial.print(ciphertext[x]);                               //mencetak pada serial monitor variabel ciphertext ke-x
    Serial.print(" bertemu dengan ");                          //mencetak pada serial monitor
    Serial.print(kbaru[x]);                                    //mencetak pada serial monitor variabel kbaru ke-x

    /*PROSES UTAMA DIMANA NILAI CT AKAN DIDAPATKAN DARI KALKULASI ANTARA PLAINTEXT DAN KBARU, KONDISI SAAT INI TIDAK DAPAT MERUBAH MENJADI HURUF NON-KAPITAL*/
    PT[x] = (((ciphertext[x] - kbaru[x]) + 26) % 26) + 'A';    //menyatakan nilai variabel PT ke-x = (((nilai variabel ciphertext ke-x - nilai variabel kbaru ke-x)+26) % 26) + 'A' (bila pake huruf kecil ubah A -> a)

    Serial.print(" Dirubah -> ");                              //mencetak pada serial monitor
    Serial.print(PT[x]);                                       //mencetak pada serial monitor variabel PT ke-x
  }
}                                                          

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                    //inisialisasi loop
{}
