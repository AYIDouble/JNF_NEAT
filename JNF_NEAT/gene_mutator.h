#pragma once
#include "gene.h"
#include "training_parameters.h"
#include <vector>
#include <algorithm>
class GeneMutator {
	// Members
	private:
		const TrainingParameters & parameters;

	// Methods
	public:
		GeneMutator() = delete;
		explicit GeneMutator(const TrainingParameters & parameters);
		GeneMutator(const GeneMutator & other) = default;
		GeneMutator(const GeneMutator && other) = delete;

		~GeneMutator() = default;

		void MutateGenes(std::vector<Gene> & genes) const;
	private:
		static bool DidChanceOccure(float chance);
		bool ShouldAddNeuron() const { return DidChanceOccure(parameters.advanced.mutation.chanceForNeuralMutation); }
		bool ShouldAddConnection() const { return DidChanceOccure(parameters.advanced.mutation.chanceForConnectionalMutation); }
		bool ShouldMutateWeight() const { return DidChanceOccure(parameters.advanced.mutation.chanceForWeightMutation); }
		void AddRandomNeuron(std::vector<Gene> & genes) const;
		void AddRandomConnection(std::vector<Gene> & genes) const;
		void ShuffleWeights(std::vector<Gene> & genes) const;
		void MutateWeightOfGene(Gene & gene) const;
		void PerturbWeight(float weight) const;
};