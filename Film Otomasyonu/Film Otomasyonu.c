#include <stdio.h>
#include <stdlib.h>
typedef struct kisi
{
    //21100011062/HAKAN/EMİK
    char film_ad[100];
    int film_imbd;
    int film_no;
    float film_fiyat;
    int film_yili;
    char film_basrol[100];
    char film_yonetmen[100];
} kisi;
typedef struct turu
{
    char film_turu[20];
    int tur_no;
    int film_sayisi;
    kisi *film;
} turu;
int i,j,sayi,secenek,silinecektur,go,aramano,filmsayisi,turno,filmno,arttir=0,silinecekfilm;
float toplam=0;
turu *tur=NULL; //fonksiyona 1.girişiyle 2. girişini ayırmak için null atadım
void ekle()
{
    printf("\n----EKLEME----\n\n");


    if(tur==0)
    {
        arttir++;
        tur=(turu *)calloc(1,sizeof(turu));
        if(tur==NULL)
        {
            printf("yetersiz bellek\n");
            exit(1);
        }



        printf("tur  adi="); //filmin türü
        scanf("%s",&(tur)->film_turu);
        printf("tur no=");
        scanf("%d",&(tur)->tur_no);
        printf("icindeki film sayisi=");
        scanf("%d",&(tur)->film_sayisi);

        (tur)->film=(kisi *)calloc((tur)->film_sayisi,sizeof(kisi));
        if((tur)->film==NULL){

             printf("yetersiz bellek\n");
            exit(1);
        }
        if((tur)->film==NULL)
        {
            printf("yetersiz bellek\n");
            exit(1);
        }






        for(j=0; j<(tur)->film_sayisi; j++)
        {

            printf("filmin adi=");
            scanf("%s",&((tur)->film+j)->film_ad);
            printf("filmin imbd puani=");
            scanf("%d",&((tur)->film+j)->film_imbd);
            printf("film no=");
            scanf("%d",&((tur)->film+j)->film_no);
            printf("filmin fiyati=");
            scanf("%f",&((tur)->film+j)->film_fiyat);
            printf("filmin cikis yili=");
            scanf("%d",&((tur)->film+j)->film_yili);
            printf("filmin basrolu=");
            scanf("%s",&((tur)->film+j)->film_basrol);
            printf("filmin yonetmeni=");
            scanf("%s",&((tur)->film+j)->film_yonetmen);
        }
        printf("menuye donmek icin bir sayiya basiniz=");
        scanf("%d",&go);

    }

    else
    {
        arttir++; // yeni tür girerken hafızayı arttırmak için kullandım
        tur=realloc(tur,arttir*sizeof(turu));
        if(tur==NULL){
             printf("yetersiz bellek\n");
            exit(1);
        }
        printf("tur  adi="); //filmin türü
        scanf("%s",&(tur+(arttir-1))->film_turu);
        printf("tur no=");
        scanf("%d",&(tur+(arttir-1))->tur_no);
        printf("icindeki film sayisi=");
        scanf("%d",&(tur+(arttir-1))->film_sayisi);
        (tur+(arttir-1))->film=(kisi *)calloc((tur+(arttir-1))->film_sayisi,sizeof(kisi));
        if((tur+(arttir-1))->film==NULL){
            printf("yetersiz bellek\n");
            exit(1);
        }
        for(j=0; j<(tur+(arttir-1))->film_sayisi; j++)
        {

            printf("film adi=");
            scanf("%s",&((tur+(arttir-1))->film+j)->film_ad);
            printf("film imbd puani=");
            scanf("%d",&((tur+(arttir-1))->film+j)->film_imbd);
            printf("film no=");
            scanf("%d",&((tur+(arttir-1))->film+j)->film_no);
            printf("film fiyati=");
            scanf("%f",&((tur+(arttir-1))->film+j)->film_fiyat);
            printf("film cikis yili=");
            scanf("%d",&((tur+(arttir-1))->film+j)->film_yili);
            printf("filmin basrolu=");
            scanf("%s",&((tur+(arttir-1))->film+j)->film_basrol);
            printf("filmin yonetmeni=");
            scanf("%s",&((tur+(arttir-1))->film+j)->film_yonetmen);
        }
        printf("menuye donmek icin bir sayiya basiniz=");
        scanf("%d",&go);
    }
}







