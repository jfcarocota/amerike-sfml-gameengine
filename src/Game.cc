#include "CommonHeaders.hh"
#include "Player.hh"

Rectangle* rectangle{new Rectangle(100, 100, 200, 100, sf::Color::Red)};
sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{new Player("../assets/sprites.png", 4.f, 16, 16, 0, 5, 100, 25, 200.f)};
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
  idleAnimation = new Animation(player1->GetSprite(), 0, 5, 0.05f, 5);
  runAnimation = new Animation(player1->GetSprite(), 0, 5, 0.08f, 6);
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
  window->draw(*player1->GetSprite());
}

//Keyboard, joysticks, etc.
void Game::Input()
{
  player1->Move(deltaTime);
}

void Game::Destroy()
{
  delete window;
  delete event;
}