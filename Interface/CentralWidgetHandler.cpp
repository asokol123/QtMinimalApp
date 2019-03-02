//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include <QEvent>
#include <QWidget>
#include <QDebug>
#include "CentralWidgetHandler.h"
//---------------------------------------------------------------------------

namespace NSApplication {
namespace NSInterface {
//---------------------------------------------------------------------------
// CCentralWidgetHandler Definition
//---------------------------------------------------------------------------

CCentralWidgetHandler::CCentralWidgetHandler(QWidget* Widget)
  : Widget_(Widget),
    EventCount_(0) {
  Widget_->installEventFilter(this);
}
//---------------------------------------------------------------------------

CCentralWidgetHandler::~CCentralWidgetHandler() {
  qDebug() << "centralWidget events = " << EventCount_;
}
//---------------------------------------------------------------------------

bool CCentralWidgetHandler::eventFilter(QObject* watched, QEvent* event) {
  if (watched == Widget_)
    return processEvent(event);
  // false means "do not stop event processing"
  return false;
}
//---------------------------------------------------------------------------

bool CCentralWidgetHandler::processEvent(QEvent* event) {
  // Thid is just an example. No code must be here
  // instead call an appropriate function like:
  // increaseEventCount();
  ++EventCount_;
  switch (event->type()) {
  case QEvent::Show:
    // This is just an example. No code must be here.
    // Call an appropriate function here, for example:
    // return processShowEvent(event);
    // The function processShowEvent(event) returns true
    // if you want to prevent any further event processing
    // and false otherwise.
    qDebug() << "Central Widget has been shown";
    // use "return true;" here if you want
    // to stop further event processing
    break;
  case QEvent::Hide:
    // This is just an example. No code must be here.
    // Call an appropriate function here, for example:
    // return processHideEvent(event);
    // The function processHideEvent(event) returns true
    // if you want to prevent any further event processing
    qDebug() << "Central Widget has been hidden";
    break;
  default:
    break;
  }
  // false means "do not stop event processing"
  return false;
}
//---------------------------------------------------------------------------
} // NSInterface
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
