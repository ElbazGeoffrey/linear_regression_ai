# Linear Regression AI (C Implementation)

## Overview

This project implements **linear regression trained with gradient descent** using a simple **neuron model written in C**.

The goal is getting familiar with AI concept by making basic machine learning algorithm **from scratch**, without external libraries.
The implementation treats linear regression as a **single artificial neuron**.

---

# Model

The neuron computes an affine function:

ŷ = w·x + b

Where:

* **x** : input vector
* **w** : weights vector
* **b** : bias
* **ŷ** : predicted output

---

# Dataset Representation

Each training sample is stored as:

```
struct Dot {
    double x[NEURON_DIM];
    double y;
};
```

Where:

* `x` is the input vector
* `y` is the expected output

The dataset is simply an array of these samples.

---

# Forward Pass

The forward pass computes the predicted output of the neuron:

```
y_pred = w · x + b
```

In code this corresponds to:

```
sum = bias
for each input i
    sum += weight[i] * x[i]
```

The result is the model prediction for a single sample.

---

# Error Function

The prediction error is defined as:

error = y_pred − y

Where:

* `y_pred` is the predicted value
* `y` is the true value

This value indicates whether the model prediction is **too large or too small**.

---

# Gradient Descent

The model parameters are optimized using **stochastic gradient descent**.

For each training sample, the weights and bias are updated as:

```
w_j = w_j − lr * error * x_j
b   = b   − lr * error
```

Where:

* **lr** is the learning rate
* **error** measures prediction accuracy
* **x_j** indicates how much each weight influences the output

These updates gradually reduce the prediction error.

---

# Training Loop

Training proceeds for several **epochs**.

An epoch corresponds to one full pass through the dataset.

```
for epoch in epochs
    for each sample in dataset
        y_pred = forward_pass(...)
        error  = y_pred − y
        update weights
        update bias
```

Over time the parameters converge toward the best linear approximation.

---

# Expected Result

After training, the neuron learns parameters `(w, b)` such that:

```
y ≈ w·x + b
```

For example, if the dataset follows:

```
y = 3x + 1
```

the algorithm should converge toward:

```
w ≈ 3
b ≈ 1
```

---

# Project Structure

```
main.c
neuron.h
linear_regression.h
inputs.h
```


