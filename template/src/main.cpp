#include "main.hpp"
#include "Settings.hpp"

#include "questui/shared/QuestUI.hpp"
#include "custom-types/shared/register.hpp"

static ModInfo modInfo;
DEFINE_CONFIG(ModConfig);

Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load(); // Load the config file
    getLogger().info("Completed setup!");
}

extern "C" void load() {
    getLogger().info("Installing hooks...");
    il2cpp_functions::Init();

    // Use this for Quest UI
    QuestUI::Init();

    LoggerContextObject logger = getLogger().WithContext("load");

    // Register our mod settings menu
    QuestUI::Register::RegisterModSettingsViewController(modInfo, DidActivate);

    // Install our hooks

    // Hook for BS hook 1.3.3
    // INSTALL_HOOK_OFFSETLESS(logger, Class_Method, il2cpp_utils::FindMethodUnsafe("", "Class", "Method", 0));
    getLogger().info("Installed all hooks!");
}