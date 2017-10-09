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
	
	double ExtCurrent(0.0);
	cout << "Determine an external current ([1;100] pA) :";
	cin >> ExtCurrent;
	cout << endl;
		
	ofstream sortie("Data.txt");

	Neuron neurone;
	
	int nb_steps(t_stop/Neuron::h); //0.1ms est notre pas de temps
	
	for (int t(0); t < nb_steps; ++t){
		if (sortie.fail()){
			cerr<< "Erreur d'ouvertur du fichier" << endl;
		}else{
			sortie /*<< "At time " << t << " : " */<< neurone.getPotential() << endl;
		
			neurone.update(ExtCurrent);
		}
	}
	
	for (size_t i(0); i < neurone.getSpikesNumber();++i){
		cout << "Spike au temps : " << neurone.getTime(i)*Neuron::h << endl;
	}
	
	cout << "Le neurone a 'spiké' " << neurone.getSpikesNumber() << " fois." << endl;
	
	return 0;
}
