# Physics-Informed Geometric Fingerprints

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This project uses a novel conceptual framework to analyze and visualize the behavior of dynamical systems. It applies the "Geometric Fingerprint" method to a simple harmonic oscillator, demonstrating how the underlying physics can be translated into a unique trajectory on the complex plane.

![Spring Oscillator Trajectory](https'://i.imgur.com/G4gA3rJ.png)
*(The trajectory of the fingerprint vector H for a simple harmonic oscillator, `y'' = -y`)*

---

## 📖 Overview

The core of this project is a C program that performs two key tasks simultaneously:

1.  **High-Fidelity Simulation**: It simulates a simple harmonic oscillator (a frictionless spring) using the highly accurate **4th-order Runge-Kutta (RK4)** method for numerical integration. This ensures a stable, non-decaying oscillation that closely models the ideal physical system.

2.  **Geometric Fingerprinting**: At each time step of the simulation, it calculates a "geometric fingerprint" (`H`). This unique complex vector is derived from the system's state variables (position, velocity, acceleration) using a custom mathematical framework.

The result is a time-series of complex numbers that represents the "fingerprint" of the oscillator's state as it evolves through time.

### The Fingerprint Calculation

The fingerprint vector `H` is calculated from the system's derivatives (`y'`, `y''`, `y'''`) by translating them into unit vectors on the complex plane. Their additive (`H₁`) and multiplicative (`H₂`) interactions are then unified via a **geometric mean**.

$$
H_1 = \frac{h_1 + h_2 + h_3}{3}
$$

$$
H_2 = h_1 \cdot h_2 \cdot h_3
$$

$$
H = \sqrt{H_1 \cdot H_2} \cdot 2^{-n}
$$

---

## 🚀 How to Use

The program is designed to be run from the command line, piping its output directly into a plotting tool like Gnuplot for real-time visualization.

### 1. Compile

First, compile the C program. You will need a standard C compiler (like GCC) and the math library.

```sh
chmod +x spring_program.sh
./spring_program.sh
command+Q
