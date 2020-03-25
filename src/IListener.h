#ifndef _ILISTENER_H
#define _ILISTENER_H

// Abstract class IListener //
namespace Antix{
    
    class IListener
    {
    public:
        virtual ~IListener() = 0;

        virtual void BeginFrame() = 0;     
        virtual void DisplayFrame() = 0;
        virtual void EndFrame() = 0;
        virtual void Reshape(int width,
                            int height,
                            int previousWidth,
                            int previousHeight) = 0;
    };
    // destructor //
    inline IListener::~IListener() {
        
    }
}
#endif