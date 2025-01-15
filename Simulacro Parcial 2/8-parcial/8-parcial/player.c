#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../../libs/random.h"
#include "./../../libs/key.h"
#include "./../../libs/messages.c"
#include "./../../libs/memory.h"
#include "./state.h"

pthread_mutex_t mutex;
int position = 0;

void *player(void *parametro) {
    Player *player = (Player *)parametro;

    printf("Soy el jugador %d y existo\n", player->number);

    Message message;
    recieveMessage(player->messageQueueID, SUBJECT_PLAYER + player->number,
                   &message);

    if (message.eventID == EVENT_INIT) {
        if (player->number == 0) {
            while (player->steps < GOAL) {
                int steps = randomNumberWaiting(1, 5);
                player->steps = player->steps + steps;

                int stops = player->steps / 50;

                if (stops > player->stops) {
                    player->stops = player->stops + 1;
                    usleep(1000 * 5000);
                }

                printf("Jugador %d da %d pasos\n", player->number, steps);
                usleep(1000 * 100);
            }
        }

        if (player->number == 1) {
            while (player->steps < GOAL) {
                int steps = randomNumberWaiting(1, 5);
                player->steps = player->steps + steps;

                printf("Jugador %d da %d pasos\n", player->number, steps);
                usleep(1000 * 500);
            }
        }
    }

    player->position = position;
    position++;

    pthread_exit((void *)"Termino");
}

void endGame(int messageQueueID, int playerID){
    Message message;

    char content[TEXT_LENGTH] = "";
    sprintf(content, "%d", playerID);

    message.recieverID = SUBJECT_RACE;
    message.senderID = SUBJECT_PLAYER;
    message.eventID = EVENT_END;
    strcpy(message.content, content);

    sendMessage(messageQueueID, message);
}

int main() {
    key_t key = createKey(MESSAGE_QUEUE_FILE, MESSAGE_QUEUE_INT);
    int messageQueueID = createMessageQueue(key);

    int memoryID;
    Player *players = (Player*)createSharedMemory(sizeof(Player) * PLAYERS_LENGTH, &memoryID, createKey(MEMORY_FILE, MEMORY_INT));

    pthread_t *threadID =
        (pthread_t *)malloc(sizeof(pthread_t) * PLAYERS_LENGTH);
    pthread_attr_t atributos;
    int i;
    char *valorDevuelto = NULL;

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < PLAYERS_LENGTH; i++) {
        players[i].number = i;
        players[i].steps = 0;
        players[i].stops = 0;
        players[i].position = 0;
        players[i].messageQueueID = messageQueueID;

        int created =
            pthread_create(&threadID[i], &atributos, player, &players[i]);

        if (created != 0) {
            printf("No puedo crear el thread\n");
            exit(-1);
        }
    }

    printf("Espero a los jugadores\n");

    for (i = 0; i < PLAYERS_LENGTH; i++) {
        pthread_join(threadID[i], (void **)&valorDevuelto);
    }

    printf("Terminaron todos los jugadores\n");

    int winner = -1;

    for (i = 0; i < PLAYERS_LENGTH; i++) {
        if(players[i].position == 0){
            winner = players[i].number;
        }
    }

    endGame(messageQueueID, winner);//

    return 0;
}
