[top]
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