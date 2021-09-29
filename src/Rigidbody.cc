#include "Rigidbody.hh"

Rigidbody::Rigidbody(b2World*& world, b2BodyType bodyType, b2Vec2* position,
float width, float height, float density, float friction, float restitution,
b2Vec2* origin, float angle)
{
  this->world = world;

  //init body
  bodyDef = new b2BodyDef();
  bodyDef->type = bodyType;
  bodyDef->position = *position;
  body = world->CreateBody(bodyDef);

  //define polygon shape
  polygonShape = new b2PolygonShape();
  polygonShape->SetAsBox(width, height, *origin, angle);

  //init fixture
  fixtureDef = new b2FixtureDef();
  fixtureDef->shape = polygonShape;
  fixtureDef->density = density;
  fixtureDef->friction = friction;
  fixtureDef->restitution = restitution;
  fixture = body->CreateFixture(fixtureDef);
}

Rigidbody::~Rigidbody()
{
}

b2Body* Rigidbody::GetBody() const
{
  return body;
}
void Rigidbody::FreezeRotation(bool freeze)
{
  body->SetFixedRotation(freeze);
}