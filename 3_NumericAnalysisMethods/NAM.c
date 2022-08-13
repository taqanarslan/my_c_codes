#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <conio.h>
#define MAX 100

void turevAlma(double fonksiyon[],double turevliFonksiyon[],int derece);
double sonucBulma(double fonksiyon[],int derece,double deger);
void fonksiyonAlma(double fonksiyon[],int derece);
void bisection(double fonksiyon[],int derece);
void regulafalsi(double fonksiyon[],int derece);
void newtonraphson(double fonksiyon[],int derece,double turevliFonksiyon[]);
void lineSwap(float matris[MAX][MAX],int boyut,int line1,int line2);
void lineMultiply(float matris[MAX][MAX],int boyut,int line,float deger);
void lineMultiplyAdd(float matris[MAX][MAX],int boyut,int line1,int line2,float deger);
void inverseAlma();
void gaussESwap(float matris[MAX][MAX],int boyut,int line1,int line2);
void gaussEMultiply(float matris[MAX][MAX],int boyut,int line,float deger);
void gaussEMultiplyAdd(float matris[MAX][MAX],int boyut,int line1,int line2,float deger);
void gaussEliminasyon();
void gaussSeidel();
int menu();
void trapez();
void simpson();

int main()
{
	
	double fonksiyon[MAX],turevliFonksiyon[MAX];
	int derece,yontem=-1;
	

	while (yontem!=9)
	{
		yontem=menu();
		//Bisection
		if(yontem==1)
		{
			printf("dereceyi girin: ");
			scanf("%d",&derece);
			fonksiyonAlma(fonksiyon,derece);
			bisection(fonksiyon,derece);
		}
		//regula falsi(lineer interpolasyon)
		else if(yontem==2)
		{
			printf("dereceyi girin: ");
			scanf("%d",&derece);
			fonksiyonAlma(fonksiyon,derece);
			regulafalsi(fonksiyon,derece);
		}
		//Newton Raphson
		else if(yontem==3)
		{
			printf("dereceyi girin: ");
			scanf("%d",&derece);
			fonksiyonAlma(fonksiyon,derece);
			turevAlma(fonksiyon,turevliFonksiyon,derece);
			newtonraphson(fonksiyon,derece,turevliFonksiyon);
		}
		//INVERSE ALMA
		else if(yontem==4)
		{
			inverseAlma();
		}
		//GAUSS ELIMINASYON
		else if(yontem==5)
		{
			gaussEliminasyon();
		}
		//GAUSS SEIDEL
		else if(yontem==6)
		{
			gaussSeidel();
		}
		//TRAPEZ
		else if(yontem==7)
		{
			trapez();
		}
		//SIMPSON
		else if(yontem==8)
		{
			simpson();
		}
	}
	printf("Program Sonlandiriliyor...");
	return 0;
}

