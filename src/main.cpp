#include <cstdlib>
#include <dpp/appcommand.h>
#include <dpp/cluster.h>
#include <dpp/dispatcher.h>
#include <dpp/message.h>
#include <iostream>

#include <dpp/dpp.h>

#include "main.hpp"

int MAIN() {
    const char *rawBotToken = std::getenv("BOT_TOKEN");
    if (!rawBotToken) {
        std::cerr << "No BOT_TOKEN in environment!" << std::endl;
        return 1;
    }
    dpp::cluster bot(rawBotToken);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t &event) {
        if (event.command.get_command_name() == "ping") {
            event.reply(dpp::message().set_flags(dpp::m_ephemeral).set_content("Bloop!"));
        }
    });

    bot.on_ready([&bot](const dpp::ready_t &event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);
    __builtin_unreachable();
}
