#include<stdio.h>
#include<string.h>

int main()
{
char motechach[100];
char motdonnee[100];
int i, j, nb_ltr1, nb_ltr2, coup, falss;
int  ltrplac,ltrmalplac, essai, choix;
                              /* Joueur 1 */
 /*l acceuil de jeu*/
 printf("\n bienvenue dans le jeu   MOTUS\n" );

 
 printf("Entrez le mot cachee\n" );
 fflush(stdin);//effacer les donner//
  
 scanf("%s", &motechach); /*donner le mot correcte*/
 nb_ltr1 = strlen(motechach);/*longeur de mot1*/
 for(i=0; i<nb_ltr1; i++) /*tester la validiter du mot1:doit contenir que des caracteres alphabitiques*/
 {
  if(motechach[i] < 'a' || motechach[i] > 'z')
  {
   printf("Vous avez entrer un caractere erronne : %c\n", motechach[i]);
   printf("Entrez le nouveaux mot a faire decouvrir\n" );
 fflush(stdin); /*vider stdim (ram)*/
 scanf("%s", &motechach); /*donner le mot a decouvrir*/
  }
 }
printf("Le mot contient %d caracteres\n", nb_ltr1); //afficher la lengeur de mot1
system("cls" );//vider l'ecrant
                               /* Joueur 2 */
 /* la niveu de difuculte */
 printf("\n selon votre niveau\n\n" );
 printf("1-FACILE (15 essai)\n" );
 printf("2-MOYEN (10 essais)\n" );
 printf("3-DIFFICILE ( 5 essais)\n" );
 fflush(stdin);
 printf("Choix : " );
 scanf("%d", &choix);
 if(choix == 1)
 {
  essai = 15;
 }
 else
 {
  if(choix == 2)
  {
   essai = 10;
  }
  else
  {
   essai = 5;
  }
 }

falss=0;// le nomber de jeu//
coup = essai;
while(falss < essai && ltrplac < nb_ltr1)
{
 do
 {
  printf("Vous avez %d chances\n", coup);
  printf("Entrez un mot\n" );
  fflush(stdin);
  scanf("%s", &motdonnee);
  nb_ltr2 = strlen(motdonnee);
  if(nb_ltr2 != nb_ltr1 && falss < essai)
  {
   printf("Vous devez entrer un mot de %d caractere\n", nb_ltr1);
  }
 }while(nb_ltr2 != nb_ltr1);
 ltrplac = 0; // le letter bien placer egale 0 //
 for(i=0; i<nb_ltr1; i++)
 {
  if(motechach[i] == motdonnee[i])
  {
   ltrplac = ltrplac + 1;
  }
 }


 ltrmalplac = 0;
 for(j=0; j<nb_ltr1; j++)
  
  {
   if( motechach[j] != motdonnee[j])
   {
   	
   	motdonnee[j]='*';
    ltrmalplac = ltrmalplac + 1;
   }
  }
  printf("%s\n",motdonnee);
  printf("vous reste  a remplir %d\n",ltrmalplac);

 falss++;// nomber de de essai deja jouer //
 coup--;// nomber de essai reste //
}


if(ltrplac != nb_ltr1) // tester l'egaliter entre le nombre des letres de motcachee  et motdonnee
{
 printf("\n                   PERDU\n" );//motechach differents de motdonnee
 printf("Vous avez depasse le nombre d essai maximum\n" );
 printf("Le mot etait : %s\n", motechach);
}
else
{
 printf("\n GAGNE\n" );// motechach et motdonnee sont egaux (de meme longueur)
}
}

