#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f("turisti.in");
ofstream g("turisti.out");

class Turisti
{
    //date
    char nume[20];
    int varsta;
    char sexul;
    char activ_pref[20];
    bool masina_personala;
    //munte
    bool manastire;
    bool rau;
    bool sauna;
    bool cunoasterea_plantelor;
    bool supravietuire;
    //mare
    char tip_plaja[20];
    bool scufundari;
    bool croaziera;
    bool piscina;
    bool vizita_delfinariu;
    //muzeu
    char tip_muzeu[20];

public:
    friend istream& operator>>(istream&, Turisti&);
    friend ostream& operator<<(ostream&, Turisti&);
    Turisti();
    Turisti(const Turisti &c);
    ~Turisti();
    int GetVarsta(){return varsta;}
    char *GetNume(){return nume;}
    //munte:
    bool GetManastire(){return manastire;}
    bool GetRau(){return rau;}
    bool GetSauna(){return sauna;}
    bool GetPlante(){return cunoasterea_plantelor;}
    bool GetSupravietuire(){return supravietuire;}
    //mare:
    char *GetTipPlaja(){return tip_plaja;}
    bool GetScufundari(){return scufundari;}
    bool GetCroaziera(){return croaziera;}
    bool GetPiscina(){return piscina;}
    bool GetDelfinariu(){return vizita_delfinariu;}
    //muzeu:
    char *GetTipMuzeu(){return tip_muzeu;}
    char GetSexul(){return sexul;}
    char *GetActivitate(){return activ_pref;}

};

istream& operator>>(istream& in, Turisti& Citire)
{
    //date
    in>>Citire.nume;
    in>>Citire.varsta;
    in>>Citire.sexul;
    in>>Citire.activ_pref;
    in>>Citire.masina_personala;
    //munte
    in>>Citire.manastire;
    in>>Citire.rau;
    in>>Citire.sauna;
    in>>Citire.cunoasterea_plantelor;
    in>>Citire.supravietuire;
    //mare
    in>>Citire.tip_plaja;
    in>>Citire.scufundari;
    in>>Citire.croaziera;
    in>>Citire.piscina;
    in>>Citire.vizita_delfinariu;
    //muzeu
    in>>Citire.tip_muzeu;

    return in;
}

ostream& operator<<(ostream& out, Turisti& Afisare)
{
    return out;
}

Turisti::Turisti()
{
    //dete:
    varsta = 0;
    masina_personala = 0;
    //munte
    manastire = 0;
    sauna = 0;
    cunoasterea_plantelor = 0;
    supravietuire = 0;
    rau = 0;
    //mare
    scufundari = 0;
    croaziera = 0;
    piscina = 0;
    vizita_delfinariu = 0;
}

Turisti::Turisti(const Turisti &c)
{
    //date:
    strcpy(nume, c.nume);
    varsta = c.varsta;
    sexul = c.sexul;
    strcpy(activ_pref, c.activ_pref);
    masina_personala = c.masina_personala;
    //munte:
    manastire = c.manastire;
    sauna = c.sauna;
    cunoasterea_plantelor = c.cunoasterea_plantelor;
    supravietuire = c.supravietuire;
    rau = c.rau;
    //mare:
    strcpy(tip_plaja, c.tip_plaja);
    scufundari = c.scufundari;
    croaziera = c.croaziera;
    piscina = c.piscina;
    vizita_delfinariu = c.vizita_delfinariu;
    //muzeu:
    strcpy(tip_muzeu, c.tip_muzeu);
}

Turisti::~Turisti()
{}

class Activitate
{
    Turisti *t;
    int nr_turisti;
    char nume_activitate[20];
public:
    friend istream& operator>>(istream&, Activitate&);
    friend ostream& operator<<(ostream&, Activitate&);
    Activitate();
    Activitate(const Activitate &a);
    ~Activitate();
    void Mare();
    void Munte();
    void Muzeu();
    char *GetNumeActivitate()
    {
        return nume_activitate;
    }
};

