#pragma once
#include <GLFW/glfw3.h>
#include <vector>
//
#define AstroWindow GLFWwindow 
#define ASTRO_VERSION 0.1
#define ASTRO_PLAYER_OBJECT 1
#define ASTRO_REGULAR_OBJECT 2
#define ASTRO_OBJECT_AI 3
#define ASTRO_OBJECT_BACKROUND 4
#define astroUninitWindow(window) glfwDestroyWindow(window); glfwTerminate();
#define AstroProgramRunning(window) !glfwWindowShouldClose(window)
//
int astroGravityinit(int windowWidth, int windowHeight);
int astroInitWindow(int width, int height, const char* title, AstroWindow** window);
int astroGetKey();
class AstroObjects {
public:
	int type = 5;
	unsigned int width = 0;
	unsigned int height = 0;
	int x_location = 0;
	int y_location = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
	bool isVisible = true;
	bool isCollidable = true;
	bool isAnchor = false;
	std::vector<unsigned char> pixels;
	int astroSetTexture(std::string filename, std::vector<unsigned char> &texturePixels);
	int astroUpdateTexture(std::vector<unsigned char> texturePixels);
	int astroGravityUpdate(int windowWidth, int windowHeight, std::vector<int>& grid);
	int astroStartObject(int type, unsigned int width, unsigned int height, int x_location, int y_location, int red, int green, int blue);
	int astroUpdateObject(int x_location, int y_location);
};
