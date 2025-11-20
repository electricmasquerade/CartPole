# Cart-Pole Genetic Algorithm Balancer

A C++ implementation of a cart-pole balancing system controlled by a genetic algorithm, with Python-based visualization using NiceGUI.

## Project Overview

This project simulates a classic inverted pendulum (cart-pole) control problem and uses a genetic algorithm to evolve controllers that can balance the pole upright. The physics simulation and GA logic run in high-performance C++, while visualization and parameter control happen in Python through a clean binding layer.

### Why This Project?

- **Learn genetic algorithms in a clear context** - Cart-pole provides immediate visual feedback on controller quality
- **Practice C++/Python integration** - Real-time shared data between languages using Pybind11
- **Build modular simulation architecture** - Separate physics, evolution, and visualization concerns
- **Explore evolutionary computation** - Start simple with linear controllers, potentially expand to neural networks

## Goals

### Core Goals
1. **Implement cart-pole physics** - Accurate coupled differential equations with stable integration
2. **Build genetic algorithm framework** - Selection, crossover, mutation for evolving controllers
3. **Evolve a working controller** - Successfully balance the pole for extended periods
4. **Real-time visualization** - Watch the best controller from each generation attempt to balance

### Stretch Goals
- Expand to double pendulum (two poles)
- Compare linear controllers vs. small neural networks
- Experiment with different GA parameters and observe effects
- Add noise/perturbations to test controller robustness

## Technical Architecture

### C++ Components
- **Physics Engine** - Cart and Pole classes with coupled dynamics simulation
- **Genetic Algorithm** - Population management, fitness evaluation, evolution operators
- **Controller** - Linear mapping from state (position, velocity, angle, angular velocity) to force
- **System Manager** - Orchestrates simulation episodes and evolution cycles

### Python Components
- **NiceGUI Interface** - Real-time cart-pole visualization
- **Data Visualization** - Fitness graphs, parameter plots over generations
- **Parameter Control** - Adjust GA settings, reset, save/load controllers

### Integration Layer
- **Pybind11 bindings** - Expose C++ state and control to Python
- **Shared data structures** - Efficient transfer of cart/pole state for rendering

## Development Timeline

### Phase 1: Physics Foundation
- Set up project structure (CMake, basic classes)
- Implement Cart and Pole classes with proper accessors
- Build CartPoleSystem with coupled physics equations
- Test physics in terminal (apply forces, verify behavior)
- **Milestone**: Cart-pole responds correctly to applied forces

### Phase 2: Manual Control Testing
- Add failure detection (cart off track, pole past angle threshold)
- Implement fixed timestep simulation loop (60Hz)
- Test with simple control strategies (constant force, proportional control)
- Debug and validate physics accuracy
- **Milestone**: Can manually specify a controller and watch it attempt to balance

### Phase 3: Genetic Algorithm Core
- Design Genome structure (5 floats for linear controller)
- Implement fitness evaluation (episode length/reward function)
- Build GA operators: initialization, selection, crossover, mutation
- Run evolution in terminal with fitness output per generation
- **Milestone**: GA evolves controllers with improving fitness scores

### Phase 4: Python Visualization
- Create Pybind11 bindings for necessary C++ classes
- Build basic NiceGUI interface showing cart and pole
- Connect real-time state updates from C++ to Python
- Add fitness graph and generation counter
- **Milestone**: Watch evolved controllers balance in real-time

### Phase 5: Refinement & Experimentation
- Tune GA parameters (population size, mutation rate, etc.)
- Add UI controls for parameter adjustment
- Implement save/load for best controllers
- Document interesting behaviors and failure modes
- **Milestone**: Robust, well-tuned system ready for extension

## Success Criteria

**Minimum Viable Product:**
- Cart-pole physics working correctly
- GA successfully evolves controllers better than random
- Python visualization shows cart-pole state in real-time
- Can observe improvement over generations

**Fully Successful:**
- Controllers consistently balance pole for 10+ seconds
- Clean, modular codebase ready for extensions
- Understanding of why GA parameters affect performance
- Documented lessons learned from tuning process

## Future Extensions

- Double pendulum balancing
- Neural network controllers (fixed topology or NEAT-style)
- Swing-up task (start with pole hanging down)
- Comparison with other optimization methods (CMA-ES, PSO)
- Add cart friction, pole air resistance for realism
- Multi-objective optimization (balance time + minimize force usage)

## Requirements

- C++17 or later
- CMake 3.15+
- Python 3.8+ with UV build system
- Pybind11
- NiceGUI


