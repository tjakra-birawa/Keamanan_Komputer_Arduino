### Rivest – Shamir - Adleman

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/rsa.gif?raw=true)

Merupakan sakah satu enkripsi pertama sistem kripto yang banyak digunakan sebagai keamanan data dalam transmisinya. Metode ini menggnakan sebuah key enkripsi publik dan dekripsi yang rahasia, sifatnya adalah asimetrik karena menerapkan sistem faktorisasi dari bilangan prima yang sangat besar sehingga kerap dikenali sebagai one-trap door.
Metodenya ialah dengan rumus sederhana

**M^c = c (mod n)**

Dimana rumus tersebut digunakan sebagai fungsi enkripsi suatu data yang diketahui oleh kedua belah pihak. Akan tetapi Ketika data tersebut telah tiba tentunya perlu di dekripsi, oleh karena itu sang penerima nantinya telah memiliki suatu kunci rahasia untuk menemukan hasil dekripsinya yaitu dengan

**C^d = (m^c)^d = m (mod n)**

Kunci tersebut adalah rahasia karenanya kunci tersebut dapat menyelesaikan permasalahan kompleks dari faktorisasi sebuah bilangan prima.
