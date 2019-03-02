//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include <QApplication>
#include "Application.h"
#include "ExceptionHandler.h"
//---------------------------------------------------------------------------
// main
//---------------------------------------------------------------------------

int main(int argc, char *argv[]) {
  namespace NSApp = NSApplication;
  try {
    QApplication QApp(argc, argv);
    NSApp::CApplication Application;
    QApp.exec();
  } catch(std::exception& Exception) {
    NSApp::CExceptionHandler React(Exception);
  } catch(...) {
    NSApp::CExceptionHandler React;
  }
  return 0;
}
//---------------------------------------------------------------------------
