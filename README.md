# Mystery of the Forgotten Castle

## Overview

**Title:** Mystery of the Forgotten Castle  
**Genre:** Text-based Adventure / Puzzle Exploration  
**Platform:** Console (Terminal)  
**Language:** C++ (C++11 or later recommended)  
**Target Audience:** Gamers and developers interested in interactive storytelling and C++ fundamentals

## Game Concept

In *Mystery of the Forgotten Castle*, the player becomes an adventurer exploring an abandoned castle filled with secrets, puzzles, and hidden treasures. Navigate eerie corridors, solve puzzles, and make decisions that determine your fate.

## Story and Setting

### Story Background
- **Premise:**  
  The castle was once majestic until mysterious events caused its inhabitants to vanish. A cryptic letter draws you to the castle, promising danger and fortune.
- **Objective:**  
  Uncover the castle's secrets, solve puzzles, avoid traps, and choose your fate: escape with treasure, lift the curse, or become a part of the legend.

### Environment
- **Areas Include:**
  - Grand Entrance Hall
  - Dimly Lit Corridors
  - Secret Passages and Hidden Chambers
  - Trap-filled Dungeons
  - A Library with Cryptic Clues
  - A Tower or Rooftop for Final Confrontations
- **Atmosphere:**  
  Rich, descriptive text sets a mysterious, foreboding tone with details like creaking floors, cold stone, and flickering torchlight.

## Gameplay Mechanics

### Core Mechanics
- **Exploration:**  
  Navigate using commands like `go north` or `enter door`.
- **Interaction:**  
  Examine (`look`, `inspect`), collect (`take`), and use items (`use`).
- **Puzzle Solving:**  
  Combine items or solve riddles to unlock secrets.
- **Inventory System:**  
  Manage items crucial for progression.
- **Health/Status:**  
  Track health or sanity; negative events (traps, poor decisions) can affect your status.
- **Multiple Endings:**  
  Player choices determine different endings.

### Example Commands
- **Movement:**  
  `go north`, `go south`, `go east`, `go west`
- **Examine:**  
  `look at [object]`, `inspect [room/item]`
- **Interaction:**  
  `take [item]`, `use [item]`, `open [door/chest]`
- **Inventory:**  
  `inventory` to check collected items
- **Help:**  
  `help` to list available commands

## System Architecture

### Core Components
- **Game Engine/Main Loop:**  
  Processes user input, updates the game state, and outputs text.
- **Parser:**  
  Interprets commands by breaking them into verbs and objects.
- **World/Map System:**  
  Represents interconnected rooms, each with descriptions, exits, items, and events.
- **Inventory Manager:**  
  Manages the items collected by the player.
- **Event System:**  
  Triggers changes in the game state (e.g., traps, puzzles).

### Key Classes
- **Room:**  
  - **Attributes:** Description, exits (directions to other rooms), items, and event flags.
- **Item:**  
  - **Attributes:** Name, description, and interaction methods.
- **Player:**  
  - **Attributes:** Current room, inventory, health/status.
- **Parser:**  
  - **Methods:** Processes and interprets input commands.
- **Game:**  
  - Orchestrates the game loop and integrates all components.

### File Organization
- `main.cpp`: Entry point and main game loop.
- `Game.h` / `Game.cpp`: Game management and state control.
- `Room.h` / `Room.cpp`: Room class definition.
- `Item.h` / `Item.cpp`: Item class definition.
- `Player.h` / `Player.cpp`: Player class definition.
- `Parser.h` / `Parser.cpp`: Command parsing logic.
- `Utils.h` / `Utils.cpp` (optional): Helper functions and utilities.

## Implementation Plan

### Phase 1: Setup and Basic Framework
- Establish the project structure and main loop.
- Implement basic classes (`Room`, `Player`, `Parser`).
- Create a simple map with 3–4 interconnected rooms.

### Phase 2: Core Gameplay Features
- Develop the command parser for movement and interactions.
- Build the inventory system.
- Add initial room descriptions and objects.

### Phase 3: Puzzle Integration and Story Expansion
- Code puzzles (e.g., unlocking doors, solving riddles).
- Expand the castle map with more rooms and secret passages.
- Integrate a basic health or status system.

### Phase 4: Narrative Enhancement and Multiple Endings
- Enhance descriptive text and narrative elements.
- Implement branching paths for multiple endings.
- Refine event handling for complex interactions.

### Phase 5: Testing and Polishing
- Thorough playtesting and debugging.
- Refine input handling for smoother gameplay.
- Add a help command to guide players.

## Tools and Libraries
- **C++ Standard Library:** For I/O, string manipulation, and data structures.
- **Optional:** [ncurses](https://invisible-island.net/ncurses/) for an enhanced terminal UI (colors, layout).

## Future Enhancements (Optional)
- **Save/Load Functionality:** Enable progress saving.
- **Randomized Elements:** Introduce procedural generation for replayability.
- **Enhanced UI:** Transition to a graphical interface or add audio effects.
- **Advanced Puzzles:** Implement multi-step puzzles with intricate item combinations.

