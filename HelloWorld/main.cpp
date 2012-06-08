#include <ma.h>
#include <conprint.h>


//include sneeuwlandschap zodat deze gebruikt kan worden
#include "SneeuwLandschap.h"


//de main functie
extern "C" int MAMain()
{
	MAEvent event;

	//nieuw sneeuwlandschap
	SneeuwLandschap* sneeuwLandschap = new SneeuwLandschap();


	//oneindige loop zodat de app blijft werken
	while (TRUE)
	{
		//run met 1 frame per 40 ms
		maWait(40);

		//kijk of er events hebben plaatsgevonden, sla die info op in MAEvent event.
		maGetEvent(&event);



		//als een event de app wil sluiten...
		if (EVENT_TYPE_CLOSE == event.type)
		{
			// Exit while loop.
			break;
		}

		//handel alle logica van sneeuwlandschap af
		sneeuwLandschap->run( event );

		//teken het sneeuwlandschap
		sneeuwLandschap->draw();


		//update het scherm
		maUpdateScreen();
	}

	return 0;
}
