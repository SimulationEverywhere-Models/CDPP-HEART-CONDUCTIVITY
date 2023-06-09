#ifndef __IMPULSOALEATORIO_H
#define __IMPULSOALEATORIO_H

#include "atomic.h"  

class ImpulsoAleatorio: public Atomic
{
public:
	ImpulsoAleatorio( const string &name = "ImpulsoAleatorio" ) ;	 // Default constructor

	~ImpulsoAleatorio();	// Destructor

	virtual string className() const
		{return "ImpulsoAleatorio";}

protected:
	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	Port &impulso_out ;
        
    //Período que dura el sistema en un estado. Una vez cada diez ocurrirá 
    //un latido con baja probabilidad. Las otras nueve de cada diez veces
    //ocurrirá un latido no esperado con baja probabilidad.
	Time ticTacPeriod;
	
	//Probabilidad de que se produzca un latido. Float entre 0 y 1.
	float ticProb;
	
	//Con esta variable secuenciaremos los estados
	int estado;
};

#endif
