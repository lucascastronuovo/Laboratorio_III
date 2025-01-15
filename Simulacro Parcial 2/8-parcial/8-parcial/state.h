#define MESSAGE_QUEUE_FILE "/bin/ls"
#define MESSAGE_QUEUE_INT 48

#define MEMORY_FILE "/bin/ls"
#define MEMORY_INT 40

#define TEXT_LENGTH 100
#define PLAYERS_LENGTH 2
#define GOAL 100

typedef enum { SUBJECT_NULL, SUBJECT_RACE, SUBJECT_PLAYER } Subjects;

typedef enum { EVENT_NULL, EVENT_INIT, EVENT_END } Events;

typedef struct {
    int number;
    int steps;
    int stops;
    int position;
    int messageQueueID;
} Player;

typedef struct {
    Player *players;
} Race;
