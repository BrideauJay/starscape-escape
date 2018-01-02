# starscape-escape
Puzzle platformer with original game engine

Starscape Escape (working title) is a puzzle platformer game I am developing from scratch in C++, making the game engine as I go. 
The game supports multiple playable characters who will each have different abilities to help them navigate the level. 
Characters gain additional abilities as they progress through the game, to help them solve increasingly difficult puzzles.

Currently, I am still implementing some of what I consider 'the basics' of the game engine.

Currently implemented:
- 3 playable characters (toggle with 'Q' key), each of which can:
    - Face in four directions, with appropriate images for each direction (WASD keys)
    - Move left and right
    - Jump
    - Move from one screen to another
    -Fall when they are no longer standing on a platform
- Multiple 'screens' contained in one level, so that characters stop moving upon reaching either end of the level but can navigate 
the screens in between
- Platform objects that can be drawn on any screen and that players interact with appropriately
  
