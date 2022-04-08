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
	void nekle(Node*, int); //değer ve sıra numarası alarak ekleme yapar
	void sonaEkle(Node*);
	void basaEkle(Node*);
	void ortayaEkle(Node*);
	int sayac; //liste kaç eleman olduğunu tutar
};
int main()
{


	LinkedList* l = new LinkedList();
	l->olustur();
	l->yazdir();

	Node* n = new Node();
	n->deger = 0;

	//linked liste x miktarda veri ekleme işlemi yap.
	int EklenecekVeriSayisi = 100;

	for (int i = 1;i < EklenecekVeriSayisi;i++)
	{
		n = new Node();
		n->deger = i;
		l->ekle(i, 0);
	}
	//l->yazdir();

	auto LinkedEkleBegin = std::chrono::high_resolution_clock::now();
	l->ekle(1445, 8715);
	auto LinkedEkleEnd = std::chrono::high_resolution_clock::now();
	auto LinkedEkleElapsed = std::chrono::duration_cast<std::chrono::microseconds>(LinkedEkleEnd - LinkedEkleBegin);
	// l->yazdir();
	cout << "ekleme islemi yapildi" << endl;


	auto LinkedGuncelleBegin = std::chrono::high_resolution_clock::now();
	l->guncelle(31, 1);
	auto LinkedGuncelleEnd = std::chrono::high_resolution_clock::now();
	auto LinkedGuncelleElapsed = std::chrono::duration_cast<std::chrono::microseconds>(LinkedGuncelleEnd - LinkedGuncelleBegin  );
	
	// l->yazdir();
	cout << "güncelleme islemi yapıldı" << endl;
	//l->yazdir(); 
	cout << "---------- islemi yapıldı" << endl << endl;
	cout << "Linked List Veri Adeti --> " << EklenecekVeriSayisi << " <--" << endl;
	cout << "Linked List Veri Ekleme suresi => " << LinkedEkleElapsed.count() << " mikro-saniye" << endl;
	cout << "Linked List Veri Guncelleme suresi => " << LinkedGuncelleElapsed.count() << " mikro-saniye" << endl;

}

void LinkedList::olustur() {
	bas = NULL;
}
void LinkedList::ekle(int yenideger, int sira)
{
	Node* umutnode = new Node();
	umutnode = new Node();
	if (bas == NULL) {
		umutnode->deger = yenideger;
		bas = umutnode;
		cout << " test1 \t";
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
		}
	}

}
void LinkedList::sil(int sira) {

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


void LinkedList::nekle(Node* yenideger, int sira)
{
	if (bas == NULL) {
		bas = yenideger;
		return;
	}

	int dugumSayisi = 0;
	Node* tara;
	tara = bas;
	if (sira == 1)
	{
		yenideger->sonraki = bas;
		bas = yenideger;

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

			for (int i = 0; i < sira - 2; i++) //linkedliste eklenecek sıra için döngü oluşturdum "i < sira-2;" düğümde istenilen sıraya eklemek için
			{
				tara = tara->sonraki;
			}
			yenideger->sonraki = tara->sonraki;
			tara->sonraki = yenideger;
		}
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