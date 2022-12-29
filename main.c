#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 2
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1

// Sigmoid activation function
double sigmoid(double x) {
  return 1.0 / (1.0 + exp(-x));
}

int main(int argc, char** argv) {
  // Randomly initialize weights and biases
  double input_weights[INPUT_SIZE][HIDDEN_SIZE] = {{0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}};
  double hidden_weights[HIDDEN_SIZE][OUTPUT_SIZE] = {{0.7}, {0.8}, {0.9}};
  double input_biases[HIDDEN_SIZE] = {0.1, 0.2, 0.3};
  double hidden_biases[OUTPUT_SIZE] = {0.4};

  // Input data
  double inputs[INPUT_SIZE] = {1.0, 2.0};

  // Forward propagation
  double hidden_inputs[HIDDEN_SIZE];
  for (int i = 0; i < HIDDEN_SIZE; i++) {
    hidden_inputs[i] = input_biases[i];
    for (int j = 0; j < INPUT_SIZE; j++) {
      hidden_inputs[i] += inputs[j] * input_weights[j][i];
    }
  }
  double hidden_outputs[HIDDEN_SIZE];
  for (int i = 0; i < HIDDEN_SIZE; i++) {
    hidden_outputs[i] = sigmoid(hidden_inputs[i]);
  }
  double output_inputs[OUTPUT_SIZE];
  for (int i = 0; i < OUTPUT_SIZE; i++) {
    output_inputs[i] = hidden_biases[i];
    for (int j = 0; j < HIDDEN_SIZE; j++) {
      output_inputs[i] += hidden_outputs[j] * hidden_weights[j][i];
    }
  }
  double outputs[OUTPUT_SIZE];
  for (int i = 0; i < OUTPUT_SIZE; i++) {
    outputs[i] = sigmoid(output_inputs[i]);
  }

  // Print output
  printf("Output: %f\n", outputs[0]);

  return 0;
}
