/*
 * SneeuwVlok.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Luuk
 */


#include "SneeuwVlok.h"
#include <ma.h>

SneeuwVlok::SneeuwVlok(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->size = rand()%10; // getal onder de 10
	this->dead = false;

}

//tekent een sneeuwvlok met een random grootte en witte kleur
void SneeuwVlok::draw()
{
	maSetColor( 0xffffff);
	maFillRect ( this->positionX, this->positionY, this->size, this->size);
}


// laat sneeuwvlokken verdwijnen als ze de grond raken
void SneeuwVlok::fall(int groundLevel)
{

	if(positionY < groundLevel)
	{
	this->positionY++;
	}
	else
	{
		dead = true;
	}

}

bool SneeuwVlok::isDead()
{
	return dead;

}


