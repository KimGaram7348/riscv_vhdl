/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      Serial console emulator.
 */

#pragma once

#include "api_core.h"   // MUST BE BEFORE QtWidgets.h or any other Qt header.
#include "attribute.h"
#include "igui.h"
#include "coreservices/irawlistener.h"
#include "coreservices/iserial.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtGui/qevent.h>

namespace debugger {

/**
 * QPlainTextEdit gives per-line scrolling (but optimized for plain text)
 * QTextEdit gives smooth scrolling (line partial move up-down)
 */
class UartWidget : public QPlainTextEdit,
                   public IRawListener {
    Q_OBJECT
public:
    UartWidget(IGui *igui, QWidget *parent = 0);
    ~UartWidget();

    // IRawListener
    virtual void updateData(const char *buf, int buflen);

signals:
    void signalClose(QWidget *, AttributeType &);
private slots:
    void slotConfigure(AttributeType *cfg);
    void slotRepaintByTimer();
    void slotClosingMainForm();

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void closeEvent(QCloseEvent *event_);

private:
    char keyevent2char(QKeyEvent *e);

private:
    IGui *igui_;
    ISerial *uart_;
    QString strOutput_;
    bool bNewDataAvailable_;
    mutex_def mutexStr_;
};

}  // namespace debugger
