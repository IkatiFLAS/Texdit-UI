# Arquitectura de Texdit-UI

## Componentes principales

### Buffer

Responsable de almacenar y modificar el texto cargado
en memoria.

### Cursor

Mantiene la posicion actual del usuario dentro del documento.

### Editor

Coordina el Buffer, Cursor y los modos del editor.

### Input 

Procesa las teclas y las convierte en acciones.

### Terminal 

Gestiona la terminal y el modo RAW.


## Flujo

- Archivo
|
|-- Buffer
|
|-- Editor
|
|-- Render
|
|-- Terminal

## Modos

### **Normal**

Modo de navegacion y comandos.

### **Insert** 

Modo de edicion del texto.

### **Visual**

Modo de seleccion.
