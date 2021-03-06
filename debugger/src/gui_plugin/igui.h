/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      Graphical User Interface (GUI).
 */

#ifndef __DEBUGGER_IGUI_H__
#define __DEBUGGER_IGUI_H__

#include "iface.h"
#include "attribute.h"

namespace debugger {

static const char *const IFACE_GUI_PLUGIN = "IGui";
static const char *const IFACE_GUI_CMD_HANDLER = "IGuiCmdHandler";

class IGuiCmdHandler : public IFace {
public:
    IGuiCmdHandler() : IFace(IFACE_GUI_CMD_HANDLER) {}

    virtual void handleResponse(AttributeType *req, AttributeType *resp) =0;
};


class IGui : public IFace {
public:
    IGui() : IFace(IFACE_GUI_PLUGIN) {}

    virtual void registerMainWindow(void *iwindow) =0;

    virtual void registerWidgetInterface(IFace *iface) =0;

    virtual void unregisterWidgetInterface(IFace *iface) =0;

    virtual void registerCommand(IGuiCmdHandler *src, AttributeType *cmd) =0;
};

}  // namespace debugger

#endif  // __DEBUGGER_IGUI_H__
