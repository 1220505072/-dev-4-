#include <stdio.h>
#include <stdlib.h>

struct element {          //baðlantýlý listede kullanýlmak üzere bir düðüm yapýsý
    int verii;               // Her düðüm, bir veri elemaný
    struct element *ilerii;   //bir sonraki düðüme iþaret eden bir iþaretçi
};

//baðlý liste tabanlý bir kuyruk veri yapýsý oluþturmak için iki pointer tanýmla
//kuyruk henuz oluþturulmadi null ata
struct element *bas = NULL; //kuyrugun basý
struct element *son = NULL; //kuyrugun sonu

void enqueue(int verii);  //enqueue fonksiyonu ile yeni bir düðüm oluþturup veriyi sona ekle
void dequeue();    //dequeue fonksiyonu ile kuyruktan ilk elemaný sil
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
                enqueue(verii);  ////enqueue fonksiyonu ile yeni bir düðüm oluþturup veriyi sona eklemek icin fonksiyonu cagir
                break;
            case 2:
            	printf("Seciminiz: %d", secim);
            	printf("\n");
                dequeue();  //dequeue fonksiyonu ile kuyruktan ilk elemaný silmek icin yukaridan fonksiyonu cagir
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

void enqueue(int verii) {  //kuyruðun sonuna yeni bir eleman eklemek için kullanýlýr
    struct element *element2 = (struct element*)malloc(sizeof(struct element)); //yeni bir "struct element" tipinde eleman oluþturur ve bu elemana "element2" adýný verir.
    element2->verii = verii; //yeni elemanýn veri kýsmýný "verii" olarak ata
    element2->ilerii = NULL;  //bu  ve ileriye iþaretçisini NULL olarak ayarlar.
    if (bas == NULL) { //eðer kuyruk boþ ise,
        bas = son = element2;   //yeni eleman hem "bas" hem de "son" elemanýdýr. Yani, "bas" ve "son" iþaretçileri yeni elemaný gösterir.
    } else { //Eðer kuyruk dolu ise, 
        son->ilerii = // element2; yeni eleman sadece "son" elemanýnýn ileriye iþaretçisi olur 
        son = element2; //"son" iþaretçisi de yeni elemaný gösterir.
    }
    printf("%d basariyla kuyruga eklendi.\n", verii);
}

void dequeue() {  //baðlý listeden eleman çýkarma iþlemini gerçekleþtirir.
    if (bas == NULL) {  //Fonksiyon, kuyruðun boþ olup olmadýðýný kontrol eder 
        printf("Kuyruk bos!\n"); //boþ ise bir hata mesajý yazdýrýr 
        return; //fonksiyondan çýkar.
    }
    struct element* gezgin = bas;  //önce kuyruktaki ilk elemanýn verisini geçici bir deðiþkene kaydeder.
    bas = bas->ilerii;  //ilk elemanýn iþaret ettiði düðümü siler ve ilk elemaný bir sonraki eleman yapar.
    if (bas == NULL) { //Eðer son eleman siliniyorsa
        son = NULL; //son düðümü de NULL olarak ayarlar.
    }
    printf("%d kuyruktan silindi.\n", gezgin->verii); //silinen elemanýn verisini ve bir mesajý yazdýrýr 
    free(gezgin); //bellekteki geçici deðiþkeni serbest býrakýr.
}

void display() { //kuyruktaki elemanlarý ekrana yazdýrmak için kullan
    if (bas == NULL) {  //kuyruðun boþ olup olmadýðýný kontrol eder. Eðer kuyruk boþ ise
        printf("Kuyruk bos!\n");  //ekrana "Kuyruk bos!" mesajýný yazdýrýr 
        return; //fonksiyondan çýkar.
    }
    printf("Kuyruk: "); //Kuyruk boþ deðilse, "Kuyruk: " mesajýný yazdýrýr 
    // // döngü kullanarak kuyruktaki her elemanýn verisini ekrana yazdýrýr. Döngü, kuyruðun baþýndan (bas) baþlayarak, her bir elemanýn "ilerii" iþaretçisi yardýmýyla bir sonraki elemana ilerler.
    struct element *gezgin = bas;
    while (gezgin != NULL) {
        printf("%d ", gezgin->verii);
        gezgin = gezgin->ilerii;
    }
    printf("\n");
}