int menu()
{
	int i;
	system("cls");
	printf("Yontem Seciniz \n(1)Ikiye Bolme \n(2)Lineer Interpolasyon \n(3)Newton Raphson \n(4)Matris Inverse Alma \n(5)GaussEliminasyon \n(6)GaussSeidel \n(7)Trapez\n(8)Simpson\n(9)Cikis\nSecenek= ");
	scanf("%d",&i);
	system("cls");
	return i;
}
void bisection(double fonksiyon[],int derece)
{
	double bas,son,hata,mid;
	int secenek,end=-1,iterasyon=0,flag=0,itersay;
	char trash;
	printf("Belli bir hataya degerine ulasmak icin (1), Belli bir iterasyon sayisina kadar ilerlemek icin (2) girin:");
	scanf("%d",&secenek);
	if(secenek==1)
	{
		do
		{
		printf("Sirasiyla Hata,Baslangic ve Bitis degerini girin:");
		scanf("%lf %lf %lf",&hata,&bas,&son);
		if(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0)
		{
			printf("Zero crossing yok, Tekrar girin: ");
		}
		}while(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0);
		while((son-bas)>=hata && flag==0)
		{
			iterasyon++;
			mid=(son+bas)/2;
			if(sonucBulma(fonksiyon,derece,mid)*sonucBulma(fonksiyon,derece,son)<0)
			{
				bas=mid;
			}
			else if(sonucBulma(fonksiyon,derece,mid)*sonucBulma(fonksiyon,derece,son)>0)
			{
				son=mid;
			}
			else
			{
				flag=1;
			}
		}
		printf("%lf Hata degeri icin,%d. Iterasyonda ulasilan kok= %lf\nMenuye donmek icin entere basin.",hata,iterasyon,mid);
		scanf("%c",&trash);
		scanf("%c",&trash);
	}
	else if(secenek==2)
	{
		do
		{
		printf("Sirasiyla Baslangic, Bitis degerini ve Iterasyon sayisini girin:");
		scanf("%lf %lf %d",&bas,&son,&itersay);
		if(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0)
		{
			printf("Zero crossing yok, Tekrar girin: ");
		}
		}while(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0);
		while(itersay>iterasyon)
		{
			iterasyon++;
			mid=(son+bas)/2;
			if(sonucBulma(fonksiyon,derece,mid)*sonucBulma(fonksiyon,derece,son)<0)
			{
				bas=mid;
			}
			else if(sonucBulma(fonksiyon,derece,mid)*sonucBulma(fonksiyon,derece,son)>0)
			{
				son=mid;
			}
		}
		printf("%d. Iterasyonda ulasilan kok= %lf\nMenuye donmek icin entere basin.",iterasyon,mid);
		scanf("%c",&trash);
		scanf("%c",&trash);
	}
	
}
void regulafalsi(double fonksiyon[],int derece)
{
	double bas,son,hata,c,c2;
	int secenek,end=-1,iterasyon=0,flag=0,itersay;
	char trash;
	printf("Belli bir hataya degerine ulasmak icin (1), Belli bir iterasyon sayisina kadar ilerlemek icin (2) girin:");
	scanf("%d",&secenek);
	if(secenek==1)
	{
		do
		{
		printf("Sirasiyla Hata,Baslangic ve Bitis degerini girin:");
		scanf("%lf %lf %lf",&hata,&bas,&son);
		if(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0)
		{
			printf("Zero crossing yok, Tekrar girin: ");
		}
		}while(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0);
		do
		{
			if(iterasyon>0)
			{
				c2=c;
			}
			c=(bas*sonucBulma(fonksiyon,derece,son)-son*sonucBulma(fonksiyon,derece,bas))/(sonucBulma(fonksiyon,derece,son)-sonucBulma(fonksiyon,derece,bas));
			if(iterasyon==0)
			{
				c2=c+hata+1;
			}
			iterasyon++;
			if(sonucBulma(fonksiyon,derece,c)*sonucBulma(fonksiyon,derece,son)<0)
			{
				bas=c;
			}
			else if(sonucBulma(fonksiyon,derece,c)*sonucBulma(fonksiyon,derece,son)>0)
			{
				son=c;
			}
			else
			{
				flag=1;
			}
		}while(fabs(c-c2)>=hata && flag==0);
		printf("%lf Hata degeri icin,%d. Iterasyonda ulasilan kok= %lf\nMenuye donmek icin entere basin.",hata,iterasyon,c);
		scanf("%c",&trash);
		scanf("%c",&trash);
	}
	else if(secenek==2)
	{
		do
		{
		printf("Sirasiyla Baslangic, Bitis degerini ve Iterasyon sayisini girin:");
		scanf("%lf %lf %d",&bas,&son,&itersay);
		if(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0)
		{
			printf("Zero crossing yok, Tekrar girin: ");
		}
		}while(sonucBulma(fonksiyon,derece,bas)*sonucBulma(fonksiyon,derece,son)>0);
		while(itersay>iterasyon)
		{
			iterasyon++;
			c=(bas*sonucBulma(fonksiyon,derece,son)-son*sonucBulma(fonksiyon,derece,bas))/(sonucBulma(fonksiyon,derece,son)-sonucBulma(fonksiyon,derece,bas));
			if(sonucBulma(fonksiyon,derece,c)*sonucBulma(fonksiyon,derece,son)<0)
			{
				bas=c;
			}
			else if(sonucBulma(fonksiyon,derece,c)*sonucBulma(fonksiyon,derece,son)>0)
			{
				son=c;
			}
		}
		printf("%d. Iterasyonda ulasilan kok= %lf\nMenuye donmek icin entere basin.",iterasyon,c);
		scanf("%c",&trash);
		scanf("%c",&trash);
	}
}
void newtonraphson(double fonksiyon[],int derece,double turevliFonksiyon[])
{
	double hata,x1,x2,turevsizSonuc,turevliSonuc;
	int secenek,end=-1,iterasyon=0,flag=0,itersay;
	char trash;
	printf("Belli bir hataya degerine ulasmak icin (1), Belli bir iterasyon sayisina kadar ilerlemek icin (2) girin:");
	scanf("%d",&secenek);
	if(secenek==1)
	{
		printf("Sirasiyla Hata ve Baslangic degerini girin:");
		scanf("%lf %lf",&hata,&x1);
		x2=x1+hata+1;
		while(fabs(x1-x2)>=hata)
		{
			iterasyon++;
			turevsizSonuc=sonucBulma(fonksiyon,derece,x1);
			turevliSonuc=sonucBulma(turevliFonksiyon,derece-1,x1);
			x2=x1;
			x1=x1-turevsizSonuc/turevliSonuc;
		}
		printf("%lf Hata degeri icin,%d. Iterasyonda ulasilan kok= %lf\nMenuye donmek icin entere basin.",hata,iterasyon,x1);
		scanf("%c",&trash);
		scanf("%c",&trash);
	}
	else if(secenek==2)
	{
		printf("Sirasiyla Gideceginiz Iterasyon Sayisini ve Baslangic degerini girin:");
		scanf("%d %lf",&itersay,&x1);
		x2=x1+hata+1;
		while(itersay>iterasyon)
		{
			iterasyon++;
			turevsizSonuc=sonucBulma(fonksiyon,derece,x1);
			turevliSonuc=sonucBulma(turevliFonksiyon,derece-1,x1);
			x2=x1;
			x1=x1-turevsizSonuc/turevliSonuc;
		}
		printf("%d. Iterasyonda ulasilan kok= %lf\nMenuye donmek icin entere basin.",iterasyon,x1);
		scanf("%c",&trash);
		scanf("%c",&trash);
	}
}
double sonucBulma(double fonksiyon[],int derece,double deger)
{
	double toplam=0,us=1;
	int i;
	for(i=0;i<=derece;i++)
	{
		toplam+=fonksiyon[i]*us;
		us=us*deger;
	}
	return toplam;
}

