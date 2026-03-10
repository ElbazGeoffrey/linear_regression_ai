#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H
#include "inputs.h"

#define DATA_SIZE 5


struct Neuron *create_neuron(int nb_inputs);
void free_neuron(struct Neuron *neuron);
double forward_pass(const double x[], struct Neuron *neuron);
double error(double predicted_y, double y);
void gradient_descent(struct Neuron *neuron, struct Dot dataset[DATA_SIZE], int n_samples, double lr, int epochs);

#endif // !LINEAR_REGRESSION_H
