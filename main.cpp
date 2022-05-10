#include <iostream>

using namespace std;
char matrice [3][3]={'1','2','3','4','5','6','7','8','9'} ;
char joueur='X';
void printMatrice()
{
system("clear");//pour windows :system("cls");
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
{
cout << matrice[i][j] << " ! ";
}
cout << endl ;
cout<<"-----------";
cout << endl ;
}
}
void saisieJeu ()
{
char pos ;
cout <<"choisissez votre position - joueur ("<<joueur<<") :" ;
cin >> pos ;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
{
if(matrice[i][j]==pos)
matrice[i][j]=joueur ;
}
}
if(joueur=='X')
joueur='O';
else
joueur='X';
}
char morpion()
{
int xc=0,oc=0 ,compteur=0 ;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
{
if (matrice[i][j]!='X' && matrice[i][j]!='O')  compteur++ ;
if(matrice[i][j]=='X') xc++ ;
else if (matrice[i][j]=='O') oc++;

if(xc==3||oc==3)
return xc > oc ? 'X' : 'O' ;
}
 xc=0;
 oc =0 ;
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
{
if(matrice[j][i]=='X') xc++ ;
else if (matrice[j][i]=='O') oc++;

if(xc==3||oc==3)
return xc > oc ? 'X' : 'O' ;
}
 xc=0;
 oc =0 ;
}
if(matrice[0][0]=='X'&& matrice[1][1]=='X' && matrice[2][2]=='X') return 'X';
if(matrice[0][0]=='O'&& matrice[1][1]=='O' && matrice[2][2]=='O') return 'O';
if(matrice[0][2]=='X'&& matrice[1][1]=='X' && matrice[2][0]=='X') return 'X';
if(matrice[0][2]=='O'&& matrice[1][1]=='O' && matrice[2][0]=='O') return 'O';
if (compteur==0) return 'z' ;
return '.' ;

}

int main()
{
while(morpion()=='.')
{
printMatrice();
saisieJeu ();
}
printMatrice() ;
if(morpion()=='z') cout <<"il n'y a pas de gagnant" <<endl ;
else cout<< "le gagant est "<<morpion() <<" félicitation" <<endl;


}
