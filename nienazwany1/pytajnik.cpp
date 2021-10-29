/*
#include <iostream>
#include <stdlib.h>

#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>

using namespace std;

int wylosuj (int low, int high){
    return low + rand() % (high-low+1);

}

class pytajnik {
public:
    string slowo1;
    string slowo2;

    void wpisz(string h,int i) {
        if(i%2) slowo1=h;
        else slowo2=h;

    };
    void wyswietl(int i) {
        if(i%2) cout<<slowo1<<" ";
        else cout<<slowo2<<" ";
    };

};


int main()
{
    srand(time(NULL));
    string h;
    int N,l;
    N=l=0;
    int i,j,k,m;
    ofstream plikcpp1;
    fstream plikcpp;
    plikcpp1.open("slowka.txt",ios::app);
    //plikcpp.open("slowka.txt", ios::in |  ios::out); //app // plik nie chce otworzyc sie sam

    cout << "Czy chcialbys dodac do swojej listy kilka slowek przed rozpoczecien nauki? (tak/nie)" << endl;
    cin>>h;
    if(h=="tak"){
        cout<<"Ile slowek chcialbys dodac?"<<endl;

        do {
            cin>>N;
            l=cin.fail();

            if(N<0) cout<<"Nie mozesz w ten sposob usuwac slowek. Zajmiemy sie tym pozniej. \n";
            if(N>100) cout<<"To troche za duzo jak na jeden raz. Ogranicz sie do 100 slowek w tym podejsciu. \n";
            if(l==1) {
                cout<<"Zapisz liczbe slowek w systemie dziesietnym i prosze nie uzywaj zbednych znakow \n";
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }while (N < 0 || N > 100 || l !=0);

        cout<<"Prosze wpisz slowka w formacie english:angielski.Oddzielaj slowka dwukropkiem"<<endl;
    }
        plikcpp1.seekp( 0, std::ios_base::end );
        for(i=0;i<N;i++) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(1000,'\n');
            }
            cin>>h;
            plikcpp1<<h<<endl;
        }
        plikcpp1.close();
        plikcpp.open("slowka.txt", ios::in |  ios::out);


        l=0;
        plikcpp.seekg( 0, std::ios_base::beg ); //
        while(getline(plikcpp,h)) {
            l++;
            //cout<<h<<" . ";
        }
        if(l==0) {
            cout<<"Plik jest pusty lub nie udalo sie go otworzyc"<<endl;
            exit(0);
        }
        cout<<"Masz zapisanych "<<l*2<<" slowek."<<endl;

        m=0;
        if(l==1) m=1;
        pytajnik pytu[l+m]; // nie chce stworzyc jedno elementowej tablicy
        plikcpp.clear();
        plikcpp.seekg( 0, std::ios_base::beg );


        cout<<"Twoja aktualna lista slowek "<<endl;
        for(i=0;i<l;i++) {
            getline(plikcpp,h,':');
            //cout<<h<<" . ";
            pytu[i].wpisz(h,1);
            getline(plikcpp,h);
            pytu[i].wpisz(h,2);
            pytu[i].wyswietl(1);
            pytu[i].wyswietl(2);
            cout<<endl;
        }

        do {
            cout<<"Na ile pytan chcesz odpowiedziec? "<<endl;
            cin>>N;
            j=cin.fail();

            if(N<0) cout<<"Usun ten minus zanim ktos zobaczy. \n";
            if(N>100) cout<<"To troche za duzo jak na jeden raz. Ogranicz sie do 100 pytan w tym podejsciu. \n";
            if(j==1) {
                cout<<"Zapisz liczbe pytan w systemie dziesietnym i prosze nie uzywaj zbednych znakow \n";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            //cout<<N<<endl;
        }while (N < 0 || N > 100 || j !=0);

        j=0;
        for(i=0;i<N;i++) {

            k=j;
            while(k==j) {
                if(l>1) j=wylosuj(0,l-1);
                else {
                    j=0;
                    break;
                }
            }
            m=wylosuj(0,1);
            if(m ) cout<<"Co znaczy "<<pytu[j].slowo1<<" ?"<<endl;
            else cout<<"Co znaczy "<<pytu[j].slowo2<<" ?"<<endl;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(1000,'\n');
            }
            cin>>h;
            if(( m && h==pytu[j].slowo2 ) || ( !m && h==pytu[j].slowo1 ) )
                cout<<"To jest prawidlowa odpowiedz "<<endl;
            else {
                if(m) cout<<"Prawidlowa odpowiedz to: "<<pytu[j].slowo2<<endl;
                else cout<<"Prawidlowa odpowiedz to: "<<pytu[j].slowo1<<endl;
            }
        }


        //delete[] pytu; //zwraca blad
        plikcpp.close();
        return 0;
}
*/
