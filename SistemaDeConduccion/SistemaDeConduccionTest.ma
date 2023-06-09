[top]
components : noduloSinusal@NoduloSinusal impulsoAleatorio@ImpulsoAleatorio conduccionAuricular noduloAV hazDeHis@HazDeHis conduccionVentricular
out : inicio_onda_P
out : fin_onda_P
out : onda_QRS
out : falla_rama_derecha
out : falla_rama_izquierda
out : impulso_inicial
out : impulso_no_producido
out : impulso_anomalo
Link : qrs@conduccionVentricular onda_QRS
Link : conduccion@conduccionAuricular inicio_onda_P
Link : impulso@conduccionAuricular fin_onda_P
Link : bloqueo_rama_derecha@conduccionVentricular falla_rama_derecha
Link : bloqueo_rama_izquierda@conduccionVentricular falla_rama_izquierda
Link : impulso_out@noduloSinusal impulso_inicial
Link : no_impulso_out@noduloSinusal impulso_no_producido
Link : impulso_out@impulsoAleatorio impulso_anomalo
Link : impulso_out@noduloSinusal impulso_sinusal@conduccionAuricular
Link : impulso_out@impulsoAleatorio impulso_extra_sinusal@conduccionAuricular
Link : impulso@conduccionAuricular impulso_in@noduloAV
Link : impulso@noduloAV impulso_in@hazDeHis
Link : impulso_out@hazDeHis impulso_in@conduccionVentricular

[noduloSinusal]
ticTacPeriod : 0:0:1:0
standardTicFailureProb : 0
nonStandardTicProb : 0

[impulsoAleatorio]
ticTacPeriod : 0:0:1:0
ticProb : 0

[conduccionAuricular]
components : fibraAuricular1@Fibra fibraAuricular2@Fibra
out : conduccion
out : impulso
in : impulso_sinusal
in : impulso_extra_sinusal
Link : impulso_sinusal impulso_in@fibraAuricular1
Link : impulso_extra_sinusal impulso_in@fibraAuricular2
Link : impulso_out@fibraAuricular1 impulso
Link : impulso_out@fibraAuricular2 impulso
Link : impulso_out@fibraAuricular1 impulso_in@fibraAuricular2
Link : impulso_out@fibraAuricular2 impulso_in@fibraAuricular1
Link : conduccion_out@fibraAuricular1 conduccion
Link : conduccion_out@fibraAuricular2 conduccion

[fibraAuricular1]
tiempoConduccion : 0:0:1:0
tiempoRefractario : 0:0:2:0

[fibraAuricular2]
tiempoConduccion : 0:0:1:0
tiempoRefractario : 0:0:2:0

[noduloAV]
components : fibraDerecha@Fibra fibraIzquierda@Fibra
out : impulso
in : impulso_in
Link : impulso_in impulso_in@fibraDerecha
Link : impulso_in impulso_in@fibraIzquierda
Link : impulso_out@fibraDerecha impulso
Link : impulso_out@fibraIzquierda impulso

[fibraDerecha]
tiempoConduccion : 0:0:1:0
tiempoRefractario : 0:0:2:0

[fibraIzquierda]
tiempoConduccion : 0:0:1:0
tiempoRefractario : 0:0:2:0

[hazDeHis]
tiempoRefractario : 0:0:2:0

[conduccionVentricular]
components : ramaDerecha@RamaDePurkinje ramaIzquierda@RamaDePurkinje
out : qrs
out : bloqueo_rama_derecha
out : bloqueo_rama_izquierda
in : impulso_in
Link : impulso_in impulso_in@ramaDerecha
Link : impulso_in impulso_in@ramaIzquierda
Link : impulso_out@ramaDerecha qrs
Link : impulso_out@ramaIzquierda qrs
Link : bloqueo_out@ramaDerecha bloqueo_rama_derecha
Link : bloqueo_out@ramaIzquierda bloqueo_rama_izquierda

[ramaDerecha]
tiempoRefractario : 0:0:2:0
tiempoConduccion : 0:0:1:0
failureProb : 0

[ramaIzquierda]
tiempoRefractario : 0:0:2:0
tiempoConduccion : 0:0:1:0
failureProb : 0