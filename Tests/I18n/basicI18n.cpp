#include <criterion/criterion.h>
#include <sstream>

#include "I18nHelper.hpp"

Test(I18nHelper, defaultConstruct) {
    Zappy::GUI::I18n::I18nHelper* i18nTester = Zappy::GUI::I18n::I18nHelper::getInstance();

    cr_assert_eq(i18nTester->getCurrentLocale(), Zappy::GUI::I18n::SupportedLocale::en_GB);
}

Test(I18nHelper, setCurrentLocaleValue) {
    Zappy::GUI::I18n::I18nHelper* i18nTester = Zappy::GUI::I18n::I18nHelper::getInstance();
    i18nTester->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::fr_FR);
    std::string currentLocaleValue = i18nTester->getLocaleValue(i18nTester->getCurrentLocale());

    cr_assert_str_eq(currentLocaleValue.c_str(), "fr_FR");
}

Test(I18nHelper, getLocaleValueFromSupportedLocale) {
    Zappy::GUI::I18n::I18nHelper* i18nTester = Zappy::GUI::I18n::I18nHelper::getInstance();
    std::string enLocaleValue = i18nTester->getLocaleValue(Zappy::GUI::I18n::SupportedLocale::en_GB);
    std::string frLocaleValue = i18nTester->getLocaleValue(Zappy::GUI::I18n::SupportedLocale::fr_FR);

    cr_assert_str_eq(enLocaleValue.c_str(), "en_GB");
    cr_assert_str_eq(frLocaleValue.c_str(), "fr_FR");
}

Test(I18nHelper, getTranslationFromUnknownKey) {
    Zappy::GUI::I18n::I18nHelper* i18nTester = Zappy::GUI::I18n::I18nHelper::getInstance();
    std::string translationValue = i18nTester->getTranslation("Unknown key");

    cr_assert_str_eq(translationValue.c_str(), "Unknown key");
}

Test(I18nHelper, getTranslationValue) {
    Zappy::GUI::I18n::I18nHelper* i18nTester = Zappy::GUI::I18n::I18nHelper::getInstance();
    std::string translationValue_en = i18nTester->getTranslation("[menu.start_title]");
    i18nTester->setCurrentLocale(Zappy::GUI::I18n::SupportedLocale::fr_FR);
    std::string translationValue_fr = i18nTester->getTranslation("[menu.start_title]");

    cr_assert_str_eq(translationValue_en.c_str(), "PLAY");
    cr_assert_str_eq(translationValue_fr.c_str(), "JOUER");
}