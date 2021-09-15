#include <iostream>
#include <string>
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
int balans;
};
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
    int o=0,d=0,a=0,b;
    elementy *nowy = new elementy;
    elementy *t[15];
     elementy *rodzic=0;
      elementy *temp=korzen;
      elementy *dziadek=0;
  elementy *pradziadek=0;
      elementy *tmp=0;
nowy->lewo = 0;
nowy->prawo = 0;
nowy->klucz = klucz;
nowy->balans = 0;
//nowy->tab = klucz;
if (korzen == 0){
    korzen=nowy;}
else{
    o=0;
    temp=korzen;
    while (temp!= 0 ){
              if(klucz==temp->klucz){
                o=1;
                break;}
                t[a]=temp;
                a++;
                 pradziadek=dziadek;
                dziadek=rodzic;
                rodzic=temp;
 if(nowy->klucz<rodzic->klucz){
        temp->balans --;
        cout<<"lewo "<<temp->balans<<endl;
        temp=temp->lewo;
        }
     else {
         temp->balans ++;
          cout<<"prawo "<<temp->balans<<endl;
        temp=temp->prawo;
        }
                 }
                if(o==1)
        puts("Jest taki klucz. Podaj inny\n");
        else     if (rodzic->klucz>nowy->klucz){
    rodzic->lewo=nowy;
    t[a]=nowy;
    }
        else{
            rodzic->prawo=nowy;
            t[a]=nowy;
             }
    cout<<"jest"<<endl;
    cout<<korzen<<" korzen"<<endl;
    for(int i=0; i<a; i++)
       cout<<t[i]<<" pierwsza"<<endl;
    if (rodzic->balans==0){
                temp=korzen;
                 while (temp!= rodzic ){
  if(nowy->klucz<temp->klucz){
        temp->balans ++;
        temp=temp->lewo;
        }
     else {
         temp->balans --;
        temp=temp->prawo;
        }
        }}
        else if(dziadek!=0){
    while(t[0]!=rodzic){
            d=0;
            b=a-2;
            tmp=0;
    nowy=t[a];
    rodzic=t[a-1];
    if(b>=0)
    dziadek=t[b];
    b=a-3;
    if(b>=0)
    pradziadek=t[b];
    for(int i=0; i<a; i++)
       cout<<t[i]<<" druga"<<endl;
    a--;
            if(dziadek->balans == 2 || dziadek->balans == -2){
                if(dziadek->balans<0 && rodzic->balans<0){
                      if(dziadek==korzen){
korzen=rodzic;
tmp=rodzic->prawo;
rodzic->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
else{
        if(pradziadek->lewo==dziadek)
pradziadek->lewo=rodzic;
else
    pradziadek->prawo=rodzic;
tmp=rodzic->prawo;
rodzic->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
}
else if(dziadek->balans>0 && rodzic->balans>0){
        if(dziadek==korzen){
korzen=rodzic;
tmp=rodzic->lewo;
rodzic->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
else{
    if(pradziadek->lewo==dziadek)
pradziadek->lewo=rodzic;
else
    pradziadek->prawo=rodzic;
tmp=rodzic->lewo;
rodzic->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
}
else if(dziadek->balans<0 && rodzic->balans>0){
   if(dziadek==korzen){
korzen->lewo=nowy;
tmp=nowy->lewo;
nowy->lewo=rodzic;
rodzic->prawo=tmp;
korzen=nowy;
tmp=nowy->prawo;
nowy->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
nowy->balans=0;
d=2;}
else{
dziadek->lewo=nowy;
tmp=nowy->lewo;
nowy->lewo=rodzic;
rodzic->prawo=tmp;
if(pradziadek->lewo==dziadek)
pradziadek->lewo=nowy;
else
    pradziadek->prawo=nowy;
tmp=nowy->prawo;
nowy->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
nowy->balans=0;
d=2;}
}
else if(dziadek->balans>0 && rodzic->balans<0){
    if(dziadek==korzen){
korzen->prawo=nowy;
tmp=nowy->prawo;
nowy->prawo=rodzic;
rodzic->lewo=tmp;
korzen=nowy;
tmp=nowy->lewo;
nowy->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
nowy->balans=0;
d=2;}
else {
dziadek->prawo=nowy;
tmp=nowy->prawo;
nowy->prawo=rodzic;
rodzic->lewo=tmp;
if(pradziadek->lewo==dziadek)
pradziadek->lewo=nowy;
else
    pradziadek->prawo=nowy;
tmp=nowy->lewo;
nowy->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
nowy->balans=0;
d=2;}
}
temp=korzen;
if(d==1){
                 while (temp!= rodzic ){
  if(nowy->klucz<temp->klucz){
        temp->balans ++;
        temp=temp->lewo;
        }
     else {
         temp->balans --;
        temp=temp->prawo;
        }}}
        if(d==2){
                 while (temp!= nowy ){
  if(nowy->klucz<temp->klucz){
        temp->balans ++;
        temp=temp->lewo;
        }
     else {
         temp->balans --;
        temp=temp->prawo;
        }}}
        }
 if(d==1 || d==2){
    break;}
 if(b==-2){
    break;}
 }
     }}}
void drzewo::wstaw2(int X)
{
    int o=0,d=0,a=0,b;
 srand(time(NULL));
  elementy *rodzic=0;
  elementy *t[15];
     elementy *dziadek=0;
  elementy *pradziadek=0;
  elementy *temp=korzen;
  elementy *tmp=0;
    for(int i=1; i<=X; i++){
    elementy *nowy = new elementy;
    rodzic=korzen;
    a=0;
nowy->lewo = 0;
nowy->prawo = 0;
nowy->klucz = (rand() %20000)-10000;
nowy->balans = 0;
if (korzen == 0){
    korzen=nowy;
}
else{
        while(1){
    o=0;
    temp=korzen;
     rodzic=0;
     dziadek=0;
  pradziadek=0;
  tmp=0;
  a=0;
    while (temp!= 0 ){
              if(nowy->klucz==temp->klucz){
                    nowy->klucz = (rand() %20000)-10000;
                o=1;
                break;}
                t[a]=temp;
                a++;
                pradziadek=dziadek;
                dziadek=rodzic;
                rodzic=temp;

  if(nowy->klucz<rodzic->klucz){
        temp->balans --;
        cout<<"lewo "<<temp->balans<<endl;
        temp=temp->lewo;
        }
     else {
         temp->balans ++;
          cout<<"prawo "<<temp->balans<<endl;
        temp=temp->prawo;
        }
                 }
                  if(o==0)
                    break;
                  }
    if (rodzic->klucz>nowy->klucz){
    rodzic->lewo=nowy;
    t[a]=nowy;
    }
        else{
            rodzic->prawo=nowy;
            t[a]=nowy;
             }
    cout<<"jest"<<endl;
    cout<<korzen<<" korzen"<<endl;
    for(int i=0; i<a; i++)
       cout<<t[i]<<endl;
    if (rodzic->balans==0){
                temp=korzen;
                 while (temp!= rodzic ){
  if(nowy->klucz<temp->klucz){
        temp->balans ++;
        temp=temp->lewo;
        }
     else {
         temp->balans --;
        temp=temp->prawo;
        }
        }}
        else if(dziadek!=0){
   while(t[0]!=rodzic){
            d=0;
            b=a-2;
            tmp=0;
    nowy=t[a];
    rodzic=t[a-1];
    if(b>=0)
    dziadek=t[b];
    b=a-3;
    if(b>=0)
    pradziadek=t[b];
    for(int i=0; i<a; i++)
       cout<<t[i]<<" druga"<<endl;
    a--;
            if(dziadek->balans == 2 || dziadek->balans == -2){
                if(dziadek->balans<0 && rodzic->balans<0){
                      if(dziadek==korzen){
korzen=rodzic;
tmp=rodzic->prawo;
rodzic->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
else{
        if(pradziadek->lewo==dziadek)
pradziadek->lewo=rodzic;
else
    pradziadek->prawo=rodzic;
tmp=rodzic->prawo;
rodzic->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
}
else if(dziadek->balans>0 && rodzic->balans>0){
        if(dziadek==korzen){
korzen=rodzic;
tmp=rodzic->lewo;
rodzic->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
else{
    if(pradziadek->lewo==dziadek)
pradziadek->lewo=rodzic;
else
    pradziadek->prawo=rodzic;
tmp=rodzic->lewo;
rodzic->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(nowy->lewo!=0 && nowy->prawo!=0)
nowy->balans=0;
else if(nowy->lewo!=0)
nowy->balans=-1;
else if(nowy->prawo!=0)
nowy->balans=1;
else nowy->balans=0;
rodzic->balans=0;
d=1;}
}
else if(dziadek->balans<0 && rodzic->balans>0){
   if(dziadek==korzen){
korzen->lewo=nowy;
tmp=nowy->lewo;
nowy->lewo=rodzic;
rodzic->prawo=tmp;
korzen=nowy;
tmp=nowy->prawo;
nowy->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
nowy->balans=0;
d=2;}
else{
dziadek->lewo=nowy;
tmp=nowy->lewo;
nowy->lewo=rodzic;
rodzic->prawo=tmp;
if(pradziadek->lewo==dziadek)
pradziadek->lewo=nowy;
else
    pradziadek->prawo=nowy;
tmp=nowy->prawo;
nowy->prawo=dziadek;
dziadek->lewo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
nowy->balans=0;
d=2;}
}
else if(dziadek->balans>0 && rodzic->balans<0){
    if(dziadek==korzen){
korzen->prawo=nowy;
tmp=nowy->prawo;
nowy->prawo=rodzic;
rodzic->lewo=tmp;
korzen=nowy;
tmp=nowy->lewo;
nowy->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
if(rodzic->lewo!=0 && rodzic->prawo!=0)
rodzic->balans=0;
else if(rodzic->lewo!=0)
rodzic->balans=-1;
else if(rodzic->prawo!=0)
rodzic->balans=1;
else rodzic->balans=0;
nowy->balans=0;
d=2;}
else {
dziadek->prawo=nowy;
tmp=nowy->prawo;
nowy->prawo=rodzic;
rodzic->lewo=tmp;
if(pradziadek->lewo==dziadek)
pradziadek->lewo=nowy;
else
    pradziadek->prawo=nowy;
tmp=nowy->lewo;
nowy->lewo=dziadek;
dziadek->prawo=tmp;
if(dziadek->lewo!=0 && dziadek->prawo!=0)
dziadek->balans=0;
else if(dziadek->lewo!=0)
dziadek->balans=-1;
else if(dziadek->prawo!=0)
dziadek->balans=1;
else dziadek->balans=0;
nowy->balans=0;
d=2;}
}
temp=korzen;
if(d==1){
                 while (temp!= rodzic ){
  if(nowy->klucz<temp->klucz){
        temp->balans ++;
        temp=temp->lewo;
        }
     else {
         temp->balans --;
        temp=temp->prawo;
        }}}
        if(d==2){
                 while (temp!= nowy ){
  if(nowy->klucz<temp->klucz){
        temp->balans ++;
        temp=temp->lewo;
        }
     else {
         temp->balans --;
        temp=temp->prawo;
        }}}
        }
 if(d==1 || d==2){
    break;}
 if(b==-2){
    break;}
 }
     }}}}
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
else if (rodzic->prawo == temp) rodzic->prawo = pop;
else rodzic->lewo = pop;
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
    cout<<" / "<<endl;
    wyswietl_pre(temp->lewo);}
    if(temp->prawo!=0){
         cout<<" | "<<endl;
    wyswietl_pre(temp->prawo);
}cout<<"g"<<endl;
}
    void drzewo::wyswietl_in(elementy* korzen){
        elementy *temp=korzen;
  if(temp->lewo!=0){
    cout<<" / "<<endl;
    wyswietl_in(temp->lewo);}
    printf(" %d\n", temp->klucz);
    licznik++;
    if(temp->prawo!=0){
         cout<<" | "<<endl;
    wyswietl_in(temp->prawo);}
}
void drzewo::wyswietl_post(elementy* korzen){
        elementy *temp=korzen;
  if(temp->lewo!=0){
    cout<<" / "<<endl;
    wyswietl_post(temp->lewo);}
    if(temp->prawo!=0){
         cout<<" | "<<endl;
    wyswietl_post(temp->prawo);}
    printf(" %d\n", temp->klucz);
    licznik++;
}
int main()
{
    drzewo *baza = new drzewo;
    int X,klucz1,klucz2,klucz3,klucz4,klucz5;
FILE* fp = fopen("inlab04.txt", "r");
if (fp == NULL)
return -1;
fscanf (fp, "%d %d %d %d %d %d", &X, &klucz1, &klucz2, &klucz3, &klucz4, &klucz5);
fclose(fp);
clock_t begin, end;
double czas;
begin = clock();
baza->usun(klucz1);
baza->wstaw2(X);
/*baza->wstaw(50);
baza->wstaw(15);
baza->wstaw(55);
baza->wstaw(16);
baza->wstaw(12);
baza->wstaw(53);
baza->wstaw(60);
baza->wstaw(13);
baza->wstaw(10);
baza->wstaw(52);
baza->wstaw(57);
baza->wstaw(65);
baza->wstaw(61);
baza->wstaw(70);
baza->wstaw(62);*/

baza->wyswietl(1);
end = clock();
czas = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Czas wykonania programu : %.4f\n", czas);
    return 0;
}

