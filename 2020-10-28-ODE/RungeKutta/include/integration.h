#include <iostream>

#ifndef __INTEGRATION_H_
#define __INTEGRATION_H_

template<typename system_t, typename state_t>
void euler(system_t deriv, state_t & data, double t, double h)
{
    state_t dydt(data.size());
    deriv(data, dydt, t);

    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + h*dydt[ii];
    }
}

template<typename system_t, typename state_t>
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

template<typename system_t, typename state_t>
    void integrate(system_t deriv, state_t & data, double tmin, double tmax, double dt)
{
    const int nsteps = (tmax-tmin)/dt;
    for (int ii = 0; ii <= nsteps; ++ii) {
        double t = tmin + ii*dt;
        std::cout << t << "  " << data[0] << "   " << data[1] << "\n";
        //euler(fderiv, y, t, H);
        rk4(deriv, data, t, dt);
    }

}



#endif // __INTEGRATION_H_
