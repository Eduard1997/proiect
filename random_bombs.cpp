#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void game();
int nrpatrate, nrbombe;
int main()
{
    cout<<"Bun venit la Minesweeper!"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Dati numarul de patrate per linie"<<endl;
    cin>>nrpatrate;
    cout<<"---------------------------------"<<endl;
    game();
    return 0;
}
void game()
{
    srand(time(NULL));

    char a[nrpatrate][nrpatrate];
    for(int i=1;i<=nrpatrate;i++)
    {
        for(int j=1;j<=nrpatrate;j++)
        a[i][j]='x';

    }

        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
                cout<<a[i][j]<<" ";
                cout<<endl;
        }
    cout<<endl;
     int revealed[nrpatrate][nrpatrate], nrbombe, copiebombe;
        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
            revealed[i][j]=0;

        }
    do {
        cout<<"dati numarul de bombe (1-"<<(nrpatrate*nrpatrate)-1<<")"<<endl;
        cin>>nrbombe;
        if(nrbombe<1 || nrbombe>nrpatrate*nrpatrate-1)
            cout<<"ati introdus valoarea gresita"<<endl;

    }while(nrbombe<1 || nrbombe>(nrpatrate*nrpatrate)-1);

            int p, q, copienrbombe,marcare[nrpatrate][nrpatrate];
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

        for(int i=1;i<=nrpatrate;i++)
        {
            for(int j=1;j<=nrpatrate;j++)
                cout<<revealed[i][j]<<" ";
            cout<<endl;

        }


}
