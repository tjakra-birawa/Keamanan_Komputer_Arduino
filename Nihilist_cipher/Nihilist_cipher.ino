/*VARIABEL GLOBAL */
char matriks[5][5];                                            //mendeklarasikan variabel char bernama matriks 2D array 5x5
String keyword = "WAIFU";                                      //mendeklarasikan variabel string bernama keyword = "WAIFU" (harap gunakan kapital, jangan diubah menjadi huruf biasa)
String plaintext = "HIMEKOINABA";                              //mendeklarasikan variabel string bernama plaintext = "HIMEKOINABA" (harap gunakan kapital, jangan diubah menjadi huruf biasa)
String key = "DEREBAN";                                        //mendeklarasikan variabel string bernama key = "DEREBAN" (harap gunakan kapital, jangan diubah menjadi huruf biasa)
String kbaru,poli_pt,poli_key;                                 //mendeklarasikan variabel string bernama kbaru, polit_pt, dan poli_key,  
int tanda[130],baris,kolom;                                    //mendeklarasikan variabel int bernama tanda sebesar 130 dalam 1D array, baris, dan kolom
int panjang_pt = sizeof(plaintext)-1;                          //mendeklarasikan variabel int bernama panjang_pt sebesar variabel plaintext -1

/*METHOD SETUP*/
void setup()                                                   //inisilasisasi setup
{
  Serial.begin(9600);                                          //memulai komunikasi serial pada 9600 bps
  
  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor
  Serial.print("Enkripsi Nihilist kalimat '");                 //mencetak pada serial monitor
  Serial.print(plaintext);                                     //mencetak pada serial monitor variabel plaintext
  Serial.print("' akan menjadi berikut : ");                   //mencetak pada serial monitor
  Serial.println ("");                                         //mencetak pada serial monitor

  Serial.print("Diketahui keyword -> ");                       //mencetak pada serial monitor
  Serial.print(keyword);                                       //mencetak pada serial monitor variabel keyword
  Serial.println("");                                          //mencetak pada serial monitor
  
  /*PROSES MASUK keyword PADA MATRIKS*/
  tanda['J']=1;                                                //deklarasi tanda huruf 'j' nilainya berupa 1 (kondisi agar ketika penyimpanan nilai akan di skip
  for(int x=0; x < panjang_pt; x++)                            //memulai kondisi for dengan kondisi variabel int x = 0 dan selama x kurang dari variabel panjang_pt, setiap selesai iterasi x akan x++
  {
    if(!tanda[keyword[x]])                                     //memulai kondisi if variabel tanda tidak ada pada variabel keyword ke-x
    {
      tanda[(keyword[x])]=1;                                   //menyatakan variabel tanda pada keyword ke-x senilai 1
      matriks[baris][kolom++]=keyword[x];                      //menyatakan nilai variabel matriks baris dan kolom saat ini bernilai variabel keyword ke-x saat ini dan bila selesai kolom akan di increment
      if(kolom%5==0)                                           //memulai kondisi if nilai variabel kolom mod 5 hasilnya 0
      {
        kolom=0;                                               //menyatakan nilai variabel kolom = 0
        baris++;                                               //menambahkan nilai variabel baris sebesar 1
      }
    }
  }
  
  /*PROSES MEMASUKKAN SISA YANG BELUM MATRIKS*/  
  for(int x='A';x<='Z';x++)                                    //memulai kondisi for dengan kondisi variabel int x = A dan selama x kurang dari Z, setiap selesai iterasi x akan x++
  {
    if(tanda[x]==0)                                            //memulai kondisi if variabel tanda ke-x adalah 0
    {
      matriks[baris][kolom++]=x;                               //menyatakan nilai variabel matriks baris dan kolom saat ini bernilai x saat ini dan bila selesai kolom akan di increment
      tanda[x]=1;                                              //menyatakan nilai tanda ke-x senilai 1
      if(kolom%5==0)                                           //memulai kondisi if nilai variabel kolom mod 5 hasilnya 0
      {
        baris++;                                               //menambahkan nilai variabel baris sebesar 1
        kolom=0;                                               //menyatakan nilai variabel kolom = 0                                       
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
  
  Serial.print("Diketahui plaintext -> ");                      //mencetak pada serial monitor
  Serial.print(plaintext);                                      //mencetak pada serial monitor variabel plaintext
  Serial.println("");                                           //mencetak pada serial monitor
  Serial.print("Diketahui key -> ");                            //mencetak pada serial monitor
  Serial.print(key);                                            //mencetak pada serial monitor variabel key
  Serial.println("");                                           //mencetak pada serial monitor
  
  /*PROSES UNTUK PELENGKAPAN ISI DARI ARRAY KEY AGAR SESUAI DENGAN BESAR ARRAY PLAINTEXT*/
  if (key.length() <= plaintext.length())                       //memulai kondisi if bila panjang variabel key kurang dari panjang variabel plaintext
  {
    for (int x = 0, y = 0; x < plaintext.length(); x++, y++)    //memulai kondisi for dengan variabel int bernama x dan y sebesar 0 dimana selama x kurang dari panjang variabel plaintext, setiap iterasi x dan y akan di increment 
    {
      if (y == key.length())                                    //memulai kondisi if bila y sama dengan panjang variabel key
      {y = 0;}                                                  //menyatakan y senilai 0
      kbaru += key[y];                                          //menyatakan variabel kbaru bernilai variabel key ke-y dan bila selesai kbaru akan di increment
    }
  } else                                                        //jika syarat if tidak memenuhi maka
  {kbaru = key;}                                                //menyatakan variabel kbaru senilai key
  
  Serial.print("Penyesuaian Key baru : ");                     //mencetak pada serial monitor
  Serial.print(kbaru);                                         //mencetak pada serial monitor variabel kbaru
  Serial.println("");                                          //mencetak pada serial monitor

  /*MENENTUKAN LETAK POSISI PLAINTEXT*/
  for (int x = 0; x < plaintext.length(); x++)                 //memulai kondisi for dengan variabel x senilai 0 selama x kurang dari panjang variabel plaintext, setiap iterasi x akan di increment
  {
    for (int y = 0; y < 5; y++)                                //memulai kondisi for dengan variabel y senilai 0 selama y kurang dari  5 , setiap iterasi y akan di increment
    {
      for (int z = 0; z < 5; z++)                              //memulai kondisi for dengan variabel z senilai 0 selama z kurang dari 5 , setiap iterasi z akan di increment
      {
        if (plaintext[x] == 'J')                               //memulai kondisi if bila nilai variabel plaintext ke-x bernilai J
        {
          plaintext[x]--;                                      //mengurangi nilai plaintext ke-x
        }
        if (matriks[y][z] == plaintext[x])                     //memulai kondisi if bila variabel matriks ke y dan z senilai dengan variabel plaintext ke x
        {
          poli_pt += char(y + '0' + 1);                        //menyatakan nilai variabel poli_pt senilai char dari y + 0 + 1 dan bila selesai incerment
          poli_pt += char(z + '0' + 1);                        //menyatakan nilai variabel poli_pt senilai char dari z + 0 + 1 dan bila selesai incerment
        }
      }
    }
  }
  
  /*MENENTUKAN LETAK POSISI KEY BARU*/
  for (int x = 0; x < kbaru.length(); x++)                    //memulai kondisi for dengan variabel x senilai 0 selama x kurang dari panjang variabel kbaru, setiap iterasi x akan di increment
  {
    for (int y = 0; y < 5; y++)                               //memulai kondisi for dengan variabel y senilai 0 selama y kurang dari 5, setiap iterasi y akan di increment
    {
      for (int z = 0; z < 5; z++)                             //memulai kondisi for dengan variabel z senilai 0 selama z kurang dari 5, setiap iterasi z akan di increment
      {
        if (kbaru[x] == 'J')                                  //memulai kondisi if bila nilai variabel kbaru ke-x bernilai J
        {
          kbaru[x]--;                                         //mengurangi nilai kbaru ke-x
        }
        if (matriks[y][z] == kbaru[x])                        //memulai kondisi if bila variabel matriks ke y dan z senilai dengan variabel kbaru ke x
        {
          poli_key += char(y + '0' + 1);                      //menyatakan nilai variabel poli_key senilai char dari y + 0 + 1 dan bila selesai incerment
          poli_key+= char(z + '0' + 1);                       //menyatakan nilai variabel poli_key senilai char dari z + 0 + 1 dan bila selesai incerment
        }
      }
    }
  }
  
  /*MENCETAK HASIL PENJUMLAHAN*/
  int hasil[plaintext.length()];                              //mendeklarasikan variabel int bernama hasil dengan array sepanjang variabel plaintext
  for (int x = 0; x < plaintext.length() * 2; x += 2)         //memulai kondisi for dengan variabel int bernama x senilai 0 selama x kurang dari panjang variabel laintext x 2, setiap iterasi akan ditambahkan 2
  {
    hasil[x / 2] = (((poli_pt[x] - '0') * 10) + (poli_pt[x + 1] - '0')) + (((poli_key[x] - '0') * 10) + (poli_key[x + 1] - '0'));   //menyatakan nilai variabel hasil [x/2] senilai (((poli_pt[x] - '0') * 10) + (poli_pt[x + 1] - '0')) + (((poli_key[x] - '0') * 10) + (poli_key[x + 1] - '0'))
  }
  for (int x = 0; x < plaintext.length(); x++)     //memulai kondisi for dengan variabel x senilai 0 dan selama x kurang dari panjang variabel plaintext, setiap iterasi akan increment
  {
    if (plaintext[x] >= 'A' && plaintext[x] <= 'Z')          //memulai kondisi if bila variabel plaintext ke-x diantara A dan Z
    {
      Serial.print(plaintext[x]);                            //mencetak pada serial monitor variabel plaintext ke-x
      Serial.print("   ");                                   //mencetak pada serial monitor
    }
  }
  
  Serial.println("");                                        //mencetak pada serial monitor
  for (int x = 0; x < plaintext.length() * 2; x += 2)        //memulai kondisi for dengan variabel x senilai 0 dan selama x kurang dari panjang variabel plaintext*2, setiap iterasi akan increment 2
  {
    Serial.print(poli_pt[x]);                                //mencetak pada serial monitor
    Serial.print(poli_pt[x + 1]);                            //mencetak pada serial monitor
    Serial.print("  ");                                      //mencetak pada serial monitor
  } 

  Serial.println("");                                        //mencetak pada serial monitor
  for (int x = 0; x < kbaru.length(); x++)                   //memulai kondisi for dengan variabel x senilai 0 dan selama x kurang dari panjang variabel kbaru, setiap iterasi akan increment
  {
      Serial.print(kbaru[x]);                                //mencetak pada serial monitor
      Serial.print("   ");                                   //mencetak pada serial monitor
  }
  Serial.println("");                                        //mencetak pada serial monitor
  for (int x = 0; x < kbaru.length() * 2; x += 2)            //memulai kondisi for dengan variabel x senilai 0 dan selama x kurang dari panjang variabel kbaru*2, setiap iterasi akan increment 2
  {
    Serial.print(poli_key[x]);                               //mencetak pada serial monitor
    Serial.print(poli_key[x + 1]);                           //mencetak pada serial monitor
    Serial.print("  ");                                      //mencetak pada serial monitor
  }

  Serial.println("");                                        //mencetak pada serial monitor
  Serial.println("");                                        //mencetak pada serial monitor
  for (int x = 0; x < plaintext.length(); x++)               //memulai kondisi for dengan variabel x senilai 0 dan selama x kurang dari panjang variabel plaintext, setiap iterasi akan increment
  {
    Serial.print(hasil[x]);                                  //mencetak pada serial monitor
    Serial.print("  ");                                      //mencetak pada serial monitor
  }    
}

/*METHOD LOOP*/
void loop() 
{}
