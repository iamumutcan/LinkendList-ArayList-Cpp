# Proje Amacı

ArrayList ve LinkedList  mantığını kavram ve ekle/sil/güncelle fonksiyonları yazıp hangisinin hangi işlemde daha performanslı çalıştığını ölçemek.

`void  LinkedList::olustur()`:  LinkedListi oluşturur ver listenin başına NULL değerini atar.

`void  LinkedList::yazdir()`  : LinkedListe bulunan tüm verileri ekrana yazdırır

`void  LinkedList::ekle(int  yenideger, int  sira)`:  Linkedlist’e gönderilen değeri belirtilen sira numarasına ekleme yapar. Yerine eklendiği verinin adresini kendisinden sonraki veri adresi olarak kaydeder.

`void  LinkedList::guncelle(int  yenideger, int  sira)` : Gönderilen sıra numarasındaki adrese gidip oradaki veriyi gönderilen veri ile günceller.

`void  LinkedList::sil(int  sira)` : Gönderilen sıra numarasındaki adrese ondan sonraki verinin adresini kendisinden önce gelen veride bulunan sonraki adresi ile değiştirip o sıra numarasında bulunan veriyi siler

`void  LinkedList::bosalt()`: Linkedliste bulunun tüm adreslere teker teker gidip verileri siler.

`void  ArrayList::olustur()` : Arraylisti oluşturur ve bas işaretçisine adresini gönderir

`void  ArrayList::yazdir()` : Arraylist içinde bulunan tüm verileri ekrana yazdırır.

`void  ArrayList::ekle(int  deger, int  sira)` : Gönderilen değeri belirtilen sira numarasına ekleme yapar ve önceden orada bulunan veriyi bir sonraki verinin bulunduğu yere taşır bu veri taşıma işlemi son veriye kadar devam eder.

`void  ArrayList::ilkveri()` ; Arraylist oluştuktan sonra sadece diziye toplu şekilde veri eklemesi yapar.

`void  ArrayList::guncelle(int  deger, int  sira)` : Gönderilen değeri belirtilen sira numarasına gidip orada bulunan veri ile değiştirir güncelleme yapar.

`void  ArrayList::sil(int  sira)` : Gönderilen sira numarasındaki veriyi silip silinen veriden sonraki gelen verileri bir önceye taşıyarak silinen verinin yerinin null olarak kalmasını engeller.

`void  ArrayList::bosalt()`: Diziyi boşaltır

# Programın Akışı

Program çalıştığı zaman linkedlist oluşturuyor ardından belirtilen sıralara veri ekleme işlemleri gerçekleşiyor, güncelleme ve silme işlemleri yapıyor son olarakta lindkedlist boşaltılıyor. Eğer istenirse yazdırma fonksiyonu hazırdır main kısmına ekle yapılabilir. Aynı şekilde arraylist oluşturuluyor ve veri ekleme işlemleri yapılıyor güncelleme ve silme işlemleri yapılıyor ve son olarak arraylist boşaltılıyor.

# Performans gözlemi:

100 veri ile ayısında çok farklı performanslar gözleyemedim sayıyı 1000’e ve 10000’e çıkarınca daha farklı sonuçlar gelmeye başladı.

 - **ilk sırada ekleme ve silme işlemleri yapıyorsak** Linkedlist daha performanslı sonuçlar veriyor. Ancak veri güncelleme konusunda
   ArrayList çok daha performanslı çünkü verilen indeks numarasına göre
   işlem yapıyor. Linkedlist tüm verileri, gezdiği için daha maliyetli
   oluyor.
 - **Orta sırada işlem ekleme ve silme yapıyorsak** Arraylist daha performanslı sonuç veriyor. Güncelleme işleminde de aynı şekilde
   Arraylist daha performanslı.
 - **Son sırada işlem Ekleme ve silme yapıyorsak** Arraylist daha performanslı sonuç veriyor. Güncelleme işleminde yine aynı şekilde
   Arraylist daha performanslı. Son sırada işlem yapmak için Linkedlist
   çok maliyetli.

 # **Çıkarım:** 
  Kullanılacak sistemde veri sayısı yüksek ve yeni eklenecek değerler en başa eklenecek ise Linkedlist kullanılmak için uygundur. Ancak sistemde sürekli veri güncelleme işlemleri yapılacak ise ArrayList kullanılmak için uygundur
