# Taller 2 Estructura de Datos

Clasificación automática de pacientes mediante un **árbol de decisión** y almacenamiento en **árboles AVL** según el servicio asignado (Hospital Marmaja).

## Autores

- **Patricio Javier Vidal Veas** - 22.330.827-9 - [patriciovidal01-hub] - Carrera: ICCI - Paralelo: C2
- **Vicente Antonio Garriga Muñoz** - 22.380.392-k - [vicentegarriga-stack] - Carrera: ICCI - Paralelo: C2
- **Martín Ignacio Alvarado Lafferte** - 22.330.833-3 - [Martinooski] - Carrera: ICCI - Paralelo: C2

## Árbol de decisión

El sistema hospitalario utiliza un árbol binario de decisión para clasificar automáticamente a los pacientes en uno de los ocho servicios disponibles.

Cada nodo interno representa una condición que evalúa un atributo del paciente. Si la condición se cumple, se continúa por la rama izquierda (Sí); en caso contrario, se continúa por la rama derecha (No).

El proceso termina al alcanzar un nodo hoja, que contiene el nombre del servicio asignado.

### Estructura del árbol

```text
¿Dolor >= 8?
|-- Si: Urgencias
|
|-- No:
    ¿Edad <= 14?
    |-- Si: Pediatria
    |
    |-- No:
        ¿PresionArterial > 140?
        |-- Si: Cardiologia
        |
        |-- No:
            ¿Trauma == 1?
            |-- Si:
            |   ¿RequiereCirugia == 1?
            |   |-- Si: Cirugia
            |   |-- No: Traumatologia
            |
            |-- No:
                ¿SintomasNeurologicos == 1?
                |-- Si: Neurologia
                |
                |-- No:
                    ¿DiasHospitalizacion >= 2?
                    |-- Si: Hospitalizacion
                    |-- No: Medicina General
```

### Justificación de las decisiones

1. **Dolor >= 8 — Urgencias:** Se priorizan los pacientes que presentan un nivel de dolor elevado, asignándolos directamente al servicio de Urgencias.

2. **Edad <= 14 — Pediatría:** Los pacientes de hasta 14 años que no hayan sido clasificados en Urgencias son derivados al servicio de Pediatría.

3. **Presión arterial > 140 — Cardiología:** Los pacientes que superan el umbral de presión arterial definido por el grupo son enviados a Cardiología, siempre que no hayan sido clasificados previamente.

4. **Trauma == 1 — Traumatología o Cirugía:** Cuando un paciente presenta un trauma, se evalúa si requiere una intervención quirúrgica. Si `RequiereCirugia == 1`, se deriva a Cirugía; en caso contrario, a Traumatología.

5. **SintomasNeurologicos == 1 — Neurología:** Los pacientes que presentan síntomas neurológicos y no han sido asignados a otro servicio son derivados a Neurología.

6. **DiasHospitalizacion >= 2 — Hospitalización:** Los pacientes que requieren al menos dos días estimados de hospitalización son enviados a este servicio, siempre que no cumplan las condiciones anteriores.

7. **Medicina General:** Se utiliza como servicio predeterminado para los pacientes que no cumplen ninguna de las condiciones anteriores.

### Consideraciones

- El árbol de decisión utiliza siete atributos del paciente: dolor, edad, presión arterial, trauma, requerimiento de cirugía, síntomas neurológicos y días de hospitalización.

- El orden de evaluación determina la prioridad de clasificación. Por ejemplo, un paciente de 10 años con dolor de nivel 9 será enviado a Urgencias y no a Pediatría, porque el dolor se evalúa primero.

- Cada paciente sigue una única ruta desde la raíz hasta un nodo hoja, obteniendo un servicio correspondiente.

- Los datos se validan durante la lectura del archivo, antes de ingresar a la cola. Los registros que no superan las validaciones implementadas son rechazados.

- Los criterios y umbrales fueron definidos por el grupo para la simulación académica del sistema hospitalario y no constituyen un protocolo médico de clasificación real.

## Ejecución y compilación

1. Crear un codespace de la rama principal (`main`).
2. Compilar el programa mediante el siguiente comando:

   ```bash
   g++ -std=c++17 *.cpp -o hospital
   ```

   Para correr el programa en cualquier momento ocupa:

   ```bash
   ./hospital
   ```

3. ¡Disfruta de tu código!
