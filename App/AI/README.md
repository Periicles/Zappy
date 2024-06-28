# AI

[![CI AI][ci-ai-badge]][ci-ai]

## Usage

### Build

```bash
$> cd App/AI
$> make
[...]
```
> if it doesn't work, try the following command:
```bash
$> make re
[...]
```

### Run

```bash 
$> ./zappy_ai -p port -n teamName -h host
    port		is the port number
    teamName	is the name of the team
    host		is the host name
```

## Informations

The AI client’s connection to the server happens as follows:

    1. the client opens a socket on the server’s port,

    2. the server and the client communicate the following way:
        Server --> WELCOME\n
               <-- TEAM-NAME\n
               --> game informations (see tha above array)

```X``` and ```Y``` indicate the world’s dimensions.

```CLIENT-NUM``` indicates the number of slots available on the server for the ```TEAM-NAME``` team.
If this number ```>= 1```, a new client can connect.

> The client can send up to 10 requests in a row without any response from the server. Over 10, the server will drop the incomming commands.

The server executes the client’s requests in the order they were received.

The requests are buffered and a command’s execution time only blocks the player in question.

Trantorians have adopted an international time unit. The time unit is seconds.

An action’s execution time is calculated with the following formula: ```action / f```


Where f is an integer representing the reciprocal (multiplicative inverse) of time unit.

For instance, if ```f=1```, “forward” takes ```7 / 1 = 7``` seconds.

By default ```f=100```.


## Protocol

Each player responds to the following actions and only to these, with the following syntax :

|            Action            |      Command       | Time limit |          Response          |
|:----------------------------:|:------------------:|:----------:|:--------------------------:|
|       move up one tile       |    __Forward__     |    7/f     |             ok             |
|        turn 90° right        |     __Right__      |    7/f     |             ok             |
|        turn 90° left         |      __Left__      |    7/f     |             ok             |
|         look around          |      __Look__      |    7/f     |     [tile1, tile2,...]     |
|          inventory           |   __Inventory__    |    1/f     | [linemate n, sibur n, ...] |
|        broadcast text        | __Broadcast text__ |    7/f     |             ok             |
| number of team unused slots  |  __Connect_nbr__   |     -      |           value            |
|        fork a player         |      __Fork__      |    42/f    |             ok             |
| eject players from this tile |     __Eject__      |    7/f     |           ok/ko            |
|      death of a player       |        _-_         |     -      |            dead            |
|        fork a player         |      __Fork__      |    42/f    |             ok             |
|         take object          |  __Take object__   |    7/f     |           ok/ko            |
|       set object down        |   __Set object__   |    7/f     |           ok/ko            |
|      start incantation       |  __Incantation__   |   300/f    |     Elevation underway     |

> In case of a bad/unknown command, the server must answer “ko”.

[ci-ai]: https://github.com/Periicles/Zappy/workflows/AI.yml
[ci-ai-badge]: https://github.com/Periicles/Zappy/actions/workflows/AI.yml/badge.svg
