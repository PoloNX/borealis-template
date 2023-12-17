#include <borealis.hpp>
#include <switch.h>

#include "main_frame.hpp"
#include "constants.hpp"

namespace i18n = brls::i18n;
using namespace i18n::literals;

void init();
void exit();

int main() {
    if(!brls::Application::init(fmt::format("{}, v{}", "menu/main/application"_i18n, APP_VER))) {
        brls::Logger::error("Failed to initialize application");
        return -1;
    }

    init();

    i18n::loadTranslations("en-US");

    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);
    brls::Application::pushView(new MainFrame());

    while(brls::Application::mainLoop()) ;

    exit();

    return 0;
}

void init() {
    setsysInitialize();
    plInitialize(PlServiceType_User);
    nsInitialize();
    socketInitializeDefault();
    nxlinkStdio();
    pmdmntInitialize();
    pminfoInitialize();
    splInitialize();
    fsInitialize();
    romfsInit();
}

void exit() {
    romfsExit();
    splExit();
    pminfoExit();
    pmdmntExit();
    socketExit();
    nsExit();
    setsysExit();
    fsExit();
    plExit();
}