#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<math.h>

char modo_ejecucion;

/* Variables Globales */
char sentido_puente;
unsigned int largo_puente;
unsigned short k;
unsigned short tiempo_semaforo;
float v_promedio;
unsigned int media_vehiculos;

//Creacion de thread
pthread_t tabla_threads[100];

//Declaracion de mutex
static pthread_mutex_t candado;

//Estructura para los carros
typedef struct{
	int id;
	//char *nombre_carro; //Persona que lo conduce, podriamos poner nombres de conocidos y comparar en varias corridas
	char *lado_puente; //Oeste o Este
	int prioridad; // Si es ambulancia(prioridad 1), auto normal(prioridad 2)
} thr_param_t;

void *pasarPuente(thr_param_t *carro) {
	
    pthread_mutex_lock(&candado);

    //unsigned int tcruzar = 0;

    //for(int i=0; i<=tcruzar;i++);
    
    printf("\n Se cruzo puente desde %s, identificador %d, con una prioridad de %d\n",
			carro->lado_puente, carro->id, carro->prioridad);

    pthread_mutex_unlock(&candado);
    
    pthread_exit(&(carro->id));

    return NULL;
}


int main(void)
{
    //int err;

    /*if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    //generador de tiempos para media de vehiculos 
    x = numero random con distribucion exponencial
    u = numero random con distribucion uniforme*/
    //double x;
    //double u;
    media_vehiculos = 15;
    thr_param_t tabla_parametros[media_vehiculos];
    
    //Se crean los threads
    int i;
    for(i = 0; i <= media_vehiculos; i = i +1)
    {
		tabla_parametros[i].id = i;
		int lado = rand() % 11;
		lado = lado % 2;
		if(lado == 0)
		{
			tabla_parametros[i].lado_puente = strdup("Oeste");
		}
		else
		{
			tabla_parametros[i].lado_puente = strdup("Este");
		}
		
		int prioridad = rand() % 100;
		if(prioridad > 60)
		{
			tabla_parametros[i].prioridad = 1;
		}
		else
		{
			tabla_parametros[i].prioridad = 2;
		}
		
		pthread_create(&tabla_threads[i], NULL, (void*)&pasarPuente, (void*)&tabla_parametros[i]);
		
	}
	
	
    
    
    //int i;
    
    //Leer parametros desde archivo
    /*
    char lectura[80];
    FILE *archivo = fopen("parametros.txt", "r");
    
    if(archivo == NULL) return -1;
    
    fscanf(archivo, " %s\n", lectura);
    printf("Lectura %s\n", lectura);
    */

    /*srand(time(NULL));

    for (i=0; i < media_vehiculos; i++) {
        u = (double) rand() / (double) RAND_MAX;
        x = (double) log(1-u) / (double) -(1.00 / media_vehiculos);
        printf("%0.2f\t", x);
    }
    printf("\n");*/
    /*while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }*/

    /*pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);*/

    return 0;
}