void turevAlma(double fonksiyon[],double turevliFonksiyon[],int derece)
{
	int i;
	for(i=derece;i>0;i--)
	{
		turevliFonksiyon[i-1]=fonksiyon[i]*i;
	}
}

void fonksiyonAlma(double fonksiyon[],int derece)
{
	int i;
	for(i=derece;i>=0;i--)
	{
		printf("%d. dereceli elemanin katsayisini girin:",i);
		scanf("%lf",&fonksiyon[i]);
	}
}

//SATIRI ÇARPMA
void lineMultiply(float matris[MAX][MAX],int boyut,int line,float deger)
{
	int i;
	for(i=0;i<boyut;i++)
	{
		matris[line][i]=matris[line][i]*deger;
	}
}

//SATIR YER DEÐÝÞTÝRME
void lineSwap(float matris[MAX][MAX],int boyut,int line1,int line2)
{
	float n;
	int i;
	for(i=0;i<boyut;i++)
	{
		n=matris[line1][i];
		matris[line1][i]=matris[line2][i];
		matris[line2][i]=n;
	}
}

//SATIRI ÇARPIP DÝÐER SATIRA EKLEME
void lineMultiplyAdd(float matris[MAX][MAX],int boyut,int line1,int line2,float deger)
{
	float n;
	int i;
	for(i=0;i<boyut;i++)
	{
		matris[line2][i]=matris[line2][i]+matris[line1][i]*deger;
	}
}

void inverseAlma()
{
		float matris1[MAX][MAX],matris2[MAX][MAX]={0};
	int boyut,i,j,k;
	
	printf("Tersini Alacaginiz Matrisin Boyutunu Girin:");
	scanf("%d",&boyut);
	
	for(i=0;i<boyut;i++)
	{
		matris2[i][i]=1;
		for(j=0;j<boyut;j++)
		{
			printf("[%d,%d]'yi Girin: ",i,j);
			scanf("%f",&matris1[i][j]);
		}
	}
	//lineSwap(matris1,boyut,0,1);
	//lineMultiply(matris1,boyut,0,(1/matris1[0][0]));
	//lineMultiplyAdd(matris1,boyut,0,1,3.5);
	
	//0-0 1-1 2-2 gibi satýrlarýn 0 olmasýný engelleme.
	for(i=0;i<boyut;i++)
	{
		if(matris1[i][i]==0)
		{
			k=i+1;
			while(matris1[i][k]==0 && k<boyut-1)
			{
				k++;
			}
			if(k<boyut)
			{
			lineSwap(matris1,boyut,i,k);
			lineSwap(matris2,boyut,i,k);
			}
			else
			{
				printf("Determinant 0, Tersi yok.");
				return;
			}
		}
		//ilk i-i (0,0 1,1 2,2...)yi 1 yapma
		lineMultiply(matris2,boyut,i,(1/matris1[i][i]));
		lineMultiply(matris1,boyut,i,(1/matris1[i][i]));
		
		//olduðumuz sütunun aþaðýsýndaki bütün sayýlarý 0 yapma.
		for(j=i+1;j<boyut;j++)
		{
			lineMultiplyAdd(matris2,boyut,i,j,(-1)*matris1[j][i]);
			lineMultiplyAdd(matris1,boyut,i,j,(-1)*matris1[j][i]);	
		}
	}
	//ters yönde iþlemi tekrarlayarak ilk matrisi birim matrise çevirme
	for(i=boyut-1;i>0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			lineMultiplyAdd(matris2,boyut,i,j,(-1)*matris1[j][i]);
			lineMultiplyAdd(matris1,boyut,i,j,(-1)*matris1[j][i]);
		}
	}
	
	printf("\n\nGIRILEN MATRISIN INVERSI:\n");
	
	for(i=0;i<boyut;i++)
		{
			for(j=0;j<boyut;j++)
			{
				printf("%.2f  ",matris2[i][j]);
			}
			printf("\n");
		}
	
	printf("\n\nMenuye Donmek Icin Entere Basin: ");
	getch();
}

