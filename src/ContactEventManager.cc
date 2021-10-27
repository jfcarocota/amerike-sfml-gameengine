#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& gameObjects)
{
  this->gameObjects = gameObjects;
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact* contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(actorA && actorB)
  {
    std::cout << "Collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    if(actorB->GetTagName().compare("chest") == 0)
    {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), actorB), gameObjects->end());
      //actorB->~GameObject();
      //delete actorB;
    }
  }
}
void ContactEventManager::EndContact(b2Contact* contact)
{

}