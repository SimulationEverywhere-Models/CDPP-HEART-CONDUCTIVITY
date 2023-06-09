/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "randlib.h"         // Random numbers library
#include "HazDeHis.h"  // base header
#include "OutputConstants.h"  
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

HazDeHis::HazDeHis( const string &name )
: Atomic( name )
	, impulso_in ( addInputPort ( "impulso_in" ) )	
	, impulso_out( addOutputPort( "impulso_out" ) )
{
	string time(MainSimulator::Instance().getParameter(this->description(), "tiempoRefractario"));
	
	if (time != "")
		tiempoRefractario = time;	
}

Model &HazDeHis::initFunction()
{	
	this->passivate();
	return *this ;
}


//No hay puertos de entrada, esta funci�n nunca ser� ejecutada.
Model &HazDeHis::externalFunction( const ExternalMessage &msg )
{
	//El �nico puerto de origen posible es impulso_in
	
	if (this->state() == passive){
		//Est�bamos en estado excitable y transmitimos el est�mulo instant�neamente
		this->sendOutput(msg.time(), impulso_out, IMPULSO);
		
		//Nos quedaremos en el nuevo estado tiempoRefractario
		this->holdIn(active, tiempoRefractario);
	}
	return *this ;
}

Model &HazDeHis::internalFunction( const InternalMessage & )
{
	//Hay un �nico estado activo, as� que directamente pasivamos
	this->passivate();
	return *this;
}

Model &HazDeHis::outputFunction( const InternalMessage &msg )
{
  return *this;
}

HazDeHis::~HazDeHis()
{
}
