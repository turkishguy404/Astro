#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include "Astro.h"
//
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")
//
const struct WindowSettings {
	int windowWidth = 800;
	int windowHeight = 600;
}w;
int main(void)
{
    //window 
	AstroWindow* window;
    //innit window
    //
	astroInitWindow(w.windowWidth, w.windowHeight, "Hello World", &window);
    //
    AstroObjects astroObject;
    AstroObjects Ground;
	std::vector<unsigned char> *texturePixels1 = new std::vector<unsigned char>;
    //
    astroObject.astroStartObject(ASTRO_PLAYER_OBJECT, 20, 20, 50, 50, 255, 128, 0);
    Ground.astroStartObject(ASTRO_REGULAR_OBJECT, w.windowWidth, 50, 0,450, 255, 255, 255);
	Ground.isAnchor = true;
	astroObject.astroSetTexture("image_pixels.txt", *texturePixels1);
	//astroObject.astroUpdateTexture(*texturePixels1);
    while (AstroProgramRunning(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		astroObject.astroUpdateObject(w.windowWidth, w.windowHeight);
		Ground.astroUpdateObject(w.windowWidth, w.windowHeight);
		if (astroGetKey() == 1) {
			astroObject.y_location -= 5;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
        else if (astroGetKey() == 2) {
            astroObject.y_location += 5;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        else if (astroGetKey() == 3) {
			astroObject.x_location -= 5;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

		}
        else if (astroGetKey() == 4) {
            astroObject.x_location += 5;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //
    astroUninitWindow(window);
    //
    return 0;
}