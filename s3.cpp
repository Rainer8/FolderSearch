 #include <iostream>

 using namespace std;

class TVA{
    virtual void afisare_mesaj(){
        cout<<"Mesaj";
    }

    virtual float calculTVA()=0;
};

class Produs:public TVA{
    private:
    
    string den_produs;
    string cod_produs;
    float pret;
    float* preturi_catalog;
    int nr_preturi;
    
    public:

    float calculTVA(){
        return this->pret*0.19;
    }
    void afisare_mesaj(){
        cout<<"S-a apelat fs virtuala pt Produs";
    }
    Produs(){
        this->den_produs="Nume invalid";
        this->cod_produs="0000";
        this->pret=0.0;
        this->preturi_catalog=NULL;
        this->nr_preturi=0;
    }

    Produs(string den,string cod, float pt,float* preturi,int nr_pt){
        this->den_produs=den;
        this->cod_produs=cod;
        this->pret=pt;
        this->nr_preturi=nr_pt;
        this->preturi_catalog=new float[nr_pt];
        for(int i=0;i<nr_pt;i++)
            this->preturi_catalog[i]=preturi[i];
    }

    Produs(Produs &a){
        this->den_produs=a.den_produs;
        this->cod_produs=a.cod_produs;
        this->pret=a.pret;
        this->nr_preturi=a.nr_preturi;
        this->preturi_catalog=new float[a.nr_preturi];
        for(int i=0;i<a.nr_preturi;i++)
            this->preturi_catalog[i]=a.preturi_catalog[i];
    }

    Produs operator=(Produs &a){
        this->den_produs=a.den_produs;
        this->cod_produs=a.cod_produs;
        this->pret=a.pret;
        this->nr_preturi=a.nr_preturi;
        this->preturi_catalog=new float[a.nr_preturi];
        for(int i=0;i<a.nr_preturi;i++)
            this->preturi_catalog[i]=a.preturi_catalog[i];
        return *this;
    }

    friend ostream & operator<<(ostream & out,Produs &a){
        out<<endl<<"Produsul:"<<a.den_produs;
        out<<endl<<"Pret:"<<a.pret;
        return out;
    }
    friend istream & operator<<(istream & in,Produs &a){
        cout<<endl<<"Produsul:";
        in>>a.den_produs;
        in>>a.cod_produs;
        in>>a.pret;
        in>>a.nr_preturi;
        a.preturi_catalog=new float[a.nr_preturi];
        for(int i=0;i<a.nr_preturi;i++)
            in>>a.preturi_catalog[i];
        return in;
    }

    bool operator>(Produs &a)
    {
        if(this->pret>a.pret)
            return 1;
        else
            return 0;
    }

    bool operator<(Produs &a)
    {
        if(this->pret<a.pret)
            return 1;
        else
            return 0;
    }

    bool operator!(){
        if(this->pret>1000)
            return 1;
        else
            return 0;
    }

    Produs & operator++(){
        this->pret++;
        return *this;
    }

    float operator[](int i){
        cout<<this->preturi_catalog[i];
    }

    float operator+(float x){
        return this->pret+x;
    }
};

    class Aliment:public TVA{
        private:
        string tip;
        float pret_standard;
        public:

        float calculTVA(){
            return this->pret_standard*0.15;
        }

        void afisare_mesaj(){
            cout<<"S-a apelat fs virtuala pt Aliment";
        }
        Aliment()
        {
            this->tip="NULL";
            this->pret_standard=0.0;
        }

        Aliment(string tp,float pt){
            this->tip=tp;
            this->pret_standard=pt;
        }

        Aliment & operator=(Aliment &a){
            this->pret_standard=a.pret_standard;
            this->tip=a.tip;
        }

        friend ostream & operator<<(ostream & out,Aliment &a){
            out<<endl<<"Tip:"<<a.tip;
            out<<endl<<"Pret:"<<a.pret_standard;
            return out;
        }

        string getTip(){
            return this->tip;
        }

        float getPret(){
            return this->pret_standard;
        }
        

    };

    class Paine:public Aliment{
        private:
            string nume_paine;
            string furnizor_paine;
            float pret_vanzare;

        public:
        float calculTVA(){
            return this->pret_vanzare*0.9;
        }

        void afisare_mesaj(){
            cout<<"S-a apelat fs virt pt Paine";
        }

        Paine():Aliment(){
            this->nume_paine="Nu exista";
            this->furnizor_paine="Nu exista";
            this->pret_vanzare=0.0;
        }

        Paine(string nume,string furnizor,float pret,string tp, float pt):Aliment( tp, pt){
            this->nume_paine=nume;
            this->furnizor_paine=furnizor;
            this->pret_vanzare=pret;
        }

         friend ostream & operator<<(ostream & out,Paine &p){
            out<<endl<<"Nume paine:"<<p.nume_paine;
            out<<endl<<"Furnizor:"<<p.furnizor_paine;
            out<<endl<<"Pret:"<<p.pret_vanzare;
            out<<p.getPret()<<p.getTip();
            return out;
        }

       /* friend istream & operator>>(istream & in,Paine &p){
            cout<<endl;
            in>>"Nume paine:">>p.nume_paine;
            cout<<endl;
            in>>"Furnizor:">>p.furnizor_paine;
            cout<<endl;
            in>>"Pret:"<<p.pret_vanzare;
            out<<p.getPret()<<p.getTip();
            return out;
       */
    };


    class Centralizator{

    };

 int main()
 {
     float pt[3]={380.0,400.0,500.0};
     Produs p1("Anvelopa","0110",350.0,pt,3);
     float prt[3]={400.0,450.0,520.0};
     Produs p2("Janta","0220",380.0,prt,3);
     cout<<p1;

     Aliment a1("Ciocolata",20.0);
     Paine pn1("Franzela","Vel Pitar",5.0,"Paine",5.0);

     TVA **v=new TVA*[3];
     v[0]=&p1;
     v[1]=&a1;
     v[2]=&pn1;

 }


 //3 clase baza+abstract+derivat 
 //2 clase 1 baza + 1 care o contine pe prima (tip is a/ has a)