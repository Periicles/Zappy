/*
** EPITECH PROJECT, 2024
** Server
** File description:
** player
*/

#include <stdlib.h>
#include <stdio.h>

#include "Server/Game/game.h"
#include "Server/Game/player.h"
#include "Server/Game/clock.h"
#include "Server/tools.h"

player_t *create_player(
    char *team_name,
    game_t *game,
    position_t position,
    int fd)
{
    player_t *new_player = malloc(sizeof(player_t));

    if (!new_player)
        return NULL;
    game->index_client++;
    new_player->id = game->index_client;
    new_player->level = 1;
    new_player->fd_client = fd;
    new_player->team_name = team_name;
    new_player->position = position;
    new_player->direction = NORTH;
    for (int i = 0; i < COUNT; i++) {
        new_player->resources[i].quantity = 0;
    }
    new_player->resources[FOOD].quantity = 10;
    new_player->clock = game->clock;
    new_player->action_queue = NULL;
    new_player->action_queue_tail = NULL;
    return new_player;
}

action_t *create_action(action_type_t type, int duration, char *msg, int freq)
{
    action_t *new_action = malloc(sizeof(action_t));
    server_clock_t *clock = malloc(sizeof(server_clock_t));
    struct timespec start_time = {0};

    if (!new_action || !clock) {
        return NULL;
    }
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    new_action->clock = clock;
    new_action->clock->freq = freq;
    new_action->clock->value = start_time;
    new_action->type = type;
    new_action->duration = duration;
    new_action->msg = msg;
    new_action->next = NULL;
    return new_action;
}

void add_action_to_player(
    player_t *player,
    action_type_t type,
    char *msg,
    int duration)
{
    action_t *new_action =
        create_action(type, duration, msg, player->clock->freq);

    if (!new_action) {
        return;
    }
    if (!player->action_queue) {
        player->action_queue = new_action;
        player->action_queue_tail = new_action;
    } else {
        player->action_queue_tail->next = new_action;
        player->action_queue_tail = new_action;
    }
}

void execute_player_action(player_t *player)
{
    action_t *current_action;

    if (!player->action_queue) {
        return;
    }
    current_action = player->action_queue;
    print_msg(player->fd_client, current_action->msg);
    player->action_queue = current_action->next;
    if (!player->action_queue) {
        player->action_queue_tail = NULL;
    }
    free(current_action);
}

bool is_current_action_done(player_t *player)
{
    int ticks_elapsed = 0;

    if (!player->action_queue) {
        return true;
    }
    ticks_elapsed = get_ticks_elapsed(player->action_queue->clock);
    if (ticks_elapsed < 0) {
        return false;
    }
    if (ticks_elapsed >= player->action_queue->duration) {
        return true;
    }
    return false;
}
