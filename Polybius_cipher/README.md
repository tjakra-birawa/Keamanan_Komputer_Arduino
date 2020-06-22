## Classical Crypto I
### Polybius Cipher
Sebuah metode keamanan sederhana dimana menggunakan enkripsi dari tabel 5x5 yang berisikan huruf A-Z. Metode ini nantinya akan membaca letak baris dan kolom setiap huruf dari plaintext, dimana untuk tabel tersendiri dapat dibuat berdasarkan keinginan pengguna karena nantinya ada 1 huruf yang harus digabung.

|     | 1   | 2   | 3   | 4   | 5   | 
| --- | --- | --- | --- | --- | --- | 
| 1   | A   | B   | C   | D   | E   | 
| 2   | F   | G   | H   | I/J | K   | 
| 3   | L   | M   | N   | O   | P   | 
| 4   | Q   | R   | S   | T   | U   | 
| 5   | V   | W   | X   | Y   | Z   | 

Diketahui patokan array kita akan menyamakan posisi huruf i dan j dalam satu kolom dan baris. Setelah mendapatkan plaintext, nantinya akan terjadi perulangan secara terus menerus untuk menemukan satu kata yang sama di tabel tersebut dan bila ditemukan maka akan dimasukkan nilai baris dan kolom untuk di cetak. Berikut adalah bentuk ciphertext.

| plaintext    | I   | N   | A   | B   | A   | 
| ---          | --- | --- | --- | --- | --- | 
| ciphertext   | 24  | 33  | 11  | 14  | 11  | 
