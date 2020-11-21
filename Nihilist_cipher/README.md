## Classical Crypto I

### Nihilist Cipher

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/nihilist.gif?raw=true)

Metode kriptografi dengan memadukan seluruh konsep yang telah dijelaskan sebelumnya mulai dari **caesar** hingga **bifid**. Akan tetapi konsep nihilis sangatlah berbeda karena sang pengaman akan menaruh suatu kata atau huruf secara acak diawal tabel yang kemudian akan dilanjutkan oleh seri huruf alfabet yang belum ada. Sehingga tabel yang nantinya dibuat akan berdasarkan keinginan sang pengaman.
Untuk melihat contoh mari lihat tabel berikut:
*catatan: PT -> plain text, CT -> cipher text, pembacaan baris dan kolom (angka-nya)

|     | 1   | 2   | 3   | 4   | 5   | 
| --- | --- | --- | --- | --- | --- | 
| 1   | I   | N   | A   | B   | H   | 
| 2   | C   | D   | E   | F   | G   | 
| 3   | J/K | L   | M   | O   | P   | 
| 4   | Q   | R   | S   | T   | U   | 
| 5   | V   | W   | X   | Y   | Z   | 

Pada tabel diatas saya telah menuliskan kata pembuka di baris 1 hingga kolom 5 “INABH”, selanjutnya saya menaruh posisi J/K serupa pada B/K = 1/3.  Setelah menentukan tabel untuk referensi utama, mari menentukan plain text dan key yang diperlukan sebelum mendapatkan cipher text.

| plaintext    | I   | N   | A   | B   | A   | N   | S   | U   | K   | I   |
| ---          | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |  
| key          | W   | A   | I   | F   | U   |     |     |     |     |     | 

Setelah menetukan plain text dan key, maka lakukanlah pelokasian masing-masing huruf berdasarkan tabel yang menjadi rujukan.

| plaintext    | 11   | 12   | 11   | 14   | 11   | 12   | 43   | 45   | 31   | 11   |
| ---          | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  |  
| key          | 52   | 13   | 11   | 24   | 45   | 52   | 13   | 11   | 24   | 45   | 

Baik setelah mengubah bentuk ke angka, selanjutnya ialah proses penjumlahan antara plain text dan key masing-masing huruf. Dan akan didapatkan hasil baru

| plaintext    | 11   | 12   | 11   | 14   | 11   | 12   | 43   | 45   | 31   | 11   |
| ---          | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  |  
| key          | 52   | 13   | 11   | 24   | 45   | 52   | 13   | 11   | 24   | 45   | 
| ciphertext   | 63   | 25   | 22   | 38   | 56   | 64   | 56   | 56   | 55   | 56   | 

Dari hasil tersebut telah dienkripsi ke dalam bentuk baru berupa angka yang tidak berpola khusus selain berdasarkan key yang telah ditentukan.
