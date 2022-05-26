// VeriYapilariProje.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

using namespace std;

struct Node {
	int deger; //düğümün sayısal değeri
	Node* sonraki; //sonraki düğüme işaretçi
};
struct LinkedList {
	Node* bas; //listenin başlangıç adresini tutar
	void olustur(); //başlangıç için gereken tanımları içerir
	void ekle(int, int); //değer ve sıra numarası alarak ekleme yapar
	void guncelle(int, int);//değer ve sıra numarası alarak günceller
	void sil(int); //sıra numarası alarak silme yapar
	void yazdir(); //liste içeriğini ekrana yazar
	void bosalt(); //listenin bellek alanlarını iade eder
	int sayac; //liste kaç eleman olduğunu tutar
};
int main()
{   //++++++ Linked List işlemleri ++++++++
	LinkedList* l = new LinkedList();
	l->olustur();
	l->yazdir();

	Node* n = new Node();
	n->deger = 0;

	//linked liste x miktarda veri ekleme işlemi yap.
	int EklenecekVeriSayisi = 1000;

	for (int i = 1;i < EklenecekVeriSayisi;i++)
	{
		n = new Node();
		n->deger = i;
		l->ekle(i, 0);
	}

	auto LinkedEkleBegin = std::chrono::high_resolution_clock::now();
	l->ekle(1445, 1008);
	auto LinkedEkleEnd = std::chrono::high_resolution_clock::now();
	auto LinkedEkleElapsed = std::chrono::duration_cast<std::chrono::microseconds>(LinkedEkleEnd - LinkedEkleBegin);

	auto LinkedGuncelleBegin = std::chrono::high_resolution_clock::now();
	l->guncelle(31, 1);
	auto LinkedGuncelleEnd = std::chrono::high_resolution_clock::now();
	auto LinkedGuncelleElapsed = std::chrono::duration_cast<std::chrono::microseconds>(LinkedGuncelleEnd - LinkedGuncelleBegin  );

	auto LinkedSilBegin = std::chrono::high_resolution_clock::now();
	 l->sil(1);
	 auto LinkedSilEnd = std::chrono::high_resolution_clock::now();
	 auto LinkedSilElapsed = std::chrono::duration_cast<std::chrono::microseconds>(LinkedSilEnd - LinkedSilBegin);

	 auto LinkedBosaltBegin = std::chrono::high_resolution_clock::now();
	 l->bosalt();
	 auto LinkedBosaltEnd = std::chrono::high_resolution_clock::now();
	 auto LinkedBosaltElapsed = std::chrono::duration_cast<std::chrono::microseconds>(LinkedBosaltEnd - LinkedBosaltBegin);
	cout << "---------- islemi yapıldı" << endl << endl;
	cout << "Linked List Veri Adeti --> " << EklenecekVeriSayisi << " <--" << endl;
	cout << "Linked List Veri Ekleme suresi => " << LinkedEkleElapsed.count() << " mikro-saniye" << endl;
	cout << "Linked List Veri Guncelleme suresi => " << LinkedGuncelleElapsed.count() << " mikro-saniye" << endl;
	cout << "Linked List Veri Silme suresi => " << LinkedSilElapsed.count() << " mikro-saniye" << endl;
	cout << "Linked List Belekleri Bosaltma  suresi => " << LinkedBosaltElapsed.count() << " mikro-saniye" << endl;
	//----------Linked List işlemleri ----------
}
//++++++ Linked List işlemleri ++++++++
void LinkedList::olustur() {
	bas = NULL;
}
void LinkedList::bosalt() {
	Node* p;
	while (bas)
	{
		p = bas;
		bas = bas->sonraki;
		sayac--;
		delete p;
	}
}
void LinkedList::ekle(int yenideger, int sira)
{
	Node* umutnode = new Node();
	umutnode = new Node();
	if (bas == NULL) {
		umutnode->deger = yenideger;
		bas = umutnode;
		return;
	}
	int dugumSayisi = 0;
	Node* tara;
	tara = bas;
	if (sira == 1)
	{
		umutnode->sonraki = bas;
		umutnode->deger = yenideger;
		bas = umutnode;
		sayac++;
	}
	else
	{
		while (tara)
		{
			dugumSayisi++;
			tara = tara->sonraki;
		}
		if (sira <= dugumSayisi)
		{
			tara = bas;

			for (int i = 1; i < sira; i++) //linkedliste eklenecek sıra için döngü oluşturdum "i < sira-2;" düğümde istenilen sıraya eklemek için
			{
				tara = tara->sonraki;
			}
			umutnode->sonraki = tara->sonraki;
			umutnode->deger = yenideger;
			tara->sonraki = umutnode;
			sayac++;
		}
		else
		{
			tara = bas;

			for (int i = 0; i < dugumSayisi - 2; i++) //linkedliste eklenecek sıra için döngü oluşturdum "i < sira-2;" düğümde istenilen sıraya eklemek için
			{
				tara = tara->sonraki;
			}
			umutnode->sonraki = tara->sonraki;
			umutnode->deger = yenideger;
			tara->sonraki = umutnode;
			cout << "Sira no dugum sirasindan fazla sona ekenmistir." << endl;
			sayac++;
		}
	}

}
void LinkedList::sil(int sira) {
	Node* tara;
	Node* umutnode = new Node();
	umutnode = new Node();
	int sirasayac = 1;
	tara = bas;
	if (sira <= 0)
	{	// 0 dan küçük bir sıra olamaz.
		cout << "Hatali sira numarası!! \n";
		return;
	}
	if (sira == 1)
	{	// eğer ilk sıradaki verinin silinmesi istenirse.
		bas = bas->sonraki;
		delete tara;
		sayac--;
		return;
	}
	while ((tara!=NULL)&&(sirasayac <sira))
	{
		umutnode = tara; // döngü sonlandığı anda veri silinecek veriden bir önceki veriyi tutmak için.
		tara = tara->sonraki; // döngü sonlandığı anda veri silinecek veriyi tutmak için.
	}
	if (sirasayac < sira)
	{	//Verilen sira no çok büyük
		cout << "Silinecek kayit bulunamadı!!\n";
	}
	else {
		// istenilen kayit bulundu
		umutnode->sonraki = tara->sonraki;
		delete tara;
		sayac--;
	}

}
void LinkedList::guncelle(int yenideger, int sira)
{
	Node* umutnode = new Node();
	umutnode = new Node();
	umutnode->deger = yenideger;
	if (bas == NULL) {
		bas = umutnode;
		return;
	}

	int dugumSayisi = 0;
	Node* tara;
	tara = bas;
	while (tara) {
		dugumSayisi++;
		tara = tara->sonraki;
	}
	if (sira <= dugumSayisi)
	{
		tara = bas;

		for (int i = 0; i < sira - 1; i++) //linkedliste eklenecek sıra için döngü oluşturdum "i < sira-2;" düğümde istenilen sıraya eklemek için
		{
			tara = tara->sonraki;
		}
		tara->deger = umutnode->deger;

	}
	
}
void LinkedList::yazdir() {
	Node* tara;
	tara = bas;
	if (!tara) {
		cout << "LinkedList bos!!!" << endl;
		return;
	}
	while (tara) {
		cout << tara->deger << " ";
		tara = tara->sonraki;
	}
	cout << endl;
}
//----------Linked List işlemleri ----------
