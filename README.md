# Empotrados_ProyectoII

Segundo proyecto del curso de Sistemas Empotrados del primer semestre 2024.

## Project Setup

Academia collaboration project clone.
```bash
git clone https://github.com/mmongeo/academia-collaboration
```

Project creation.
```bash
instalation/simics-6.0.XXX/bin/project-setup
```
Add model to project.
```bash
instalation/simics-6.0.XXX//bin/project-setup --device image-capturing-device --ignore-existing-files
```
Make device.
```bash
make
```

## Simulation

Open simics and run pci setup.
```bash
./simics targets/qsp-x86/custom-target.simics
```

Runs simics commands to create device on simulation.
```simics
run-command-file targets/qsp-x86/icd.simics
```

## Simics' commands to remember

Clear terminal.
```simics
shell clear
```

Restart terminal.
```simics
restart-simics
```

List all available configuration classes.
```simics
list-classes ["substr"] [-l] [-m] 
```

List all modules that can be loaded into Simics.
```simics
list-modules ["substr"] [package-number] [-l] [-v] [thread-safe] 
```

Load the specified module.  By specifying class, the module implementing the specified class will be loaded.
```simics
load-module ("module"|"class") 
```

Read from a device register and return the value. The register argument is of the form device.bank.register.
```simics
get-device-reg "register" ["field"] [-l|-b]
```

Write data to a device register. The register argument is of the form device.bank.register.
```simics
set-device-reg "register" ["field"] data [-l|-b]
```

Quit simics
```simics
q
```

