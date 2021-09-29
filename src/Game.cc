#include "CommonHeaders.hh"
#include "Player.hh"

//Rectangle* rectangle{new Rectangle(100, 100, 200, 100, sf::Color::Red)};

//Physics Init
b2Vec2* gravity{new b2Vec2(0.f, 0.f)};
b2World* world{new b2World(*gravity)};


TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 100, 25, 200.f)};
Animation* idleAnimation{new Animation()};
Animation* runAnimation{new Animation()};

Rigidbody* rigidbody{new Rigidbody(world, b2BodyType::b2_dynamicBody, 
new b2Vec2(player1->GetSprite()->getPosition().x, player1->GetSprite()->getPosition().y), 
16, 16, 1, 0, 0, new b2Vec2(player1->GetSprite()->getOrigin().x, player1->GetSprite()->getOrigin().y), 
0.f)};

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
  textObj1->SetTextStr("Hello game engine");
  idleAnimation = new Animation(player1->GetSprite(), 0, 5, 0.05f, 5);
  runAnimation = new Animation(player1->GetSprite(), 0, 5, 0.08f, 6);
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  player1->GetSprite()->setPosition(rigidbody->GetBody()->GetPosition().x, 
  -rigidbody->GetBody()->GetPosition().y);

  if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
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

    UpdatePhysics();
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
  window->draw(*textObj1->GetText());
}

//Keyboard, joysticks, etc.
void Game::Input()
{
  //player1->Move(deltaTime);
}

void Game::Destroy()
{
  delete window;
  delete event;
}