# function_fingerprint

# Geometric Fingerprint Framework

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

An original conceptual framework for visualizing the local properties (derivatives) of a function as a unique "geometric fingerprint" on the complex plane.

![Example Trajectory](spring_rk4_trajectory.png)
*(Upload and display an image of a generated trajectory, e.g., for the spring simulation, here)*

---

## 📖 Overview

This project integrates information from the first, second, and third derivatives of a function `f(x)` or a system described by a differential equation at a given point, calculating a characteristic "step vector `H`" onto the complex plane.

By plotting the trajectory of `H` as `x` or time `t` varies, it becomes possible to capture the intrinsic mathematical characteristics of each function or system (such as periodicity, stability, singularities, chaos, etc.) as a visual pattern.

### The Concept: Integration via Geometric Mean

The core of this framework lies in its elegant method of integrating the **additive interaction (`H₁`)** and the **multiplicative interaction (`H₂`)** of direction vectors—generated from the derivatives—via a **geometric mean**.

$$
H_1 = \frac{h_2 + h_3 + h_4}{3}
$$

$$
H_2 = h_2 \cdot h_3 \cdot h_4
$$

$$
H = \sqrt{H_1 \cdot H_2} \cdot 2^{-n}
$$

---

## ✨ Examples of Discovered "Fingerprints"

Using this framework, unique "fingerprints" have been discovered for various functions and systems.

| Function/System | Magnitude of H vs. Time | Trajectory of H on the Complex Plane |
| :--- | :---: | :---: |
| **`f(x) = sin(x)`** | ![sin(x) magnitude](sin_magnitude.png) | ![sin(x) trajectory](sin_trajectory.png) |
| **`f(x) = x^4`** | ![x^4 magnitude](x4_magnitude.png) | ![x^4 trajectory](x4_trajectory.png) |
| **Spring Oscillation (RK4)** | ![Spring magnitude](spring_rk4_magnitude.png) | ![Spring trajectory](spring_rk4_trajectory.png) |

*(Upload and display your generated graph images here)*

---

## 🚀 Usage

There are two main steps to run this framework.

### 1. Generate Trajectory Data

First, compile and run the C program (e.g., `spring_rk4.c`) to generate the coordinate data for the trajectory.

```sh
# Compile
gcc spring_rk4.c -o spring_sim -lm

# Run
./spring_sim
