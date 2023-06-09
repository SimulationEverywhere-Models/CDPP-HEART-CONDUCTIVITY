#ifndef __HAZDEHIS_H
#define __HAZDEHIS_H

#include "atomic.h"  

class HazDeHis: public Atomic
{
public:
	HazDeHis( const string &name = "HazDeHis" ) ;	 // Default constructor

	~HazDeHis();	// Destructor

	virtual string className() const
		{return "HazDeHis";}

protected:
	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &impulso_in;
	Port &impulso_out;
        
	//Tiempo que el haz demora en estado refractario
	Time tiempoRefractario;
};

#endif
