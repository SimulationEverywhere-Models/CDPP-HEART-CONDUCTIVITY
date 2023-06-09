#include "modeladm.h" 
#include "mainsimu.h"
#include "RamaDePurkinje.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<RamaDePurkinje>() , "RamaDePurkinje" ) ;
}
