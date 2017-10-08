#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "Constantes.hpp"

class Neuron{
	
	private:
		double potential;
		double spikesNumber;
		std::vector<double> times;
		
		double temps_pause; //For the refractory time after a spike
		
	public:
		double getPotential() const;
		double getSpikesNumber() const;
		double getTime(unsigned int i) const;
		
		void setPotential(double i);
		void addSpike(); //Ajout d'un spike
		void addTime(double i);
		
		void update(double t, double current);
		
		Neuron();
		Neuron(double p, double s, std::vector<double> t);
		
		~Neuron(){}
	
};

#endif
