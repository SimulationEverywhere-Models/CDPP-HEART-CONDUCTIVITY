#ifndef __NODULOSINUSAL_H
#define __NODULOSINUSAL_H

#include "atomic.h"  

class NoduloSinusal: public Atomic
{
public:
	NoduloSinusal( const string &name = "NoduloSinusal" ) ;	 // Default constructor

	~NoduloSinusal();					// Destructor

	virtual string className() const
		{return "NoduloSinusal";}

protected:
	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	Port &impulso_out ;
    Port &no_impulso_out;
    
    //Período que dura el sistema en un estado. Una vez cada diez ocurrirá 
    //el latido "standard" con alta probabilidad. Las otras nueve de cada diez veces
    //ocurrirá un latido no esperado con baja probabilidad.
	Time ticTacPeriod;
	
	//Probabilidad de que no se produzca un latido cuando se esperaba,
	//float entre 0 y 1.
	float standardTicFailureProb;
	
	//Probabilidad de que se produzca un latido cuando no se esperaba,
	//float entre 0 y 1.
	float nonStandardTicProb;
	
	//Con esta variable secuenciaremos los estados
	int estado;
};

#endif
