
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

int main(void)
{
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // Handle Errors
  glfwSetErrorCallback(error_callback);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
