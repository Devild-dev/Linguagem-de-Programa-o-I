#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int cont = 10;
int *pt;

int main(){
 pt = &cont;
 printf("cont = %d; pt = %d ; endereco de (cont,pt) = (%d,%d) \n", cont, *pt, &cont, pt);
 
 *pt = 12;
 printf("cont = %d; pt = %d ; endereco de (cont,pt) = (%d,%d) \n", cont, *pt, &cont, pt);
 
 pt++;//avan�ado o ponteiro na mem�ria
 pt++;//avan�ando o ponteio na mem�ria
 printf("cont = %d; pt = %d ; endereco de (cont,pt) = (%d,%d) \n", cont, *pt, &cont, pt);
 
 pt--;
 printf("cont = %d; pt = %d ; endereco de (cont,pt) = (%d,%d) \n", cont, *pt, &cont, pt);
 
 getch();
}
