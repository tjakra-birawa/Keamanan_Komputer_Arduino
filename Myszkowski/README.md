## Classical Crypto II

### Myszkowski Cipher

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/myszkowski.gif?raw=true)

Metode serupa dengan **columnar** dan **double columnar transposition** yang bertujuan untuk membaca secara kolom dan berurutan berdarkan kata *keyword*, namun yang membedakan adalah pembacaannya yang dapat menggunakan alfabet yang sama dalam satu *keyword*

| W   | A   | T   | A   | S   | 
| --- | --- | --- | --- | --- | 
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

| L   | O   | L   | I   | P   | 
| --- | --- | --- | --- | --- |
| W   | A   | T   | A   | S   |  
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

| 2   | 3   | 2   | 1   | 4   | 
| --- | --- | --- | --- | --- |
| W   | A   | T   | A   | S   |  
| H   | I   | N   | O   | W   | 
| A   | I   | F   | U   | K   | 
| A   | W   | A   | I   | I   | 
| I   | N   | A   | B   | A   | 

Bila ada kondisi seperti itu maka yang dilakukan adalah membaca dari kolom pertama terlebih dahulu sehingga didapatkan

**AOUIB WHAAI TNFAA AIIWN SWKIA**

Maka ditemukan ciphertextnya
