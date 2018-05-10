#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

double prom( double u21, double u01, double u12, double u10 );


int main () {

    double L;
    double V0;
    double d;
    double l;
    double h;
    int n;
    double N;
    L=5.0;
    l=2.0;
    d=1.0;
    h=5.0/(512);
    V0=100;
    N=2.0*(L/h)*(L/h);

    n=L/h;


    double espacio0[n][n];
    double partialx[n][n];
    double partialy[n][n];

    int k1;
    int k2;
    int k3;
    int k4;
    
    k1=(n/L)*(0.5*L-0.5*l);
    k2=(n/L)*(0.5*L+0.5*l);
    k3=(n/L)*(0.5*L-0.5*d);
    k4=(n/L)*(0.5*L+0.5*d);
    


    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            if( (j==k3) && (i>=k1 && i<=k2) ){
                espacio0[i][j]=0.5*V0;
            }
            else if( (j==k4) && (i>=k1 && i<=k2) ){
                espacio0[i][j]=-0.5*V0;
            }
            else{
                espacio0[i][j]=0;
            }
            partialx[i][j]=0;
            partialy[i][j]=0;
        }
    }

    for(int k=0; k<N ; k++){
        for(int i=1; i<n-1 ; i++){
            for(int j=1; j<n-1 ; j++){
                if( (j==k3 || j==k4) && (i>=k1 && i<=k2) ){
                    
                }
                else{
                    espacio0[i][j]=prom(espacio0[i+1][j],espacio0[i-1][j],espacio0[i][j+1],espacio0[i][j-1]);
                }
            }
        }
    }

    double delta;
    delta=h/100.0;

    for(int i=1; i<n-1 ; i++){
        for(int j=1; j<n-1 ; j++){
            partialx[i][j]=-(espacio0[i-1][j]-espacio0[i+1][j])/(2.0*h);
            partialy[i][j]=-(espacio0[i][j-1]-espacio0[i][j+1])/(2.0*h);
        }
    }


    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cout<<espacio0[i][j]<<" ";
        }
    }
    cout<<"\n";

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cout<<partialx[i][j]<<" ";
        }
    }
    cout<<"\n";

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cout<<partialy[i][j]<<" ";
        }
    }
    cout<<"\n";


return 0;

}

double prom( double u21, double u01, double u12, double u10 ){
    
    double res;

    res=0.25*(u21+u01+u12+u10);

    return res;

}


