/*
 * Xournal++
 *
 * The configuration for a button in the Settings Dialog
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <gdk/gdk.h>

#include "control/Actions.h"
#include "control/DeviceListHelper.h"
#include "gui/GladeGui.h"
#include "gui/IconNameHelper.h"

class Settings;
class SettingsDialog;

class ButtonConfigGui: public GladeGui {
public:
    ButtonConfigGui(GladeSearchpath* gladeSearchPath, GtkWidget* w, Settings* settings, int button, bool withDevice);
    ~ButtonConfigGui() override;

public:
    void loadSettings();
    void saveSettings();

    // Not implemented! This is not a dialog!
    void show(GtkWindow* parent) override;

private:
    static void cbSelectCallback(GtkComboBox* widget, ButtonConfigGui* gui);
    void enableDisableTools();
    std::string toolSizeToLabel(ToolSize size);

private:
    Settings* settings;

    GtkWidget* cbDevice;
    GtkWidget* cbDisableDrawing;

    GtkWidget* cbTool;
    GtkWidget* cbThickness;
    GtkWidget* colorButton;
    GtkWidget* cbEraserType;
    GtkWidget* cbDrawingType;

    std::vector<InputDevice> deviceList;

    int button = 0;
    bool withDevice = false;

    typedef std::map<int, ToolSize> ToolSizeIndexMap;
    static ToolSizeIndexMap toolSizeIndexMap;
    IconNameHelper iconNameHelper;
};
