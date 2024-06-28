# GUI

[![CI GUI][ci-gui-badge]][ci-gui]


## Usage

### Build

```bash
$> cd App/GUI
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
$> ./zappy_gui -p [port] -h [host]
[...]
```
> ```port``` is the port number to connect to the server.
> 
> ```host``` is the host name or IP address of the server.


## Informations

The GUI client’s connection to the server happens as follows:

    1. the client opens a socket on the server’s port,

    2. the server and the client communicate the following way:
        Server --> WELCOME\n
               <-- GRAPHIC\n
               --> game informations (see the above array)


## Protocol

| SYMBOL |               MEANING               |
|:------:|:-----------------------------------:|
|   X    |    width or horizontal position     |
|   Y    |     height or vertical position     |
|   q0   |     resource 0 (food) quantity      |
|   q1   |   resource 1 (linemate) quantity    |
|   q2   |   resource 2 (deraumere) quantity   |
|   q3   |     resource 3 (sibur) quantity     |
|   q4   |   resource 4 (mendiane) quantity    |
|   q5   |    resource 5 (phiras) quantity     |
|   q6   |   resource 6 (thystame) quantity    |
|   n    |            player number            |
|   O    | orientation: 1(N), 2(E), 3(S), 4(W) |
|   L    |     player or incantation level     |
|   e    |             egg number              |
|   T    |              time unit              |
|   N    |          name of the team           |
|   R    |         incantation result          |
|   M    |               message               |
|   i    |          resource  number           |


|                   SERVER                   |  CLIENT   |                    DETAILS                    |                    TO A GUI client                     |                        TO ALL GUI client                        |
|:------------------------------------------:|:---------:|:---------------------------------------------:|:------------------------------------------------------:|:---------------------------------------------------------------:|
|                 msz X Y\n                  |   msz\n   |                   map size                    |        new GUI client connection or msz command        |                                                                 |
|       bct X Y q0 q1 q2 q3 q4 q5 q6\n       | bct X Y\n |               content of a tile               |                      bct command                       |                                                                 |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles |   mct\n   |      content of the map (all the tiles)       | new GUI client connection or mct command or map refill |                                                                 |
|            tna N\n * nbr_teams             |   tna\n   |             name of all the teams             |               new GUI client connection                |                                                                 |
|             pnw #n X Y O L N\n             |           |          connection of a new player           |               new GUI client connection                |                    new AI client connection                     |
|               ppo n X Y O\n                | ppo #n\n  |               player’s position               |                      ppo command                       |         AI left, right forward action or AI is ejected          |
|                 plv n L\n                  | plv #n\n  |                player’s level                 |        new GUI client connection or plv command        |                    AI sucessfully incantate                     |
|      pin n X Y q0 q1 q2 q3 q4 q5 q6\n      | pin #n\n  |              player’s inventory               |        new GUI client connection or pin command        | new AI client connection or AI set, take action or AI lost food |
|                  pex n\n                   |           |                   expulsion                   |                                                        |                         AI eject action                         |
|                 pbc n M\n                  |           |                   broadcast                   |                                                        |                       AI broadcast action                       |
|            pic X Y L n n ...\n             |           | start of an incantation (by the first player) |                                                        |                      AI incantation action                      |
|                pie X Y R\n                 |           |             end of an incantation             |                                                        |                        AI incatation end                        |
|                  pfk n\n                   |           |           egg laying by the player            |                                                        |                         AI fork action                          |
|                 pdr n i\n                  |           |               resource dropping               |                                                        |                          AI set action                          |
|                 pgt n i\n                  |           |              resource collecting              |                                                        |                         AI take action                          |
|                  pdi n\n                   |           |               death of a player               |                                                        |        AI client disconnection or AI lost all it's food         |
|               enw e n X Y\n                |           |          an egg was laid by a player          |               new GUI client connection                |                 AI fork action end (after 42/f)                 |
|                  ebo e\n                   |           |         player connection for an egg          |                                                        |                    new AI client connection                     |
|                  edi e\n                   |           |                death of an egg                |                                                        |                     egg is ejected by an AI                     |
|                  sgt T\n                   |   sgt\n   |               time unit request               |            new GUI client connection or sgt            |                           sst command                           |
|                  sst T\n                   |  sst T\n  |            time unit modification             |                                                        |                                                                 |
|                  seg N\n                   |           |                  end of game                  |                                                        |             an AI team reach the victory conditions             |
|                  smg M\n                   |           |            message from the server            |                                                        |                      server send a message                      |
|                   suc\n                    |           |                unknown command                |                                                        |                    empty or unknown command                     |
|                   sbp\n                    |           |               command parameter               |                                                        |              invalide command (wrong parameter.s)               |
|                  eht e\n                   |           |                 egg is mature                 |               new GUI client connection                |    server create an egg or egg create by an AI become mature    |

[ci-gui]: https://github.com/Periicles/Zappy/actions/workflows/GUI.yml
[ci-gui-badge]: https://github.com/Periicles/Zappy/actions/workflows/GUI.yml/badge.svg
