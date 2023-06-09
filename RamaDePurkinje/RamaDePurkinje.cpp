/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "randlib.h"         // Random numbers library
#include "RamaDePurkinje.h"  // base header
#include "OutputConstants.h"  
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

#define EXCITABLE 0
#define VENTRICULOS_EN_CONDUCCION 1
#define VENTRICULOS_REFRACTARIOS 2

RamaDePurkinje::RamaDePurkinje( const string &name )
: Atomic( name )
	, impulso_in ( addInputPort ( "impulso_in" ) )	
	, impulso_out( addOutputPort( "impulso_out" ) )
	, conduccion_out( addOutputPort( "conduccion_out" ) )
	, bloqueo_out( addOutputPort( "bloqueo_out" ) )	
{
	string time(MainSimulator::Instance().getParameter(this->description(), "tiempoRefractario"));
	string time2(MainSimulator::Instance().getParameter(this->description(), "tiempoConduccion"));	
	string prob(MainSimulator::Instance().getParameter(this->description(), "failureProb"));	
	
	if (time != "")
		tiempoRefractario = time;	
	
	if (time2 != "")
		tiempoConduccion = time2;	
		
	if (prob != "")
	{
		failureProb = str2float(prob);
	}	
}

Model &RamaDePurkinje::initFunction()
{	
	this->passivate();
	this->estado = EXCITABLE;
	return *this ;
}


Model &RamaDePurkinje::externalFunction( const ExternalMessage &msg )
{

    double randnumber = (double)rand()/(double)RAND_MAX;	  	
	if (randnumber <= this->failureProb)
	{
		//Esta falla se traduce en un bloqueo de la rama
		this->sendOutput(msg.time(), bloqueo_out, BLOQUEO);
	}
	else 
	{
		//El impulso pasa 
		if (this->state() == passive)
		{
			//Los ventrículos estaban excitables, empieza la conducción
			this->sendOutput(msg.time(), conduccion_out, CONDUCCION);
			this->estado = VENTRICULOS_EN_CONDUCCION;
			this->holdIn(active, tiempoConduccion);
		}
		//Si no, los ventrículos estaban conduciendo o refractarios, por lo que 
		//el impulso queda sin efecto.				
	}

	return *this ;
}

Model &RamaDePurkinje::internalFunction( const InternalMessage & )
{	
	if (this->estado == VENTRICULOS_EN_CONDUCCION)
	{	
		//Los ventrículos quedan en estado refractario
		this->estado = VENTRICULOS_REFRACTARIOS;
		
		//Utilizamos el tiempo de refracción
		this->holdIn(active, tiempoRefractario);
	}
	else if (this->estado == VENTRICULOS_REFRACTARIOS)
	{
		//Los ventrículos vuelven a estar excitables, sólo hay que pasivar
		this->estado = EXCITABLE;
		this->passivate();
	}
	return *this;
}

Model &RamaDePurkinje::outputFunction( const InternalMessage &msg )
{
  if (this->estado == VENTRICULOS_EN_CONDUCCION)
  {
  	//Los ventrículos terminaron de conducir, se produce la sístole
  	this->sendOutput(msg.time(), impulso_out, IMPULSO);
  }

  return *this;
}

RamaDePurkinje::~RamaDePurkinje()
{
}
