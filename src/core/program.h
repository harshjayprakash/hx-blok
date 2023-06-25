#ifndef BLOK_PROGRAM_H
#define BLOK_PROGRAM_H

#include <windows.h>

/**
 * @brief Stores all of the globals that will need to be accessible throughout
 * the program.
 */
struct program {
    /**
     * @brief Stores the instance handle of the program. This is what Windows
     * uses to find the executable in memory.
     */
    HINSTANCE instance_handle;

    /**
     * @brief Stores the previous version of the instance handle of the program.
     * This is for 16-bit programs. This is not used.
     */
    HINSTANCE previous_instance_handle;

    /**
     * @brief Stores the command line arguments specified on startup of the
     * program.
     */
    LPSTR command_line_arguments;

    /**
     * @brief Stores how the program's user interface should be shown to the
     * user.
     */
    int show_flag;
};

/**
 * @brief Responsible for initialising and allocating any memory required for
 * the program's globals.
 * @param _instance_handle program instance handle.
 * @param _previous_instance_handle previous version of the instance handle.
 * @param _command_line_arguments command line arguments specified.
 * @param _show_flag how the application will be shown.
 */
void program_init(HINSTANCE _instance_handle,
                  HINSTANCE _previous_instance_handle,
                  LPSTR _command_line_arguments, int _show_flag);

/**
 * @brief An accessor to retrieve the globals.
 * @return A pointer to the program structure that stores the globals.
 */
struct program *program_instance_get(void);

/**
 * @brief Responsible for freeing any memory used by the program's globals.
 */
void program_free(void);

#endif