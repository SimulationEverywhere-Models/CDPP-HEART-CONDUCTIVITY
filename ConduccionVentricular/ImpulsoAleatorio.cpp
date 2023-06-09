/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "randlib.h"         // Random numbers library
#include "ImpulsoAleatorio.h"  // base header
#include "OutputConstants.h"  
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

#define STAND_BY 0

ImpulsoAleatorio::ImpulsoAleatorio( const string &name )
: Atomic( name )
	, impulso_out( addOutputPort( "impulso_out" ) )

{
	string time(MainSimulator::Instance().getParameter(this->description(), "ticTacPeriod"));
	string sTProb(MainSimulator::Instance().getParameter(this->description(), "ticProb"));
	
	if (time != "")
		ticTacPeriod = time;
	
	if (sTProb != "")
	{
		ticProb = str2float(sTProb);
	}	
}

Model &ImpulsoAleatorio::initFunction()
{	
	this->estado = STAND_BY;
	this->holdIn( active, ticTacPeriod );
	return *this ;
}


//No hay puertos de entrada, esta función nunca será ejecutada.
Model &ImpulsoAleatorio::externalFunction( const ExternalMessage &msg )
{	
	return *this ;
}

Model &ImpulsoAleatorio::internalFunction( const InternalMessage & )
{
	this->estado = ((this->estado + 1) % 10);
	holdIn(active, ticTacPeriod);
	return *this;
}

Model &ImpulsoAleatorio::outputFunction( const InternalMessage &msg )
{
      double randnumber = (double)rand()/(double)RAND_MAX;	  	
	  if ( this->estado == STAND_BY )
	  {	  	
	  	 if (randnumber <= ticProb)
	  	 {
	         sendOutput( msg.time(), impulso_out, IMPULSO);	  	 	
	  	 }
	  }
	return *this;
}

ImpulsoAleatorio::~ImpulsoAleatorio()
{
}
