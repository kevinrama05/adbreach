#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XI2.h>
#include <X11/extensions/XInput2.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Display *dpy = XOpenDisplay(NULL);
    if (!dpy){
        fprintf(stderr, "Failed to open display\n");
        return 1;
    }

    int opcode, event, error;
    if (!XQueryExtension(dpy, "XInputExtension", &opcode, &event, &error)){
        fprintf(stderr, "XInput not available\n");
        return 1;
    }


    int major = 2, minor = 0;
    if (XIQueryVersion(dpy, &major, &minor) == BadRequest){
        fprintf(stderr, "XI2 not supported\n");
        return 1;
    }

    XIEventMask mask;
    unsigned char mask_bits[XIMaskLen(XI_RawMotion)] = {0};

    mask.deviceid = XIAllMasterDevices;
    mask.mask = mask_bits;
    mask.mask_len = sizeof(mask_bits);

    XISetMask(mask_bits, XI_RawMotion);
    XISelectEvents(dpy, DefaultRootWindow(dpy), &mask, 1);
    XFlush(dpy);

    printf("Listening for mouse movement...\n");

    XEvent ev;
    while (1) {
        XNextEvent(dpy, &ev);

        if (ev.type != GenericEvent) continue;
        if (ev.xcookie.extension != opcode) continue;
        if (!XGetEventData(dpy, &ev.xcookie)) continue;

        if (ev.xcookie.evtype == XI_RawMotion) {
            XIRawEvent *re = (XIRawEvent *)ev.xcookie.data;
            double dx = 0, dy = 0;

            int idx = 0;
            if (XIMaskIsSet(re->valuators.mask, 0)) dx = re->raw_values[idx++];
            if (XIMaskIsSet(re->valuators.mask, 1)) dy = re->raw_values[idx++];

            printf("dx: %.0f  dy: %.0f\n", dx, dy);
        }

        XFreeEventData(dpy, &ev.xcookie);
    }

    XCloseDisplay(dpy);
    return 0;
}
