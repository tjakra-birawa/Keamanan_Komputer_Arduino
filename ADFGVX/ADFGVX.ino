/* VARIABEL GLOBAL */
char keyword[]={"WAIFU"};                                                                   //deklarasi variabel char bernama keyword dengan nilai "WAIFU" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
char plaintext[]={"HIMEKOINABA"};                                                           //deklarasi variabel char bernama plaintext dengan nilai "HIMEKOINABA" (harap gunakan huruf KAPITAL atau jika ada huruf BIASA harap disatukan saja jangan dibedakan satu sama lain)
char plaintextA[(sizeof(plaintext)-1)*2];                                                   //deklarasi variabel char bernama plaintextA dengan array 1D dari nilai besar variabel (plaintext-1) *2
char adfgvx[6]={'A','D','F','G','V','X'};                                                   //deklarasi variabel char bernama adfgvx dengan array 1D dari nilai A,D,F,G,V,X
char tabelA[6][6]={{'8','P','3','D','1','N'},{'L','T','4','O','A','H'},
                   {'7','K','B','C','5','Z'},{'J','U','6','W','G','M'},
                   {'X','S','V','I','R','2'},{'9','E','Y','0','F','Q'}};                    //deklarasi variabel char bernama tabelA dengan array 2D 6x6 dari nilai yang ditetapkan
