//-------- Functions --------------------------------

void Render();
// The function responsible for drawing everything in the
// OpenGL context associated to a window.

void Resize(int w, int h);
// Handle the window size changes and define the world coordinate
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void Keyboard(unsigned char key, int x, int y);

void processSpecialKeys(int key, int xx, int yy);
void AutoMoveMenu(int value);
