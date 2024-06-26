#include <criterion/criterion.h>
#include <sstream>

#include "Commands.hpp"

Test(Commands, validCommandMszTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string width = "18";
    std::string heigth = "20";

    commandsTester->setRessources(ressources);
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);

    commandsTester->handleCommandMsz("msz " + width + " " + heigth);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), std::stoi(heigth));
    for (const auto& line : commandsTester->getRessources()->tileRessources) {
        cr_assert_eq(line.size(), std::stoi(width));
    }
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
}

Test(Commands, invalidCommandMszTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();

    commandsTester->setRessources(ressources);
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), 0);

    commandsTester->handleCommandMsz("msz");
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), 0);

    commandsTester->handleCommandMsz("msz invalidCommand");
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), 0);

    commandsTester->handleCommandMsz("msz c h a r");
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), 0);

    commandsTester->handleCommandMsz("msz 0");
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), 0);

    commandsTester->handleCommandMsz("msz a b");
    cr_assert_eq(commandsTester->getRessources()->mapSet, false);
    cr_assert_eq(commandsTester->getRessources()->tileRessources.size(), 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandBctTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tileRessourcesTester;
    std::string x = "8";
    std::string y = "10";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);

    commandsTester->handleCommandBct("bct " + x + " " + y + " 1 2 3 4 5 6 7");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester->getFood(), 1);
    cr_assert_eq(tileRessourcesTester->getLinemate(), 2);
    cr_assert_eq(tileRessourcesTester->getDeraumere(), 3);
    cr_assert_eq(tileRessourcesTester->getSibur(), 4);
    cr_assert_eq(tileRessourcesTester->getMendiane(), 5);
    cr_assert_eq(tileRessourcesTester->getPhiras(), 6);
    cr_assert_eq(tileRessourcesTester->getThystame(), 7);
}

Test(Commands, invalidCommandBctTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tileRessourcesTester;
    std::string x = "28";
    std::string y = "30";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);

    commandsTester->handleCommandBct("bct " + x + " " + y + " 1 2 3 4 5 6 7");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester, nullptr);

    commandsTester->handleCommandBct("bct");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester, nullptr);

    commandsTester->handleCommandBct("bct invalidCommand");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester, nullptr);

    commandsTester->handleCommandBct("bct a b c d e f g h i");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester, nullptr);

    commandsTester->handleCommandBct("bct 8 10 1 2 3 4 5 6 7 8 9 10");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester, nullptr);

    commandsTester->handleCommandBct("bct 8");
    tileRessourcesTester = commandsTester->getRessources()->getTileFromPos(std::stoi(x), std::stoi(y));
    cr_assert_eq(tileRessourcesTester, nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandTnaTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string teamNameTester = "Test42";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    cr_assert_eq(commandsTester->getRessources()->teamsColor.find(teamNameTester), nullptr);

    commandsTester->handleCommandTna("tna " + teamNameTester);
    cr_assert_eq(commandsTester->getRessources()->teamsColor.size(), 2);

    commandsTester->handleCommandTna("tna " + teamNameTester);
    cr_assert_eq(commandsTester->getRessources()->teamsColor.size(), 2);

    commandsTester->handleCommandTna("tna " + teamNameTester + "Bis");
    cr_assert_eq(commandsTester->getRessources()->teamsColor.size(), 3);
}

Test(Commands, invalidCommandTnaTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string teamNameTester = "Test";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    cr_assert_eq(commandsTester->getRessources()->teamsColor.find(teamNameTester), nullptr);

    commandsTester->handleCommandTna("tna");
    cr_assert_eq(commandsTester->getRessources()->teamsColor.find(teamNameTester), nullptr);

    commandsTester->handleCommandTna("tna invalid command");
    cr_assert_eq(commandsTester->getRessources()->teamsColor.find(teamNameTester), nullptr);

    commandsTester->handleCommandTna("tna 1 2");
    cr_assert_eq(commandsTester->getRessources()->teamsColor.find(teamNameTester), nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandPnwTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "000";
    std::string x = "8";
    std::string y = "10";
    std::string orientation = "1";
    std::string level = "1";
    std::string teamName = "teamNameTester";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);

    commandsTester->handleCommandBct("tna teamNameTester");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);

    commandsTester->handleCommandPnw("pnw " + playerId + " " + x + " " + y + " " + orientation + " " + level + " " + teamName);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), std::stoi(playerId));
        cr_assert_eq(player->getX(), std::stoi(x));
        cr_assert_eq(player->getY(), std::stoi(y));
        cr_assert_eq(player->getTeam(), teamName);
        cr_assert_eq(player->getLinemate(), 0);
        cr_assert_eq(player->getDeraumere(), 0);
        cr_assert_eq(player->getSibur(), 0);
        cr_assert_eq(player->getMendiane(), 0);
        cr_assert_eq(player->getPhiras(), 0);
        cr_assert_eq(player->getThystame(), 0);
        cr_assert_eq(player->getFood(), 0);
        cr_assert_eq(player->getLvl(), std::stoi(level));
    }

    playerId = "001";
    teamName = "teamNameTesterBis";
    orientation = "4";
    level = "8";
    commandsTester->handleCommandPnw("pnw " + playerId + " " + x + " " + y + " " + orientation + " " + level + " " + teamName);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 2);
    cr_assert_eq(commandsTester->getRessources()->teamsColor.size(), 3);
}