void listeleme()
{
    int i,j;
    printf("\n----LISTELEME----\n");
    for(i=0; i<arttir; i++)
    {


        printf("tur adi=%s\ntur no=%d\n\n",(tur+i)->film_turu,(tur+i)->tur_no);

        for(j=0; j<(tur+i)->film_sayisi; j++)
        {
            if(((tur+i)->film+j)->film_no==0) //  film nosu 0 olanları listelememek için kullandım.
            {
                continue;
            }
            printf("%d nolu turun %d nolu filminin adi=%s\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_ad);
            printf("%d nolu turun %d nolu filminin imbd puani=%d\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_imbd);
            printf("%d nolu turun %d nolu filminin nosu=%d\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_no);
            printf("%d nolu turun %d nolu filminin fiyati=%f\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_fiyat);
            printf("%d nolu turun %d nolu filminin cikis yili=%d\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_yili);
            printf("%d nolu turun %d nolu filminin basrolu=%s\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_basrol);
            printf("%d nolu turun %d nolu filminin yonetmeni=%s\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_yonetmen);
            printf("-------------------\n");


        }
    }
    printf("menuye donmek icin bir sayiya basiniz=");
    scanf("%d",&go);





}








void guncelleme()
{
    printf("\n----GUNCELLEME----\n\n");

    printf("guncellemek istediginiz filmin tur nosu=");
    scanf("%d",&turno);
    printf("guncelemek istediginiz filmin nosu=");
    scanf("%d",&filmno);
    for(i=0; i<arttir; i++)
    {
        if((tur+i)->tur_no==turno)
        {


            for(j=0; j<(tur+i)->film_sayisi; j++)
            {
                if(((tur+i)->film+j)->film_no==filmno)
                {
                    printf("filmin yeni adi=");
                    scanf("%s",&((tur+i)->film+j)->film_ad);
                    printf("filmin yeni imbd puani=");
                    scanf("%d",&((tur+i)->film+j)->film_imbd);
                    printf("filmin yeni nosu=");
                    scanf("%d",&((tur+i)->film+j)->film_no);
                    printf("filmin yeni fiyati=");
                    scanf("%f",&((tur+i)->film+j)->film_fiyat);
                    printf("film yeni cikis yili=");
                    scanf("%d",&((tur+i)->film+j)->film_yili);
                    printf("filmin yeni basrolu=");
                    scanf("%s",&((tur+i)->film+j)->film_basrol);
                    printf("filmin yeni yonetmeni=");
                    scanf("%s",&((tur+i)->film+j)->film_yonetmen);

                    printf("menuye donmek icin bir sayiya basiniz=");
                    scanf("%d",&go);
                }

            }





        }
    }








}
void sil()
{
    printf("\n----SILME----\n\n");
    printf("silinecek turun nosu=");
    scanf("%d",&silinecektur);
    printf("silinecek filmin nosu=");
    scanf("%d",&silinecekfilm);
    for(i=0; i<arttir; i++)
    {
        if((tur+i)->tur_no==silinecektur)
        {
            for(j=0; j<(tur+i)->film_sayisi; j++)
            {
                if(((tur+i)->film+j)->film_no==silinecekfilm)
                {
                    ((tur+i)->film+j)->film_no=0;
                    printf("%d nolu tur %d nolu film silinmistir...\n",silinecektur,silinecekfilm);
                    printf("menuye donmek icin bir sayiya basiniz=");
                    scanf("%d",&go);

                }


            }




        }
    }
}
void ara()
{
    printf("\n----ARAMA----\n\n");
    int filmnosu;
    printf("aradiginiz turun nosu=");
    scanf("%d",&aramano);
    printf("aradiginiz filmin nosu=");
    scanf("%d",&filmnosu);
    for(i=0; i<arttir; i++)
    {
        if((tur+i)->tur_no==aramano)
        {
            printf("tur adi=%s\n",(tur+i)->film_turu);
            printf("tur nosu=%d\n",(tur+i)->tur_no);





            for(j=0; j<(tur+i)->film_sayisi; j++)
            {
                if(filmnosu==((tur+i)->film+j)->film_no)
                {
                    printf("%d nolu turun %d nolu filminin adi=%s\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_ad);
                    printf("%d nolu turun %d nolu filminin imbd puani=%d\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_imbd);
                    printf("%d nolu turun %d nolu filminin nosu=%d\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_no);
                    printf("%d nolu turun %d nolu filminin fiyati=%f\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_fiyat);
                    printf("%d nolu turun %d nolu filminin cikis yili=%d\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_yili);
                    printf("%d nolu turun %d nolu filminin basrolu=%s\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_basrol);
                    printf("%d nolu turun %d nolu filminin yonetmeni=%s\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no,((tur+i)->film+j)->film_yonetmen);
                    printf("-----------------------------------------\n");







                }
            }



            printf("menuye donmek icin bir sayiya basiniz=");
            scanf("%d",&go);





        }

    }
}
void satinal()
{
    printf("\n----SATIN ALMA----\n\n");


    printf("satin alacaginiz filmin tur nosu=");
    scanf("%d",&turno);
    printf("satin alacaginiz filmin nosu=");
    scanf("%d",&filmno);
    for(i=0; i<arttir; i++)
    {
        if(turno==(tur+i)->tur_no)
        {
            for(j=0; j<(tur+i)->film_sayisi; j++)
            {
                if(filmno==((tur+i)->film+j)->film_no)
                {
                    toplam=((tur+i)->film+j)->film_fiyat+toplam;
                    printf("%d nolu tur %d nolu filmi satin aldiniz keyifli seyirler\n",(tur+i)->tur_no,((tur+i)->film+j)->film_no);
                    printf("toplam borcunuz=%f \n",toplam);
                    printf("menuye donmek icin bir sayiya basiniz=");
                    scanf("%d",&go);
                }
            }



        }




    }

}


int main()

{

    turu *ptr;
    secenek=9;
    printf("----------------FILM OTOMASYONU----------------\n\n");
    while(secenek!=7)
    {
        printf("----MENU----\n");
        printf("1.EKLE\n2.LISTELE\n3.GUNCELLE\n4.SIL\n5.ARA\n6.SATIN AL\n7.CIKIS\n1 ile 7 arasinda sayi giriniz\n\nSECIM= ");
        scanf("%d",&secenek);


        switch(secenek)
        {
        case 1:
            ekle();
            break;
        case 2:
            listeleme();
            break;
        case 3:
            guncelleme();
            break;
        case 4:
            sil();
            break;
        case 5:
            ara();
            break;
        case 6:
            satinal();
            break;
        case 7:
            printf("otomasyon'dan cikiliyor...");
            break;







        }
    }














    return 0;
}
