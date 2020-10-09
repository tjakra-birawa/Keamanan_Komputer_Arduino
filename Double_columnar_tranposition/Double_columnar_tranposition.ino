/* VARIABEL GLOBAL */
String keyword1={"WAIFU"};                                                                 //deklarasi variabel string bernama keyword1 dengan nilai "WAIFU" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String keyword2={"BESTG"};                                                                 //deklarasi variabel string bernama keyword2 dengan nilai "BESTG" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String plaintext={"HIMEKOINABA"};                                                          //deklarasi variabel string bernama plaintext dengan nilai "HIMEKOINABA" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
String ciphertext="";                                                                      //deklarasi variabel string bernama ciphertext dengan nilai masih kosong
String ciphertextH={"II0EA0MN0KB0HOA"};                                                    //deklarasi variabel string bernama ciphertextH dengan nilai" II0EA0MN0KB0HOA" (TOLONG MASUKIN INPUT HASIL CIPHERTEXT SEBELUMNYA SECARA MANUAL, MASIH BELUM BISA RETURN HASIL)
String ciphertext2="";                                                                     //deklarasi variabel string bernama ciphertext2 dengan nilai masih kosong
int pKey1 = keyword1.length();                                                             //deklarasi variabel int bernama pKey1 dengan nilai sebesar variabel keyword1 
int pKey2 = keyword2.length();                                                             //deklarasi variabel int bernama pKey2 dengan nilai sebesar variabel keyword2
int pPlain = plaintext.length();                                                           //deklarasi variabel int bernama pPlain dengan nilai sebesar variabel plaintext 
int baris,kolom,sementara;                                                                 //deklarasi variabel int global bernama baris, kolom, dan sementara

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode Double Columnnar Transposition");                                    //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 
  kolom=pKey1;                                                                              //menyatakan nilai kolom senilai pKey1
  columnarT(pPlain,pKey1,baris,kolom,keyword1,ciphertext,plaintext);                        //memulai method columnarT dengan variabel pPlain, pKey1, baris, kolom, keyword1, ciphertext2, dan cipertextH              
  /*^-ZONA ITERASI 1 DAN ZONA ITERASI 2 -v*/
  Serial.println("");                                                                       //mencetak pada serial monitor                  
  Serial.println("ITERASI 2");                                                              //mencetak pada serial monitor
  int pCipher= ciphertextH.length();                                                        //menyatakan variabel int bernama pCipher dengan nilai sebesar variabel ciphertextH
  sementara=0;                                                                              //menyatakan variabel sementara=0
  baris=0;                                                                                  //menyatakan variabel baris = 0
  kolom=pKey2;                                                                              //menyatakan nilai variabel kolom sebensar variabel pKey2
  columnarT(pCipher,pKey2,baris,kolom,keyword2,ciphertext2,ciphertextH);                    //memulai method columnarT dengan variabel pCipher,pKey2,baris,kolom,keyword2,ciphertext2, dan ciphertextH

}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                  //inisialisasi loop
{}

