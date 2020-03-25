// Author : Utkarsha //
// ////// Date : 13 Feb 2020 // //////
// Simple Break-out game //

#pragma once
#include "InitAntix.h"
#include "SceneManager.h"

using namespace Antix;
using namespace Init;

int main(int argc, char argv)
{
    Window window(std::string("Breakout"), 400, 200, 800, 600, true);

    Context context(4, 5, true);

    Framebuffer framebuffer(true, true, true, true);

    // Initialize Antix Engine and run it //
    Init::InitAntix::init(window, context, framebuffer);

    IListener* scene = new Managers::SceneManager();

    Init::InitAntix::setListener(scene);

    Init::InitAntix::run();
    return 0;
}