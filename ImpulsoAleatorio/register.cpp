#include "modeladm.h" 
#include "mainsimu.h"
#include "ImpulsoAleatorio.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ImpulsoAleatorio>() , "ImpulsoAleatorio" ) ;
}