//GAUSS Eliminasyon Ýçin SATIRI ÇARPMA
void gaussEMultiply(float matris[MAX][MAX],int boyut,int line,float deger)
{
	int i;
	for(i=0;i<boyut;i++)
	{
		matris[line][i]=matris[line][i]*deger;
	}
}

//GAUSS Eliminasyon Ýçin SATIR YER DEÐÝÞTÝRME
void gaussESwap(float matris[MAX][MAX],int boyut,int line1,int line2)
{
	float n;
	int i;
	for(i=0;i<boyut;i++)
	{
		n=matris[line1][i];
		matris[line1][i]=matris[line2][i];
		matris[line2][i]=n;
	}
}

//GAUSS Eliminasyon Ýçin SATIRI ÇARPIP DÝÐER SATIRA EKLEME
void gaussEMultiplyAdd(float matris[MAX][MAX],int boyut,int line1,int line2,float deger)
{
	float n;
	int i;
	for(i=0;i<boyut;i++)
	{
		matris[line2][i]=matris[line2][i]+matris[line1][i]*deger;
	}
}

void gaussEliminasyon()
{
	float matris[MAX][MAX],degiskenler[MAX]={0};
	int denklemSayisi,degiskenSayisi,i,j,k;
	do
	{
	printf("Denklem Sayisini Girin: ");
	scanf("%d",&denklemSayisi);
	printf("Degisken Sayisini Girin: ");
	scanf("%d",&degiskenSayisi);
	if(denklemSayisi<degiskenSayisi)
	{
		printf("denklem sayisi degisken sayisina esit olmalidir lutfen tekrar girin\n");
	}
	}while(denklemSayisi!=degiskenSayisi);
	
	for(i=0;i<denklemSayisi;i++)
	{
		for(j=0;j<=degiskenSayisi;j++)
		{
			if(j<degiskenSayisi)
			{
				printf("%d. denklemin %d. degiskeninin katsayisini girin: ",i+1,j+1);
			}
			else
			{
				printf("%d. denklemin sonucunu girin: ",i+1);
			}
			scanf("%f",&matris[i][j]);
		}
	}
	
	for(i=0;i<degiskenSayisi;i++)
	{
		if(matris[i][i]==0)
		{
			k=i+1;
			while(matris[i][k]==0 && k<degiskenSayisi-1)
			{
				k++;
			}
			if(k<degiskenSayisi)
			{
			gaussESwap(matris,degiskenSayisi+1,i,k);
			}
			else
			{
				printf("Determinant 0, Tersi yok.");
				return ;
			}
		}
		//ilk i-i (0,0 1,1 2,2...)yi 1 yapma
		gaussEMultiply(matris,degiskenSayisi+1,i,(1/matris[i][i]));
		//olduðumuz sütunun aþaðýsýndaki bütün sayýlarý 0 yapma.
		for(j=i+1;j<degiskenSayisi;j++)
		{
			gaussEMultiplyAdd(matris,degiskenSayisi+1,i,j,(-1)*matris[j][i]);	
		}
	}
	
	printf("\n\n");
	
	for(i=degiskenSayisi-1;i>=0;i--)
	{
		degiskenler[i]=matris[i][degiskenSayisi];
	}
	for(i=degiskenSayisi-1;i>=0;i--)
	{
		for(j=degiskenSayisi-1;j>=0;j--)
		{
			if(i!=j)
			{
				degiskenler[i]-=matris[i][j]*degiskenler[j];
			}
		}
	}
	
	
	for(i=0;i<degiskenSayisi;i++)
	{
		printf("%d. degisken = %f\n",i+1,degiskenler[i]);
	}
	printf("\n\nMenuye Donmek Icin Entere Basin: ");
	getch();
}

