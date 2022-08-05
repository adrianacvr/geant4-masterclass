# geant4-class

1. Ingresar a Obatala con la opción de interfaz gráfica
`ssh -Y usuario@200.16.117.76`

2. Para crear el contenedor GEANT4 
https://gitmilab.redclara.net/halleyUIS/geant4

3. Iniciar el contenedor
`docker start geant4`

4. Ingresar al contenedor
`docker exec -it geant4 bash`

5. Dentro del contenedor:

  1. Copiar la carpeta del ejemplo que vamos a probar
  
  2. Crear carpeta

  3. Compilar código

  4. Abrir el ejecutable

    En el visualizador
    `/run/beamOn`

  5. Ejecutar sin visualizador
  6. Ver los histogramas en root
    root
    new TBrowser
    .q (para salir)
   
 Para salir del contenedor 