String ciphertext="";                                                                       //deklarasi variabel strring bernama ciphertext dengan nilai masih kosong
int pKey = sizeof(keyword)-1;                                                               //deklarasi variabel int bernama pKey dengan nilai sebesar variabel keyword - 1
int pPlain = sizeof(plaintext)-1;                                                           //deklarasi variabel int bernama pPlain dengan nilai sebesar variabel plaintext - 1
int  baris,kolom,sementara;                                                                 //deklarasi variabel int global bernama baris, kolom, dan sementara

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode ADFGVX");                                                            //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  /*CETAK TABEL ADFGVX*/
  for (int x=0;x<6;x++)                                                                     //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari 6 maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0; y<6;y++)                                                                   //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari 6 maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      Serial.print(tabelA[x][y]);                                                           //mencetak pada serial monitor variabel tabelA ke x dan y
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    }
    Serial.println("");                                                                     //mencetak pada serial monitor
  }

  /*MENCARI LETAK PADA TABEL ADFGVX*/
  for(int x=0;x<pPlain;x++)                                                                 //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pPlain maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0; y<6;y++)                                                                   //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari 6 maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      for(int z=0;z<6;z++)                                                                  //memulai kondisi for dengan variabel int bernama z senilai 0 dan selama z tersebut kurang dari 6 maka setiap iterasi berikutnya z akan ditambahkan 1
      {
        if(tabelA[y][z]==plaintext[x])                                                      //memulai kondisi if bila nilai variabel tabelA ke y dan z sama dengan nilai variabel plaintext ke x
        {
          plaintextA[sementara]= adfgvx[y];                                                 //menyatakan nilai variabel plaintextA ke sementara akan senilai dengan nilai variabel adfgvx ke y
          plaintextA[sementara+1]=adfgvx[z];                                                //menyatakan nilai variabel plaintextA ke sementara+1 akan senilai dengan nilai variabel adfgvx ke z
          sementara=sementara+2;                                                            //menyatakan nilai variabel sementara akan senilai dengan nilai sementara saat itu + 2
        }
      }
    }
  }
  Serial.println("");                                                                       //mencetak pada serial monitor
  
  /*CETAK HASIL PELETAKANNYA*/
  int y=0;                                                                                  //deklarasi variabel int bernama y senilai 0
  Serial.println("POSISI DI ADFGVX SAAT INI");                                              //mencetak pada serial monitor
  for(int x=0; x<pPlain;x++)                                                                //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pPlain maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.print(plaintext[x]);                                                             //mencetak pada serial monitor variabel plaintext ke x
    Serial.print(" berada di lokasi -> ");                                                  //mencetak pada serial monitor
    
    for(y;y<pPlain*2;y++)                                                                   //memulai kondisi for dengan variabel y dan selama y tersebut kurang dari variabel pPlain*2 maka setiap iterasi berikutnya y akan ditambahkan y+2
    {
      Serial.print(plaintextA[y]);                                                          //mencetak pada serial monitor variabel plaintextA ke y
      Serial.print(" dan ");                                                                //mencetak pada serial monitor
      Serial.print(plaintextA[y+1]);                                                        //mencetak pada serial monitor variabel plaintextA ke y+1
      Serial.print(" ");                                                                    //mencetak pada serial monitor
      y=y+2;                                                                                //menyatakan nilai variabel y akan senilai dengan nilai y saat itu + 2
      break;                                                                                //menghentikan kondisi for
    } 
    Serial.println("");                                                                     //mencetak pada serial monitor
  }
  
  /*KALKULASI BESAR MATRIKS YANG AKAN TERSIMPAN, MENGECEK APAKAH GANJIL ATAU GENAP DAN MENYESUAIKANNYA*/
  baris=0;                                                                                  //menyatakan nilai variabel baris = 0
  sementara=0;                                                                              //menyatakan nilai variabel sementara = 0
  kolom=pKey;                                                                               //menyatakan nilai variabel kolom = variabel pKey
  if((pPlain*2)%pKey>0)                                                                     //memulai kondisi if bila nilai variabel pPlain*2 mod pKey lebih besar dari 0
  {baris = 1+((pPlain*2)/pKey);}                                                            //menyatakan nilai variabel baris akan senilai 1+ (variabel pPlain*2 / pKey
  else                                                                                      //bila tidak
  {baris = pPlain*2/pKey;}                                                                  //menyatakan nilai variabel baris akan senilai variabel pPlain*2 / pKey
  
   /*INISILASISASI TABEL key, MENYATAKAN PENEMPATAN KE BARIS DAN KOLOM BERAPA*/
  char keyA[baris][kolom];                                                                  //deklarasi variabel char bernama keyA dengan array 2D dari variabel baris dan kolom
  for(int x=0;x<baris;x++)                                                                  //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel baris maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0;y<kolom;y++)                                                                //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel kolom maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      if(sementara<pPlain*2)                                                                //memulai kondisi if bila nilai variabel sementara kurang dari variabel pPlain*2
      {keyA[x][y] = plaintextA[sementara];}                                                 //menyatakan nilai variabel keyA ke x dan y akan senilai variabel plaintextA ke sementara
      else                                                                                  //bila tidak
      {keyA[x][y] = '.';}                                                                   //menyayakan nilai variabel keyA ke x dan y senilai "."
      sementara++;                                                                          //menambahkan nilai variabel sementara sebesar 1
    }
  }

  /*PENOMORAN SORTED KEY*/
  char sortKey[pKey];                                                                       //deklarasi variabel char bernama sortKey dengan array 1D dari variabel pKey
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {sortKey[x]=keyword[x];}                                                                  //menyatakan nilai variabel sortKey ke x akan sama dengan variabel nilai keyword ke x
  
  /*SORTING KEY BUBBLE SORT*/
  for(int x=0;x<pKey-1;x++)                                                                  //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey-1 maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0;y<pKey-1-x;y++)                                                              //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel pKey-1-x maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      if(sortKey[y]>sortKey[y+1])                                                            //memulai kondisi if bila nilai variabel sortKey ke y lebih besar dari variabel softKey ke y+1
      {
        sementara=sortKey[y];                                                                //menyatakan nilai variabel sementara = nilai variabel sortKey ke y
        sortKey[y]=sortKey[y+1];                                                             //menyatakan nilai variabel sortKey ke y = nilai variabel sortKey ke y+1
        sortKey[y+1]=sementara;                                                              //menyatakan nilai variabel sortKey ke y+1 = nilai variabel sementara
      }
    }
  }
  
  /*PENOMORAN KEY INDEX*/
  int indexKey[pKey];                                                                        //deklarasi variabel char bernama indexKey dengan array 1D dari variabel pKey
  for(int x=0;x<pKey;x++)                                                                    //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0;y<pKey;y++)                                                                  //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel pKey maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      if(sortKey[y]==keyword[x])                                                             //memulai kondisi if bila nilai variabel sortKey ke y =  variabel keyword ke x
      {indexKey[x]=y;}                                                                       //menyatakan nilai variabel indexKey ke x = nilai ke y
    }
  }

  /*SORTING INDEX KEY*/
  int indexSortKey[pKey];                                                                   //deklarasi variabel char bernama indexSortKey dengan array 1D dari variabel pKey
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0;y<pKey;y++)                                                                 //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel pKey maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      if(sortKey[x]==keyword[y])                                                            //memulai kondisi if bila nilai variabel sortKey ke x = variabel keyword ke y
      {indexSortKey[x]=y;}                                                                  //menyatakan nilai variabel indexSortKey ke x = nilai ke y
    }
  }
  
  Serial.println("");                                                                       //mencetak pada serial monitor
  Serial.println("ARRAY SAAT INI:");                                                        //mencetak pada serial monitor
  /*CETAK PENOMORAN KEYWORD SEBELUM*/
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.print(indexKey[x+1]);                                                            //mencetak pada serial monitor variabel indexKey ke x+1
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  /*CETAK KEYWORD SEBELUM*/
  Serial.println("");                                                                       //mencetak pada serial monitor
  for(int x=0;x<pKey;x++)                                                                   //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.print(keyword[x]);                                                               //mencetak pada serial monitor
    Serial.print(" ");                                                                      //mencetak pada serial monitor
  }
  /*CETAK ARRAY KEYWORD*/
  for(int x=0;x<baris;x++)                                                                  //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.println("");                                                                     //mencetak pada serial monitor
    for(int y=0;y<pKey;y++)
    {
      Serial.print(keyA[x][y]);                                                             //mencetak pada serial monitor
      Serial.print(" ");                                                                    //mencetak pada serial monitor
    }
  }
  Serial.println("");                                                                       //mencetak pada serial monitor

  /*PROSES SORTING KEYWORD ARRAY*/
  char sortKeyA[baris][kolom];                                                              //deklarasi variabel char bernama sortKeyA dengan array 2D dari variabel baris dan kolom
  for(int x=0; x<pKey; x++)                                                                 //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0; y<pKey; y++)                                                               //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel pKey maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      sortKeyA[x][y] = keyA[x][indexSortKey[y]];                                            //menyatakan nilai sortKeyA ke x dan y senilai variabel keyA ke x dan ke indexSortKey ke y
    }
  }

  Serial.println("");                                                                     //mencetak pada serial monitor
  Serial.println("ARRAY SORTING:");                                                       //mencetak pada serial monitor
  /*CETAK PENOMORAN KEYWORD SESUDAH*/
  for(int x=1;x<=pKey;x++)                                                                //memulai kondisi for dengan variabel int bernama x senilai 1 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.print(x);                                                                      //mencetak pada serial monitor
    Serial.print(" ");                                                                    //mencetak pada serial monitor
  }
  Serial.print(" ");                                                                      //mencetak pada serial monitor
  Serial.println("");                                                                     //mencetak pada serial monitor
  /*CETAK KEYWORD SESUDAH SORT*/
  for(int x=0; x<pKey;x++)                                                                //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel pKey maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.print(sortKey[x])+1;                                                          //mencetak pada serial monitor
    Serial.print(" ");                                                                   //mencetak pada serial monitor
  }
   /*CETAK ARRAY KEYWORD*/
  for(int x=0;x<baris;x++)                                                               //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel baris maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    Serial.println("");                                                                 //mencetak pada serial monitor
    for(int y=0;y<kolom;y++)                                                            //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel kolom maka setiap iterasi berikutnya y akan ditambahkan 1
    {
      Serial.print(sortKeyA[x][y]);                                                     //mencetak pada serial monitor
      Serial.print(" ");                                                                //mencetak pada serial monitor
    }
  }

  /*PROSES CIPHERTEXT*/
  for(int x=0; x<kolom;x++)                                                            //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari variabel kolom maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    for(int y=0;y<baris;y++)                                                          //memulai kondisi for dengan variabel int bernama y senilai 0 dan selama y tersebut kurang dari variabel baris maka setiap iterasi berikutnya y akan ditambahkan 1
    {ciphertext+=sortKeyA[y][x];}                                                     //menyatakan nilai variabel ciphertext senilai sortKeyA ke y dan x dan menambahkan 1
  }
  /*CETAK CIPHERTEXT*/
  Serial.println("");                                                                 //mencetak pada serial monitor
  Serial.println("");                                                                 //mencetak pada serial monitor
  Serial.println("HASIL CIPHERTEXT:");                                                //mencetak pada serial monitor
  for(int x=0; x<ciphertext.length();x++)                                             //memulai kondisi for dengan variabel int bernama x senilai 0 dan selama x tersebut kurang dari besar variabel ciphertext maka setiap iterasi berikutnya x akan ditambahkan 1
  {
    if(x>0 && x%baris==0)                                                             //memulai kondisi if bila x lebih besar bersama dengan x mod baris adalah 0 maka
    {Serial.print(' ');}                                                              //mencetak pada serial monitor
    Serial.print(ciphertext[x]);                                                      //mencetak pada serial monitor
  }
}      
                                     
/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                  //inisialisasi loop
{}
