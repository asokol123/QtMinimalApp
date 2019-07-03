#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
// I use precompiled header for STL library
#include <memory> // pch
#include <QMainWindow>
//---------------------------------------------------------------------------

namespace Ui {
class CMainWindow;
}
//---------------------------------------------------------------------------

namespace NSApplication {
namespace NSQt {
//---------------------------------------------------------------------------
// CMainWindow Declaration
//---------------------------------------------------------------------------
// A part of the Application object
// Its purpose is to provide all Qt related resources
// to the application object
//
// It may use its own Qt event() method or eventFilter() method
// in order to react to global Qt events
//
// If you need to react to events of a specific UI component
// Use application interface handlers in CApplicationInterface
//---------------------------------------------------------------------------

class CMainWindow : protected QMainWindow {
  Q_OBJECT
  using CBase = QMainWindow;
public:
  explicit CMainWindow(QWidget *parent = 0);
  ~CMainWindow();
protected:
  Ui::CMainWindow* accessUI();
  const Ui::CMainWindow* accessUI() const;
private:
  std::unique_ptr<Ui::CMainWindow> Interface_;
};
//---------------------------------------------------------------------------
} // NSQt
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // MAINWINDOW_H
