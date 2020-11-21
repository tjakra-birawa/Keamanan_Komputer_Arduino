## Classical Crypto II

### Columnar Cipher

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/columnar.gif?raw=true)

Sebuah metode kriptografi yang melakukan enkripsi melalui pengurutan *plaintext* sebagai tabel yang akan digunakan untuk referensi lalu akan menggunakan *keyword* untuk membaca urutan dari tabel tersebut. Pengurutannya akan berdasarkan huruf paling awal yang diberikan.
Sebagai contoh silahkan lihat tabel dibawah ini:
*catatan: PT -> plain text, CT -> cipher text

| W   | A   | T   | A   | S   | 
| --- | --- | --- | --- | --- | 
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

Pada tabel diatas diketahui bahwa *plaintext* yang digunakan adalah “watashi no waifu kawaii inaba”, dan plain text tersebut nantinya akan dimasukkan pada bentuk tabel yang diinginkan, dalam konteks ini berupa 5x5.
Lalu selanjutnya adalah menentukan *keyword* untuk patokan pembacaan, mari sebut saja “kanoj”.

| K   | A   | N   | O   | J   | 
| --- | --- | --- | --- | --- |
| W   | A   | T   | A   | S   |  
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

Maka setelah kita memasukan *keyword* sebagai sumber pembacaan, mari mengurutkan berdasarkan alfabet huruf mana yang lebih awal?
Dari pembacaan tersebut diketahui bahwa urutannya menjadi A,J,K,N, dan O sehingga mari ubah bentuk key tersebut menjadi urutan

| 3   | 1   | 4   | 5   | 2   | 
| --- | --- | --- | --- | --- |
| W   | A   | T   | A   | S   |  
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

Barulah dilakukan sebuah pembacaan dimana dibaca per-kolom, maka dalam hal ini didapatkan hasil baru menjadi

**AIIWN SWKIA WHAAI TNFAA AOUIB**

Kalimat tersebut merupakan hasil enkripsi yang didapatkan dari pembacaan plaintext secara per kolom. Bagaimana jika kata tersebut kurang sehingga tidak terbentuk bentuk tabel kotak 5x5 / 6x6? Maka tabel akan mengisi kekurangan kata tersebut dengan nilai acak atau konstan.
