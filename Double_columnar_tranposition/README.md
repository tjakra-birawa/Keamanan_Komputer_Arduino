## Classical Crypto II

### ADFGVX Cipher

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/adfgvx.gif?raw=true)

Sama seperti **columnar transposition** sebelumnya, kali ini tapi diulangi kembali sistem sebelumnya dimana pertama mencari kata *plaintext* apa yang diinginkan lalu mencari *keyword* yang diinginkan dan mengurutkannya berdasarkan alfabet. Terakhir ia akan mengulang kembali percobaan diatas tapi hasil dari *ciphertext*nya lah yang menjadi *plaintext* dan selanjutnya pilihlah *keyword* baru sebagai rujukan.

| W   | A   | T   | A   | S   | 
| --- | --- | --- | --- | --- | 
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

| K   | A   | N   | O   | J   | 
| --- | --- | --- | --- | --- |
| W   | A   | T   | A   | S   |  
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

| 3   | 1   | 4   | 5   | 2   | 
| --- | --- | --- | --- | --- |
| W   | A   | T   | A   | S   |  
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

Setelah dilakukan percobaan awal. Mari menentukan tabel barunya yakni **AIIWN SWKIA WHAAI TNFAA AOUIB**

| A   | I   | I   | W   | N   | 
| --- | --- | --- | --- | --- | 
| S   | W   | K   | I   | A   | 
| W   | H   | A   | A   | I   | 
| T   | N   | F   | A   | A   | 
| A   | O   | U   | I   | B   | 

Dari *ciphertext* menjadi *plaintext*, maka selantnya ialah menentukan *keyword* baru misal LONTE

| L   | O   | N   | T   | E   | 
| --- | --- | --- | --- | --- | 
| A   | I   | I   | W   | N   | 
| S   | W   | K   | I   | A   | 
| W   | H   | A   | A   | I   | 
| T   | N   | F   | A   | A   | 
| A   | O   | U   | I   | B   | 

Sana seperti sebelumnya, urutkanlah berdasarkan alfabet

| 2   | 4   | 3   | 5   | 1   | 
| --- | --- | --- | --- | --- | 
| A   | I   | I   | W   | N   | 
| S   | W   | K   | I   | A   | 
| W   | H   | A   | A   | I   | 
| T   | N   | F   | A   | A   | 
| A   | O   | U   | I   | B   | 

Kemudian bacalah kembali sesuai urutan baru berdarkan pembacaan kolom sebagai berikut:

**NAIAB ASWTA IKAFU IWHNO WIAAI**

Maka ditemukanlah cipher text terbaru
