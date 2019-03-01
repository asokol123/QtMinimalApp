#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include <QMainWindow>
#include <memory>
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

class CMainWindow : protected QMainWindow {
  Q_OBJECT
  using CBase = QMainWindow;
public:
  explicit CMainWindow(QWidget *parent = 0);
  ~CMainWindow();
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
