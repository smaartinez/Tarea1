#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "arraylist.h"

typedef struct 
{
    int idTicket;
    char descripcionProblema[100];
    int prioridad;
    char horaActual[20];
}Ticket;

void mostrarMenuInicial()
{
    puts("Bienvenido al Sistema de Gestion de Tickets");
    puts("=============================================");
    puts("1. Crear Ticket");
    puts("2. Asignar tipo de prioridad al ticket");
    puts ("3. Mostrar lista de tickets pendientes por resolver");
    puts ("4. Procesar siguiente ticket");
    puts("5. Buscar ticket por ID y mostrar sus detalles");
    puts("6. Salir del programa");

}

void asignarHora(Ticket *ticket)
{
    time_t aux;
    time(&aux);
    strftime(ticket->horaActual, sizeof(ticket->horaActual), "%H:%M:%S", localtime(&aux));
}

void limpiarTerminal()
{
    system("cls || clear");
}

void registrarTicket(List *listaTicketsBajo)
{
    Ticket *nuevoTicket = (Ticket *)malloc(sizeof(Ticket));
    printf("Ingrese el ID del ticket: ");
    scanf(" %d", &nuevoTicket->idTicket);
    printf("Ingrese la Descripcion del Ticket: ");
    scanf(" %[^\n]", nuevoTicket->descripcionProblema);
    asignarHora(nuevoTicket);
    nuevoTicket->prioridad = 3; 
    pushBack(listaTicketsBajo, nuevoTicket);
    system("cls || clear");
    puts("Ticket ingresado con exito! Ingresado en la lista de Prioridad Baja\n\n");
    return;
}
    
void asignarTipoPrioridad(List *listaBajo, List *listaAlto, List *listaMedio)
{
    int Id;
    printf("Ingrese el ID del ticket a asignar prioridad: ");
    scanf("%d", &Id);

    Ticket *ticketAuxiliar = first(listaBajo);
    while (ticketAuxiliar != NULL && ticketAuxiliar->idTicket != Id)
    {
        ticketAuxiliar = next(listaBajo);
    }

    if (ticketAuxiliar == NULL)
    {
        puts("No se encontro el ticket con el ID ingresado.\n");
        return;
    }
    else 
    {
        int newPrioridad;
        puts("Seleccione la nueva prioridad del ticket:");
        puts("1. Alta");
        puts("2. Media");
        puts("3. Baja");
        scanf("%d", &newPrioridad);
        ticketAuxiliar->prioridad = newPrioridad;

        if (newPrioridad == 1)
        {
            pushBack(listaAlto, ticketAuxiliar);
            popCurrent(listaBajo);
            system("cls || clear");
            printf("Ticket con ID %d asignado a la lista de prioridad alta.\n\n", ticketAuxiliar->idTicket);
        }
        else if (newPrioridad == 2)
        {
            pushBack(listaMedio, ticketAuxiliar);
            popCurrent(listaBajo);
            system("cls || clear");
            printf("Ticket con ID %d asignado a la lista de prioridad media.\n\n", ticketAuxiliar->idTicket);
        }
        else if (newPrioridad == 3)
        {
            pushBack(listaBajo, ticketAuxiliar);
            popCurrent(listaBajo);
            system("cls || clear");
            printf("Ticket con ID %d reasignado a la lista de prioridad baja.\n\n", ticketAuxiliar->idTicket);
        }
        else
        {
            system("cls || clear");
            puts("Prioridad no valida. Por favor, intente nuevamente.\n\n");
            return;
        }
    }
}


void mostrarListaPendientes(List *listaBajo, List *listaAlto, List *listaMedio)
{
    puts("Lista de Tickets sin Atender:");
    puts("===================================");
    printf("Tickets Pendientes con Prioridad Alta:\n");
    Ticket *ticketAuxiliar = (Ticket *)malloc(sizeof(Ticket));
    ticketAuxiliar = first(listaAlto);
    while (ticketAuxiliar != NULL)
    {
        printf("ID: %d\n", ticketAuxiliar->idTicket);
        printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
        printf("Hora de ingreso: %s\n\n", ticketAuxiliar->horaActual);
        ticketAuxiliar = next(listaAlto);
    }
    printf("Tickets Pendientes con Prioridad Media:\n");
    ticketAuxiliar = (Ticket *)malloc(sizeof(Ticket));
    ticketAuxiliar = first(listaMedio);
    while (ticketAuxiliar != NULL)
    {
        printf("ID: %d\n", ticketAuxiliar->idTicket);
        printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
        printf("Hora de ingreso: %s\n\n", ticketAuxiliar->horaActual);
        ticketAuxiliar = next(listaMedio);
    }
    printf("Tickets Pendientes con Prioridad Baja:\n");
    ticketAuxiliar = (Ticket *)malloc(sizeof(Ticket));
    ticketAuxiliar = first(listaBajo);
    while (ticketAuxiliar != NULL)
    {
        printf("ID: %d\n", ticketAuxiliar->idTicket);
        printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
        printf("Hora de ingreso: %s\n\n", ticketAuxiliar->horaActual);
        ticketAuxiliar = next(listaBajo);
    }
    printf("===================================\n");
    free(ticketAuxiliar);
    printf("\n");
}

