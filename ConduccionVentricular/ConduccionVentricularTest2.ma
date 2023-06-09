[top]
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
failureProb : 1

[ramaIzquierda]
tiempoRefractario : 0:0:2:0
tiempoConduccion : 0:0:1:0
failureProb : 1