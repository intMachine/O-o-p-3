#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
using namespace std;


time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int year = aTime->tm_year + 1900;
int month = aTime->tm_mon + 1;


class automobil
{
private:
    string model;
    string producator;
    int anFab;
    float lungime;
    float pret;

public:
    int getAn(){return anFab;}
    int getPret(){return pret;}
    void setPret(float p){pret = p;}
    automobil(string model="", string producator="", int anFab=0, float lungime=0, float pret=0);
    automobil(const automobil &Ob);
    virtual ~automobil();
    void afisare(ostream& out);
    void citire(istream& in);
    virtual bool isEqual(const automobil& Ob) const
    {
        if(Ob.anFab == anFab && Ob.model == model && Ob.producator == producator && Ob.lungime == lungime && Ob.pret == pret)
            return true;
        else return false;
    }
    friend bool operator==(const automobil&, const automobil&);
    automobil& operator=(automobil &Ob);
    friend ostream& operator<<(ostream&, const automobil&);
    friend istream& operator>>(istream&, automobil&);
};
automobil& automobil :: operator= (automobil &Ob)
{
    if (this!=&Ob)
    {
        model = Ob.model;
        producator = Ob.producator;
        anFab = Ob.anFab;
        lungime = Ob.lungime;
        pret = Ob.pret;
    }
    return *this;
}
automobil :: automobil(string mod, string prd, int an, float ln, float p)
{
    model = mod;
    producator = prd;
    anFab = an;
    lungime = ln;
    pret = p;
}
automobil :: automobil(const automobil &Ob)
{
    model = Ob.model;
    producator = Ob.producator;
    anFab = Ob.anFab;
    lungime = Ob.lungime;
    pret = Ob.pret;
}
automobil :: ~automobil()
{
    model = producator = anFab = lungime = pret = NULL;
}
void automobil :: afisare(ostream &out)
{
    out<<"Model: "<<model<<endl;
    out<<"Producator: "<<producator<<endl;
    out<<"An fabricatie: "<<anFab<<endl;
    out<<"Lungime: "<<lungime<<endl;
    out<<"Pret: "<<pret<<" lei";
}
ostream& operator<<(ostream &out, automobil &Ob)
{
    Ob.afisare(out);
    return out;
}
void automobil :: citire(istream &in)
{
    cout<<"Model: ";
    in>>model;

    cout<<"Producator: ";
    in>>producator;

    cout<<"An fabricatie: ";
    in>>anFab;

    cout<<"Lungime: ";
    in>>lungime;

    cout<<"Pret: ";
    in>>pret;
}
istream& operator>>(istream &in, automobil &Ob)
{
    Ob.citire(in);
    return in;
}

bool operator==(const automobil& left, const automobil& right) {
    return typeid(left) == typeid(right) && left.isEqual(right);
}

class mini : public automobil
{
private:
    string clasa = "MINI";
public:
    mini(string model="", string producator="", int anFab=0, float lungime=0, float pret=0) : automobil(model, producator, anFab, lungime, pret){}
    mini(const mini& Ob) : automobil(Ob){}
    friend ostream& operator<<(ostream&, const mini&);
    void afisare(ostream& out);
};

void mini :: afisare(ostream &out)
{
    out<<"Clasa: "<<clasa<<endl;
    automobil::afisare(out);
}
ostream& operator<<(ostream &out, mini &Ob)
{
    Ob.afisare(out);
    return out;
}


class mica : public automobil
{
private:
    string clasa = "MICA";

public:
    mica(string model="", string producator="", int anFab=0, float lungime=0, float pret=0) : automobil(model, producator, anFab, lungime, pret){}
    mica(const mica& Ob) : automobil(Ob){}
    friend ostream& operator<<(ostream&, const mica&);
    void afisare(ostream& out);
};

