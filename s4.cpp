#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Interfata{
    virtual float calculTVA()=0;//pura, pt vanzare //fs virt pura nu are corp, e egala cu 0
    virtual string afisareVIN(){
        return "098765";
    };
};

class Masina:public Interfata{
private:
    string VIN;
    float buy_price;
    float sell_price;
    bool test_ITP;
public:
    float calculTVA(){
        float TVA=this->sell_price*0.24;
        return TVA;
    }

    string afisareVIN(){
        return this->VIN;
    }

    Masina(){
        this->VIN="0000";
        this->buy_price=NULL;
        this->sell_price=NULL;
        this->test_ITP=0;
    }
    Masina(string VN,float buy,float sell,bool ITP){
        this->VIN=VN;
        this->buy_price=buy;
        this->sell_price=sell;
        this->test_ITP=ITP;
    }
    Masina(Masina &a){
        this->VIN=a.VIN;
        this->buy_price=a.buy_price;
        this->sell_price=a.sell_price;
        this->test_ITP=a.test_ITP;
    }

    Masina operator=(Masina &a){
        this->VIN=a.VIN;
        this->buy_price=a.buy_price;
        this->sell_price=a.sell_price;
        this->test_ITP=a.test_ITP;
        return *this;
    }

    void setVIN(string VN){
        this->VIN=VN;
    }

    void setBuy(float buy){
        this->buy_price=buy;
    }

    void setSell(float sell){
        this->sell_price=sell;
    }

    string getVIN(){
        return this->VIN;
    }

    float getBuy(){
        return this->buy_price;
    }

    float getSell(){
        return this->sell_price;
    }

    friend ostream & operator<<(ostream & out, Masina & a);
    friend istream & operator>>(istream & in, Masina & a);

    float Profit(float comision){
        float sell_c=this->sell_price+(this->sell_price*comision)/100;
        return (sell_c-(this->buy_price));
    }

    bool operator>(Masina & a){
        if(this->Profit(15.0)>a.Profit(15.0))
            return true;
            else
            {
                return false;
            }
            
    }

    Masina & operator++(){
        this->buy_price=this->buy_price+500;
        return *this;
    }

    Masina & operator-(float comision){
        this->sell_price=(this->sell_price-500)+(this->sell_price-500)*0.05;
        return *this;
    }

};

ostream & operator<<(ostream & out, Masina & a){
    out<<"VIN:"<<a.getVIN();
    out<<"BUY:"<<a.getBuy();
    out<<"SELL:"<<a.getSell();
    return out;
};
istream & operator>>(istream & in, Masina & a){
    in>>a.VIN>>a.buy_price>>a.sell_price;
    return in;
};


//in magazin fac suma profitului pe masina la comisionu de 15%
class Magazin{
private:
    float adaos_comercial;
    Masina *masini;
    int nr_masini;
    float pret_vanzare;
public:
    void SalvareTXT(string nume,int valid){
        cin>>this->adaos_comercial;
        cin>>this->nr_masini;
        cin>>this->pret_vanzare;
        for(int i=0;i<this->nr_masini;i++)
            cin>>this->masini[i];
        if(this->nr_masini>=valid){
        ofstream out(nume);
        out<<"Adaos:"<<this->adaos_comercial<<endl;
        out<<"Nr masini:"<<this->nr_masini<<endl;
        for(int i=0;i<this->nr_masini;i++)
            out<<this->masini[i];
        }
    }

    Magazin(){
        this->adaos_comercial=0.0;
        this->nr_masini=0;
        this->masini=NULL;
        this->pret_vanzare=0.0;
    }

    Magazin(float adaos, Masina *cars,int nr,float pret){
        this->adaos_comercial=adaos;
        this->nr_masini=nr;
        this->pret_vanzare=pret;
        this->masini=new Masina[this->nr_masini];
        for(int i=0;i<this->nr_masini;i++)
            this->masini[i]=cars[i];
    }

    Magazin(Magazin &a){
        this->adaos_comercial=a.adaos_comercial;
        this->nr_masini=a.nr_masini;
        this->pret_vanzare=a.pret_vanzare;
        this->masini=new Masina[this->nr_masini];
        for(int i=0;i<this->nr_masini;i++)
            this->masini[i]=a.masini[i];
    }

    Magazin & operator=(Magazin &a){
        delete[]this->masini;
        this->adaos_comercial=a.adaos_comercial;
        this->nr_masini=a.nr_masini;
        this->pret_vanzare=a.pret_vanzare;
        this->masini=new Masina[this->nr_masini];
        for(int i=0;i<a.nr_masini;i++)
            this->masini[i]=a.masini[i];
        return *this;
        
    }

    ~Magazin(){
        if(this->masini!=NULL)
        delete[]this->masini;
    }

    float getAdaos(){
        return this->adaos_comercial;
    }

    int getNrMasini(){
        return this->nr_masini;
    }

    float getPretVanzare(){
        return this->pret_vanzare;
    }

    Masina* getMasini(){
        return this->masini;
    }

    void setAdaos(float a){
        this->adaos_comercial=a;
    }

    void setNrMasini(int a){
        this->nr_masini=a;
    }

    void setPretVanzare(float a){
        this->pret_vanzare=a;
    }

    void setMasini(Masina *cars,int nr){
        delete[]this->masini;
        this->nr_masini=nr;
        this->masini=new Masina[this->nr_masini];
        for(int i=0;i<this->nr_masini;i++)
            this->masini[i]=cars[i];
    }

    Masina operator[](int i){
        if(i!=0)
            return this->masini[i];
      //  else
           // throw exception("Error: Index 0")
    }
;
    friend ostream & operator<<(ostream & out, Magazin & a){
        out<<a.adaos_comercial;
        out<<a.nr_masini;
        out<<a.pret_vanzare;
        for(int i=0;i<a.nr_masini;i++)
            out<<a.masini[i];
        return out;
    }

    friend istream & operator>>(istream & in, Magazin & a){
        in>>a.adaos_comercial;
        in>>a.nr_masini;
        in>>a.pret_vanzare;
        for(int i=0;i<a.nr_masini;i++)
            in>>a.masini[i];
        return in;
    }

    float ProfitTotal(){
        float total=0.0;
        for(int i=0;i<this->nr_masini;i++)
            total=total+masini[i].Profit(15.0);
        return total;
    }
    
};

//functie in care se introd de la tastatura obiect de tip magazin, salvare in fisier Txt 


int main(){
    string a="12345";
    Masina m1(a,460.0,550.0,true);
    Masina m2("54321",660.0,800.0,false);
    Masina m3=m2;
    Masina m4(m1);
    Masina cars[4]={m1,m2,m3,m4};
    Magazin mag1(3.4,cars,4,2600.0);
    cout<<mag1;
    cout<<endl<<m1.Profit(15.0);
    if(m1.Profit(15.0)>m2.Profit(15.0))
        cout<<"m1 este mai profitabil";
    else
        cout<<"m1 nu este mai profitabil";
    ++m1;
    cout<<endl<<m1<<endl;
    cout<<m1.afisareVIN()<<endl<<m1.calculTVA();
    cout<<endl<<mag1.ProfitTotal();
    //mag1.SalvareTXT("masini.txt",4);
}