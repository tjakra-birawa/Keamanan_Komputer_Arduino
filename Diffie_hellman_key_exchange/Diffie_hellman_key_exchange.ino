/* VARIABEL GLOBAL */
/* PENJELASAN VARIABEL
 * g  -> PUBLIC KEY PROGRAM
 * p  -> MODULO BERAPA
 * xA -> PRIVATE KEY MILIK A (TIDAK BOLEH DIKETAHUI SIAPAPUN)
 * xB -> PRIVATE KEY MILIK B (TIDAK BOLEH DIKETAHUI SIAPAPUN)
 * yA -> HASIL DARI KOMPUTASI Y=G^A MOD P DAN SEKARANG DIMILIKI OLEH A
 * yB -> HASIL DARI KOMPUTASI Y=G^B MOD P DAN SEKARANG DIMILIKI OLEH B
 * yHASIL1 -> SHARED KEY A SETELAH EXCHANGE yB
 * yHASIL2 -> SHARED KEY B SETELAH EXCHANGE yA
 * HARAP DIBACA TERLEBIH DAHULU */
int  xA,xB;                                                                                 //deklarasi variabel int global bernama xA dan xB
int  p,g,yA,yB,yHasil1,yHasil2;                                                             //deklarasi variabel int global p,g,yA,yB,yHasil1,yHasil2

/* METHOD BOOTING AWAL */
void setup()                                                                                //inisialisasi setup
{
  Serial.begin(9600);                                                                       //memulai komunikasi serial pada 9600 bps

  /*COPYRIGHT*/
  Serial.println ("Cakra Bhirawa - Keamanan Komputer SP A");                                //mencetak pada serial monitor
  Serial.println ("");                                                                      //mencetak pada serial monitor
  Serial.print("Metode Algoritma Key Exchange Diffie-Hellman");                             //mencetak pada serial monitor
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 
  
  p = cekPrima();                                                                           //menyatakan nilai variabel p diambil dari hasil method cekPrima
  Serial.print ("Diketahui p = ");                                                          //mencetak pada serial monitor
  Serial.println(p);                                                                        //mencetak pada serial monitor variabel p
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  g = cekPrima();                                                                           //menyatakan nilai variabel g diambil dari hasil method cekPrima
  Serial.print ("Diketahui g = ");                                                          //mencetak pada serial monitor
  Serial.println(g);                                                                        //mencetak pada serial monitor variabel g
  Serial.println("");                                                                       //mencetak pada serial monitor 
  Serial.println("");                                                                       //mencetak pada serial monitor 

  xA=4;                                                                                     //menyatakan nilai variabel xA adalah 4
  xB=6;                                                                                     //menyatakan nilai variabel xB adalah 6

  Serial.println("NILAI RANDOM SAAT INI:");                                                 //mencetak pada serial monitor 
  Serial.print ("Nilai Xa = ");                                                             //mencetak pada serial monitor 
  Serial.println(xA);                                                                       //mencetak pada serial monitor variabel xA
  Serial.print ("Nilai Xb = ");                                                             //mencetak pada serial monitor 
  Serial.println(xB);                                                                       //mencetak pada serial monitor variabel xB
  Serial.println("");                                                                       //mencetak pada serial monitor 

  Serial.print (g);                                                                         //mencetak pada serial monitor variabel g
  Serial.print ("^");                                                                       //mencetak pada serial monitor 
  Serial.print (xA);                                                                        //mencetak pada serial monitor variabel xA
  Serial.print (" mod ");                                                                   //mencetak pada serial monitor 
  Serial.print (p);                                                                         //mencetak pada serial monitor variabel p
  Serial.print (" = ");                                                                     //mencetak pada serial monitor 
  yA=proses(g,xA,p);                                                                        //menyatakan nilai yA berasal dari kalkulasi method proses dengan variabel g,xA,p
  Serial.println(yA);                                                                       //mencetak pada serial monitor variabel yA
  
  Serial.print (g);                                                                         //mencetak pada serial monitor variabel g
  Serial.print ("^");                                                                       //mencetak pada serial monitor 
  Serial.print (xB);                                                                        //mencetak pada serial monitor variabel xB
  Serial.print (" mod ");                                                                   //mencetak pada serial monitor 
  Serial.print (p);                                                                         //mencetak pada serial monitor variabel p
  Serial.print (" = ");                                                                     //mencetak pada serial monitor 
  yB=proses(g,xB,p);                                                                        //menyatakan nilai yB berasal dari kalkulasi method proses dengan variabel g, xB, p
  Serial.println(yB);                                                                       //mencetak pada serial monitor variabel yB
  
  Serial.println("Saatnya bertukar antara keduanya");                                        //mencetak pada serial monitor 
  Serial.print (yB);                                                                         //mencetak pada serial monitor variabel yB
  Serial.print ("^");                                                                        //mencetak pada serial monitor 
  Serial.print (xA);                                                                         //mencetak pada serial monitor variabel xA
  Serial.print (" mod ");                                                                    //mencetak pada serial monitor 
  Serial.print (p);                                                                          //mencetak pada serial monitor variabel p
  Serial.print (" = ");                                                                      //mencetak pada serial monitor 
  yHasil1=proses(yB,xA,p);                                                                   //menyatakan nilai yHassil1 berasal dari komputasi dari variabel yB,xA,p
  Serial.println(yHasil1);                                                                   //mencetak pada serial monitor variabel yHasil1

  Serial.print (yA);                                                                         //mencetak pada serial monitor variabel yA
  Serial.print ("^");                                                                        //mencetak pada serial monitor 
  Serial.print (xB);                                                                         //mencetak pada serial monitor variabel xB
  Serial.print (" mod ");                                                                    //mencetak pada serial monitor 
  Serial.print (p);                                                                          //mencetak pada serial monitor variabel p
  Serial.print (" = ");                                                                      //mencetak pada serial monitor 
  yHasil2=proses(yA,xB,p);                                                                   //menyatakan nilai yHasil2 berasal dari komputasi method proses dengan variabel yA, xB, p
  Serial.println(yHasil2);                                                                   //mencetak pada serial monitor variabel yHasil2
}                                           

