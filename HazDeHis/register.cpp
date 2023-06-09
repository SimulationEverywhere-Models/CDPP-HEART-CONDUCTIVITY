#include "modeladm.h" 
#include "mainsimu.h"
#include "HazDeHis.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<HazDeHis>() , "HazDeHis" ) ;
}
