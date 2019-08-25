#include "cx11keyloggerworker.h"
#include <exception>
#include <iostream> // cout to show that everething works

CX11KeyloggerWorker::CX11KeyloggerWorker(QThread* myThread, QObject *parent)
    : QObject(parent)
    , myThread_(myThread)
{
    // Setup X11
    X11Display_ = XOpenDisplay(nullptr);
    if (X11Display_ == nullptr) {
        throw std::runtime_error("Cannot open display");
    }

    // Magic to check if XInput 2 is avaible and find it's opcode
    int queryEvent, queryError;
    if (! XQueryExtension(X11Display_, "XInputExtension", &xi_opcode_, &queryEvent, &queryError)) {
        throw std::runtime_error("X Input extension not available\n");
    }

    Window X11DefaultWindow = DefaultRootWindow(X11Display_);

    // Setup catching events
    XIEventMask X11EventMask;
    X11EventMask.deviceid = XIAllMasterDevices;
    X11EventMask.mask_len = XIMaskLen(XI_LASTEVENT);
    X11EventMask.mask = new unsigned char[X11EventMask.mask_len];
    std::fill(X11EventMask.mask, X11EventMask.mask + X11EventMask.mask_len, 0);

    XISetMask(X11EventMask.mask, XI_RawKeyPress);
    XISetMask(X11EventMask.mask, XI_RawKeyRelease);

    // third parameter is pointer to the array of Masks, but we have only 1 mask, so we can just take it's address
    // last parameter is size of the array
    XISelectEvents(X11Display_, X11DefaultWindow, &X11EventMask, 1);
    XSync(X11Display_, false);
    delete[] X11EventMask.mask;

    // Done
}

void CX11KeyloggerWorker::StartLogging() {
    XEvent X11CurrentEvent;
    XGenericEventCookie *X11CurrentEventCookie = &X11CurrentEvent.xcookie;
    while (!myThread_->isInterruptionRequested()) {
        // TODO: 100 milliseconds timeout using custom class?
        XNextEvent(X11Display_, &X11CurrentEvent);

        if (!XGetEventData(X11Display_, X11CurrentEventCookie) || X11CurrentEventCookie->extension != xi_opcode_) {
            continue;
        }
        if (X11CurrentEventCookie->evtype == XI_RawKeyPress) {
            std::cout << "RawKeyPressed, Symbol: " << XKeysymToString(XkbKeycodeToKeysym(X11Display_, static_cast<XIRawEvent*>(X11CurrentEventCookie->data)->detail, 0, 0)) << std::endl;
            emit RawKeyPressedSignal(*static_cast<XIRawEvent*>(X11CurrentEventCookie->data));
        }
        if (X11CurrentEventCookie->evtype == XI_RawKeyRelease) {
            std::cout << "RawKeyPressed, Symbol: " << XKeysymToString(XkbKeycodeToKeysym(X11Display_, static_cast<XIRawEvent*>(X11CurrentEventCookie->data)->detail, 0, 0)) << std::endl;
            emit RawKeyReleasedSignal(*static_cast<XIRawEvent*>(X11CurrentEventCookie->data));
        }
    }
}
