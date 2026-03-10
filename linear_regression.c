#include <stdio.h>
#include <stdlib.h>
#include "neuron.h"
#include "linear_regression.h"

#define LEARNING_RATE 0.1
#define EPOCHS 100


int main(int argc, char *argv[])  
{
  struct Neuron *neuron = create_neuron(NEURON_DIM);

  //initializing the Dataset
 /* struct Dot dataset[DATA_SIZE] = {
    {{1}, 2},
    {{3}, 2},
    {{5}, 2},
    {{7}, 2},
    {{10}, 2}
  };

  struct Dot dataset[DATA_SIZE] = {
    {{1}, 4},
    {{2}, 7},
    {{3}, 10},
    {{4}, 13},
    {{5}, 16}
  };
  */

  //gradient descent updating the weight and bias
  gradient_descent(neuron, dataset, DATA_SIZE, LEARNING_RATE,  EPOCHS);


  // After training
  printf("Trained weights: ");
  for(int i = 0; i < NEURON_DIM; i++)
  {
    printf("%f ", neuron->weights[i]);
  }

  printf("\n");

  printf("Trained bias: %f\n", neuron->bias);


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
  for(int i = 0; i < NEURON_DIM; i++)
  {
    neuron_sum += neuron->weights[i] * x[i];
  }

  return neuron_sum;
}

double error(double predicted_y, double y)
{
  return predicted_y - y;
}

void gradient_descent(struct Neuron *neuron, struct Dot dataset[DATA_SIZE], int n_samples, double lr, int epochs)
{
  for(int e = 0; e < epochs; e++)
  {
    for(int i = 0; i < n_samples; i++)
    {
      double y_pred = forward_pass(dataset[i].x, neuron);
      double err = error(y_pred, dataset[i].y);
      
      for(int j = 0; j < NEURON_DIM; j++)
        neuron->weights[j] -= lr * err * dataset[i].x[j];
      
      neuron->bias -= lr * err;
      
    }
  }
}
