## Classical Crypto I
### BIFID Cipher
![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/bifid.gif?raw=true)

Sebuah metode keamanan dimana mengembangkan konsep Polybius cipher dengan menggabungkan sesama baris dan baris ataupun baris dan kolom kemudian dikonversikan kembali dalam bentuk huruf baru berdasarkan nilai tersebut.

|     | 1   | 2   | 3   | 4   | 5   | 
| --- | --- | --- | --- | --- | --- | 
| 1   | A   | B   | C   | D   | E   | 
| 2   | F   | G   | H   | I/J | K   | 
| 3   | L   | M   | N   | O   | P   | 
| 4   | Q   | R   | S   | T   | U   | 
| 5   | V   | W   | X   | Y   | Z   | 

Diketahui patokan array, maka selanjutnya tentukan plaintext dan mencari letak baris dan kolom.

| plaintext    | I   | N   | A   | B   | A   | 
| ---          | --- | --- | --- | --- | --- | 
| baris        | 2   | 3   | 1   | 1   | 1   | 
| kolom        | 4   | 3   | 1   | 2   | 1   |

Selanjutnya bacalah angka tersebut mulai pada baris pertama hingga akhir baris secara perlahan seperi 23, 11, 14, ...
Diketahui nantinya akan terbentuk cipher baru

| baris + kolom| 23  | 11  | 14  | 31  | 21  | 
| ---          | --- | --- | --- | --- | --- | 
| ciphertext   | H   | A   | D   | L   | F   |