void gaussSeidel()
{
	float degiskenler1[3],degiskenler2[3];
	float hata,matris[MAX][MAX];
	int maxIterasyon,iterasyon,i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(j<3)
			{
				printf("%d. denklemin %d. degiskenin degerini girin: ",i+1,j+1);
			}
			else
			{
				printf("%d. denklemin sonucunu girin:",i+1);
			}
			scanf("%f",&matris[i][j]);
		}
	}
	
	printf("aranan hata degerini ve gidilecek maximum iterasyon sayisini sirasiyla girin(aralarinda bir bosluk ile): ");
	scanf("%f %d",&hata,&maxIterasyon);
	
	for(i=0;i<3;i++)
	{
		printf("%d. degiskenin baslangic degerini girin: ",i+1);
		scanf("%f",&degiskenler1[i]);
	}
	
	iterasyon=0;
	
	do
	{
		degiskenler2[0]=degiskenler1[0];
		degiskenler2[1]=degiskenler1[1];
		degiskenler2[2]=degiskenler1[2];
		degiskenler1[0]=(matris[0][3]-degiskenler1[2]*matris[0][2]-degiskenler1[1]*matris[0][1])/matris[0][0];
		degiskenler1[1]=(matris[1][3]-degiskenler1[2]*matris[1][2]-degiskenler1[0]*matris[1][0])/matris[1][1];
		degiskenler1[2]=(matris[2][3]-degiskenler1[1]*matris[2][1]-degiskenler1[0]*matris[2][0])/matris[2][2];
		iterasyon++;
	}while(((fabs(degiskenler1[0]-degiskenler2[0])>hata) || (fabs(degiskenler1[1]-degiskenler2[1])>hata) || (fabs(degiskenler1[2]-degiskenler2[2])>hata))&& iterasyon<maxIterasyon);
	
	printf("x1=%f x2=%f x3=%f",degiskenler1[0],degiskenler1[1],degiskenler1[2]);
	printf("\n\nMenuye Donmek Icin Entere Basin: ");
	getch();
}

void trapez()
{
	double trapezfonk[MAX],a,b,h,sum=0;
	int n,i,j,derece;
	
	printf("Dereceyi Girin: ");
	scanf("%d",&derece);
	fonksiyonAlma(trapezfonk,derece);
	printf("N degerini girin: ");
	scanf("%d",&n);
	printf("Araligi Girin(Kucukten Buyuge Aralarinda Bir Bosluk Ile): ");
	scanf("%lf %lf",&a,&b);
	h=(b-a)/n;
	for(i=0;i<n;i++)
	{
		sum+=(sonucBulma(trapezfonk,derece,a)+sonucBulma(trapezfonk,derece,a+h))*h/2;
		a+=h;
	}
	printf("Alan degeri=%.2f",sum);
	printf("\n\nmenuye donmek icin entere basin: ");
	getch();
}

void simpson()
{
	double simpsonfonk[MAX],a,b,h,sum=0;
	int n,i,derece;
	
	printf("Dereceyi Girin: ");
	scanf("%d",&derece);
	fonksiyonAlma(simpsonfonk,derece);
	do
	{
	printf("N degerini girin: ");
	scanf("%d",&n);
	if(n%2!=0)
	{
		printf("N degeri cift olmali. Lutfen tekrar girin\n");
	}
	}while(n%2!=0);
	printf("Araligi Girin(Kucukten Buyuge Aralarinda Bir Bosluk Ile): ");
	scanf("%lf %lf",&a,&b);
	h=(b-a)/n;
	sum+=sonucBulma(simpsonfonk,derece,a)+sonucBulma(simpsonfonk,derece,b);
	for(i=1;i<n;i++)
	{
		a+=h;
		if(i%2!=0)
		{
			sum+=4*sonucBulma(simpsonfonk,derece,a);
		}
		else
		{
			sum+=2*sonucBulma(simpsonfonk,derece,a);
		}
	}
	sum=sum*h/3;
	printf("Alan degeri=%.2f",sum);
	
	printf("\n\nmenuye donmek icin entere basin: ");
	getch();
}
