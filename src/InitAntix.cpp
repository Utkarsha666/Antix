#include "InitAntix.h"

using namespace Antix::Init;

Antix::IListener* InitAntix::listener = NULL;
Antix::Window InitAntix::window;


void InitAntix::init(const Antix::Window& windowInfo,       // window name
                    const Antix::Context& context,          // context 
                    const Antix::Framebuffer& framebuffer)
{
    int fakeargc = 1;
    char *fakeargv[] = { "fake", NULL };
    window = windowInfo;
    glutInit(&fakeargc, fakeargv);

    if (context.core)
    {
        glutInitContextVersion(context.major_version, context.minor_version);
        glutInitContextProfile(GLUT_CORE_PROFILE);
    }
    else
    {
        glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    }
    // set display mode //
    glutInitDisplayMode(framebuffer.flags);
    glutInitWindowPosition(window.x_pos, window.y_pos);     // initial window position //
    glutInitWindowSize(window.width, window.height);        // initial window size //
    glutCreateWindow(windowInfo.name.c_str());      // create the window with the given name //

    // display this message on the console //
    std::cout << "-- ANTIX: INITIALIZED SUCCESSFULLY -- " << std::endl;

    // glut callback functions ///
    glutIdleFunc(idleCallback);
    glutCloseFunc(closeCallback);
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);

    // Now Initialize glew //
    Init::InitGlew::Init();

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
                GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    
    // display opengl info to the console //
    printOpenGLInfo(windowInfo, context);
}

// glut mainloop function //
void InitAntix::run()
{
    std::cout << "Antix Engine:\t Start Running " << std::endl;
    glutMainLoop();
}

// called when the application is closed //
void InitAntix::close()
{
    std::cout << "Antix Engine:\t Closing Engine " << std::endl;
    glutLeaveMainLoop();
}

// called when the application is idle //
void InitAntix::idleCallback(void)
{
    glutPostRedisplay();
}

void InitAntix::displayCallback(void)
{
    // this is a display callback function
    if (listener)
    {
        listener->BeginFrame();
        listener->DisplayFrame();

        glutSwapBuffers();
        listener->EndFrame();
    }
}

// called when the application is resized //
void InitAntix::reshapeCallback(int width, int height)
{
    if (window.isReshapable == true)
    {
        if (listener)
        {
            listener->Reshape(width, height,
                            window.width, window.height);

            window.width = width;
            window.height = height;
        }
    }
}

void InitAntix::closeCallback()
{
    close();
}

void InitAntix::enterFullScreen()
{
    glutFullScreen();
}

void InitAntix::exitFullScreen()
{
    glutLeaveFullScreen();
}

void InitAntix::setListener(Antix::IListener *&iListener)
{
    listener = iListener;
}

void InitAntix::printOpenGLInfo(const Antix::Window& windowInfo,
                                const Antix::Context& contextInfo)
{
    const unsigned char* renderer = glGetString(GL_RENDERER);
    const unsigned char* vendor = glGetString(GL_VENDOR);
    const unsigned char* version = glGetString(GL_VERSION);

    std::cout << "********************************************\n";
    std::cout << "Antix Game Engine:- By Utkarsha " << std::endl;
    std::cout << "Antix: Initialized " << std::endl;
    std::cout << "OpenGL:\tVendor : " << vendor << std::endl;
    std::cout << "OpenGL:\tRenderer : " << renderer << std::endl;
    std::cout << "OpenGL:\tVersion :" << version << std::endl;
    std::cout << "********************************************\n";
}

