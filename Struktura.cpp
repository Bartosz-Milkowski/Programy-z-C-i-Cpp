#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
    struct Struktura
{
int in;
char c;
float f;
};
Struktura **losowanie (int N)
{
srand( time( NULL ) );
int z=0;
struct Struktura** tablica=(struct Struktura**) malloc(N*sizeof(struct Struktura*));
for (int i = 1; i <= N; i++){
tablica[i]=(struct Struktura*) malloc(sizeof(struct Struktura));
tablica[i]->in = ( rand() % 10000 ) - 1000;
while(1){
    z=0;
for (int j = 1; j < i; j++){
        if(tablica[j]->in==tablica[i]->in){
            tablica[i]->in = ( rand() % 10000 ) - 1000;
            z=1;}}
            if (z==0) break;
            }
tablica[i]->c = ( rand() % 22 ) + 66;
tablica[i]->f = 1000+i;}
return tablica;
}
void kasowanie (Struktura **tablica,int N){
    for (int i = 1; i <= N; i++){
free(tablica[i]);}
free(*tablica);
}
void sortowanie (Struktura **tablica,int N){
    int z;
Struktura tmp;
    for (int i = 1; i <= N-1; i++){
            z=0;
    for (int j = 1; j <= N-1; j++){
            if (tablica[j]->in>tablica[j+1]->in){
                z=1;
tmp=*tablica[j];
*tablica[j]=*tablica[j+1];
*tablica[j+1]=tmp;}}
                if(z==0){
                    break;}
            }
            for (int i = 1; i <= N; i++){
    if(i<=20){
            printf("Strukura %.0f\n", tablica[i]->f - 1000);
            printf("%d\n", tablica[i]->in);
            printf("%c\n", tablica[i]->c);
            printf("%.0f\n", tablica[i]->f);
}}
}
void zliczanie_znakow (Struktura **tablica,int N, char X){
    int licznik=0;
   for (int i = 1; i <= N; i++){
        if(tablica[i]->c==X){
            licznik++;}}
printf("Liczba wystapien znaku  %c", X);
printf(": %d\n", licznik);
}
int main()
{
int N;
char X;
Struktura **tablica;
FILE* fp = fopen("inlab01.txt", "r");
if (fp == NULL)
return -1;
fscanf (fp, "%d %c", &N, &X);
fclose(fp);
clock_t begin, end;
double czas;
begin = clock();
tablica=losowanie(N);
sortowanie (tablica,N);
zliczanie_znakow (tablica,N,X);
kasowanie(tablica,N);
end = clock();
czas = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Czas wykonania programu : %.4f\n", czas);
return 0;
}