istream& operator>>(istream& in, Activitate& Citire)
{
    int munte = 0, mare = 0, muzeu = 0;

    in>>Citire.nr_turisti;
    for(int i = 0; i < Citire.nr_turisti; i++)
        in>>Citire.t[i];
    for(int i = 0; i < Citire.nr_turisti; i++)
    {
        if(strcmp(Citire.t[i].GetActivitate(), "Munte") == 0)
            munte++;
        else
        if(strcmp(Citire.t[i].GetActivitate(), "Mare") == 0)
            mare++;
        else
        if(strcmp(Citire.t[i].GetActivitate(), "Muzeu") == 0)
            muzeu++;
    }
    if((munte >= mare) && (munte >= muzeu))
        strcpy(Citire.nume_activitate, "Munte");
    else
    if((mare >= munte) && (mare >= muzeu))
        strcpy(Citire.nume_activitate, "Mare");
    else
        strcpy(Citire.nume_activitate, "Muzeu");

    return in;
}

ostream& operator<<(ostream& out, Activitate& Afisare)
{
    return out;
}

Activitate::Activitate()
{
    nr_turisti = 0;
    t = new Turisti[nr_turisti];
}

Activitate::Activitate(const Activitate &c)
{
    nr_turisti = c.nr_turisti;
    t = c.t;
}

Activitate::~Activitate()
{
    delete[]t;
}

void Activitate::Munte()
{
    int i, munte1 = 0, munte2 = 0, munte3 = 0, munte4 = 0, munte5 = 0;
    //afisare
    g<<"OFERTA: Libertate in natura"<<endl;
    g<<"CAZARE: Cabana Trei Brazi****"<<endl;
    g<<"DETALII:"<<endl;
    for(i = 0; i < nr_turisti; i++)
    {
        if(t[i].GetVarsta() < 18 || t[i].GetVarsta() >90)
            g<<"- Turistul cu numele "<<t[i].GetNume()<<" nu poate participa la traseul cu dificultate grea";
        if(t[i].GetManastire() == 1)
            munte1++;
        if(t[i].GetRau() == 1)
            munte2++;
        if(t[i].GetSauna() == 1)
            munte3++;
        if(t[i].GetPlante() == 1)
            munte4++;
        if(t[i].GetSupravietuire() == 1)
            munte5++;
    }
    if(munte1 >= nr_turisti/2)
        g<<"- Excurise de o zi la Manastire Crucea"<<endl;
    if(munte2 >= nr_turisti/2)
        g<<"- Excursie de o zi cu barca pe raul Rece"<<endl;
    if(munte3 >= nr_turisti/2)
        g<<"- Abonament pe toata durata excursiei la sauna"<<endl;
    if(munte4 >= nr_turisti/2)
        g<<"- Excursie de o zi pentru a cunoaste plantele de la munte"<<endl;
    if(munte5 >= nr_turisti/2)
        g<<"- Excursie de  3 zile pentru a invata sa supravietuiesti in natura"<<endl;
    g<<"ATENTIE!"<<endl;
    g<<"-Traseul montan va tine 2 zile"<<endl;
    g<<"- Cele 3 mese sunt incluse in pret precum si acces nelimitat la piscina hotelului"<<endl;
    g<<"DURATA:"<<endl;
    g<<"3 - 8 zile"<<endl;
    g<<"PRET STANDARD:"<<endl;
    g<<"- 2 activitati la alegere: 1500 lei"<<endl;
    g<<"- 3 activitati la alegere: 2000 lei"<<endl;
    g<<"- 4 activitati la alegere: 2500 lei"<<endl;
    g<<"- numarul maxim de activitati disponibile: 3000 lei"<<endl;
}

