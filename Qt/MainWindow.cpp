//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "MainWindow.h"
#include "ui_CMainWindow.h"
//---------------------------------------------------------------------------

namespace NSApplication {
namespace NSQt {
//---------------------------------------------------------------------------
// CMainWindow Definition
//---------------------------------------------------------------------------

CMainWindow::CMainWindow(QWidget *parent) :
  QMainWindow(parent),
  Interface_(std::make_unique<Ui::CMainWindow>()) {
  Interface_->setupUi(this);
  show();
}
//---------------------------------------------------------------------------

CMainWindow::~CMainWindow() {
  // I need an explicit destructor because the class contains
  // a unique_ptr to an incomplete type
}
//---------------------------------------------------------------------------

Ui::CMainWindow* CMainWindow::accessUI() {
  return Interface_.get();
}
//---------------------------------------------------------------------------

const Ui::CMainWindow* CMainWindow::accessUI() const {
  return Interface_.get();
}
//---------------------------------------------------------------------------
} // NSQt
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
