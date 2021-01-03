#include <stdio.h>
#include <conio.h>

/*<--------------MAIN FUNCTION--------------->*/ 
//Mine Nur Kaya 1821012089
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;
printf("Lutfen Max Degerleri , Atanan Degerleri ve Musait (Kullanilabilir)Degerleri girerken araya bir bosluk birakiniz!");
printf("\n \n Kac adet P degeri oldugunu girin : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	completed[i] = 0;

printf("\n\n Kac Adet Kaynak oldugunu girin : ");
scanf("%d", &r);

printf("\n\nP deðerlerinin Max Matrisini her P deðeri için girin : ");
for(i = 0; i < p; i++)
{
	printf("\n P %d : ", i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}
//Mine Nur Kaya 1821012089
printf("\n\n P Degerlerine atanan degerleri girin : ");
for(i = 0; i < p; i++)
{
	printf("\nP %d : ",i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);	
}

printf("\n\n Musait Kaynak Degerlerini girin : ");
for(i = 0; i < r; i++)
		scanf("%d", &avail[i]);	


	for(i = 0; i < p; i++)
		for(j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];
		
do
{
	printf("\n Max matris:\t Atama matrisi:\n");
	for(i = 0; i < p; i++)
	{
		for( j = 0; j < r; j++)
			printf("%d  ", Max[i][j]);
		printf("\t\t");
		for( j = 0; j < r; j++)
			printf("%d  ", alloc[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)//Tamamlanmadýysa
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if(avail[j] < need[i][j])
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
		printf("\n Islemler ( %d )Basariyla tamamlandi!", process + 1);
		safeSequence[count] = process + 1;
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
//Mine Nur Kaya 1821012089
if(count == p)
{
	printf("\nSistem guvenli alanda!!\n");
	printf("Güvenli Sýra : < ");
	for( i = 0; i < p; i++)
			printf(" P %d , ", safeSequence[i]);
	printf(">\n");
}
else
	printf("\nSistem guvensiz alanda!!");
getch();
}
