[top]
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
tiempoConduccion : 0:0:2:0
tiempoRefractario : 0:0:4:0

[fibraAuricular2]
tiempoConduccion : 0:0:1:0
tiempoRefractario : 0:0:4:0