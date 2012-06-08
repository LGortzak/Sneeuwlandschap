/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Luuk
 */


#include "SneeuwLandschap.h"
#include <mastdlib.h>
#include "SneeuwMan.h"

// breedte en hoogte definieren
int screenWidth;
int screenHeight;


//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//breedte en hoogte definieren
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );



	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte );
}


//event die wordt aangeroepen als er in dit geval links of rechts wordt gedrukt
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//key code
		int key = maGetKeys();


		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels (naar links )


		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels ( naar rechts)
	}


	//TODO: voeg een sneeuwvlok toe
	for(int i= 0; i < 1; i++)
	{
		SneeuwVlok* sneeuwVlok = new SneeuwVlok((rand()%screenWidth),0);
		this->sneeuwVlokArray.add(sneeuwVlok);
	}


	//TODO: laat alle sneeuwvlokken vallen

	for(int i = 0; i <this->sneeuwVlokArray.size();i++)
		{
			sneeuwVlokArray[i]->fall(screenHeight - sneeuwHoogte);
		}
}


//tekent lucht, sneeuw, sneeuwman en sneeuwvlokken
void SneeuwLandschap::draw()
{
	//kleurt de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	//TODO: teken de sneeuwman
	sneeuwMan->draw();

	//TODO: teken alle sneeuwvlokken
	for(int i = 0; i <this->sneeuwVlokArray.size();i++)
		{
			this->sneeuwVlokArray[i]->draw();

			if(this->sneeuwVlokArray[i]->isDead())
			{
				delete sneeuwVlokArray[i];
				sneeuwVlokArray.remove(i);
			}
		}
}