Test(Commands, invalidCommandPnwTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "000";
    std::string x = "8";
    std::string y = "10";
    std::string orientation = "-1";
    std::string level = "-1";
    std::string teamName = "teamNameTester";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw " + playerId + " " + x + " " + y + " " + orientation + " " + level + " " + teamName);

    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);

    orientation = "5";
    level = "1";
    commandsTester->handleCommandPnw("pnw " + playerId + " " + x + " " + y + " " + orientation + " " + level + " " + teamName);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);

    orientation = "1";
    level = "9";
    commandsTester->handleCommandPnw("pnw " + playerId + " " + x + " " + y + " " + orientation + " " + level + " " + teamName);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);

    x = 100;
    y = 100;
    level = "1";
    commandsTester->handleCommandPnw("pnw " + playerId + " " + x + " " + y + " " + orientation + " " + level + " " + teamName);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandPpoTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "000";
    std::string x = "8";
    std::string y = "10";
    std::string orientation = "1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 000 9 11 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), std::stoi(playerId));
        cr_assert_eq(player->getX(), std::stoi(x));
        cr_assert_eq(player->getY(), std::stoi(y));
    }
}

Test(Commands, invalidCommandPpoTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "001";
    std::string x = "9";
    std::string y = "11";
    std::string orientation = "1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);
    commandsTester->handleCommandPnw("pnw 000 9 11 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 9);
        cr_assert_eq(player->getY(), 11);
    }

    playerId = "1";
    orientation = "-1";
    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 9);
        cr_assert_eq(player->getY(), 11);
    }

    playerId = "1";
    orientation = "5";
    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 9);
        cr_assert_eq(player->getY(), 11);
    }

    orientation = "1";
    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation + "invalid command");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 9);
        cr_assert_eq(player->getY(), 11);
    }

    x = "100";
    y = "100";
    commandsTester->handleCommandPpo("ppo " + playerId + " " + x + " " + y + " " + orientation);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 9);
        cr_assert_eq(player->getY(), 11);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandPlvTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "000";
    std::string level = "3";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 000 1 1 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandPlv("plv " + playerId + " " + level);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), std::stoi(playerId));
        cr_assert_eq(player->getLvl(), std::stoi(level));
    }
}

Test(Commands, invalidCommandPlvTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "000";
    std::string level = "-1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 18 20");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPlv("plv " + playerId + " " + level);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 0);
    commandsTester->handleCommandPnw("pnw 000 9 11 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandPlv("plv " + playerId + " " + level);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getLvl(), 1);
    }

    level = "9";
    commandsTester->handleCommandPlv("plv " + playerId + " " + level);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getLvl(), 1);
    }

    playerId = "1";
    level = "2";
    commandsTester->handleCommandPlv("plv " + playerId + " " + level);
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getLvl(), 1);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandPinTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "000";
    std::string x = "1";
    std::string y = "1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 000 1 1 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandPin("pin " + playerId + " " + x + " " + y + " 1 2 3 4 5 6 7");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), std::stoi(playerId));
        cr_assert_eq(player->getX(), std::stoi(x));
        cr_assert_eq(player->getY(), std::stoi(y));
        cr_assert_eq(player->getFood(), 1);
        cr_assert_eq(player->getLinemate(), 2);
        cr_assert_eq(player->getDeraumere(), 3);
        cr_assert_eq(player->getSibur(), 4);
        cr_assert_eq(player->getMendiane(), 5);
        cr_assert_eq(player->getPhiras(), 6);
        cr_assert_eq(player->getThystame(), 7);
    }
}

