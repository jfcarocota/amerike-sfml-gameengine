#include "Player.hh"
#include "InputSystem.hh"

Player::Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float playerSpeed)
{
  this->textureUrl = textureUrl;
  this->playerScale = playerScale;
  this->width = width;
  this->height = height;
  this->column = column;
  this->row = row;
  this->playerSpeed = playerSpeed;

  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(column * width, row * height, width, height));
  sprite->setPosition(posX, posY);
  sprite->setColor(sf::Color::White);
  sprite->setScale(playerScale, playerScale);
  sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getOrigin().y);
}
Player::Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float posX, float posY, float playerSpeed)
{
  this->textureUrl = textureUrl;
  this->playerScale = playerScale;
  this->width = width;
  this->height = height;
  this->column = column;
  this->row = row;
  this->posX = posX;
  this->posY = posY;
  this->playerSpeed = playerSpeed;

  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(column * width, row * height, width, height));
  sprite->setPosition(posX, posY);
  sprite->setColor(sf::Color::White);
  sprite->setScale(playerScale, playerScale);
  sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getOrigin().y);
}

Player::~Player()
{
}

sf::Sprite* Player::GetSprite() const
{
  return sprite;
}

void Player::Move(float& deltaTime)
{
  sprite->move(InputSystem::Axis() * deltaTime * playerSpeed);
  FlipSprite();
}
void Player::FlipSprite()
{
  sprite->setScale(InputSystem::Axis().x > 0 ? playerScale : InputSystem::Axis().x < 0 ? -playerScale : 
  sprite->getScale().x, 
  playerScale);
}