#ifndef Entity_h
#define Entity_h

#include <vector>
#include <stdio.h>
#include "SheetSprite.h"

enum EntityType{ PLAYER, CHASER1, CHASER2, SHOOTER, BULLET, PLATFORM };
//Chaser 1 can jump to other platforms
//Chaser 2 can only move left and right along a platform

class Entity {
public:
	Entity();
	Entity(float x_pos, float y_pos,const SheetSprite* sprite, EntityType type);
	~Entity();

	void setSprite(SheetSprite* newSprite);
	virtual void render(ShaderProgram &program);
	virtual void update(float elapsed);
	
	bool collisionEntity(Entity* other);

	bool collisionInX(float x, float width);
	bool collisionInY(float y, float height);

	SheetSprite* sprite;
	EntityType type;


	
	float x_pos;
	float y_pos;
	float x_velocity;
	float y_velocity;
	float width;
	float height;
	float x_acceleration;
	float y_acceleration;

	bool collidedTop;
	bool collidedBottom;
	bool collidedLeft;
	bool collidedRight;

	Matrix modelMatrix;
};


#endif