Test(Commands, invalidCommandPinTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string playerId = "001";
    std::string x = "1";
    std::string y = "1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 000 1 1 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandPin("pin " + playerId + " " + x + " " + y + "1 2 3 4 5 6 7");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 1);
        cr_assert_eq(player->getY(), 1);
        cr_assert_eq(player->getFood(), 0);
        cr_assert_eq(player->getLinemate(), 0);
        cr_assert_eq(player->getDeraumere(), 0);
        cr_assert_eq(player->getSibur(), 0);
        cr_assert_eq(player->getMendiane(), 0);
        cr_assert_eq(player->getPhiras(), 0);
        cr_assert_eq(player->getThystame(), 0);
    }

    playerId = "0";
    commandsTester->handleCommandPin("pin " + playerId + " " + x + " " + y + "1 2 3 4 5 6 7 invalid command");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 1);
        cr_assert_eq(player->getY(), 1);
        cr_assert_eq(player->getFood(), 0);
        cr_assert_eq(player->getLinemate(), 0);
        cr_assert_eq(player->getDeraumere(), 0);
        cr_assert_eq(player->getSibur(), 0);
        cr_assert_eq(player->getMendiane(), 0);
        cr_assert_eq(player->getPhiras(), 0);
        cr_assert_eq(player->getThystame(), 0);
    }

    x = 100;
    y = 100;
    commandsTester->handleCommandPin("pin " + playerId + " " + x + " " + y + "1 2 3 4 5 6 7");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 1);
        cr_assert_eq(player->getY(), 1);
        cr_assert_eq(player->getFood(), 0);
        cr_assert_eq(player->getLinemate(), 0);
        cr_assert_eq(player->getDeraumere(), 0);
        cr_assert_eq(player->getSibur(), 0);
        cr_assert_eq(player->getMendiane(), 0);
        cr_assert_eq(player->getPhiras(), 0);
        cr_assert_eq(player->getThystame(), 0);
    }

    commandsTester->handleCommandPin("pin ");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    for (auto &player : commandsTester->getRessources()->players) {
        cr_assert_eq(player->getId(), 0);
        cr_assert_eq(player->getX(), 1);
        cr_assert_eq(player->getY(), 1);
        cr_assert_eq(player->getFood(), 0);
        cr_assert_eq(player->getLinemate(), 0);
        cr_assert_eq(player->getDeraumere(), 0);
        cr_assert_eq(player->getSibur(), 0);
        cr_assert_eq(player->getMendiane(), 0);
        cr_assert_eq(player->getPhiras(), 0);
        cr_assert_eq(player->getThystame(), 0);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandEnwTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string eggNum = "1";
    std::string playerId = "0";
    std::string x = "1";
    std::string y = "1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 0 1 1 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandEnw("enw " + eggNum + " " + playerId + " " + x + " " + y);
    cr_assert_eq(commandsTester->getRessources()->getEggFromId(std::stoi(eggNum))->getX(), std::stoi(x));
    cr_assert_eq(commandsTester->getRessources()->getEggFromId(std::stoi(eggNum))->getY(), std::stoi(y));
    cr_assert_eq(commandsTester->getRessources()->getEggFromId(std::stoi(eggNum))->getTeam(), "teamNameTest");

}

Test(Commands, invalidCommandEnwTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string eggNum = "1";
    std::string playerId = "0";
    std::string x = "1";
    std::string y = "1";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 0 1 1 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);

    commandsTester->handleCommandEnw("enw ");
    cr_assert_eq(commandsTester->getRessources()->getEggFromId(std::stoi(eggNum)), nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(Commands, validCommandEboTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::shared_ptr<Zappy::Server::SharedMemory> sharedMemory = std::make_shared<Zappy::Server::SharedMemory>();
    std::string eggNum = "2";

    commandsTester->setRessources(ressources);
    commandsTester->setSharedMemory(sharedMemory);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    commandsTester->handleCommandPnw("pnw 0 1 1 1 1 teamNameTest");
    cr_assert_eq(commandsTester->getRessources()->players.size(), 1);
    commandsTester->handleCommandEnw("enw 2 0 1 1");

    commandsTester->handleCommandEbo("ebo " + eggNum);
    cr_assert_eq(commandsTester->getRessources()->getEggFromId(std::stoi(eggNum)), nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Test(Commands, validCommandSgtTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    std::string timeUnit = "3";

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);

    commandsTester->handleCommandSgt("sgt " + timeUnit);
    cr_assert_eq(commandsTester->getRessources()->frequency, std::stoi(timeUnit));
}

Test(Commands, invalidCommandSgtTest)
{
    std::shared_ptr<Zappy::Server::Commands> commandsTester = std::make_shared<Zappy::Server::Commands>();
    std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources = std::make_shared<Zappy::GUI::Ressources::Ressources>();
    int freq;
    int freqTester = -1;

    commandsTester->setRessources(ressources);
    commandsTester->handleCommandMsz("msz 2 2");
    cr_assert_eq(commandsTester->getRessources()->mapSet, true);
    freq = commandsTester->getRessources()->frequency;

    commandsTester->handleCommandEbo("sgt " + freqTester);
    cr_assert_eq(commandsTester->getRessources()->frequency, freq);

    commandsTester->handleCommandEbo("sgt ");
    cr_assert_eq(commandsTester->getRessources()->frequency, freq);
}
