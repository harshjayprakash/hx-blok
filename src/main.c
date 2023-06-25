#include <stdio.h>
#include <windows.h>

#include "core/program.h"
#include "model/square.h"
#include "presentation/window.h"
#include "service/store.h"
#include "service/logger.h"

/**
 * @brief Provides a entrypoint into the program.
 * @param instance_handle program instance handle.
 * @param previous_instance_handle previous version of the instance handle.
 * @param command_line_arguments command line arguments specified.
 * @param show_flag how the application will be shown.
 * @return An integer indicating whether the program operation was successful.
 *      zero for success, anything else for failure.
 */
int APIENTRY WinMain(HINSTANCE instance_handle,
                     HINSTANCE previous_instance_handle,
                     LPSTR command_line_arguments, int show_flag) {

    program_init(instance_handle, previous_instance_handle,
                 command_line_arguments, show_flag);

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