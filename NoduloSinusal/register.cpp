#include "modeladm.h" 
#include "mainsimu.h"
#include "NoduloSinusal.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<NoduloSinusal>() , "NoduloSinusal" ) ;
}
