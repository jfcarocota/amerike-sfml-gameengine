#pragma once
#include<box2d/box2d.h>
#include "GameObject.hh"
#include<iostream>

class ContactEventManager : public b2ContactListener
{
private:
  std::vector<GameObject*>* gameObjects;

public:
  ContactEventManager(std::vector<GameObject*>*& gameObjects);
  ~ContactEventManager();
  void BeginContact(b2Contact* contact) override;
  void EndContact(b2Contact* contact) override;
};