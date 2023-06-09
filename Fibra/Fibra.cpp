/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "randlib.h"         // Random numbers library
#include "Fibra.h"  // base header
#include "OutputConstants.h"  
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

#define CONDUCIENDO 0
#define REFRACTARIA 1

Fibra::Fibra( const string &name )
: Atomic( name )
	, impulso_in ( addInputPort ( "impulso_in" ) )	
	, impulso_out( addOutputPort( "impulso_out" ) )
	, conduccion_out( addOutputPort( "conduccion_out" ) )

{
	string time(MainSimulator::Instance().getParameter(this->description(), "tiempoConduccion"));
	string time2(MainSimulator::Instance().getParameter(this->description(), "tiempoRefractario"));
	
	if (time != "")
		tiempoConduccion = time;
	
	if (time2 != "")
	{
		tiempoRefractario = time2;
	}	
}

Model &Fibra::initFunction()
{	
	this->passivate();
	return *this ;
}


//No hay puertos de entrada, esta función nunca será ejecutada.
Model &Fibra::externalFunction( const ExternalMessage &msg )
{
	//El único puerto de origen posible es impulso_in
	
	if (this->state() == passive){
		//Estábamos en estado excitable y pasamos a conducción
		this->sendOutput(msg.time(), conduccion_out, CONDUCCION);
		
		//Pasamos estado a conducción
		this->estado = CONDUCCION;
		
		//Nos quedaremos en el nuevo estado tiempoConduccion
		this->holdIn(active, tiempoConduccion);
	}
	return *this ;
}

Model &Fibra::internalFunction( const InternalMessage & )
{
	if (this->estado == CONDUCCION)
	{
		this->estado = REFRACTARIA;
		this->holdIn(active, tiempoRefractario);
	}
	else if (this->estado == REFRACTARIA)
	{
		this->passivate();
	}

	return *this;
}

Model &Fibra::outputFunction( const InternalMessage &msg )
{
  if ( this->estado == CONDUCCION )
  {	  	
  	sendOutput( msg.time(), impulso_out, IMPULSO);	  	 	  	
  }
  return *this;
}

Fibra::~Fibra()
{
}