void columnarT(int a, int b,int ba, int ko, String key, String cipherTemp, String pt)        //inisilasisasi method columnarT dengan syarat variabel int a,b,ba,ko, dan string key, ciphertemp,pt
{
  /*KALKULASI BESAR MATRIKS YANG AKAN TERSIMPAN, MENGECEK APAKAH GANJIL ATAU GENAP DAN MENYESUAIKANNYA*/
  if(a%b>0)                                                                                 //memulai kondisi if variabel a mod b hasilnya lebih dari 0
  {ba=1+(a/b);                                                                              //menyatakan nilai variabel ba adalah 1 + (variabel a / b)
  }else                                                                                     //jika bukan atau tidak sesuai
  {ba=(a/b);}                                                                               //menyatakan nilai variabel ba adalah (variabel a / b1)

  /*INISILASISASI TABEL COLUMNAR, MENYATAKAN PENEMPATAN KE BARIS DAN KOLOM BERAPA*/
  char tabelA[ba][ko];                                                                      //deklarasi variabel char bernama tabelA dengan besar array 2D dari nilai variabel ba dan ko
  for(int x=0; x < ba;x++)                                                                  //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel ba maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0; y<ko;y++)                                                                  //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel ba maka setiap iterasi y akan di tambahkan 1
    {
      if(sementara<a)                                                                       //memulai kondisi if bila nilai variabel sementara kurang dari variabel a
      {tabelA[x][y]=pt[sementara];}                                                         //menyatakan nilai variabel tabelA ke x dan y adalah sebesar variabel key ke sementara
      else                                                                                  //bila tidak
      {tabelA[x][y]='.';}                                                                   //menyatakan nilai variabel tabelA ke x dan y dengan nilai "0";
      sementara++;                                                                          //menambahkan 1 pada variabel sementara
    }
  }

  /*INISIALISASI SORTING DENGAN ARRAY TERPISAH*/
  char sortKey[b];                                                                          //deklarasi variabel char bernama sortKey dengan besar array 1D senilai variabel b                                                                      
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1 
  {sortKey[x]=key[x];}                                                                      //menyatakan nilai variabel sortKey ke x senilai dengan variabel key ke x
  /*SORTING key (BUBBLE SORT)*/
  for(int x=0;x<b-1;x++)                                                                    //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b - 1 maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<b-1-x;y++)                                                                //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama x tersebut kurang dari variabel b -1 -x maka setiap iterasi y akan di tambahkan 1
    {
      if(sortKey[y]>sortKey[y+1])                                                           //memulai kondisi if bila variabel sortKey ke y lebih besar dari variabel sortKey ke y+1
      {
        sementara=sortKey[y];                                                               //menyatakan nilai variabel sementara adalah variabel sortKey ke y
        sortKey[y]=sortKey[y+1];                                                            //menyatakan nilai sortKey ke y adalah nilai sortKey ke y+1
        sortKey[y+1]=sementara;                                                             //menyatakan nilai sortKey ke y+1 adalah nilai variabel sementara
      }
    }
  }
  /*PENOMORAN key*/
  int indexKey[b];                                                                          //deklarasi variabel int bernama indexKey dengan array 1D senilai variabel b
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<b;y++)                                                                    //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel b maka setiap iterasi y akan di tambahkan 1
    {
      if(sortKey[y]==key[x])                                                                //memulai kondisi if bila variabel sortKey ke y adalah sama dengan nilai variabel key ke x
      {indexKey[x]=y;}                                                                      //menyatakan nilai variabel indexKey ke x adalah nilai variabel y
    }
  }
  /*INISIALISASI SORTING DARI ARRAY INDEX*/
  int indexSortKey[b];                                                                      //deklarasi variabel int bernama indexSortKey dengan array 1D senilai variabel b
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<b;y++)                                                                    //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel b maka setiap iterasi y akan di tambahkan 1
    {
      if(sortKey[x]==key[y])                                                                //memulai kondisi if bila variabel sortKey ke x adalah sama dengan nilai variabel key ke y
      {indexSortKey[x]=y;}                                                                  //menyatakan nilai variabel indexSortKey ke x adalah nilai variabel y
    }
  }

  /*CETAK PENOMORAN key DAN key*/
  Serial.println("TABEL SAAT INI");                                                         //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(indexKey[x]+1);                                                            //mencetak pada seral monitor variabel indexKey ke x+1
    Serial.print(" ");                                                                      //mencetak pada serial monitor                             
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(key[x]);                                                                   //mencetak pada serial monitor variabel key ke x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  /*CETAK TABEL UTAMA*/
  for(int x=0;x<ba;x++)                                                                     //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel ba maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0; y<ko;y++)                                                                  //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel ko maka setiap iterasi y akan di tambahkan 1
    {
      Serial.print(tabelA[x][y]);                                                           //mencetak pada serial monitor variabel tabelA ke x dan y
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    }
    Serial.println("");                                                                     //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor

  /*CETAK HASIL SORTING TABEL BERDASARKAN key*/
  Serial.println("HASIL SORTING");                                                          //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=1; x<=b;x++)                                                                    //memulai kondisi for dengan variabel int bernama x sebesar 1 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(x);                                                                        //mencetak pada serial monitor variabel x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    Serial.print(sortKey[x]);                                                               //mencetak pada serial monitor variabel sortKey ke x
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  /*INI BAGIAN ARRAYNYA*/
  char sortTabelA[ba][ko];                                                                  //deklarasi variabel char bernama sortTabelA dengan array 2D dari variabel ba dan ko
  for(int x=0;x<b;x++)                                                                      //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel b maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<b;y++)                                                                    //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel b maka setiap iterasi y akan di tambahkan 1
    {sortTabelA[x][y]=tabelA[x][indexSortKey[y]];}                                          //menyatakan nilai variabel sortTabelA ke x dan y adalah nilai variabel tabelA ke x dan ke indexSortKey ke y
  }
  /*CETAK TABEL SORTING*/
  for(int x=0;x<ba;x++)                                                                     //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel ba maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0; y<ko;y++)                                                                  //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel ko maka setiap iterasi y akan di tambahkan 1
    {
      Serial.print(sortTabelA[x][y]);                                                       //mencetak pada serial monitor variabel sortTabelA ke x dan y
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    }
    Serial.println("");                                                                     //mencetak pada serial monitor
  }

  /*SEKARANG CETAK HASIL CIPHERTEXT*/
  for(int x=0;x<ko;x++)                                                                     //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel ko maka setiap iterasi x akan di tambahkan 1
  {
    for(int y=0;y<ba;y++)                                                                   //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama y tersebut kurang dari variabel ba maka setiap iterasi y akan di tambahkan 1
    {cipherTemp += sortTabelA[y][x];}                                                       //menyatakan nilai variabel has senilai variabel sortTabelA ke y dan x dan menambahkan ciphhertext selanjutnya
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  Serial.println("HASIL CIPHERTEXT");                                                       //mencetak pada serial monitor
  int pCipher= cipherTemp.length();                                                         //deklarasi variabel int bernama pCpiher senilai panjangnya variabel has
  for(int x=0;x<pCipher;x++)                                                                //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama x tersebut kurang dari variabel pCipher maka setiap iterasi x akan di tambahkan 1
  {
    if(x>0 && x%ba==0)                                                                      //memulai kondisi if bila x lebih dari 0 dan bila x mod variabel ba nilainya 0 secara bersaamaan maka
    {Serial.print(" ");}                                                                    //mencetak pada serial monitor   
    Serial.print(cipherTemp[x]);                                                            //mencetak pada serial monitor variabel has ke x
  }
  Serial.println("");                                                                       //mencetak pada serial monitor  
}
