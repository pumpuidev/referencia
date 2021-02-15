#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;

class Matrix //altalaban azert a deklaraciokat es definiciokat illik elvalasztani kulon fajlokba
{
private:	//a matrix "reprezentacioja" kerul a privat reszbe
    vector<vector<int> > mx;
    size_t n;	//(erre vegul is nincs szukseg -- mert n = mx.size() -- csak a pelda kedveert van)

public:		//a publikba pedig az osztaly "interfesze"
    Matrix(size_t n, bool nullaz = false)	//konstruktor. hivhato (int,bool) es (int) parameterezessel is
    {
        mx.resize(n);
        this->n = n;			//ha a param. neve azonos, mint az adattag, akkor elfedi azt, de a thisen keresztul elerjuk az adattagot is
        for(size_t i=0; i<n; ++i)
        {
            mx[i].resize(n);
            for(size_t j=0; j<n; ++j)
            {
                if(nullaz)
                    mx[i][j] = 0;			//nullmatrix
                else
                    mx[i][j] = rand() % 10;	//[0..9]-beli random szamok
            }
        }
    }

    ~Matrix()	//destruktor
    {
        cout<<"Destruktor meghivodott egy "<<n<<"x"<<n<<"-es matrixon."<<endl;
    }   //lathato, ezen a ponton meg elnek a (statikus memoriabeli) attributumok!

    void Kiir(ostream& os) const //const, mert a thist (azaz azt a matrixot, akin meghivom) nem modositja
    {
        //az ostreamet viszont igen, hiszen kiir ra...
        for(size_t i=0; i<n; ++i)
        {
            for(size_t j=0; j<n; ++j)
            {
                os<<mx[i][j]<<" ";
            }
            os<<endl;
        }
    }

    int Lekerdez(size_t i,size_t j) const
    {
        return mx[i][j];
    }

    void Modosit(size_t i, size_t j, int ertek)	//ez nem const, mert modosit
    {
        //a legritkabb esetekben hasznalunk publikus adattagokat,
        mx[i][j] = ertek;		//inkabb irunk publikus lekerdezo es modosito fuggvenyeket, mint itt is.
    }							//indoklast lasd pdf-ben

    //elofeltetel: "this" es "kit" meretei azonosak
    Matrix Szorzas(const Matrix& kit) const
    {
        //ez most ugy mukodik hogy egy matrixon meghivom, atadok neki parameterul egy masikat
        //egyik matrixot se modositom, hanem letrehozok egy harmadikat. teljesen jo megoldas, de nem tul szep,
        //hivaskor furan nez ki. mert miert van a baloldali operandus "kiemelve"?

        Matrix uj(n,true); //kezdetben csupa nulla
        for(size_t i=0; i<n; ++i)
            for(size_t j=0; j<n; ++j)
                for(size_t k=0; k<n; ++k)
                    uj.mx[i][j] += (mx[i][k] * kit.mx[k][j]);
        return uj;
    }

    //elofeltetel: a es b meretei azonosak, es mindketto negyzetes
    friend Matrix Szorzas(const Matrix& a, const Matrix& b)
    {
        //ebben a fuggvenyben most nincs szintaktikailag "kiemelve" az egyik operandus
        //ennek kovetkezteben ez NEM a Matrix osztaly tagfuggvenye, csak az osztaly baratfv-e
        Matrix uj(a.n,true); //kezdetben csupa nulla
        for(size_t i=0; i<a.n; ++i)
            for(size_t j=0; j<a.n; ++j)
                for(size_t k=0; k<a.n; ++k)
                    uj.mx[i][j] += (a.mx[i][k] * b.mx[k][j]);
        return uj;
    }

    //elofeltetel: "this" es "kit" meretei azonosak, es mindketto negyzetes
    void Hozzaszoroz(const Matrix& kit)
    {
        //most megint ki van emelve a baloldali operandus (this)
        //de jelen fuggvenynel ez logikus, hiszen ez nem egy uj matrixot
        //hoz letre a ket konstans matrixbol, hanem a jobb oldalit beken
        //hagyja, a baloldalit meg modositja ugy, hogy hozzaszorozza a jobboldalit
        //ez alapjan ezt logikus a "baloldalin meghivni"

        //persze vissza lehet vezetni a mar megirt muveletre!
        mx = (this->Szorzas(kit).mx);	 //a "this->" resz elhagyhato...
    }

    //Elofeltetel: azonos dimenziojuak legyenek
    void Hozzaad(const Matrix& kit)
    {
        for(size_t i=0; i<n; ++i)
            for(size_t j=0; j<n; ++j)
                mx[i][j] += kit.mx[i][j];
        //ezt is irhattam volna:
        //		Modosit((i,j,Lekerdez(i,j)+kit.Lekerdez(i,j)));
    }

    //Elofeltetel: azonos dimenziojuak legyenek
    friend Matrix operator+(const Matrix& a, const Matrix& b)
    {
        //ez a legszebb megoldas ilyen esetekre, a sima + jelet "altalanositottuk"
        Matrix m(a.n);
        for(size_t i=0; i<a.n; ++i)
            for(size_t j=0; j<a.n; ++j)
                m.mx[i][j] = a.mx[i][j] + b.mx[i][j];
        return m;
        //ezt megirhattam volna ilyen szignaturaval is:
        //Matrix operator+(const Matrix& b) const
        //az "operatorsag" miatt igy is-ugy is
        //meg szabad hivni infix modon
    }

