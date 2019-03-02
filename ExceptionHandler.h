#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include <QMessageBox>
//---------------------------------------------------------------------------
namespace NSApplication {
//---------------------------------------------------------------------------
// Declaration of CExceptionHandler
//---------------------------------------------------------------------------
// The purpose of the object is to provide information about exceptions
// happend during initialization of the Application resources
//---------------------------------------------------------------------------

class CExceptionHandler {
public:
  CExceptionHandler();
  CExceptionHandler(std::exception& exception);
private:
  static constexpr const char* kUnknownExceptionMsg = "Unknown Exception!";
  QMessageBox MessageBox;
};
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // EXCEPTIONHANDLER_H
