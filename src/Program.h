//
// Created by hunde on 3/30/2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "OpenSimplexNoise.h"

class Program {

    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;
    static constexpr double SCALE = 100;

    sf::Vertex* m_points;
    sf::VertexBuffer m_pointBuf;
    unsigned long m_pointCount;

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    OpenSimplexNoise::Noise m_noise;

    float m_dt;
    float m_elapsedTime;
    float m_time;

    void Update();
    void HandleEvents();
    void HandleKeyboardInput(sf::Keyboard::Key key);
    void Render();

    void ComputeNoise();

public:
    Program();
    ~Program();
    void Run();


};



#endif //PROGRAM_H
