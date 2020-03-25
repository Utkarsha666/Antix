/////////////////////////////////////// Antix Game Engine Feb 13, 2020 //////////////////////////////////////////////
/////////////////////////////////////// By: Utkarsha Khanal ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _INIT_ANTIX
#define _INIT_ANTIX

///// Header Files /////
#include "InitGlew.h"
#include "Window.h"
#include "Context.h"
#include "Framebuffer.h"
#include "IListener.h"

////////////////////////
namespace Antix {
    namespace Init {
        class InitAntix{

        public:
            // functions that creates the window // 
            static void init(const Antix::Window& window,
                            const Antix::Context& context,
                            const Antix::Framebuffer& framebuffer);
            static void run();
            static void close();

            void enterFullScreen();
            void exitFullScreen();

            // function to print opengl info on the console window //
            static void printOpenGLInfo(const Antix::Window& window,
                                        const Antix::Context& context);
                                        
            static void setListener(Antix::IListener*& iListener);

        private:
            static Antix::IListener* listener;
            static Antix::Window window;
            // callbacks
            static void idleCallback(void);
            static void displayCallback(void);
            static void reshapeCallback(int width, int height);
            static void closeCallback();  
        };
    }
}
#endif