#pragma once
#include "SFML/Graphics.hpp"
#include<fstream>
#include<string>

class Animation
{
private:
  std::ifstream* reader{};
  sf::Sprite* sprite;
  int animationIndex{};
  int startFrame{};
  int endFrame{};
  float animationDelay{};
  float currentTime{};
  int currentAnimation{};
public:
  Animation();
  Animation(sf::Sprite* sprite, std::string animationUrl);

  void Play(float& deltaTime);
  ~Animation();
};