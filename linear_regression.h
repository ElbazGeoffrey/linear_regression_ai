#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

struct Neuron *create_neuron(int nb_inputs);
void free_neuron(struct Neuron *neuron);

#endif // !LINEAR_REGRESSION_H
