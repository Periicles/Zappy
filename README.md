# EPITECH | B-YEP-400 | Zappy

![Epitech](doc/png/Epitech_banner.png)

[![CI AI][ci-ai-badge]][ci-ai]
[![CI GUI][ci-gui-badge]][ci-gui]
[![CI SERVER][ci-server-badge]][ci-server]


## Description

The goal of this project is to create a network game where several teams confront on a tiles map
containing resources.
The winning team is the first one where at least 6 players who reach the maximum elevation.


## Prerequisites

- CMake 3.27
- C++20
- SFML 2.5.1
- Python 3.8


## Usage

### Build

```bash
$> make
[...]
```
> if it doesn't work, try the following command:
```bash
$> make re
[...]
```

### Run

>To see the usage of each program, go to the corresponding documentation:

[AI Documentation](App/AI/README.md) - 
[GUI Documentation](App/GUI/README.md) -
[Server Documentation](App/Server/README.md)

## Commit Norms

| Commit Type | Description                                                                                                               |
|:------------|:--------------------------------------------------------------------------------------------------------------------------|
| build       | Changes that affect the build system or external dependencies (npm, make, etc.)                                           |
| ci          | Changes related to integration files and scripts or configuration (Travis, Ansible, BrowserStack, etc.)                   |
| feat        | Addition of a new feature                                                                                                 |
| fix         | Bug fix                                                                                                                   |
| perf        | Performance improvements                                                                                                  |
| refactor    | Modification that neither adds a new feature nor improves performance                                                     |
| style       | Change that does not affect functionality or semantics (indentation, formatting, adding space, renaming a variable, etc.) |
| docs        | Writing or updating documentation                                                                                         |
| test        | Addition or modification of tests                                                                                         |

[ci-ai]: https://github.com/Periicles/Zappy/actions/workflows/AI.yml
[ci-ai-badge]: https://github.com/Periicles/Zappy/actions/workflows/AI.yml/badge.svg
[ci-gui]: https://github.com/Periicles/Zappy/actions/workflows/GUI.yml
[ci-gui-badge]: https://github.com/Periicles/Zappy/actions/workflows/GUI.yml/badge.svg
[ci-server]: https://github.com/Periicles/Zappy/actions/workflows/Server.yml
[ci-server-badge]: https://github.com/Periicles/Zappy/workflows/Server.yml/badge.svg
