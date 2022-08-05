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
  
  `cp -r examples-geant4/basic/B4/B4a/ .`
  
  2. Crear y entrar a la carpeta donde se va a compilar el código

  `mkdir B4a-build`
  
  `cd B4a-build`

  3. Compilar código

  `cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../B4a/; make -j2;`

  4. Probar el ejecutable

  `./exampleB4a`

    En el visualizador
    
    `/run/beamOn`
    
    Comparar 3 partículas:
    
    `/gun/particle gamma`
    
    `/gun/energy 2 MeV`


    `/gun/particle e-`
    
    `/gun/energy 2 MeV`


    `/gun/particle mu-`

    `/gun/energy 2 MeV`

Ahora con más energía (100 MeV)

  5. Ejecutar sin visualizador
  
  `./exampleB4a -m run2.mac > outputfile.out`
  
  6. Ver los histogramas en root
  
    `root`

    `new TBrowser`
    
    `.q` (para salir)
   
 
 Para salir y detener el contenedor
 
 `exit`
 
 `docker stop geant4`

