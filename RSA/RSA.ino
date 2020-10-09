/* VARIABEL GLOBAL */                                                                                 
int p,q,cipher,puKey,prKey;                                                                  //deklarasi variabel int qlobal p,q,cipher,puKey, dan prKey
int pesan=12;                                                                                //deklarasi variabel int pesan senilai '12' (HARAP ISI PESAN DISINI SECARA MANUAL DAN HANYA BENTUK ANGKA)

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode Alqoritma Key Exchanqe Diffie-Hellman");                             //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 
  
  p = cekPrima();                                                                           //menyatakan nilai variabel p diambil dari hasil method cekPrima
  Serial.print ("Diketahui p = ");                                                          //mencetak pada serial monitor
  Serial.println(p);                                                                        //mencetak pada serial monitor variabel p
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  q = cekPrima();                                                                           //menyatakan nilai variabel q diambil dari hasil method cekPrima
  Serial.print ("Diketahui q = ");                                                          //mencetak pada serial monitor
  Serial.println(q);                                                                        //mencetak pada serial monitor variabel q
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  int modulus = p * q;                                                                      //deklarasi variabel int bernama modulus dari kalkulasi nilai variabel p * q
  int phi = (p - 1)*(q - 1);                                                                //deklarasi variabel int phi bernama phi dari kalkulasi nilai (p-1)*(q-1)
  /*KALKULASI PUBLIC KEY DAN PRIVATE*/
  puKey = publicKey(phi);                                                                   //menyatakan nilai puKey dari kalkulasi method publicKey berdasarkan nilai phi
  prKey = privateKey(puKey, phi);                                                           //menyatakan nilai prKey dari kalkulasi method privateKey berdasrkan nilai puKey dan phi
  Serial.print("Pesan Asli = ");                                                            //mencetak pada serial monitor
  Serial.println(pesan);                                                                    //mencetak pada serial monitor variabel pesan

  /*PROSES RSA ENKRIPSI DAN DEKRIPSI*/
  cipher = enkripsi(pesan, puKey, modulus);                                                 //menyatakan nilai cipher dari method enkripsi berdasarkan nilai pesan, puKey, dan modulus
  Serial.print("Enkrpsi = ");                                                               //mencetak pada serial monitor
  Serial.println(cipher);                                                                   //mencetak pada serial monitor variabel cipher
  pesan = enkripsi(cipher, prKey, modulus);                                                 //menyatakan nilai pesan dari method enkripsi berdasarkan nilai cipher, prKey, dan modulus
  Serial.print("Dekipsi = ");                                                               //mencetak pada serial monitor
  Serial.println(pesan);                                                                    //mencetak pada serial monitor variabel pesan
}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                 //inisialisasi loop
{}

int  cekPrima()                                                                             //inisialisasi cekPrima
{
  int  c;                                                                                   //menyatakan variabel int bernama c
  /*PROSES UNTUK LOOPING CEK PRIMA ATAU BUKAN*/
  while(c == false)                                                                         //menyatakan kondisi while selama c masih false
  {
    Serial.print ("Silahkan masukan anqka:");                                               //mencetak pada serial monitor 
    Serial.println(" ");                                                                    //mencetak pada serial monitor 
    c = Serial.parseInt ();                                                                 //menyatakan nilai c berasal dari input serial berupa anqka 
    if(c<=1)                                                                                //menyatakan kondisi if selama c masih kuranq dari 1
    {
      Serial.print (c);                                                                     //mencetak pada serial monitor  variabel c
      Serial.println(" Bukan anqka prima");                                                 //mencetak pada serial monitor 
      c=false;                                                                              //menyatakan c adalah false
    }
    else                                                                                    //jika tidak
    {
      for(int  i =2; i<c;i++)                                                               //menyatakan kondisi for denqan variabel int i senilai 2, dan selama i kuranq dari c, setelah setiap iterasi i akan diincrement
      {
        if(c%i==0)                                                                          //menyatakan kondisi if apabila c mod i nilainya 0
        {
          Serial.print (c);                                                                 //mencetak pada serial monitor variabel c
          Serial.println(" Bukan anqka prima");                                             //mencetak pada serial monitor 
          c=false;                                                                          //menyatakan nilai c adalah false
        }
      }
    }
  }
  return c;                                                                                 //menqembalikan nilai c
}

int gcd(int a, int b)                                                                       //inisialisasi method gcd dengan nilai int a dan b
{
  int sementara;                                                                            //deklarasi variabel int bernama sementara
  while(1)                                                                                  //memulai kondisi while selama nilai 1
  {
    sementara = a % b;                                                                      //menyatakan nilai sementara adalah a mod b
    if(sementara == 0)                                                                      //memulai kondisi if bila nilai sementara adalah 0
    {return b;}                                                                             //mengembalikan nilai b
    a = b;                                                                                  //menyatakan nilai a adalah b
    b = sementara;                                                                          //menyatakan nilai b adalah sementara
  }
}

int publicKey(int z)                                                                        //inisilasisai method publicKey dari nilai int z
{
  int e = 2;                                                                                //deklarasi variabel int bernama e senilai 2
  while(e < z){                                                                             //memulai kondisi while bila nilai variabel e kurang dari z
    if(gcd(e, z) == 1)                                                                      //memulai kondisi if bila hasil method gcd dari nilai e dan z adalah 1
    {return e;}                                                                             //mengembalikan nilai e
    else                                                                                    //jika tidak
    {e++;}                                                                                  //menambahkan 1 pada nilai e
  }
}

int privateKey(int e, int z)                                                                //inisialisasi method privateKey dari variabel int e dan z
{
  int konstan = 2;                                                                          //mdeklarasi variabel int bernama konstan senilai 2
  while(1)                                                                                  //memulai kondisi while bila nilai 1
  {
    if(((e * konstan) % z) == 1)                                                            //memulai kondisi if bila nilai variabel (e * konstan) mod z adalah 1
    {return konstan;}                                                                       //mengembalikan nilai  konstan
    else                                                                                    //bila tidak
    {konstan++;}                                                                            //menambahkan nilai 1 pada variabel konstan
  }
}

int enkripsi(int m, int e, int n)                                                           //inisialisasi method enkripsi dari variabel int m, e, n
{
  int c;                                                                                    //deklarasi variabel int bernama c
  long pangkat = pow(m, e) + 1;                                                             //deklarasi variabel long bernama pangkat dari hasil pangkat m dan e + 1
  c = pangkat % n;                                                                          //menyatakan nilai c adalah hasil variabel pangkat mod n
  return c;                                                                                 //mengembalikan nilai c
}
