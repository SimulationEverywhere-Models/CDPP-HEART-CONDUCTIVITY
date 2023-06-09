/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "randlib.h"         // Random numbers library
#include "NoduloSinusal.h"  // base header
#include "OutputConstants.h"  // Shared output constants
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

#define LATIDO_STANDARD 0

NoduloSinusal::NoduloSinusal( const string &name )
: Atomic( name )
	, impulso_out( addOutputPort( "impulso_out" ) )
	, no_impulso_out( addOutputPort( "no_impulso_out" ) )
{
	string time(MainSimulator::Instance().getParameter(this->description(), "ticTacPeriod"));
	string sTProb(MainSimulator::Instance().getParameter(this->description(), "standardTicFailureProb"));
	string nSTProb(MainSimulator::Instance().getParameter(this->description(), "nonStandardTicProb"));
	
	if (time != "")
		ticTacPeriod = time;
	
	if (sTProb != "")
	{
		standardTicFailureProb = str2float(sTProb);
	}
	
	if (nSTProb != "")
	{
		nonStandardTicProb = str2float(nSTProb);
	}
}

Model &NoduloSinusal::initFunction()
{	
	this->estado = LATIDO_STANDARD;
	this->holdIn( active, ticTacPeriod );
	return *this ;
}


//No hay puertos de entrada, esta función nunca será ejecutada.
Model &NoduloSinusal::externalFunction( const ExternalMessage &msg )
{	
	return *this ;
}

Model &NoduloSinusal::internalFunction( const InternalMessage & )
{
	this->estado = ((this->estado + 1) % 10);
	holdIn(active, ticTacPeriod);
	return *this;
}

Model &NoduloSinusal::outputFunction( const InternalMessage &msg )
{
      double randnumber = (double)rand()/(double)RAND_MAX;	  	
	  if ( this->estado == LATIDO_STANDARD )
	  {	  	
	  	 if (randnumber > standardTicFailureProb)
	  	 {
	         sendOutput( msg.time(), impulso_out, IMPULSO);	  	 	
	  	 }
	  	 else 
	  	 {
	  	 	sendOutput(msg.time(), no_impulso_out, NO_IMPULSO);
	  	 }	
	  }
	  else 
	  {
	  	if (randnumber <= nonStandardTicProb)
	  	{
	  		sendOutput(msg.time(), impulso_out, IMPULSO);
	  	}
	  }
	  
	return *this;
}

NoduloSinusal::~NoduloSinusal()
{
}
