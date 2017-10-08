#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

#include <cmath>

///Certaines constantes sont spécifiques au type de neurone --> envisager de tranférer certaines constantes dans la classe Neurone en tant qu'attribut

const double h = 0.1; //milliseconds, laps de temps entre chaque mesures de potentiel
const double R = 20.0; //picoFarad, tau/C = R 
const double C = 1.0;
const double tau = 20.0; //milliseconds, tau = R*C
const double tauRef = 2.0; //milliseconds, refractory time
const double Erepos = 0.0; //milliVolts
const double Vth = 20.0;
const double Vreset = 0.0; //milliVolts, potentiel de repos
const double exphtau = exp(-h/tau); //Constante dont on a besoin pour calculer le nouveau potentiel

#endif
