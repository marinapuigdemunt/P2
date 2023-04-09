PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
	-	Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.

	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual, usando el repositorio remoto en GitHub como repositorio central para el trabajo colaborativo
	de los distintos miembros del grupo de prácticas o como copia de seguridad.
	-	Puede *confirmar* versiones del proyecto en su directorio local con las órdenes siguientes:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

	-	Las versiones confirmadas, y sólo ellas, se almacenan en el repositorio y pueden ser accedidas en cualquier momento.

*	Para interactuar con el contenido remoto en GitHub es necesario que los cambios en el directorio local estén confirmados.

	-	Puede comprobar si el directorio está *limpio* (es decir, si la versión actual está confirmada) usando el comando
		`git status`.

	-	La versión actual del directorio local se sube al repositorio remoto con la orden:

		```.sh
		git push
		```

		*	Si el repositorio remoto contiene cambios no presentes en el directorio local, `git` puede negarse
			a subir el nuevo contenido.

			-	En ese caso, lo primero que deberemos hacer es incorporar los cambios presentes en el repositorio
				GitHub con la orden `git pull`.

			-	Es posible que, al hacer el `git pull` aparezcan *conflictos*; es decir, ficheros que se han modificado
				tanto en el directorio local como en el repositorio GitHub y que `git` no sabe cómo combinar.

			-	Los conflictos aparecen marcados con cadenas del estilo `>>>>`, `<<<<` y `====`. Los ficheros correspondientes
				deben ser editados para decidir qué versión preferimos conservar. Un editor avanzado, del estilo de Microsoft
				Visual Studio Code, puede resultar muy útil para localizar los conflictos y resolverlos.

			-	Tras resolver los conflictos, se ha de confirmar los cambios con `git commit` y ya estaremos en condiciones
				de subir la nueva versión a GitHub con el comando `git push`.


	-	Para bajar al directorio local el contenido del repositorio GitHub hay que ejecutar la orden:

		```.sh
		git pull
		```
	
		*	Si el repositorio local contiene cambios no presentes en el directorio remoto, `git` puede negarse a bajar
			el contenido de este último.

			-	La resolución de los posibles conflictos se realiza como se explica más arriba para
				la subida del contenido local con el comando `git push`.



*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

Primeramente, hemos movido todos los ficheros necesarios de la práctica 1 al directorio de la 2. Entonces, situándonos en la nueva práctica, hemos obtenido dos ficheros con la información de la potencia de la señal y la tasa de cruces por cero. Para ello usamos los siguientes comandos:

- Potencia:  `./p1 pav_2341.wav | cut -f 2 > pav_2341_pot.pot`
- ZCR: `./p1 pav_2341.wav | cut -f 4 > pav_2341_zcr.pot`

Una vez hecho esto, accedemos a Wavesurfer y abrimos el fichero de audio de la señal a analizar. En la WaveForm, clicamos botón derecho con el ratón > create panel > transcription. A continuación, buscamos donde creemos que empieza la voz y clicamos botón derecho > insert label → Acabamos de determinar donde empieza la voz, así que el intervalo anterior era de silencio: Lo etiquetamos con una s. Continuamos así hasta llegar al final, etiquetando el silecio con 's' y la voz con 'v'. Durante el proceso cabe destacar que se ha tenido en cuenta que, si se trata de un segmento muy corto de silencio, es mejor no marcarlo con la s (podría causar problemas al posterior análisis de los segmentos). Para ello, seleccionando con el ratón nos dice cuanto dura. Hemos considerado 50ms como el umbral entre silencio o natural del habla.

Después clicamos botón derecho y seleccionamos **Create Panel → Data Plot**. Se nos crea un panel en blanco. Volvemos a hacer click derecho y esta vez seleccionamos **Open Data File** y abrimos el fichero donde se han guardado los datos de la potencia: `pav_2341_pot.pot`. 
A continuación hacemos lo mismo para visualizar la tasa de cruces por cero con el fichero: `pav_2341_zcr.pot`.

El resultado ha sido el siguiente:

<img width="1440" alt="image" src="https://github.com/marinapuigdemunt/P2/blob/dc0a4712ddf65aca2e2f51ed4948ba394f30e38c/wavesurfer_waveform_power_zcr.png">

La primera gráfica pertenece al waveform de la señal, la segunda a la potencia y la tercera a la ZCR.

