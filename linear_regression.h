#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

struct Neuron *create_neuron(int nb_inputs);
void free_neuron(struct Neuron *neuron);
double forward_pass(const double x[], struct Neuron *neuron);

#endif // !LINEAR_REGRESSION_H
