1. En su contenedor, clonar el repositorio de la barra centelladora de MuTe:

`git clone https://github.com/adrianacvr/Simulacion-barra-MuTe.git`

2. Crear y entrar en la carpeta donde va a compilar el código:

`mkdir barra`

`cd barra`

4. Compilar:

`cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../Simulacion-barra-MuTe/; make -j2;`

6. Ejecutar el programa para visualizar la barra:

`./bar`

8. Lanzar una simulación de prueba:

`./bar -m input.in`

10. Revisar los histogramas de "scintbar.root":

`root`

`new TBrowser`


## Tarea: 
1. Lanzar 100 mu- de 1 GeV en los dos extremos de la barra (2 cm y 118 cm).
2. Lanzar 100 e- de 1 GeV en los dos extremos de la barra (2 cm y 118 cm).
3. Analizar las diferencias entre los histogramas de cada caso.
