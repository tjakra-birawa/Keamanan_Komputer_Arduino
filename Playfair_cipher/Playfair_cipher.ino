/* VARIABEL GLOBAL */
char matriks[5][5];                                                                         //mendeklarasikan variabel char bernama matriks 2D array 5x5
String keyword={"WAIFU"};                                                                   //deklarasi variabel string bernama keyword dengan nilai "WAIFU" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String plaintext={"HIMEKOINABA"};                                                           //deklarasi variabel string bernama plaintext dengan nilai "HIMEKOINABA" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String ciphertext="";                                                                       //deklarasi variabel string bernama ciphertext dengan nilai masih kosong
int pPlain = sizeof(plaintext)-1;                                                           //deklarasi variabel int bernama pPlain dengan nilai sebesar variabel plaintext - 1
int tanda[130],baris,kolom;                                                                 //deklarasi variabel int global bernama tanda [130], baris, dan kolom 

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode Playfair cipher");                                                   //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  Serial.print("Diketahui keyword -> ");                                                    //mencetak pada serial monitor
  Serial.print(keyword);                                                                    //mencetak pada serial monitor variabel keyword
  Serial.println("");                                                                       //mencetak pada serial monitor  

  Serial.print("Diketahui plaintext -> ");                                                  //mencetak pada serial monitor
  Serial.print(plaintext);                                                                  //mencetak pada serial monitor variabel keyword
  Serial.println("");                                                                       //mencetak pada serial monitor  
  /*PROSES MASUK keyword PADA MATRIKS*/
  tanda['J']=1;                                                                             //deklarasi tanda huruf 'J' nilainya berupa 1 (kondisi agar ketika penyimpanan nilai akan di skip
  for(int x=0; x < pPlain; x++)                                                             //memulai kondisi for dengan kondisi variabel int x = 0 dan selama x kurang dari variabel panjang_pt, setiap selesai iterasi x akan x++
  {
    if(!tanda[keyword[x]])                                                                  //memulai kondisi if variabel tanda tidak ada pada variabel keyword ke-x
    {
      tanda[(keyword[x])]=1;                                                                //menyatakan variabel tanda pada keyword ke-x senilai 1
      matriks[baris][kolom++]=keyword[x];                                                   //menyatakan nilai variabel matriks baris dan kolom saat ini bernilai variabel keyword ke-x saat ini dan bila selesai kolom akan di increment
      if(kolom%5==0)                                                                        //memulai kondisi if nilai variabel kolom mod 5 hasilnya 0
      {
        kolom=0;                                                                            //menyatakan nilai variabel kolom = 0
        baris++;                                                                            //menambahkan nilai variabel baris sebesar 1
      }
    }
  }
  
  /*PROSES MEMASUKKAN SISA YANG BELUM MATRIKS*/  
  for(int x='A';x<='Z';x++)                                                                  //memulai kondisi for dengan kondisi variabel int x = A dan selama x kurang dari Z, setiap selesai iterasi x akan x++
  {
    if(tanda[x]==0)                                                                          //memulai kondisi if variabel tanda ke-x adalah 0
    {
      matriks[baris][kolom++]=x;                                                             //menyatakan nilai variabel matriks baris dan kolom saat ini bernilai x saat ini dan bila selesai kolom akan di increment
      tanda[x]=1;                                                                            //menyatakan nilai tanda ke-x senilai 1
      if(kolom%5==0)                                                                         //memulai kondisi if nilai variabel kolom mod 5 hasilnya 0
      {
        baris++;                                                                             //menambahkan nilai variabel baris sebesar 1
        kolom=0;                                                                             //menyatakan nilai variabel kolom = 0                                       
      }
    }
  } 
  
  Serial.println("");                                                                        //mencetak pada serial monitor
  Serial.print("Matriks 5x5:");                                                              //mencetak pada serial monitor
  Serial.println("");                                                                        //mencetak pada serial monitor
  
  /*PROSES PENCETAKAN TABEL BERDASRKAN VARIABEL MATRIKS*/
  for(int x=0;x<5;x++)                                                                       //memulai kondisi for untuk nilai variabel int x = 0 selama nilainya kurang dari 5, setiap iterasi selesai nilai x akan x++
  {
    for(int y=0;y<5;y++)                                                                     //memulai kondisi for untuk nilai variabel int x = 0 selama nilainya kurang dari 5, setiap iterasi selesai nilai x akan x++
    {
      Serial.print(matriks[x][y]);                                                           //mencetak pada serial monitor nilai matriks ke-x dan y
      Serial.print(" ");                                                                     //mencetak pada serial monitor
    }
    Serial.println("");                                                                      //mencetak pada serial monitor
  }

  /*CEK GANJIL DALAM PLAINTEXT BILA IYA TAMBAHKAN ANGKA Z*/
  if (pPlain % 2 > 0)                                                                       //memulai kondisi if bila pPlain mod 2 lebih dari 0 maka
  {plaintext += 'Z';}                                                                       //menyatakan nilai plaintext berikutnya 'Z' dan menambahkan jumlah plaintext selanjutnya
  
  /*PROSES ENKRIPSI*/
  for (int i = 0; i < plaintext.length(); i += 2)                                           //memulai kondisi for dengan variabel int bernama i senilai 0 dan selama i kurang dari besar variabel plaintext, maka setiap selesai iterasi akan ditambahkan 2
  {
    char A = plaintext[i];                                                                  //deklarasi variabel char bernama A dari nilai variabel plaintext ke i
    char B = plaintext[i + 1];                                                              //deklarasi variabel char bernama B dari nilai variabel plaintext ke i+1
    int Ax, Ay, Bx, By;                                                                     //deklarasi variabel int bernama Ax, Ay, Bx, By
    int sementara;                                                                          //deklarasi variabel int bernama sementara

    /*CEK KOORDINAT*/
    for (int y = 0; y < 5; y++)                                                              //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y kurang dari 5, maka setiap selesai iterasi akan ditambahkan 1
    {
      for (int x = 0; x < 5; x++)                                                            //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x kurang dari 5, maka setiap selesai iterasi akan ditambahkan 1
      {
        if (matriks[y][x] == A)                                                              //memulai kondisi if bila variabel matriks ke y dan x senilai variabel A
        {
          Ax = x;                                                                            //menyatakan nilai variabel Ax senilai variabel x
          Ay = y;                                                                            //menyatakan nilai variabel Ay senilai variabel y
        }
        if (matriks[y][x] == B)                                                              //memulai kondisi if bila variabel matriks ke y dan x senilai variabel B
        {
          Bx = x;                                                                            //menyatakan nilai variabel Bx senilai variabel x
          By = y;                                                                            //menyatakan nilai variabel By senilai variabel y
        }
      }
    }

    /*1 - JIKA X != Y MAKA X DITUKAR*/
    if (Ax != Bx && Ay != By)                                                                //memulai kondisi if bila nilai variabel Ax tidak sama dengan varibel Bx bersamaan dengan nilai variabek Ay tidak sama dengan variabel By
    {
      sementara = Ax;                                                                        //menyatakan nilai variabel sementara senilai variabel Ax
      Ax = Bx;                                                                               //menyatakan nilai variabel Ax senilai variabel Bx
      Bx = sementara;                                                                        //menyatakan nilai variabel Bx senilai variabel sementara
    } 
    /*2 - JIKA X = X (VERTIKAL) MAKA AMBIL YANG BAWAH*/
    else if (Ax == Bx && Ay != By)                                                           //bila tidak, nilai variabel Ax sama dengan nilai variabel Bx bersamaan dengan nilai variabel Ay tidak sama dengan nilai variabel By
    { 
      Ay = (Ay + 1) % 5;                                                                     //menyatakan nilai variabel Ay senilai variabel Ay+1 mod5
      By = (By + 1) % 5;                                                                     //menyatakan nilai variabel By senilai variabel By+1 mod5
    } 
    /*3 - JIKA Y = Y (HORIZONTAL) MAKA AMBIL SEBELAH*/
    else if (Ax != Bx && Ay == By)                                                           //bila tidak, nilai variabel Ax tidak sama dengan nilai variabel Bx bersamaan dengan nilai variabel Ay  sama dengan nilai variabel By
    {
      Ax = (Ax + 1) % 5;                                                                     //menyatakan nilai variabel Ax senilai variabel Ax+1 mod5
      Bx = (Bx + 1) % 5;                                                                     //menyatakan nilai variabel Bx senilai variabel Bx+1 mod5
    }
    A = matriks[Ay][Ax];                                                                     //menyatakan nilai variabel A senilai dengan nilai variabel matriks ke Ay dan Ax
    B = matriks[By][Bx];                                                                     //menyatakan nilai variabel B senilai dengan nilai variabel matriks ke By dan Bx
    ciphertext += A;                                                                         //menyatakan nilai variabel ciphertext senilai dengan nilai variabel A dan menambahkan ke ciphertext selanjutnya
    ciphertext += B;                                                                         //menyatakan nilai variabel ciphertext senilai dengan nilai variabel B dan menambahkan ke ciphertext selanjutnya
  }
  
  /*CETAK PLAINTEXT GENAP*/
  Serial.print("Plaintext : ");                                                              //mencetak pada serial monitor
  for (int x = 0; x < plaintext.length(); x++)                                               //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x kurang dari besar variabel plaintext, maka setiap selesai iterasi akan ditambahkan 1
  {
    if (x > 0 && x % 2 == 0)                                                                 //memulai kondisi if bila variabel x lebih besar dari 0 dan variabel x mod 2 hasilnya 0
    {Serial.print(" ");}                                                                     //mencetak pada serial monitor
    Serial.print(plaintext[x]);                                                              //mencetak pada serial monitor variabel plaintext ke x
  }
  Serial.println("");                                                                        //mencetak pada serial monitor
  /*CETAK HASIL ENKRIPSI*/
  Serial.print("Ciphertext: ");                                                              //mencetak pada serial monitor
  for (int x = 0; x < ciphertext.length(); x++)                                              //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x kurang dari besar variabel ciphertext, maka setiap selesai iterasi akan ditambahkan 1
  {
    if (x > 0 && x % 2 == 0)                                                                 //memulai kondisi if bila variabel x lebih besar dari 0 dan variabel x mod 2 hasilnya 0
    {Serial.print(" ");}                                                                     //mencetak pada serial monitor
    Serial.print(ciphertext[x]);                                                             //mencetak pada serial monitor variabel ciphertext ke x
  }
}      
                                     
/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                  //inisialisasi loop
{}
