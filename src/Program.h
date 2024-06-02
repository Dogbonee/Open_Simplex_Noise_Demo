//
// Created by hunde on 3/30/2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


class Program {

    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow m_window;
    sf::Shader m_noiseShader;
    sf::RectangleShape m_shaderShape;

    sf::Clock m_clock;
    float m_elapsedTime;


    void Update();
    void HandleEvents();
    void HandleKeyboardInput(sf::Keyboard::Key key);
    void Render();

public:
    Program();
    ~Program();
    void Run();


};



#endif //PROGRAM_H