void mica :: afisare(ostream &out)
{
    out<<"Clasa: "<<clasa<<endl;
    automobil::afisare(out);
}
ostream& operator<<(ostream &out, mica &Ob)
{
    Ob.afisare(out);
    return out;
}


class compacta : public automobil
{
private:
    string clasa = "COMPACTA";
    string caroserie;

public:
    compacta(string model="", string producator="", int anFab=0, float lungime=0, float pret=0, string car="") : automobil(model, producator, anFab, lungime, pret){caroserie = car;}
    compacta(const compacta& Ob) : automobil(Ob){ caroserie = Ob.caroserie; }
    friend ostream& operator<<(ostream&, const compacta&);
    void afisare(ostream& out);
    friend istream& operator>>(istream&, const compacta&);
    void citire(istream& in);
};

void compacta :: citire(istream &in)
{
    int x=0;
    while(x<1 || x>4)
    {
        cout<<"Caroserie \n 1:Sedan \n 2:Hatchback \n 3:Combi \n";
        cin>>x;
        if(x<1 || x>4)
            cout<<"Va rog alegeti un numar de la 1 la 3 \n";
    }
    switch (x)
    {
        case 1: {caroserie = "Sedan"; break;}
        case 2: {caroserie = "Hatchback"; break;}
        case 3: {caroserie = "Combi"; break;}
    }
    automobil::citire(in);
}
void compacta :: afisare(ostream &out)
{
    out<<"Clasa: "<<clasa<<endl;
    out<<"Caroseria: "<<caroserie<<endl;
    automobil::afisare(out);
}
ostream& operator<<(ostream &out, compacta &Ob)
{
    Ob.afisare(out);
    return out;
}
istream& operator>>(istream &in, compacta &Ob)
{
    Ob.citire(in);
    return in;
}


class monovolume : public automobil
{
private:
    string clasa = "MONOVOLUME";

public:
    monovolume(string model="", string producator="", int anFab=0, float lungime=0, float pret=0) : automobil(model, producator, anFab, lungime, pret){}
    friend ostream& operator<<(ostream&, const monovolume&);
    void afisare(ostream& out);
};

void monovolume :: afisare(ostream &out)
{
    out<<"Clasa: "<<clasa<<endl;
    automobil::afisare(out);
}
ostream& operator<<(ostream &out, monovolume &Ob)
{
    Ob.afisare(out);
    return out;
}

template <class t> class Vanzare
{
private:
    t *stoc;
    t *vandute;
    int nrVand;
    int nrStoc;

public:
    Vanzare(t *x=NULL, int n=0)
    {
        n+=1;
        nrStoc=n;
        nrVand=0;
        if (n!=0){
            stoc=new t[n];
            vandute = new t[n];
            for(int i=0;i<n;i++)
            {
                stoc[i]=x[i];
            }
        }
    }
    Vanzare(Vanzare<t>& Aux)
    {
        stoc = Aux.stoc;
        vandute = Aux.vandute;
        nrStoc = Aux.nrStoc;
        nrVand = Aux.nrVand;
    }
    ~Vanzare()
    {
    }
    void destr()
    {
        delete stoc;
        delete vandute;
        nrStoc = 0;
        nrVand = 0;
    }

    int getNrStoc(){return nrStoc;}
    void dec(){nrStoc--;}
    void operator-= (const t &Ob);
    void operator+= ( t &Ob);
    friend ostream& operator<<(ostream& out, const Vanzare& Ob)
    {
        out<<"Masini in stoc \n";
        for(int i=0; i<Ob.nrStoc-1; i++)
            out<<i+1<<":"<<Ob.stoc[i]<<"\n\n";
        out<<"\n Masini vandute \n";
        for(int i=1; i<=Ob.nrVand; i++)
            out<<i<<":"<<Ob.vandute[i]<<"\n \n";
        return out;
    }
    void sell(int x)
    {
        this->nrStoc--;
        this->nrVand++;
        this->vandute[nrVand] = stoc[x];
        for (int i=0; i<=nrStoc; i++)
        {
            if(stoc[i] == stoc[x])
            {
                for(int j=i; j<nrStoc; j++)
                stoc[j]=stoc[j+1];
                delete &stoc[nrStoc];
                break;
            }
        }
    }
};
template <class t> void Vanzare<t> :: operator-=(const t &Ob)
{
    this->nrStoc--;
    this->nrVand++;
    this->vandute[nrVand] = Ob;
    for (int i=0; i<=nrStoc; i++)
    {
        if(stoc[i] == Ob)
        {
            for(int j=i; j<nrStoc; j++)
            stoc[j]=stoc[j+1];
            delete &stoc[nrStoc];
            break;
        }
    }
}

