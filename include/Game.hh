#pragma once

#include<SFML/Graphics.hpp>
#include "GameObject.hh"

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
  static std::vector<GameObject*>* gameObjects;

  Game();
  ~Game();
  void Initialize();

  static void AddGameObject(GameObject* gameObject);
};
