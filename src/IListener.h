#ifndef _ILISTENER_H
#define _ILISTENER_H
#include "ModelsManager.h"

// Abstract class IListener //
namespace Antix{
    
    class IListener
    {
        // abstract class don't have destructors //
    public:
        // destructor
        virtual ~IListener() = 0;

        virtual void BeginFrame() = 0;     
        virtual void DisplayFrame() = 0;
        virtual void EndFrame() = 0;
        virtual void Reshape(int width,
                            int height,
                            int previousWidth,
                            int previousHeight) = 0;

        // getters and setters for models managers //
        virtual Managers::ModelsManager* getModelsManager() const = 0;
        virtual void setModelsManager(Managers::ModelsManager*&) = 0;
    };
    // destructor //
    inline IListener::~IListener() {
        
    }
}
#endif