#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

const double dt=0.006;
const double eps=0.001;
const double a=1.0/(2.0*sqrt(2.0));
const double seis=1.0/6.0;

double fp1( double q1 );
double fp2( double q1, double q2 );
void fk1(double x[4] , double k1[4]); 
void fk2(double x[4], double k1[4] , double k2[4]); 
void fk3(double x[4], double k2[4] , double k3[4]); 
void fk4(double x[4], double k3[4] , double k4[4]);
void rk(double x[4] , double k1[4], double k2[4], double k3[4], double k4[4]);



int main () {

    double tmax=3000;
    int n=tmax/dt;
    double x[4]={a,-a,0,0};
    double k1[4]={0,0,0,0};
    double k2[4]={0,0,0,0};
    double k3[4]={0,0,0,0};
    double k4[4]={0,0,0,0};
    double q11=a;
   

    for(int i=0; i<n ; i++){
        rk(x,k1,k2,k3,k4);
        if(q11*x[0]<0){
            cout<<x[1]<<" "<<x[3]<<"\n";
        }
        q11=x[0];
    }
    
    

    


return 0;

}


double fp1 ( double q1 ){

    double t1=((4.0*q1*q1)+(eps*eps));
    double p1=(-2.0*q1)/sqrt(t1*t1*t1);
    return p1;

}


double fp2 ( double q1, double q2 ){

    double q11=(q1-q2);
    double q22=(q1+q2);
    double t11=((q11*q11)+(0.25*eps*eps));
    double t22=((q22*q22)+(0.25*eps*eps));
    double p11=q11/sqrt(t11*t11*t11);
    double p22=q22/sqrt(t22*t22*t22);
    return p11-p22;
}

void fk1(double x[4] , double k1[4]){

    k1[0]=dt*x[2];
    k1[1]=dt*x[3];
    k1[2]=dt*fp1(x[0]);
    k1[3]=dt*fp2(x[0],x[1]);


}

void fk2(double x[4], double k1[4] , double k2[4]){

    k2[0]=dt*(x[2]+(0.5*k1[2]));
    k2[1]=dt*(x[3]+(0.5*k1[3]));
    k2[2]=dt*fp1(x[0]+(0.5*k1[0]));
    k2[3]=dt*fp2(x[0]+(0.5*k1[0]),x[1]+(0.5*k1[1]));


}

void fk3(double x[4], double k2[4] , double k3[4]){

    k3[0]=dt*(x[2]+(0.5*k2[2]));
    k3[1]=dt*(x[3]+(0.5*k2[3]));
    k3[2]=dt*fp1(x[0]+(0.5*k2[0]));
    k3[3]=dt*fp2(x[0]+(0.5*k2[0]),x[1]+(0.5*k2[1]));


}

void fk4(double x[4], double k3[4] , double k4[4]){

    k4[0]=dt*(x[2]+k3[2]);
    k4[1]=dt*(x[3]+k3[3]);
    k4[2]=dt*fp1(x[0]+k3[0]);
    k4[3]=dt*fp2(x[0]+k3[0],x[1]+k3[1]);


}

void rk(double x[4] , double k1[4], double k2[4], double k3[4], double k4[4]){


    fk1(x,k1);
    fk2(x,k1,k2);
    fk3(x,k2,k3);
    fk4(x,k3,k4);


    for(int i=0; i<4 ; i++){
        x[i]+=(seis*(k1[i]+(2.0*k2[i])+(2.0*k3[i])+k4[i]));
    }


}


