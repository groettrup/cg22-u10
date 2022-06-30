#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

int main(void)
{
  // Handler for the window object
  GLFWwindow* window;

  // Try to initialize GLFW
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // Handle Errors
  glfwSetErrorCallback(error_callback);

  // Try to create Window
  window = glfwCreateWindow(200, 200, "homework", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Make context current on main thread (gl now usable)
  glfwMakeContextCurrent(window);
  
  // load extensions using glad
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

  // Avoid tearing by limiting draws to one per refresh
  glfwSwapInterval(1);

  // Main loop
  while(!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
