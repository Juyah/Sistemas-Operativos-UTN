#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "memoria_data_holder.h"

void abrir_archivo(uint32_t tamanio, int nroTablaNivel1, t_memoria_data_holder*);
void cerrar_archivo(uint32_t tamanio, t_memoria_data_holder*);
void crear_archivo_de_proceso(uint32_t tamanio, int nroTablaNivel1, t_memoria_data_holder*);
void eliminar_archivo_de_proceso(int nroTablaNivel1, t_memoria_data_holder*);

#endif
