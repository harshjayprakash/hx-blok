#include <stdio.h>
#include <windows.h>

#include "core/program.h"
#include "model/square.h"
#include "presentation/window.h"
#include "service/store.h"
#include "service/logger.h"
#include "service/store.h"

/**
 * @brief Provides a entrypoint into the program.
 * @param hInstance program instance handle.
 * @param hPrevInstance previous version of the instance handle.
 * @param lpCmdLine command line arguments specified.
 * @param nShowCmd how the application will be shown.
 * @return An integer indicating whether the program operation was successful.
 *      zero for success, anything else for failure.
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nShowCmd) {

    program_init(hInstance, hPrevInstance, lpCmdLine, nShowCmd);

    global_square_get()->y = 0;
    global_square_get()->x = 0;
    global_square_get()->height = 15;
    global_square_get()->width = 15;

    struct window_wrapper window_ = window_new();

    if (!window_.present)
        printlog(log_err, "main.c:WinMain", "Failed to initalise window.");

    window_free(&window_.handle.instance);
    program_free();

    return 0;
}