#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ogrenciler{
	char isim[10],soyIsim[10];
	int topKredi,topDers,ogrenciNo;
	struct ogrenciler *next;
	struct ogrenciler *prev;
}OGRENCILER;
	
typedef struct dersler{
	char dersAdi[35],kod[10];
	int kredi,kontenjan;
	int *ogrenciler,ogrenciSayisi;
	struct dersler *next;
}DERSLER;

typedef struct ogrenciderskayit{
	char kod[10],durum[10],tarih[10];
	int id,ogrenciNo;
	struct ogrenciderskayit *next;
}ODK;

void dersAc(DERSLER **dhead);
void dersKapa(DERSLER **dhead,ODK *odkhead);
void acilanDerslerGet(DERSLER **dhead);
void acilanDerslerSend(DERSLER *dhead);

void ogrenciEkle(OGRENCILER **ohead);
void ogrenciSil(OGRENCILER **ohead);
void ogrencilerGet(OGRENCILER **ohead);
void ogrencilerSend(OGRENCILER *ohead);

void ogrenciDersKayit(OGRENCILER *ohead,DERSLER *dhead,ODK **odkhead,char tarih[],int maxKredi,int maxDers);
void ogrenciDersKayitSil(OGRENCILER *ohead,DERSLER *dhead,ODK **odkhead,char tarih[],int maxKredi,int maxDers);
void ODKGet(ODK **odkhead);
void ODKSend(ODK*ogkhead);

void dersiAlanOgrenciOlustur(DERSLER *dhead,ODK *odkhead);
void dersiAlanOgrenciSirala(DERSLER *dhead);
void dersiAlanOgrenciDosyala(DERSLER *dhead);

void dersProgramiOlustur(ODK *odkhead,OGRENCILER *ohead);

int main(){
	DERSLER *dhead=NULL;
	OGRENCILER *ohead=NULL;
	ODK *odkhead=NULL;	
	int maxKredi=300,maxDers=300,menu=9;
	char tarih[20]="2001";
	ODKGet(&odkhead);
	ogrencilerGet(&ohead);
	acilanDerslerGet(&dhead);
	printf("Max Ders Sayisini Girin: ");
	scanf("%d",&maxDers);
	printf("Max Krediyi Girin: ");
	scanf("%d",&maxKredi); 
	printf("Tarih Bilgisini Girin: ");
	scanf("%s",tarih);
	printf("Baslangic Islemleri Tamam!\nMenuye Donmek Icin Entere Basin");
	getch();
	system("cls");
	
	while(menu!=0){
		printf("(Menu)\nDERS ACMAK ICIN(1)\nDERS KAPAMAK ICIN(2)\nOGRENCI EKLEMEK ICIN(3)\nOGRENCI SILMEK ICIN(4)\nDERS ALMAK ICIN(5)\nDERS KAYDINI SILMEK ICIN(6)\nDERS PROGRAMI ALMAK ICIN(7)\nCIKMAK ICIN(0)\nOPERASYONU GIRIN: ");
		scanf("%d",&menu);
		printf("\n\n");
		switch(menu){
			case 1:
				dersAc(&dhead);
				dersiAlanOgrenciOlustur(dhead,odkhead);
				dersiAlanOgrenciDosyala(dhead);
				break;
			case 2:
				dersKapa(&dhead,odkhead);
				dersiAlanOgrenciOlustur(dhead,odkhead);
				dersiAlanOgrenciDosyala(dhead);
				break;
			case 3:
				ogrenciEkle(&ohead);
				break;
			case 4:
				ogrenciSil(&ohead);
				break;
			case 5:
				ogrenciDersKayit(ohead,dhead,&odkhead,tarih,maxKredi,maxDers);
				dersiAlanOgrenciOlustur(dhead,odkhead);
				dersiAlanOgrenciDosyala(dhead);
				break;
			case 6:
				ogrenciDersKayitSil(ohead,dhead,&odkhead,tarih,maxKredi,maxDers);
				dersiAlanOgrenciOlustur(dhead,odkhead);
				dersiAlanOgrenciDosyala(dhead);
				break;
			case 7:
				dersProgramiOlustur(odkhead,ohead);
				break;
		}
	}
	dersiAlanOgrenciOlustur(dhead,odkhead);
	dersiAlanOgrenciDosyala(dhead);
	ODKSend(odkhead);
	acilanDerslerSend(dhead);
	ogrencilerSend(ohead);
	
	return 0;
}

