#include "plugin.hpp"
#include "MyGUI_PluginManager.h"

MyGUI::ResourcePlugin* plugin_item = nullptr;

extern "C" MYGUI_EXPORT_DLL void dllStartPlugin(void)
{
    plugin_item = new MyGUI::ResourcePlugin();
    MyGUI::PluginManager::getInstance().installPlugin(plugin_item);
}

extern "C" MYGUI_EXPORT_DLL void dllStopPlugin(void)
{
    MyGUI::PluginManager::getInstance().uninstallPlugin(plugin_item);
    delete plugin_item;
    plugin_item = nullptr;
}
