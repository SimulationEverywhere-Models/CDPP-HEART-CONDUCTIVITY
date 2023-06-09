#ifndef __RAMADEPURKINJE_H
#define __RAMADEPURKINJE_H

#include "atomic.h"  

class RamaDePurkinje: public Atomic
{
public:
	RamaDePurkinje( const string &name = "RamaDePurkinje" ) ;	 // Default constructor

	~RamaDePurkinje();	// Destructor

	virtual string className() const
		{return "RamaDePurkinje";}

protected:
	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &impulso_in;
	Port &impulso_out;
	Port &conduccion_out;
	Port &bloqueo_out;	
        
	//Tiempo que los ventrículos demoran en conducir
	Time tiempoConduccion;        
        
	//Tiempo que los ventrículso demoran en estado refractario
	Time tiempoRefractario;
	
	//Probabilidad de falla de la rama ante la llegada de un impulso
	float failureProb;
	
	int estado;
};

#endif
