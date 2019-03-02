#ifndef CENTRALWIDGETHANDLER_H
#define CENTRALWIDGETHANDLER_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include <QObject>
//---------------------------------------------------------------------------
// QWidget Forward Declaration
//---------------------------------------------------------------------------

class QWidget;

namespace NSApplication {
namespace NSInterface {
//---------------------------------------------------------------------------
// CCentralWidgetHandler Declaration
//---------------------------------------------------------------------------
// An object providing interaction of centralWidget of Qt MainWindow
// with internal resources of the Application object
//---------------------------------------------------------------------------

class CCentralWidgetHandler : public QObject {
  Q_OBJECT
public:
  CCentralWidgetHandler(QWidget* Widget);
  ~CCentralWidgetHandler();
private:
  bool eventFilter(QObject* watched, QEvent* event);
  bool processEvent(QEvent* event);
  QWidget* Widget_;
  unsigned long long EventCount_;
};
//---------------------------------------------------------------------------
} // NSAInterface
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // CENTRALWIDGETHANDLER_H
