[top]
components : ramaDePurkinje@ramaDePurkinje
in : impulso_in
out : impulso 
out : conduccion
out : bloqueo
Link : impulso_in impulso_in@ramaDePurkinje
Link : impulso_out@ramaDePurkinje impulso 
Link : bloqueo_out@ramaDePurkinje bloqueo
Link : conduccion_out@ramaDePurkinje conduccion 

[ramaDePurkinje]
tiempoRefractario : 0:0:2:0
tiempoConduccion : 0:0:1:0
failureProb : 0
