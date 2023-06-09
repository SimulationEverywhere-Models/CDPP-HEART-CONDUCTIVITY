#include "modeladm.h" 
#include "mainsimu.h"
#include "Fibra.h"
#include "HazDeHis.h"
#include "ImpulsoAleatorio.h"
#include "NoduloSinusal.h"
#include "RamaDePurkinje.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Fibra>() , "Fibra" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<HazDeHis>() , "HazDeHis" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ImpulsoAleatorio>() , "ImpulsoAleatorio" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<NoduloSinusal>() , "NoduloSinusal" ) ;	
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<RamaDePurkinje>() , "RamaDePurkinje" ) ;	
}
