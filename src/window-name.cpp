#include <Geode/Geode.hpp>
using namespace geode::prelude;

#define MBO(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset) 

#include <Geode/modify/CCScene.hpp>
class $modify(CCScene) {
    static CCScene* create() {
#ifdef GEODE_IS_WINDOWS
        auto GameWindowHandle = WindowFromDC(MBO(HDC, CCEGLView::sharedOpenGLView()->getWindow(), 0x244));
        SetWindowTextA(GameWindowHandle, Mod::get()->getName().data());
#endif
        return CCScene::create();
    }
};