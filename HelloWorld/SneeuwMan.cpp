/*
 * SneeuwMan.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Luuk
 */


#include "SneeuwMan.h"
#include <ma.h>


SneeuwMan::SneeuwMan(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
}

// tekent sneeuwman
void SneeuwMan::draw()
{
	maSetColor(0xCCCCCC); //kleur v/d sneeuwman
	maFillRect(this->positionX, this->positionY -30, 30, 30); //hoofd
	maFillRect(this->positionX +5, this->positionY -50, 20, 20); // lichaam

}

// zorgt voor beweging
void SneeuwMan::move( int direction)
{

	this->positionX += direction;

}

