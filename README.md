# Pemrograman Kemanan Komputer pada Arduino
Halo warganet Github, berikut saya TjakraP ingin menaruh hasil dokumentasi pembelajaran selama mata kuliah kemanan komputer dan implementasinya dalam bentuk kode program untuk sistem mikrokontroler Arduino.
Mungkin pada beberapa kode program terdapat kesalahan ataupun kurang efisien, tapi silahkan dilihat hasil pemrogramannya ~

## Classical Crypto I

### Caesar Cipher
Sebuah metode keamanan paling sederhana dimana metode ini digunakan dalam bentuk **menggeser huruf** yang inginkan sejumlah [X] menjadi keinginan sang pengirim. Berikut merupakan contoh maksudnya:


|Plaintext | a   | b   | c   | d   | e   | f   | g   |
| ---      | --- | --- | --- | --- | --- | --- | --- |
|Ciphertext| E   | F   | G   | H   | I   | J   | K   |


Array tersebut merupakan patokan utama tabel yang akan kita keluarkan, dan untuk memberikan definisi pada setiap perulangan, diharuskan untuk membuat suatu aturan akan pergeseran sebanyak seberapa besar. Akhir kata Ketika ingin dieksekusi maka diharuskan untuk menuliskan kata yang diinginkan pada file/input serial yang nantinya akan diselesaikan oleh Arduino.

Change-log:

- V0.1 (penerapan caesar cipher melalui variabel)
- V0.2 (penambahan method sehingga tidak semuanya berada di setup)

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

Change-log:

- V0.1 (penerapan caesar cipher melalui variabel)
- V0.2 (penambahan method sehingga tidak semuanya berada di setup)

### Vigerene Cipher
Sebuah metode keamanan selanjutnya dimana mengembangkan lebih lanjut dari caesar cipher, namun menyatakan segala probibilitas yang kemungkinan terjadi dalam satu tabel. Nantinya akan digunakan sebuah key sebagai referensi utama dalam pengecekan setiap kata di plaintext.

![Vigerene Cipher](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Vigen%C3%A8re_square_shading.svg/800px-Vigen%C3%A8re_square_shading.svg.png)

Pada array tetap diatas tersebut nantinya akan disesuaikan berdasarkan key, selanjutnya mari menentukan key

| plaintext    | I   | N   | A   | B   | A   | 
| ---          | --- | --- | --- | --- | --- | 
| key          | H   | I   | M   | E   | K   | 
| ciphertext   | P   | V   | M   | F   | K   |

plaintext nantinya akan dibandingkan dengan key ke berapa yang bersamaan lalu dicek kembali pada tabel diatas posisi berapakah itu dan hurufnya apa? misal pada baris I dan kolom H diketahui persimpangan adalah P.

Change-log:

- V0.1 (penerapan caesar cipher melalui variabel)
- V0.2 (penambahan method sehingga tidak semuanya berada di setup)

### BIFID Cipher
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

Change-log:

- V0.1 (penerapan caesar cipher melalui variabel)
- V0.2 (penambahan method sehingga tidak semuanya berada di setup)

### Nihilist Cipher
lorem ipsum de sulum

## Classical Crypto II

### Columnar Transposition Cipher
lorem ipsum de sulum

### Double Columnar Transposition Cipher
lorem ipsum de sulum

### Myszkowski Cipher
lorem ipsum de sulum

### ADFGVX Cipher
lorem ipsum de sulum

### Playfair Cipher
lorem ipsum de sulum

## Key Exchange

### Diffie-Hellman Key Exchange
lorem ipsum de sulum
