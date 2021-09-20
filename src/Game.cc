#include "Game.hh"
#include "Constants.hh"
#include "Rectangle.hh"
#include "InputSystem.hh"
#include "Animation.hh"
#include<iostream>

Rectangle* rectangle{new Rectangle(100, 100, 200, 100, sf::Color::Red)};
sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
sf::Texture* texture1{new sf::Texture()};
sf::Sprite* sprite1{new sf::Sprite()};
const float playerScale{4.f};
const float playerSpeed{500.f};
/*int animationIndex{};
int startFrame{};
int endFrame{5};
float animationDelay{0.05f};
float currentTime{};
int currentAnimation{5};*/
Animation* idleAnimation{new Animation()};
Animation* runAnimation{new Animation()};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  texture1->loadFromFile("../assets/sprites.png");
  if(texture1 != nullptr) std::cout << "Ok";
  sprite1->setTexture(*texture1);
  sprite1->setTextureRect(sf::IntRect(0 * 16, 5 * 16, 16, 16));
  sprite1->setPosition(100, 25);
  sprite1->setColor(sf::Color::White);
  sprite1->setScale(playerScale, playerScale);
  sprite1->setOrigin(sprite1->getGlobalBounds().width / playerScale / 2, 0.f);
  //animationIndex = startFrame;
  idleAnimation = new Animation(sprite1, 0, 5, 0.05f, 5);
  runAnimation = new Animation(sprite1, 0, 5, 0.08f, 6);
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();
  //std::cout << "elapsed time: " << deltaTime << std::endl;

  //currentAnimation = std::abs(InputSystem::Axis().x) > 0 ? 6 : 5;
  if(std::abs(InputSystem::Axis().x) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  //window->draw(*rectangle->GetShape());
  window->draw(*sprite1);
}

//Keyboard, joysticks, etc.
void Game::Input()
{
  /*rectangle->GetShape()->move(sf::Vector2f(InputSystem::Axis().x * deltaTime * 1000.f,
  InputSystem::Axis().y * deltaTime * 1000.f));*/
  sprite1->move(sf::Vector2f(InputSystem::Axis().x * deltaTime * playerSpeed,
  InputSystem::Axis().y * deltaTime * playerSpeed));
  sprite1->setScale(InputSystem::Axis().x > 0 ? playerScale : InputSystem::Axis().x < 0 ? -playerScale : 
  sprite1->getScale().x, 
  playerScale);
}

void Game::Destroy()
{
  delete window;
  delete event;
}