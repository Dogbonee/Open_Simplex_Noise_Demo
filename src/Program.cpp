//
// Created by hunde on 3/30/2024.
//

#include "Program.h"

Program::Program() : m_window(sf::VideoMode(WIDTH, HEIGHT), "Open Simplex Noise"),
m_noise(time(nullptr)), m_elapsedTime(0), m_pointBuf(sf::Points)
{
    m_pointCount = WIDTH * HEIGHT;
    m_points = (sf::Vertex*)malloc(sizeof(sf::Vertex) * m_pointCount);

    sf::Vertex point;
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x <WIDTH; x++)
        {
            point.position = sf::Vector2f(x,y);
            m_points[y * WIDTH + x] = point;
        }

    }

    m_pointBuf.create(m_pointCount);
    m_pointBuf.update(m_points);
}

Program::~Program() = default;

void Program::Update()
{
    m_dt = m_clock.restart().asSeconds();
    m_elapsedTime += m_dt;

    ComputeNoise();
    HandleEvents();
    Render();
}

void Program::HandleEvents()
{
    for(sf::Event event{}; m_window.pollEvent(event);)
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                HandleKeyboardInput(event.key.code);
                break;

        }
    }
}

void Program::HandleKeyboardInput(sf::Keyboard::Key key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
            m_window.close();
            break;
        default:
            std::cout << "Key pressed: " << key << '\n';
    }
}

void Program::Render()
{
    m_window.clear();

    m_pointBuf.update(m_points);
    m_window.draw(m_pointBuf);

    m_window.display();
}

void Program::ComputeNoise()
{
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            double result = m_noise.eval(x / SCALE, y / SCALE, m_elapsedTime);
            int rgb = (result + 1) * 128;
            int roundedRgb = rgb >= 128 ? 255 : 0;
            m_points[WIDTH * y + x].color = sf::Color(roundedRgb,roundedRgb,roundedRgb);

        }
    }
}

void Program::Run()
{
    while(m_window.isOpen())
    {
        Update();
    }
}
