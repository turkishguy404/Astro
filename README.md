# Astro

Easy to use 2d game engine.

## Description

Astro is an game engine I made using open gl and c++.

## Getting Started

### Dependencies

* You'll need GLFW 3.0 (minimum)

### Installing

Just copy and paste header and .cpp file and include it like normal.

### Executing program

After instaling you have to include it.

*include "Astro.h"*

## Complete Function & Macro Reference

### Window & Engine Functions

* **`astroInitWindow(int width, int height, const char* title, AstroWindow** window)`**: Initializes GLFW, creates the window context, and handles termination on failure.


* **`astroGravityinit(int windowWidth, int windowHeight, std::vector<int>& grid)`**: Resizes the tracking grid vector to match window dimensions.


* **`astroGetKey()`**: Checks GLFW input state for WASD keys and returns a directional code (1 for W, 2 for S, 3 for A, 4 for D, 0 for none).


### AstroObjects Methods

* **`AstroObjects::astroStartObject(...)`**: Initializes an object's type, size, position, RGB color values, and determines whether it is collidable.


* **`AstroObjects::astroSetTexture(std::string filename, std::vector<unsigned char> &texturePixels)`**: Loads line-by-line RGB text file data into the object's pixel buffers and texture arrays.


* **`AstroObjects::astroUpdateObject(int windowWidth, int windowHeight)`**: Normalizes object coordinates and draws the pixel data using OpenGL (`glRasterPos2f` and `glDrawPixels`).


* **`AstroObjects::astroUpdateTexture(std::vector<unsigned char> texturePixels)`**: *(Commented out/Upcoming)* Designed to process and print texture pixel data arrays.


* **`AstroObjects::astroGravityUpdate(...)`**: *(Commented out/Upcoming)* Intended to handle gravity and collision checks using a grid vector.


### Helpful Macros (`Astro.h`)

* **`AstroWindow`**: Maps to `GLFWwindow`.


* **`ASTRO_VERSION`**: Defines the library version (`0.1`).


* **Object Type Constants**: `ASTRO_PLAYER_OBJECT` (1), `ASTRO_REGULAR_OBJECT` (2), `ASTRO_OBJECT_AI` (3), and `ASTRO_OBJECT_BACKROUND` (4).


* **`astroUninitWindow(window)`**: Destroys the window context and terminates GLFW.


* **`AstroProgramRunning(window)`**: Checks if the window should remain open (`!glfwWindowShouldClose(window)`).
## Authors

Turkishguy404
miracyedier10@gmail.com

## Version History

*1.0
   * initial release
* 0.1
    * First release

## NOTE
   * AstroGravityInit() does nothing for now :P
