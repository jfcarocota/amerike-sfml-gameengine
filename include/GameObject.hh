#pragma once
#include "Rigidbody.hh"
#include "SFML/Graphics.hpp"

class GameObject
{
protected:
  float scale{};
  int width{};
  int height{};
  int column{};
  int row{};
  float posX{};
  float posY{};
  sf::Sprite* sprite;
  sf::Texture* texture;
  Rigidbody* rigidbody{};
  b2World* world{};
  sf::RenderWindow* window;
public:
  GameObject(std::string textureUrl, float scale, int width, int height, int column, int row, 
  float posX, float posY, b2World*& world, sf::RenderWindow*& window);
  ~GameObject();

  virtual void Start();
  virtual void Update(float& deltaTime);
  virtual void Draw();
  virtual void Input();
};
