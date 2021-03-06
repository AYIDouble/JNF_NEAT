#include "neural_network_trainer.h"
#include "xor_solver.h"
#include <iostream>
#include <time.h>

int main() {
    srand((unsigned)time(0U));
	std::cout << "Hello World" << std::endl;

	TrainingParameters params;
	params.numberOfInputs = 2;
	params.numberOfOutputs = 1;
	params.updatesPerGeneration = 10;

	std::vector<ITrainable*> population;
	for (int i = 0; i < 20; ++i) {
		population.push_back(new XORSolver());
	}
	NeuralNetworkTrainer trainer(population, params);
	trainer.TrainUntilFitnessEquals(100);
	auto& champ = trainer.GetFittestSpecimen();

    for (auto& individuum : population) {
        delete individuum;
    }

	return 0;
}