# 2D Particles-SFML-
Here’s a README template you can use for your project. It explains what the code does, how to set it up, and provides additional details for users.

---

# Particle System with SFML

This is a simple particle system implemented in C++ using the SFML (Simple and Fast Multimedia Library). The program creates particles that move in random directions and fade out after a certain lifespan.

## Features
- Particles are generated with random positions, velocities, and lifespans.
- The particles move according to their velocity and disappear when their lifespan expires.
- The system continuously spawns new particles as the application runs.

## Getting Started

### Prerequisites
- **C++ Compiler**: Make sure you have a C++ compiler that supports C++11 or later.
- **SFML Library**: You need to have the SFML library installed on your system.

### Installing SFML

1. **Linux (Ubuntu/Debian)**:
   ```bash
   sudo apt-get install libsfml-dev
   ```

2. **Windows**: Download the SFML library from the [official website](https://www.sfml-dev.org/download/sfml/2.5.1/). Follow the instructions for integrating it with your compiler.

3. **macOS**:
   ```bash
   brew install sfml
   ```

### Cloning the Repository
To get started, clone this repository to your local machine:
```bash
git clone https://github.com/your-username/particle-system-sfml.git
cd particle-system-sfml
```

### Building the Project
You can compile the project using the following commands:

1. **Linux/macOS**:
   ```bash
   g++ -std=c++11 main.cpp -o ParticleSystem -lsfml-graphics -lsfml-window -lsfml-system
   ./ParticleSystem
   ```

2. **Windows** (assuming MinGW and SFML setup):
   ```bash
   g++ -std=c++11 main.cpp -o ParticleSystem -lsfml-graphics -lsfml-window -lsfml-system
   ParticleSystem.exe
   ```

## How It Works
1. **Particle Class**: Each particle has a position, velocity, lifespan, and is represented visually by a circle shape.
   - The position is updated based on the velocity.
   - The lifespan decreases with time, and once it reaches zero, the particle is removed.

2. **ParticleSystem Class**: This class manages a collection of particles.
   - It updates the particles' positions and removes any that have expired.
   - The particles are drawn to the window each frame.

3. **Main Loop**:
   - In the main loop, the program continuously spawns new particles with random attributes.
   - The particle system is updated, and particles are drawn onto the window.

## Customization
You can customize the particle system by adjusting the random distributions for:
- **Particle position**
- **Velocity**
- **Lifespan**

For example, if you want faster particles, increase the range of `velocityDist`. If you want particles to last longer, increase the range of `lifespanDist`.

## Dependencies
- **SFML**: Simple and Fast Multimedia Library (version 2.5.1 or later)

## Acknowledgments
- [SFML Documentation](https://www.sfml-dev.org/documentation/2.5.1/) - For excellent resources on SFML.
