// **************************************************** JUEGO DE DAMAS *****************************************************//
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;


char aux;
char tabla[10][10]=
{
    {'.', 'O', '.', 'O', '.', 'O', '.', 'O','.','O'},
    {'O', '.', 'O', '.', 'O', '.', 'O', '.','O','.'},
    {'.', 'O', '.', 'O', '.', 'O', '.', 'O','.','O'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.',' ','.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' ','.',' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.',' ','.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' ','.',' '},
    {'X', '.', 'X', '.', 'X', '.', 'X', '.','X','.'},
    {'.', 'X', '.', 'X', '.', 'X', '.', 'X','.','X'},
    {'X', '.', 'X', '.', 'X', '.', 'X', '.','X','.'},
};
int i, j, x, y, falla, desplaza, jugada=1, fin=1, FichaX=15, FichaO=15, auxX=9, auxO=9;

void FuncionMostrar()
{
cout<<"    A     B      C     D     E     F     G     H     I    J  \n";
cout<<"   _____ _____ _____ _____ _____ _____ _____ _____ _____ _____\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 0|  "<<tabla[0][0]<<"  |  "<<tabla[0][1]<<"  |  "<<tabla[0][2]<<"  |  "<<tabla[0][3]<<"  |  "<<tabla[0][4]<<"  |  "<<tabla[0][5]<<"  |  "<<tabla[0][6]<<"  |  "<<tabla[0][7]<<"  |  "<<tabla[0][8]<<"  |  "<<tabla[0][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 1|  "<<tabla[1][0]<<"  |  "<<tabla[1][1]<<"  |  "<<tabla[1][2]<<"  |  "<<tabla[1][3]<<"  |  "<<tabla[1][4]<<"  |  "<<tabla[1][5]<<"  |  "<<tabla[1][6]<<"  |  "<<tabla[1][7]<<"  |  "<<tabla[1][8]<<"  |  "<<tabla[1][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 2|  "<<tabla[2][0]<<"  |  "<<tabla[2][1]<<"  |  "<<tabla[2][2]<<"  |  "<<tabla[2][3]<<"  |  "<<tabla[2][4]<<"  |  "<<tabla[2][5]<<"  |  "<<tabla[2][6]<<"  |  "<<tabla[2][7]<<"  |  "<<tabla[2][8]<<"  |  "<<tabla[2][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 3|  "<<tabla[3][0]<<"  |  "<<tabla[3][1]<<"  |  "<<tabla[3][2]<<"  |  "<<tabla[3][3]<<"  |  "<<tabla[3][4]<<"  |  "<<tabla[3][5]<<"  |  "<<tabla[3][6]<<"  |  "<<tabla[3][7]<<"  |  "<<tabla[3][8]<<"  |  "<<tabla[3][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 4|  "<<tabla[4][0]<<"  |  "<<tabla[4][1]<<"  |  "<<tabla[4][2]<<"  |  "<<tabla[4][3]<<"  |  "<<tabla[4][4]<<"  |  "<<tabla[4][5]<<"  |  "<<tabla[4][6]<<"  |  "<<tabla[4][7]<<"  |  "<<tabla[4][8]<<"  |  "<<tabla[4][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 5|  "<<tabla[5][0]<<"  |  "<<tabla[5][1]<<"  |  "<<tabla[5][2]<<"  |  "<<tabla[5][3]<<"  |  "<<tabla[5][4]<<"  |  "<<tabla[5][5]<<"  |  "<<tabla[5][6]<<"  |  "<<tabla[5][7]<<"  |  "<<tabla[5][8]<<"  |  "<<tabla[5][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 6|  "<<tabla[6][0]<<"  |  "<<tabla[6][1]<<"  |  "<<tabla[6][2]<<"  |  "<<tabla[6][3]<<"  |  "<<tabla[6][4]<<"  |  "<<tabla[6][5]<<"  |  "<<tabla[6][6]<<"  |  "<<tabla[6][7]<<"  |  "<<tabla[6][8]<<"  |  "<<tabla[6][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 7|  "<<tabla[7][0]<<"  |  "<<tabla[7][1]<<"  |  "<<tabla[7][2]<<"  |  "<<tabla[7][3]<<"  |  "<<tabla[7][4]<<"  |  "<<tabla[7][5]<<"  |  "<<tabla[7][6]<<"  |  "<<tabla[7][7]<<"  |  "<<tabla[7][8]<<"  |  "<<tabla[7][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 8|  "<<tabla[8][0]<<"  |  "<<tabla[8][1]<<"  |  "<<tabla[8][2]<<"  |  "<<tabla[8][3]<<"  |  "<<tabla[8][4]<<"  |  "<<tabla[8][5]<<"  |  "<<tabla[8][6]<<"  |  "<<tabla[8][7]<<"  |  "<<tabla[8][8]<<"  |  "<<tabla[8][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
cout<<"  |     |     |     |     |     |     |     |     |     |     |\n";
cout<<" 9|  "<<tabla[9][0]<<"  |  "<<tabla[9][1]<<"  |  "<<tabla[9][2]<<"  |  "<<tabla[9][3]<<"  |  "<<tabla[9][4]<<"  |  "<<tabla[9][5]<<"  |  "<<tabla[9][6]<<"  |  "<<tabla[9][7]<<"  |  "<<tabla[9][8]<<"  |  "<<tabla[9][9]<<"  |\n";
cout<<"  |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";

}


//***************************************************************************************************************************
int FuncionSustituir(int intp)
{
    int outp=intp;
    int caract=65;
    for(int i=0;i<=9;i++)
    {
      if(outp==i)
      {
        outp=caract;
      }
      caract++;
    }
    caract=0;
    return outp;
}
//***************************************************************************************************************************
void FuncionAux2(char tabla[10][10], int aux1, int aux2, int x, int y, char casilla, char car)
{
    tabla[x][y]=' ' ;
    tabla[aux1][aux2] = car;
    y--;
    casilla=char (FuncionSustituir(y));
    cout<<"\nLA CPU HA REALIZADO UN MOVIMIENTO HACIA LA CASILLA: "<<casilla<<""<<aux1 <<"\n";
}
//***************************************************************************************************************************
void FuncionAux3(char tabla[10][10], int aux1, int aux2, int x, int y, char casilla, char car)
{
    tabla[x][y]=' ' ;
    tabla[aux1][aux2] = car;
    y++;
    casilla=char (FuncionSustituir(y));
    cout<<"\nLA CPU HA REALIZADO UN MOVIMIENTO HACIA LA CASILLA: "<<casilla<<""<<aux1 <<"\n";
}
//***************************************************************************************************************************
void FuncionAux4(char tabla[10][10], int aux1, int aux2, int aux3, int aux4, int x, int y, char casilla, char car)
{
    tabla[x][y]=' ' ;
    tabla[aux1][aux2]=' ' ;
    tabla[aux3][aux4]= car;
    cout<<"\a";
    y--;
    casilla=char (FuncionSustituir(y));
    cout<<"\nCOMISTE UNA FICHA DEL OPONENTE (X) EN LA CASILLA: "<<casilla<<""<<aux1 <<"\n";
    FichaX=FichaX-1;
    auxO= (auxO)+3;
}
//***************************************************************************************************************************
void FuncionAux5(char tabla[10][10], int aux1, int aux2, int aux3, int aux4, int x, int y, char casilla, char car)
{
    tabla[x][y]=' ' ;
    tabla[aux1][aux2]=' ' ;
    tabla[aux3][aux4]= car;
    y++;
    casilla=char (FuncionSustituir(y));
    cout<<"\nCOMISTE UNA FICHA DEL OPONENTE (X) EN LA CASILLA: "<<casilla<<""<<aux1 <<"\n";
    FichaX=FichaX-1;
    auxO= (auxO)+3;
}
//***************************************************************************************************************************
void MoverCPU()
{
    char casilla;
    int aux1,aux2,aux3,aux4;
    if (tabla[x][y]=='*' && desplaza == 1 && tabla[x+1][y-1]== ' ')
    {
        aux1=x+1;
        aux2=y-1;
        FuncionAux2(tabla,aux1,aux2,x,y,casilla,'*');
    }
    else
        if (tabla[x][y]=='*' && desplaza == 2 && tabla[x+1][y+1]== ' '  )
        {
            aux1=x+1;
            aux2=y+1;
            FuncionAux3(tabla,aux1,aux2,x,y,casilla,'*');
        }
    else
        if (tabla[x][y]=='*' && desplaza == 3 && tabla[x-1][y-1]== ' '  )
        {
            aux1=x-1;
            aux2=y-1;
            FuncionAux2(tabla,aux1,aux2,x,y,casilla,'*');
        }
    else
        if (tabla[x][y]=='*' && desplaza == 4 && tabla[x-1][y+1]== ' '  )
        {
            aux1=x-1;
            aux2=y+1;
            FuncionAux3(tabla,aux1,aux2,x,y,casilla,'*');
        }
    else
        if(tabla[x][y]=='*' && desplaza== 1 && (tabla [x+1][y-1] == 'X'||tabla [x+1][y-1] == '#'))
        {
            aux1=x+1;
            aux2=y-1;
            aux3=x+2;
            aux4=y-2;
            FuncionAux4(tabla,aux1,aux2,aux3,aux4,x,y,casilla,'*');
        }
    else
        if(tabla[x][y]=='*' && desplaza== 2 && (tabla [x+1][y+1] == 'X'||tabla [x+1][y+1] == '#'))
        {
            aux1=x+1;//era +
            aux2=y+1;
            aux3=x+2;
            aux4=y+2;
            FuncionAux5(tabla,aux1,aux2,aux3,aux4,x,y,casilla,'*');
        }
    else
        if(tabla[x][y]=='*' && desplaza== 3 && (tabla [x-1][y-1] == 'X'||tabla [x-1][y-1] == '#'))
        {
            aux1=x-1;
            aux2=y-1;
            aux3=x-2;
            aux4=y-2;
            FuncionAux4(tabla,aux1,aux2,aux3,aux4,x,y,casilla,'*');
        }
    else
        if(tabla[x][y]=='*' && desplaza== 4 && (tabla [x-1][y+1] == 'X'||tabla [x-1][y+1] == '#'))
        {
            aux1=x-1;
            aux2=y+1;
            aux3=x-2;
            aux4=y+2;
            FuncionAux5(tabla,aux1,aux2,aux3,aux4,x,y,casilla,'*');
        }
    else
        if (tabla[x][y]=='O' && desplaza == 1 && tabla[x+1][y-1]== ' ')
        {
            aux1=x+1;
            aux2=y-1;
            FuncionAux2(tabla,aux1,aux2,x,y,casilla,'O');
        }
     if (tabla[x][y]=='O' && desplaza == 2 && tabla[x+1][y+1]== ' ' )
     {
        aux1=x+1;
        aux2=y+1;
        FuncionAux3(tabla,aux1,aux2,x,y,casilla,'O');
     }
    else
        if(tabla[x][y]=='O'&& desplaza== 1 && (tabla [x+1][y-1] == 'X'||tabla [x+1][y-1] == '#'))
        {
            aux1=x+1;
            aux2=y-1;
            aux3=x+2;
            aux4=y-2;
            FuncionAux4(tabla,aux1,aux2,aux3,aux4,x,y,casilla,'O');
        }
    else
        if(tabla[x][y]=='O'&& desplaza== 2 && ( tabla [x+1][y+1] == 'X'|| tabla [x+1][y+1] == '#'))
        {
            aux1=x+1;
            aux2=y+1;
            aux3=x+2;//era +
            aux4=y+2;
            FuncionAux5(tabla,aux1,aux2,aux3,aux4,x,y,casilla,'O');
        }
       jugada = 1 ;
}
//***************************************************************************************************************************
void Mueve()
{
   do
     {
       if (tabla[x][y]=='*')
        {
          desplaza=rand()% 4+1 ;
          falla=0;
          if (tabla[x][y] == 'O')
          {
            desplaza=rand() % 2+1 ;
            falla=0;
          }
        }
    }while (desplaza>4||desplaza<1);
}
//***************************************************************************************************************************
void FichaAleatoria()
{
  do{
        srand(time(NULL));
        x=rand() % 9+0 ;
        y=rand() % 9+0 ;
    }while (tabla[x][y]!='O'&&tabla[x][y]!='*');
}
//***************************************************************************************************************************
void FuncionTactica()
{
    for(i=1; i<=2; i++)
   {
     for(j=0; j<=9; j++)
     {
        if(tabla[i][j]=='O' && i==2 && tabla[i+1][j+1]==' ')
        {
              desplaza=2;
              x=2;
              y=j;
              j=10;
              i=5;
        }
        else
        {
            if(tabla[i][j]=='O' && i==1 && tabla[i+1][j-1]==' ')
            {
                 desplaza=1;
                 x=1;
                 y=j;
                 j=10;
                 i=5;
            }
            else
            {
                 FichaAleatoria();
                 Mueve();
            }
       }
     }
    }
}
//***************************************************************************************************************************
void Maquina ()
{
    cout<<"\n";
    cout<<"ESTADO CPU: \n" <<"Jugando...\n" <<endl;
    do{
        do{
           do{
                FuncionTactica();
             }while ((y==9&&desplaza==2)||(y==0&&desplaza==1)||(y==9&&desplaza==4)||(y==0&&desplaza==3)||(x==0&&desplaza==4)||(x==0&&desplaza==3)||(x==9&&desplaza==1)||(x==9&&desplaza==2));
           }while((desplaza == 1 &&( tabla[x+1][y-1]== 'O'||tabla[x+1][y-1]== '*') )||(desplaza == 2 && (tabla[x+1][y+1]== 'O' || tabla[x+1][y+1]== '*') )|| (desplaza == 3 && (tabla[x-1][y-1]== 'O' || tabla[x-1][y-1]== '*') )||(desplaza == 4 && (tabla[x-1][y+1]== 'O' || tabla[x-1][y+1]== '*') ));
            if (desplaza==1 &&( tabla[x+1][y-1] == 'X' || tabla[x+1][y-1] == '#') )
            {
                if(y==1 || y==0 || x==8 || x==9 || tabla[x+2][y-2] == 'X' || tabla[x+2][y-2] == 'O' || tabla[x+2][y-2] == '*' || tabla[x+2][y-2] == '#')
                {
                  falla=1;
                }
              }
              if (desplaza==2 && (tabla[x+1][y+1] == 'X'||tabla[x+1][y+1] == '#'))
              {
                if( y==8 || y==9 || x==8 || x==9 || tabla[x+2][y+2] == 'X' || tabla[x+2][y+2] == 'O' || tabla[x+2][y+2] == '*' || tabla[x+2][y+2] == '#')
                {
                   falla=1;
                }
              }
              if (desplaza==3 && (tabla[x-1][y-1] == 'X'||tabla[x-1][y-1] == '#'))
              {
                if(y==1 || y==0 || x==1 || x==0 || tabla[x-2][y-2] == 'X' || tabla[x-2][y-2] == 'O' || tabla[x-2][y-2] == '*' || tabla[x-2][y-2] == '#')
                {
                    falla=1;
                }
              }
              if (desplaza==4 && (tabla[x-1][y+1] == 'X'||tabla[x-1][y+1] == '#'))
              {
                if(y==8 || y==9 || x==1 || tabla[x-2][y+2] == 'X' || tabla[x-2][y+2] == 'O' || tabla[x-2][y+2] == '#' || tabla[x-2][y+2] == '*')
                {
                    falla=1;
                }
              }
     }while(falla==1);
     MoverCPU();
}
//***************************************************************************************************************************
void Funcion1(char tabla[10][10], char casilla, int aux2, int i, int j, int a1, int a2, int a3, int a4, char car)
{
    casilla=char (FuncionSustituir(aux2));
    cout<<"\n\nPERDISTE UNA FICHA EN LA CASILLA: "<<casilla<<""<<a1<<"\n\n"<<endl;
    tabla[i][j]=' ';
    tabla[a1][a2]= ' ';
    tabla[a3][a4]= car ;
    FichaX=FichaX-1;
    jugada=1;
}
//***************************************************************************************************************************
void FuncionComer()
{
    char casilla;
    int aux2,a1,a2,a3,a4;
    for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
      {
        if(tabla[i][j]=='*'&& tabla[i+2][j+2]==' ' && (tabla[i+1 ][j+1]=='X'||tabla[i+1 ][j+1]=='#') && (i!=8) && (i!=9) && (j!=8) && (j!=9) )
        {
              aux2=j;
              aux2++;
              a1=i+1;
              a2=j+1;
              a3=i+2;
              a4=j+2;
              Funcion1(tabla,casilla,aux2,i,j,a1,a2,a3,a4,'*');
         }
         if (tabla[i][j]=='*' && tabla[i-2 ][j-2]==' ' && ( tabla[i-1][j-1]=='X'||tabla[i-1][j-1]=='#') && (j!=1) && (j!=0 ) && (i!=0) && (i!=1) )
         {
              aux2=j;
              aux2--;
              a1=i-1;
              a2=j-1;
              a3=i-2;
              a4=j-2;
              Funcion1(tabla,casilla,aux2,i,j,a1,a2,a3,a4,'*');
         }
         else
         if (tabla[i][j]=='*' && tabla[i-2][j+2]==' ' && (tabla[i-1][j+1]=='X'||tabla[i-1][j+1]=='#') && (j!=8) && (j!=9) && (i!=0) && (i!=1) )
         {
              aux2=j;
              aux2--;
              a1=i-1;
              a2=j+1;
              a3=i-2;
              a4=j+2;
              Funcion1(tabla,casilla,aux2,i,j,a1,a2,a3,a4,'*');
         }
         else
         if (tabla[i][j]=='*' && tabla[i+2][j-2]==' ' && (tabla[i+1][j-1]=='X'||tabla[i+1][j-1]=='#') && (j!=0) && (j!=1) && (i!=8) && (i!=9) )
         {
              aux2=j;
              aux2++;
              a1=i+1;
              a2=j-1;
              a3=i+2;
              a4=j-2;
              Funcion1(tabla,casilla,aux2,i,j,a1,a2,a3,a4,'*');
        }
         else
         if(tabla[i][j]=='O'&& tabla[i+2][j+2]==' ' &&( tabla[i+1][j+1]=='X'||tabla[i+1][j+1]=='#') && (j!=8) && (j!=9) && (i!=8) && (i!=9) )
         {
              aux2=j;
              aux2++;
              a1=i+1;
              a2=j+1;
              a3=i+2;
              a4=j+2;
              Funcion1(tabla,casilla,aux2,i,j,a1,a2,a3,a4,'O');
         }
            else
            if (tabla[i][j]=='O' && tabla[i+2 ][j-2 ]==' ' && (tabla[i+1][j-1]=='X' ||tabla[i+1][j-1]=='#' ) && (j!=1) && (i!=8) && (j!=0) && (i!=9) )
            {
                 aux2=j;
                 aux2--;
                 a1=i+1;
                 a2=j-1;
                 a3=i+2;
                 a4=j-2;
                 Funcion1(tabla,casilla,aux2,i,j,a1,a2,a3,a4,'O');
            }
      }
    }
}
//***************************************************************************************************************************
void FuncionAux(char tabla[10][10], int auxiliar, int i, int j, char casilla)
{
    auxiliar=j;
    cout<<"\n\n";
    casilla=char (FuncionSustituir(auxiliar));
    cout<<"¡SOPLADITA!, obligación de captura en: "<<casilla<<""<<i<<endl;
    tabla[i][j]=' ';
    FichaX=FichaX-1;
    jugada=0;
    j=10;
    i=10;
}
//***************************************************************************************************************************
void Sopladita()
{
    char casilla;
    int auxiliar;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if (tabla[i][j]=='#' && tabla[i+2][j+2]==' ' && (tabla[i+1][j+1]=='O'||tabla[i+1][j+1]=='*') && (j!= 8 || j!=9))
            {
                FuncionAux(tabla,auxiliar,i,j,casilla);
            }
            else
                if (tabla[i][j]=='#' && tabla[i+2][j-2]==' ' && (tabla[i+1][j-1]=='O'||tabla[i+1][j-1]=='*') && j!= 1)
                {
                    FuncionAux(tabla,auxiliar,i,j,casilla);
                }
            else
                if (tabla[i][j]=='#' && tabla[i-2][j+2]==' ' && (tabla[i-1][j+1]=='O'||tabla[i-1][j+1]=='*')  && (j!= 8 || j!=9))
                {
                    FuncionAux(tabla,auxiliar,i,j,casilla);
                }
            else
                if(tabla[i][j]=='#'&& tabla[i-2][j-2]==' ' && (tabla[i-1][j-1]=='O'||tabla[i-1][j-1]=='*') && j!= 1 )
                {
                    FuncionAux(tabla,auxiliar,i,j,casilla);
                }
            else
                if(tabla[i][j]=='X'&& tabla[i-2][j-2]==' ' && (tabla[i-1][j-1]=='O'||tabla[i-1][j-1]=='*') && j!= 1  )
                {
                    FuncionAux(tabla,auxiliar,i,j,casilla);
                }
            else
                if (tabla[i][j]=='X' && tabla[i-2][j+2]==' ' && (tabla[i-1][j+1]=='O'||tabla[i-1][j+1]=='*') && (j!= 8 || j!=9 ))
                {
                    FuncionAux(tabla,auxiliar,i,j,casilla);
                }
        }
    }
}
//***************************************************************************************************************************
void FuncionMayusculas(char a)
{
    if(aux == 'a')
    {aux='A';}if(aux=='b'){aux='B';}if(aux=='c'){aux='C';}if(aux=='d'){aux='D';}if(aux=='e'){aux='E';}if(aux=='f'){aux='F';}if(aux=='g'){aux='G';}if(aux=='h'){aux='H';}if(aux=='i'){aux='I';}if(aux=='j'){aux='J';}
}
//***************************************************************************************************************************
void Funcion2(char tabla[10][10], int x, int y, char casilla, char car, int b1, int b2, int b3, int b4)
{
        tabla[x][y]=' ' ;
        tabla[b1][b2]=' ' ;
        tabla[b3][b4]= car;
        casilla=char (FuncionSustituir(y));
        cout<<"\n";
        casilla=casilla-1;
        cout<<"COMISTE UNA FICHA DEL OPONENTE (O) EN LA CASILLA:"<<casilla<<""<<b1;
        FichaO=FichaO-1;
        auxX= (auxX)+3;
}
//***************************************************************************************************************************
void Funcion3(char tabla[10][10], int x, int y, char casilla, char car, int b1, int b2, int b3, int b4)
{
        tabla[x][y]=' ' ;
        tabla[b1][b2]=' ' ;
        tabla[b3][b4]= car;
        casilla=char (FuncionSustituir(y));
        cout<<"\n";
        casilla=casilla+1;
        cout<<"COMISTE UNA FICHA DEL OPONENTE (O) EN LA CASILLA:"<<casilla<<""<<b1;
        FichaO=FichaO-1;
        auxX= (auxX)+3;
}
//***************************************************************************************************************************
void MoverJugador()
{
    int caract=0, b1,b2,b3,b4;
    char casilla;
    do{do{do{do{
                    cout<<"\n\n";
                    cout<<"ES SU TURNO (X)" <<endl ;
                    if(jugada==1)
                    {
                        cout<<"ESCOJA CASILLA VERTICAL (A-J)"<<endl;
                        cin>> aux;
                        FuncionMayusculas(aux);
                        cout<<"ESCOJA CASILLA HORIZONTAL (0-9)";
                        cin>>x;
                        //HAY QUE VALIDAR ESTA COSA POR QUE HACE LOOP SI INGRESAS LETRAS
                        y=int(aux);
                        for(int z=65;z<=74;z++)
                        {
                            if(y==z)
                            {
                                y=caract;
                            }
                            caract++;
                        }
                        caract=0;
                     }
                        if  (tabla[x][y]!='X'&&tabla[x][y]!='#')
                        {
                          casilla=char (FuncionSustituir(y));
                          cout<<"\n";
                          cout<<"*SE HA DETECTADO UN ERROR* \n CASILLA " <<casilla<<" "<<x<<" SIN FICHA"<<endl;
                          cout<<"INTENTE NUEVAMENTE\n";
                        }
                }while (tabla[x][y]!='X'&&tabla[x][y]!='#');
                do
                {
                    if (tabla[x][y] == 'X')
                   {
                            cout<<"\n*ELIJA MOVIMIENTO*\n\n";
                            cout<<"\tOPCIÓN 1: Izquierda hacia arriba\n";
                            cout<<"\tOPCIÓN 2: Derecha hacia arriba\n";
                            cout<<"Opción: ";
                            cin>>desplaza ;
                            falla=0;
                            if(desplaza>2||desplaza<1)
                            {
                                cout<<"OPCIÓN INCORRECTA, INTENTE NUEVAMENTE\n"<<endl;
                            }
                        if((y==9&&desplaza==2)||(y==0&&desplaza==1))
                        {
                            cout<<"*SE HA DETECTADO UN ERROR* \n";
                            cout<<"JUGADA NO PERMITIDA, INTENTE NUEVAMENTE\n "<<endl ;
                        }
                    }
                     if (tabla[x][y]=='#')
                     {
                        cout<<"\n*ELIJA MOVIMIENTO*\n\n";
                        cout<<"OPCIÓN 1: Izquierda hacia arriba\n";
                        cout<<"OPCIÓN 2: Derecha hacia arriba\n";
                        cout<<"OPCIÓN 3: Izquierda hacia abajo\n";
                        cout<<"OPCIÓN 4: Derecha hacia abajo\n";
                        cout<<"OPCIÓN: ";
                        cin>>desplaza;
                        falla=0;
                        if(desplaza>4||desplaza<1)
                        {
                            cout<<"OPCIÓN INCORRECTA, INTENTE NUEVAMENTE\n"<<endl;
                        }
                        if((y==9&&desplaza==2)||(y==0&&desplaza==1)||(y==9&&desplaza==4)||(y==0&&desplaza==3)||(x==0&&desplaza==1)||(x==0&&desplaza==2)||(x==9&&desplaza==3)||(x==9&&desplaza==4))
                        {
                            cout<<"*SE HA DETECTADO UN ERROR* \n";
                            cout<<"JUGADA NO PERMITIDA, INTENTE NUEVAMENTE\n "<<endl ;
                        }
                    }
                }while (desplaza>4||desplaza<1);
            }while((y==9&&desplaza==2)||(y==0&&desplaza==1)||(y==9&&desplaza==4)||(y==0&&desplaza==3)||(x==0&&desplaza==1)||(x==0&&desplaza==2)||(x==9&&desplaza==3)||(x==9&&desplaza==4));
            if (desplaza == 1 && ( tabla[x-1][y-1]== 'X'||tabla[x-1][y-1]== '#')  )
            {
                cout<<"*SE HA DETECTADO UN ERROR* \n";
                cout<<"CASILLA UTILIZADA\n "<<endl ;
            }
            else
                if (desplaza == 2 && (tabla[x-1][y+1]== 'X'||tabla[x-1][y+1]== '#') )
                {
                    cout<<"*SE HA DETECTADO UN ERROR* \n";
                    cout<<"CASILLA UTILIZADA\n "<<endl ;
                }
            else
                if (desplaza == 3 && (tabla[x+1][y-1]== 'X'||tabla[x+1][y-1]== '#') )
                {
                    cout<<"*SE HA DETECTADO UN ERROR* \n";
                    cout<<"CASILLA UTILIZADA\n "<<endl ;
                }
            else
                if (desplaza == 4 && (tabla[x+1][y+1]== 'X'||tabla[x+1][y+1]== '#') )
                {
                    cout<<"*SE HA DETECTADO UN ERROR* \n";
                    cout<<"CASILLA UTILIZADA\n "<<endl ;
                }
         }while((desplaza==1&&(tabla[x-1][y-1]== 'X'||tabla[x-1][y-1]== '#'))||(desplaza==2&&(tabla[x-1][y+1]== 'X'||tabla[x-1][y+1]== '#') )||(desplaza == 3 && (tabla[x+1][y-1]== 'X'||tabla[x-1][y+1]== '#') )||(desplaza == 4 && (tabla[x+1][y+1]== 'X'||tabla[x+1][y+1]== '#') ));
        if (desplaza==1 && (tabla[x-1][y-1] == 'O'||tabla[x-1][y-1] == '*') )
        {
            if(y==1 || x==1)
            {
                cout<<"*SE HA DETECTADO UN ERROR* \n";
                cout<<"JUGADA NO PERMITIDA, INTENTE NUEVAMENTE\n "<<endl ;
                falla=1;
            }
            if(tabla[x-2][y-2] == 'X' || tabla[x-2][y-2] == 'O' || tabla[x-2][y-2] == '#' || tabla[x-2][y-2] == '*')
            {
                casilla=char (FuncionSustituir(y));
                cout<<"*SE HA DETECTADO UN ERROR* \n";
                casilla=casilla-2;
                cout<<"CASILLA "<<casilla<<x-2<<"UTILIZADA";
                falla=1;
            }
        }
         else
             if (desplaza==2 && (tabla[x-1][y+1] == 'O'||tabla[x-1][y+1] == '*'))
            {
                if(y==8 || y==9 || x==1 || x==0 || tabla[x-2][y+2] == 'X' || tabla[x-2][y+2] == 'O' || tabla[x-2][y+2] == '#' || tabla[x-2][y+2] == '*')
                {
                    cout<<"*SE HA DETECTADO UN ERROR* \n";
                    cout<<"JUGADA NO PERMITIDA, INTENTE NUEVAMENTE\n"<<endl ;
                    falla=1;
                }
            }
         else
             if (desplaza==3 && (tabla[x+1][y-1] == 'O'||tabla[x+1][y-1] == '*'))
            {
              if(y==1 || y==0 || x==8 || x==9 || tabla[x+2][y-2] == 'X' || tabla[x+2][y-2] == 'O' || tabla[x-2][y+2] == '*' || tabla[x-2][y+2] == '#')
              {
                   cout<<"*SE HA DETECTADO UN ERROR*\n";
                   cout<<"JUGADA NO PERMITIDA, INTENTE NUEVAMENTE\n"<<endl ;
                   falla=1;
              }
            }
         else
             if (desplaza==4 && (tabla[x+1][y+1] == 'O'||tabla[x+1][y+1] == '*'))
            {
                if(y==8 || x==8||x==9 || tabla[x+2][y+2] == 'X' || tabla[x+2][y+2] == 'O' || tabla[x+2][y+2] == '#' || tabla[x+2][y+2] == '*')
                {
                    cout<<"*SE HA DETECTADO UN ERROR*\n";
                    cout<<"JUGADA NO PERMITIDA, INTENTE NUEVAMENTE\n"<<endl ;
                    falla=1;
                }
            }
    }while(falla==1);
    if(tabla[x][y]== '#' && desplaza==1 && tabla[x-1][y-1]== ' '  )
    {
        tabla[x][y]= ' ';
        tabla[x-1][y-1]= '#';
    }
    else
        if (tabla[x][y]=='#'&& desplaza == 2 && tabla[x-1][y+1]== ' ' )
        {
        tabla[x][y]=' ' ;
        tabla[x-1][y+1] = '#' ;
    }
    else
        if (tabla[x][y]=='#'&& desplaza == 3 && tabla[x+1][y-1]== ' ' )
        {
        tabla[x][y]=' ' ;
        tabla[x+1][y-1] = '#';
    }
    else
        if (tabla[x][y]=='#'&& desplaza == 4 && tabla[x+1][y+1]== ' ' )
    {
        tabla[x][y]=' ' ;
        tabla[x+1][y+1] = '#';
    }
    else
        if(tabla[x][y]=='#'&& desplaza== 1 &&( tabla [x-1][y-1] == 'O' || tabla [x-1][y-1] == '*'))
    {
        b1=x-1;
        b2=y-1;
        b3=x-2;
        b4=y-2;
        Funcion2(tabla,x,y,casilla,'#',b1,b2,b3,b4);
    }
    else
        if(tabla[x][y]=='#'&& desplaza==2 && (tabla [x-1][y+1] == 'O'||tabla [x-1][y+1] == '*'))
    {
        b1=x-1;
        b2=y+1;
        b3=x-2;
        b4=y+2;
        Funcion3(tabla,x,y,casilla,'#',b1,b2,b3,b4);
    }
    else
        if(tabla[x][y]=='#'&& desplaza== 3 && (tabla [x+1][y-1] == 'O'||tabla [x+1][y-1] == '*'))
    {
        b1=x+1;
        b2=y-1;
        b3=x+2;
        b4=y-2;
        Funcion2(tabla,x,y,casilla,'#',b1,b2,b3,b4);
    }
    else
        if(tabla[x][y]=='#'&& desplaza== 4 && (tabla [x+1][y+1] == 'O'||tabla [x+1][y-1] == '*'))
    {
        b1=x+1;
        b2=y+1;
        b3=x+2;
        b4=y+2;
        Funcion3(tabla,x,y,casilla,'#',b1,b2,b3,b4);
    }
     else
         if(tabla[x][y]== 'X' && desplaza== 1 && tabla [x-1][y-1] == ' ')
        {
            tabla[x][y]=' ';
            tabla [x-1][y-1]= 'X';
        }
    else
        if(tabla[x][y]=='X'&& desplaza== 1 && (tabla [x-1][y-1] == 'O'||tabla [x-1][y-1] == '*'))
        {
            b1=x-1;
            b2=y-1;
            b3=x-2;
            b4=y-2;
            Funcion2(tabla,x,y,casilla,'X',b1,b2,b3,b4);
        }
    else
        if(tabla[x][y]== 'X' && desplaza== 2 && tabla [x-1][y+1] == ' ')
        {
            tabla[x][y]=' ' ;
            tabla [x-1][y+1]= 'X' ;
        }
    else
        if(tabla[x][y]== 'X' && desplaza== 2 && (tabla [x-1][y+1] == 'O'||tabla [x-1][y+1] == '*'))
        {
            b1=x-1;
            b2=y+1;
            b3=x-2;
            b4=y+2;
            Funcion3(tabla,x,y,casilla,'X',b1,b2,b3,b4);
        }
    jugada = 0 ;
}
//***************************************************************************************************************************
//***************************************************************************************************************************
//***************************************************************************************************************************
int main()
{
     int opcElegida;
     int aux2;

     do{
            cout<<"\n\n";

            cout<< "            1) Jugar versus CPU              \n";
            cout<< "            2) Instrucciones del Juego      \n";
            cout<< "            3) Salir                         \n";
            cout<< "Introduzca opción escogida: ";
            cin>>opcElegida;
            system("clear");
            switch (opcElegida)
            {
                case 1:
                {
                    //FuncionLlenar();
                    FuncionMostrar();
                    do{
                    if(jugada==1)
                    {
                        MoverJugador();
                    }
                    for (x=0;x<10;x++)
                    {
                        if(tabla[0][x]== 'X')
                        {
                            tabla[0][x]='#';
                            cout<<"SU FICHA SE HA TRANSFORMADO EN DAMA (#)\n";
                        }
                    }
                    FuncionMostrar();
                    if (FichaO==0)
                    {
                        cout<<"\n\n¡HA GANADO EL JUEGO! \n ¡FELICITACIONES!\n\n";
                        fin=2;
                        break;
                    }
                    FuncionComer();
                    if(jugada==0)
                    {
                        Sopladita();
                        Maquina();
                    }
                    for (x=0;x<10;x++)
                    {
                        if(tabla[9][x]== 'O' )
                        {
                            tabla[9][x]='*';
                            cout<<"LA CPU A CORONADO UNA FICHA (*)\n";
                        }
                    }
                    for (x=0;x<10;x++)
                    {
                        if(tabla[9][x]== 'O' )
                        {
                            tabla[9][x]='*';
                        }
                    }
                    FuncionMostrar() ;
                    if(FichaX==0)
                    {
                        cout<<"¡LA CPU A GANADO EL JUEGO!\n";
                        fin=2;
                        break;
                    }
                     }while(fin==1);
                    break;
                }
                case 2:
                {
                    cout<<"\n\n";
                    cout<<"\t\t\t*INSTRUCCIONES DEL JUEGO*\n\n";
                    cout<<"* Instrucción 1: \nLas fichas avanzan en forma diagonal por el tablero sólo hacia adelante, no pueden capturar hacia atrás.\n\n";
                    cout<<"* Instrucción 2: \nSe corona cuando se llega a la linea final, en donde la dama tiene la particularidad de moverse libremente sobre las diagonales de las casillas.\n\n";
                    cout<<"* Instrucción 3: \nSe coronará con un # la dama del jugador y con un * la dama de la maquina.\n\n";
                    cout<<"* Instrucción 4: \nLas coordenadas verticales del tablero van desde las letras A-J.\n\n";
                    cout<<"* Instrucción 5: \nLas coordenadas horizontales del tablero van desde el numero 0-9.\n\n";
                    cout<<"* Instrucción 6: \nAl momento de mover una ficha se debe poner primero la coordenada vertical luego la horizontal.\n\n";
                    cout<<"* Instrucción 7: \nAl momento de seleccionar la ficha existen dos opciones:\n\n";
                    cout<<"\t 1)Mover Izquierda hacia arriba.\n\n";
                    cout<<"\t 2)Mover Derecha hacia arriba.\n\n";
                    cout<<"* Instrucción 8: \nSi una dama llega a ser coronada tandrá la opcion de moverse hacia cualquier lugar (opciones 1, 2, 3 y 4)\n\n";
                    cout<<"* Instrucción 9: \nExiste la regla llamada “Sopladita” (obligación de captura), si no se cumple el oponente tiene el derecho de pedir que se capture o se retire del juego la ficha que no se capturó anteriormete.\n\n";
                    break;
                }
                case 3:
                {
                    cout<<"\t**Fin del programa**\n";
                    exit(0);
                    break;
                }
       }
       }while (opcElegida>=1&&opcElegida<=4);
       return 0;
 }
