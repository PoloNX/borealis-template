#include "main_frame.hpp"
#include "constants.hpp"

namespace i18n = brls::i18n;
using namespace i18n::literals;

MainFrame::MainFrame() {
    this->setTitle(fmt::format("{}, {}", "menu/main/application"_i18n, APP_VER));

    //this->setIcon(BOREALIS_ASSET("icon/icon.png"));

    this->registerAction("", brls::Key::B, [this] {brls::Application::quit(); return true;});
}