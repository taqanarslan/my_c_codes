#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#define MAX 100


int main()
{
	int p,q,n,totient,e,d,prime[8]={11,13,17,19,23,29,31,37},i,j,k,karmasikliktutucu[50]={0},a=0,deger,toplamkarmasiklik=0;
	char metin[MAX],metin2[MAX],trash;
	unsigned long int sayiTutma[MAX],t;
	srand(time(NULL));

	printf("islemi kac kere tekrarlamak istiyorsunuz?");
	scanf("%d",&deger);
	scanf("%c",&trash);
	
	while(a<deger)
	{
		printf("metni giriniz: ");
		gets(metin);
		printf("asal random 2 sayi olusturuluyor\n");
		//asal sayilari random secme
		p=prime[rand()%8];
	
		printf("secilen 1. asal sayi= %d\n",p);
		q=p;
		do
		{
			q=prime[rand()%6];
		}while(q==p);
		printf("secilen 2. asal sayi= %d\n",q);
	
		n=p*q;
		totient=(p-1)*(q-1);
		printf("totient fonksiyonu degeri= %d\nn degeri= %d\n",totient,n);
		
		//en kucuk e degerini bulma
		e=2;
		i=2;
		while (i<=e)
		{
			if(e%i==0 && totient%i==0)
			{
				e++;
				i=2;
			}
			else
			{
				i++;
			}
		}
		printf("bulunan e degeri= %d\n",e);
		//d degerini hesaplama      d*e=1modtotient
		d=2;
		while((d*e)%totient!=1)
		{
			d=rand()%(totient-2);
			d+=2;
		}
		printf("bulunan d degeri= %d\n",d);

		//Sifreleme A=65   65^e%n 93
		j=strlen(metin);
		for(i=0;i<j;i++)
		{
			sayiTutma[i]=metin[i];
			t=sayiTutma[i];
			for(k=0;k<e-1;k++)
			{
				t*=sayiTutma[i];
				t=t%n;
				karmasikliktutucu[a]++;
			}
			sayiTutma[i]=t;
			metin[i]=sayiTutma[i];
		}
		//Desifre Etme 93^d%n  65
		for(i=0;i<j;i++)
		{
			t=sayiTutma[i];
			for(k=0;k<d-1;k++)
			{
				t*=sayiTutma[i];
				t=t%n;
				karmasikliktutucu[a]++;
			}
			metin2[i]=t;
		}
		metin2[i]=NULL;
		printf("Metnin Sifrelenmis Hali:");
		for(i=0;i<j;i++)
		{
			printf("%d ",sayiTutma[i]);
		}
		printf("\n");
		printf("Metnin Desifre Edilmis Hali:");
		puts(metin2);
		toplamkarmasiklik+=karmasikliktutucu[a];
		a++;
		if(a<deger)
		{
			printf("\ndevam etmek icin entere basin\n");
			getch();
		}
		else
		{
			printf("\n");
		}
		for(i=0;i<j;i++)
		{
			metin[i]=0;
			metin2[i]=0;
		}
	}
	
	printf("Zaman olcum tablosu:");
	for(i=0;i<deger;i++)
	{
		karmasikliktutucu[i]=karmasikliktutucu[i]*50/toplamkarmasiklik;
		printf("\n");
		printf("%d. Islem Icin Karmasiklik: ",i+1);
		for(j=0;j<karmasikliktutucu[i];j++)
		{
			printf("*");
		}
	}
	
	
	
	
	return 0;
}
