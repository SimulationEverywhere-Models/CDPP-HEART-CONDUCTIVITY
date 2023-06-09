#ifndef __FIBRA_H
#define __FIBRA_H

#include "atomic.h"  

class Fibra: public Atomic
{
public:
	Fibra( const string &name = "Fibra" ) ;	 // Default constructor

	~Fibra();	// Destructor

	virtual string className() const
		{return "Fibra";}

protected:
	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &impulso_in;
	Port &impulso_out;
	Port &conduccion_out;
        
	//Tiempo que esta fibra demora en el estado de conducción 
	Time tiempoConduccion;
	
	//Tiempo que esta fibra demora en estado refractario
	Time tiempoRefractario;
	
	//Con esta variable secuenciaremos los estados
	int estado;
};

#endif
