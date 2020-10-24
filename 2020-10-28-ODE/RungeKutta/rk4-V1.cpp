#include <iostream>
#include <cmath>
#include <vector>
#include "integration.h"

const double K = 1.23;
const double M = 0.987;
const double W = std::sqrt(K/M);
const double T0 = 0.0;
const double TF = 35;
const double H = 0.1;
const int NSTEPS = (TF)/H;
const int DIM = 2;

typedef std::vector<double> state_t;

void fderiv(const state_t & y, state_t & dydt, double t)
{
    dydt[0] = y[1];
    dydt[1] = -K*std::pow(y[0], 1)/M;
}

int main(void)
{
    state_t y(DIM);
    y = {0.787, 0.0};  // initial conditions

    integrate(fderiv, y, T0, TF, H);

    return 0;
}

