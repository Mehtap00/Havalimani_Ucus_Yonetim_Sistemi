#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

    struct inis_pisti{
    int oncelik_id;
    int ucak_id;
    int talep_edilen_inis_saati;
    int inis_saati;
    int gecikme_suresi;
    };

    struct kalkis_pisti{
    int oncelik_id;
    int ucak_id;
    int kalkis_saati;
    };

    struct inis_pisti input;
    struct inis_pisti onceki;
    struct inis_pisti temp;
    struct inis_pisti inis_pisti_kullanim_sirasi[24];
    struct kalkis_pisti kalkis_pisti_kullanim_sirasi[24];

    int index=0,i,j,k,l,sayac=0,kontrol=0,n=0,r;


int kuyruk_dolumu()
{
if(index==24)
return 1;

else
return 0;
}


int main()
{
    FILE *yaz;
    FILE *fp;
    fp=fopen("input.txt","r");
    if (fp == NULL)
    {
        printf("Aranilan dosya bulunamadi.");
        exit(1);
    }

    l=0;
    fseek(fp,42,SEEK_SET);
    while((fscanf(fp, "%d %d %d",&input.oncelik_id, &input.ucak_id, &input.talep_edilen_inis_saati))!=EOF)
    {
    input.inis_saati=input.talep_edilen_inis_saati;
    input.gecikme_suresi=0;

    printf("\n Ucak id'si %d, oncelik id'si %d olan ucak %d saati icin kuleden Istanbul Havalimanina inis izni istiyor...",input.ucak_id,input.oncelik_id,input.talep_edilen_inis_saati);
    getch();
    printf("\n");


    if(kuyruk_dolumu()==1)
    {
    printf(" Istanbul Havalimani inis pisti tum saatler icin dolu. Inis izin talebiniz, ucagin onceligi goz onunde bulundurularak degerlendiriliyor...");
    getch();
    printf("\n");

    for(k=input.talep_edilen_inis_saati-1;k<=input.talep_edilen_inis_saati+2;k++){

    if(input.oncelik_id < inis_pisti_kullanim_sirasi[k].oncelik_id ){
    input.inis_saati=inis_pisti_kullanim_sirasi[k].inis_saati;
    input.gecikme_suresi=input.inis_saati-input.talep_edilen_inis_saati;
    temp=inis_pisti_kullanim_sirasi[k];
    inis_pisti_kullanim_sirasi[k]=input;


    if(input.gecikme_suresi==0){
    printf(" Inis izin talebiniz saat %d icin onaylanmistir...",input.inis_saati);
    getch();
    printf("\n");}

    else if(input.gecikme_suresi!=0){
    printf(" Inis izin talebiniz %d saat gecikmeli olarak saat %d icin onaylanmistir...",input.gecikme_suresi,input.inis_saati);
    getch();
    printf("\n");}

    printf("\n -Acil inis yapmasi gereken %d numarali ucak nedeniyle, %d numarali ucagin inis izni iptal edilmistir. %d numarali ucak inis icin Sabiha Gokcen Havalimanina yonlendiriliyor.",input.ucak_id,temp.ucak_id,temp.ucak_id);
    n++;
    getch();
    printf("\n");
    break;
    }
    }

    r=input.talep_edilen_inis_saati-1;
    if(k==input.talep_edilen_inis_saati+3){
    printf(" Ucagin onceligi, 3 saatlik erteleme siniri dahilinde bulunan, daha once inis izni verilmis %d, %d, %d ve %d numarali ucaklardan dusuk oldugu icin inis izni verilememektedir...",inis_pisti_kullanim_sirasi[r].ucak_id,inis_pisti_kullanim_sirasi[r+1].ucak_id,inis_pisti_kullanim_sirasi[r+2].ucak_id,inis_pisti_kullanim_sirasi[r+3].ucak_id);
    getch();
    printf("\n");}

    goto son;
    }



    else if(kuyruk_dolumu()==0)
    {
    sayac=0;

    if(index==0){
    input.gecikme_suresi=0;
    inis_pisti_kullanim_sirasi[index]=input;
    printf(" Inis izin talebiniz saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[index].inis_saati);
    index++;
    getch();
    printf("\n");
    goto son;}

    i=0;
    loop:
    for(;i<=index;i++){

    if(input.gecikme_suresi+sayac==4){

    if(kontrol==0){
    printf(" 3 saatlik erteleme sinirini astigi icin inis izni verilememektedir. Sabiha Gokcen Havalimanina yonlendiriliyorsunuz...");
    n=0;
    getch();
    printf("\n");
    break;}

    if(kontrol==1){
    kontrol=2;
    sayac--;
    goto acil;
    }
    }


    if(input.inis_saati+sayac < inis_pisti_kullanim_sirasi[i].inis_saati || i==index ){

    if(i==index && input.inis_saati+sayac > inis_pisti_kullanim_sirasi[i].inis_saati){

    for(k=0;k<index;k++){
    if(input.inis_saati+sayac == inis_pisti_kullanim_sirasi[k].inis_saati){
    i=k+1;
    break;}

    else if(input.inis_saati+sayac > inis_pisti_kullanim_sirasi[k].inis_saati)
    i=k+1;
    }}

    if(i==0)
    goto kontrolyok;

    if(input.inis_saati+sayac != inis_pisti_kullanim_sirasi[i-1].inis_saati){
    kontrolyok:

    for(j=index;j>i;j--)
    inis_pisti_kullanim_sirasi[j]=inis_pisti_kullanim_sirasi[j-1];

    input.inis_saati=input.inis_saati+sayac;
    input.gecikme_suresi+=sayac;
    inis_pisti_kullanim_sirasi[i]=input;

    if(kontrol==0){
    if(sayac==0){
    printf(" Inis izin talebiniz saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[i].inis_saati);
    n=0;
    getch();
    printf("\n");}

    else{
    printf(" Inis izin talebiniz %d saat gecikmeli olarak saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[i].gecikme_suresi,inis_pisti_kullanim_sirasi[i].inis_saati);
    n=0;
    getch();
    printf("\n");}
    }

    if(kontrol==1){
    if(n==0)
    printf("\n");

    printf(" -Daha onceden inis izni onaylanan %d numarali ucagin inis izni, %d numarali ucagin oncelikli olmasindan dolayi %d saat gecikmeli olarak saat %d'e ertelenmistir.",input.ucak_id,onceki.ucak_id,input.gecikme_suresi,input.inis_saati);
    kontrol=0;
    n++;
    getch();
    printf("\n");}

    index++;
    sayac=0;
    kontrol=0;
    goto son;
    }

    acil:
    if(input.inis_saati+sayac == inis_pisti_kullanim_sirasi[i-1].inis_saati){

    if(kontrol==2){

    if(inis_pisti_kullanim_sirasi[i-1].gecikme_suresi==3){
    if(n==0)
    printf("\n");
    printf(" -Daha onceden inis izni onaylanan %d numarali ucagin inis izni, %d numarali ucagin oncelikli olmasindan ve %d numarali ucagin 3 saatlik erteleme sinirini asmasindan dolayi iptal edilmistir. %d numarali ucak inis icin Sabiha Gokcen Havalimanina yonlendiriliyor. (Erteleme sinirinin asilmasinin nedeni 3. erteleme saatinde bulunan %d numarali ucagin da erteleme suresinin dolmus olmasidir.)",input.ucak_id,onceki.ucak_id,input.ucak_id,input.ucak_id,inis_pisti_kullanim_sirasi[i-1].ucak_id);
    n++;
    getch();
    printf("\n");
    sayac=0;
    kontrol=0;
    goto son;}

    temp=inis_pisti_kullanim_sirasi[i-1];
    input.inis_saati=input.inis_saati+sayac;
    input.gecikme_suresi+=sayac;

    inis_pisti_kullanim_sirasi[i-1]=input;

    if(n==0)
    printf("\n");
    printf(" -Daha onceden inis izni onaylanan %d numarali ucagin, 3 saatlik erteleme siniri oldugundan, oncelik id'sine bakilmaksizin inis izni %d saat gecikmeli olarak saat %d'e ertelenmistir. Bu ertelenmenin nedeni %d numarali ucagin oncelikli olmasidir.",inis_pisti_kullanim_sirasi[i-1].ucak_id,inis_pisti_kullanim_sirasi[i-1].gecikme_suresi,inis_pisti_kullanim_sirasi[i-1].inis_saati,onceki.ucak_id);
    n++;
    getch();
    printf("\n");

    onceki=input;
    input=temp;
    sayac=1;
    kontrol=1;
    goto loop;
    }

    if(inis_pisti_kullanim_sirasi[i-1].gecikme_suresi==3)
    goto sayac_arttir;

    if(input.oncelik_id < inis_pisti_kullanim_sirasi[i-1].oncelik_id){
    temp=inis_pisti_kullanim_sirasi[i-1];

    input.inis_saati=input.inis_saati+sayac;
    input.gecikme_suresi+=sayac;
    inis_pisti_kullanim_sirasi[i-1]=input;

    if(kontrol==0){
    if(sayac==0){
    printf(" Inis izin talebiniz saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[i-1].inis_saati);
    n=0;
    getch();
    printf("\n");}

    else{
    printf(" Inis izin talebiniz %d saat gecikmeli olarak saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[i-1].gecikme_suresi,inis_pisti_kullanim_sirasi[i-1].inis_saati);
    n=0;
    getch();
    printf("\n");}}

    if(kontrol==1){
    if(n==0)
    printf("\n");

    printf(" -Daha onceden inis izni onaylanan %d numarali ucagin inis izni, %d numarali ucagin oncelikli olmasindan dolayi %d saat gecikmeli olarak saat %d'e ertelenmistir.",input.ucak_id,onceki.ucak_id,input.gecikme_suresi,input.inis_saati);
    kontrol=0;
    n++;
    getch();
    printf("\n");}

    onceki=input;
    input=temp;
    sayac=1;
    kontrol=1;
    goto loop;
    }

    else if(input.oncelik_id > inis_pisti_kullanim_sirasi[i-1].oncelik_id){
    sayac_arttir:
    sayac++;
    goto loop;}


    else if(input.oncelik_id == inis_pisti_kullanim_sirasi[i-1].oncelik_id){

    if(input.ucak_id < inis_pisti_kullanim_sirasi[i-1].ucak_id){
    temp=inis_pisti_kullanim_sirasi[i-1];

    input.inis_saati=input.inis_saati+sayac;
    input.gecikme_suresi+=sayac;
    inis_pisti_kullanim_sirasi[i-1]=input;

    if(kontrol==0){
    if(sayac==0){
    printf(" Inis izin talebiniz saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[i-1].inis_saati);
    n=0;
    getch();
    printf("\n");}

    else{
    printf(" Inis izin talebiniz %d saat gecikmeli olarak saat %d icin onaylanmistir...",inis_pisti_kullanim_sirasi[i-1].gecikme_suresi,inis_pisti_kullanim_sirasi[i-1].inis_saati);
    n=0;
    getch();
    printf("\n");}
    }

    if(kontrol==1){
    if(n==0)
    printf("\n");

    printf(" -Daha onceden inis izni onaylanan %d numarali ucagin inis izni, %d numarali ucagin oncelikli olmasindan dolayi %d saat gecikmeli olarak saat %d'e ertelenmistir.",input.ucak_id,onceki.ucak_id,input.gecikme_suresi,input.inis_saati);
    kontrol=0;
    n++;
    getch();
    printf("\n");}

    onceki=input;
    input=temp;
    sayac=1;
    kontrol=1;
    goto loop;
    }

    else if(input.ucak_id > inis_pisti_kullanim_sirasi[i-1].ucak_id){
    sayac++;
    goto loop;}
    }
    }}}

    son:

    yaz=fopen("output.txt","w");
    for(int d=0; d<index; d++)
    {
        kalkis_pisti_kullanim_sirasi[d].oncelik_id=inis_pisti_kullanim_sirasi[d].oncelik_id;
        kalkis_pisti_kullanim_sirasi[d].ucak_id=inis_pisti_kullanim_sirasi[d].ucak_id;
        kalkis_pisti_kullanim_sirasi[d].kalkis_saati=inis_pisti_kullanim_sirasi[d].inis_saati + 1;
        if(kalkis_pisti_kullanim_sirasi[d].kalkis_saati==25)
        {
            kalkis_pisti_kullanim_sirasi[d].kalkis_saati=1;
        }

        if(d==0)
        fprintf(yaz,"%s %s %s %s %s %s\n","oncelik_id","ucak_id","talep_edilen_inis_saati","inis_saati","gecikme_suresi","kalkis_saati");

        fprintf(yaz,"%d %d %d %d %d %d\n",kalkis_pisti_kullanim_sirasi[d].oncelik_id,kalkis_pisti_kullanim_sirasi[d].ucak_id,inis_pisti_kullanim_sirasi[d].talep_edilen_inis_saati,inis_pisti_kullanim_sirasi[d].inis_saati,inis_pisti_kullanim_sirasi[d].gecikme_suresi,kalkis_pisti_kullanim_sirasi[d].kalkis_saati);
    }
    fclose(yaz);


    printf("\n");
    if(n!=0)
    printf("\n");

    for(k=0;k<index;k++){
    if(k==0)
    printf("    Oncelik id       Ucak id          Talep edilen inis saati      Inis saati    Gecikme suresi   Kalkis Saati\n");

    printf("\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\t\t%d\n",inis_pisti_kullanim_sirasi[k].oncelik_id,inis_pisti_kullanim_sirasi[k].ucak_id,inis_pisti_kullanim_sirasi[k].talep_edilen_inis_saati,inis_pisti_kullanim_sirasi[k].inis_saati,inis_pisti_kullanim_sirasi[k].gecikme_suresi,kalkis_pisti_kullanim_sirasi[k].kalkis_saati);}

    getch();
    printf("\n\n");
    l++;
    }
    }
    fclose(fp);

    return 0;
}
