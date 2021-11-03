/* file command.h */
/* file berisi header untuk setiap command dalam game */

#include "../ADT/gameState.h"

void command_BUY(gameState* status);

void command_DROP_OFF(gameState* status);

void command_HELP();

void command_IN_PROGRESS(gameState status);

void command_INVENTORY(gameState* status);

void command_MAP(gameState status);

void command_MOVE(gameState* status);

void command_PICK_UP(gameState* status);

void command_TO_DO(gameState* status);