/* VARIABEL GLOBAL */
int ascii[130], baris, kolom;                                 //membuat variabel global int bernama ascii, baris, dan kolom
char plaintext[]= {"HIMEKOINABA"};                            //membuat variabel global char bernama plaintext (hanya bisa huruf biasa, bila kapital sesuaikan kembali kodingan bawahnya, gantilah "a" menjadi "A" bila ingin merubah)
char ciphertext[]= {"2324321525342433111211"};                //membuat variabel global char bernama plaintext (hanya bisa huruf biasa, bila kapital sesuaikan kembali kodingan bawahnya, gantilah "a" menjadi "A" bila ingin merubah)
char PT[130];                                                 //membuat variabel global char bernama PT
char matriks[5][5];                                           //membuat variabel global char bernama matriks sejumlah array 2D 5x5
int besar = sizeof(ciphertext)/2;                             //membuat variabel global int bernama besar dengan ukuran sebesar ciphertext /2

/* METHOD BOOTING AWAL */
void setup()                                                   //inisialisasi setup
{
  Serial.begin(9600);                                          //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor
  Serial.print("Enkripsi Polybius kalimat '");                 //mencetak pada serial monitor
  Serial.print(plaintext);                                     //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor

  /*PROSES PEMBUATAN TABEL YANG DISIMPAN PADA VARIABEL MATRIKS*/
  ascii['J']=1;                                                //deklarasi ascii huruf 'j' nilainya berupa 1 (kondisi agar ketika penyimpanan nilai akan di skip
  for(int x='A'; x<='Z'; x++)                                  //memulai kondisi for dengan kondisi variabel int x = a dan selama x kurang dari z, setiap selesai iterasi x akan x++
  {
    if(ascii[x]==0)                                            //memulai kondisi if bila ascii ke-x bernilai 0 (dalam hal ini cek atas)
    {
      matriks[baris][kolom++]=x;                               //menyatakan nilai matriks pada baris dan kolom saat itu akan senilai x saat itu, dan bila selesai nilai kolom akan bertambah
      ascii[x]=1;                                              //menyatakan ascii ke-x bernilai 1 (dalam hal ini cek diatas)
      if(kolom%5==0)                                           //memulai kondisi if bila saat kolom di mod 5 hasilnya 0 
      { 
        baris++;                                               //maka nilai baris akan bertambah selanjutya
        kolom=0;                                               //nilai kolom dinyatakan kembali menjadi 0
      }
    }  
  }

  Serial.println("");                                           //mencetak pada serial monitor
  Serial.print("Matriks 5x5:");                                 //mencetak pada serial monitor
  Serial.println("");                                           //mencetak pada serial monitor

  /*PROSES PENCETAKAN TABEL BERDASRKAN VARIABEL MATRIKS*/
  for(int x=0;x<5;x++)                                          //memulai kondisi for untuk nilai variabel int x = 0 selama nilainya kurang dari 5, setiap iterasi selesai nilai x akan x++
  {
    for(int y=0;y<5;y++)                                        //memulai kondisi for untuk nilai variabel int x = 0 selama nilainya kurang dari 5, setiap iterasi selesai nilai x akan x++
    {
      Serial.print(matriks[x][y]);                              //mencetak pada serial monitor nilai matriks ke-x dan y
      Serial.print(" ");                                        //mencetak pada serial monitor
    }
    Serial.println("");                                         //mencetak pada serial monitor
  }

  /*PROSES ENKRIPSI POLYBIUS DARI KATA MENJADI ANGKA SESUAI MATRIKS*/
  for (int x = 0; x < plaintext[x]; x++)                       //memulai proses looping for dari variabel int baru bernama x=0, dalam kondisi array ke-x pada plaintext[x], bila selesai increment x++
  { 
    Serial.println("");                                        //mencetak pada serial monitor
    Serial.print("Saat ini ");                                 //mencetak pada serial monitor
    Serial.print(plaintext[x]);                                //mencetak pada serial monitor variabel plaintext ke-x

    /*PROSES PENENTUAN LOKASI MELALUI RUMUS PEMBAGIAN MATRIKS 5X5, UBAHLAH RUMUS INI 'A' dan 'a' BILA MENGGUNAKAN SALAH SATU DARI KALIMAT DIATAS, HARAP DIBUAT SAMA TIDAK ADA PROSES PENYAMAAN DISINI*/
    baris = ceil((plaintext[x] - 'A') / 5) + 1;                //rumus untuk mencari baris dengan menormalisasi hasil dari kalkulasi plaintext ke-x dikurangi dengan huruf a dan nilai tersebut akan di bagi 5 dan kemudian ditambahkan angka 1
    kolom = ((plaintext[x] - 'A') % 5) + 1;                    //rumus untuk mencari kolom dengan dari kalkulasi plaintext ke-x dikurangi dengan huruf a dan nilai tersebut akan di bagi terus dengan 5 dan kemudian ditambahkan angka 1
  
    /*KONDISI PENGECEKAN BILA LOKASINYA BERADA PADA K, JIKA IYA BEGITU PULA PADA J KARENA AKAN DIANGGAP SATU*/
    if (plaintext[x] == 'K')                                   //kondisi if bila huruf tersebut adalah k
    { 
      baris = baris - 1;                                       //menyatakan baris baru = nilai baris saat itu - 1
      kolom = 5 - kolom + 1;                                   //menyatakan kolom baru = 5 - nilai kolom saat itu + 1
    } 
  
    /*KONDISI PENGECEKAN BILA LOKASINYA BERADA PADA DIATAS J, JIKA IYA BEGITU PULA PADA J DAN K AKAN DIANGGAP SATU*/
    else if (plaintext[x] >= 'J')                              //kondisi jika bukan == k tapi lebih dari j
    { 
      if (kolom == 1)                                          //kondisi if bila kolom = 1
      { 
        kolom = 6;                                             //menyatakan nilai kolom = 6
        baris = baris - 1;                                     //menyatakan nilai baris baru = baris saat ini - 1
      } 
      kolom = kolom - 1;                                       //menyatakan  nilai kolom baru = kolom saat ini - 1
    } 
    
    Serial.print(" Dirubah -> ");                              //mencetak pada serial monitor
    Serial.print(baris);                                       //mencetak pada serial monitor variabel baris
    Serial.print(kolom);                                       //mencetak pada serial monitor variabel kolom
  } 
  Serial.println("");                                          //mencetak pada serial monitor

  Serial.println("");                                          //mencetak pada serial monitor
  Serial.print("Dekripsi Polybius kalimat '");                 //mencetak pada serial monitor
  Serial.print(ciphertext);                                    //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor

  /*PROSES DEKRIPSI POLYBIUS DARI KATA MENJADI ANGKA SESUAI MATRIKS*/
  int i;                                                       //membuat variabel int bernama i
  for(int x=0;x < besar;x++)                                   //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x kurang dari variabel besar, maka x akan di x++
  { 
    char sementara1 = ciphertext[i];                            //membuat variabel char bernama sementara1 dari nilai cipher ke-i
    baris = sementara1 - '0';                                   //menyatakan nilai baris adalah dari nilai variabel sementara1 - '0'
    char sementara2 = ciphertext[i+1];                          //membuat variabel char bernama sementara2 dari nilai cipher ke-i+1
    kolom = sementara2 - '0';                                   //menyatakan nilai kolom adalah dari nilai variabel sementara2 - '0'
    Serial.print("Saat ini ");                                  //mencetak pada serial monitor
    Serial.print(baris);                                        //mencetak pada serial monitor variabel baris
    Serial.print(kolom);                                        //mencetak pada serial monitor variabel kolom
    PT[x]= matriks[baris-1][kolom-1];                           //menyatakan nilai PT ke-x adalah nilai pada posisi matriks pada baris-1 dan kolom-1
    Serial.print(" Dirubah -> ");                               //mencetak pada serial monitor
    Serial.print(PT[x]);                                        //mencetak pada serial monitor variabel PT ke-x
    Serial.println("");                                         //mencetak pada serial monitor
    i+=2;                                                       //menambahkan i sejumlah 2
  }
  Serial.println("");                                          //mencetak pada serial monitor
}                                                          

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                    //inisialisasi loop
{}
