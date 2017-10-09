#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "Constantes.hpp"

class Neuron{
	
	private:
	
	//Constantes
		const double R = 20.0; //picoFarad, tau/C = R 
		const double C = 1.0;
		const double tau = 20.0; //milliseconds, tau = R*C
		const double tauRef = 2.0; //milliseconds, refractory time
		const double Erepos = 0.0; //milliVolts
		const double Vth = 20.0;
		const double Vreset = 0.0; //milliVolts, potentiel de repos
		const double exphtau = exp(-h/tau); //Constante dont on a besoin pour calculer le nouveau potentiel
	
	//Attributs
		double potential;
		double spikesNumber;
		std::vector<double> times;
		
		int temps_pause; //For the refractory time after a spike, in nb of steps
		
		int clock_; //in nb of steps (not in seconds)
		
	public:
	
		static constexpr double h = 0.1; //milliseconds, laps de temps entre chaque mesures de potentiel
	
		double getPotential() const;
		double getSpikesNumber() const;
		double getTime(unsigned int i) const;
		
		void setPotential(double i);
		void addSpike(); //Ajout d'un spike
		void addTime(double i);
		
		void update(double current);
		
		Neuron();
		Neuron(double p, double s, std::vector<double> t);
		
		~Neuron(){}
	
};

#endif