    Matrix operator*(int n) const
    //ez a konstanssal valo szorzas.
    {
        Matrix m(this->n);
        for(size_t i=0; i<this->n; ++i)
            for(size_t j=0; j<this->n; ++j)
                m.mx[i][j] = (this->mx[i][j]) * n;
        return m;
        //felmerul az az igeny is, hogy en nem csak mx*szam,
        //hanem szam*mx alakban is hasznalhassam ezt...
        //ez teljesen kommutativ, ugyan azt adja... viszont az inten
        //nem tudom ertelmezni a "matrixszal valo szorzast", hiszen
        //1) az int definiciojat nem modosithatom, mert akkor minden gepen
        //forditva mas es mas lenne az int jelentese
        //2) az int eleve nem osztaly -> nem irhatok neki tagfuggvenyeket
        //megoldas: barat fuggveny, erre a fuggvenyre visszavezetve (a kommutativitas miatt)
        //lasd kovetketo fuggveny
    }

    friend Matrix operator*(int n, const Matrix& m)
    {
        return m*n;	//tehat ez az elozo fuggvenyt hivja meg!
        //ha ugy tetszik:
        //return m.operator*(n);
        //es ez fordul es fut!!!
    }

    //a fuggvenytulterheles illusztralasara:
    void Tulterh(int n, int m)
    {
        cout<<"Tulterh(int,int)"<<endl;
    }

    void Tulterh(int n, double m)
    {
        cout<<"Tulterh(int,double)"<<endl;
    }

    //statikus (osztalyszintu) fuggveny:
    static void Stat()
    {
        cout<<"Stat()"<<endl;
    }
};

int main()
{
    srand(time(NULL));

    Matrix m1(4);
    cout<<"m1 4-szer 4-es:"<<endl;
    m1.Kiir(cout);
    cout<<endl;

    {
        Matrix m2(4);	//blokkon belul hozva letre...
    }					//... a destruktora mar itt, a blokk vegen lefut, mig a tobbinek csak a main() vegen.
    cout<<"m2 mar nincs, szegeny"<<endl;
    cout<<endl;

    Matrix m3(3);
    Matrix m4(3);

    //m2.Kiir(cout);	//o mar nem el
    cout<<"m3 eredeti:"<<endl;
    m3.Kiir(cout);
    cout<<endl;
    cout<<"m4 eredeti:"<<endl;
    m4.Kiir(cout);
    cout<<endl;

    m3.Hozzaszoroz(m4);
    cout<<"Itt meghivunk egy muveletet, ami visszater egy matrixszal, ";
    cout<<"de ezt a matrixot eldobjuk es csak a \"mx\" adattagjat tartjuk meg. ";
    cout<<"Itt ezert hivodott meg a konstruktor"<<endl;
    cout<<endl;

    cout<<"m3 <- m3*m4:"<<endl;
    m3.Kiir(cout);
    cout<<endl;
    cout<<"de m4 megmaradott annak, ami:"<<endl;
    m4.Kiir(cout);
    cout<<endl;

    cout<<"m5 legyen m4 negyzete:"<<endl;
    Matrix m5 = m4.Szorzas(m4);
    m5.Kiir(cout);
    cout<<endl;
    cout<<"de m4 nyilvan nem valtozott:"<<endl;
    m4.Kiir(cout);
    cout<<endl;
    cout<<"se m3 a legutobbi ota:"<<endl;
    m3.Kiir(cout);
    cout<<endl;

    cout<<"m4-et most duplazzuk meg:"<<endl;
    m4.Hozzaad(m4);
    m4.Kiir(cout);
    cout<<endl;

    cout<<"majd megint:"<<endl;
    m4 = m4 + m4;
    m4.Kiir(cout);
    cout<<endl;

    cout<<"m3-at mindegy, hogy balrol vagy jobbrol szorzom konstanssal:"<<endl;
    m5 = m3*2;
    m5.Kiir(cout);
    cout<<endl;
    m5 = 2*m3;
    m5.Kiir(cout);
    cout<<endl;
    cout<<"m3 maga persze nem valtozott meg:"<<endl;
    m3.Kiir(cout);
    cout<<endl;

    m1.Tulterh(5,5);	//ket int, tiszta sor
    m1.Tulterh(5,5.0);	//int double, ilyen is van, tiszta sor
    m1.Tulterh(5.0,5);	//itt az elso double kenytelen intkent viselkedni - kerekites miatti adatvesztes lehet
    m1.Tulterh(5.0,5.0);//itt pedig az elso int kasztolodik double-le. ha ez az int nagyon nagy lenne, akkor szinten adatvesztes terhe mellett
    cout<<endl;

    Matrix::Stat();		//ehhez meg nem kell leteznie objektumnak.
    m1.Stat(); 			//de szintaktikailag szabad objektumon is hivni, de ugyanugy osztalyszintukent viselkedik
    cout<<endl;

    cout<<"A destruktorok pedig meghivodnak a letrehozassal ellentetes sorrendben (lasd hivasi verem)"<<endl;

    return 0;
}
