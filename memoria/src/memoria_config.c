#include "memoria_config.h"

#include <stdlib.h>
#include <string.h>

#include "module_config.h"

struct t_memoria_config {
    char* IP_ESCUCHA;
    char* PUERTO_ESCUCHA;
    int TAM_MEMORIA;
    int TAM_PAGINA;
    int ENTRADAS_POR_TABLA;
    int RETARDO_MEMORIA;
    char* ALGORITMO_REEMPLAZO;
    int MARCOS_POR_PROCESO;
    int RETARDO_SWAP;
    char* PATH_SWAP;
    int KERNEL_SOCKET;
    int CPU_SOCKET;
};

static void __memoria_config_initializer(void* moduleConfig, t_config* tempCfg) {
    t_memoria_config* memoriaConfig = (t_memoria_config*)moduleConfig;
    memoriaConfig->IP_ESCUCHA = strdup(config_get_string_value(tempCfg, "IP_ESCUCHA"));
    memoriaConfig->PUERTO_ESCUCHA = strdup(config_get_string_value(tempCfg, "PUERTO_ESCUCHA"));
    memoriaConfig->TAM_MEMORIA = config_get_int_value(tempCfg, "TAM_MEMORIA");
    memoriaConfig->TAM_PAGINA = config_get_int_value(tempCfg, "TAM_PAGINA");
    memoriaConfig->ENTRADAS_POR_TABLA = config_get_int_value(tempCfg, "ENTRADAS_POR_TABLA");
    memoriaConfig->RETARDO_MEMORIA = config_get_int_value(tempCfg, "RETARDO_MEMORIA");
    memoriaConfig->ALGORITMO_REEMPLAZO = strdup(config_get_string_value(tempCfg, "ALGORITMO_REEMPLAZO"));
    memoriaConfig->MARCOS_POR_PROCESO = config_get_int_value(tempCfg, "MARCOS_POR_PROCESO");
    memoriaConfig->RETARDO_SWAP = config_get_int_value(tempCfg, "RETARDO_SWAP");
    memoriaConfig->PATH_SWAP = strdup(config_get_string_value(tempCfg, "PATH_SWAP"));
    memoriaConfig->KERNEL_SOCKET = -1;
    memoriaConfig->CPU_SOCKET = -1;
}

t_memoria_config* memoria_config_create(char* memoriaConfigPath, t_log* memoriaLogger) {
    t_memoria_config* self = malloc(sizeof(*self));
    config_init(self, memoriaConfigPath, memoriaLogger, __memoria_config_initializer);
    return self;
}

char* memoria_config_get_ip_escucha(t_memoria_config* self) {
    return self->IP_ESCUCHA;
}

char* memoria_config_get_puerto_escucha(t_memoria_config* self) {
    return self->PUERTO_ESCUCHA;
}

int memoria_config_get_tamanio_memoria(t_memoria_config* self) {
    return self->TAM_MEMORIA;
}

int memoria_config_get_tamanio_pagina(t_memoria_config* self) {
    return self->TAM_PAGINA;
}

int memoria_config_get_marcos_por_proceso(t_memoria_config* self) {
    return self->MARCOS_POR_PROCESO;
}

int memoria_config_get_entradas_por_tabla(t_memoria_config* self) {
    return self->ENTRADAS_POR_TABLA;
}

char* memoria_config_get_path_swap(t_memoria_config* self) {
    return self->PATH_SWAP;
}

int memoria_config_get_retardo_swap(t_memoria_config* self) {
    return self->RETARDO_SWAP;
}

int memoria_config_get_retardo_memoria(t_memoria_config* self) {
    return self->RETARDO_MEMORIA;
}

int memoria_config_get_procesos_totales(t_memoria_config* self) {
    return self->TAM_MEMORIA / (self->TAM_PAGINA * self->MARCOS_POR_PROCESO);
}

bool memoria_config_es_algoritmo_sustitucion_clock(t_memoria_config* self) {
    return strcmp(self->ALGORITMO_REEMPLAZO, "CLOCK") == 0;
}

bool memoria_config_es_algoritmo_sustitucion_clock_modificado(t_memoria_config* self) {
    return strcmp(self->ALGORITMO_REEMPLAZO, "CLOCK-M") == 0;
}
