#ifndef NEURON_H
#define NEURON_H

struct Neuron {
  double *weights;
  double bias;
  int nb_inputs;
};

#endif //NEURON_H
