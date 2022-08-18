1. Iniciar un contenedor en su local o en obatala:

`docker start "docker_name"`

`docker exec -it "docker_name" bash`

2. Crear una carpeta nueva donde vamos a compilar la nueva versión del ejemplo B4a

`mkdir histos`

3. Modificar el archivo B4RunAction.cc

`cd B4a/src/`

`vim B4RunAction.cc`
    
    Dentro de B4RunAction.cc:
    
    `i` (para editar)
    
    Modificar los valores de los histogramas de la línea 64:
    
    // Creating histograms
    analysisManager->CreateH1("Eabs","Edep in absorber", 10000, 0.,100*MeV);
    analysisManager->CreateH1("Egap","Edep in gap", 10000, 0., 100*MeV);
    analysisManager->CreateH1("Labs","trackL in absorber", 1000, 0., 1*m);
    analysisManager->CreateH1("Lgap","trackL in gap", 1000, 0., 1*m);
    
    `:wq` (para guardar y salir de vim)

4. Compilar la nueva versión en la carpeta histos

`cd ../../histos/`

`cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../B4a/; make -j2;`

5. Modificar run2.mac para enviar 1000 gammas de 4 MeV

`./exampleB4a -m run2.mac`

6. Visualizar los histogramas de B4.root con la nueva resolución (número de bines)

`root`
`new TBrowser`
`.q`