template <class t> void Vanzare<t> :: operator+=( t &Ob)
{
    this->nrStoc++;
    stoc[nrStoc] = Ob;
}

template <>
class Vanzare <monovolume>
{
private:
    monovolume *stoc;
    monovolume *vandute;
    int nrVand;
    int nrStoc;

public:
    Vanzare(monovolume *x=NULL, int n=0)
    {
        n+=1;
        nrStoc=n;
        nrVand=0;
        if (n!=0)
        {
            stoc=new monovolume[n];
            vandute = new monovolume[n];
            for(int i=0;i<n;i++)
            {
                stoc[i]=x[i];
            }
        }
    }
    void operator=(Vanzare<monovolume> &Ob);
    void operator-= (monovolume &Ob);
    friend ostream& operator<<(ostream& out, const Vanzare& Ob)
    {
        out<<"Masini in stoc \n";
        for(int i=0; i<Ob.nrStoc-1; i++)
            out<<i+1<<Ob.stoc[i]<<"\n\n";
        out<<"\n Masini vandute \n";
        for(int i=1; i<=Ob.nrVand; i++)
            out<<i<<Ob.vandute[i]<<"\n \n";
        return out;
    }
    void sell(int x)
    {
        this->nrStoc--;
        this->nrVand++;
        this->vandute[nrVand] = stoc[x];
        for (int i=0; i<=nrStoc; i++)
        {
            if(i==x)
            {
                for(int j=i; j<nrStoc; j++)
                stoc[j]=stoc[j+1];
                delete &stoc[nrStoc];
                break;
            }
        }
    }
};
void Vanzare<monovolume> :: operator=(Vanzare<monovolume> &Aux)
{
        stoc = Aux.stoc;
        vandute = Aux.vandute;
        nrStoc = Aux.nrStoc;
        nrVand = Aux.nrVand;
}
void Vanzare<monovolume> :: operator-=(monovolume &Ob)
{
    float difAni = year-Ob.getAn();
    if(difAni>9)
        difAni = 9;
    float newPret = Ob.getPret() - difAni/10*Ob.getPret();
    if(month>5 && month<9)
        newPret = newPret - newPret*0.1;
    cout<<newPret;
    Ob.setPret(newPret);
    this->nrStoc--;
    this->nrVand++;
    this->vandute[nrVand] = Ob;
    for (int i=0; i<=nrStoc; i++)
    {
        if(stoc[i] == Ob)
        {
            for(int j=i; j<nrStoc; j++)
            stoc[j]=stoc[j+1];
            delete &stoc[nrStoc];
            break;
        }
    }
}



