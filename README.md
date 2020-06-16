# Pemrograman Kemanan Komputer pada Arduino
Halo warganet Github, berikut saya Tjakra ingin menaruh hasil dokumentasi pembelajaran selama mata kuliah kemanan komputer dan implementasinya dalam bentuk kode program untuk sistem mikrokontroler Arduino.
Mungkin pada beberapa kode program terdapat kesalahan ataupun kurang efisien, tapi silahkan dilihat hasil pemrogramannya ~

## Classical Crypto I

### Caesar Cipher
Sebuah metode keamanan paling sederhana dimana metode ini digunakan dalam bentuk **menggeser huruf** yang inginkan sejumlah [X] menjadi keinginan sang pengirim. Berikut merupakan contoh maksudnya:


PT | a | b | c | d | e | f | g | h | i | j | k | l

CT | E | F | G | H | I | J | K | L | M | N | O | P

_PT: Plaintext, CT: Ciphertext_

Array tersebut merupakan patokan utama tabel yang akan kita keluarkan, dan untuk memberikan definisi pada setiap perulangan, diharuskan untuk membuat suatu aturan akan pergeseran sebanyak seberapa besar. Akhir kata Ketika ingin dieksekusi maka diharuskan untuk menuliskan kata yang diinginkan pada file/input serial yang nantinya akan diselesaikan oleh Arduino.

Change-log:

- V0.01 (penerapan caesar cipher melalui variabel)

# Polybius Cipher
Sebuah metode keamanan paling sederhana dimana metode ini digunakan dalam bentuk menggeser huruf yang inginkan sejumlah [X] menjadi keinginan sang pengirim. Dalam hal ini bisa berupa penggeseran sebesar 1 hingga tak terhingga.
