#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

class Player
{
private:
  std::string textureUrl{};
  float playerScale{};
  int width{};
  int height{};
  int column{};
  int row{};
  float posX{};
  float posY{};
  sf::Sprite* sprite;
  sf::Texture* texture;
  float playerSpeed{};

  void FlipSprite();
public:
  Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float playerSpeed);
  Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float posX, float posY, float playerSpeed);
  ~Player();
  sf::Sprite* GetSprite() const;
  void Move(float& deltaTime);
};