void menu_output()
{
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii despre automobile";
    cout<<"\n";
    cout<<"2. Vinde automobil";
    cout<<"\n";
    cout<<"3. Afiseaza automobilele";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

void menu()
{
    int option;
    option=0;
    int n=0;
    bool ok=false;
    bool ok1=false;
    bool ok2=false;
    bool ok3=false;
    bool ok4=false;
    mini a1[3];
    mica a2[3];
    compacta a3[3];
    monovolume a4[3];
    Vanzare<mini>m(a1, 0);
    Vanzare<mica>M(a2, 0);
    Vanzare<compacta>comp(a3, 0);
    Vanzare<monovolume>mon(a4, 0);
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            int model=0;
            do
            {
                cout<<"Introduceti tipul automobilului: \n 1:MINI \n 2:MICA \n 3:COMPACATA \n 4:MONOVOLUM \n";
                cin>>model;
                if(model<1 || model>4)
                    cout<<"Introduceti un numar de la 1 la 4 \n";
            }while(model<1 || model>4);

            cout<<"Introduceti numarul de obiecte citite: ";
            cin>>n;

            if (n>0)
                switch (model)
            {
                case 1:
                    {
                        mini aut1[n+1];
                        for(int i=0; i<n; i++)
                            {cin>>aut1[i];
                            m+=aut1[i];}
                        ok=true;
                        ok1=true;
                        break;
                    }
                case 2:
                    {
                        mica aut2[n+1];
                        for(int i=0; i<n; i++)
                            cin>>aut2[i];
                        Vanzare<mica> aux2(aut2, n);
                        M = aux2;
                        ok=true;
                        ok2=true;
                        break;
                    }
                case 3:
                    {
                        compacta aut3[n+1];
                        for(int i=0; i<n; i++)
                            cin>>aut3[i];
                        Vanzare<compacta> aux3(aut3, n);
                        comp = aux3;
                        ok=true;
                        ok3=true;
                        break;
                    }
                case 4:
                    {
                        monovolume aut4[n+1];
                        for(int i=0; i<n; i++)
                            cin>>aut4[i];
                        Vanzare<monovolume> aux4(aut4, n);
                        mon = aux4;
                        ok=true;
                        ok4=true;
                        break;
                    }
            }
            else
                {cout<<"Numarul introdus trebuie sa fie intre 1 si 4.\n"; break;}
        }
        if (option==2)
        {
            int model=0;
            int alegere= 0;
            do
            {
                cout<<"Introduceti tipul automobilului: \n 1:MINI \n 2:MICA \n 3:COMPACATA \n 4:MONOVOLUM \n";
                cin>>model;
                if(model<1 || model>4)
                    cout<<"Introduceti un numar de la 1 la 4 \n";
            }while(model<1 || model>4);
            switch (model)
            {
                case 1:
                    {
                        cout<<m;
                        cout<<"\n alegeti nr unei masini ";
                        cin>>alegere;
                        if(alegere > 0 && alegere < m.getNrStoc())
                            {
                                m.sell(alegere);
                                cout<<m;
                            }
                        break;
                    }
                case 2:
                    {
                        cout<<M;
                        cout<<"\n alegeti nr unei masini ";
                        cin>>alegere;
                        if(alegere > 0 && alegere < M.getNrStoc())
                            {
                                M.sell(alegere);
                                cout<<M;
                            }
                        break;
                    }
                case 3:
                    {
                        cout<<comp;
                        cout<<"\n alegeti nr unei masini ";
                        cin>>alegere;
                        if(alegere > 0 && alegere < comp.getNrStoc())
                            {
                                comp.sell(alegere);
                                cout<<comp;
                            }
                        break;
                    }
                case 4:
                    {
                        cout<<mon;
                        cout<<"\n alegeti nr unei masini ";
                        cin>>alegere;
                        if(alegere > 0 && alegere < m.getNrStoc())
                            {
                                mon.sell(alegere);
                                cout<<mon;
                            }
                        break;
                    }
            }
        }
        if (option==3)
        {
            if(ok)
            {
                if(ok1)
                    cout<<m<<endl;
                if(ok2)
                    cout<<M<<endl;
                if(ok3)
                    cout<<comp<<endl;
                if(ok4)
                    cout<<mon<<endl;
            }
            else cout<<"Nu exista date";
        }
        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>5)
        {
            m.destr();
            M.destr();
            comp.destr();
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }
    while(option!=0);
}
int main()
{
    menu();

    return 0;
}

