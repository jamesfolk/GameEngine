#include "game.h"
#include "asset_utils.h"
#include "buffer.h"
#include "image.h"
#include "platform_gl.h"
#include "platform_asset_utils.h"
#include "shader.h"
#include "texture.h"
#include <stdlib.h>

static GLuint texture;
static GLuint buffer;
static GLuint program;

static GLint a_position_location;
static GLint a_texture_coordinates_location;
static GLint u_texture_unit_location;

// position X, Y, texture S, T
static const float rect[] = {-1.0f, -1.0f, 0.0f, 0.0f,
                             -1.0f,  1.0f, 0.0f, 1.0f,
                              1.0f, -1.0f, 1.0f, 0.0f,
                              1.0f,  1.0f, 1.0f, 1.0f};







GLuint my_programObject;



///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint LoadShader(const char *shaderSrc, GLenum type)
{
   GLuint shader;
   GLint compiled;

   // Create the shader object
   shader = glCreateShader(type);

   if(shader == 0)
      return 0;

   // Load the shader source
   glShaderSource(shader, 1, &shaderSrc, NULL);

   // Compile the shader
   glCompileShader(shader);

   // Check the compile status
   glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

   if(!compiled)
   {
      GLint infoLen = 0;

      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

      if(infoLen > 1)
      {
         char* infoLog = malloc(sizeof(char) * infoLen);

         glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
//         esLogMessage("Error compiling shader:\n%s\n", infoLog);
         free(infoLog);
      }

      glDeleteShader(shader);
      return 0;
   }

   return shader;

}

///
// Initialize the shader and program object
//
int Init()//ESContext *esContext)
{
//   UserData *userData = esContext->userData;
//   GLbyte vShaderStr[] =
//      "attribute vec3 vPosition;   \n"
//      "void main()                 \n"
//      "{                           \n"
//      "  gl_Position = vPosition;  \n"
//      "}                           \n";
//
//   GLbyte fShaderStr[] =
//      "precision mediump float;                   \n"
//      "void main()                                \n"
//      "{                                          \n"
//	  "  vec4 color(0.0, 0.0, 1.0, 1.0);          \n"
//      "  gl_FragColor = color;                    \n"
//      "}                                          \n";

   GLuint vertexShader;
   GLuint fragmentShader;
   GLuint programObject;
   GLint linked;









	FileData vertex_shader_source = get_asset_data("shaders/shader.vsh");
	FileData fragment_shader_source = get_asset_data("shaders/shader.fsh");


  // Load the vertex/fragment shaders
  vertexShader = LoadShader(vertex_shader_source.data, GL_VERTEX_SHADER);
  fragmentShader = LoadShader(fragment_shader_source.data, GL_FRAGMENT_SHADER);

	release_asset_data(&vertex_shader_source);
	release_asset_data(&fragment_shader_source);

  // Create the program object
  programObject = glCreateProgram();

  if(programObject == 0)
     return 0;

  glAttachShader(programObject, vertexShader);
  glAttachShader(programObject, fragmentShader);

  // Bind vPosition to attribute 0
  glBindAttribLocation(programObject, 0, "vPosition");

  // Link the program
  glLinkProgram(programObject);

  // Check the link status
  glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

  if(!linked)
  {
     GLint infoLen = 0;

     glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

     if(infoLen > 1)
     {
        char* infoLog = malloc(sizeof(char) * infoLen);

        glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
//        esLogMessage("Error linking program:\n%s\n", infoLog);

        free(infoLog);
     }

     glDeleteProgram(programObject);
     return 0;
  }

  // Store the program object
//  userData->programObject = programObject;
  my_programObject = programObject;

  return 1;
}



///
// Draw a triangle using the shader pair created in Init()
//
void Draw()//ESContext *esContext)
{
//   UserData *userData = esContext->userData;
   GLfloat vVertices[] = {0.0f,  0.5f, 0.0f,
                          -0.5f, -0.5f, 0.0f,
                          0.5f, -0.5f,  0.0f};



   // Clear the color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   // Use the program object
   glUseProgram(my_programObject);

   // Load the vertex data
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
   glEnableVertexAttribArray(0);

   glDrawArrays(GL_TRIANGLES, 0, 3);
}





void on_surface_created() {
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);

//	texture = load_png_asset_into_texture("textures/air_hockey_surface.png");
//	buffer = create_vbo(sizeof(rect), rect, GL_STATIC_DRAW);
//	program = build_program_from_assets("shaders/shader.vsh", "shaders/shader.fsh");
//
//	a_position_location = glGetAttribLocation(program, "a_Position");

    Init();
}

void on_surface_changed(int width, int height) {
	// Set the viewport
   glViewport(0, 0, width, height);



    a_texture_coordinates_location =
        glGetAttribLocation(program, "a_TextureCoordinates");
    u_texture_unit_location = glGetUniformLocation(program, "u_TextureUnit");
}

void on_draw_frame() {
	Draw();

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glUseProgram(program);
//
//    glBindBuffer(GL_ARRAY_BUFFER, buffer);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);

//    glUseProgram(program);
//
////    glActiveTexture(GL_TEXTURE0);
////    glBindTexture(GL_TEXTURE_2D, texture);
////    glUniform1i(u_texture_unit_location, 0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, buffer);
//    glVertexAttribPointer(a_position_location, 2, GL_FLOAT, GL_FALSE,
//        4 * sizeof(GL_FLOAT), BUFFER_OFFSET(0));
////    glVertexAttribPointer(a_texture_coordinates_location, 2, GL_FLOAT, GL_FALSE,
////        4 * sizeof(GL_FLOAT), BUFFER_OFFSET(2 * sizeof(GL_FLOAT)));
//    glEnableVertexAttribArray(a_position_location);
////    glEnableVertexAttribArray(a_texture_coordinates_location);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

//    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
