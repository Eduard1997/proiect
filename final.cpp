#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void game();
int nrpatrate, nrbombe, dead=0;
int main()
{
    cout<<"Bun venit la Minesweeper!"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Observatie: 0 reprezinta spatiu liber"<<endl;
    cout<<"-------------------------------------"<<endl;
    game();
    return 0;
}
void game()
{
    cout<<"Tasteaza numarul de linii si coloane"<<endl;
    cin>>nrpatrate;
    cout<<"---------------------------------"<<endl;
    srand(time(NULL));
    char a[nrpatrate+100][nrpatrate+100];
    for(int i=1;i<=nrpatrate;i++)
    {
        for(int j=1;j<=nrpatrate;j++)
        a[i][j]='X';

    }

        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
                cout<<a[i][j]<<" ";
                cout<<endl;
        }
    cout<<"-----------------"<<endl;
    int revealed[nrpatrate][nrpatrate];
        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
            revealed[i][j]=0;

        }

    do {
        cout<<"Tasteaza numarul de bombe (2-"<<(nrpatrate*nrpatrate)-1<<")"<<endl;
        cin>>nrbombe;
        cout<<endl;
        if(nrbombe<=1 || nrbombe>nrpatrate*nrpatrate-1)
            cout<<"Ai introdus valoarea gresita"<<endl;


    }while(nrbombe<=1 || nrbombe>(nrpatrate*nrpatrate)-1);

    int copienrbombe;

            int p, q, marcare[nrpatrate][nrpatrate];
            for(int i=1;i<=nrpatrate;i++)
                for(int j=1;j<=nrpatrate;j++)
                    marcare[i][j]=0;
            copienrbombe=nrbombe;
            do{
                p=rand()%nrpatrate+1;
                q=rand()%nrpatrate+1;
                if(marcare[p][q]==0)
                {
                    revealed[p][q]=9;
                    copienrbombe--;
                    marcare[p][q]=1;
                }

            }while(copienrbombe!=0);


        int z=2+nrpatrate;
        int matricemare[z][z];
        for(int i=1;i<=z;i++)
            for(int j=1;j<=z;j++)
                matricemare[i][j]=0;
            for(int i=1;i<=nrpatrate;i++)
            {
                for(int j=1;j<=nrpatrate;j++)
                    if(revealed[i][j]==9)
                        matricemare[i+1][j+1]=9;
            }
            for(int i=1;i<=z;i++)
            {
                for(int j=1;j<=z;j++)
                    if(matricemare[i][j]==9)
                        {
                            if(matricemare[i-1][j-1]!=9)
                            matricemare[i-1][j-1]++;
                            if(matricemare[i-1][j]!=9)
                            matricemare[i-1][j]++;
                            if(matricemare[i-1][j+1]!=9)
                            matricemare[i-1][j+1]++;
                            if(matricemare[i][j+1]!=9)
                            matricemare[i][j+1]++;
                            if(matricemare[i+1][j+1]!=9)
                            matricemare[i+1][j+1]++;
                            if(matricemare[i+1][j]!=9)
                            matricemare[i+1][j]++;
                            if(matricemare[i+1][j-1]!=9)
                            matricemare[i+1][j-1]++;
                            if(matricemare[i][j-1]!=9)
                            matricemare[i][j-1]++;

                        }
            }


        int matricebuna[nrpatrate][nrpatrate];
         for(int a=1;a<=nrpatrate;a++)
                {
                    for(int b=1;b<=nrpatrate;b++)
                        matricebuna[a][b]=0;

                }
        for(int i=2;i<=z-1;i++)
            {
            for(int j=2;j<=z-1;j++)
                matricebuna[i-1][j-1]=matricemare[i][j];
            }

        int matricebombe[nrpatrate][nrpatrate];
        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
                matricebombe[i][j]=0;
        }
        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
                if(matricebuna[i][j]==9)
                matricebombe[i][j]=9;
        }

    int copienrbombe1;
    copienrbombe1=nrbombe;
    do{
        int x,y,f1,f2;
        char raspuns;
        do{
        cout<<"Doresti sa introduci un flag sau sa descoperi o locatie?"<<endl;
        cout<<"Tastateaza F pentru flag sau J pentru a descoperi o locatie"<<endl;
        cout<<endl;
            cin>>raspuns;
            cout<<endl;
            if(raspuns=='J')
                break;
            if(raspuns!='F')
                cout<<"Aceasta nu este o optiune valida"<<endl;
            cout<<endl;

        }while(raspuns!='F');
        if(raspuns=='F')
        {
            cout<<"Tasteaza coordonatele flag-ului"<<endl;
            cout<<"Tasteaza coordonata liniei X a flag-ului"<<endl;
            cin>>f1;
            cout<<endl;
            cout<<"Tasteaza coordonata liniei Y a flag-ului"<<endl;
            cin>>f2;
            a[f1][f2]='F';
            copienrbombe1--;
            cout<<endl;
            for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        cout<<"Numar bombe ramase="<<copienrbombe1<<endl<<endl;
        }
        if(raspuns=='J')
        {
            do{
        cout<<"Tasteaza coordonata X a liniei"<<endl;
        cin>>x;
        cout<<endl;
        cout<<"Tasteaza coordonata Y a coloanei"<<endl;
        cin>>y;
        if(x==f1 && y==f2)
            cout<<"coordonatele coincid cu cele ale flag-ului"<<endl;
        }while(x==f1 && y==f2);
        int copiex1,y1,x1,x2,copiey;
        x1=x;
        if(matricebuna[x][y]==0)
        {
          while(x1>=1)
   {
        copiex1=x1;
        while(matricebuna[copiex1][y]==0 && copiex1>=1)
        {
            a[copiex1][y]=0+'0';
            copiex1--;
        }
        copiex1=x1;
        while(matricebuna[copiex1][y]==0 && copiex1<=nrpatrate)
        {
            a[copiex1][y]=0+'0';
            copiex1++;
        }
        copiex1=x1; y1=y;
        while(matricebuna[copiex1][y1]==0 && y1>=1)
        {
            a[copiex1][y1]=0+'0';
            y1--;
        }
        y1=y;
        while(matricebuna[copiex1][y1]==0 && y1<=nrpatrate)
        {
            a[copiex1][y1]=0+'0';
            y1++;
        }
        y1=y;
        x1--;

   }

        x1=copiex1++;
        while(x1<=nrpatrate)
        {
        copiex1=x1; y1=y;
        while(matricebuna[copiex1][y1]==0 && y1>=1)
            {
            a[copiex1][y1]=0+'0';
            y1--;
            }
        y1=y;
        while(matricebuna[copiex1][y1]==0 && y1<=nrpatrate)
            {
            a[copiex1][y1]=0+'0';
            y1++;
            }
        y1=y;
        x1++;
        }

        }
        cout<<endl;
        a[x][y]=matricebuna[x][y]+'0';
        if(matricebuna[x][y]==9)
        {
            dead=1;
            cout<<"Ai pierdut!"<<endl;
            cout<<"9 reprezinta bomba"<<endl<<endl;
            for(int i=1;i<=nrpatrate;i++)
            {
                for(int j=1;j<=nrpatrate;j++)
                    cout<<matricebombe[i][j]<<" ";
                cout<<endl;
            }
        char raspuns1;
        cout<<endl;
        cout<<"Joc nou?"<<endl;
        cout<<"Tasteaza D pentru joc nou sau N pentru a iesi"<<endl;
        cin>>raspuns1;
        if(raspuns1=='D')
        {
            system("cls");
            game();

        }

        if(raspuns1=='N')
            return ;

        }
        if(matricebuna[x][y]!=9)
        {
             for(int i=1;i<=nrpatrate;i++)
                {
            for(int j=1;j<=nrpatrate;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
                }
            cout<<endl;
            cout<<"Numar bombe ramase="<<copienrbombe1<<endl<<endl;
        }
        //system("cls");


        }
            if(dead==0 && copienrbombe1==0)
            {
                cout<<"Ai castigat!"<<endl;
                char raspuns2;
                cout<<endl;
                cout<<"Joc nou?"<<endl;
                cout<<"Tasteaza D pentru joc nou sau N pentru a iesi"<<endl;
                cin>>raspuns2;
                if(raspuns2=='D')
                {
                    system("cls");
                    game();

                }

            if(raspuns2=='N')
            return ;



            }

    }while(dead!=1);




}