Una vez finalizado el etiquetado, haciendo un cat del fichero en el terminal podemos ver su contenido:
```bash
judith@LAPTOP-RSBTF2ED:~/PAV/P2/senyals$ cat pav_2341.lab
0.0000000 0.5326841 S
0.5326841 0.8848719 V
0.8848719 0.9399013 S
0.9399013 1.2304562 V
1.2304562 1.2964915 S
1.2964915 1.6222652 V
1.6222652 1.9282284 S
1.9282284 3.8652615 V
3.8652615 4.0567500 S
```

- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

Primeramente, y para la correcta resolución de los siguientes apartados, hemos considerado necesario hacer un análisis de la señal de audio en cuestión. Analizando la señal entera, nos encontramos con los siguientes valores:

El punto con más potencia encontrado en un segmento de voz es de -17,92 dB:

<img width="1439" alt="Captura de pantalla 2023-03-18 a les 12 35 18" src="https://user-images.githubusercontent.com/125259984/226103140-3c75cf22-1611-4e6e-9fb3-04b7d6819f99.png">

El punto con menos potencia encontrado en un segmento de voz es de -59,84 dB, y se encuentra en el abismo de un segmento de voz, justo antes de pasar a considerarse silencio (mirar línea roja):

<img width="1259" alt="image" src="https://user-images.githubusercontent.com/125259984/226103737-b9051c4f-d185-47a7-afa0-681f3b634d27.png">

Por otra parte, el punto de menor potencia de silencio encontrado se da al inicio de la grabación y es de -142,04 dB:

<img width="1440" alt="image" src="https://user-images.githubusercontent.com/125259984/226105484-07d1aedb-496a-4b4b-ace7-89df551f796c.png">

Finalmente, el punto de mayor potencia de silencio encontrado es de -31,06 dB, y de nuevo se da al borde de cambiar de segmento, en este caso a uno de voz:

<img width="1440" alt="image" src="https://user-images.githubusercontent.com/125259984/226106735-48d5407e-f781-4f01-bb53-8750d70b63bc.png">

Una vez analizados tanto los máximos y mínimos de ambos tipos de segmento, como sus valores medios cuando se encuentran a mitad de un segmento (cuando es más claro si es silencio o voz), concluimos que acotar la voz a un rango de potencias de entre -20 dB y -30 dB, y el silencio a un rango de entre -60 dB y -100 dB es válido (aunque claramente haya 'outliers' o valores atípicos que se salgan de estos intevalos). Cogiendo entonces las medias de ambos segmentos:

- Media de la voz: -25 dB
- Media del silencio: -80 dB

Ahora ya podemos responder a las preguntas planteadas:

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
	  estar seguros de que un segmento de señal se corresponde con voz.
	  
Para responder a esta preguna, hemos hecho un zoom del segmento inicial en que el audio pasaba de silencio a voz:

<img width="1440" alt="image" src="https://user-images.githubusercontent.com/125259984/226103402-0dbde21c-790a-42ba-bba3-755697b093ec.png">

Deslizándonos al principio del audio en Wavesurfer, obtenemos que su potencias es de -142,04 dB (correspondiente al inicio del todo de la grabación, en silencio absoluto):

<img width="1437" alt="image" src="https://user-images.githubusercontent.com/125259984/226105666-35a6d6f9-08aa-476d-bf7e-0fc17856c1a5.png">

Este valor, de hecho, es el mínimo de potencia que el silencio alcanza en la señal entera, como se ha encontrado previamente.

Por otra parte, el primer segmento de voz empieza en -26,75 dB: 

<img width="1440" alt="image" src="https://user-images.githubusercontent.com/125259984/226105895-c44562d7-2150-4777-9873-bc10ae5c62d3.png">

Concluimos, entonces, que un incremento razonable de potencia respecto del silencio inicial para determinar que suena voz, sería de -26,75 - (-142,04) = **115,29 dB**.

	* Duración mínima razonable de los segmentos de voz y silencio.
	
Como se ha visto en el apartado anterior, para pasar de silencio absoluto a voz se requiere un aumento de potencia de más de 100 dB. Sin embargo, si calculamos este aumento analizando las medias obtenidas previamente: -25 - (-80) = 55 dB, vemos que el aumento es mucho menor. Esto se da debido a que el silencio dado entre dos palabras o frases no será igual de "silencioso" que el dado cuando aun no se ha empezado a hablar en sí. Es por ello que es muy importante entender que, si un segmento de silencio o voz es muy pequeño, éste probablemente nos dará valores de potencia poco realistas que nos estorbarán a la hora de obtener datos. De esta manera, analizando nuestra señal:

<img width="1440" alt="image" src="https://user-images.githubusercontent.com/125259984/226106554-94e164f3-d304-4810-9366-dd04b48bb9de.png">