/* METHOD PERULANGAN SELAMA AKTIF */
void loop()                                                                                  //inisialisasi loop
{}

int  cekPrima()                                                                             //inisialisasi cekPrima
{
  int  c;                                                                                   //menyatakan variabel int bernama c
  /*PROSES UNTUK LOOPING CEK PRIMA ATAU BUKAN*/
  while(c == false)                                                                         //menyatakan kondisi while selama c masih false
  {
    Serial.print ("Silahkan masukan angka:");                                               //mencetak pada serial monitor 
    Serial.println(" ");                                                                    //mencetak pada serial monitor 
    c = Serial.parseInt ();                                                                 //menyatakan nilai c berasal dari input serial berupa angka 
    if(c<=1)                                                                                //menyatakan kondisi if selama c masih kurang dari 1
    {
      Serial.print (c);                                                                     //mencetak pada serial monitor  variabel c
      Serial.println(" Bukan angka prima");                                                 //mencetak pada serial monitor 
      c=false;                                                                              //menyatakan c adalah false
    }
    else                                                                                    //jika tidak
    {
      for(int  i =2; i<c;i++)                                                               //menyatakan kondisi for dengan variabel int i senilai 2, dan selama i kurang dari c, setelah setiap iterasi i akan diincrement
      {
        if(c%i==0)                                                                          //menyatakan kondisi if apabila c mod i nilainya 0
        {
          Serial.print (c);                                                                 //mencetak pada serial monitor variabel c
          Serial.println(" Bukan angka prima");                                             //mencetak pada serial monitor 
          c=false;                                                                          //menyatakan nilai c adalah false
        }
      }
    }
  }
  return c;                                                                                 //mengembalikan nilai c
}

int  proses(int  x, int  y, int   z)                                                        //inisialisasi proses dengan variabel int x,y,z
{
  int  hasil;                                                                               //menyatakan variabel int bernama hasil
  long  pangkat = pow(x,y)+0.5;                                                             //menyatakan variabel long bernama pangkat dengan nilai dari pangkat x^y dan ditambahkan 0.5
  hasil=pangkat%z;                                                                          //menyatakan nilai hasil berasal dari hasil variabel pangkat mod z
  return hasil;                                                                             //mengembalikan nilai hasil
}