void buscarticketId(List *listaBajo, List *listaAlto, List *listaMedio)
{
    int Id;
    printf("Ingrese el ID del ticket a buscar: ");
    scanf("%d", &Id);
    Ticket *ticketAuxiliar = (Ticket *)malloc(sizeof(Ticket));
    ticketAuxiliar = first(listaAlto);
    while (ticketAuxiliar != NULL)
    {
        if (ticketAuxiliar->idTicket == Id)
        {
            printf("Ticket encontrado en la lista de prioridad alta:\n");
            printf("ID: %d\n", ticketAuxiliar->idTicket);
            printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
            printf("Hora de ingreso: %s\n\n", ticketAuxiliar->horaActual);
            return;
        }
        ticketAuxiliar = next(listaAlto);
    }
    ticketAuxiliar = first(listaMedio);
    while (ticketAuxiliar != NULL)
    {
        if (ticketAuxiliar->idTicket == Id)
        {
            printf("Ticket encontrado en la lista de prioridad media:\n");
            printf("ID: %d\n", ticketAuxiliar->idTicket);
            printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
            printf("Hora de ingreso: %s\n\n", ticketAuxiliar->horaActual);
            return;
        }
        ticketAuxiliar = next(listaMedio);
    }
    ticketAuxiliar = first(listaBajo);
    while (ticketAuxiliar != NULL)
    {
        if (ticketAuxiliar->idTicket == Id)
        {
            printf("Ticket encontrado en la lista de prioridad baja:\n");
            printf("ID: %d\n", ticketAuxiliar->idTicket);
            printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
            printf("Hora de ingreso: %s\n\n", ticketAuxiliar->horaActual);
            return;
        }
        ticketAuxiliar = next(listaBajo);
    }
    puts("No se encontro el ticket con el ID ingresado.\n\n");
    free(ticketAuxiliar);
    return;
}

void atenderSiguiente(List *listaBajo, List *listaAlto, List *listaMedio)
{
    Ticket *ticketAuxiliar = (Ticket *)malloc(sizeof(Ticket));
    ticketAuxiliar = first(listaAlto);
    if (ticketAuxiliar != NULL)
    {
        printf("Atendiendo con ID: %d\n", ticketAuxiliar->idTicket);
        printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
        printf("Hora de ingreso: %s\n", ticketAuxiliar->horaActual);
        printf("Ticket atendido con exito!\n");
        printf("===================================\n\n");
        popCurrent(listaAlto);
    }
    else
    {
        ticketAuxiliar = first(listaMedio);
        if (ticketAuxiliar != NULL)
        {
            printf("Atendiendo ticket con ID: %d\n", ticketAuxiliar->idTicket);
            printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
            printf("Hora de ingreso: %s\n", ticketAuxiliar->horaActual);
            popCurrent(listaMedio);
            printf("Ticket atendido con exito!\n");
            printf("===================================\n\n");
        }
        else
        {
            ticketAuxiliar = first(listaBajo);
            if (ticketAuxiliar != NULL)
            {
                printf("Atendiendo ticket con ID: %d\n", ticketAuxiliar->idTicket);
                printf("Descripcion: %s\n", ticketAuxiliar->descripcionProblema);
                printf("Hora de ingreso: %s\n", ticketAuxiliar->horaActual);
                popCurrent(listaBajo);
                printf("Ticket atendido con exito!\n");
            printf("===================================\n\n");
            }
            else
            {
                puts("No hay tickets pendientes por atender.\n\n");
            }
        }
    }
    free(ticketAuxiliar);
}   

int main ()
{
    limpiarTerminal();
    List *listaTicketsAlto = create_list();
    List *listaTicketsMedio = create_list();
    List *listaTicketsBajo = create_list();
    int opcionSeleccionada;
    do
    {
        mostrarMenuInicial();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcionSeleccionada);
        switch (opcionSeleccionada)
        {
            case 1:
                system("cls || clear");    
                registrarTicket(listaTicketsBajo);
                break;
            case 2:
                system("cls || clear");
                asignarTipoPrioridad(listaTicketsBajo, listaTicketsAlto, listaTicketsMedio);
                break;
            case 3:
                system("cls || clear");
                mostrarListaPendientes(listaTicketsBajo, listaTicketsAlto, listaTicketsMedio);
                break;
            case 4:
                system("cls || clear");
                atenderSiguiente(listaTicketsBajo, listaTicketsAlto, listaTicketsMedio);
                break;
            case 5:
                system("cls || clear");
                buscarticketId(listaTicketsBajo, listaTicketsAlto, listaTicketsMedio);
                break;
            case 6:
                system("cls || clear");
                puts("Saliendo del programa. Gracias por usar el sistema de gestion de tickets.");
                break;
            default:
                puts("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcionSeleccionada != 6);
    
    return 0;
}
