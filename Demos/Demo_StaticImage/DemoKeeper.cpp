/*!
    @file
    @author     Albert Semenov
    @date       08/2008
    @module
*/
#include "DemoKeeper.h"
 
namespace demo
{
 
    void DemoKeeper::createScene()
    {
		using namespace MyGUI;
        const IntSize & view = Gui::getInstance().getViewSize();
        const IntSize size(100, 100);
 
        base::BaseManager::getInstance().addResourceLocation("../../Media/Demos/Demo_StaticImage");
        base::BaseManager::getInstance().addResourceLocation("../../Media/Wallpapers");
        base::BaseManager::getInstance().setWallpaper("wallpaper1.jpg");

		mView.initialise();
    }
 
    void DemoKeeper::destroyScene()
    {
		mView.shutdown();
    }
 
} // namespace demo 
 


  