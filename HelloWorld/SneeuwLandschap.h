/*
 * SneeuwLandschap.h
 *
 *  Created on: 27 feb. 2012
 *      Author: Luuk
 */


#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_


#include <ma.h>
#include <MAUtil/Vector.h>


#include "SneeuwMan.h"
#include "SneeuwVlok.h"



class SneeuwLandschap
{
private:
	int sneeuwHoogte;
	SneeuwMan* sneeuwMan;

	MAUtil::Vector<SneeuwVlok*> sneeuwVlokArray;

public:
	SneeuwLandschap();
	void draw();
	void run( MAEvent event );
};


#endif /* SNEEUWLANDSCHAP_HPP_ */
