/* VARIABEL GLOBAL */
String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";                                              //deklarasi variabel String bernama keyword dengan nilai "ABCDEFGHIJKLMNOPQRSTUVWXYZ" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String keyword={"HASSHI"};                                                                   //deklarasi variabel String bernama keyword dengan nilai "HASSHI" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String plaintext={"SAYASUKASEKALIHIMEKOINABA"};                                              //deklarasi variabel String bernama plaintext dengan nilai "SAYASUKASEKALIHIMEKOINABA" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String ciphertext = "";                                                                      //deklarasi variabel string bernama ciphertext dengan nilai masih kosong
String lokasiAngka = "";                                                                     //deklarasi variabel string bernama lokasiAngka dengan nilai masih kosong
String nomorKey = "";                                                                        //deklarasi variabel string bernama nomorKey dengan nilai masih kosong
int pKey= keyword.length();                                                                  //deklarasi variabel int bernama pKey dengan nilai besar variabel keyword
int pPlain= plaintext.length();                                                              //deklarasi variabel int bernama pPlain dengan nilai besar variabel plaintext
int lebihan = pPlain % pKey;                                                                 //deklarasi variabel int bernama lebihan dengan nilai besar variabel pPlain mod pKey
int sementara = pKey - lebihan;                                                              //deklarasi variabel int bernama sementara dengan nilai besar variabel pKey - lebihan
int baris, kolom=pKey, z=0, coba=0;                                                          //deklarasi variabel int bernama baris, kolom= senilai pKey, z=0, coba=0

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode MYSZKOWSKI");                                                        //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  Serial.print("Diketahui plaintext -> ");                                                  //mencetak pada serial monitor
  Serial.println(plaintext);                                                                //mencetak pada serial monitor variabel plaintext
  Serial.print("Diketahui keyword -> ");                                                    //mencetak pada serial monitor
  Serial.println(keyword);                                                                  //mencetak pada serial monitor variabel keyword
  Serial.println("");                                                                       //mencetak pada serial monitor
     
  /*BILA MASIH ADA SISA DARI DARI PANJANG STRING (ALIAS TIDAK PAS)*/ 
  if (lebihan != 0)                                                                         //memulai kondisi if bila variabel lebihan tidak sama 0
  {
   for (int x = 0; x < sementara; x++)                                                      //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari variabel sementara, maka setiap iterasi x akan bertambah 1
   {plaintext += '.';}                                                                      //menyatakan nilai plaintext saat itu '.' dan menambahkan ke plaintext selanjutnya
  }
  baris = plaintext.length() / pKey;                                                        //menyatakan variabel baris senilai besar variabel plaintext / pKey
  
  /*PERUBAHAN MENJADI MATRIKS*/ 
  char matriks[baris][kolom];                                                               //deklarasi variabel char bernama matriks dengan array 2D dari variabel baris dan kolom
  for (int x = 0; x < baris; x++)                                                           //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari variabel baris, maka setiap iterasi x akan bertambah 1
  {
    for (int y = 0; y < kolom; y++)                                                         //memulai kondisi for dengan varibel int bernama y senilai 0 dan selama y kurang dari variabel kolom, maka setiap iterasi y akan bertambah 1
    {
      matriks[x][y] = plaintext[z];                                                         //menyatakan nilai variabel matriks ke x dan y senilai variabel plaintext ke z
      z++;                                                                                  //menambahkan nilai z sebesar 1
    }
  }
    
  /*KLASIFIKASI URUTAN KEYWORD (ALFABBET)*/
  int listNomorKey[pKey];                                                                   //deklarasi variabel int bernama listNomorKey dengan array 1D sebesar variabel pKey
  for (int x = 0; x < alphabet.length(); x++)                                               //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari besar variabel alphabet, maka setiap iterasi x akan bertambah 1
  {
    for (int y = 0; y < pKey; y++)                                                          //memulai kondisi for dengan varibel int bernama y senilai 0 dan selama y kurang dari variabel pKey, maka setiap iterasi y akan bertambah 1
    {
      if (alphabet[x] == keyword[y])                                                        //memulai kondisi if bila nilai variabel alphabet ke x sama dengan keyword ke y
      {
        coba++;                                                                             //menambahkan nilai coba sebesar 1
        listNomorKey[y] = coba;                                                             //menyatakan nilai variabel listNomorKey ke y sebesar variabel coba
       }
     } 
   } 

  /*CEK SATU PERSATU LOKASINYA DIMANA UNTUK KEYWORD (PENOMORANNYA)*/
  for (int x = 0; x < sizeof(listNomorKey)/sizeof(listNomorKey[0]); x++)                    //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari besar variabel listNomorKey/besar variabel listNomorKey ke-0, maka setiap iterasi x akan bertambah 1
  {
    nomorKey += listNomorKey[x];                                                            //menyatakan nilai variabel nomorKey senilai variabel listNomorKey ke  x dan menambahkan variabel tersebut setelah selesai
    listNomorKey[x] = nomorKey[x] - 48;                                                     //menyatakan nilai variabel listNomorKey ke x senilai nomorKey ke x - 48
  }
  
  /*CETAK URUTAN KEYWORD*/
  Serial.println("Tabel Saat ini:");                                                        //mencetak pada serial monitor
  for (int x: listNomorKey)                                                                 //memulai kondisi for untuk variabel int bernama x dari isi variabel listNomorKey
  {
    Serial.print(x);                                                                        //mencetak pada serial monitor variabel x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  /*CETAK KEYWORD*/
  for (int x =0; x< pKey;x++)                                                               //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x kurang dari variabel pKey maka setiap iterasi x akan ditambahkan 1
  {
    Serial.print(keyword[x]);                                                               //mencetak pada serial monitor variabel keyword ke x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println(" ");                                                                      //mencetak pada serial monitor
  /*CETAK ARRAY*/
  for (int x = 0; x < baris; x++)                                                           //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari variabel baris, maka setiap iterasi x akan bertambah 1
  {
    for (int y = 0; y < pKey; y++)                                                          //memulai kondisi for dengan varibel int bernama y senilai 0 dan selama y kurang dari variabel pKey, maka setiap iterasi y akan bertambah 1
    {
      Serial.print(matriks[x][y]);                                                          //mencetak pada serial monitor variabel matriks ke x dan y
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    } 
    Serial.println("");                                                                     //mencetak pada serial monitor
  }
  
  /*PROSES PEMBUATAN CIPHERTEXT, PENCARIAN ANGKA PALING PALING RENDAH*/
  for (int x = 0; x < sizeof(listNomorKey)/sizeof(listNomorKey[0]); x++)                    //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari besar variabel listNomorKey/besar variabel listNomorKey ke-0, maka setiap iterasi x akan bertambah 1
  {listNomorKey[x] = nomorKey[x] - 48;}                                                     //menyatakan nilai variabel listNomorKey ke x senilai nomorKey ke x - 48
  
  /*PROSES PENGECEKAN ANGKA TERSEBUT BERADA DIMANA*/
  for (int x = 1; x <=pKey; x++)                                                            //memulai kondisi for dengan varibel int bernama x senilai 1 dan selama x kurang dari variabel pKey , maka setiap iterasi x akan bertambah 1
  {
    for (int y = 0; y < pKey; y++)                                                          //memulai kondisi for dengan varibel int bernama y senilai 0 dan selama y kurang dari variabel pKey, maka setiap iterasi y akan bertambah 1
    {
      if (listNomorKey[y] == x)                                                             //memulai kondisi if apabila variabel listNomorKey ke y sama dengan variabel x
      {lokasiAngka += y;}                                                                   //menyatakan nilai variabel lokasiAngka senilai y dan menambahkan 1 selanjutnya
    }
  }
  
  /*MEMASUKKAN HASIL PENCARIAN TERSEBUT DALAM CIPHERTEXT*/
  for (int x = 0, k = 0; x <= pKey; x++, k++)                                              //memulai kondisi for dengan varibel int bernama x dan k senilai 0 dan selama x kurang dari variabel pKey, maka setiap iterasi x dan k akan bertambah 1
  {
    int d;                                                                                 //deklarasi variabel int bernama d
    if (k == pKey)                                                                         //memulai kondisi if bila nilai variabel k sama dengan nilai variabel pKey
    {break;}                                                                               //memberhentikan iterasi
    else                                                                                   //jika tidak
    {
      d = lokasiAngka[k];                                                                  //menyatakan nilai d senilai variabel lokasiAngka ke k
      d = d - '0';                                                                         //menyatakan nilai d senilai variabel d saat itu - '0'
     }
     for (int y = 0; y < baris; y++)                                                       //memulai kondisi for dengan varibel int bernama y senilai 0 dan selama y kurang dari variabel bvaris, maka setiap iterasi y akan bertambah 1
     {ciphertext += matriks[y][d];}                                                        //menyatakan nilai ciphertext senilai variabel matriks ke y dan d lalu menambahkannya 
  }  
 
  /*CETAK HASIL CIPHERTEXT*/
  Serial.println("");                                                                     //mencetak pada serial monitor
  Serial.print("Hasil Ciphertext -> ");                                                   //mencetak pada serial monitor
  for (int x = 0; x< ciphertext.length();x++)                                             //memulai kondisi for dengan varibel int bernama x senilai 0 dan selama x kurang dari variabel sementara, maka setiap iterasi x akan bertambah 1
  {
    if(x>0 && x%baris==0)                                                                 //memulai kondisi if apabila variabel x lebih besar dari 0 bersamaan x mod variabel baris adalah 0
    {Serial.print(" ");}                                                                  //mencetak pada serial monitor
    Serial.print(ciphertext[x]);                                                          //mencetak pada serial monitor variabel ciphertext ke x
  }
  Serial.println("");                                                                     //mencetak pada serial monitor
}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                               //inisialisasi loop
{}
