# Server

[![CI SERVER](https://github.com/Periicles/Zappy/actions/workflows/Server.yml/badge.svg)](https://github.com/Periicles/Zappy/actions/workflows/Server.yml)


## Description

A server, created in C, that generates the inhabitants’ world.

The server is executed in the form of one, single process and one, single thread.
It must use select to handle socket multiplexing; the select must unlock only if something happen on a
socket or if an event is ready to be executed.


## Usage

### Build

```bash
$> cd App/Server
$> ./build.sh build
[...]
```
> if it doesn't work, try the following command:
```bash
$> ./build.sh clean && ./build.sh build
[...]
```

### Run

```bash 
$> ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
	port		is the port number
	width		is the width of the world
	height		is the height of the world
	nameX		is the name of the team X
	clientsNb	is the number of authorized clients per team
	freq		is the reciprocal of time unit for execution of actions
```


## Informations

> The team name GRAPHIC is reserved for the GUI to authenticate itself as such to the server.

### Incantations

This ritual, which augments physical and mental capacities, must be done according to a particular rite: they
must gather the following on the same unit of terrain:

- At least a certain number of each stones
- At least a certain number of players with the same level

The elevation begins as soon as a player initiates the incantation.
The player who starts an incantation will receive ko if all the requirements are not satisfied and the incantation will be canceled,
the player will receive the ko instantly after the initial server check (not at the end of the incantation duration).

which means that it will make the next action received by the server.

It is not necessary for the players to be on the same team; they only need to be of the same level.
Every player with the corresponding level and present at the beginning and at the end of the incantation attain the higher level.

During the incantation, the participants can not make any action until the end of the rite.

At the end of the incantation, the exact quantity of resources needed by the rite are consumed.