Encontramos que segmentos como el anterior (que, como se nos mostraba en WaveSurfer, es de 60 ms), ya empiezan a dificultar la bajada de potencia. Consideramos, entonces, que 50 ms será un umbral suficientemente pequeño como para obtener todos los intervalos de voz y de silencio bien definidos, pero no tanto como para que se confunda los segmenos.

	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?

La tasa de cruces por cero es una medida útil para distinguir segmentos de voz de silencio en una señal de audio. Esta medida indica la cantidad de veces que la señal cambia de polaridad (de positivo a negativo o viceversa) por segundo.

En los segmentos de voz, la tasa de cruces por cero o ZCR suele ser alta debido a las vibraciones vocales que generan cambios rápidos de polaridad. En cambio, en los segmentos de silencio, la ZCR es baja porque la señal es plana y no hay cambios de polaridad significativos.

Además, sabemos que como los sonidos sordos se producen sin vibraciones en las cuerdas vocales no producen ondas sonoras continuas, por lo tanto, pasan muchas más veces por cero que los sonidos sonoros, los cuales si que generan ondas sonoras continuas. Por lo tanto, las partes que la ZCR sea más elevada se tratará de sonidos sordos.

Analizando la tasa de cruces por cero de nuestra señal de audio, se identifican los segmentos de voz como aquellos que presentan una tasa alta y los segmentos de silencio como aquellos que presentan una tasa bastante baja:

<img width="1437" alt="image" src="https://user-images.githubusercontent.com/125259984/226108281-23f466e2-6651-44b4-bf6f-a665ce6371c6.png">

Como se puede ver, la ZCR es más elevada en los segmentos de voz. Dentro de los segmentos de voz vemos que en las partes donde la ZCR es bastante más elevada corresponde a sonidos sordos, tal y como vemos a los 2 segundos donde aparece un pico bastante notable y si escuchamos el audio en ese instante nos damos cuenta que en ese momento se pronuncia la letra 's' que es un sonido sordo. También vemos que al inicio de la grabación la ZCR es mayoritariamente cero hasta que se empieza a hablar:

<img width="1429" alt="image" src="https://user-images.githubusercontent.com/125259984/226108330-8a408a1a-7641-4cd8-afe4-5ee37f178a72.png">


### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal en
  tiempo real tan exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.
  
  El código se encuentra en las carpetas src y scripts de este mismo respositorio.

- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 
  
  Como el audio utilizado en los apartados anteriores estaba "demasiado" bien grabado y como las primeras tramas tienen todas las muestras iguales a cero el nivel de ruido es menos infinito en dB (o algún valor extremadamente pequeño). Por ello, se ha ensuciado ligeramente la señal para que el resutado se vea mejor:
  
  ![image](https://user-images.githubusercontent.com/125259801/230765327-24b4bbaf-79db-40a3-a79e-41b74d427b40.png)

  ![image](https://user-images.githubusercontent.com/125259801/230765354-07ee26cc-66bd-4945-8929-4b13e8efb20e.png)

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.
  
<img width="804" alt="image" src="https://user-images.githubusercontent.com/125259984/230736245-4d397ee3-ac55-4f1b-9b52-db7e6a3cd1bc.png">

![image](https://user-images.githubusercontent.com/125259801/230765612-5ddb6e8f-deae-4616-8445-9bbf3043a1b9.png)

### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o parámetros alternativos, etc.).
  
 Hemos añadido un segundo umbral, alfa 1. Esto lo hemos hecho para separar los umbrales de voz y de silencio, de manera que el mínimo de voz no es directamente el máximo de silencio, y viceversa. Hemos considerado conveniente esta adición puesto que así obteníamos mejores resultados. El funcionamiento de ambos umbrales es el siguiente: Para pasar de  `VOICE` a `MAYBE SILENCE`, o de `SILENCE` a `MAYBE VOICE`, se requiere que la señal de audio en ese momento entre estrictamente en el rango de silencio o de voz respectivamente, de manera que si estamos en `VOICE`, por ejemplo, para pasar a `MAYBE SILENCE` se debe estar *por debajo* del máximo de silencio, pero si estamos en `VOICE` y en algún momento pasamos al intervalo que está por debajo del rango de voz, pero por encima del máximo de ruido, seguimos en voz (no se requiere estar en el rango estricto definido de voz o de silencio, simplemente no entrar en el rango estricto opuesto). De manera más visual, la máquina de estados seguida ha sido la siguiente:
  
  AQUI pondre foto del good notes
  
  ## Máquina de Estados

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.

