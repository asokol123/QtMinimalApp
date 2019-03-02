#ifndef APPLICATIONINTERFACE_H
#define APPLICATIONINTERFACE_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "ApplicationGlobals.h"
//---------------------------------------------------------------------------

namespace NSApplication {
namespace NSInterface {
//---------------------------------------------------------------------------
// CCentralWidgetHandler Forward Declaration
//---------------------------------------------------------------------------

class CCentralWidgetHandler;
//---------------------------------------------------------------------------
} // NSInterface
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// CApplicationInterface Declaration
//---------------------------------------------------------------------------
// A part of the Application object
// Its purpose is to provide a Qt independent way of handling
// Qt events of its specific UI components
//
// All internal parts of the application object must use interface handlers
// in order to interact with the Qt resources
//
// Below you will find an example of handling the centralWidget of
// the MainWindow object
//---------------------------------------------------------------------------

class CApplicationInterface : protected CApplicationGlobals {
  using CBase = CApplicationGlobals;
  using CCentralWidgetHandler = NSInterface::CCentralWidgetHandler;
public:
  CApplicationInterface();
  ~CApplicationInterface();
private:
  //---------------------------------------------------------------------------
  // We initialize a pointer to the handler and not the handler it-self
  // because the handler contains Q_OBJECT macro and we do not want
  // to expose such a heavy object in a header
  //---------------------------------------------------------------------------
  std::unique_ptr<CCentralWidgetHandler> CentralWidgetHandler_;
};
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // APPLICATIONINTERFACE_H
