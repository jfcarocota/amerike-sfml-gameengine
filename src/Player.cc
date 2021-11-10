#include "Player.hh"
#include "InputSystem.hh"


Player::Player(std::string textureUrl, float playerScale, int width, int height, int column, int row,
float posX, float posY, float playerSpeed, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window) :
GameObject(textureUrl, playerScale, width, height, column, row, posX, posY, bodyType, world, window)
{
  animationSystem = new AnimationSystem();

  animationSystem->AddAnimation("idle", new Animation(sprite, "assets/animations/player/idle.anim"));
  animationSystem->AddAnimation("walk", new Animation(sprite, "assets/animations/player/walk.anim"));
  this->playerSpeed = playerSpeed;
  rigidbody->FreezeRotation(true);
}

Player::~Player()
{
}

sf::Sprite* Player::GetSprite() const
{
  return sprite;
}

void Player::Update(float& deltaTime)
{
  animationSystem->Update(deltaTime);
  GameObject::Update(deltaTime);
  Move();

  if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    animationSystem->Play("walk");
  }
  else
  {
    animationSystem->Play("idle");
  }

}

void Player::Draw()
{
  GameObject::Draw();

}

void Player::Move()
{
  rigidbody->GetBody()->SetLinearVelocity(b2Vec2(InputSystem::Axis().x * playerSpeed,
  InputSystem::Axis().y * playerSpeed));

  FlipSprite();
}
void Player::FlipSprite()
{
  sprite->setScale(InputSystem::Axis().x > 0 ? scale : InputSystem::Axis().x < 0 ? -scale :
  sprite->getScale().x,
  scale);
}