#include <GLFW/glfw3.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Astro.h"
//
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")
//
int astroGravityinit(int windowWidth, int windowHeight,std::vector<int>& grid) {
	grid.resize(windowWidth * windowHeight, 0);
	return 0;
}
int astroInitWindow(int width, int height, const char* title, AstroWindow** window) {
    if (!glfwInit())
        return -1;
    *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!(*window))
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(*window);
    return 0;
}
int astroGetKey(){
    int get = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_W);
	if (get == GLFW_PRESS) {
		return 1;
	}
    get = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_S);
    if (get == GLFW_PRESS) {
        return 2;
    }
    get = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_A);
    if (get == GLFW_PRESS) {
        return 3;
    }
    get = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_D);
    if (get == GLFW_PRESS) {
        return 4;
    }
	return 0;
}
//problem
//int astroGravityinit(int windowWidth, int windowHeight) {
//	grid.resize(windowWidth * windowHeight, 0);
//	return 0;
//}
int AstroObjects::astroUpdateObject(int windowWidth,int windowHeight) {
	if (!isVisible) return 0;
	float normX = (x_location / float(windowWidth)) * 2.0f - 1.0f;
	float normY = (0.8f - ((y_location + (height / 2.0f)) / float(windowHeight))) * 2.0f - 1.0f;
    glRasterPos2f(normX, normY);
    glDrawPixels(int(width), int(height), GL_RGB, GL_UNSIGNED_BYTE, pixels.data());
    return 0;
}
int AstroObjects::astroStartObject(int ntype, unsigned int nwidth, unsigned int nheight, int nx_location, int ny_location, int nred, int ngreen, int nblue) {
	type = ntype;
	width = nwidth;
	height = nheight;
	x_location = nx_location;
	y_location = ny_location;
	red = nred;
	green = ngreen;
	blue = nblue;
    if (ntype == ASTRO_OBJECT_BACKROUND) {
		isCollidable = false;
    }
    else {
		isCollidable = true;
    }
	pixels.resize(width * height * 3);
    for (size_t i = 0; i < pixels.size(); i += 3)
    {
        pixels[i + 0] = red;
        pixels[i + 1] = green;
        pixels[i + 2] = blue;
    }
	return 0;
}
int AstroObjects::astroSetTexture(std::string filename,std::vector<unsigned char> &texturePixels) {
	std::string line;
	int nred, ngreen, nblue;
	texturePixels.resize(width * height * 3);
    std::ifstream file(filename, std::ios::binary);
	while (!file) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return -1;
	}
    int i = 0;
	while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> nred >> ngreen >> nblue;
        pixels[i + 0] = nred;
        pixels[i + 1] = ngreen;
        pixels[i + 2] = nblue;
        texturePixels[i + 0] = pixels[i + 0];
        texturePixels[i + 1] = pixels[i + 1];
        texturePixels[i + 2] = pixels[i + 2];
        i += 3;
		std::cout << "Line " << i/3 << ": " << nred << " " << ngreen << " " << nblue <<std::endl;
	}
	return 0;
}
//next update
//int AstroObjects::astroUpdateTexture(std::vector<unsigned char> texturePixels) {
//	texturePixels.resize(width * height * 3);
//    int i = 0;
//	std::cout << "Texture size: " << texturePixels.size() << std::endl;
//    while (i!=texturePixels.size()) {
//        i += 3;
//        std::cout << "Line " << i / 3 << ": " << texturePixels[i + 0] << " " << texturePixels[i + 1] << " " << texturePixels[i + 2] << std::endl;
//		if (i == texturePixels.size()) {
//			break;
//		}
//    }
//    return 0;
//}
// next update
//int AstroObjects::astroGravityUpdate(int windowWidth, int windowHeight, std::vector<int>& grid) {
//    grid.reserve(windowWidth * windowHeight);
//    std::fill(grid.begin(), grid.end(), 0);
//    int w = width;
//    int h = height;
//    int x = x_location;
//    int y = y_location;
//    while (x < windowWidth && y < windowHeight && !isAnchor && x > 0 && y > 0) {
//        for (int i = w; i > 0; i--) {
//            for (int j = h; j > 0; j--) {
//                if (y + j < windowHeight && x + i < windowWidth) {
//                    if (grid[(y + j) * windowWidth + (x + i)] == 1) {
//                        return 0;
//                    }
//                }
//            }
//        }
//        return 0;
//    }
//}
