#include<iostream>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<cmath>
#include<graphics.h>
#include<winbgim.h>
//#include "Grfic.h"
#define infinit 9999999
#define minfinit -9999999
#define epsilon 0.01
#define multiplier 2

using namespace std;
double grad;
double impartire(double a,double b)
{
     if(fabs(a)>=infinit && fabs(b)>=infinit)
    {
        if(a<0 && fabs(a)>fabs(b))
        {
            grad++;
            return minfinit;
        }
        if(a>0 && fabs(a)>fabs(b))
        {
            grad++;
            return infinit;
        }
        if(fabs(a)<fabs(b))
        {
            grad++;
            return 0;
        }
        if(fabs(a)==fabs(b)) return 1;
    }
    if(a==infinit && b>=0 )
    {
        grad++;
        return infinit;
    }
    if(a==infinit && b<0)
    {
        grad++;
        return minfinit;
    }
    if(a==infinit || b==minfinit)
    {
        return 0;
    }
    if(a==infinit && b==infinit)
    {
        return 0;
    }

    if(a==minfinit || b==infinit)
    {
        return 0;
    }

    if(a==minfinit || b==minfinit)
    {
        return 0;
    }
    if(b==0 && a>0 )
    {
        grad--;
        return infinit;
    }
    if(b==0 && a<0)
    {
        grad--;
        return minfinit;
    }

    if((a/b)>=400) return infinit;
    if((a/b)<=-400) return minfinit;

    return a/b;
}
double adunare(double a,double b)
{
    if(a==infinit || b==infinit) return infinit;


    return a+b;
}
double scadere(double a, double b)
{
    if(a==infinit || b==infinit) return infinit;

    return a-b;
}
double inmultire(double a, double b)
{
    if(a==infinit && b==infinit)
    {
        grad+=2;
         return infinit;
    }
    if(a==infinit && b==minfinit)
    {
        grad+=2;
         return minfinit;
    }
    if(b==infinit && a==minfinit)
    {
        grad+=2;
        return minfinit;
    }
    if(b==minfinit && a==minfinit)
    {
        grad+=2;
        return infinit;
    }
    if(a==infinit && b!=0)
    {
        grad++;
        return infinit;
    }
    if(b==infinit && a!=0)
    {
        grad++;
        return infinit;
    }
    if((a==infinit || a==minfinit) && b==0) return 1;
    if((b==infinit || b==minfinit) && a==0) return 1;
    if(a==0 || b==0)
    {
        grad--;
        return 0;
    }

    return a*b;
}
double putere(double a, double b)
{
    if(a==0) return 0;
    if(a==1) return 1;
    if(b==0) return 1;
    if(a==0 && b==0) return 0;
    if(a==infinit || b==infinit) return infinit;
    if(a>0 && a<1 && b==infinit) return 0;
    if(a>0 && a<1 && b==minfinit) return infinit;
    if(a>0 && a>1 && b==infinit) return infinit;
    if(a>0 && a>1 && b==minfinit) return 0;

    return pow(a,b);
}
double logaritm(double a)
{
    if(a==0) return minfinit;
    if(a>=infinit) return infinit;

    return log(a);
}
double cosinus(double a)
{
    int A=a*pow(10,multiplier);
    int PI=3.14*pow(10,multiplier);
    if(A%(2*PI)==0) return 1;
    if(A%PI==0 && A%(2*PI)) return-1;
    return cos(a);
}
double sinus(double a)
{
    int A=a*100;
    int multiplu=628;
    if(A>=0)
    {
        while(A>471) A-=multiplu;
        if(A==157) return 1;
        if(A==0 || A==-314 || A==314) return 0;
        if(A==471) return -1;
    }
    if(A<0)
    {
        while(A<-471) A+=multiplu;
        if(A==(-157)) return -1;
        if(A==0 || A==-314 || A==314) return 0;
        if(A==(-471)) return 1;
    }
    return sin(a);
}
struct nod_1
{
    char info;
    nod_1 *urm;
};
struct operatori
{
    int lungime;
    nod_1 *prim;
};
struct nod_2
{
    double info;
    nod_2 *urm;
};
struct operanzi
{
    int lungime;
    nod_2 *prim;
};
void initializeaza_1(operatori &Op)
{
    Op.lungime=0;
    Op.prim=NULL;
}
void initializeaza_2(operanzi &Opd)
{
    Opd.lungime=0;
    Opd.prim=NULL;
}
char top_1(operatori Op)
{
    return Op.prim->info;
}

