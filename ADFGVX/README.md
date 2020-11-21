## Classical Crypto Ii

### ADFGVX Cipher

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/adfgvx.gif?raw=true)

Konsep dasarnya serupa kembali dengan **columnar**, **double columnar**, dan **MYSZKOWSKI**, namun yang membedakan bila melihat ini maka konsepnya seperti gabungan **bifid** ataupun polybius namun dengan kata **ADFGVX** yang memungkinkan 36 jenis kombinasi sehingga memungkinkan juga adanya angka memasuki alfabet dan tidak adanya penggabungan alfabet satu sama lain.
Tabel ADFGVX adalah tetap dan tidak akan berubah sehingga pada awalan hanya tinggal memasukan plaintext dan mencocokannya dengan data tabel saat itu dan selanjutnya serupa pembacaannya melalui keyword di kolom.


|     | A   | D   | F   | G   | V   | X   |
| --- | --- | --- | --- | --- | --- | --- |
| A   | 8   | P   | 3   | D   | 1   | N   |
| D   | L   | T   | 4   | O   | A   | H   |
| F   | 7   | K   | B   | C   | 5   | Z   |
| G   | J   | U   | 6   | W   | G   | M   |
| V   | X   | S   | V   | I   | R   | 2   |
| X   | 9   | E   | Y   | 0   | F   | Q   |

lalu dapat kita lihat jika posisi kata berikut akan seperti ini:

H = **DX** |
I = **VG** |
HIMEKOINABA = **DXVGGXXDFDDGVGAXDVFFDV**

Dari tabel tersebut masukkanlah plaintext dan kemudian *plaintext* tersebut akan mendapatkan kata baru yang berupa kalimat dari ADFGVX

| R   | H   | I   | E   | N   |
| --- | --- | --- | --- | --- |
| 5   | 2   | 3   | 1   | 4   |
| F   | D   | D   | V   | V   |
| G   | V   | D   | X   | D   | 
| V   | V   | G   | G   | V   | 
| G   | D   | A   | D   | X   | 
| X   | D   | D   | A   | G   | 
| X   |     |     |     |     | 

Kalimat tersebut disusun kembali menjadi tabel 5x5 dengan tambahan keyword yang diinginkan, dalam hal ini RHIEN dan urutkanlah berdasarkan posisi alfabet keyword, dan bacalah sesuai urutan pertama kolomnya.
