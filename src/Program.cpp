//
// Created by hunde on 3/30/2024.
//

#include "Program.h"

Program::Program() : m_window(sf::VideoMode(WIDTH, HEIGHT), "Open Simplex Noise")
{

    m_window.setFramerateLimit(120);
    m_noiseShader.loadFromFile("../shaders/simplex.glsl", sf::Shader::Fragment);

    m_shaderShape.setSize(sf::Vector2f(WIDTH,HEIGHT));
}

Program::~Program()
{

}

void Program::Update()
{
    float lastElapsedTime = m_elapsedTime;
    m_elapsedTime = m_clock.getElapsedTime().asSeconds();
    m_noiseShader.setUniform("iResolution", sf::Glsl::Vec2(m_window.getSize()));
    m_noiseShader.setUniform("iTime", m_elapsedTime);
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

    m_window.draw(m_shaderShape, &m_noiseShader);

    m_window.display();
}


void Program::Run()
{
    while(m_window.isOpen())
    {
        Update();
    }
}
