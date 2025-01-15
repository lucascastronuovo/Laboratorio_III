#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "./../../libs/random.h"
#include "./../../libs/key.h"
#include "./../../libs/memory.h"
#include "./../../libs/messages.c"
#include "./state.h"

int messageQueueID;

void startGame(){
    int i;

    for(i = 0; i < PLAYERS_LENGTH; i++){
        Message message;

        message.recieverID = SUBJECT_PLAYER + i;
        message.senderID = SUBJECT_RACE;
        message.eventID = EVENT_INIT;
        strcpy(message.content, "");

        sendMessage(messageQueueID, message);//a
    }
}

void *display(void *parametro) {
    Race *race = (Race *)parametro;

    int i;

    while(1){
        system("clear");

        for(i = 0; i < PLAYERS_LENGTH; i++){
            printf("Jugador %d con %d pasos\n", race->players[i].number, race->players[i].steps);
        }

        usleep(1000 * 100);
    }
}

int main(int argc, char* argv[]) {
    key_t key = createKey(MESSAGE_QUEUE_FILE, MESSAGE_QUEUE_INT);
    messageQueueID = createMessageQueue(key);

    int option = 0;

    printf("Presione una tecla para empezar el juego...\n");
    scanf("%d", &option);

    startGame();

    pthread_t threadID;
    pthread_attr_t atributos;

    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);
    
    int memoryID;
    Player *players = (Player*)createSharedMemory(sizeof(Player) * PLAYERS_LENGTH, &memoryID, createKey(MEMORY_FILE, MEMORY_INT));

    Race race;
    race.players = players;

    if (pthread_create(&threadID, &atributos, display, &race) != 0) {
        perror("No puedo crear thread\n");
        exit(-1);
    }

    Message message;
    recieveMessage(messageQueueID, SUBJECT_RACE, &message);

    if (message.eventID == EVENT_END) {
        pthread_cancel(threadID);
        system("clear");
        printf("Termino la carrera y gano el jugador %s\n", message.content);
    }
};
