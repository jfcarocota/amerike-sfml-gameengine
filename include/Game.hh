#pragma once

#include<SFML/Graphics.hpp>

class Game
{
private:
  sf::RenderWindow* window{};
  sf::Event* event{};

  void Update();
  void Render();
  void Input();
  void Start();
  void Draw();
  void MainLoop();
  void Destroy();
  void UpdatePhysics();
public:
  Game();
  ~Game();
  void Initialize();
};
