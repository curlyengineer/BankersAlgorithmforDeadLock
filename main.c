#include <stdio.h>
#include <conio.h>

/*<--------------MAIN FUNCTION--------------->*/ 
//Mine Nur Kaya 
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10],availl[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;
printf("Lutfen Max Degerleri , Atanan Degerleri ve Musait (Kullanilabilir)Degerleri girerken araya bir bosluk birakiniz!");
printf("\n \n Kac adet P degeri oldugunu girin : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	completed[i] = 0;

printf("\n\n Kac Adet Kaynak oldugunu girin : ");
scanf("%d", &r);

printf("\n\nP değerlerinin Max Matrisini her P değeri için girin : ");
for(i = 0; i < p; i++)
{
	printf("\n P %d : ", i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}
//Mine Nur Kaya 
printf("\n\n P Degerlerine atanan degerleri girin : ");
for(i = 0; i < p; i++)
{
	printf("\nP %d : ",i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);	
}

printf("\n\n Toplam Kaynak Degerlerini girin : ");
for(i = 0; i < r; i++)
		scanf("%d", &availl[i]);	
		
		
	// kullanılabilir kaynakların bulunduğu alan
int countt[5]={0,0,0,0,0};
for(i = 0; i < r; i++){
	for(j = 0; j < p; j++)	
{    
countt[i]=alloc[j][i]+countt[i];
}
avail[i]=availl[i]-countt[i];
}

//İhtiyaçların bulunması
	for(i = 0; i < p; i++)
		for(j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];
		
do
{
	printf("\n Max matris:\t Atama matrisi:\t Her bir P degeri icin Kullanilabilir kaynaklar :\n");
	for(i = 0; i < p; i++)
	{
		for( j = 0; j < r; j++)
			printf("%d  ", Max[i][j]);
		printf("\t\t");
		for( j = 0; j < r; j++)
			printf("%d  ", alloc[i][j]);
		printf("\t\t");
		for (j=0;j<r;j++)
		printf("%d ",avail[j]);
			printf("\n");	
	}
//ihtiyac matrisi ve kullanılabilir kaynakların bakıldığı kod bloğu
	process = -1;

	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)//Tamamlanmadıysa
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if( need[i][j] >avail[j] )
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\n Islem (P %d )Basariyla tamamlandi!", process +1);
		safeSequence[count] = process +1;
		count++;
		for(j = 0; j < r; j++)
		{
			avail[j] += alloc[process][j];
			alloc[process][j] = 0;
			Max[process][j] = 0;
			completed[process] = 1;
		}
	}
}while(count != p && process != -1);
//Mine Nur Kaya 
if(count == p)
{
	printf("\nSistem guvenli alanda!!\n");
	printf("Guvenli Sira : < ");
	for( i = 0; i < p; i++)
			printf(" P %d , ", safeSequence[i]);
	printf(">\n");
}
else
	printf("\nSistem guvensiz alanda!!");
getch();
}
