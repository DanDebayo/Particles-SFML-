#include <SFML/Graphics.hpp>
#include <random>

class Particle
{
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Time lifespan;
    sf::CircleShape shape;

    Particle()
    {
        shape.setRadius(1.f);
        shape.setFillColor(sf::Color::Red);
    }

    void update(sf::Time dt)
    {
        position += velocity * dt.asSeconds();
        lifespan -= dt;
        shape.setPosition(position);
    }
};

class ParticleSystem
{
public:
    std::vector<Particle> particles;

    void addParticle(const Particle& particle)
    {
        particles.push_back(particle);
    }

    void update(sf::Time dt)
    {
        for (auto& particle : particles)
        {
            particle.update(dt);
        }

        particles.erase(
            std::remove_if(particles.begin(), particles.end(),
                [](const Particle& p) { return p.lifespan <= sf::Time::Zero; }),
            particles.end());
    }

    void draw(sf::RenderWindow& window)
    {
        for (const auto& particle : particles)
        {
            window.draw(particle.shape);
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle System");

    ParticleSystem particleSystem;

    sf::Clock clock;
    sf::Time deltaTime;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> positionDist(0.f, 800.f);
    std::uniform_real_distribution<float> velocityDist(-50.f, 50.f);
    std::uniform_real_distribution<float> lifespanDist(1.f, 3.f);

    while (window.isOpen())
    {
        deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Particle particle;
        particle.position = sf::Vector2f(positionDist(gen), positionDist(gen));
        particle.velocity = sf::Vector2f(velocityDist(gen), velocityDist(gen));
        particle.lifespan = sf::seconds(lifespanDist(gen));

        particleSystem.addParticle(particle);

        particleSystem.update(deltaTime);

        window.clear();
        particleSystem.draw(window);
        window.display();
    }

    return 0;
}
