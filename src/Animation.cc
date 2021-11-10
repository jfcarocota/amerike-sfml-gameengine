#include "Animation.hh"

Animation::Animation(){}
// int startFrame, int endFrame, float animationDelay, int currentAnimation
Animation::Animation(sf::Sprite* sprite, std::string animationUrl)
{
  reader = new std::ifstream();
  reader->open(animationUrl);
  this->sprite = sprite;

  *reader >> startFrame;
  *reader >> endFrame;
  *reader >> animationDelay;
  *reader >> currentAnimation;

  animationIndex = startFrame;
}

void Animation::Play(float& deltaTime)
{
  currentTime += deltaTime;

  sprite->setTextureRect(sf::IntRect(animationIndex * sprite->getTextureRect().width,
  currentAnimation * sprite->getTextureRect().height, sprite->getTextureRect().width, 
  sprite->getTextureRect().height));

  if(currentTime >= animationDelay)
  {
    if(animationIndex == endFrame)
    {
      animationIndex = startFrame;
    }
    else
    {
      animationIndex++;
    }
    currentTime = 0.f;
  }
}

Animation::~Animation()
{
}