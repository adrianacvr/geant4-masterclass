## WCD de LAGO

Para simular el Detector Cherenkov de Agua (WCD, en inglés) de LAGO:

1. Clonar el repositorio 

`git clone https://github.com/adrianacvr/geant4-class.git`


2. La carpeta `wcd_flux_corsika` contiene la fuente del código del WCD. La podemos mover al sitio donde tenemos los demás códigos:

`mv geant4-class/wcd_flux_corsika .`


3. **En su local:** 

Descargar el archivo de CORSIKA (https://drive.google.com/file/d/16BHZksUYniZ5w_Vg9jZYT5K5iQEjy4jt/view)

Copiarlo en la carpeta fuente `wcd_flux_corsika` de la siguiente manera: 

`docker cp RUTA_LOCAL NOMBRE_CONTENEDOR:RUTA_DEL_CONTENEDOR`


En **mi computador** sería:

`cp /Users/macbookpro/Downloads/salidasimu.shw.bz2 geant4-mc:/root/wcd_flux_corsika`


4. Revisar en su docker si el archivo se copió en la carpeta `wcd_flux_corsika` con el comando `ls`

`cd wcd_flux_corsika`

`ls *.shw.bz2`


5. Crear una carpeta nueva para compilar el programa del WCD

`mkdir wcd-build`

`cd wcd-build`

`cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../wcd_flux_corsika/; make -j2;`


6. Visualizar el detector

`./wcd`

`/run/beamOn`


7. Para simular la respuesta del WCD al flujo de partículas secundarias en Bucaramanga:

Verifique o cambie el número de partículas secundarias, en el archivo input.in:

`/run/beamOn 10000` (Recomendación para la clase de hoy)

`/run/beamOn 3855333` (Este número corresponde a 1 hora de flujo por m2 en Bucaramanga)

Para ejecutar la simulación:

`time ./wcd -m input.in`


8. Revisar y analizar los histogramas obtenidos con 10000 partículas. 
