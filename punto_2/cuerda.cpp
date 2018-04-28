#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

double tmas( double cp, double u11, double u01, double u12, double u10 );
double tmas1( double cp, double u11, double u12, double u10 );


int main () {

    double L=100;
    double T=40;
    double rho=10;
    double c;
    c=sqrt(T/rho);
    int n=501;
    double u0[n];
    double u1[n];
    double utemp;
    double dx;
    dx=L/(n-1);
    double dt;
    dt=0.0001*dx/c;
    double cp;
    cp=dt*dt*c*c/(dx*dx);
    int rep = 200/dt;
    
    for(int i=0; i<n ; i++){
        double posx;
        posx = i * dx;
        cout<< posx <<" ";
    }
    cout<<"\n";

    for(int i=0; i<n ; i++){
        double posx;
        posx = i * dx;
        if(posx<=0.8*L ){
            u0[i]=1.25*posx/L;
        }
        else{
            u0[i]=5.0-(5.0*posx/L);
        }
        cout<< u0[i] <<" ";
    }

    cout<<"\n";


    for(int k=0; k<rep ; k++){
        if(k==0){
            u1[0]=0;
            u1[n]=0;
            for(int i=1; i<n-1 ; i++){
                u1[i]=tmas1( cp, u0[i], u0[i+1], u0[i-1] );
            }
        }
        else{
            for(int i=1; i<n-1 ; i++){
                utemp=u1[i];
                u1[i]=tmas( cp, u1[i], u0[i], u1[i+1], u1[i-1] );
                u0[i]=utemp;
            }
            if(k%(rep/50)==0){
                for(int i=0; i<n ; i++){
                    cout<< u1[i] <<" ";
                }
                cout << "\n";
            }
        }
    }


return 0;

}

double tmas( double cp, double u11, double u01, double u12, double u10 ){

    double u21;
    u21=2.0*u11-u01+cp*(u12+u10-2.0*u11);
    return u21;

}

double tmas1( double cp, double u11, double u12, double u10 ){

    double u21;
    u21=u11+(cp*0.5)*(u12+u10-2.0*u11);
    return u21;

}


