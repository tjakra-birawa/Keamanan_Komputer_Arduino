/* VARIABEL GLOBAL */
char keyword[]={"WAIFU"};                                                                   //deklarasi variabel char bernama keyword dengan nilai "WAIFU" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
char plaintext[]={"HIMEKOINABA"};                                                           //deklarasi variabel char bernama plaintext dengan nilai "HIMEKOINABA" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String ciphertext="";                                                                       //deklarasi variabel strring bernama ciphertext dengan nilai masih kosong
int pKey = sizeof(keyword)-1;                                                               //deklarasi variabel int bernama pKey dengan nilai sebesar variabel keyword - 1
int pPlain = sizeof(plaintext)-1;                                                           //deklarasi variabel int bernama pPlain dengan nilai sebesar variabel plaintext - 1
int  baris,kolom =pKey,sementara;                                                                 //deklarasi variabel int global bernama baris, kolom, dan sementara

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode Columnnar Transposition");                                           //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  /*KALKULASI BESAR MATRIKS YANG AKAN TERSIMPAN, MENGECEK APAKAH GANJIL ATAU GENAP DAN MENYESUAIKANNYA*/
  if(pPlain%pKey>0)                                                                         //memulai kondisi if variabel pPlain mod pKey hasilnya lebih dari 0
  {baris=1+(pPlain/pKey);                                                                   //menyatakan nilai variabel baris adalah 1 + (variabel pPlain / pKey)
  }else                                                                                     //jika bukan atau tidak sesuai
  {baris=(pPlain/pKey);}                                                                    //menyatakan nilai variabel baris adalah (variabel pPlain / pKey)

  /*INISILASISASI TABEL COLUMNAR, MENYATAKAN PENEMPATAN KE BARIS DAN KOLOM BERAPA*/
  char tabelA[baris][kolom];                                                                //deklarasi variabel char bernama tabelA dengan besar array 2D dari nilai variabel baris dan kolom
  for(int x=0; x < baris;x++)                                                               //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel baris maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0; y<kolom;y++)                                                               //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel baris maka setiap iterasi y akan di tambahkan 1
    {
      if(sementara<pPlain)                                                                  //memulai kondisi if bila nilai variabel sementara kurang dari variabel pPlain
      {tabelA[x][y]=plaintext[sementara];}                                                  //menyatakan nilai variabel tabelA ke x dan y adalah sebesar variabel plaintext ke sementara
      else                                                                                  //bila tidak
      {tabelA[x][y]='.';}                                                                   //menyatakan nilai variabel tabelA ke x dan y dengan nilai "0";
      sementara++;                                                                          //menambahkan 1 pada variabel sementara
    }
  }

  /*INISIALISASI SORTING DENGAN ARRAY TERPISAH*/
  char sortKey[pKey];                                                                       //deklarasi variabel char bernama sortKey dengan besar array 1D senilai variabel pKey                                                                      
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1 
  {sortKey[x]=keyword[x];}                                                                  //menyatakan nilai variabel sortKey ke x senilai dengan variabel keyword ke x
  /*SORTING KEYWORD (BUBBLE SORT)*/
  for(int x=0;x<pKey-1;x++)                                                                 //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey - 1 maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<pKey-1-x;y++)                                                             //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama x tersebut kurang dari variabel pKey -1 -x maka setiap iterasi y akan di tambahkan 1
    {
      if(sortKey[y]>sortKey[y+1])                                                           //memulai kondisi if bila variabel sortKey ke y lebih besar dari variabel sortKey ke y+1
      {
        sementara=sortKey[y];                                                               //menyatakan nilai variabel sementara adalah variabel sortKey ke y
        sortKey[y]=sortKey[y+1];                                                            //menyatakan nilai sortKey ke y adalah nilai sortKey ke y+1
        sortKey[y+1]=sementara;                                                             //menyatakan nilai sortKey ke y+1 adalah nilai variabel sementara
      }
    }
  }
  /*PENOMORAN KEYWORD*/
  int indexKey[pKey];                                                                       //deklarasi variabel int bernama indexKey dengan array 1D senilai variabel pKey
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<pKey;y++)                                                                 //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel pKey maka setiap iterasi y akan di tambahkan 1
    {
      if(sortKey[y]==keyword[x])                                                            //memulai kondisi if bila variabel sortKey ke y adalah sama dengan nilai variabel keyword ke x
      {indexKey[x]=y;}                                                                      //menyatakan nilai variabel indexKey ke x adalah nilai variabel y
    }
  }
  /*INISIALISASI SORTING DARI ARRAY INDEX*/
  int indexSortKey[pKey];                                                                   //deklarasi variabel int bernama indexSortKey dengan array 1D senilai variabel pKey
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<pKey;y++)                                                                 //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel pKey maka setiap iterasi y akan di tambahkan 1
    {
      if(sortKey[x]==keyword[y])                                                            //memulai kondisi if bila variabel sortKey ke x adalah sama dengan nilai variabel keyword ke y
      {indexSortKey[x]=y;}                                                                  //menyatakan nilai variabel indexSortKey ke x adalah nilai variabel y
    }
  }

  /*CETAK PENOMORAN KEYWORD DAN KEYWORD*/
  Serial.println("TABEL SAAT INI");                                                         //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(indexKey[x]+1);                                                            //mencetak pada seral monitor variabel indexKey ke x+1
    Serial.print(" ");                                                                      //mencetak pada serial monitor                             
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(keyword[x]);                                                               //mencetak pada serial monitor variabel keyword ke x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  /*CETAK TABEL UTAMA*/
  for(int x=0;x<baris;x++)                                                                  //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel baris maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0; y<kolom;y++)                                                               //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel kolom maka setiap iterasi y akan di tambahkan 1
    {
      Serial.print(tabelA[x][y]);                                                           //mencetak pada serial monitor variabel tabelA ke x dan y
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    }
    Serial.println("");                                                                     //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor

  /*INI BAGIAN ARRAYNYA SORTING*/
  char sortTabelA[baris][kolom];                                                            //deklarasi variabel char bernama sortTabelA dengan array 2D dari variabel baris dan kolom
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<pKey;y++)                                                                 //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel pKey maka setiap iterasi y akan di tambahkan 1
    {sortTabelA[x][y]=tabelA[x][indexSortKey[y]];}                                          //menyatakan nilai variabel sortTabelA ke x dan y adalah nilai variabel tabelA ke x dan ke indexSortKey ke y
  }
  
  /*CETAK HASIL SORTING TABEL BERDASARKAN KEYWORD*/
  Serial.println("HASIL SORTING");                                                          //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=1; x<=pKey;x++)                                                                 //memulai kondisi for dengan variabel int bernama x sebesar 1 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(x);                                                                        //mencetak pada serial monitor variabel x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(sortKey[x]);                                                               //mencetak pada serial monitor variabel sortKey ke x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor  
  /*CETAK TABEL SORTING*/
  for(int x=0;x<baris;x++)                                                                  //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel baris maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0; y<kolom;y++)                                                               //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel kolom maka setiap iterasi y akan di tambahkan 1
    {
      Serial.print(sortTabelA[x][y]);                                                       //mencetak pada serial monitor variabel sortTabelA ke x dan y
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    }
    Serial.println("");                                                                     //mencetak pada serial monitor
  }

  /*SEKARANG CETAK HASIL CIPHERTEXT*/
  for(int x=0;x<kolom;x++)                                                                  //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel kolom maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<baris;y++)                                                                //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel baris maka setiap iterasi y akan di tambahkan 1
    {ciphertext += sortTabelA[y][x];}                                                       //menyatakan nilai variabel ciphertext senilai variabel sortTabelA ke y dan x dan menambahkan ciphhertext selanjutnya
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  Serial.println("HASIL CIPHERTEXT");                                                       //mencetak pada serial monitor
  int pCipher= ciphertext.length();                                                         //deklarasi variabel int bernama pCpiher senilai panjangnya variabel ciphertext
  for(int x=0;x<pCipher;x++)                                                                //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pCipher maka setiap iterasi x akan di tambahkan 1
  {
    if(x>0 && x%baris==0)                                                                   //memulai kondisi if bila x lebih dari 0 dan bila x mod variabel baris nilainya 0 secara bersaamaan maka
    {Serial.print(" ");}                                                                    //mencetak pada serial monitor   
    Serial.print(ciphertext[x]);                                                            //mencetak pada serial monitor variabel ciphertext ke x
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                  //inisialisasi loop
{}
