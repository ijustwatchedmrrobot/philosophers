import matplotlib.pyplot as plt
import random
from scipy.stats import qmc
import numpy as np

START, FINISH = -5, 5

# Parameters for the Linear Congruential Generator (LCG)
modulus = 2**32
a = 1664525
c = 1013904223
seed = 123456789

def lcg(modulus, a, c, seed, n):
    numbers = []
    for _ in range(n):
        seed = (a * seed + c) % modulus
        numbers.append((seed / modulus) * (FINISH - START) + START)
    return numbers

def random_samples(n):
    return [(random.random() * (FINISH - START) + START) for _ in range(n)]

def halton_samples(dim, n):
    sampler = qmc.Halton(dim)
    return sampler.random(n) * (FINISH - START) + START

def monte_carlo_area(samples):
    count_inside = 0
    for x, y in samples:
        if x**2 - abs(x)*y + y**2 <= 25:
            count_inside += 1
    return (count_inside / len(samples)) * 100

# Simulation settings
n_values = [1000, 10000, 100000]
methods = {
    'LCG': lambda n: lcg(modulus, a, c, seed, n),
    'Random': random_samples,
    'Halton': lambda n: halton_samples(2, n)
}

for method_name, method in methods.items():
    plt.figure(figsize=(5, 3))
    areas = []
    for n in n_values:
        samples = method(n)
        if method_name != 'Halton':  # Adjust for Halton's 2D output
            samples = [(samples[i], samples[i + 1]) for i in range(0, len(samples), 2)]
        area_estimate = monte_carlo_area(samples)
        areas.append(area_estimate)
    plt.plot(n_values, areas, label=method_name, marker='o', linestyle='-')
    plt.xticks(n_values, [f'{n}' for n in n_values])
    plt.xlabel('Number of Samples (n)')
    plt.ylabel('Estimated Area (%)')
    plt.title(f'Performance of {method_name} Method Across Sample Sizes')
    plt.legend()
    plt.grid(True)
    plt.show()

# Conduct simulations and plot results using line graphs
plt.figure(figsize=(10, 6))
for method_name, method in methods.items():
    areas = []
    for n in n_values:
        samples = method(n)
        if method_name != 'Halton':  # Adjust for Halton's 2D output
            samples = [(samples[i], samples[i + 1]) for i in range(0, len(samples), 2)]
        area_estimate = monte_carlo_area(samples)
        areas.append(area_estimate)
    plt.plot(n_values, areas, label=method_name, marker='o')

plt.xticks(n_values, [f'{n}' for n in n_values])  # Set custom x-axis tick labels
plt.xlabel('Number of Samples (n)')
plt.ylabel('Estimated Area (%)')
plt.title('Area Estimation Comparison Across Sample Sizes')
plt.legend()
plt.grid(True)
plt.show()

# Generate random numbers and save to files for Diehard tests
n_samples = 100000  # Number of samples for randomness tests

methods_for_tests = {
    'LCG': lambda n: lcg(modulus, a, c, seed, n),
    'Random': random_samples,
    'Halton': lambda n: halton_samples(1, n).flatten()
}

# Only generate LCG numbers for the Diehard test
method_name = 'LCG'
numbers = methods_for_tests[method_name](n_samples)
with open(f'{method_name}_numbers.txt', 'w') as f:
    for number in numbers:
        f.write(f'{number}\n')

print("LCG random numbers generated and saved to LCG_numbers.txt for Diehard tests.")