void dersKapa(DERSLER **dhead,ODK *odkhead){
	char kod[10];
	DERSLER *tmp,*tmp2;
	tmp=*dhead;
	printf("Ders Kodunu Girin: ");
	scanf("%s",kod);
	while(tmp!=NULL && strcmp(tmp->kod,kod)){
		tmp2=tmp;
		tmp=tmp->next;
	}
	if(tmp!=NULL){
		if(tmp==*dhead){
			*dhead=tmp->next;
			remove(strcat(tmp->kod,".txt"));
			free(tmp);
		}
		else{
			tmp2->next=tmp->next;
			remove(strcat(tmp->kod,".txt"));
			free(tmp);
		}
		while(odkhead!=NULL){
			if(strcmp(odkhead->durum,"KAPANDI")!=0 && strcmp(odkhead->kod,kod)==0){
				strcpy(odkhead->durum,"KAPANDI");
			}
			odkhead=odkhead->next;
		}
		printf("Ders Silindi.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return;
	}
	else{
		printf("Ders Bulunamadi!!\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return;
	}
	
}

void dersAc(DERSLER **dhead){
	DERSLER *tmp,*tmp2;
	char kod[10],dersAdi[10];
	int kontenjan,kredi;
	printf("Ders Kodunu Girin: ");
	scanf("%s",kod);
	if((*dhead)==NULL){
		tmp=(DERSLER*)malloc(sizeof(DERSLER));
		(*dhead)=tmp;
		tmp->next=NULL;
	}
	else{
		tmp=(*dhead);
		while(tmp->next!=NULL && strcmp(tmp->kod,kod)<0){
			tmp2=tmp;
			tmp=tmp->next;
		}
		if(strcmp(tmp->kod,kod)==0){
			printf("Bu Ders Zaten Ekli!!\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
			return;
		}
		else if(tmp==(*dhead)){
			tmp=(DERSLER*)malloc(sizeof(DERSLER));
			tmp->next=(*dhead);
			(*dhead)=tmp;
			printf("Ders Adini Girin: ");
			scanf("%s",dersAdi);	
			printf("Ders Kontenjanini Girin: ");
			scanf("%d",&kontenjan);	
			printf("Ders Kredisini Girin: ");
			scanf("%d",&kredi);
			strcpy((*dhead)->kod,kod);
			strcpy((*dhead)->dersAdi,dersAdi);
			(*dhead)->kontenjan=kontenjan;
			(*dhead)->kredi=kredi;
			(*dhead)->ogrenciSayisi=0;
		}
		else if(strcmp(tmp->kod,kod)>0){
			printf("Ders Adini Girin: ");
			scanf("%s",dersAdi);	
			printf("Ders Kontenjanini Girin: ");
			scanf("%d",&kontenjan);	
			printf("Ders Kredisini Girin: ");
			scanf("%d",&kredi);
			tmp2->next=(DERSLER*)malloc(sizeof(DERSLER));
			tmp2=tmp2->next;
			tmp2->next=tmp;
			strcpy(tmp2->kod,kod);
			strcpy(tmp2->dersAdi,dersAdi);
			tmp2->kontenjan=kontenjan;
			tmp2->kredi=kredi;
			tmp2->ogrenciSayisi=0;
		}
		else{
			printf("Ders Adini Girin: ");
			scanf("%s",dersAdi);	
			printf("Ders Kontenjanini Girin: ");
			scanf("%d",&kontenjan);	
			printf("Ders Kredisini Girin: ");
			scanf("%d",&kredi);
			tmp->next=(DERSLER*)malloc(sizeof(DERSLER));
			tmp=tmp->next;
			tmp->next=NULL;
			strcpy(tmp->kod,kod);
			strcpy(tmp->dersAdi,dersAdi);
			tmp->kontenjan=kontenjan;
			tmp->kredi=kredi;
			tmp->ogrenciSayisi=0;
		}
	}
	printf("Ders Eklendi.\nMenuye Donmek Icin Entere Basin:");
	getch();
	system("cls");
	return;
}

void acilanDerslerGet(DERSLER **dhead){
	DERSLER *tmp;
	DERSLER *tmp2;
	FILE*dosya = fopen("acilanDersler.txt","r");
	while(!feof(dosya)){
		tmp=(DERSLER*)malloc(sizeof(DERSLER));
		tmp->next=NULL;
		fscanf(dosya,"%[^,],%[^,],%d,%d\n",tmp->kod,tmp->dersAdi,&(tmp->kontenjan),&(tmp->kredi));
		if((*dhead)==NULL){
			*dhead=tmp;
		}
		else{
			tmp2 = *dhead;
			while(tmp2->next != NULL){
				tmp2 = tmp2->next;
			}
			tmp2->next = tmp;
		}
	}
	fclose(dosya);
}

void acilanDerslerSend(DERSLER *dhead){
	FILE*dosya = fopen("acilanDersler.txt","w");
	while(dhead!=NULL){
		fprintf(dosya,"%s,%s,%d,%d\n",dhead->kod,dhead->dersAdi,dhead->kontenjan,dhead->kredi);
		dhead=dhead->next;
	}
	fclose(dosya);
}

void ogrenciSil(OGRENCILER **ohead){
	OGRENCILER *tmp,*tmp2;
	char isim[10],soyIsim[10];
	int topKredi,topDers,ogrenciNo;
	tmp=*ohead;
	printf("Silinecek Ogrencinin Numarasini Girin: ");
	scanf("%d",&ogrenciNo);
	while(tmp!=NULL && tmp->ogrenciNo!=ogrenciNo ){
		tmp2=tmp;
		tmp=tmp->next;
	}
	if(tmp!=NULL){
		if(tmp==*ohead){
		*ohead=tmp->next;
		free(tmp);
		(*ohead)->prev=NULL;
		}
		else{
			tmp2->next=tmp->next;
			free(tmp);
			tmp2->next->prev=tmp2;
		}
		printf("Ogrenci Silindi.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return;
	}
	else{
		printf("Ogrenci Bulunamadi!!\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return;
	}
	
}

void ogrenciEkle(OGRENCILER **ohead){
	OGRENCILER *tmp,*tmp2;
	char isim[10],soyIsim[10];
	int topKredi,topDers,ogrenciNo;
	
	printf("Eklenecek Ogrencinin Numarasini Girin: ");
	scanf("%d",&ogrenciNo);
	if((*ohead)==NULL){
		tmp=(OGRENCILER*)malloc(sizeof(OGRENCILER));
		(*ohead)=tmp;
		tmp->next=NULL;
		tmp->prev=NULL;
		printf("Ogrencinin Ismini Girin: ");
		scanf("%s",isim);	
		printf("Ogrencinin Soyismini Girin: ");
		scanf("%s",soyIsim);
		(*ohead)->ogrenciNo=ogrenciNo;
		strcpy((*ohead)->isim,isim);
		strcpy((*ohead)->soyIsim,soyIsim);
		(*ohead)->topKredi=0;
		(*ohead)->topDers=0;
	}
	else{
		tmp=(*ohead);
		while(tmp->next!=NULL && ogrenciNo>(tmp->ogrenciNo)){
			tmp2=tmp;
			tmp=tmp->next;
		}
		if(ogrenciNo==tmp->ogrenciNo){
			printf("Bu Ogrenci Zaten Ekli!!\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
			return;
		}
		else if(tmp==(*ohead)){
			tmp=(OGRENCILER*)malloc(sizeof(OGRENCILER));
			tmp->next=(*ohead);
			(*ohead)=tmp;
			printf("Ogrencinin Ismini Girin: ");
			scanf("%s",isim);	
			printf("Ogrencinin Soyismini Girin: ");
			scanf("%s",soyIsim);
			(*ohead)->ogrenciNo=ogrenciNo;
			strcpy((*ohead)->isim,isim);
			strcpy((*ohead)->soyIsim,soyIsim);
			(*ohead)->topKredi=0;
			(*ohead)->topDers=0;
		}
		else if(tmp->ogrenciNo>ogrenciNo){
			printf("Ogrencinin Ismini Girin: ");
			scanf("%s",isim);	
			printf("Ogrencinin Soyismini Girin: ");
			scanf("%s",soyIsim);
			tmp2->next=(OGRENCILER*)malloc(sizeof(OGRENCILER));
			tmp2->next->prev=tmp2;
			tmp2=tmp2->next;
			tmp->prev=tmp2;
			tmp2->next=tmp;
			tmp2->ogrenciNo=ogrenciNo;
			strcpy(tmp2->isim,isim);
			strcpy(tmp2->soyIsim,soyIsim);
			tmp2->topKredi=0;
			tmp2->topDers=0;
		}
		else{
			printf("Ogrencinin Ismini Girin: ");
			scanf("%s",isim);	
			printf("Ogrencinin Soyismini Girin: ");
			scanf("%s",soyIsim);	
			tmp->next=(OGRENCILER*)malloc(sizeof(OGRENCILER));
			tmp->next->prev=tmp;
			tmp=tmp->next;
			tmp->next=NULL;
			tmp->ogrenciNo=ogrenciNo;
			strcpy(tmp->isim,isim);
			strcpy(tmp->soyIsim,soyIsim);
			tmp->topKredi=0;
			tmp->topDers=0;
		}
	}
	printf("Ogrenci Eklendi.\nMenuye Donmek Icin Entere Basin:");
	getch();
	system("cls");
	return;
}

void ogrencilerGet(OGRENCILER **ohead){
	OGRENCILER *tmp;
	OGRENCILER *tmp2;
	FILE*dosya = fopen("ogrenciler.txt","r");
	while(!feof(dosya)){
		tmp=(OGRENCILER*)malloc(sizeof(OGRENCILER));
		tmp->next=NULL;
		fscanf(dosya,"%d,%[^,],%[^,],%d,%d\n",&(tmp->ogrenciNo),tmp->isim,tmp->soyIsim,&(tmp->topDers),&(tmp->topKredi));
		if((*ohead)==NULL){
			*ohead=tmp;
			tmp->prev=NULL;
		}
		else{
			tmp2 = *ohead;
			while(tmp2->next != NULL){
				tmp2 = tmp2->next;
			}
			tmp2->next = tmp;
			tmp->prev= tmp2;
		}
	}
	fclose(dosya);
}

void ogrencilerSend(OGRENCILER *ohead){
	FILE*dosya = fopen("ogrenciler.txt","w");
	while(ohead!=NULL){
		fprintf(dosya,"%d,%s,%s,%d,%d\n",ohead->ogrenciNo,ohead->isim,ohead->soyIsim,ohead->topDers,ohead->topKredi);
		ohead=ohead->next;
	}
	fclose(dosya);
}

void ogrenciDersKayitSil(OGRENCILER *ohead,DERSLER *dhead,ODK **odkhead,char tarih[],int maxKredi,int maxDers){
	int ogrenciNo,counter=1;
	char kod[10];
	ODK *tmp,*tmp2;
	
	printf("Ders Kaydi Silinecek Ogrencinin Numarasini Girin: ");
	scanf("%d",&ogrenciNo);
	while(ohead!=NULL && ohead->ogrenciNo!=ogrenciNo){
		ohead=ohead->next;
	}
	if(ohead==NULL){
		printf("Ogrenci Bulunamadi!!.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return ;
	}
	else{
		printf("Ogrenci Bulundu, Kayit Silecegi Dersin Kodunu Girin: ");
		scanf("%s",kod);
	}
	while(dhead!=NULL && strcmp(kod,dhead->kod)!=0){
		dhead=dhead->next;
	}
	if(dhead==NULL){
		printf("Ders Bulunamadi!!.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return ;
	}
	else{
		tmp=*odkhead;
		while(tmp!=NULL && (strcmp(tmp->kod,kod)!=0 || tmp->ogrenciNo!=ogrenciNo)){
			tmp=tmp->next;
		}
		if(tmp==NULL || strcmp(tmp->durum,"BIRAKTI")==0){
			printf("Ogrenci Bu Dersi Almiyor !!.\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
			return ;
		}
		else if(tmp!=NULL && strcmp(tmp->durum,"KAYITLI")==0){
			strcpy(tmp->durum,"BIRAKTI");
			ohead->topDers--;
			ohead->topKredi-=dhead->kredi;
			dhead->ogrenciSayisi--;
			
			printf("Ogrencinin Ders Kaydi Silindi.\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
			return ;
		}
	}
}

void ogrenciDersKayit(OGRENCILER *ohead,DERSLER *dhead,ODK **odkhead,char tarih[],int maxKredi,int maxDers){
	int ogrenciNo,counter=1;
	char kod[10];
	ODK *tmp,*tmp2;
	
	printf("Kayit Olacak Ogrencinin Numarasini Girin: ");
	scanf("%d",&ogrenciNo);
	while(ohead!=NULL && ohead->ogrenciNo!=ogrenciNo){
		ohead=ohead->next;
	}
	if(ohead==NULL){
		printf("Ogrenci Bulunamadi!!.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return ;
	}
	else{
		printf("Ogrenci Bulundu, Kayit Olacagi Dersin Kodunu Girin: ");
		scanf("%s",kod);
	}
	while(dhead!=NULL && strcmp(kod,dhead->kod)!=0){
		dhead=dhead->next;
	}
	if(dhead==NULL){
		printf("Ders Bulunamadi!!.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return ;
	}
	else{
		if(ohead->topDers>=maxDers){
			printf("Ogrenci Daha Fazla Ders Alamaz!!.\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
			return;
		}
		else if(ohead->topKredi+dhead->kredi>maxKredi){
			printf("Ogrencinin Yeterli Kredi Hakki Yok!!.\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
		}
		else if(dhead->ogrenciSayisi>=dhead->kontenjan){
			printf("Ders Dolu!!.\nMenuye Donmek Icin Entere Basin:");
			getch();
			system("cls");
		}
		else{
			if(*odkhead==NULL){
				tmp=(ODK*)malloc(sizeof(ODK));
				*odkhead=tmp;
				tmp->next=NULL;
				strcpy(tmp->durum,"KAYITLI");
				tmp->id=counter;
				strcpy(tmp->tarih,tarih);
				strcpy(tmp->kod,kod);
				tmp->ogrenciNo=ogrenciNo;
				ohead->topDers+=1;
				ohead->topKredi+=dhead->kredi;
				dhead->ogrenciSayisi++;
				printf("Ders Alindi.\nMenuye Donmek Icin Entere Basin:");
				getch();
				system("cls");
				return;
			}
			else{
				tmp=*odkhead;
				while(tmp!=NULL && (strcmp(tmp->kod,kod)!=0 || tmp->ogrenciNo!=ogrenciNo)){
					tmp=tmp->next;
				}
				if(tmp!=NULL && strcmp(tmp->durum,"KAYITLI")==0){
					printf("Ogrenci Zaten Kayitli !!.\nMenuye Donmek Icin Entere Basin:");
					getch();
					system("cls");
					return ;
				}
				tmp=*odkhead;
				counter=1;
				while(tmp!=NULL){
					tmp2=tmp;
					tmp=tmp->next;
					counter++;
				}
				tmp=(ODK*)malloc(sizeof(ODK));
				tmp2->next=tmp;
				tmp->next=NULL;
				strcpy(tmp->durum,"KAYITLI");
				tmp->id=counter;
				strcpy(tmp->tarih,tarih);
				strcpy(tmp->kod,kod);
				tmp->ogrenciNo=ogrenciNo;
				ohead->topDers+=1;
				ohead->topKredi+=dhead->kredi;
				dhead->ogrenciSayisi++;
				printf("Ders Alindi.\nMenuye Donmek Icin Entere Basin:");
				getch();
				system("cls");
				return;
			}
		}	
	}
}
//fscanf(dosya,"%d,%[^,],%d,%[^,],%[^,]\n",&(tmp->id),tmp->kod,&(tmp->ogrenciNo),tmp->durum,tmp->tarih);
void ODKGet(ODK **odkhead){
	ODK *tmp;
	ODK *tmp2;
	FILE*dosya = fopen("ogrenciderskayit.txt","r");
	while(!feof(dosya)){
		tmp=(ODK*)malloc(sizeof(ODK));
		fscanf(dosya,"%d,%[^,],%d,%[^,],%s\n",&(tmp->id),tmp->kod,&(tmp->ogrenciNo),tmp->durum,tmp->tarih);
		if((*odkhead)==NULL){
			*odkhead=tmp;
			tmp->next=NULL;
		}
		else{
			tmp2 = *odkhead;
			while(tmp2->next != NULL){
				tmp2 = tmp2->next;
			}
			tmp2->next = tmp;
			tmp->next=NULL;
		}
	}
	fclose(dosya);
}
void ODKSend(ODK *odkhead){
	FILE*dosya = fopen("ogrenciderskayit.txt","w");
	while(odkhead!=NULL){
		fprintf(dosya,"%d,%s,%d,%s,%s\n",odkhead->id,odkhead->kod,odkhead->ogrenciNo,odkhead->durum,odkhead->tarih);
		odkhead=odkhead->next;
	}
	fclose(dosya);
}

void dersiAlanOgrenciOlustur(DERSLER *dhead,ODK *odkhead){
	ODK *odktmp;
	DERSLER *dtmp;
	dtmp=dhead;
	while(dtmp!=NULL){
		odktmp=odkhead;
		dtmp->ogrenciSayisi=0;
		while(odktmp!=NULL){
			if(strcmp(odktmp->kod,dtmp->kod)==0 && strcmp(odktmp->durum,"KAYITLI")==0){
				dtmp->ogrenciSayisi++;
				if(dtmp->ogrenciSayisi==1){
					dtmp->ogrenciler=(int*)malloc(sizeof(int)*dtmp->ogrenciSayisi);
					dtmp->ogrenciler[dtmp->ogrenciSayisi-1]=odktmp->ogrenciNo;
				}
				else{
					dtmp->ogrenciler=(int*)realloc(dtmp->ogrenciler,sizeof(int)*dtmp->ogrenciSayisi);
					dtmp->ogrenciler[dtmp->ogrenciSayisi-1]=odktmp->ogrenciNo;
				}
			}
			odktmp=odktmp->next;
		}
		dtmp=dtmp->next;
	}
	dersiAlanOgrenciSirala(dhead);
}

void dersiAlanOgrenciSirala(DERSLER *dhead){
	int tmp,i,j;
	while(dhead!=NULL){
		for(i=0;i<dhead->ogrenciSayisi-1;i++){
			for(j=i+1;j<dhead->ogrenciSayisi;j++){
				if(dhead->ogrenciler[i]>dhead->ogrenciler[j]){
					tmp=dhead->ogrenciler[i];
					dhead->ogrenciler[i]=dhead->ogrenciler[j];
					dhead->ogrenciler[j]=tmp;
				}
			}
		}
		dhead=dhead->next;
	}
}

void dersiAlanOgrenciDosyala(DERSLER *dhead){
	int i=0;
	char txtName[15];
	while(dhead!=NULL){
		i=0;
		strcpy(txtName,dhead->kod);
		strcat(txtName,".txt");
		FILE*dosya = fopen(txtName,"w");
		for(i=0;i<dhead->ogrenciSayisi;i++){
			fprintf(dosya,"%d\n",dhead->ogrenciler[i]);
		}
		fclose(dosya);
		dhead=dhead->next;
	}
}

void dersProgramiOlustur(ODK *odkhead,OGRENCILER *ohead){
	int ogrenciNo;
	printf("Ders Programi Olusturulacak Ogrencinin Numarasini Girin: ");
	scanf("%d",&ogrenciNo);
	char charOgrenciNo[20];
	while(ohead!=NULL){
		ohead=ohead->next;
	}
	if(ohead=NULL){
		printf("Ogrenci Mevcut Degil.\nMenuye Donmek Icin Entere Basin:");
		getch();
		system("cls");
		return;
	}
	itoa(ogrenciNo,charOgrenciNo,10);
	strcat(charOgrenciNo,".txt");
	FILE*dosya = fopen(charOgrenciNo,"w");
	while(odkhead!=NULL){
		if(odkhead->ogrenciNo==ogrenciNo && strcmp(odkhead->durum,"KAYITLI")==0){
			fprintf(dosya,"%s\n",odkhead->kod);
		}
		odkhead=odkhead->next;
	}
	fclose(dosya);
	printf("Ders Programi Olusturuldu.\nMenuye Donmek Icin Entere Basin:");
	getch();
	system("cls");
	return;
}