void Activitate::Mare()
{
    int i;
    int mare1=0, mare2=0, mare3=0, mare4=0, mare5=0, mare6=0, mare7=0;
    //afisare
    g<<"OFERTA: Marea infinita"<<endl;
    g<<"CAZARE: Hotel Albastriu*****"<<endl;
    g<<"DETALII:"<<endl;
    for(i = 0; i < nr_turisti; i++)
    {
        if(strcmp(t[i].GetTipPlaja(), "Nudisti") == 0)
            mare1++;
        if(strcmp(t[i].GetTipPlaja(), "Nisip") == 0)
            mare2++;
        if(strcmp(t[i].GetTipPlaja(), "Pietricele") == 0)
            mare3++;
        if(t[i].GetScufundari() == 1)
            mare4++;
        if(t[i].GetCroaziera() == 1)
            mare5++;
        if(t[i].GetPiscina() == 1)
            mare6++;
        if(t[i].GetDelfinariu() == 1)
            mare7++;
    }
    if((mare1 >= mare2) && (mare1 >= mare3))
        g<<"- Plaja Nudisti"<<endl;
    else
    if((mare2 >= mare1) && (mare2 >= mare3))
        g<<"- Plaja cu nisip fin"<<endl;
    else
        g<<"- Plaja cu pietricele"<<endl;
    if(mare4 >= nr_turisti/2)
        g<<"- O zi plina de scufundari"<<endl;
    if(mare5 >= nr_turisti/2)
        g<<"- 3 zile de Croaziera va sunt la dispozitie"<<endl;
    if(mare6 >= nr_turisti/2)
        g<<"- Un abonament nelimitat pe toata perioada vacantei"<<endl;
    if(mare7 >= nr_turisti/2)
        g<<" O excursie de neuitat la Delfinariul din statiunde"<<endl;
    g<<"ATENTIE!"<<endl;
    g<<"-Activitatea Croaziera cat si cea la delfinariu necesita autovehicul personal"<<endl;
    g<<"- Cele 3 mese sunt incluse in pret"<<endl;
    g<<"DURATA:"<<endl;
    g<<"3 - 7 zile"<<endl;
    g<<"PRET STANDARD:"<<endl;
    g<<"- 2 activitati la alegere: 2500 lei"<<endl;
    g<<"- 3 activitati la alegere: 3500 lei"<<endl;
    g<<"- numarul maxim de activitati disponibile: 4000 lei"<<endl;

}

void Activitate::Muzeu()
{
    int i;
    int muzeu1=0, muzeu2=0, muzeu3=0;
    //afisare
    g<<"OFERTA: Intelectual"<<endl;
    g<<"CAZARE: Hotel Muzeu***"<<endl;
    g<<"DETALII:"<<endl;
    for(i = 0; i < nr_turisti; i++)
    {
        if(strcmp(t[i].GetTipMuzeu(), "Arta") == 0)
            muzeu1++;
        if(strcmp(t[i].GetTipMuzeu(), "Istorie") == 0)
            muzeu2++;
        if(strcmp(t[i].GetTipMuzeu(), "Stiinte") == 0)
            muzeu3++;
    }
    if((muzeu1 >= muzeu2) && (muzeu1 >= muzeu3))
        g<<"- Muzeul National de arte, Nicolae Tonitza"<<endl;
    else
    if((muzeu2 >= muzeu1) && (muzeu2 >= muzeu3))
        g<<"- Muzeul National de Istorie"<<endl;
    else
    {
          if(t[i].GetSexul() == 'F')
            g<<"- Accesul la Muzeul National Tehnic Dimitrie Leonida este INTERZIS femeilor"<<endl;
        else
        //if(t[i].GetSexul() == 'M')
            g<<"Muzeul National Tehnic Dimitrie Leonida";
    }
    g<<"ATENTIE!"<<endl;
    g<<"Activitatea necesita autovehicul"<<endl;
    g<<"- Cele 3 mese sunt incluse in pret"<<endl;
    g<<"DURATA:"<<endl;
    g<<"2 zile"<<endl;
    g<<"PRET: 1000 lei";

}

int main()
{
    Activitate a;
    f>>a;
    if(strcmp(a.GetNumeActivitate(), "Munte") == 0)
        a.Munte();
    else
    if(strcmp(a.GetNumeActivitate(), "Mare") == 0)
        a.Mare();
    else
    if(strcmp(a.GetNumeActivitate(), "Muzeu") == 0)
        a.Muzeu();


    return 0;
}
