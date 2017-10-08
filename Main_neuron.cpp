#include <iostream>
#include <fstream>
#include "Constantes.hpp"
#include "Neuron.hpp"

using namespace std;

int main(){
	
	//We say t_start=0
	double t_stop(0.0);
	cout << "Determine a time to stop :";
	cin >> t_stop;
	cout << endl;
	
	double ExtCurrent(0);
	cout << "Determine an external current ([0;400] pA) :";
	cin >> ExtCurrent;
	cout << endl;
		
	ofstream sortie("Simulator.txt");

	Neuron neurone;
	
	for (double t(0); t < t_stop; t+=h){
		if (sortie.fail()){
			cerr<< "Erreur d'ouvertur du fichier" << endl;
		}else{
			sortie /*<< "At time " << t << " : " */<< neurone.getPotential() << endl;
		
			neurone.update(t,ExtCurrent);
		}
	}
	
	for (size_t i(0); i < neurone.getSpikesNumber();++i){
		cout << "Spike au temps : " << neurone.getTime(i) << endl;
	}
	
	cout << "Le neurone a 'spiké' " << neurone.getSpikesNumber() << " fois." << endl;
	
	return 0;
}