double top_2(operanzi Opd)
{
    return Opd.prim->info;
}
void push_1(operatori &Op,char valoare)
{

    //cout<<"se adauga in stiva Op operatorul "<<valoare<<endl;
    nod_1 *t=new nod_1;
    t->info=valoare;
    t->urm=Op.prim;
    Op.prim=t;
    Op.lungime++;

}
void push_2(operanzi &Opd,double valoare)
{
    //cout<<"se adauga in stiva Opd operandul "<<valoare<<endl;
    nod_2 *t=new nod_2;
    t->info=valoare;
    t->urm=Opd.prim;
    Opd.prim=t;
    Opd.lungime++;
}
void pop_1(operatori &Op)
{
    //cout<<"se scoate din stiva Op operatorul "<<Op.prim->info<<endl;
    nod_1 *t=new nod_1;
    t=Op.prim;
    Op.prim=Op.prim->urm;
    delete t;
    Op.lungime--;
}
void pop_2(operanzi &Opd)
{
    //cout<<"se scoate din stiva Opd operandul "<<Opd.prim->info<<endl;
    nod_2 *t=new nod_2;
    t=Opd.prim;
    Opd.prim=Opd.prim->urm;
    delete t;
    Opd.lungime--;
}
void afisare_1(operatori &Op)
{
    nod_1 *t=new nod_1;
    t=Op.prim;
    while(t)
    {
        cout<<t->info<<endl;
        t=t->urm;
    }
}
void afisare_2(operanzi &Opd)
{
    nod_2 *t=new nod_2;
    t=Opd.prim;
    while(t)
    {
        cout<<t->info<<endl;
        t=t->urm;
    }
}
int operatie(char o)
{
    switch(o)
    {
        case'+':{ return 1; } break;
        case'-':{ return 1; } break;
        case'*':{ return 1; } break;
        case'/':{ return 1; } break;
        case'^':{ return 1; } break;
        case'(':{ return 1; } break;
        case')':{ return 1; } break;
        case'a':{ return 1; } break;
        case'l':{ return 1; } break;
        case's':{ return 1; } break;
        case'c':{ return 1; } break;
        case'r':{ return 1; } break;
        case'#':{ return 1; } break;
        case'=':{ return 1; } break;
        case'<':{ return 1; } break;
        case'>':{ return 1; } break;
        default:{return 0;}
    }
}
int prioritate(char c)
{
    if(c=='(' || c==')') return 0;
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    if(c=='a' || c=='r' || c=='l' || c=='s' || c=='c')return 5;
    if(c=='#' || c=='=' || c=='<' || c=='>')return 4;
    return -1;
}
bool cifra(char c)
{
    return (c>='0'&& c<='9');
}
double valoare_cifra(char c)
{
  switch(c)
  {
        case'0':{ return 0; } break;
        case'1':{ return 1; } break;
        case'2':{ return 2; } break;
        case'3':{ return 3; } break;
        case'4':{ return 4; } break;
        case'5':{ return 5; } break;
        case'6':{ return 6; } break;
        case'7':{ return 7; } break;
        case'8':{ return 8; } break;
        case'9':{ return 9; } break;
  }
  return -1;
}
double limita()
{
    if(grad<0) return 0;
    if(grad==0) return 1;
    return infinit;
}
double functie(char f[100], double x)
{
    grad=0;
    operatori Op;
    initializeaza_1(Op);
    push_1(Op,'(');
    operanzi Opd;
    initializeaza_2(Opd);
    unsigned int i=0;
    while(Op.lungime && i<strlen(f)-1)
    {
        if(operatie(f[i]))
        {
            if(f[i]=='(') {push_1(Op,f[i]);/*cout<<"ramura 0"<<endl;*/}

            if(f[i]==')')
            {
                //cout<<"ramura 1"<<endl;
                nod_1 *t=new nod_1;
                t=Op.prim;
                while(t && t->info!='(')
                {
                    //cout<<t->info<<endl;

                    double a=top_2(Opd);
                    pop_2(Opd);

                    switch(t->info)
                        {
                        case'+':{ Opd.prim->info=adunare(Opd.prim->info,a);}break;
                        case'-':{ Opd.prim->info=scadere(Opd.prim->info,a);}break;
                        case'*':{ Opd.prim->info=inmultire(Opd.prim->info,a);}break;
                        case'/':{ Opd.prim->info=impartire(Opd.prim->info,a);}break;
                        case'^':{ Opd.prim->info=pow(Opd.prim->info,a);}break;
                        case'a':{ a=fabs(a);push_2(Opd,a);}break;
                        case'l':{ a=logaritm(a);push_2(Opd,a);}break;
                        case'r':{ a=sqrt(a);push_2(Opd,a);}break;
                        case's':{ a=sinus(a);push_2(Opd,a);}break;
                        case'c':{ a=cosinus(a);push_2(Opd,a);}break;
                        case'#':{ a=(Opd.prim->info!=a);Opd.prim->info=a;}break;
                        case'=':{ a=(Opd.prim->info==a);Opd.prim->info=a;}break;
                        case'>':{ a=(Opd.prim->info>a);Opd.prim->info=a;}break;
                        case'<':{ a=(Opd.prim->info<a);Opd.prim->info=a;}break;

                        }
                        pop_1(Op);

                   //cout<<"terminat switch"<<endl;

                    t=Op.prim;
                }
                pop_1(Op);
            }

            if(f[i]!='(' && f[i]!=')')
            {
                bool ok=1;
                if(prioritate(Op.prim->info)< prioritate(f[i]))
                    {
                    if(f[i]=='-'&& f[i-1]=='(')
                       ok=0;
                    if(ok==1)
                        push_1(Op,f[i]);
                    }

                else
                {       //cout<<"ramura 3"<<endl;
                    double a=top_2(Opd);
                    pop_2(Opd);

                    switch(Op.prim->info)
                    {
                        case'+':{ Opd.prim->info=adunare(Opd.prim->info,a);}break;
                        case'-':{ Opd.prim->info=scadere(Opd.prim->info,a);}break;
                        case'*':{ Opd.prim->info=inmultire(Opd.prim->info,a);}break;
                        case'/':{ Opd.prim->info=impartire(Opd.prim->info,a);}break;
                        case'^':{ Opd.prim->info=pow(Opd.prim->info,a);}break;
                        case'a':{ a=fabs(a);push_2(Opd,a);}break;
                        case'l':{ a=logaritm(a);push_2(Opd,a);}break;
                        case'r':{ a=sqrt(a);push_2(Opd,a);}break;
                        case's':{ a=sinus(a);push_2(Opd,a);}break;
                        case'c':{ a=cosinus(a);push_2(Opd,a);}break;
                        case'#':{ a=(Opd.prim->info!=a);Opd.prim->info=a;}break;
                        case'=':{ a=(Opd.prim->info==a);Opd.prim->info=a;}break;
                        case'>':{ a=(Opd.prim->info>a);Opd.prim->info=a;}break;
                        case'<':{ a=(Opd.prim->info<a);Opd.prim->info=a;}break;

                    }
                    pop_1(Op);
                    push_1(Op,f[i]);
                    //cout<<"op.lungime="<<Op.lungime<<endl;
                }
            }
        }
        else
        {
           if(f[i]=='x') push_2(Opd,x);
           if(f[i]=='e') push_2(Opd,2.718);
           if(f[i]=='p') push_2(Opd,3.14);
           if(cifra(f[i]))
           {
               bool ok=1;
               if(i>1 && f[i-1]=='-' && f[i-2]=='(')
                    ok=0;
               unsigned int j=i,contor_pozitie=-1,k;
               double a=0,b;
               while((cifra(f[j])||f[j]=='.')&& j<strlen(f))
               {
                   if(cifra(f[j])) a=a*10+valoare_cifra(f[j]);
                   else {j++;
                         k=0;
                         b=0;
                         contor_pozitie++;
                         while(cifra(f[j]))
                         {
                            b=b*10+valoare_cifra(f[j]);
                            k++;
                            j++;
                            contor_pozitie++;
                         }
                         b=b/pow(10,k);
                         a=a+b;
                         j--;
                         contor_pozitie--;
                        }
                   j++;
                   contor_pozitie++;
               }
               if(ok)
                    push_2(Opd,a);
                else
                {
                    a=0-a;
                    push_2(Opd,a);
                }
               i+=contor_pozitie;
           }
        }
        i++;
    }
    if(Op.lungime)
    {
        //cout<<"ramura 2"<<endl;
        if(Op.lungime==1 && Op.prim->info=='(')
            pop_1(Op);
        else
        {
            nod_1 *t=new nod_1;
            t=Op.prim;
            while(t && t->info!='(')
            {
                //cout<<t->info<<endl;
                double a=top_2(Opd);
                pop_2(Opd);
                switch(t->info)
                    {
                    case'+':{ Opd.prim->info+=a;}break;
                    case'-':{ Opd.prim->info-=a;}break;
                    case'*':{ Opd.prim->info*=a;}break;
                    case'/':{ Opd.prim->info=impartire(Opd.prim->info,a);}break;
                    case'^':{ Opd.prim->info=pow(Opd.prim->info,a);}break;
                    case'a':{ a=fabs(a);push_2(Opd,a);}break;
                    case'l':{ a=logaritm(a);push_2(Opd,a);}break;
                    case'r':{ a=sqrt(a);push_2(Opd,a);}break;
                    case's':{ a=sinus(a);push_2(Opd,a);}break;
                    case'c':{ a=cosinus(a);push_2(Opd,a);}break;
                    case'#':{ a=(Opd.prim->info!=a);push_2(Opd,a);}break;
                    case'=':{ a=(Opd.prim->info==a);push_2(Opd,a);}break;
                    case'>':{ a=(Opd.prim->info>a);push_2(Opd,a);}break;
                    case'<':{ a=(Opd.prim->info<a);push_2(Opd,a);}break;
                    }
                pop_1(Op);
                //cout<<"terminat switch"<<endl;
                t=Op.prim;
            }
            pop_1(Op);
        }
    }
    return top_2(Opd);//inmultire(top_2(Opd),limita());
}
double minim(char f[100],double a,double b)
{
        double miny=functie(f,a);
        for(double i=a;i<=b;i+=epsilon)
        {
            if(functie(f,i)<miny)
            {
                miny=functie(f,i);
            }
        }
        return miny;
}
double maxim(char f[100],double a,double b)
{
        double maxy=functie(f,a);
        for(double i=a;i<=b;i+=epsilon)
        {
            if(functie(f,i)>maxy)
            {
                maxy=functie(f,i);
            }
        }
        return maxy;
}
bool functie_putere(char f[100])
{
    int nr_paranteze=0;
    if(f[0]=='x' && f[1]=='^')
    {
        for(unsigned int i=2;i<strlen(f)-1 && f[i]=='(';i++) nr_paranteze++;
        if(int(valoare_cifra(f[strlen(f)-nr_paranteze-2]))%2==0) return 1;
        return 0;
    }
    return 0;
}
bool butonInversa (int x, int y)
{
    if(x>=750 && x<=800 && y>=750 && y<=800)
        return 1;
    return 0;
}
bool butonPuncteExtreme (int x, int y)
{
    if(x>=700 && x<=750 && y>=750 && y<=800)
        return 1;
    return 0;
}
bool butonMinus (int x, int y)
{
    if(x>=0 && x<=50 && y>=750 && y<=800)
        return 1;
    return 0;
}
bool butonPlus (int x, int y)
{
    if(x>=50 && x<=100 && y>=750 && y<=800)
        return 1;
    return 0;
}
bool butonAsimptotaVerticala (int x, int y)
{
    if(x>=650 && x<=700 && y>=0 && y<=50)
        return 1;
    return 0;
}
bool butonAsimptotaOrizontala (int x, int y)
{
    if(x>=700 && x<=750 && y>=0 && y<=50)
        return 1;
    return 0;
}
bool butonAsimptotaOblica (int x, int y)
{
    if(x>=750 && x<=800 && y>=0 && y<=50)
        return 1;
    return 0;
}
bool butonClen (int x, int y)
{
    if(x>=100 && x<=179 && y>=750 && y<=800)
        return 1;
    return 0;
}
bool butonBack (int x, int y)
{
    if(x>=0 && x<=50 && y>=0 && y<=50)
        return 1;
    return 0;
}
bool butonStart(int x, int y)
{
    if(x>=250 && x<=550 && y>=150 && y<=275)
        return 1;
    return 0;
}
bool butonInformatii(int x, int y)
{
    if(x>=250 && x<=550 && y>=400 && y<=550)
        return 1;
    return 0;
}
bool butonDespreNoi(int x, int y)
{
    if(x>=250 && x<=550 && y>=650 && y<=775)
        return 1;
    return 0;
}
bool butonFunctie (int x,int y)
{
    if(x>=0 && x<=800 && y>=400 && y<=550)
        return 1;
    return 0;
}
bool injectivitate(char f[100], double a, double b)
{
    double i,j;

    if(functie_putere(f) && a>=0) return 1;
    if(functie_putere(f) && a<0) return 0;

    if(strcmp(f,"sx)")==0 && b-a<=3.14) return 1;
    if(strcmp(f,"sx)")==0 && b-a>3.14) return 0;

    if(strcmp(f,"sx/cx)")==0 && b-a<=3.14) return 1;
    if(strcmp(f,"sx/cx)")==0 && b-a>3.14) return 0;

    if(strcmp(f,"cx/sx)")==0 && b-a<=3.14) return 1;
    if(strcmp(f,"cx/sx)")==0 && b-a>3.14) return 0;

    for(i=a;i<b;i++)
    {
        for(j=i+1;j<=b;j++)
        {
            if(functie(f,i)==functie(f,j))
            {
                cout<<i<<' '<<functie(f,i)<<endl;
                cout<<j<<' '<<functie(f,j)<<endl;
                return 0;
            }
        }
    }
    return 1;
}
int nr_paranteze(char f[100])
{
    int nr_d=0,nr_i=0;

    for(unsigned int i=0;i<strlen(f);i++)
    {
        if(f[i]==')') nr_i++;
        if(f[i]=='(') nr_d++;
    }

    return (nr_i==(nr_d+1));
}
bool caractere(char f[100])
{
    for(unsigned int i=0;i<strlen(f);i++)
    {
       if(operatie(f[i])==0 && cifra(f[i])==0 && f[i]!='x' && f[i]!='e' && f[i]!='.') return 0;
    }

    return 1;
}
int operatori(char f[100])
{
    for(unsigned int i=0;i<strlen(f)-1;i++)
    {
        if(operatie(f[i]) && f[i]!='-')
        {
            if(prioritate(f[i])>0 && prioritate(f[i])<5)
            {
                if( prioritate(f[i-1])>0 || (cifra(f[i-1])==0 && f[i-1]!='x' && f[i-1]=='e') )
                {
                    if(prioritate(f[i-1])>0)
                    {
                        return 0;
                    }
                    if(cifra(f[i-1])==0 && f[i-1]!='x' && f[i-1]!='e')
                    {
                        return 0;
                    }
                }
                if((prioritate(f[i+1])!=0 || prioritate(f[i+1])!=5)|| (cifra(f[i+1])==0 && f[i+1]!='x' && f[i+1]=='e'))
                {
                    if(prioritate(f[i+1])>0 && prioritate(f[i+1])<5)
                    {
                        return 0;
                    }
                    if(prioritate(f[i+1])!=0 && prioritate(f[i+1])!=5 && cifra(f[i+1])==0 && f[i+1]!='x'&& f[i+1]!='e' && prioritate(f[i+1])!=5)
                    {
                        return 0;
                    }
                }
            }
            if(prioritate(f[i])==5)
            {
                if(f[i+1]!='(' && cifra(f[i+1])==0 && f[i+1]!='x'&& f[i+1]!='e') return 0;
            }
            if(prioritate(f[i])==0)
            {
                if(f[i]==')' && i==0) return 0;
                if(f[i]==')' && (cifra(f[i+1])||f[i+1]=='x'||f[i+1]=='e')) return 0;
                if(f[i]=='(' && i!=0 &&!(cifra(f[i+1])||f[i+1]=='x'||f[i+1]=='e') && prioritate(f[i+1])<5 ) return 0;
            }
        }
        if(f[i]=='-')
        {
            if( i==0 && cifra(f[1])==0 && f[1]!='(' && f[1]!='x') return 0;
            if(prioritate(f[i-1])>0 && prioritate(f[i-1])<5 && cifra(f[i-1])==0 && f[i-1]!='x') return 0;
            if(prioritate(f[i+1])>0 && prioritate(f[i+1])<5 && cifra(f[i+1])==0 && f[i+1]!='x') return 0;
        }
        if(f[i]=='.' && (cifra(f[i+1])==0 && f[i+1]!='x') && (cifra(f[i-1])==0 && f[i-1]!='x')) return 0;
    }
    return 1;
}
bool corectitudine(char f[100])
{
    return operatori(f)&&nr_paranteze(f)&&caractere(f) ;
}
void CitesteSir(int x, int y, char mesaj[100], char S[100] )
{
    char Enter = 13;
    char BackSpace = 8;
    char Escape = 27;
    char s2[2];
    s2[1]='\0';
    char MultimeDeCaractereAcceptabile[200]="ABCDEFGHIJKLMNOPQRTSUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz~!`@#$%+-^&*/\\()_=[],;.?<>:;{} ";
    char S_initial[100];
    char tasta;
    char S_[100];
    char mesaj_[100];
    strcpy(mesaj_,mesaj);
    strcpy(S_initial,S);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(GREEN);
    //settextjustify(0,0);
    outtextxy(x,y,mesaj_);
    x=x+textwidth(mesaj);
    strcpy(S,"");
    strcpy(S_,S);
    strcat(S_,"_");
    setcolor(RED);
    outtextxy(x,y,S_);
    s2[0]=tasta; strcat(S,s2);
    strcpy(S_,S);
    strcat(S_,"_");
    setcolor(WHITE);
    outtextxy(x,y,S_);
    int i=0;
    int j=0;
    do {
        tasta=getch();
        if (tasta==0) { tasta=getch(); Beep(1000,500); }
        else
            if (strchr(MultimeDeCaractereAcceptabile, tasta))
            {
                // stergem fostul sir
                //cout<<"i="<<i<<endl;
                strcpy(S_,S); strcat(S_,"_");
                setcolor(BLACK); outtextxy(x,y,S_);
                s2[0]=tasta; strcat(S,s2); strcpy(S_,S); strcat(S_,"_");
                setcolor(WHITE); outtextxy(x,y,S_);
                i++;
            }
            if (tasta==BackSpace)
                    if (!(strcmp(S,""))) Beep(500,100);
                    else
                    {
                        //cout<<"j="<<j<<endl;
                        setcolor(BLACK); outtextxy(x,y,S_); setcolor(WHITE);///
                        S[strlen(S)-1]='\0'; strcpy(S_,S); strcat(S_,"_") ;
                        outtextxy(x,y,S_); Beep(200,20);
                        j++;
                    }
            else
                if (tasta!=Enter && tasta!=Escape) {Beep(200,20); }
    }
    while (tasta!=Enter && tasta!=Escape);
    if (tasta == Escape)
        strcpy(S,S_initial);
    setcolor(RED);
    outtextxy(x,y,S_);
    setcolor(BLACK);
    outtextxy(x,y,S);
}
void interfataGrafica()
{
    settextstyle(4,0,4);
    for(int l=0;l<=800;l++)
    {
        setcolor (8);
        line(0,l,800,l);
    }
    int midX = 800/2;
    int midY = 800/8;
    setcolor(10);
    int width = textwidth("Graficul functiei");
    int height = textheight("Graficul functiei");
    outtextxy(midX - width/2, midY - height/2, "Graficul functiei");
    int l;
    ///bar(250,150,550,275); Buton 1 "Start"
    setcolor(GREEN);
    rectangle(249,149,551,276);
    setcolor(BLACK);
    for(l=250;l<=550;l++)
    {
        line(l,150,l,275);
    }
    ///bar(250,400,550,525); Buton 2 "informatii"
    setcolor(GREEN);
    rectangle(249,399,551,526);
    setcolor(BLACK);
    for(l=250;l<=550;l++)
    {
        line(l,400,l,525);
    }
    ///bar(250,650,550,775); Buton 3 "despre noi"
    setcolor(GREEN);
    rectangle(249,649,551,776);
    setcolor(BLACK);
    for(l=250;l<=550;l++)
    {
        line(l,650,l,775);
    }
    setcolor(10);
    width = textwidth("Start");
    height = textheight("Start");
    outtextxy(400-width/2 , 213-height , "Start");

    width = textwidth("Informatii");
    height = textheight("Informatii");
    outtextxy(400 - width/2, 468 - height, "Informatii");

    width = textwidth("Credite");
    height = textheight("Credite");
    outtextxy(400 - width/2, 720 - height, "Credite");

    POINT cursorPosition;
    int mX,mY;
    cout<< "butoanele apasate: ";
         while (1)
        {
            GetCursorPos(&cursorPosition);
            mX = cursorPosition.x;
            mY = cursorPosition.y;
            if(ismouseclick(WM_MOUSEMOVE))
            {
                if(butonStart(mX,mY))
                {
                    setcolor(RED);
                    rectangle(249,149,551,276);
                    setcolor(RED);
                    width = textwidth("Start");
                    height = textheight("Start");
                    outtextxy(midX - width/2, 213 - height, "Start");
                }
                else
                {
                    setcolor(GREEN);
                    rectangle(249,149,551,276);
                    setcolor(GREEN);
                    width = textwidth("Start");
                    height = textheight("Start");
                    outtextxy(midX - width/2, 213 - height, "Start");
                }
                if(butonInformatii(mX,mY))
                {
                    setcolor(RED);
                    rectangle(249,399,551,526);
                    width = textwidth("Informatii");
                    height = textheight("Informatii");
                    outtextxy(midX - width/2, 468 - height, "Informatii");
                }
                else
                {
                    setcolor(GREEN);
                    rectangle(249,399,551,526);
                    width = textwidth("Informatii");
                    height = textheight("Informatii");
                    outtextxy(midX - width/2, 468 - height, "Informatii");
                }
                if(butonDespreNoi(mX,mY))
                {
                    setcolor(RED);
                    rectangle(249,649,551,776);
                    width = textwidth("Credite");
                    height = textheight("Credite");
                    outtextxy(midX - width/2, 720 - height, "Credite");
                }
                else
                {
                    setcolor(GREEN);
                    rectangle(249,649,551,776);
                    width = textwidth("Credite");
                    height = textheight("Credite");
                    outtextxy(midX - width/2, 720 - height, "Credite");
                }
            }
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                    if(butonStart(mX,mY))
                    {
                            cout<<"1"<<endl;
                            ///functia
                            for(int l=0;l<=800;l++)
                            {
                                setcolor (BLACK);
                                line(0,l,800,l);
                            }

                            width = textwidth("Apasati aici pentru a introduce functia");
                            height = textheight("Apasati aici pentru a introduce functia");

                            //outtextxy(midX - width/2, 468 - height, "Apasati aici pentru a introduce functia");
                             //initwindow(800,800,"Citire sir de caractere in mod grafic");
                            char f[100]="";
                            char mesaj[100];
                            strcpy(mesaj,"Introduceti functia: f(x)=");
                            CitesteSir(3,100,mesaj,f);
                            for(int l=0;l<=800;l++)
                            {
                                setcolor (BLACK);
                                line(0,l,800,l);
                            }
                            if(!strcmp(f,"sauron"))
                            {
                                //initwindow(800,800,"Easter-egg number 1: The eye of Sauron");
                                bar(0,0,50,50);
                                setcolor(RED);
                                for(int l=0;l<=50;l++)
                                    line(l,0,l,50);
                                setcolor (GREEN);
                                line(10,25,40,25);
                                line(10,25,15,15);
                                line(10,25,15,35);
                                rectangle(0,0,51,51);
                                setcolor(4);
                                int i;
                                for(i=400;i>=10;i--)
                                {
                                    ellipse(400,400,0,180,i,400);
                                    ellipse(400,400,180,360,i,400);
                                }
                                setcolor(14);
                                for(i=100;i>=10;i--)
                                {
                                    ellipse(400,400,0,180,i,400);
                                    ellipse(400,400,180,360,i,400);
                                }
                                int mX,mY;
                                while (1)
                                {
                                    getmouseclick(WM_LBUTTONDOWN, mX, mY);
                                    if(butonBack(mX,mY))
                                    {
                                        interfataGrafica();
                                        break;
                                    }
                               }
                            }
                            else
                                if(!(strcmp(f,"sus")))
                                {
                                    bar(0,0,50,50);
                                    setcolor(RED);
                                    for(int l=0;l<=50;l++)
                                        line(l,0,l,50);
                                    setcolor (GREEN);
                                    line(10,25,40,25);
                                    line(10,25,15,15);
                                    line(10,25,15,35);
                                    rectangle(0,0,51,51);
                                    int i=0;
                                    //initwindow(800,800,"Easter-egg number 2: Among us crewmate");
                                    setcolor(4);
                                    while(i<200)
                                    {
                                        line(200,450-i,400,450-i);
                                        i++;
                                    }
                                    i=0;
                                    while(i<200)
                                    {
                                        line(200,350+i,250,350+i);
                                        line(350,350+i,400,350+i);
                                        i++;
                                    }
                                    i=0;
                                    while(i<200)
                                    {
                                        line(100,450-i,175,450-i);
                                        i++;
                                    }
                                    i=0;
                                    while(i<100)
                                    {
                                        line(200,250-i,400,250-i);
                                        i++;
                                    }
                                    i=0;
                                    while(i<75)
                                    {
                                        setcolor(1);
                                        line(275,250-i,420,250-i);
                                        i++;

                                    }
                                    int mX,mY;
                                    while (1)
                                    {
                                        getmouseclick(WM_LBUTTONDOWN, mX, mY);
                                        if(butonBack(mX,mY))
                                        {
                                            interfataGrafica();
                                            break;
                                        }
                                    }
                                }
                            else
                                if(!stricmp(f,"nota1") || !stricmp(f,"nota2")|| !stricmp(f,"nota3") || !stricmp(f,"nota4")|| !stricmp(f,"nota5")||!stricmp(f,"nota6")||!stricmp(f,"nota7")||!stricmp(f,"nota8")||!stricmp(f,"nota9"))
                                {
                                        //initwindow(1500,1500,"NASPA");
                                        readimagefile("IONIE.jpg",230,90,800,800);
                                        setcolor(RED);
                                        for(int l=0;l<=50;l++)    line(l,0,l,50);
                                        setcolor (GREEN);
                                        line(10,25,40,25);
                                        line(10,25,15,15);
                                        line(10,25,15,35);
                                        rectangle(0,0,51,51);
                                        while (1)
                                        {
                                            getmouseclick(WM_LBUTTONDOWN, mX, mY);
                                            if(butonBack(mX,mY))
                                            {
                                                interfataGrafica();
                                                break;
                                            }
                                        }
                                }
                            else
                                if(!stricmp(f,"nota10"))
                                {
                                    //initwindow(1500,1500,"BUN BOSS");
                                    readimagefile("ROCK.gif",0,0,800,800);
                                }
                            else
                            {
                                strcat(f,")");
                                if(corectitudine(f))
                                {
                                    double a,b,my,My;
                                    //cout<<"a=";cin>>a;cout<<endl;
                                    //cout<<"b=";cin>>b;cout<<endl;
                                    char A[100];
                                    char B[100];
                                    char mesaj[100];
                                    strcpy(mesaj,"a=");
                                    CitesteSir(3,100,mesaj,A);
                                    cleardevice();
                                    a=atoi(A);
                                    cout<<a<<endl;
                                    strcpy(mesaj,"b=");
                                    CitesteSir(3,100,mesaj,B);
                                    b=atoi(B);
                                    cleardevice();

                                    setcolor(2);
                                    line(0,400,400,400);
                                    line(400,800,400,400);
                                    line(400,400,400,0);
                                    line(400,400,800,400);
                                    setcolor(4);
                                    my=minim(f,a,b);
                                    My=maxim(f,a,b);
                                    double m,n;
                                    int oblica;
                                    double i=a;
                                    double j;
                                    double J=0;
                                    double zoom=1.5;
                                    char scala[100];
                                    setcolor(WHITE);
                                    J=0;
                                    j=400;//-pow(10,zoom);
                                    while(j>0)
                                    {
                                        line(j,398,j,403);
                                        strcpy(scala,itoa(J,scala,10));
                                        settextstyle(0,0,1);
                                        outtextxy(j,405,scala);
                                        j-=pow(10,zoom);
                                       J--;
                                    }
                                    j=400+pow(10,zoom);
                                    J=1;
                                    while(j<=800)
                                    {
                                        line(j,398,j,403);
                                        strcpy(scala,itoa(J,scala,10));
                                        settextstyle(0,0,1);
                                        outtextxy(j+1,405,scala);
                                        j+=pow(10,zoom);
                                        J++;
                                    }
                                    J=1;
                                    j=400-pow(10,zoom);
                                    while(j>=0)
                                    {
                                        line(398,j,403,j);
                                        strcpy(scala,itoa(J,scala,10));
                                        settextstyle(0,0,1);
                                        outtextxy(405,j+1,scala);
                                        j-=pow(10,zoom);
                                        J++;
                                    }
                                    J=-1;
                                    j=400+pow(10,zoom);
                                    while(j<=800)
                                    {
                                        line(398,j,403,j);
                                        strcpy(scala,itoa(J,scala,10));
                                        settextstyle(0,0,1);
                                        outtextxy(405,j+1,scala);
                                        j+=pow(10,zoom);
                                        J--;
                                    }
                                    while(i<b)
                                    {
                                        setcolor(4);
                                        if((functie(f,i)<200 && functie(f,i)>-200)&&(functie(f,i+epsilon)<200 && functie(f,i+epsilon)>-200))
                                        {
                                            line(400+pow(10,zoom)*i,400-pow(10,zoom)*functie(f,i),400+pow(10,zoom)*(i+epsilon),400-pow(10,zoom)*functie(f,i+epsilon));
                                        }

                                        i+=epsilon;
                                    }
                                    double inversa=injectivitate(f,a,b);
                                    i=a;
                                    cout<<"pentru functia inversa apasati i"<<endl;
                                    cout<<"pentru asimptotele verticale apasati v"<<endl;
                                    cout<<"pentru asimptotele orizontale apasati ob"<<endl;
                                    cout<<"pentru lupa apasati +/-"<<endl;
                                    cout<<"pentru punctele de extrem apasati m"<<endl;
                                    bar(0,0,50,50);
                                    setcolor(RED);
                                    for(int l=0;l<=50;l++)
                                        line(l,0,l,50);
                                    setcolor(BLACK);
                                    for(int l=650;l<=800;l++)
                                        line(l,0,l,50);
                                    for(int l=0;l<=179;l++)
                                        line(l,750,l,800);
                                    for(int l=700;l<=800;l++)
                                        line(l,750,l,800);
                                    setcolor (GREEN);
                                    line(10,25,40,25);
                                    line(10,25,15,15);
                                    line(10,25,15,35);
                                    rectangle(0,0,51,51);
                                    setcolor(GREEN);
                                    rectangle(1,750,100,798);
                                    rectangle(700,750,799,798);
                                    rectangle(650,1,799,50);
                                    rectangle(100,750,179,798);
                                    line(50,750,50,800);
                                    line(750,750,750,800);
                                    line(700,1,700,50);
                                    line(750,1,750,50);
                                    setcolor(RED);
                                    settextstyle(4,0,1);
                                    outtextxy(772,766, "i");
                                    outtextxy(703,767, "Pct");
                                    outtextxy(21,765, "-");
                                    outtextxy(68,765, "+");
                                    outtextxy(102,765,"Clean");
                                    outtextxy(667,20, "V");
                                    outtextxy(710,21, "Or");
                                    outtextxy(756,21, "Ob");
                                    while(1)
                                    {
                                        getmouseclick(WM_LBUTTONDOWN, mX, mY);
                                        if(butonBack(mX,mY))
                                        {
                                            interfataGrafica();
                                            break;
                                        }
                                        if(butonInversa(mX,mY))
                                        {
                                        //cout<<injectivitate(f,A,b)<<endl;
                                        if(inversa)
                                        {
                                                 while(i<=b)
                                                {
                                                    setcolor(LIGHTRED);
                                                    line(400+pow(10,zoom)*functie(f,i),400-pow(10,zoom)*i,400+pow(10,zoom)*functie(f,i+epsilon),400-pow(10,zoom)*(i+epsilon));
                                                    i+=epsilon;
                                                }
                                        }

                                        else cout<<"f nu este injectiva"<<endl;
                                    }
                                    if(butonAsimptotaVerticala(mX,mY))
                                    {
                                        i=a;
                                        if(My>=infinit || my<=-infinit)
                                        {
                                            setcolor(10);
                                            if(my<=-infinit)
                                            {
                                                while(i<=b)
                                                {
                                                    if(functie(f,i)<=-infinit) line(400+pow(10,zoom)*i,0,400+i*pow(10,zoom),800);

                                                    i+=0.0001;
                                                }
                                                setcolor(RED);
                                                for(int l=0;l<=50;l++)
                                                    line(l,0,l,50);
                                                setcolor(BLACK);
                                                for(int l=650;l<=800;l++)
                                                    line(l,0,l,50);
                                                for(int l=0;l<=179;l++)
                                                    line(l,750,l,800);
                                                for(int l=700;l<=800;l++)
                                                    line(l,750,l,800);
                                                setcolor (GREEN);
                                                line(10,25,40,25);
                                                line(10,25,15,15);
                                                line(10,25,15,35);
                                                rectangle(0,0,51,51);
                                                setcolor(GREEN);
                                                rectangle(1,750,100,798);
                                                rectangle(700,750,799,798);
                                                rectangle(650,1,799,50);
                                                rectangle(100,750,179,798);
                                                line(50,750,50,800);
                                                line(750,750,750,800);
                                                line(700,1,700,50);
                                                line(750,1,750,50);
                                                setcolor(RED);
                                                settextstyle(4,0,1);
                                                outtextxy(772,766, "i");
                                                outtextxy(703,767, "Pct");
                                                outtextxy(21,765, "-");
                                                outtextxy(68,765, "+");
                                                outtextxy(102,765,"Clean");
                                                outtextxy(667,20, "V");
                                                outtextxy(710,21, "Or");
                                                outtextxy(756,21, "Ob");
                                                cout<<" asimptota spre -infinit "<<endl;
                                            }
                                            if(My>=infinit)
                                            {
                                                while(i<=b)
                                                {
                                                    if(functie(f,i)>=infinit) line(400+pow(10,zoom)*i,0,400+pow(10,zoom)*i,800);

                                                    i+=0.0001;
                                                }
                                                setcolor(RED);
                                                for(int l=0;l<=50;l++)
                                                    line(l,0,l,50);
                                                setcolor(BLACK);
                                                for(int l=650;l<=800;l++)
                                                    line(l,0,l,50);
                                                for(int l=0;l<=179;l++)
                                                    line(l,750,l,800);
                                                for(int l=700;l<=800;l++)
                                                    line(l,750,l,800);
                                                setcolor (GREEN);
                                                line(10,25,40,25);
                                                line(10,25,15,15);
                                                line(10,25,15,35);
                                                rectangle(0,0,51,51);
                                                setcolor(GREEN);
                                                rectangle(1,750,100,798);
                                                rectangle(700,750,799,798);
                                                rectangle(650,1,799,50);
                                                rectangle(100,750,179,798);
                                                line(50,750,50,800);
                                                line(750,750,750,800);
                                                line(700,1,700,50);
                                                line(750,1,750,50);
                                                setcolor(RED);
                                                settextstyle(4,0,1);
                                                outtextxy(772,766, "i");
                                                outtextxy(703,767, "Pct");
                                                outtextxy(21,765, "-");
                                                outtextxy(68,765, "+");
                                                outtextxy(102,765,"Clean");
                                                outtextxy(667,20, "V");
                                                outtextxy(710,21, "Or");
                                                outtextxy(756,21, "Ob");
                                                cout<<"asimptota spre infinit"<<endl;
                                            }
                                        }
                                        else cout<<"f nu are asimptote verticale"<<endl;
                                    }
                                    if(butonAsimptotaOrizontala(mX,mY))
                                    {
                                        oblica=1;
                                        if(strcmp(f,"sx)")&&strcmp(f,"cx)")&& strcmp(f,"sx/cx)")&& strcmp(f,"cx/sx)") &&(My!=my))
                                        {
                                            if(functie(f,infinit)<infinit && functie(f,infinit)>minfinit)
                                            {
                                                oblica=0;
                                                cout<<"f are asiptota orizontala spre infinit"<<endl;
                                                setcolor(LIGHTMAGENTA);
                                                line(0,400-pow(10,zoom)*functie(f,infinit),800,400-pow(10,zoom)*functie(f,infinit));
                                                setcolor(RED);
                                                for(int l=0;l<=50;l++)
                                                    line(l,0,l,50);
                                                setcolor(BLACK);
                                                for(int l=650;l<=800;l++)
                                                    line(l,0,l,50);
                                                for(int l=0;l<=179;l++)
                                                    line(l,750,l,800);
                                                for(int l=700;l<=800;l++)
                                                    line(l,750,l,800);
                                                setcolor (GREEN);
                                                line(10,25,40,25);
                                                line(10,25,15,15);
                                                line(10,25,15,35);
                                                rectangle(0,0,51,51);
                                                setcolor(GREEN);
                                                rectangle(1,750,100,798);
                                                rectangle(700,750,799,798);
                                                rectangle(650,1,799,50);
                                                rectangle(100,750,179,798);
                                                line(50,750,50,800);
                                                line(750,750,750,800);
                                                line(700,1,700,50);
                                                line(750,1,750,50);
                                                setcolor(RED);
                                                settextstyle(4,0,1);
                                                outtextxy(772,766, "i");
                                                outtextxy(703,767, "Pct");
                                                outtextxy(21,765, "-");
                                                outtextxy(68,765, "+");
                                                outtextxy(102,765,"Clean");
                                                outtextxy(667,20, "V");
                                                outtextxy(710,21, "Or");
                                                outtextxy(756,21, "Ob");
                                            }
                                            if(functie(f,minfinit)<infinit && functie(f,minfinit)>minfinit)
                                            {
                                                oblica=0;
                                                cout<<"f are asimptota orizontala spre -infinit"<<endl;
                                                setcolor(LIGHTMAGENTA);
                                                line(0,400-pow(10,zoom)*functie(f,minfinit),800,400-pow(10,zoom)*functie(f,minfinit));
                                                setcolor(RED);
                                                for(int l=0;l<=50;l++)
                                                    line(l,0,l,50);
                                                setcolor(BLACK);
                                                for(int l=650;l<=800;l++)
                                                    line(l,0,l,50);
                                                for(int l=0;l<=179;l++)
                                                    line(l,750,l,800);
                                                for(int l=700;l<=800;l++)
                                                    line(l,750,l,800);
                                                setcolor (GREEN);
                                                line(10,25,40,25);
                                                line(10,25,15,15);
                                                line(10,25,15,35);
                                                rectangle(0,0,51,51);
                                                setcolor(GREEN);
                                                rectangle(1,750,100,798);
                                                rectangle(700,750,799,798);
                                                rectangle(650,1,799,50);
                                                rectangle(100,750,179,798);
                                                line(50,750,50,800);
                                                line(750,750,750,800);
                                                line(700,1,700,50);
                                                line(750,1,750,50);
                                                setcolor(RED);
                                                settextstyle(4,0,1);
                                                outtextxy(772,766, "i");
                                                outtextxy(703,767, "Pct");
                                                outtextxy(21,765, "-");
                                                outtextxy(68,765, "+");
                                                outtextxy(102,765,"Clean");
                                                outtextxy(667,20, "V");
                                                outtextxy(710,21, "Or");
                                                outtextxy(756,21, "Ob");
                                            }

                                            else cout<<"f nu are asiptota orizontala"<<endl;
                                        }

                                        else cout<<"f nu are asimptota orizontala"<<endl;
                                    }
                                        if(butonAsimptotaOblica(mX,mY))
                                        {
                                                if(strcmp(f,"sx)") && strcmp(f,"cx)") &&strcmp(f,"sx/cx)") && strcmp(f,"cx/sx)")&& strcmp(f,"x)"))
                                                {
                                                    if(functie(f,infinit)==infinit || functie(f,infinit)==-infinit)
                                                    {
                                                        m=functie(f,infinit);///
                                                        m=impartire(m,infinit);///
                                                        cout<<"m="<<m<<endl;
                                                        n=functie(f,minfinit)-m*minfinit;
                                                        cout<<"n="<<n<<endl;
                                                        if(m!=infinit && m!=minfinit && n!=infinit && n!=minfinit)
                                                        {
                                                            cout<<"f are asimptota oblica spre infinit dreapte de ecutie y="<<m<<"x+"<<n<<endl;
                                                            setcolor(LIGHTBLUE);
                                                            line(400,400-pow(10,zoom)*(n),400+pow(10,zoom)*2*b,400-pow(10,zoom)*(m*2*b+n));
                                                            setcolor(RED);
                                                            for(int l=0;l<=50;l++)
                                                                line(l,0,l,50);
                                                            setcolor(BLACK);
                                                            for(int l=650;l<=800;l++)
                                                                line(l,0,l,50);
                                                            for(int l=0;l<=179;l++)
                                                                line(l,750,l,800);
                                                            for(int l=700;l<=800;l++)
                                                                line(l,750,l,800);
                                                            setcolor (GREEN);
                                                            line(10,25,40,25);
                                                            line(10,25,15,15);
                                                            line(10,25,15,35);
                                                            rectangle(0,0,51,51);
                                                            setcolor(GREEN);
                                                            rectangle(1,750,100,798);
                                                            rectangle(700,750,799,798);
                                                            rectangle(650,1,799,50);
                                                            rectangle(100,750,179,798);
                                                            line(50,750,50,800);
                                                            line(750,750,750,800);
                                                            line(700,1,700,50);
                                                            line(750,1,750,50);
                                                            setcolor(RED);
                                                            settextstyle(4,0,1);
                                                            outtextxy(772,766, "i");
                                                            outtextxy(703,767, "Pct");
                                                            outtextxy(21,765, "-");
                                                            outtextxy(68,765, "+");
                                                            outtextxy(102,765,"Clean");
                                                            outtextxy(667,20, "V");
                                                            outtextxy(710,21, "Or");
                                                            outtextxy(756,21, "Ob");
                                                        }
                                                        else
                                                        {
                                                            cout<<"f nu are asimptote oblica spre infinit"<<endl;
                                                        }
                                                    }
                                                    if(functie(f,minfinit)==infinit || functie(f,minfinit)==-infinit)
                                                    {
                                                        char asimptota[100];
                                                        strcpy(asimptota,"(");
                                                        strcat(asimptota,f);
                                                        strcat(asimptota,"/x)");
                                                        cout<<asimptota<<endl;
                                                        m=functie(asimptota,minfinit);
                                                        cout<<"m="<<m<<endl;
                                                        n=functie(f,infinit)-m*infinit;
                                                        cout<<"n="<<n<<endl;
                                                        if(m!=infinit && m!=minfinit && n!=infinit && n!=minfinit)
                                                        {
                                                            cout<<"f are asimptota oblica spre -infinit dreapte de ecutie y="<<m<<"x+"<<n<<endl;
                                                            setcolor(LIGHTBLUE);
                                                            line(400+pow(10,zoom)*2*a,400-pow(10,zoom)*(2*a*m+n),400,400-pow(10,zoom)*(n));
                                                            setcolor(RED);
                                                            for(int l=0;l<=50;l++)
                                                                line(l,0,l,50);
                                                            setcolor(BLACK);
                                                            for(int l=650;l<=800;l++)
                                                                line(l,0,l,50);
                                                            for(int l=0;l<=179;l++)
                                                                line(l,750,l,800);
                                                            for(int l=700;l<=800;l++)
                                                                line(l,750,l,800);
                                                            setcolor (GREEN);
                                                            line(10,25,40,25);
                                                            line(10,25,15,15);
                                                            line(10,25,15,35);
                                                            rectangle(0,0,51,51);
                                                            setcolor(GREEN);
                                                            rectangle(1,750,100,798);
                                                            rectangle(700,750,799,798);
                                                            rectangle(650,1,799,50);
                                                            rectangle(100,750,179,798);
                                                            line(50,750,50,800);
                                                            line(750,750,750,800);
                                                            line(700,1,700,50);
                                                            line(750,1,750,50);
                                                            setcolor(RED);
                                                            settextstyle(4,0,1);
                                                            outtextxy(772,766, "i");
                                                            outtextxy(703,767, "Pct");
                                                            outtextxy(21,765, "-");
                                                            outtextxy(68,765, "+");
                                                            outtextxy(102,765,"Clean");
                                                            outtextxy(667,20, "V");
                                                            outtextxy(710,21, "Or");
                                                            outtextxy(756,21, "Ob");
                                                        }

                                                        else cout<<"f nu are asimptota oblica spre -infinit"<<endl;
                                                    }

                                                    else
                                                    {
                                                        cout<<"f nu are asimptote oblice"<<endl;
                                                    }
                                                }
                                                else
                                                {
                                                    cout<<"f nu are asimptote oblice"<<endl;
                                                }
                                        }
                                    if(butonPuncteExtreme(mX,mY))
                                    {
                                        i=a;
                                        while(i<b)
                                        {
                                            if(My != my )
                                            {
                                                if(functie(f,i)==My)
                                                    {
                                                        setcolor(LIGHTCYAN);
                                                        circle(400+pow(10,zoom)*i,400-pow(10,zoom)*My,10);
                                                    }
                                                if(functie(f,i)==my)
                                                    {
                                                        setcolor(14);
                                                        circle(400+pow(10,zoom)*i,400-pow(10,zoom)*my,10);
                                                    }
                                           }
                                           i+=epsilon;
                                        }
                                        if(functie(f,b)>=My && My!=my)
                                            {
                                                setcolor(LIGHTCYAN);
                                                circle(400+pow(10,zoom)*b,400-pow(10,zoom)*My,10);
                                            }
                                        if(functie(f,b)<=my && My!=my)
                                            {
                                                setcolor(14);
                                                circle(400+pow(10,zoom)*b,400-pow(10,zoom)*my,10);}
                                            }
                                    if(butonMinus(mX,mY))
                                    {
                                        cout<<"zoom="<<zoom<<endl;
                                        i=a;
                                        setcolor(0);
                                        cleardevice();
                                        setcolor(2);
                                        line(0,400,400,400);
                                        line(400,800,400,400);
                                        line(400,400,400,0);
                                        line(400,400,800,400);
                                        zoom=zoom-(0.1);
                                        setcolor(WHITE);
                                        J=0;
                                        j=400;//-pow(10,zoom);
                                        while(j>0)
                                        {
                                            line(j,398,j,403);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(j,405,scala);
                                            j-=pow(10,zoom);
                                            J--;
                                        }
                                        j=400+pow(10,zoom);
                                        J=1;
                                        while(j<=800)
                                        {
                                            line(j,398,j,403);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(j+1,405,scala);
                                            j+=pow(10,zoom);
                                            J++;
                                        }
                                        J=1;
                                        j=400-pow(10,zoom);
                                        while(j>=0)
                                        {
                                            line(398,j,403,j);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(405,j+1,scala);
                                            j-=pow(10,zoom);
                                            J++;
                                        }
                                        J=-1;
                                        j=400+pow(10,zoom);
                                        while(j<=800)
                                        {
                                            line(398,j,403,j);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(405,j+1,scala);
                                            j+=pow(10,zoom);
                                            J--;
                                        }

                                            i=a;
                                            setcolor(RED);
                                            while(i<b)
                                            {
                                                if((functie(f,i)<200 && functie(f,i)>-200)&&(functie(f,i+epsilon)<200 && functie(f,i+epsilon)>-200))
                                                {
                                                    line(400+pow(10,zoom)*i,400-pow(10,zoom)*functie(f,i),400+pow(10,zoom)*(i+epsilon),400-pow(10,zoom)*functie(f,i+epsilon));
                                                }
                                                i+=epsilon;
                                            }
                                            bar(0,0,50,50);
                                            setcolor(RED);
                                            for(int l=0;l<=50;l++)
                                                line(l,0,l,50);
                                            setcolor(BLACK);
                                            for(int l=650;l<=800;l++)
                                                line(l,0,l,50);
                                            for(int l=0;l<=179;l++)
                                                line(l,750,l,800);
                                            for(int l=700;l<=800;l++)
                                                line(l,750,l,800);
                                            setcolor (GREEN);
                                            line(10,25,40,25);
                                            line(10,25,15,15);
                                            line(10,25,15,35);
                                            rectangle(0,0,51,51);
                                            setcolor(GREEN);
                                            rectangle(1,750,100,798);
                                            rectangle(700,750,799,798);
                                            rectangle(650,1,799,50);
                                            rectangle(100,750,179,798);
                                            line(50,750,50,800);
                                            line(750,750,750,800);
                                            line(700,1,700,50);
                                            line(750,1,750,50);
                                            setcolor(RED);
                                            settextstyle(4,0,1);
                                            outtextxy(772,766, "i");
                                            outtextxy(703,767, "Pct");
                                            outtextxy(21,765, "-");
                                            outtextxy(68,765, "+");
                                            outtextxy(102,765,"Clean");
                                            outtextxy(667,20, "V");
                                            outtextxy(710,21, "Or");
                                            outtextxy(756,21, "Ob");
                                    }
                                    if(butonPlus(mX,mY))
                                    {
                                        cout<<"zoom="<<zoom<<endl;
                                        i=a;
                                        setcolor(0);
                                        cleardevice();

                                        setcolor(2);
                                        line(0,400,400,400);
                                        line(400,800,400,400);
                                        line(400,400,400,0);
                                        line(400,400,800,400);
                                        zoom+=0.1;
                                        setcolor(WHITE);
                                        J=0;
                                        j=400;//-pow(10,zoom);
                                        while(j>0)
                                        {
                                            line(j,398,j,403);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(j,405,scala);
                                            j-=pow(10,zoom);
                                           J--;
                                        }
                                        j=400+pow(10,zoom);
                                        J=1;
                                        while(j<=800)
                                        {
                                            line(j,398,j,403);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(j+1,405,scala);
                                            j+=pow(10,zoom);
                                            J++;
                                        }
                                        J=1;
                                        j=400-pow(10,zoom);
                                        while(j>=0)
                                        {
                                            line(398,j,403,j);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(405,j+1,scala);
                                            j-=pow(10,zoom);
                                            J++;
                                        }
                                        J=-1;
                                        j=400+pow(10,zoom);
                                        while(j<=800)
                                        {
                                            line(398,j,403,j);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(405,j+1,scala);
                                            j+=pow(10,zoom);
                                            J--;
                                        }
                                        setcolor(RED);
                                        i=a;
                                        while(i<b)
                                        {
                                            if((functie(f,i)<200 && functie(f,i)>-200)&&(functie(f,i+epsilon)<200 && functie(f,i+epsilon)>-200))
                                            {
                                                line(400+pow(10,zoom)*i,400-pow(10,zoom)*functie(f,i),400+pow(10,zoom)*(i+epsilon),400-pow(10,zoom)*functie(f,i+epsilon));
                                            }
                                            i+=epsilon;
                                        }
                                        bar(0,0,50,50);
                                        setcolor(RED);
                                        for(int l=0;l<=50;l++)
                                            line(l,0,l,50);
                                        setcolor(BLACK);
                                        for(int l=650;l<=800;l++)
                                            line(l,0,l,50);
                                        for(int l=0;l<=179;l++)
                                            line(l,750,l,800);
                                        for(int l=700;l<=800;l++)
                                            line(l,750,l,800);
                                        setcolor (GREEN);
                                        line(10,25,40,25);
                                        line(10,25,15,15);
                                        line(10,25,15,35);
                                        rectangle(0,0,51,51);
                                        setcolor(GREEN);
                                        rectangle(1,750,100,798);
                                        rectangle(700,750,799,798);
                                        rectangle(650,1,799,50);
                                        rectangle(100,750,179,798);
                                        line(50,750,50,800);
                                        line(750,750,750,800);
                                        line(700,1,700,50);
                                        line(750,1,750,50);
                                        setcolor(RED);
                                        settextstyle(4,0,1);
                                        outtextxy(772,766, "i");
                                        outtextxy(703,767, "Pct");
                                        outtextxy(21,765, "-");
                                        outtextxy(68,765, "+");
                                        outtextxy(102,765,"Clean");
                                        outtextxy(667,20, "V");
                                        outtextxy(710,21, "Or");
                                        outtextxy(756,21, "Ob");
                                    }
                                    if(butonClen(mX,mY))
                                    {
                                        i=a;
                                        setcolor(0);
                                        cleardevice();
                                        zoom=1.5;
                                        setcolor(2);
                                        line(0,400,400,400);
                                        line(400,800,400,400);
                                        line(400,400,400,0);
                                        line(400,400,800,400);

                                        setcolor(WHITE);
                                        J=0;
                                        j=400;//-pow(10,zoom);
                                        while(j>0)
                                        {
                                            line(j,398,j,403);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(j,405,scala);
                                            j-=pow(10,zoom);
                                           J--;
                                        }
                                        j=400+pow(10,zoom);
                                        J=1;
                                        while(j<=800)
                                        {
                                            line(j,398,j,403);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(j+1,405,scala);
                                            j+=pow(10,zoom);
                                            J++;
                                        }
                                        J=1;
                                        j=400-pow(10,zoom);
                                        while(j>=0)
                                        {
                                            line(398,j,403,j);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(405,j+1,scala);
                                            j-=pow(10,zoom);
                                            J++;
                                        }
                                        J=-1;
                                        j=400+pow(10,zoom);
                                        while(j<=800)
                                        {
                                            line(398,j,403,j);
                                            strcpy(scala,itoa(J,scala,10));
                                            settextstyle(0,0,1);
                                            outtextxy(405,j+1,scala);
                                            j+=pow(10,zoom);
                                            J--;
                                        }
                                        setcolor(RED);
                                        setcolor(4);
                                        i=a;
                                        while(i<b)
                                        {
                                                if((functie(f,i)<200 && functie(f,i)>-200)&&(functie(f,i+epsilon)<200 && functie(f,i+epsilon)>-200))
                                                {
                                                    line(400+pow(10,zoom)*i,400-pow(10,zoom)*functie(f,i),400+pow(10,zoom)*(i+epsilon),400-pow(10,zoom)*functie(f,i+epsilon));
                                                }
                                                i+=epsilon;
                                        }
                                        bar(0,0,50,50);
                                        setcolor(RED);
                                        for(int l=0;l<=50;l++)
                                            line(l,0,l,50);
                                        setcolor(BLACK);
                                        for(int l=650;l<=800;l++)
                                            line(l,0,l,50);
                                        for(int l=0;l<=179;l++)
                                            line(l,750,l,800);
                                        for(int l=700;l<=800;l++)
                                            line(l,750,l,800);
                                        setcolor (GREEN);
                                        line(10,25,40,25);
                                        line(10,25,15,15);
                                        line(10,25,15,35);
                                        rectangle(0,0,51,51);
                                        setcolor(GREEN);
                                        rectangle(1,750,100,798);
                                        rectangle(700,750,799,798);
                                        rectangle(650,1,799,50);
                                        rectangle(100,750,179,798);
                                        line(50,750,50,800);
                                        line(750,750,750,800);
                                        line(700,1,700,50);
                                        line(750,1,750,50);
                                        setcolor(RED);
                                        settextstyle(4,0,1);
                                        outtextxy(772,766, "i");
                                        outtextxy(703,767, "Pct");
                                        outtextxy(21,765, "-");
                                        outtextxy(68,765, "+");
                                        outtextxy(102,765,"Clean");
                                        outtextxy(667,20, "V");
                                        outtextxy(710,21, "Or");
                                        outtextxy(756,21, "Ob");
                                    }
                                }
                            }
                            if(!corectitudine(f))
                            {
                                readimagefile("wrong function.jpg",0,0,800,800);
                                setcolor(RED);
                                settextstyle(4,0,4);
                                outtextxy(500,60,f);
                                setcolor(RED);
                                for(int l=0;l<=50;l++)   line(l,0,l,50);

                                setcolor (GREEN);
                                line(10,25,40,25);

                                line(10,25,15,15);

                                line(10,25,15,35);

                                rectangle(0,0,51,51);
                                while (1)
                                {
                                    getmouseclick(WM_LBUTTONDOWN, mX, mY);
                                    if(butonBack(mX,mY))
                                    {
                                        interfataGrafica();
                                        break;
                                    }
                                }
                                getch(); closegraph();
                            }
                        }
                                                break;
                                            }
                if(butonInformatii(mX,mY))
                {
                    ///informatii
                    cout<< "2"<<endl;
                     for(int l=0;l<=800;l++)
                    {
                        setcolor (BLACK);
                        line(0,l,800,l);
                    }
                    bar(0,0,50,50);
                    setcolor(RED);
                    for(int l=0;l<=50;l++)
                    {
                         line(l,0,l,50);
                    }
                    setcolor (GREEN);
                    line(10,25,40,25);
                    line(10,25,15,15);
                    line(10,25,15,35);
                    rectangle(0,0,51,51);

                    midX = 800/2;
                    midY = 800/8;

                    setcolor(10);
                    settextstyle(4,0,1);
                    width = textwidth("Aici gasiti cateva informatii despre notatiile functiilor");
                    height = textheight("Aici gasiti cateva informatii despre notatiile functiilor");
                    outtextxy(midX - width/2, midY - height/2, "Aici gasiti cateva informatii despre notatiile functiilor");
                    midX = 800/2;
                    width = textwidth("- s-a folosit <<s>> pentru functia sinus");
                    height = textheight("- s-a folosit <<s>> pentru functia sinus");
                    outtextxy(100,150 - height/2, "- s-a folosit <<s>> pentru functia sinus");

                    width = textwidth("- s-a folosit <<c>> pentru functia cosinus");
                    height = textheight("- s-a folosit <<c>> pentru functia cosinus");
                    outtextxy(100, 200 - height/2, "- s-a folosit <<c>> pentru functia cosinus");

                    width = textwidth("- s-a folosit <<r>> pentru functia radical");
                    height = textheight("- s-a folosit <<r>> pentru functia radical");
                    outtextxy(100, 250 - height/2, "- s-a folosit <<r>> pentru functia radical");

                    width = textwidth("- s-a folosit <<l>> pentru functia logaritm");
                    height = textheight("- s-a folosit <<s>> pentru functia logaritm");
                    outtextxy(100, 300 - height/2, "- s-a folosit <<l>> pentru functia logaritm");

                    width = textwidth("- s-a folosit <<a>> pentru functia absolut(modul)");
                    height = textheight("- s-a folosit <<a>> pentru functia absolut(modul)");
                    outtextxy(100, 350 - height/2, "- s-a folosit <<a>> pentru functia absolut(modul");

                    width = textwidth("- apasati <<+>> pentru zoom-in");
                    height = textheight("- apasati <<+>> pentru zoom-in");
                    outtextxy(100, 400 - height/2, "- apasati <<+>> pentru zoom-in");

                    width = textwidth("- apasati <<->> pentru zoom-out");
                    height = textheight("- apasati <<->> pentru zoom-out");
                    outtextxy(100, 450 - height/2, "- apasati <<->> pentru zoom-out");

                    width = textwidth("- apasati <<Clean>> pentru a reveni la graficul initial");
                    height = textheight("- apasati <<Clean>> pentru a reveni la graficul initial");
                    outtextxy(100, 500 - height/2, "- apasati <<Clean>> pentru a reveni la graficul initial");

                    width = textwidth("- apasati <<Pct>> pentru punctele de extrem");
                    height = textheight("- apasati <<Pct>> pentru punctele de extrem");
                    outtextxy(100, 550 - height/2, "- apasati <<Pct>> pentru punctele de extrem");

                    width = textwidth("- apasati <<i>> pentru afisarea inversei");
                    height = textheight("- apasati <<i>> pentru afisarea inversei");
                    outtextxy(100, 600 - height/2, "- apasati <<i>> pentru afisarea inversei");

                    width = textwidth("- apasati <<V>> pentru afisa asimptota verticala");
                    height = textheight("- apasati <<V>> pentru afisa asimptota verticala");
                    outtextxy(100, 650 - height/2, "- apasati <<V>> pentru afisa asimptota verticala");

                    width = textwidth("- apasati <<Or>> pentru afisarea asimptotei orizontale");
                    height = textheight("- apasati <<Or>> pentru afisarea asimptotei orizontale");
                    outtextxy(100, 700 - height/2, "- apasati <<Or>> pentru afisarea asimptotei orizontale");

                    width = textwidth("- apasati <<Ob>> pentru afisarea asimptotei oblice");
                    height = textheight("- apasati <<Ob>> pentru afisarea asimptotei oblice");
                    outtextxy(100, 750 - height/2, "- apasati <<Ob>> pentru afisarea asimptotei oblice");

                    while(1)
                    {
                        getmouseclick(WM_LBUTTONDOWN, mX, mY);
                        if(butonBack(mX,mY))
                        {
                            interfataGrafica();
                            break;
                        }
                    }
                }
                if(butonDespreNoi(mX,mY))
                {
                    ///ceva despre noi
                    cout<<"3"<<endl;
                    for(int l=0;l<=800;l++)
                    {
                        setcolor (BLACK);
                        line(0,l,800,l);
                    }
                    setcolor(RED);
                    for(int l=0;l<=50;l++)
                    {
                        line(l,0,l,50);
                    }
                    setcolor (GREEN);
                    line(10,25,40,25);
                    line(10,25,15,15);
                    line(10,25,15,35);
                    rectangle(0,0,51,51);
                    setcolor(4);
                    settextstyle(10,0,4);
                    char scris[100];
                    strcpy(scris,"Bors Andrei Darius");
                    outtextxy(0,50,scris);
                    strcpy(scris,"Bacauanu Remus");
                    outtextxy(0,330,scris);
                    settextstyle(4,0,2);
                    setcolor(LIGHTGREEN);
                    strcpy(scris,"-definirea functiilor pentru erori");
                    outtextxy(0,90,scris);
                    strcpy(scris,"-trasarea graficului functiei f");
                    outtextxy(0, 130,scris);
                    strcpy(scris,"-afisarea punctelor de extrem");
                    outtextxy(0,170,scris);
                    strcpy(scris,"-afisarea asimptotelor functiei f");
                    outtextxy(0,210,scris);
                    strcpy(scris,"-afisarea inversei functiei f");
                    outtextxy(0,250,scris);
                    strcpy(scris,"-rezolvarea problemelor de logica");
                    outtextxy(0,370,scris);
                    strcpy(scris,"-conversia numerelor reale din char in double");
                    outtextxy(0,410,scris);
                    strcpy(scris,"-conversia numerelor negative din char in double");
                    outtextxy(0,450,scris);
                    strcpy(scris,"-interfata grafica a programului");
                    outtextxy(0,490,scris);
                    settextstyle(10,0,4);
                    setcolor(4);
                    strcpy(scris,"Probleme rezolvate de amandoi:");
                    outtextxy(0,640,scris);
                    setcolor(14);
                    settextstyle(4,0,2);
                    strcpy(scris,"-evaluarea functiei f intr-un punct");
                    outtextxy(0,680,scris);
                    strcpy(scris,"-testarea corectitudinii functiei f");
                    outtextxy(0,720,scris);
                    while(1)
                    {
                        getmouseclick(WM_LBUTTONDOWN, mX, mY);
                        if(butonBack(mX,mY))
                        {
                            interfataGrafica();
                            break;
                        }
                    }
                }
            }
        }
}
int main()
{
    initwindow(800,800,"GRAFICUL_FUNCTIEI");
    interfataGrafica();
    getch();
    closegraph();
}
