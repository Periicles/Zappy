/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_look
*/

#include "Server/tools.h"

void cmd_look(const int fd)
{
    print_msg(fd, "[tile1, tile2, ...]\n");
}