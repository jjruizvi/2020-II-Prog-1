#include <iostream>
#include <cmath>
#include <vector>

const double K = 1.23;
const double M = 0.987;
const double W = std::sqrt(K/M);
const double T0 = 0.0;
const double TF = 35;
const double H = 0.1;
const int NSTEPS = (TF-T0)/H;
const int DIM = 2;

typedef std::vector<double> state_t;
using system_t = void(const state_t & y, state_t & dydt, double t);

void euler(system_t deriv, state_t & data, double t, double h);
void rk4(system_t deriv, state_t & data, double t, double h);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(void)
{
    state_t y(DIM);
    y = {0.787, 0.0};  // initial conditions

    // time evolution
    for (int ii = 0; ii < NSTEPS; ++ii) {
        double t = T0 + ii*H;
        std::cout << t << "  " << y[0] << "   " << y[1] << "\n";
        //euler(fderiv, y, t, H); 
        rk4(fderiv, y, t, H);
    }
      
    return 0;
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
    dydt[0] = y[1]; // dx/dt = v
    dydt[1] = -K*std::pow(y[0], 1)/M; // dv/dt = a = -Kx/M = -W^2 x 
}


void euler(system_t deriv, state_t & data, double t, double h)
{
    state_t dydt(data.size());
    deriv(data, dydt, t);

    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + h*dydt[ii];  
    } 
}

void rk4(system_t deriv, state_t & data, double t, double h)
{
    state_t dydt(data.size());
    state_t k1(data.size()), k2(data.size()),
        k3(data.size()), k4(data.size()), aux(data.size());

    // k1
    deriv(data, dydt, t);
    for(int ii = 0; ii < data.size(); ++ii) {
        k1[ii] = h*dydt[ii];
    }
    // k2 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k1[ii]/2;
    }
    // k2
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k2[ii] = h*dydt[ii];
    }
    // k3 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k2[ii]/2;
    }
    // k3
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k3[ii] = h*dydt[ii];
    }
    // k4 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k3[ii];
    }
    // k4
    deriv(aux, dydt, t + h);
    for(int ii = 0; ii < data.size(); ++ii) {
        k4[ii] = h*dydt[ii];
    }

    // write new data
    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
}
