#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct acikarttirma {
    char AntikRomaHeykeli[50];
    double mevcutteklif;
    char yüksekteklifveren[50];
};


void startAuction(struct acikarttirma *urun) {
    printf("Açık arttırma başlıyor: %s\n", urun->AntikRomaHeykeli);
    printf("Başlangıç fiyatı: %.2f\n", urun->mevcutteklif);
}


void teklif(struct acikarttirma *urun,
            double tekliffiyati,
            char teklifveren[]
            ) {
    
    if (tekliffiyati > urun->mevcutteklif) {
        urun->mevcutteklif =tekliffiyati;
        strncpy(urun->yüksekteklifveren,teklifveren, sizeof(urun->yüksekteklifveren) - 1);
        urun->yüksekteklifveren[sizeof(urun->yüksekteklifveren) - 1] = '\0';
        printf("Yeni teklif: %.2f - Teklif Sahibi: %s\n", urun->mevcutteklif, urun->yüksekteklifveren);
    } else {
        printf("Teklif yetersiz. Yüksek teklif: %.2f - Teklif Sahibi: %s\n", urun->mevcutteklif, urun->yüksekteklifveren);
    }
}



void sonuc(struct acikarttirma *urun){
    printf("Açık arttırma sona erdi.**** TEBRİKLER! Kazanan:%s - Teklif:%.2f ****",urun->yüksekteklifveren,urun->mevcutteklif);
}


int main(void) {
    
    struct acikarttirma heykel = {"Antik Roma Heykeli", 100.0, "Başlangıç Teklif Veren"};
    
    startAuction(&heykel);

    
    int katilimcisayisi;
    
    printf("Kaç katılımcı olacak? ");
    scanf("%d", &katilimcisayisi);
    printf("\n");
    
    char teklifverenadı[50];
    double tekliffiyatı;
    
   

    
    for (int i = 0; i < katilimcisayisi; i++) {
    
        printf("%d. Katılımcı adını girin: ", i + 1);
        scanf("%s",teklifverenadı);

        printf("%s, Antik Roma Heykeli için teklif verin: ",teklifverenadı);
        scanf("%lf", &tekliffiyatı);
        
        printf("\n");
        
        teklif(&heykel, tekliffiyatı, teklifverenadı);
        
        printf("\n");
    }
    
   
    sonuc(&heykel);
    
    
    printf("\n");
    return 0;
}

