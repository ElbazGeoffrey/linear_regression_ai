#include <stdio.h>
#include <stdlib.h>
#include "neuron.h"
#include "linear_regression.h"

#define DATA_SIZE 5

int main(int argc, char *argv[])  
{
  struct Neuron *neuron = create_neuron(1);

  //initializing the Dataset
  struct Dot dataset[] = {
    {{1}, 2},
    {{1}, 2},
    {{1}, 2},
    {{1}, 2},
    {{1}, 2}
  };


  free_neuron(neuron);

  return EXIT_SUCCESS;
}


/*
 * param :
 *        -nb_inputs : number of monomials in the sum (dimension of the neuron)
 * return : 
 *        -struct Neuron * : a general neuron form such as the formula to compute the outpout is the sum of Weight_i * Xi + bias
 * *
 * *the bias and the weights are arbitrary set to 0. They might change when learning.
 * *
*/
struct Neuron *create_neuron(int nb_inputs)
{
  struct Neuron *neuron = malloc(sizeof(struct Neuron));

  neuron->nb_inputs = nb_inputs;
  neuron->bias = 0.0;
  neuron->weights = malloc(sizeof(double) * nb_inputs);

  for(int i = 0; i < nb_inputs; i++)
  {
    neuron->weights[i] = 0.0;
  }

  return neuron;
}

void free_neuron(struct Neuron *neuron)
{
  free(neuron->weights);
  free(neuron);
}


double forward_pass(const double x[], struct Neuron *neuron)
{
  double neuron_sum = neuron->bias;
  for(int i = 0; i < neuron->nb_inputs; i++)
  {
    neuron_sum += neuron->weights[i] * x[i];
  }

  return neuron_sum;
}
