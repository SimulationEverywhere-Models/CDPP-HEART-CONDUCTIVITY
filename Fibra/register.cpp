#include "modeladm.h" 
#include "mainsimu.h"
#include "Fibra.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Fibra>() , "Fibra" ) ;
}
