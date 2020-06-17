/* VARIABEL GLOBAL */
int ascii[130], baris, kolom,sementara;                       //membuat variabel global int bernama ascii, baris, dan kolom
char plaintext[]= {"HIMEKOINABA"};                            //membuat variabel global char bernama plaintext (hanya bisa huruf biasa, bila kapital sesuaikan kembali kodingan bawahnya, gantilah "a" menjadi "A" bila ingin merubah)
char CT;                                                      //membuat variabel global char bernama CT
char matriks[5][5];                                           //membuat variabel global char bernama matriks sejumlah array 2D 5x5
char plaintext1[2][sizeof(plaintext)];                        //membuat variabel global char bernama plaintext1 sejumlah array 2D 2 x besar variabel plaintext
char plaintext2[sizeof(plaintext)*2];                         //membuat variabel global char bernama plaintext2 sejumlah array 1D dengan besar 2 kali variabel plaintext
int besar1 = sizeof(plaintext)-1;                             //membuat variabel global int bernama besar1 sebesar variabel plaintext - 1
int besar2 = sizeof(plaintext)*2;                             //membuat variabel global int bernama besar1 sebesar variabel plaintext *2

/*INISILASIASI SETUP*/
void setup()                                                  //memulai method setup
{
  Serial.begin(9600);                                         //memulai komunikasi serial pada 9600 bps
  
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
  
  Serial.println("");                                           //mencetak pada serial monitor
  /*PROSES PEMBEDAHAN MENJADI ARRAY 2D*/
  for (int x = 0; x < besar1; x++)                              //memulai kondisi for dengan variabel int bernama x sebesar 0 dan selama kurang dari variabel besar1, setiap iterasi akan ditambahkan
  {
    Serial.print(plaintext[x]);                                 //mencetak pada serial monitor variabel plaintext ke-x
    Serial.print(" ");                                          //mencetak pada serial monitor 
    for (int y = 0; y < 5; y++)                                 //memulai kondisi for dengan variabel int bernama y sebesar 0 dan selama kurang dari 5, setiap iterasi akan ditambahkan 1
    {
      for (int z = 0; z < 5; z++)                               //memulai kondisi for dengan variabel int bernama z sebesar 0 dan selama kurang dari 5, setiap iterasi akan ditambahkan
      {
        if (matriks[y][z] == plaintext[x])                      //memulai kondisi if saat variabel matriks ke y dan z sama dengan variabel plaintext ke x
        {
          plaintext1[0][x] = y;                                 //menyatakan nilai variabel plaintext1 ke-0 dan x sebesar y
          plaintext1[1][x] = z;                                 //menyatakan nilai variabel plaintext1 ke-1 dan x sebesar z
        }
      }
    }
  }
  
  /*MENCETAK HASIL ARRAY*/
  for (int x = 0; x < 2; x++)                                   //memulai kondisi for dengan variabel int x sebesar 0 dan selama kurang dari 2, setiap iterasi akan ditambahkan 1
  {
    Serial.println("");                                         //mencetak pada serial monitor 
    for (int y = 0; y <  besar1; y++)                           //memulai kondisi for dengan variabel int y sebesar 0 dan selama kurang dari variabel besar1, setiap iterasi akan ditambahkan 1
    {
      Serial.print(plaintext1[x][y] + 1);                       //mencetak pada serial monitor variabel plaintex ke x dan y+1
      Serial.print(" ");                                        //mencetak pada serial monitor 
    }
  }
  
  sementara=0;
  /*MEMINDAHKAN ARRAY 2D KE 1D*/
  for (int x = 0; x < 2; x++)                                   //memulai kondisi for dengan variabel int x sebesar 0 dan selama kurang dari 2, setiap iterasi akan ditambahkan
  {
    for (int y = 0; y < besar1 ; y++)                           //memulai kondisi for dengan variabel int y sebesar 0 dan selama kurang dari variabel besar1, setiap iterasi akan ditambahkan 1
    {
      plaintext2[sementara++] = plaintext1[x][y];               //menyatakan nilai plaintext2 ke sementara sebesar plaintext ke x dan y dan bila selesai sementara akan ditambahkan 1
    }
  }

  /*PROSES PENCETAKAN NILAI ANGKA PADA ARRAY 1D*/
  for (int z = 0; z < besar2; z = z + 2)                        //memulai kondisi for dengan variabel z sebesar 0 dans elama kurang dari variabel besar2, setiap iterasi akan z sebelumnya + 2
  {
    if(z==0)                                                    //memulai kondisi if bila z adalah 0
    {Serial.println("");}                                       //mencetak pada serial monitor 
    int x = plaintext2[z];                                      //mendeklarasikan variabel int bernama x dari nilai plaintext2 ke z
    int y = plaintext2[z+1];                                    //mendeklarasikan variabel int bernama y dari nilai plaintext2 ke z+1             
    CT = matriks[x][y];                                         //menyatakan nilai variabel CT sebesar variabel matriks ke-x dan y
    Serial.print(CT);                                           //mencetak pada serial monitor variabel CT
    CT++;                                                       //menambahkan variabel CT dengan 1
  }
}

/*INISILASIASI LOOP*/
void loop()
{}
