//SDIZO I1 221A LAB03
//Bartosz Mi³kowski
//mb41449@zut.edu.pl
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int licznik=0;
struct elementy {
int klucz;
elementy *lewo;
elementy *prawo;
char tab[10];
elementy();
};
elementy::elementy(){
lewo=0;
prawo=0;
}
class drzewo
{   public:
    elementy *korzen;
    void szukaj(int klucz);
    void wstaw(int klucz);
    void wstaw2(int X);
    int usun (int klucz);
    void wyswietl(int wybor);
    void wyswietl_pre(elementy* korzen);
    void wyswietl_in(elementy* korzen);
    void wyswietl_post(elementy* korzen);
    drzewo();
};
drzewo::drzewo(){
korzen=0;
}
void drzewo::wstaw(int klucz)
{
    int o=0;
    elementy *nowy = new elementy;
     elementy *rodzic=korzen;
      elementy *temp=korzen;
nowy->lewo = 0;
nowy->prawo = 0;
nowy->klucz = klucz;
itoa(klucz,nowy->tab,10);
if (korzen == 0){
    korzen=nowy;}
else{
    o=0;
    temp=korzen;
    while (temp!= 0 ){
              if(klucz==temp->klucz){
                o=1;
                break;}
                rodzic=temp;
if(klucz<rodzic->klucz){
        temp=temp->lewo;
        }
     else {
        temp=temp->prawo;
        }
                 }
                if(o==1)
        puts("Jest taki klucz. Podaj inny\n");
        else if (rodzic->klucz>klucz){
    rodzic->lewo=nowy;
    }
        else{
            rodzic->prawo=nowy;
             }
    }
        }
void drzewo::wstaw2(int X)
{
    int o=0;
 srand(time(NULL));
  elementy *rodzic=korzen;
  elementy *temp=korzen;
    for(int i=1; i<=X; i++){
    elementy *nowy = new elementy;
    rodzic=korzen;
nowy->lewo = 0;
nowy->prawo = 0;
nowy->klucz = (rand() %20000)-10000;
itoa(nowy->klucz,nowy->tab,10);
if (korzen == 0){
    korzen=nowy;
}
else{
        while(1){
    o=0;
    temp=korzen;
    while (temp!= 0 ){
              if(nowy->klucz==temp->klucz){
                    nowy->klucz = (rand() %20000)-10000;
                o=1;
                break;}
                rodzic=temp;
  if(nowy->klucz<rodzic->klucz){
        temp=temp->lewo;
        }
     else {
        temp=temp->prawo;
        }
                 }
                  if(o==0)
                    break;
                  }
    if (rodzic->klucz>nowy->klucz){
    rodzic->lewo=nowy;
    }
        else{
            rodzic->prawo=nowy;
             }
    }
    }}
void drzewo::szukaj(int klucz)
{
 elementy *temp=korzen;
    while(temp != 0 && klucz != temp->klucz){

    if(klucz<temp->klucz)
        temp=temp->lewo;
    else
        temp=temp->prawo;
   }
        if(temp!=0)
        puts("Jest taki klucz.\n");
        else
            puts("Nie ma takiego klucza.\n");
    }
    int drzewo::usun (int klucz)
{
     elementy *temp = korzen;
     elementy *rodzic = korzen;
     elementy *pop;
     elementy *prodzic;
     elementy *rpop;
        while(temp != 0 && klucz != temp->klucz){
                rodzic=temp;
        if (klucz>temp->klucz)
        temp=temp->prawo;
        else
            temp=temp->lewo;}
       if (temp == 0 ){
            puts("Nie ma takiego klucza\n");
       return 0;}
        if (temp->lewo == 0 && temp->prawo == 0)
        {
            if (temp == korzen){
                    korzen=0;
                    return 0;}
if (rodzic->prawo == temp) rodzic->prawo = 0;
else rodzic->lewo = 0;
return 0;}
 if (temp->prawo == 0) {
  if (temp == rodzic) korzen = temp->lewo;
  else if (rodzic->prawo == temp)
    rodzic->prawo = temp->lewo;
  else
    rodzic->lewo = temp->lewo;
    return 0;}
 if (temp->lewo == 0) {
  if (temp == rodzic) korzen = temp->prawo;
  else if (rodzic->prawo == temp)
    rodzic->prawo = temp->prawo;
  else
    rodzic->lewo = temp->prawo;
    return 0;}
    prodzic = temp;
pop = temp->lewo;
while(pop->prawo != 0)
{
prodzic = pop;
pop = pop->prawo;
}
if (pop == temp->lewo)
{
if (temp == korzen) korzen = temp->lewo;
else if (rodzic->prawo == temp) {
        pop->prawo=temp->prawo;
    rodzic->prawo = pop;}
else { pop->prawo=temp->prawo;
        rodzic->lewo = pop;}
return 0;
}
 rpop = pop->lewo;
if (prodzic->prawo == pop) prodzic->prawo = rpop;
else prodzic->lewo = rpop;
pop->lewo = temp->lewo;
pop->prawo = temp->prawo;
if (temp == korzen) korzen = pop;
else if (rodzic->prawo == temp)
rodzic->prawo = pop;
else
rodzic->lewo = pop;
return 0;
}
void drzewo::wyswietl(int wybor)
{
    if(wybor==1){
wyswietl_pre(korzen);
printf(" Liczba odwiedzonych wezlow :  %d\n", licznik);}
licznik=0;
if(wybor==2){
wyswietl_in(korzen);
printf(" Liczba odwiedzonych wezlow :  %d\n", licznik);}
licznik=0;
if(wybor==3){
wyswietl_post(korzen);
printf(" Liczba odwiedzonych wezlow :  %d\n", licznik);}
    }
void drzewo::wyswietl_pre(elementy* korzen){
        elementy *temp=korzen;
        printf(" %d\n", temp->klucz);
        licznik++;
  if(temp->lewo!=0){
    wyswietl_pre(temp->lewo);}
    if(temp->prawo!=0){
    wyswietl_pre(temp->prawo);}
}
    void drzewo::wyswietl_in(elementy* korzen){
        elementy *temp=korzen;
  if(temp->lewo!=0){
    wyswietl_in(temp->lewo);}
    printf(" %d\n", temp->klucz);
    licznik++;
    if(temp->prawo!=0){
    wyswietl_in(temp->prawo);}
}
void drzewo::wyswietl_post(elementy* korzen){
        elementy *temp=korzen;
  if(temp->lewo!=0){
    wyswietl_post(temp->lewo);}
    if(temp->prawo!=0){
    wyswietl_post(temp->prawo);}
    printf(" %d\n", temp->klucz);
    licznik++;
}
int main()
{
    drzewo *baza = new drzewo;
    int X,klucz1,klucz2,klucz3,klucz4;
FILE* fp = fopen("inlab03.txt", "r");
if (fp == NULL)
return -1;
fscanf (fp, "%d %d %d %d %d", &X, &klucz1, &klucz2, &klucz3, &klucz4);
fclose(fp);
clock_t begin, end;
double czas;
begin = clock();
baza->usun(klucz1);
baza->wstaw(klucz1);
baza->wstaw2(X);
baza->wyswietl(2);
baza->wyswietl(1);
baza->wstaw(klucz2);
baza->wyswietl(2);
baza->wstaw(klucz3);
baza->wstaw(klucz4);
baza->usun(klucz1);
baza->wyswietl(1);
baza->szukaj(klucz1);
baza->usun(klucz2);
baza->wyswietl(2);
baza->usun(klucz3);
baza->usun(klucz4);
end = clock();
czas = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Czas wykonania programu : %.4f\n", czas);
    return 0;
}
