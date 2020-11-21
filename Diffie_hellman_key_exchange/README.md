## Key Exchange

### Diffie-Hellman

![](https://github.com/tjakra-birawa/Keamanan_Komputer_Arduino/blob/master/Dokumentasi/diffiehellman.gif?raw=true)

Diffie-hellman adalah key-excahnge dengan rumus

**y = g^x mod p**

Sebagai rumus pengolahannya, angka “p” nantinya diharuskan menggunakan angka prima. Ketika sudah mendapatkan hasil dari mod, maka nantinya ada 2 pihak yang akan menerima sebuah key tertentu, kedepannya dinamakan shared key. Kunci tersebut adalah kunci utama dalam megakses dan angka dari “p” tersendiri tidak boleh diketahui oleh attacker. Key nantinya akan di tukarkan satu sama lain antara kedua belah pihak untuk menverifikasi kebenaran hasilnya. Bila sesuai maka dapat dilakukan komunikasi, konsep ini seperti konsep handshake dalam jaringan komputer.
