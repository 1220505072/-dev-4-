#include <stdio.h>
#include <stdlib.h>

struct element {          //ba�lant�l� listede kullan�lmak �zere bir d���m yap�s�
    int verii;               // Her d���m, bir veri eleman�
    struct element *ilerii;   //bir sonraki d���me i�aret eden bir i�aret�i
};

//ba�l� liste tabanl� bir kuyruk veri yap�s� olu�turmak i�in iki pointer tan�mla
//kuyruk henuz olu�turulmadi null ata
struct element *bas = NULL; //kuyrugun bas�
struct element *son = NULL; //kuyrugun sonu

void enqueue(int verii);  //enqueue fonksiyonu ile yeni bir d���m olu�turup veriyi sona ekle
void dequeue();    //dequeue fonksiyonu ile kuyruktan ilk eleman� sil
void display();   //display fonksiyonu ile kuyruktaki tum elemanlari goruntule

int main() {
    int secim, verii;
    while (1) {
        printf("Lutfen asagidaki islemlerden birini seciniz:\n");
        printf("1. Ekleme\n");
        printf("2. Silme\n");
        printf("3. Goruntuleme\n");
        printf("4. Cikis\n");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
            	printf("Seciminiz: %d", secim);
            	printf("\n");
                printf("Eklemek istediginiz veriyi giriniz: ");
                scanf("%d", &verii);
                enqueue(verii);  ////enqueue fonksiyonu ile yeni bir d���m olu�turup veriyi sona eklemek icin fonksiyonu cagir
                break;
            case 2:
            	printf("Seciminiz: %d", secim);
            	printf("\n");
                dequeue();  //dequeue fonksiyonu ile kuyruktan ilk eleman� silmek icin yukaridan fonksiyonu cagir
                break;
            case 3:
            	printf("Seciminiz: %d", secim);
            	printf("\n");
                display(); ////display fonksiyonu ile kuyruktaki tum elemanlari goruntulemek icin yukaridan fonksiyon cagir
                break;
            case 4:
            	printf("Seciminiz: %d", secim);
            	printf("\n");
                printf("Program sonlandiriliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim yaptiniz!!! \n");
                break;
        }
    }
    return 0;
}

void enqueue(int verii) {  //kuyru�un sonuna yeni bir eleman eklemek i�in kullan�l�r
    struct element *element2 = (struct element*)malloc(sizeof(struct element)); //yeni bir "struct element" tipinde eleman olu�turur ve bu elemana "element2" ad�n� verir.
    element2->verii = verii; //yeni eleman�n veri k�sm�n� "verii" olarak ata
    element2->ilerii = NULL;  //bu  ve ileriye i�aret�isini NULL olarak ayarlar.
    if (bas == NULL) { //e�er kuyruk bo� ise,
        bas = son = element2;   //yeni eleman hem "bas" hem de "son" eleman�d�r. Yani, "bas" ve "son" i�aret�ileri yeni eleman� g�sterir.
    } else { //E�er kuyruk dolu ise, 
        son->ilerii = // element2; yeni eleman sadece "son" eleman�n�n ileriye i�aret�isi olur 
        son = element2; //"son" i�aret�isi de yeni eleman� g�sterir.
    }
    printf("%d basariyla kuyruga eklendi.\n", verii);
}

void dequeue() {  //ba�l� listeden eleman ��karma i�lemini ger�ekle�tirir.
    if (bas == NULL) {  //Fonksiyon, kuyru�un bo� olup olmad���n� kontrol eder 
        printf("Kuyruk bos!\n"); //bo� ise bir hata mesaj� yazd�r�r 
        return; //fonksiyondan ��kar.
    }
    struct element* gezgin = bas;  //�nce kuyruktaki ilk eleman�n verisini ge�ici bir de�i�kene kaydeder.
    bas = bas->ilerii;  //ilk eleman�n i�aret etti�i d���m� siler ve ilk eleman� bir sonraki eleman yapar.
    if (bas == NULL) { //E�er son eleman siliniyorsa
        son = NULL; //son d���m� de NULL olarak ayarlar.
    }
    printf("%d kuyruktan silindi.\n", gezgin->verii); //silinen eleman�n verisini ve bir mesaj� yazd�r�r 
    free(gezgin); //bellekteki ge�ici de�i�keni serbest b�rak�r.
}

void display() { //kuyruktaki elemanlar� ekrana yazd�rmak i�in kullan
    if (bas == NULL) {  //kuyru�un bo� olup olmad���n� kontrol eder. E�er kuyruk bo� ise
        printf("Kuyruk bos!\n");  //ekrana "Kuyruk bos!" mesaj�n� yazd�r�r 
        return; //fonksiyondan ��kar.
    }
    printf("Kuyruk: "); //Kuyruk bo� de�ilse, "Kuyruk: " mesaj�n� yazd�r�r 
    // // d�ng� kullanarak kuyruktaki her eleman�n verisini ekrana yazd�r�r. D�ng�, kuyru�un ba��ndan (bas) ba�layarak, her bir eleman�n "ilerii" i�aret�isi yard�m�yla bir sonraki elemana ilerler.
    struct element *gezgin = bas;
    while (gezgin != NULL) {
        printf("%d ", gezgin->verii);
        gezgin = gezgin->ilerii;
    }
    printf("\n");
}

